#include "stdafx.h"
#include "scene1_2.h"


scene1_2::scene1_2()
{
}


scene1_2::~scene1_2()
{
}

HRESULT scene1_2::init()
{
	//stage1_2 = true;

	IMAGEMANAGER->addImage("스테이지1_2", "images/Stage1_2_t.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_2_MG", "images/Stage1_2_MG.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	_scene1_2MG = IMAGEMANAGER->findImage("스테이지1_2_MG");

	//_scene1_2Tile = new Tile;
	//_scene1_2Tile->init(32, 24, 32, 32, tileArr);
	
	_player = new player;
	_player->init();

	//if (_player->getLoad() == true)
	//{
	//	vector<string> vStr(TXTDATA->txtLoad("save/playerSave.txt"));
	//	_player->getPlayerImage()->setX(stoi(vStr[0]));
	//	_player->getPlayerImage()->setY(stoi(vStr[1]));
	//}
	//else
	//{
		//_player->getPlayerImage()->setX(50);
		//_player->getPlayerImage()->setY(30);
	//}
	//_player->setLoad(false);
	_player->getPlayerImage()->setX(50);
	_player->getPlayerImage()->setY(30);

	_player->setStageFlag(2);

	//rc = RectMakeCenter(600, 600, 30, 30);

	return S_OK;
}

void scene1_2::release()
{
}

void scene1_2::update()
{
	boxCollision(_player);
}

void scene1_2::render()
{
	IMAGEMANAGER->render("스테이지1_2", getMemDC());
	//IMAGEMANAGER->render("스테이지1_2_MG", getMemDC());
	//_scene1_2Tile->render();
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
}

void scene1_2::boxCollision(player * player)
{
	RECT temp;
	//if (IntersectRect(&temp, &player->getPlayerImage()->getBoundingBox(), &rc))
	if (_player->getPlayerImage()->getX() + _player->getPlayerImage()->getFrameWidth() > WINSIZEX)
	{
		stage1_2 = false;
		//player->setStageFlag(3);
		SCENEMANAGER->changeScene("scene1_3");
	}

}
