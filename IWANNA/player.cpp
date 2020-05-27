#include "stdafx.h"
#include "player.h"
#include "bossClass.h"
#pragma warning(disable:4996)


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_player = IMAGEMANAGER->findImage("player");
	rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _player->getFrameWidth(), _player->getFrameHeight());//_player->getFrameWidth(), _player->getFrameHeight());
	tempGroundRc = RectMake(0, 650, 800, 100);
	_gameOver = IMAGEMANAGER->findImage("gameOver");

	mouseRECT = RectMake(m_ptMouse.x, m_ptMouse.y, 2, 2);
	
	_bossMapMG = IMAGEMANAGER->findImage("보스방마젠타");
	_scene1_1MG = IMAGEMANAGER->findImage("스테이지1_1_MG");
	_scene1_2MG = IMAGEMANAGER->findImage("스테이지1_2_MG");
	_scene1_3MG = IMAGEMANAGER->findImage("스테이지1_3_MG");
	_scene1_4MG = IMAGEMANAGER->findImage("스테이지1_4_MG");

	_player->setX(70);
	_player->setY(470);


	_isDead = false;
	_canMove = true;

	playerMove = MOVE_NONE;
	jumpSpeed = 0;
	jumpPower = 0;

	_deadIndex = 0;

	_stageFlag = 0;

	_gravity = 5.0f;
	firstJump = true;
	secondJump = false;

	_bulletPool = new objectPool;
	_bulletPool->init("bullet");

	//SetCursorPos(200, 200);
	//SetCursorPos(500, 500);
	x = m_ptMouse.x;
	y = m_ptMouse.y;
	mouseRECT = RectMake(x, y, 10, 20);

	/*GetCursorPos(&m_ptMouse);
	ClientToScreen(m_hWnd, &m_ptMouse);*/


	_tile = new Tile;
	_isLoad = false;

	return S_OK;
}

void player::release()
{
	SAFE_DELETE(_bulletPool);
}

void player::update()
{
	
	//POINT pt;
	//GetCursorPos(&pt);
	//ClientToScreen(m_hWnd, &pt);

	//ScreenToClient(m_hWnd, &m_ptMouse);
	//deltaTime += TIMEMANAGER->getElapsedTime();
	//if (deltaTime >= 2)
	//{
	//	setMouseMoveFlag(false);
	//	deltaTime = 0;
	//}
	RECT temp1;
	//RECT mouseRECT = RectMake(m_ptMouse.x, m_ptMouse.y, 2, 2);

	// 윈도우창의 마우스 x, y좌표 구해서 넣기

	//float x = m_ptMouse.x;
	//float y = m_ptMouse.y;

	//float speed = 5.0f;
	//if ((getDistance(x, y, _player->getX() + _player->getFrameWidth(), _player->getX() + _player->getFrameWidth()) > 0))
	//SetCursorPos(x++, y++);

	if(_stageFlag != 6 && _stageFlag != 5 &&!IntersectRect(&temp1, &mouseRECT, &rc))//(getMouseMoveFlag() == false) )//getDistance(m_ptMouse.x, m_ptMouse.y, _player->getX() + _player->getFrameWidth()/2, _player->getX() + _player->getFrameWidth()/2 > 0)) //(getDistance(m_ptMouse.x,m_ptMouse.y, _player->getX() + _player->getFrameWidth(), _player->getX() + _player->getFrameWidth())>0) //(!IntersectRect(&temp1, &mouseRECT, &rc))//(getMouseMoveFlag() == false) //
	{
		if (x < _player->getX() + _player->getFrameWidth()/2)
		{
			x++;
		}
		if (x >= _player->getX() + _player->getFrameWidth()/2)
		{
			x--;
		}
		if (y >= _player->getY()+ _player->getFrameHeight()/2)
		{
			y--;
		}
		if (y < _player->getY() + _player->getFrameHeight()/2)
		{
			y++;
		}
		SetCursorPos(x+108, y+28);
	}
	mouseRECT = RectMake(x, y, 8, 14);

	if (IntersectRect(&temp1, &mouseRECT, &rc))
	{
		_isDead = true;
	}
	//mouseMove(1.0f, m_ptMouse.x, m_ptMouse.y);
	if ((characterPixelbottomMove() == RGB(0, 0, 255)))
	{
		setCollision(true);
	}
	else if ((characterPixelbottomMove() == RGB(255, 0, 0 )))
	{
		_isDead = true;
	}
	else
		setCollision(false);

	if ((characterPixeltopMove() == RGB(0, 0, 255)))
	{
		jumpPower = 0;
		firstJump = false;
	}
	else if ((characterPixeltopMove() == RGB(255, 0, 0)))
	{
		_isDead = true;
	}

	if ((characterPixelrightMove() == RGB(0, 0, 255)))
	{
		_player->setX(_player->getX());
	}
	else if ((characterPixelrightMove() == RGB(255, 0, 0)))
	{
		_isDead = true;
	}
	if ((characterPixelleftMove() == RGB(0, 0, 255)))
	{
		_player->setX(_player->getX());
	}
	else if ((characterPixelleftMove() == RGB(255, 0, 0)))
	{
		_isDead = true;
	}

	//if ((characterPixelMove() == RGB(0, 0, 255)))
	//{
	//	setGravity(0);
	//	setDrop(false);
	//}
	//else if ((characterPixelMove() == RGB(255, 0, 0, )))
	//{
	//	_isDead = true;
	//}
	//else
	//{
	//	setDrop(true);
	//}

	RECT temp;
	if (_canMove)
	{
		collision();
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			playerMove = MOVE_RIGHT;
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			playerMove = MOVE_LEFT;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			playerMove = MOVE_RIGHTSTOP;
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			playerMove = MOVE_LEFTSTOP;
		}
		if (firstJump && KEYMANAGER->isStayKeyDown('Z'))
		{

			jump();
			//if (!_isLeft)
			//	playerMove = MOVE_RIGHTJUMP;
			//else
			//	playerMove = MOVE_LEFTJUMP;
		}
		if (secondJump && KEYMANAGER->isStayKeyDown('Z'))
		{

			Doublejump();
			//jump();
		}

		if (KEYMANAGER->isOnceKeyUp('Z'))
		{
			firstJump = true;
		}


		//if (KEYMANAGER->isOnceKeyDown('Z'))
		//{
		//	jump();
		//}
		//if (KEYMANAGER->isOnceKeyUp('Z'))
		//{
		//	jFlag = 0;
		//}
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			fire();
		}
		//if (KEYMANAGER->isOnceKeyDown('S'))
		//{
		//	//bulletpool에 getRect만들고 충돌했을때 저장하도록 조건문 바꾸기
		//	char temp[64];
		//	vector<string>vStr;
		//	

		//	vStr.push_back(_itoa(_player->getX(), temp, 10));
		//	vStr.push_back(_itoa(_player->getY(), temp, 10));
		//	if (_stageFlag == 1)
		//		vStr.push_back("scene1_1");
		//	if (_stageFlag == 2)
		//		vStr.push_back("scene1_2");
		//	if (_stageFlag == 3)
		//		vStr.push_back("scene1_3");
		//	if (_stageFlag == 4)
		//		vStr.push_back("scene1_4");

		//	TXTDATA->txtSave("save/playerSave.txt", vStr);
		//}



		if (bulletMove() == RGB(2, 2, 255))
		{
			//bulletpool에 getRect만들고 충돌했을때 저장하도록 조건문 바꾸기
			char temp[64];
			vector<string>vStr;


			vStr.push_back(_itoa(_player->getX(), temp, 10));
			vStr.push_back(_itoa(_player->getY(), temp, 10));
			vStr.push_back(_itoa(deadCount, temp, 10));
			if (_stageFlag == 1)
				vStr.push_back("scene1_1");
			if (_stageFlag == 2)
				vStr.push_back("scene1_2");
			if (_stageFlag == 3)
				vStr.push_back("scene1_3");
			if (_stageFlag == 4)
				vStr.push_back("scene1_4");

			TXTDATA->txtSave("save/playerSave.txt", vStr);
		}

		_bulletPool->update();
		move();
	}

	collision();



	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		vector<string> vStr(TXTDATA->txtLoad("save/playerSave.txt"));
		_deadIndex = 0;
		_isLoad = true;
		SCENEMANAGER->changeScene(vStr[3]);
		_player->setX(stoi(vStr[0]));
		_player->setY(stoi(vStr[1]));
		deadCount = stoi(vStr[2]);
		_player = IMAGEMANAGER->findImage("player");
		_isDead = false;
	}

	if (_isDead)
	{
		_canMove = false;
		//gameOver();
		dead();
	}
	if (!_isDead)
	{
		_canMove = true;
		//init();
	}


}

void player::move()
{
	//COLORREF colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX()+_player->getFrameWidth()/2,_player->getY()+_player->getFrameHeight());
	//if (!(colorMove == RGB(255, 0, 255)))
	//{
	//	_isGround = true;
	//	jumpPower = 0;
	//	fallSpeed = 0;
	//	rc.bottom = _tile->getRect().top;
	//	rc.top = rc.bottom - 50;
	//	jFlag = 0;
	//}
	//else
	//	_isGround = false;

	//if (!(colorMove == RGB(255, 0, 255)))
	//{
	//	_player->setPlayerRcTopBottom(i - (_player->getPlayerRc().bottom - _player->getPlayerRc().top), i);
	//	_player->setdropbool(false);
	//	_player->setGravity(0);
	//	break;
	//}



	//if (!(characterPixelMove() == RGB(255, 0, 255)))
	//{
	//	setCollision(true);
	//}
	//else
	//	setCollision(false);

	//if ((characterPixelMove() == RGB(0, 0, 255)))
	//{
	//	setCollision(true);
	//}
	//else
	//	setCollision(false);


	if (_isBool)
	{

		_isGround = true;
		jumpPower = 0;
		fallSpeed = 0;
	}
	else if (!_isBool)
	{
		_isGround = false;
	}


	//if (_isBool)
	//{
	//	_isGround = true;
	//	jumpPower = 0;
	//	fallSpeed = 0;
	//	rc.bottom = _tile->getRect().top;
	//	rc.top = rc.bottom - 50;
	//	jFlag = 0;
	//}
	//else if(!_isBool)
	//{
	//	_isGround = false;
	//}



	//if (_isBool)
	//{
	//	_isGround = true;
	//	jumpCount = 0;
	//}
	//else
	//{
	//	_isGround = false;
	//}

	//if (_isDrop)
	//{
	//	setGravity(7.0f);
	//}

	//_player->setY(_player->getY() + _gravity);

	_count++;
	RECT temp;

	if (!_isGround)
	{
		fallSpeed += GRAVITY;
		if (fallSpeed > 8)
		{
			fallSpeed = 8;
		}
		_player->setY(_player->getY() + fallSpeed);
	}


	//if (_isJump)
	//{
	//	jump();
	//}

	//jumpCount += 0.1f;
	//fallSpeed = jumpCount*GRAVITY;
	//if (_isJump)
	//	jump();
	//_player->setY(_player->getY() + fallSpeed*jumpCount);
	//jumpCount += 0.1f;
	//jumpSpeed = (jumpCount*jumpCount*(-GRAVITY) / 2) + (jumpCount*jumpPower);

	switch (playerMove)
	{
	case MOVE_NONE:
		playerMove = MOVE_RIGHTSTOP;
		break;
	case MOVE_RIGHTSTOP:
		_player->setFrameY(0);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= 3)
			{
				_index = 0;
			}
			_player->setFrameX(_index);
		}
		break;
	case MOVE_LEFTSTOP:
		_player->setFrameY(1);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index--;
			if (_index < 0)
			{
				_index = 3;
			}
			_player->setFrameX(_index);
		}
		break;
	case MOVE_RIGHT:
		_isLeft = false;
		_player->setX(_player->getX() + PLAYERSPEED);

		_player->setFrameY(2);
			
		if (_count % 9 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= 4)
			{
				_index = 0;
			}
			_player->setFrameX(_index);
		}

		break;
	case MOVE_LEFT:
		_isLeft = true;
		_player->setX(_player->getX() - PLAYERSPEED);
		_player->setFrameY(3);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index--;
			if (_index < 0)
			{
				_index = 4;
			}
			_player->setFrameX(_index);
		}
		break;
	case MOVE_RIGHTJUMP:
		//jump();
		_player->setFrameY(4);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index--;
			if (_index < 0)
			{
				_index = 1;
			}
			_player->setFrameX(_index);
		}
		break;
	case MOVE_LEFTJUMP:
		//jump();
		_player->setFrameY(5);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= 1)
			{
				_index = 0;
			}
			_player->setFrameX(_index);
		}


		break;
	case MOVE_FALLING:
		if (_isLeft)
		{
			_player->setFrameY(7);
			if (_count % 9 == 0)
			{
				_count = 0;
				_index--;
				if (_index < 0)
				{
					_index = 1;
				}
				_player->setFrameX(_index);
			}
		}
		else if (!_isLeft)
		{
			_player->setFrameY(6);
			if (_count % 9 == 0)
			{
				_count = 0;
				_index++;
				if (_index >= 1)
				{
					_index = 0;
				}
				_player->setFrameX(_index);
			}
		}


		break;
	default:
		break;
	}




	//rc = RectMakeCenter(_player->getX(), _player->getY(), _player->getWidth(), _player->getHeight());
	rc = RectMake(_player->getX()+10, _player->getY()+10, 20, 10);
	//rc = RectMake(_player->getX(), _player->getY(), _player->getFrameWidth(), _player->getFrameHeight());
}

void player::fire()
{
	if (!_isLeft)
	{
		_bulletPool->fire(rc.right, rc.top + (rc.bottom - rc.top) / 2, 0, 13.0f);
		/*_bulletPool->fire(mouseRECT.right,mouseRECT.top + (mouseRECT.bottom-mouseRECT.top) / 2, 0, 13.0f);*/
	}
		//_bulletPool->fire(_player->getX()+_player->getWidth(), _player->getX()+_player->getHeight()/2, 0, 10.0f);
	else
		_bulletPool->fire(rc.left, rc.top + (rc.bottom - rc.top) / 2, 0, -13.0f);
		//_bulletPool->fire(_player->getX(), _player->getX() + _player->getHeight() / 2, 0, -10.0f);
}

void player::jump()
{


	_count++;
	//jumpPower += 10.0f;
	//_player->setY(_player->getY() - jumpPower);

	//jumpPower += 30.0f;
	//jumpCount += 0.1f;
	//jumpSpeed = (jumpCount*jumpCount*(-_gravity) / 2) + (jumpCount*jumpPower);

	//_player->setY(_player->getY() - jumpSpeed);
	
	//_isJump = true;
	//jumpPower += 8;
	//if (jumpPower > 100)
	//{
	//	jumpPower = 100;
	//	_isJump = false;
	//	firstJump = false;
	//}
	//if (_isJump)
	//{
	//	_player->setY(_player->getY() - jumpPower);
	//}
	//
	
	
	_isJump = true;
	jumpPower += 8;
	if (jumpPower > 40)
	{
		jumpPower = 40;
		_isJump = false;
		firstJump = false;
	}
	if (_isJump)
	{
		_player->setY(_player->getY() - jumpPower);
	}

	//jFlag = 1;

	//jumpPower = 30.0f;

	//jumpCount += 0.1f;
	//jumpSpeed = (jumpCount*jumpCount*(-_gravity) / 2) + (jumpCount*jumpPower);
	//_player->setY(_player->getY() - jumpSpeed);

	//_isJump = true;


	//if (_isJump)
	//	_player->setY(_player->getY() - jumpPower);
	
	if (_isLeft)
	{
		_player->setFrameY(5);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index++;
			if (_index >= 1)
			{
				_index = 0;
			}
			_player->setFrameX(_index);
		}
	}
	else if (!_isLeft)
	{

		_player->setFrameY(4);
		if (_count % 9 == 0)
		{
			_count = 0;
			_index--;
			if (_index < 0)
			{
				_index = 1;
			}
			_player->setFrameX(_index);
		}
	}
}

void player::Doublejump()
{
	if (_isGround == false)// || firstJump == false)
	{
		_isSJump = true;
		jumpPower += 6;
		if (jumpPower > 36)
		{
			jumpPower = 36;
			_isSJump = false;
			secondJump = false;
		}
		if (_isSJump)
		{
			_player->setY(_player->getY() - jumpPower);
		}
	}
}


void player::render()
{
	//char str[256];
	//wsprintf(str, "jumpSpeed : %f", jumpSpeed);

	//_bossMapMG->render(getMemDC(), _bossMapMG->getX(), _bossMapMG->getY());

	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	//Rectangle(getMemDC(), _tile->getRect().left, _tile->getRect().top, _tile->getRect().right, _tile->getRect().bottom);
	//Rectangle(getMemDC(), _player->getX(), _player->getY(), _player->getX()+_player->getFrameWidth(), _player->getY()+_player->getFrameWidth());
	//Rectangle(getMemDC(), tempGroundRc.left, tempGroundRc.top, tempGroundRc.right, tempGroundRc.bottom);
	//_player->frameRender(getMemDC(), rc.left, rc.top, _player->getFrameX(), _player->getFrameY());

	_player->frameRender(getMemDC(), _player->getX(), _player->getY(), _player->getFrameX(), _player->getFrameY());
	
	//if (_isDead)
	//{
	//	_gameOver->frameRender(getMemDC(), 150, 150, _gameOver->getFrameX(), _gameOver->getFrameY());
	//}

	if(_isDead)
		_gameOver->frameRender(getMemDC(), 150, 150, _gameOver->getFrameX(), _gameOver->getFrameY());
	//_player->frameRender(getMemDC(), _player->getX(), _player->getY(), _player->getFrameX(), _player->getFrameY());
	_bulletPool->render();

	//char mouseXY[256];
	//wsprintf(mouseXY, "x: %d, y: %d", m_ptMouse.x, m_ptMouse.y);
	//TextOut(getMemDC(), 0, 220, mouseXY, strlen(mouseXY));

	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	
	//TextOut(getMemDC(), 0, 200, str, strlen(str));
	//Rectangle(getMemDC(), _player->getBoundingBox().left, _player->getBoundingBox().top, _player->getBoundingBox().right, _player->getBoundingBox().bottom);
	//Rectangle(getMemDC(), mouseRECT.left, mouseRECT.top, mouseRECT.right, mouseRECT.bottom);
}


void player::dead()
{
	_count++;
	_player = IMAGEMANAGER->addFrameImage("dead", "images/dead.bmp", _player->getX(), _player->getY(), 200, 19, 9, 1, true, RGB(255, 0, 255));
	//_player = IMAGEMANAGER->findImage("dead");
	//_deadIndex = 0;
	_player->setFrameY(0);
	if (_count % 12 == 0)
	{
		_count = 0;
		_deadIndex++;
		if (_index >= 8)
		{
			_deadIndex = 8;
		}
		_player->setFrameX(_deadIndex);
	}
	deadCount++;
}

void player::gameOver()
{
	_gameOver = IMAGEMANAGER->findImage("gameOver");
	_gameOver->setFrameY(0);
	if (_count % 5 == 0)
	{
		_count = 0;
		_index++;
		if (_index >= 7)
		{
			_index = 0;
		}
		_gameOver->setFrameX(_index);
	}

	
}

COLORREF player::characterPixelbottomMove()
{
	for (int i = _player->getX()+1; i < _player->getX() +_player->getFrameWidth(); i++)
	{
		COLORREF colorMove = GetPixel(_scene1_1MG->getMemDC(),i, _player->getY() + _player->getFrameHeight());
		if (_stageFlag == 1)
			colorMove = GetPixel(_scene1_1MG->getMemDC(), i, _player->getY() + _player->getFrameHeight());
		else if (_stageFlag == 2)
			colorMove = GetPixel(_scene1_2MG->getMemDC(), i, _player->getY() + _player->getFrameHeight());
		else if (_stageFlag == 3)
			colorMove = GetPixel(_scene1_3MG->getMemDC(), i, _player->getY() + _player->getFrameHeight());
		else if (_stageFlag == 4)
			colorMove = GetPixel(_scene1_4MG->getMemDC(), i, _player->getY() + _player->getFrameHeight());
		else if (_stageFlag == 5)
			colorMove = GetPixel(_bossMapMG->getMemDC(), i, _player->getY() + _player->getFrameHeight());
		else if (_stageFlag == 6)
			colorMove = GetPixel(_bossMapMG->getMemDC(), i, _player->getY() + _player->getFrameHeight());
		return colorMove;
	}
}

COLORREF player::characterPixelrightMove()
{
	for (int i = _player->getY() + 1; i < _player->getY() + _player->getFrameHeight(); i++)
	{
		COLORREF colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getX()+_player->getFrameWidth(), i);
		if (_stageFlag == 1)
			colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getX() + _player->getFrameWidth(), i);
		else if (_stageFlag == 2)
			colorMove = GetPixel(_scene1_2MG->getMemDC(), _player->getX() + _player->getFrameWidth(), i);
		else if (_stageFlag == 3)
			colorMove = GetPixel(_scene1_3MG->getMemDC(), _player->getX() + _player->getFrameWidth(), i);
		else if (_stageFlag == 4)
			colorMove = GetPixel(_scene1_4MG->getMemDC(), _player->getX() + _player->getFrameWidth(), i);
		else if (_stageFlag == 5)
			colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX() + _player->getFrameWidth(), i);
		else if (_stageFlag == 6)
			colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX() + _player->getFrameWidth(), i);
		return colorMove;
	}
}

COLORREF player::characterPixeltopMove()
{
	for (int i = _player->getX() + 1; i < _player->getX() + _player->getFrameWidth(); i++)
	{
		COLORREF colorMove = GetPixel(_scene1_1MG->getMemDC(), i, _player->getY());
		if (_stageFlag == 1)
			colorMove = GetPixel(_scene1_1MG->getMemDC(), i, _player->getY());
		else if (_stageFlag == 2)
			colorMove = GetPixel(_scene1_2MG->getMemDC(), i, _player->getY());
		else if (_stageFlag == 3)
			colorMove = GetPixel(_scene1_3MG->getMemDC(), i, _player->getY());
		else if (_stageFlag == 4)
			colorMove = GetPixel(_scene1_4MG->getMemDC(), i, _player->getY());
		else if (_stageFlag == 5)
			colorMove = GetPixel(_bossMapMG->getMemDC(), i, _player->getY());
		else if (_stageFlag == 6)
			colorMove = GetPixel(_bossMapMG->getMemDC(), i, _player->getY());
		return colorMove;
	}
}

COLORREF player::characterPixelleftMove()
{
	for (int i = _player->getY() + 1; i < _player->getY() + _player->getFrameHeight(); i++)
	{
		COLORREF colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getX(), i);
		if (_stageFlag == 1)
			colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getX(), i);
		else if (_stageFlag == 2)
			colorMove = GetPixel(_scene1_2MG->getMemDC(), _player->getX(), i);
		else if (_stageFlag == 3)
			colorMove = GetPixel(_scene1_3MG->getMemDC(), _player->getX(), i);
		else if (_stageFlag == 4)
			colorMove = GetPixel(_scene1_4MG->getMemDC(), _player->getX(), i);
		else if (_stageFlag == 5)
			colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX(), i);
		else if (_stageFlag == 6)
			colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX(), i);
		return colorMove;
	}
}


//COLORREF player::characterPixelMove()
//{
//	COLORREF colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//	if (_stageFlag == 1)
//		colorMove = GetPixel(_scene1_1MG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//	else if (_stageFlag == 2)
//		colorMove = GetPixel(_scene1_2MG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//	else if (_stageFlag == 3)
//		colorMove = GetPixel(_scene1_3MG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//	else if (_stageFlag == 4)
//		colorMove = GetPixel(_scene1_4MG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//	else if (_stageFlag == 5)
//		colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//	else if (_stageFlag == 6)
//		colorMove = GetPixel(_bossMapMG->getMemDC(), _player->getX() + _player->getFrameWidth() / 2, _player->getY() + _player->getFrameHeight());
//
//	return colorMove;
//}

COLORREF player::bulletMove()
{
	for (int i = 0; i < _bulletPool->getActiveBullet().size(); i++)
	{
		COLORREF colorbullet = GetPixel(_scene1_1MG->getMemDC(), _bulletPool->getActiveBullet().at(i)->getRC().left + (_bulletPool->getActiveBullet().at(i)->getRC().right - _bulletPool->getActiveBullet().at(i)->getRC().left) / 2, _bulletPool->getActiveBullet().at(i)->getRC().top + (_bulletPool->getActiveBullet().at(i)->getRC().bottom - _bulletPool->getActiveBullet().at(i)->getRC().top) / 2);

		
		if (_stageFlag == 1)
			colorbullet = GetPixel(_scene1_1MG->getMemDC(), _bulletPool->getActiveBullet().at(i)->getRC().left + (_bulletPool->getActiveBullet().at(i)->getRC().right - _bulletPool->getActiveBullet().at(i)->getRC().left) / 2, _bulletPool->getActiveBullet().at(i)->getRC().top + (_bulletPool->getActiveBullet().at(i)->getRC().bottom - _bulletPool->getActiveBullet().at(i)->getRC().top) / 2);
		else if (_stageFlag == 2)
			colorbullet = GetPixel(_scene1_2MG->getMemDC(), _bulletPool->getActiveBullet().at(i)->getRC().left + (_bulletPool->getActiveBullet().at(i)->getRC().right - _bulletPool->getActiveBullet().at(i)->getRC().left) / 2, _bulletPool->getActiveBullet().at(i)->getRC().top + (_bulletPool->getActiveBullet().at(i)->getRC().bottom - _bulletPool->getActiveBullet().at(i)->getRC().top) / 2);
		else if (_stageFlag == 3)
			colorbullet = GetPixel(_scene1_3MG->getMemDC(), _bulletPool->getActiveBullet().at(i)->getRC().left + (_bulletPool->getActiveBullet().at(i)->getRC().right - _bulletPool->getActiveBullet().at(i)->getRC().left) / 2, _bulletPool->getActiveBullet().at(i)->getRC().top + (_bulletPool->getActiveBullet().at(i)->getRC().bottom - _bulletPool->getActiveBullet().at(i)->getRC().top) / 2);
		else if (_stageFlag == 4)
			colorbullet = GetPixel(_scene1_4MG->getMemDC(), _bulletPool->getActiveBullet().at(i)->getRC().left + (_bulletPool->getActiveBullet().at(i)->getRC().right - _bulletPool->getActiveBullet().at(i)->getRC().left) / 2, _bulletPool->getActiveBullet().at(i)->getRC().top + (_bulletPool->getActiveBullet().at(i)->getRC().bottom - _bulletPool->getActiveBullet().at(i)->getRC().top) / 2);
		return colorbullet;
	}

	

}

void player::collision()
{
	for (int i = 0; i < _bulletPool->getActiveBullet().size(); i++)
	{
		RECT temp;

		if (IntersectRect(&temp, &_bulletPool->getActiveBullet().at(i)->getRC(), &_bc->getRECT()))//getBossImage()->getBoundingBox()))
		{
			_bulletPool->getActiveBullet().at(i)->setActive(false);
			_bc->hitDamage(0.5);
			//_bc->setCurrentHP(_bc->getCurrentHP()-1);
			//_bc->setHitDamage(true);
		}
		//_bc->setHitDamge(false);
	}
}