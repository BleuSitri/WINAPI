#include "stdafx.h"
#include "scene1.h"


scene1::scene1()
{
}


scene1::~scene1()
{
}

HRESULT scene1::init()
{
	//IMAGEMANAGER->addImage("사나1", "images/사나1.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	_scene1_1 = new scene1_1;
	_scene1_1->init();
	_scene1_2 = new scene1_2;
	_scene1_2->init();
	_scene1_3 = new scene1_3;
	_scene1_3->init();
	_scene1_4 = new scene1_4;
	_scene1_4->init();
	
	return S_OK;
}

void scene1::release()
{
}

void scene1::update()
{
	RECT temp;
	if (IntersectRect(&temp, &_player->getPlayerImage()->getBoundingBox(), &_scene1_1->getRc()))
	{
		flag = 1;
	}
	if (IntersectRect(&temp, &_player->getPlayerImage()->getBoundingBox(), &_scene1_2->getRc()))
	{
		flag = 2;
	}
	if (IntersectRect(&temp, &_player->getPlayerImage()->getBoundingBox(), &_scene1_3->getRc()))
	{
		flag = 3;
	}
	if (IntersectRect(&temp, &_player->getPlayerImage()->getBoundingBox(), &_scene1_4->getRc()))
	{
		flag = 4;
	}
	//if(KEYMANAGER->isOnceKeyDown('2'))
	//{
	//	SCENEMANAGER->changeScene("scene2");
	//}
}

void scene1::render()
{
	//IMAGEMANAGER->render("사나1",getMemDC());
}


