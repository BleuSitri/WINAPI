#include "stdafx.h"
#include "defeatScene.h"



defeatScene::defeatScene()
{
}


defeatScene::~defeatScene()
{
}

HRESULT defeatScene::init()
{
	IMAGEMANAGER->addImage("ÆÐ¹è¾À", "images/¾À/ÆÐ¹è¾À.bmp", 1176, 960, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¾ÀfadeOut", "images/¾À/¾ÀfadeOut.bmp", 1176, 960, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("titleScene", new titleScene);
	isDefeatSceneTime = true;
	return S_OK;
}

void defeatScene::release()
{
}

void defeatScene::update()
{
	count++;
	alpha = count / 10;
	//if (isVictorySceneTime)
	//{
	//	alpha = count / 10;
	//}
	if (isDefeatSceneTime)
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
		isDefeatSceneTime = false;
		SCENEMANAGER->changeScene("titleScene");
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		isDefeatSceneTime = false;
		SCENEMANAGER->changeScene("titleScene");
	}
}

void defeatScene::render()
{
	IMAGEMANAGER->render("ÆÐ¹è¾À", getMemDC());
	IMAGEMANAGER->findImage("¾ÀfadeOut")->alphaRender(getMemDC(), alpha);
}
