#include "stdafx.h"
#include "sceneTitle.h"
//#include "player.h"


sceneTitle::sceneTitle()
{
}


sceneTitle::~sceneTitle()
{
}

HRESULT sceneTitle::init()
{
	//stage1_1 = true;
	//IMAGEMANAGER->addImage("¸Ê", "images/¸Ê.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("title", "images/sceneTitle.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	return S_OK;
}

void sceneTitle::release()
{
}

void sceneTitle::update()
{
	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		SCENEMANAGER->changeScene("scene1_1");
	}
}

void sceneTitle::render()
{
	IMAGEMANAGER->render("title", getMemDC());
}


void sceneTitle::setFlag(player & player, int flag)
{
	player.setStageFlag(flag);
}
