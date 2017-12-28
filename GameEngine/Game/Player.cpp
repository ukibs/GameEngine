#include "Player.h"



Player::Player(string name, int x, int y, int depth, float w, float h): Object(name, x, y, depth, w, h)
{
	speed = 1;
	countBody = 0;
	RenderManager::GetInstance().addImage("images/snakeUp.jpg", "img_sUp");
	image[0] = RenderManager::GetInstance().getImageByName("img_sUp");
	RenderManager::GetInstance().addImage("images/snakeDown.jpg", "img_sDown");
	image[1] = RenderManager::GetInstance().getImageByName("img_sDown");
	RenderManager::GetInstance().addImage("images/snakeLeft.jpg", "img_sLeft");
	image[2] = RenderManager::GetInstance().getImageByName("img_sLeft");
	RenderManager::GetInstance().addImage("images/snakeRight.jpg", "img_sRight");
	image[3] = RenderManager::GetInstance().getImageByName("img_sRight");
	RenderManager::GetInstance().addImage("images/body.jpg", "img_sBody");
	image[4] = RenderManager::GetInstance().getImageByName("img_sBody");

	setImage(image[3]);
}


Player::~Player()
{
}

void Player::update()
{
	float newX = x;
	float newY = y;
	if (ActionManager::GetInstance().getDown("right"))
	{
		newX = x + speed;
		direction = 0;
	}
	if (ActionManager::GetInstance().getDown("left"))
	{
		newX = x - speed;
		direction = 1;
		
	}
	if (ActionManager::GetInstance().getDown("up"))
	{
		newY = y - speed;
		direction = 2;
		
	}
	if (ActionManager::GetInstance().getDown("down"))
	{
		newY = y + speed;
		direction = 3;
	}

	switch (direction)
	{
		//derecha
	case 0: setImage(image[3]); newX = x + speed; break;
		//izquierda
	case 1: setImage(image[2]); newX = x - speed; break;
		//arriba
	case 2: setImage(image[0]); newY = y - speed; break;
		//abajo
	case 3: setImage(image[1]); newY = y + speed; break;
	}


	if (newY < 440 && newY > 20 && newX < 600 && newX > 20)
	{
		lastX = x;
		lastY = y;
		x = newX;
		y = newY;
	}
	else
	{
		//muereeeeeee
	}

	moveBody();
}

void Player::addBody()
{
	if (countBody == 0)
	{
		body[countBody] = new Object("body" + countBody, x - 20, y, 0, 20, 20);
		body[countBody]->setImage(image[4]);
		countBody++;
	}
	else
	{
		body[countBody] = new Object("body" + countBody, body[countBody-1]->x - 20, y, 0, 20, 20);
		body[countBody]->setImage(image[4]);
		countBody++;
	}
}

void Player::moveBody()
{
	int posX;
	int posY;
	int newX;
	int newY;
	for (int i = 0; i < countBody; i++)
	{
		if(i == 0)
		{
			posX = body[i]->x;
			posY = body[i]->y;
			switch (direction)
			{
				//derecha
				case 0: body[i]->x = lastX - 20; body[i]->y = lastY; break;
				//izquierda
				case 1: body[i]->x = lastX + 20; body[i]->y = lastY; break;
				//arriba
				case 2: body[i]->y = lastY + 20; body[i]->x = lastX; break;
				//abajo
				case 3:  body[i]->y = lastY - 20; body[i]->x = lastX; break;
			}
		}
		else
		{
			newX = body[i]->x;
			newY = body[i]->y;
			body[i]->x = posX;
			body[i]->y = posY;
			posX = newX;
			posY = newY;
		}
	}
}
