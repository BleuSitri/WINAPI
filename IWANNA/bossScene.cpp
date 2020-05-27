#include "stdafx.h"
#include "bossScene.h"


bossScene::bossScene()
{
}


bossScene::~bossScene()
{
}

HRESULT bossScene::init()
{
	IMAGEMANAGER->addImage("보스맵", "images/보스방.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("보스방마젠타", "images/보스방.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_bossBridge = IMAGEMANAGER->findImage("보스방다리");
	_bossBridge->setX(307);
	_bossBridge->setY(668);

	_bossMapMG = IMAGEMANAGER->findImage("보스방마젠타");
	_bossMapMG->setX(0);
	_bossMapMG->setY(0);
	//_player->setStageFlag(6);

	_boss = new bossClass;
	_boss->init();
	_player = new player;
	_player->init();
	_player->getPlayerImage()->setX(500);
	_player->getPlayerImage()->setY(600);
	//rc = RectMake(310, 670, 410, 20);
	//_player->getPlayerImage()->setX(rc.left + (rc.right - rc.left) / 2);
	//_player->getPlayerImage()->setY(rc.top - _player->getPlayerImage()->getHeight());

	//_maxHP = _currentHP = 100;
	//_hpBar = new progressBar;
	//_hpBar->init("images/체력바.bmp", "images/체력바배경.bmp", 0, 1, WINSIZEX, 20);
	//_hpBar->setGauge(_currentHP, _maxHP);

	//_player->setEnemyMemoryLink(_boss);
	//_boss->setPlayerMemoryLink(_player);


	return S_OK;
}

void bossScene::release()
{
	SAFE_DELETE(_boss);
	SAFE_DELETE(_player);
}

void bossScene::update()
{
	//_boss->update();

	//_hpBar->setGauge(_currentHP, _maxHP);
	//_hpBar->update();
}

void bossScene::render()
{
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	IMAGEMANAGER->render("보스맵", getMemDC());

	//IMAGEMANAGER->render("보스방마젠타", getMemDC());
	//_bossMapMG->render(getMemDC(), _bossMapMG->getX(), _bossMapMG->getY());


	//_hpBar->render();
	_bossBridge->render(getMemDC(), _bossBridge->getX(), _bossBridge->getY());
	//_boss->render();
}
