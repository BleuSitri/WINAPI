#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);
	//IMAGEMANAGER->addImage("bullet", "images/bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "images/verybigbluebubble.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("시공", "images/sigong.bmp", 250, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boss", "images/솔그린.bmp", 270, 400, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("player", "images/guy.bmp", 200, 200, 5,8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player", "images/guy.bmp", 200, 330, 5, 8, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("title", "images/sceneTitle.bmp", 1024, 768, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("dead", "images/dead.bmp", 200, 19, 9, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("dead", "images/dead.bmp", 200, 330, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gameOver", "images/gameOver.bmp", 5500, 600, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("_bulletPool_YellowSTAR", "images/YellowStar.bmp", 29, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("_bulletPool_BLUEBUBBLE", "images/bluebubble.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("_bulletPool_BIGREDBUBBLE", "images/bigredbubble.bmp", 29, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("_bulletPool_VERYBIGBLUEBUBBLE", "images/verybigbluebubble.bmp", 62, 62, true, RGB(255, 0, 255));





	/*_player = new Character;*/

	IMAGEMANAGER->addImage("floor", "images/tile.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("spike", "images/spike.bmp", 32, 32, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("보스인트로", "images/솔그린2.bmp", 200, WINSIZEY, 700, 800, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("보스방다리", "images/보스방다리.bmp", 307, 650, 412, 143, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("보스방마젠타", "images/보스맵_마젠타_t.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_1_MG", "images/Stage1_1_MG.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_2_MG", "images/Stage1_2_MG.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_3_MG", "images/Stage1_3_MG.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("스테이지1_4_MG", "images/Stage1_4_MG.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));


	_player = new player;
	_player->init();

	_boss = new bossClass;
	_boss->init();

	//_scene1 = new scene1;
	//_scene1->init();

	//_scene1_1 = new scene1_1;
	//_scene1_1->init();
	//_scene1_2 = new scene1_2;
	//_scene1_2->init();
	//_scene1_3 = new scene1_3;
	//_scene1_3->init();
	//_scene1_4 = new scene1_4;
	//_scene1_4->init();

	_player->setEnemyMemoryLink(_boss);
	_boss->setPlayerMemoryLink(_player);

	//playerSetFlag(_player);

	

	//_player->setStageFlag(1);
	//_player->setStageFlag(2);
	//_player->setStageFlag(3);
	//_player->setStageFlag(4);
	//_player->setStageFlag(5);
	//_player->setStageFlag(6);
	//_scene1->setPlayerMemoryLink(_player);
	//_scene1_1->setPlayerMemoryLink(_player);
	//_player->setStageFlag(2);
	//if (_scene1->getFlag() == 1)
	//{
	//	_player->setStageFlag(2);
	//}


	SCENEMANAGER->addScene("sceneTitle", new sceneTitle);
	SCENEMANAGER->addScene("scene1_1", new scene1_1);
	SCENEMANAGER->addScene("scene1_2", new scene1_2);
	SCENEMANAGER->addScene("scene1_3", new scene1_3);
	SCENEMANAGER->addScene("scene1_4", new scene1_4);
	SCENEMANAGER->addScene("bossIntro", new bossIntro);
	SCENEMANAGER->addScene("bossScene", new bossScene);


	//SCENEMANAGER->changeScene("scene1_1");
	SCENEMANAGER->changeScene("bossScene");
	//SCENEMANAGER->changeScene("sceneTitle");

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	//SAFE_DELETE(_rocket);
	//SAFE_DELETE(_enemyManager);
	SAFE_DELETE(_player);
	SAFE_DELETE(_boss);
}

void mainGame::update()
{
	gameNode::update();
	if(_player->getStageFlag()>=1)
		_player->update();
	if(_player->getStageFlag() == 6)
		_boss->update();

	//_boss->collision();

	//if (_boss->getCollision())
	//{
	//	//_player->dead();
	//	_player->setBoolDead(true);
	//}


	//_scene1->update();

	//mouseMove(2.0f);


	if (SCENEMANAGER->getCurrentScene("scene1_1"))
	{
		_player->setStageFlag(1);
	}
	else if (SCENEMANAGER->getCurrentScene("scene1_2"))
	{
		_player->setStageFlag(2);
	}
	else if (SCENEMANAGER->getCurrentScene("scene1_3"))
	{
		_player->setStageFlag(3);
	}
	else if (SCENEMANAGER->getCurrentScene("scene1_4"))
	{
		_player->setStageFlag(4);
	}
	else if (SCENEMANAGER->getCurrentScene("bossIntro"))
	{
		_player->setStageFlag(5);
	}
	else if (SCENEMANAGER->getCurrentScene("bossScene"))
	{
		_player->setStageFlag(6);
	}

	//_rocket->update();
	//_enemyManager->update();
	//SetCursorPos(_player->getPlayerImage()->getX(), _player->getPlayerImage()->getY());


	SCENEMANAGER->update();
	
}

void mainGame::render(/*HDC hdc*/)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================

	//IMAGEMANAGER->render("배경화면", getMemDC());
	SCENEMANAGER->render();

	//_rocket->render();
	//_enemyManager->render();

	//char str[256];
	//wsprintf(str, "%s", _player->getBool());
	//TextOut(getMemDC(), 0, 100, str, strlen(str));


	//char mouseXY[256];
	//wsprintf(mouseXY, "x: %d, y: %d", m_ptMouse.x, m_ptMouse.y);
	//TextOut(getMemDC(), 0, 160, mouseXY, strlen(mouseXY));

	//if (_player->getGroundBool())
	//{
	//	TextOut(getMemDC(), 0, 100, "isGround : true", strlen("isGround : true"));
	//}
	//else if (!_player->getGroundBool())
	//{
	//	TextOut(getMemDC(), 0, 100, "isGround : false", strlen("isGround : false"));
	//}
	//if (_player->getJumpBool())
	//{
	//	TextOut(getMemDC(), 0, 120, "isJump : true", strlen("isJump : true"));
	//}
	//else if (!_player->getJumpBool())
	//{
	//	TextOut(getMemDC(), 0, 120, "isJump : false", strlen("isJump : false"));
	//}
	//if (_player->getLeftBool())
	//{
	//	TextOut(getMemDC(), 0, 140, "isLeft : true", strlen("isLeft : true"));
	//}
	//else if (!_player->getLeftBool())
	//{
	//	TextOut(getMemDC(), 0, 140, "isLeft : false", strlen("isLeft : false"));
	//}
	//char strStage[256];
	//wsprintf(strStage, "_stageFlag : %d", _player->getStageFlag());
	//TextOut(getMemDC(), 0, 180, strStage, strlen(strStage));
	//char strHP[256];
	//wsprintf(strHP, "currentHP : %d", _boss->getCurrentHP());
	//TextOut(getMemDC(), 0, 200, strHP, strlen(strHP));

	//if (_boss->getCollision())//(_player->getBoolDead())
	//{
	//	TextOut(getMemDC(), 0, 240, "죽었다!", strlen("죽었다!"));
	//}

	if (_player->getStageFlag() == 6)
		_boss->render();
	if (_player->getStageFlag() >= 1)
		_player->render();

	TIMEMANAGER->render(getMemDC());
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);


}

//void mainGame::mouseMove(float speed)
//{
//	LPPOINT mousePos;
//	mousePos = new POINT;
//
//	//GetCursorPos(mousePos);
//	//ScreenToClient(, mousePos);
//	//getDistance(mousePos->x, mousePos->y,
//	//	_player->getPlayerImage()->getX() + (_player->getPlayerImage()->getWidth()) / 2,
//	//	_player->getPlayerImage()->getY() + (_player->getPlayerImage()->getHeight()) / 2);
//
//	if (m_ptMouse.x > _player->getPlayerImage()->getX() + (_player->getPlayerImage()->getWidth()) / 2)
//	{
//		SetCursorPos(m_ptMouse.x - speed, m_ptMouse.y);
//	}
//	if (m_ptMouse.x < _player->getPlayerImage()->getX() + (_player->getPlayerImage()->getWidth()) / 2)
//	{
//		SetCursorPos(m_ptMouse.x + speed, m_ptMouse.y);
//	}
//	if (m_ptMouse.y > _player->getPlayerImage()->getY() + (_player->getPlayerImage()->getHeight()) / 2)
//	{
//		SetCursorPos(m_ptMouse.x, m_ptMouse.y - speed);
//	}
//	if (m_ptMouse.y < _player->getPlayerImage()->getY() + (_player->getPlayerImage()->getHeight()) / 2)
//	{
//		SetCursorPos(m_ptMouse.x, m_ptMouse.y + speed);
//	}
//
//	//SetCursorPos(m_ptMouse.x, m_ptMouse.y);
//	////나로호로 발사하기
//	//_bullet->fire(rc.left + (rc.right - rc.left) / 2, rc.bottom + (rc.top - rc.bottom) / 2,
//	//	getAngle(rc.left + (rc.right - rc.left) / 2,
//	//		rc.bottom + (rc.top - rc.bottom) / 2,
//	//		_rocket->getRocketImage()->getX() + _rocket->getRocketImage()->getWidth() / 2,
//	//		_rocket->getRocketImage()->getY()), 5.0f);
//
//	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
//	//{
//	//	_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
//	//	_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;
//
//	//	_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
//	//		_viBullet->bulletImage->getWidth(),
//	//		_viBullet->bulletImage->getHeight());
//
//	//	if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
//	//	{
//	//		_viBullet = _vBullet.erase(_viBullet);
//	//	}
//	//	else ++_viBullet;
//
//	//}
//
//}

//void mainGame::playerSetFlag(player * player)
//{
//	if(_scene1->getFlag()==2)
//		player->setStageFlag(2);
//}