//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "InputManager.h"
#include "ActionManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"
#include "TimerManager.h"
#include "SoundManager.h"
#include "Image.h"
#include "Text.h"
#include "Object.h"
#include "JumpMan.h"
#include "Item.h"

#undef main
int main(int argc, char* args[])
{
	//Create the managers
	ObjectManager::CreateSingleton();
	RenderManager::CreateSingleton();
	InputManager::CreateSingleton();
	ActionManager::CreateSingleton();
	ColliderManager::CreateSingleton();
	TimerManager::CreateSingleton();
	SoundManager::CreateSingleton();

	//variables


	//Initialize SDL
	if (!RenderManager::GetInstance().init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!SoundManager::GetInstance().init())
		{
			printf("Failed to initialize!\n");
		}
		//the image for the player
		RenderManager::GetInstance().addImage("images/dot.bmp", "player");
		Image* img_player = RenderManager::GetInstance().getImageByName("player");
		//create the player
		JumpMan player("player", 25, RenderManager::GetInstance().SCREEN_HEIGHT-25-20, 20, 20, img_player);

		//variables
		Object * walls[4];

		//create the walls
		walls[0] = new Object("obj_wall1", 0, 0, 0, 640, 20);
		walls[2] = new Object("obj_wall3", 0, 20, 0, 20, 480);
		walls[3] = new Object("obj_wall4", 620, 0, 0, 20, 480);
		walls[1] = new Object("obj_wall2", 0, 460, 0, 640, 20);
		RenderManager::GetInstance().addImage("images/horWall.jpg", "img_horWall");
		Image * img_horWall = RenderManager::GetInstance().getImageByName("img_horWall");
		walls[0]->setImage(img_horWall);
		walls[1]->setImage(img_horWall);
		RenderManager::GetInstance().addImage("images/verWall.jpg", "img_verWall");
		Image * img_verWall = RenderManager::GetInstance().getImageByName("img_verWall");
		walls[2]->setImage(img_verWall);
		walls[3]->setImage(img_verWall);

		//the platforms
		Object * platforms[4];

		//create the platforms
		platforms[0] = new Object("obj_plt1", 60, 400, 0, 40, 20);
		platforms[1] = new Object("obj_plt1", 120, 400, 0, 40, 20);
		platforms[2] = new Object("obj_plt1", 200, 400, 0, 40, 20);
		platforms[3] = new Object("obj_plt1", 260, 400, 0, 40, 20);
		RenderManager::GetInstance().addImage("images/plt_40_20.png", "img_plt");
		Image * img_plt = RenderManager::GetInstance().getImageByName("img_plt");
		platforms[0]->setImage(img_plt);
		platforms[1]->setImage(img_plt);
		platforms[2]->setImage(img_plt);
		platforms[3]->setImage(img_plt);


		//create an item
		Item item("obj_item", 200, 360, 0, 20, 20);
		RenderManager::GetInstance().addImage("images/manzana.jpg", "img_item");
		Image* img_Item = RenderManager::GetInstance().getImageByName("img_item");
		item.setImage(img_Item);
		
		//create the fpsCounter
		ObjectManager::GetInstance().addObject("fpsCounter", 0, 0, 0, 0, 0);
		RenderManager::GetInstance().addText("0", "fps");
		Text* fpsText = RenderManager::GetInstance().getTextByName("fps");
		ObjectManager::GetInstance().getObjectByName("fpsCounter")->setText(fpsText);
		Object * fpsCounter = ObjectManager::GetInstance().getObjectByName("fpsCounter");
		float fps = 0.0;

		//create some actions
		ActionManager::GetInstance().addAction("up", 0, "w");
		ActionManager::GetInstance().getActionByName("up")->addKey("up");
		ActionManager::GetInstance().addAction("down", 0, "s");
		ActionManager::GetInstance().getActionByName("down")->addKey("down");
		ActionManager::GetInstance().addAction("left", 0, "a");
		ActionManager::GetInstance().getActionByName("left")->addKey("left");
		ActionManager::GetInstance().addAction("right", 0, "d");
		ActionManager::GetInstance().getActionByName("right")->addKey("right");

		SoundManager::GetInstance().loadEffect("sound/high.wav", "sound_1");

		//Main loop flag
		bool quit = false;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			RenderManager::GetInstance().preUpdate();
			ActionManager::GetInstance().update();
			ObjectManager::GetInstance().update();
			RenderManager::GetInstance().postUpdate();

			TimerManager::GetInstance().update();
			fps = TimerManager::GetInstance().getFPS();
			fpsCounter->text.setText(to_string(fps));
		}
	}
	return 0;
}