#include "GameManager.h"
#include "ItemFinal.h"
using namespace Platform;


GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
{
	loadMedia();
	initPlayer();
	initWalls();
	initPull();
	initLevel(level);
	Button button = (* new Button("obj_but1", "Boton 1", 50, 50, 0, 40, 20));
	button.setImage(RenderManager::GetInstance().getImageByName("img_plt"));
}


GameManager::~GameManager()
{
}

void Platform::GameManager::initLevel(int nivel)
{
	
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
	walls.push_back(wall);
	wall = new Object("obj_wall2", 0, 460, 0, 640, 20);
	wall->setImage(img_horWall);
	walls.push_back(wall);
	wall = new Object("obj_wall3", 0, 20, 0, 20, 480);
	wall->setImage(img_verWall);
	walls.push_back(wall);
	wall = new Object("obj_wall4", 620, 0, 0, 20, 480);
	wall->setImage(img_verWall);
	walls.push_back(wall);
}

void Platform::GameManager::initPlatforms(int nivel)
{
	vector<Object*>::iterator pltIt = platforms.begin();
	for (int i = 0; i < sizeof(lvlsP[nivel])/6; i++) {
		if (lvlsP[nivel][i][0] == 0 || lvlsP[nivel][i][1] == 0) { return; }
		(*pltIt)->x = lvlsP[nivel][i][0];
		(*pltIt)->y = lvlsP[nivel][i][1];
		pltIt++;
	}
}

void Platform::GameManager::initItems(int nivel)
{
	vector<Item*>::iterator itemIt = items.begin();
	int i = 0;
	for (i; i < sizeof(lvlsI[nivel]) / 6; i++) {
		if (lvlsI[nivel][i][0] <= 0 || lvlsI[nivel][i][1] <= 0) { break; }
		mt19937 rng(rd());
		uniform_int_distribution<int> uni(0, imgNames.size() - 1);
		int rnd = uni(rng);
		string imgName = imgNames[rnd];
		(*itemIt)->setImage(RenderManager::GetInstance().getImageByName(imgName));
		(*itemIt)->restart(lvlsI[nivel][i][0],lvlsI[nivel][i][1]);
		itemIt++;
	}
	itemIt = items.end()-1;
	(*itemIt)->x = -lvlsI[nivel][i][0];
	(*itemIt)->y = -lvlsI[nivel][i][1];
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
	int s_W = RenderManager::GetInstance().SCREEN_WIDTH;
	int s_H = RenderManager::GetInstance().SCREEN_HEIGHT;
	for (vector <Object*>::iterator pltIt = platforms.begin(); pltIt != platforms.end(); pltIt++) {
		(*pltIt)->x=s_W;
		(*pltIt)->y = s_H;
	}
}

void Platform::GameManager::cleanItems()
{
	int s_W = RenderManager::GetInstance().SCREEN_WIDTH;
	int s_H = RenderManager::GetInstance().SCREEN_HEIGHT;
	for (vector <Item*>::iterator itemIt = items.begin(); itemIt != items.end(); itemIt++) {
		(*itemIt)->x = s_W;
		(*itemIt)->y = s_H;
	}
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
	int s_W = RenderManager::GetInstance().SCREEN_WIDTH;
	int s_H = RenderManager::GetInstance().SCREEN_HEIGHT;
	//create the pull of platforms
	Object* platform;
	Image * img_plt = RenderManager::GetInstance().getImageByName("img_plt");
	for (int i = 0; i < maxPlatf; i++) {
		platform = new Object("obj_plt" + to_string(i), s_W, s_H, 0, 40, 20);
		platform->setImage(img_plt);
		platforms.push_back(platform);
	}
	//create the pull of objects
	Item* item;
	for (int i = 0; i < maxItems-1; i++) {
		item = new Item("obj_item" + to_string(i), 0, 0, 0, 20, 20);
		item->kill();
		items.push_back(item);
	}
	//create the final item
	ItemFinal* itemF= new ItemFinal("obj_itemF", s_W ,s_H , 0, 30, 30, this);
	itemF->setImage(RenderManager::GetInstance().getImageByName("img_diamond"));
	items.push_back(itemF);
}

