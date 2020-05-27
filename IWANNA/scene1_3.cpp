#include "stdafx.h"
#include "scene1_3.h"


scene1_3::scene1_3()
{
}


scene1_3::~scene1_3()
{
}

HRESULT scene1_3::init()
{
	IMAGEMANAGER->addImage("스테이지1_3", "images/Stage1_3_t.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_3_MG", "images/Stage1_3_MG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_scene1_3MG = IMAGEMANAGER->findImage("스테이지1_3_MG");
	//_player->setStageFlag(3);
	//_scene1_3Tile = new Tile;
	//_scene1_3Tile->init(32, 24, 32, 32, tileArr);
	_player = new player;
	_player->init();
	_player->getPlayerImage()->setX(5);
	_player->getPlayerImage()->setY(650);

	rc = RectMakeCenter(1014, 650, 10, 50);
	return S_OK;
}

void scene1_3::release()
{
}

void scene1_3::update()
{
	boxCollision(_player);
	//if (_player->getPlayerImage()->getX() + _player->getPlayerImage()->getFrameWidth()/2 < 0)
	//{
	//	_player->setBack(true);
	//	SCENEMANAGER->changeScene("scene1_2");
	//}
}

void scene1_3::render()
{
	IMAGEMANAGER->render("스테이지1_3", getMemDC());
	//IMAGEMANAGER->render("스테이지1_3_MG", getMemDC());
	//_scene1_3Tile->render();
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
}

void scene1_3::boxCollision(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &player->getPlayerImage()->getBoundingBox(), &rc))
	{
		//player->setStageFlag(4);
		SCENEMANAGER->changeScene("scene1_4");
	}

}
