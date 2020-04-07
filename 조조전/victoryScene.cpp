#include "stdafx.h"
#include "victoryScene.h"



victoryScene::victoryScene()
{
}


victoryScene::~victoryScene()
{
}

HRESULT victoryScene::init()
{
	IMAGEMANAGER->addImage("½Â¸®¾À", "images/¾À/½Â¸®¾À.bmp", 1176, 960, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¾ÀfadeOut", "images/¾À/¾ÀfadeOut.bmp", 1176, 960, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("titleScene",new titleScene);
	isVictorySceneTime = true;

	return S_OK;
}

void victoryScene::release()
{
}

void victoryScene::update()
{
	count++;
	alpha = count / 10;
	//if (isVictorySceneTime)
	//{
	//	alpha = count / 10;
	//}
	if (isVictorySceneTime)
	{
		count += TIMEMANAGER->getElapsedTime();
	}
	if (alpha < 255)
	{
		alpha = count;

	}
	if (alpha >= 255)
	{
		alpha = 255;
		isVictorySceneTime = false;
		SCENEMANAGER->changeScene("titleScene");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		count = 0;
		alpha = 0;
		isVictorySceneTime = false;
		SCENEMANAGER->changeScene("titleScene");
	}
}

void victoryScene::render()
{
	IMAGEMANAGER->render("½Â¸®¾À", getMemDC());
	IMAGEMANAGER->findImage("¾ÀfadeOut")->alphaRender(getMemDC(), alpha);
}
