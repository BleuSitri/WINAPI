#include "stdafx.h"
#include "bossIntro.h"


bossIntro::bossIntro()
{
}


bossIntro::~bossIntro()
{
}

HRESULT bossIntro::init()
{
	IMAGEMANAGER->addImage("보스맵", "images/보스방.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
		
	_bossIntroImage = IMAGEMANAGER->findImage("보스인트로");
	_bossIntroImage->setX(150);

	_bossIntroBridge = IMAGEMANAGER->findImage("보스방다리");
	_bossIntroBridge->setX(307);
	_bossIntroBridge->setY(668);
	//_player->setStageFlag(5);
	_player = new player;
	_player->init();
	rc = RectMake(310, 670, 410, 20);
	_player->getPlayerImage()->setX(rc.left + (rc.right - rc.left) / 2);
	_player->getPlayerImage()->setY(rc.top - _player->getPlayerImage()->getHeight());


	return S_OK;
}

void bossIntro::release()
{
	//SAFE_DELETE(_boss);
}

void bossIntro::update()
{
	//_boss->update();
	speed = 1.0f;
	if (_bossIntroImage->getY() <= 300)
	{
		speed = 10.0f;
	}
	_bossIntroImage->setY(_bossIntroImage->getY() - speed);
	if (_bossIntroImage->getY() + _bossIntroImage->getHeight()<=0)
	{
		//_player->setStageFlag(6);
		SCENEMANAGER->changeScene("bossScene");
	}
}

void bossIntro::render()
{
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	IMAGEMANAGER->render("보스맵", getMemDC());
	//IMAGEMANAGER->render("보스방마젠타", getMemDC());
	_bossIntroImage->render(getMemDC(), _bossIntroImage->getX(), _bossIntroImage->getY());
	_bossIntroBridge->render(getMemDC(), _bossIntroBridge->getX(), _bossIntroBridge->getY());

}
