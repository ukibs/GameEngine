#include "Player.h"



Player::Player(string name, int x, int y, int depth, float w, float h): Object(name, x, y, depth, w, h)
{
	time = 0;
	countBody = 0;
	direction = 0;
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
	RenderManager::GetInstance().addImage("images/body2.jpg", "img_sBody2");
	image[5] = RenderManager::GetInstance().getImageByName("img_sBody2");

	setImage(image[3]);

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			position[i][j] = 0;
			snakeDirection[i][j] = 0;
		}
	}

	position[2][2] = 1;
}


Player::~Player()
{
}

void Player::update()
{
	if (ActionManager::GetInstance().getDown("right")){direction = 0;}
	if (ActionManager::GetInstance().getDown("left")){direction = 1;}
	if (ActionManager::GetInstance().getDown("up")){direction = 2;}
	if (ActionManager::GetInstance().getDown("down")){direction = 3;}

	if (time == 10)
	{
		time = 0;

		switch (direction)
		{
			//derecha
		case 0: setImage(image[3]); changePosition(1, 0); break;
			//izquierda
		case 1: setImage(image[2]); changePosition(-1, 0); break;
			//arriba
		case 2: setImage(image[0]); changePosition(0, -1); break;
			//abajo
		case 3: setImage(image[1]); changePosition(0, 1); break;
		}
		moveBody();
	}
	time++;
}

void Player::addBody()
{
	string name = "body" + to_string(countBody);
	if(countBody == 0)body[countBody] = new Object(name, x, y, 0, 20, 20);
	else body[countBody] = new Object(name, body[0]->x, body[0]->y, 0, 20, 20);
	body[countBody]->setImage(image[4]);
	countBody++;
}

void Player::moveBody()
{
	int b = 0;
	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 24; j++){
			if (position[i][j] != 0){
				if (position[i][j] == 1)
				{
					if (anyCollision(i * 20, j * 20) && getCollisionTag(i * 20, j * 20) != "enemy")
					{
						cout << "he colisionado con " << getCollisionName(i * 20, j * 20);
						time = 11;
					}
					else
					{
						x = i * 20;
						y = j * 20;
					}
				}
				else if(countBody != 0 && b < countBody)
				{
					body[b]->x = i * 20;
					body[b]->y = j * 20;
					updateDirection(b, i, j);
					b++;
				}
			}}}
}

void Player::changePosition(int newI, int newJ)
{
	bool out = false;
	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 24; j++){
			if (position[i][j] == 1){
				if (newI != 0)
				{
					position[i + newI][j] = 1;
					snakeDirection[i][j] = direction;
					out = true;
					updatePosition(i + newI, j);
					break;
				}
				else
				{
					position[i][j + newJ] = 1;
					snakeDirection[i][j] = direction;
					out = true;
					updatePosition(i, j + newJ);
					break;
				}
			}}
		if (out) break;
	}
}

void Player::updatePosition(int newI, int newJ)
{
	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 24; j++){
			if (position[i][j] != 0 && (newI != i || newJ != j)){
				if (countBody >= position[i][j]){position[i][j]++;}
				else position[i][j] = 0;}
		}
	}
}

void Player::updateDirection(int pos, int i, int j)
{
	switch (snakeDirection[i][j])
	{
		//derecha
	case 0: body[pos]->setImage(image[4]); break;
		//izquierda
	case 1: body[pos]->setImage(image[4]); break;
		//arriba
	case 2: body[pos]->setImage(image[5]); break;
		//abajo
	case 3: body[pos]->setImage(image[5]); break;
	}
}
