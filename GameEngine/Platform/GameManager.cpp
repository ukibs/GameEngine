#include "GameManager.h"
#include "ItemFinal.h"
using namespace Platform;


GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
{
	loadMedia();
	initPlayer();
	initLevel();
}


GameManager::~GameManager()
{
}

void GameManager::update() {
}

void Platform::GameManager::initLevel()
{
	initWalls();
	initPlatforms();
	initItems();
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

void Platform::GameManager::initPlatforms()
{
	//load platform image
	
	Image * img_plt = RenderManager::GetInstance().getImageByName("img_plt");
	//create the platforms
	Object* platform;
	platform = new Object("obj_plt1", 60, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
	platform = new Object("obj_plt2", 120, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
	platform = new Object("obj_plt3", 200, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
	platform = new Object("obj_plt4", 260, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
}

void Platform::GameManager::initItems()
{
	
	//create the items
	addItem("obj_item1", 100, 360, 0, 20, 20,"img_manzana");
	addItem("obj_item2", 200, 360, 0, 20, 20, "img_pineapple");
	addItem("obj_item3", 300, 360, 0, 20, 20, "img_carrot");
	addItem("obj_item4", 400, 360, 0, 20, 20, "img_tomato");
	//create the final item to reset the game when you collect it
	ItemFinal* itemF = new ItemFinal("obj_itemF", 500, 400, 0, 30, 30, this);
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
	player->x = 25;
	player->y = RenderManager::GetInstance().SCREEN_HEIGHT - 25 - 20;
	cleanPlatforms();
	cleanItems();
	initLevel();
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
	RenderManager::GetInstance().addImage("images/carrot.png", "img_carrot");
	RenderManager::GetInstance().addImage("images/pineapple.png", "img_pineapple");
	RenderManager::GetInstance().addImage("images/tomato.png", "img_tomato");
	RenderManager::GetInstance().addImage("images/diamond.png", "img_diamond");
	//the image for the player
	RenderManager::GetInstance().addImage("images/dot.bmp", "player");
}

