#include "GameManager.h"
using namespace Platform;


GameManager::GameManager(string name, int x, int y, int w, int h, int depth) : Object(name, x, y, depth, w, h)
{
	initPlayer();
	initWalls();
	initPlatforms();
}


GameManager::~GameManager()
{
}

void GameManager::update() {

}

void Platform::GameManager::initWalls()
{
	//load wall images
	RenderManager::GetInstance().addImage("images/horWall.jpg", "img_horWall");
	Image * img_horWall = RenderManager::GetInstance().getImageByName("img_horWall");
	RenderManager::GetInstance().addImage("images/verWall.jpg", "img_verWall");
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
	RenderManager::GetInstance().addImage("images/plt_40_20.png", "img_plt");
	Image * img_plt = RenderManager::GetInstance().getImageByName("img_plt");
	//create the platforms
	Object* platform;
	platform = new Object("obj_plt1", 60, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
	platform = new Object("obj_plt1", 120, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
	platform = new Object("obj_plt1", 200, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
	platform = new Object("obj_plt1", 260, 400, 0, 40, 20);
	platform->setImage(img_plt);
	platforms.push_back(platform);
}

void Platform::GameManager::initItems()
{
	//create an item
	Item* item;
	item = new Item("obj_item", 200, 360, 0, 20, 20);
	RenderManager::GetInstance().addImage("images/manzana.jpg", "img_item");
	Image* img_Item = RenderManager::GetInstance().getImageByName("img_item");
	item->setImage(img_Item);
	items.push_back(item);
}

void Platform::GameManager::initPlayer()
{
	//the image for the player
	RenderManager::GetInstance().addImage("images/dot.bmp", "player");
	Image* img_player = RenderManager::GetInstance().getImageByName("player");
	//create the player
	player = new JumpMan("player", 25, RenderManager::GetInstance().SCREEN_HEIGHT - 25 - 20, 20, 20, img_player);
}

