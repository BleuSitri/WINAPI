#include "stdafx.h"
#include "battleScene.h"

battleScene::battleScene()
{
}

battleScene::~battleScene()
{
}

HRESULT battleScene::init()
{
	_map1_1 = new map1_1();
	_map1_1->init();

	return S_OK;
}

void battleScene::release()
{
	SAFE_DELETE(_map1_1);
}

void battleScene::update()
{
	_map1_1->update();
}

void battleScene::render()
{
	_map1_1->render();
}
