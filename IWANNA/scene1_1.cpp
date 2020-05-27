#include "stdafx.h"
#include "scene1_1.h"
//#include "player.h"


scene1_1::scene1_1()
{
}


scene1_1::~scene1_1()
{
}

HRESULT scene1_1::init()
{
	//stage1_1 = true;
	//IMAGEMANAGER->addImage("맵", "images/맵.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_1", "images/Stage1_1_t.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_1_MG", "images/Stage1_1_MG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_scene1_1MG = IMAGEMANAGER->findImage("스테이지1_1_MG");

	//_scene1_1Tile = new Tile;
	//_scene1_1Tile->init(32,24, 32,32, tileArr);
	_player = new player;
	_player->init();
	//_player->_stageFlag = 1;
	/*setPlayerMemoryLink(_player);*/

	_player->setStageFlag(1);

	//rc = RectMakeCenter(WINSIZEX-10,300,30,30);
	rc = RectMake(887, 600, 45, 100);
	return S_OK;
}

void scene1_1::release()
{
}

void scene1_1::update()
{

	//COLORREF colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getPlayerImage()->getX() + _player->getPlayerImage()->getFrameWidth() / 2, _player->getPlayerImage()->getY() + _player->getPlayerImage()->getFrameHeight());
	//if (!(colorMove == RGB(255, 0, 255)))
	//{
	//	_player->setCollision(true);
	//}
	//else
	//	_player->setCollision(false);

	boxCollision(_player);
}

void scene1_1::render()
{
	//for (int i = 0; i < WINSIZEX;i+=32)
	//{
	//	for (int j=0;j<WINSIZEY;j+=32)
	//	{
	//		Rectangle(getMemDC(), i, j, i + 32, j + 32);
	//	}
	//}
	IMAGEMANAGER->render("스테이지1_1", getMemDC());
	//IMAGEMANAGER->render("스테이지1_1_MG", getMemDC());
	
	//_scene1_1Tile->render();
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	//if (_scene1_1Tile->getBool())
	//{
	//	TextOut(getMemDC(), 0, 300, "TileID = 0", strlen("TileID = 0"));
	//}
}

void scene1_1::boxCollision(player * player)
{
	RECT temp;
	if (IntersectRect(&temp, &player->getPlayerImage()->getBoundingBox(), &rc))
	{
		//player->_stageFlag = 2;
		//player->setStageFlag(2);
		//*player->_stageFlag = 2;
		//player->setStageFlag(player->getStageFlag() + 1);
		//_player->getPlayerImage()->setX(50);
		//_player->getPlayerImage()->setY(30);

		player->setStageFlag(2);
		//flag = 2;
		SCENEMANAGER->changeScene("scene1_2");
	}
}

void scene1_1::setFlag(player & player, int flag)
{
	player.setStageFlag(flag);
}
