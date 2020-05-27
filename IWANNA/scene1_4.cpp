#include "stdafx.h"
#include "scene1_4.h"


scene1_4::scene1_4()
{
}


scene1_4::~scene1_4()
{
}

HRESULT scene1_4::init()
{
	IMAGEMANAGER->addImage("스테이지1_4", "images/Stage1_4_t.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("스테이지1_4_MG", "images/Stage1_4_MG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//_player->setStageFlag(4);
	//_scene1_4MG = IMAGEMANAGER->findImage("스테이지1_4_MG");
	//_scene1_4Tile = new Tile;
	//_scene1_4Tile->init(32, 24, 32, 32, tileArr);
	_player = new player;
	_player->init();
	_player->getPlayerImage()->setX(5);
	_player->getPlayerImage()->setY(650);

	rc = RectMakeCenter(1014, 430, 10, 30);
	return S_OK;
}

void scene1_4::release()
{

}

void scene1_4::update()
{
	boxCollision(_player);
}

void scene1_4::render()
{
	IMAGEMANAGER->render("스테이지1_4", getMemDC());
	//IMAGEMANAGER->render("스테이지1_4_MG", getMemDC());
	//_scene1_4Tile->render();
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
}

void scene1_4::boxCollision(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &player->getPlayerImage()->getBoundingBox(), &rc))
	{
		//player->setStageFlag(5);
		SCENEMANAGER->changeScene("bossIntro");
	}

}
