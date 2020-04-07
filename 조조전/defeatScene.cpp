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
	IMAGEMANAGER->addImage("�й��", "images/��/�й��.bmp", 1176, 960, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��fadeOut", "images/��/��fadeOut.bmp", 1176, 960, true, RGB(255, 0, 255));

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
	IMAGEMANAGER->render("�й��", getMemDC());
	IMAGEMANAGER->findImage("��fadeOut")->alphaRender(getMemDC(), alpha);
}
