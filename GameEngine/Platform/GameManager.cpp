#include "GameManager.h"
#include "ItemFinal.h"
using namespace Platform;


GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
{
	loadMedia();
	initPlayer();
	initPull();
	initLevel(level);
}


GameManager::~GameManager()
{
}

void GameManager::update() {
}

void Platform::GameManager::initLevel(int nivel)
{
	initWalls();
	initPlatforms(nivel);
	initItems(nivel);
}

void Platform::GameManager::initWalls()
{
	//load wall images
	
	Image * img_horWall = RenderManager::GetInstance().getImageByName("img_horWall");
	
	Image * img_verWall = RenderManager::GetInstance().getImageByName("img_verWall");
	//create the walls
	Object* wall=new Object("obj_wall1", 0, 0, 0, 640, 20);
	wall->setImage(img_horWall);
	platforms.push_back(wall);
	wall = new Object("obj_wall2", 0, 460, 0, 640, 20);
	wall->setImage(img_horWall);
	platforms.push_back(wall);
	wall = new Object("obj_wall3", 0, 20, 0, 20, 480);
	wall->setImage(img_verWall);
	platforms.push_back(wall);
	wall = new Object("obj_wall4", 620, 0, 0, 20, 480);
	wall->setImage(img_verWall);
	platforms.push_back(wall);
}

void Platform::GameManager::initPlatforms(int nivel)
{
	Image * img_plt = RenderManager::GetInstance().getImageByName("img_plt");
	//create the platforms
	Object* platform;
	for (int i = 0; i < sizeof(lvlsP[nivel])/6; i++) {
		if (lvlsP[nivel][i][0] == 0 || lvlsP[nivel][i][1] == 0) { return; }
		platform = new Object("obj_plt" + to_string(i), lvlsP[nivel][i][0], lvlsP[nivel][i][1], 0, 40, 20);
		platform->setImage(img_plt);
		platforms.push_back(platform);
	}
}

void Platform::GameManager::initItems(int nivel)
{
	Item* item;
	int i = 0;
	for (i = 0; i < sizeof(lvlsI[nivel]) / 6; i++) {
		if (lvlsI[nivel][i][0] <= 0 || lvlsI[nivel][i][1] <= 0) { break; }
		//generate a random int lower than the number of item images
		mt19937 rng(rd());
		uniform_int_distribution<int> uni(0, imgNames.size()-1);
		int rnd = uni(rng);
		string imgName = imgNames[rnd];
		addItem("obj_item" + to_string(i), lvlsI[nivel][i][0], lvlsI[nivel][i][1], 0, 20, 20, imgName);
	}
	//create the final item to reset the game when you collect it
	ItemFinal* itemF = new ItemFinal("obj_itemF", -lvlsI[nivel][i][0], -lvlsI[nivel][i][1], 0, 30, 30, this);
	itemF->setImage(RenderManager::GetInstance().getImageByName("img_diamond"));
	items.push_back(itemF);
}

void Platform::GameManager::addItem(string name, int x,int y,int depth, int w, int h, string imgName) {
	//create an item
	Item* item = new Item(name, x, y, depth, w, h);
	Image* img_Item = RenderManager::GetInstance().getImageByName(imgName);
	item->setImage(img_Item);
	items.push_back(item);
}

void Platform::GameManager::reset()
{
	if (level == maxLevels-1) { level = 0; }
	else { level++; }
	player->x = 25;
	player->y = RenderManager::GetInstance().SCREEN_HEIGHT - 25 - 20;
	cleanPlatforms();
	cleanItems();
	initLevel(level);
}

void Platform::GameManager::initPlayer()
{
	
	Image* img_player = RenderManager::GetInstance().getImageByName("player");
	//create the player
	player = new JumpMan("player", 25, RenderManager::GetInstance().SCREEN_HEIGHT - 25 - 20, 20, 20, img_player);
}

void Platform::GameManager::cleanPlatforms()
{
	for (vector <Object*>::iterator pltIt = platforms.begin(); pltIt != platforms.end(); pltIt++) {
		(*pltIt)->destroy();
	}
	platforms.clear();
}

void Platform::GameManager::cleanItems()
{
	for (vector <Item*>::iterator itemIt = items.begin(); itemIt != items.end(); itemIt++) {
		(*itemIt)->destroy();
	}
	items.clear();
}

void Platform::GameManager::loadMedia()
{
	//load the images for the environment
	RenderManager::GetInstance().addImage("images/horWall.jpg", "img_horWall");
	RenderManager::GetInstance().addImage("images/verWall.jpg", "img_verWall");
	RenderManager::GetInstance().addImage("images/plt_40_20.png", "img_plt");
	//load the images for the items
	RenderManager::GetInstance().addImage("images/manzana.jpg", "img_manzana");
	imgNames.push_back("img_manzana");
	RenderManager::GetInstance().addImage("images/carrot.png", "img_carrot");
	imgNames.push_back("img_carrot");
	RenderManager::GetInstance().addImage("images/pineapple.png", "img_pineapple");
	imgNames.push_back("img_pineapple");
	RenderManager::GetInstance().addImage("images/tomato.png", "img_tomato");
	imgNames.push_back("img_tomato");
	RenderManager::GetInstance().addImage("images/diamond.png", "img_diamond");
	//the image for the player
	RenderManager::GetInstance().addImage("images/dot.bmp", "player");
}

void Platform::GameManager::initPull()
{
	Object* platform;
	for (int i = 0; i < maxPlatf; i++) {
		platform = new Object();
		ObjectManager::GetInstance().addObject(platform);
		platforms.push_back(platform);
	}
	
	Item* item;
	for (int i = 0; i < maxItems; i++) {
		item = new Item();
		ObjectManager::GetInstance().addObject(item);
		items.push_back(item);
	}
	for (int i = 0; i < maxPlatf; i++) {
		platforms[0]->destroy();
	}
	for (int i = 0; i < maxItems; i++) {
		items[0]->destroy();
	}
}

