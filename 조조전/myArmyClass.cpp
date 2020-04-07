#include "stdafx.h"
#include "myArmyClass.h"
#pragma warning(disable:4996)

myArmyClass::myArmyClass()
{
}

myArmyClass::~myArmyClass()
{
}

HRESULT myArmyClass::init()
{
	gameSystemMap = new gameSystem;
	gameSystemMap->init();

	tempFunction();
	load();

	IMAGEMANAGER->addImage("moveRange", "images/이동범위빗금48_3.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격타일", "images/공격타일.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격범위타일", "images/공격범위.bmp", 48, 48, true, RGB(255, 0, 255));

	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		_myArmyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
	}

	for (int j = 0; j < TILEX*TILEY; j++)
	{
		for (int i = 0; i < _myArmyVector.size(); i++)
		{
			RECT temp;
			if (IntersectRect(&temp, &gameSystemMap->getMap()[j].rc, &_myArmyVector[i].rc))
			{
				_myArmyVector[i].tile = j;
			}
		}
	}

	//aStar
	startTile = endTile = -1;
	isFind = false;
	noPath = false;
	startAstar = false;

	currentSelect = SELECT_NONE;

	_doneCount = 0;

	_battleOption = RectMake(0, 0, 0, 0);
	_battleOptionAttack = RectMake(0, 0, 0, 0);
	_battleOptionMagic = RectMake(0, 0, 0, 0);
	_battleOptionItem = RectMake(0, 0, 0, 0);
	_battleOptionDone = RectMake(0, 0, 0, 0);
	_battleOptionCancle = RectMake(0, 0, 0, 0);

	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		_hpBar = new  progressBar;
		_hpBar->init("images/마크/체력바.bmp", "images/마크/backgroundBar.bmp", 0, 0, 120, 10);
		_hpBar->setGauge(_myArmyVector[i].currentHp, _myArmyVector[i].maxHp);
		_hpBarMyVector.push_back(_hpBar);

		_mpBar = new  progressBar;
		_mpBar->init("images/마크/mp바.bmp", "images/마크/backgroundBar.bmp", 0, 0, 120, 10);
		_mpBar->setGauge(_myArmyVector[i].currentMp, _myArmyVector[i].maxMp);
		_mpBarMyVector.push_back(_mpBar);
	}

	return S_OK;
}

void myArmyClass::release()
{
	SAFE_DELETE(gameSystemMap);

	for (int i = 0; i < _hpBarMyVector.size(); i++)
	{
		SAFE_DELETE(_hpBar);
		SAFE_DELETE(_mpBar);
	}

	_mpBarMyVector.clear();
	_hpBarMyVector.clear();

}

void myArmyClass::update()
{
	_isShowState = false;
	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		if (PtInRect(&_myArmyVector[i].rc, m_ptMouse))
		{
			_isShowState = true;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int j = 0; j < _myArmyVector.size(); j++)
		{
			if (PtInRect(&_myArmyVector[j].rc, m_ptMouse) && currentSelect != SELECT_START && !_attackOptionMenu)
			{
				for (int i = 0; i < TILEX*TILEY; i++)
				{
					gameSystemMap->setAttackRange(false, i);
				}
				currentSelect = SELECT_START;
				_selectNum = j;
				_myArmyVector[_selectNum].isSelect = true;

			}

		}

		if (!PtInRect(&_myArmyVector[_selectNum].rc, m_ptMouse) && !_attackOptionMenu)
		{
			currentSelect = SELECT_END;
		}



		for (int i = 0; i < TILEX*TILEY; i++)
		{
			if (PtInRect(&gameSystemMap->getMap()[i].rc, m_ptMouse))
			{
				switch (currentSelect)
				{
				case SELECT_START:
					startTile = i;
					prevTile = startTile;
					prevDirection = _myArmyVector[_selectNum].direction;
					showRange = true;

					_attackOptionMenu = false;

					break;
				case SELECT_END:
					RECT temp;
					showRange = false;


					if (gameSystemMap->getMap()[i].floodFill&& gameSystemMap->getMap()[i].canMove && !_myArmyVector[_selectNum].isDone)
					{

						endTile = i;


					}
					if (startTile != -1 && endTile != -1)
					{
						startAstar = true;
						currentTile = startTile;
						//시작지점을 오픈리스트에 넣자
						openList.push_back(currentTile);
					}


					break;
				}
			}
		}
	}//end of VK_LBUTTON


	//나중에 AI 어택할때
	if (_myArmyVector[_beHitNum]._beHitMotion)
	{
		_attackCount++;
	}
	else if (!_myArmyVector[_beHitNum]._beHitMotion)
	{
		_attackCount = 0;
	}

	if (_myArmyVector[_beHitNum]._beHit)
	{
		_attackCount++;
		if (_attackCount <= 2)
		{
			_myArmyVector[_beHitNum].currentHp -= _myArmyVector[_beHitNum].currentDmg;
			_myArmyVector[_beHitNum]._beHit = false;
		}
	}



	if (startTile != -1 && currentSelect == SELECT_START)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_attackOptionMenu = true;
		}
	}

	for (int j = 0; j < TILEX*TILEY; j++)
	{
		//_tiles[j].attackRange = false;
		for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
		{

			RECT temp;
			if (IntersectRect(&temp, &_myArmyVector[_selectNum].rc, &gameSystemMap->getMap()[j].rc) && currentSelect != SELECT_NONE)
			{
				_myArmyVector[_selectNum].tile = j;
				if (_myArmyVector[_selectNum].attackArray[i] == 1)
				{
					if (j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) > 0 && j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) < 400)
						gameSystemMap->setAttackRange(true, j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)));
				}
			}
		}
	}

	while (!isFind && !noPath &&startAstar)
	{
		astar();
	}

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		RECT temp;
		for (int j = 0; j < _myArmyVector.size(); j++)
		{
			if (IntersectRect(&temp, &gameSystemMap->getMap()[i].rc, &_myArmyVector[j].rc))// && !IntersectRect(&temp,&_tiles[i].rc,&_myArmyVector[_selectNum].rc))
			{
				gameSystemMap->getMap()[i].canMove = false;

			}
			else
			{
				gameSystemMap->getMap()[i].canMove = true;
			}
		}
	}

	if (isFind && !moveStack.empty())// && _canMove)
	{


		moveSpeedIndex = _myArmyVector[_selectNum].move;
		if (moveSpeedIndex > 6)
		{
			moveSpeedIndex = 6;
		}

		if (_myArmyVector[_selectNum].rc.left > gameSystemMap->getMap()[moveStack.top()].rc.left)
		{
			_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_LEFT;
			_myArmyVector[_selectNum].rc.left -= moveSpeed[moveSpeedIndex];
			_myArmyVector[_selectNum].rc.right -= moveSpeed[moveSpeedIndex];
		}
		if (_myArmyVector[_selectNum].rc.left < gameSystemMap->getMap()[moveStack.top()].rc.left)
		{
			_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_RIGHT;
			_myArmyVector[_selectNum].rc.left += moveSpeed[moveSpeedIndex];
			_myArmyVector[_selectNum].rc.right += moveSpeed[moveSpeedIndex];
		}
		if (_myArmyVector[_selectNum].rc.top < gameSystemMap->getMap()[moveStack.top()].rc.top)
		{
			_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_BOTTOM;
			_myArmyVector[_selectNum].rc.top += moveSpeed[moveSpeedIndex];
			_myArmyVector[_selectNum].rc.bottom += moveSpeed[moveSpeedIndex];
		}
		if (_myArmyVector[_selectNum].rc.top > gameSystemMap->getMap()[moveStack.top()].rc.top)
		{
			_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_TOP;
			_myArmyVector[_selectNum].rc.top -= moveSpeed[moveSpeedIndex];
			_myArmyVector[_selectNum].rc.bottom -= moveSpeed[moveSpeedIndex];
		}
		if (_myArmyVector[_selectNum].rc.left == gameSystemMap->getMap()[moveStack.top()].rc.left &&
			_myArmyVector[_selectNum].rc.top == gameSystemMap->getMap()[moveStack.top()].rc.top)
		{
			moveStack.pop();
			for (int i = 0; i < TILEX*TILEY; i++)
			{
				gameSystemMap->setAttackRange(false, i);
			}
		}
	}




	if (startTile != -1)
	{
		//gameSystemMap->setFloodFill()
		floodFill(startTile, _myArmyVector[_selectNum].move);
		//floodFill(_myArmyVector[_selectNum].tile, _myArmyVector[_selectNum].move);
		if (_myArmyVector[_selectNum].isDone)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				startTile = -1;
				for (int i = 0; i < TILEX*TILEY; i++)
				{
					if (gameSystemMap->getMap()[i].floodFill)
						gameSystemMap->setFloodFill(false, i);
					//if (gameSystemMap->getMap()[i].attackRange)
					//	gameSystemMap->setAttackRange(false, i);
				}
			}
		}
	}
	if (endTile != -1)
	{
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			if (gameSystemMap->getMap()[i].floodFill)
				gameSystemMap->setFloodFill(false, i);
		}
	}


	if (isFind && moveStack.empty())
	{
		startAstar = false;
		openList.clear();
		closeList.clear();
		isFind = false;
		noPath = false;
		startTile = -1;
		endTile = -1;
		_canMove = false;
		//_moveComplete = false;
		_attackOptionMenu = true;

	}

	animation();


	if (_attackOptionMenu)
	{
		/*clickCount = 0;*/
		_battleOption.left = _myArmyVector[_selectNum].rc.left + TILESIZE + 20;
		_battleOption.top = _myArmyVector[_selectNum].rc.top - 45;
		_battleOption.right = _battleOption.left + 89;
		_battleOption.bottom = _battleOption.top + 122;

		_battleOptionAttack.left = _battleOption.left + 3;
		_battleOptionAttack.top = _battleOption.top + 3;
		_battleOptionAttack.right = _battleOptionAttack.left + 83;
		_battleOptionAttack.bottom = _battleOptionAttack.top + 21;

		_battleOptionMagic.left = _battleOption.left + 3;
		_battleOptionMagic.top = _battleOptionAttack.bottom + 3;
		_battleOptionMagic.right = _battleOptionMagic.left + 83;
		_battleOptionMagic.bottom = _battleOptionMagic.top + 21;


		_battleOptionItem.left = _battleOption.left + 3;
		_battleOptionItem.top = _battleOptionMagic.bottom + 3;
		_battleOptionItem.right = _battleOptionItem.left + 83;
		_battleOptionItem.bottom = _battleOptionItem.top + 21;

		_battleOptionDone.left = _battleOption.left + 3;
		_battleOptionDone.top = _battleOptionItem.bottom + 3;

		_battleOptionDone.right = _battleOptionDone.left + 83;
		_battleOptionDone.bottom = _battleOptionDone.top + 21;

		_battleOptionCancle.left = _battleOption.left + 3;
		_battleOptionCancle.top = _battleOptionDone.bottom + 3;
		_battleOptionCancle.right = _battleOptionCancle.left + 83;
		_battleOptionCancle.bottom = _battleOptionCancle.top + 21;

	}

	//for (int i = 0; i < TILEX*TILEY; i++)
	//{
	//	for (int j = 0; j < _enemyVector.size(); j++)
	//	{
	//		RECT temp;
	//		if (IntersectRect(&temp, &_tiles[i].rc, &_enemyVector[j].rc) && _tiles[i].attackRange)
	//		{
	//			_canAttack = true;
	//		}
	//	}
	//}

	if (currentSelect == SELECT_START)
	{
		if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
		{
			startTile = -1;
			endTile = -1;
			for (int i = 0; i < TILEX*TILEY; i++)
			{
				gameSystemMap->setFloodFill(false, i);
			}
		}
	}


	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && _attackOptionMenu)
	{
		if (PtInRect(&_battleOption, m_ptMouse) && !_myArmyVector[_selectNum].isDone)
		{
			if (PtInRect(&_battleOptionAttack, m_ptMouse) && _canAttack)
			{
				_myArmyVector[_selectNum].isAttack = true;
			}
			if (PtInRect(&_battleOptionMagic, m_ptMouse))
			{
				_myArmyVector[_selectNum].isMagic = true;
			}
			if (PtInRect(&_battleOptionItem, m_ptMouse))
			{
				_myArmyVector[_selectNum].isItem = true;
			}
			if (PtInRect(&_battleOptionDone, m_ptMouse))
			{
				_myArmyVector[_selectNum].isDone = true;
				_doneCount++;
			}
			if (PtInRect(&_battleOptionCancle, m_ptMouse))
			{
				_myArmyVector[_selectNum].rc.left = gameSystemMap->getMap()[prevTile].rc.left;
				_myArmyVector[_selectNum].rc.top = gameSystemMap->getMap()[prevTile].rc.top;
				_myArmyVector[_selectNum].rc.right = gameSystemMap->getMap()[prevTile].rc.right;
				_myArmyVector[_selectNum].rc.bottom = gameSystemMap->getMap()[prevTile].rc.bottom;
				_myArmyVector[_selectNum].direction = prevDirection;

			}
			_attackOptionMenu = false;

		}
	}
	if (_attackOptionMenu)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_myArmyVector[_selectNum].rc.left = gameSystemMap->getMap()[prevTile].rc.left;
			_myArmyVector[_selectNum].rc.top = gameSystemMap->getMap()[prevTile].rc.top;
			_myArmyVector[_selectNum].rc.right = gameSystemMap->getMap()[prevTile].rc.right;
			_myArmyVector[_selectNum].rc.bottom = gameSystemMap->getMap()[prevTile].rc.bottom;
			_myArmyVector[_selectNum].direction = prevDirection;
			_attackOptionMenu = false;
		}
	}
	if (!_attackOptionMenu)
	{
		_canAttack = false;
	}

	if (_myArmyVector[_selectNum].isAttack)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_myArmyVector[_selectNum].isAttack = false;
			_attackOptionMenu = true;
		}

	}

	for (int i = 0; i < _hpBarMyVector.size(); i++)
	{
		_hpBarMyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 55);
		_hpBarMyVector[i]->setY(405);
		_hpBarMyVector[i]->setGauge(_myArmyVector[i].currentHp, _myArmyVector[i].maxHp);
		_hpBarMyVector[i]->update();
		_mpBarMyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 55);
		_mpBarMyVector[i]->setY(435);
		_mpBarMyVector[i]->setGauge(_myArmyVector[i].currentMp, _myArmyVector[i].maxMp);
		_mpBarMyVector[i]->update();
	}

}

void myArmyClass::render()
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (gameSystemMap->getMap()[i].floodFill)
		{
			IMAGEMANAGER->render("moveRange", getMemDC(), i% TILEX*TILESIZE, i / TILEX * TILESIZE);

		}
		if (gameSystemMap->getMap()[i].attackRange&&showRange)// && _myArmyVector[_selectNum].isAttack)
			IMAGEMANAGER->render("공격타일", getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE);
		else if (gameSystemMap->getMap()[i].attackRange && _myArmyVector[_selectNum].isAttack)
			IMAGEMANAGER->render("공격범위타일", getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE);
	}


	for (int i = 0; i < _myArmyVector.size(); i++)
	{

		if (_myArmyVector[i].isDone)
		{
			_myArmyVector[i].characterMoveImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].currentFrameX, _myArmyVector[i].currentFrameY);
			_myArmyVector[i].characterDoneImage->alphaFrameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].doneFrameX, _myArmyVector[i].doneFrameY, 100);
		}
		else if (!_myArmyVector[i].isDone && !_myArmyVector[i].isAttackMotion && !_myArmyVector[i]._beHitMotion)
			_myArmyVector[i].characterMoveImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].currentFrameX, _myArmyVector[i].currentFrameY);

		if (_myArmyVector[i].isAttackMotion)
		{
			_myArmyVector[i].characterAttackImage->frameRender(getMemDC(), _myArmyVector[i].rc.left - 8, _myArmyVector[i].rc.top - 8, _myArmyVector[i].attackFrameX, _myArmyVector[i].attackFrameY);
		}

		if (!_myArmyVector[i]._beHitMotion && !_myArmyVector[i].isAttackMotion)
			_myArmyVector[i].characterMoveImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].currentFrameX, _myArmyVector[i].currentFrameY);
		else if (_myArmyVector[i]._beHitMotion)
			_myArmyVector[i].characterDefImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, 0, 4);
		if (_isShowState)
		{
			if (PtInRect(&_myArmyVector[i].rc, m_ptMouse))
			{
				char levelStr[128];

				char nameStr[128];
				char hpStr[128];
				char mpStr[128];

				char strStr[128];
				char dexStr[128];
				char intelligenceStr[128];
				char luckStr[128];
				char cmdStr[128];
				char atkStr[128];
				char mAtkStr[128];
				char defStr[128];
				char spdStr[128];
				char moveStr[128];
				_isShowState = true;
				//_myArmyVector[i].characterFaceImage->render(getMemDC(), 973, 350);
				_myArmyVector[i].characterFaceImage->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 9, 309);
				//wsprintf(str2, "%s", _myArmyVector[i].name);
				//TextOut(getMemDC(), 1043, 350, str2, strlen(str2));

				wsprintf(levelStr, "Lv %d", _myArmyVector[i].level);
				wsprintf(nameStr, "%s", _myArmyVector[i].name);

				_hpBarMyVector[i]->render();
				_mpBarMyVector[i]->render();

				wsprintf(hpStr, "%d / %d", _myArmyVector[i].currentHp, _myArmyVector[i].maxHp);
				wsprintf(mpStr, "%d / %d", _myArmyVector[i].currentMp, _myArmyVector[i].maxMp);
				wsprintf(strStr, "무력 : %d", _myArmyVector[i].str);
				wsprintf(dexStr, "민첩 : %d", _myArmyVector[i].dex);
				wsprintf(intelligenceStr, "지력 : %d", _myArmyVector[i].intelligence);
				wsprintf(luckStr, "운 : %d", _myArmyVector[i].luck);
				wsprintf(cmdStr, "통솔 : %d", _myArmyVector[i].cmd);
				wsprintf(atkStr, "공격력 : %d", _myArmyVector[i].atk);
				wsprintf(mAtkStr, "정신력 : %d", _myArmyVector[i].mAtk);
				wsprintf(defStr, "방어력 : %d", _myArmyVector[i].def);
				wsprintf(spdStr, "순발력 : %d", _myArmyVector[i].spd);
				wsprintf(moveStr, "이동력 : %d", _myArmyVector[i].move);
				//wsprintf(expStr, "%d", _enemyVector[i].exp);
				HFONT myFont = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "궁서");
				HFONT oldFont = (HFONT)SelectObject(getMemDC(), myFont);
				SetTextColor(getMemDC(), RGB(255, 80, 60));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 309, nameStr, strlen(nameStr));
				SelectObject(getMemDC(), oldFont);
				DeleteObject(myFont);

				HFONT myFont1 = CreateFont(15, 0, 0, 0, 600, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "궁서");
				HFONT oldFont1 = (HFONT)SelectObject(getMemDC(), myFont1);
				SetTextColor(getMemDC(), RGB(255, 255, 255));

				TextOut(getMemDC(), WINSIZEX - 60, 309, levelStr, strlen(levelStr));


				SelectObject(getMemDC(), oldFont1);
				DeleteObject(myFont1);

				HFONT myFont2 = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "궁서");
				HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), myFont2);
				SetTextColor(getMemDC(), RGB(190, 170, 200));

				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 90, 403, hpStr, strlen(hpStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 90, 433, mpStr, strlen(mpStr));

				SelectObject(getMemDC(), oldFont2);
				DeleteObject(myFont2);

				HFONT myFont3 = CreateFont(10, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "궁서");
				HFONT oldFont3 = (HFONT)SelectObject(getMemDC(), myFont3);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 330, strStr, strlen(strStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 345, dexStr, strlen(dexStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 360, intelligenceStr, strlen(intelligenceStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 375, luckStr, strlen(luckStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 390, cmdStr, strlen(cmdStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 125, 330, atkStr, strlen(atkStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 125, 345, mAtkStr, strlen(mAtkStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 125, 360, defStr, strlen(defStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 125, 375, spdStr, strlen(spdStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 125, 390, moveStr, strlen(moveStr));
				SelectObject(getMemDC(), oldFont3);
				DeleteObject(myFont3);

			}
		}
	}




	if (_attackOptionMenu)
	{
		IMAGEMANAGER->render("공격옵션", getMemDC(), _battleOption.left, _battleOption.top);
		if (!_canAttack)
			IMAGEMANAGER->render("공격메뉴_공격_비활성화", getMemDC(), _battleOptionAttack.left, _battleOptionAttack.top);
		else if (_canAttack)
			IMAGEMANAGER->render("공격메뉴_공격_활성화", getMemDC(), _battleOptionAttack.left, _battleOptionAttack.top);
		IMAGEMANAGER->render("공격메뉴_책략_비활성화", getMemDC(), _battleOptionMagic.left, _battleOptionMagic.top);
		IMAGEMANAGER->render("공격메뉴_도구_비활성화", getMemDC(), _battleOptionItem.left, _battleOptionItem.top);
		IMAGEMANAGER->render("공격메뉴_대기", getMemDC(), _battleOptionDone.left, _battleOptionDone.top);
		IMAGEMANAGER->render("공격메뉴_취소", getMemDC(), _battleOptionCancle.left, _battleOptionCancle.top);
	}


}



void myArmyClass::astar()
{

	//int currentTile = startTile;
	int endX = endTile % TILEX;
	int endY = endTile / TILEX;


	int currentX = currentTile % TILEX;
	int currentY = currentTile / TILEX;
	// left, right, up, down, leftup, rightdown, leftdown, rightup
	int dx[] = { -1, 1, 0, 0 };// , -1, 1, -1, 1 };
	int dy[] = { 0, 0, -1, 1 };// , -1, 1, 1, -1 };
	bool tempBlock[4];

	// 방향 찾는 반복문
	for (int i = 0; i < 4; i++)
	{
		int x = currentX + dx[i];
		int y = currentY + dy[i];
		tempBlock[i] = false;

		// 해당 방향으로 움직인 타일이 유효한 타일인지 확인
		if (0 <= x && x < TILEX && 0 <= y && y < TILEY)
		{
			bool isOpen;
			// 대각선 타일의 이동 문제로 (주변에 블락있으면 못감) 임시로 블락 상태 저장
			if (gameSystemMap->getMap()[y * TILEX + x].block) tempBlock[i] = true;
			else {
				// check closeList z
				bool isClose = false;
				for (int j = 0; j < closeList.size(); j++)
				{
					if (closeList[j] == y * TILEX + x)
					{
						isClose = true;
						break;
					}
				}
				if (isClose) continue;

				if (i < 4)
				{
					gameSystemMap->setG(10, y * TILEX + x);
				}
				else
				{
					// leftup인 경우 left나 up에 블락있으면 안됨
					if (i == DIRECTION_LEFTUP &&
						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_UP]) continue;
					// rightdown인 경우 right나 down에 블락있으면 안됨
					if (i == DIRECTION_RIGHTDOWN &&
						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_DOWN]) continue;
					// rightup인 경우 right나 up에 블락있으면 안됨
					if (i == DIRECTION_RIGHTUP &&
						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_UP]) continue;
					// leftdown인 경우 left나 down에 블락있으면 안됨
					if (i == DIRECTION_LEFTDOWN &&
						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_DOWN]) continue;
					gameSystemMap->setG(14, y * TILEX + x);

				}
				//abs절대값
				gameSystemMap->setH((abs(endX - x) + abs(endY - y)) * 10, y * TILEX + x);
				gameSystemMap->setF(gameSystemMap->getMap()[y * TILEX + x].g + gameSystemMap->getMap()[y * TILEX + x].h, y * TILEX + x);

				// 오픈리스트에 있으면 g 비용 비교 후 처리
				isOpen = false;
				for (int i = 0; i < openList.size(); i++)
				{
					if (openList[i] == y * TILEX + x)
					{
						isOpen = true;
						if (gameSystemMap->getMap()[openList[i]].g > gameSystemMap->getMap()[y * TILEX + x].g)
						{
							gameSystemMap->getMap()[openList[i]].h = gameSystemMap->getMap()[y * TILEX + x].h;
							gameSystemMap->getMap()[openList[i]].g = gameSystemMap->getMap()[y * TILEX + x].g;
							gameSystemMap->getMap()[openList[i]].f = gameSystemMap->getMap()[y * TILEX + x].f;
							gameSystemMap->setNode(currentTile, openList[i]);
						}
					}
				}
				// 없으면 그냥 넣고 부모 설정
				if (!isOpen)
				{
					openList.push_back(y * TILEX + x);
					gameSystemMap->setNode(currentTile, y * TILEX + x);
				}

				// find
				if (y * TILEX + x == endTile)
					isFind = true;

			}
		}
	}

	// 선택 지점 열린목록에서 빼기
	for (iter = openList.begin(); iter != openList.end(); ++iter)
	{
		if ((*iter) == currentTile)
		{
			iter = openList.erase(iter);
			break;
		}
	}

	// not Find
	if (openList.size() == 0)
	{

		noPath = true;

	}

	// 현재 타일 클로즈리스트에 넣기
	closeList.push_back(currentTile);

	if (openList.size() != 0)
	{
		// find minimum f cost in openList
		int min = gameSystemMap->getMap()[*openList.begin()].h;
		currentTile = *openList.begin();
		for (iter = openList.begin(); iter != openList.end(); ++iter)
		{
			if (min > gameSystemMap->getMap()[(*iter)].h)
			{
				min = gameSystemMap->getMap()[(*iter)].h;
				currentTile = *iter;
			}
		}
	}
	//}

	// 타일 렌더를 위해 상태 저장
	for (int i = 0; i < openList.size(); i++)
	{
		gameSystemMap->setShowState(STATE_OPEN, openList[i]);
	}
	for (int i = 0; i < closeList.size(); i++)
	{
		gameSystemMap->setShowState(STATE_CLOSE, closeList[i]);
	}
	// 길 찾기 성공시 각 타일에 길찾기 상태 저장
	int tempTile = endTile;
	//if(_turnFlag == 0)
	moveStack.push(endTile);
	while (gameSystemMap->getMap()[tempTile].node != startTile
		&& isFind)
	{
		tempTile = gameSystemMap->getMap()[tempTile].node;
		moveStack.push(tempTile);
		gameSystemMap->setShowState(STATE_PATH, tempTile);
		//_tiles[tempTile].showState = STATE_PATH;
	}

}

void myArmyClass::floodFill(int tile, int moveCount)
{
	int count;

	if (tile >= 0 && tile <= 400)
	{
		if (gameSystemMap->getMap()[tile].terrain == TR_CASTLELAND)
		{
			count = moveCount - 2;
		}
		else
		{
			count = moveCount - 1;
		}
		if (count >= 0 && !gameSystemMap->getMap()[tile].block)
		{

			floodFill(tile - 20, count);
			floodFill(tile + 20, count);
			if (tile % TILEX > 0 && tile % TILEX < 19)
			{

				floodFill(tile - 1, count);
				floodFill(tile + 1, count);
			}
			else if (startTile%TILEX == 19)
			{
				floodFill(tile - 1, count);
			}
			else if (startTile%TILEX == 0)
			{
				floodFill(tile + 1, count);
			}
			gameSystemMap->setFloodFill(true, tile);
		}
	}

}

void myArmyClass::animation()
{
	if (!_attackOptionMenu)
	{
		if (!_myArmyVector[_selectNum].isAttackMotion)// || !_myArmyVector[_selectNum].isDone)
		{
			for (int i = 0; i < _myArmyVector.size(); i++)
			{
				//if (!moveStack.empty())
				//{
				//if (!_attackOptionMenu)
				//{
				if (!_myArmyVector[i].isDone)
				{
					switch (_myArmyVector[i].direction)
					{
					case CHARACTER_DIRECTION_LEFT:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 4 || _myArmyVector[i].currentFrameY > 5)
							_myArmyVector[i].currentFrameY = 4;
						//_myArmyVector[i].characterMoveImage->setFrameY(4);
						//if (_myArmyVector[i].count % (25%moveSpeedIndex) == 0)
						if (_myArmyVector[i].count % 25 == 0)
							//if (_myArmyVector[i].count % moveSpeedIndex == 0)
						{
							//_myArmyVector[i].currentFrameY = _myArmyVector[i].characterMoveImage->getFrameY();;
							_myArmyVector[i].currentFrameY++;
							//_myArmyVector[i].characterMoveImage->setFrameY(4);
							if (_myArmyVector[i].currentFrameY > 5)
								_myArmyVector[i].currentFrameY = 4;
							_myArmyVector[i].count = 0;
						}
						break;
					case CHARACTER_DIRECTION_RIGHT:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 6 || _myArmyVector[i].currentFrameY > 7)
							_myArmyVector[i].currentFrameY = 6;
						//_myArmyVector[i].characterMoveImage->setFrameY(4);
						//if (_myArmyVector[i].count % (25 % moveSpeedIndex) == 0)
						if (_myArmyVector[i].count % 25 == 0)
							//if (_myArmyVector[i].count  % moveSpeedIndex == 0)
						{
							//_myArmyVector[i].currentFrameY = _myArmyVector[i].characterMoveImage->getFrameY();;
							_myArmyVector[i].currentFrameY++;
							//_myArmyVector[i].characterMoveImage->setFrameY(4);
							if (_myArmyVector[i].currentFrameY > 7)
								_myArmyVector[i].currentFrameY = 6;
							_myArmyVector[i].count = 0;
						}
						break;
					case CHARACTER_DIRECTION_TOP:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 2 || _myArmyVector[i].currentFrameY > 3)
							_myArmyVector[i].currentFrameY = 2;
						//_myArmyVector[i].characterMoveImage->setFrameY(4);
						//if (_myArmyVector[i].count % (25 % moveSpeedIndex) == 0)
						if (_myArmyVector[i].count % 25 == 0)
							//if (_myArmyVector[i].count  % moveSpeedIndex == 0)
						{
							//_myArmyVector[i].currentFrameY = _myArmyVector[i].characterMoveImage->getFrameY();;
							_myArmyVector[i].currentFrameY++;
							//_myArmyVector[i].characterMoveImage->setFrameY(4);
							if (_myArmyVector[i].currentFrameY > 3)
								_myArmyVector[i].currentFrameY = 2;
							_myArmyVector[i].count = 0;
						}
						break;
					case CHARACTER_DIRECTION_BOTTOM:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 0 || _myArmyVector[i].currentFrameY > 1)
							_myArmyVector[i].currentFrameY = 0;
						//_myArmyVector[i].characterMoveImage->setFrameY(4);
						//if (_myArmyVector[i].count % (25 % moveSpeedIndex) == 0)
						if (_myArmyVector[i].count % 25 == 0)
							//if (_myArmyVector[i].count % moveSpeedIndex == 0)
						{
							//_myArmyVector[i].currentFrameY = _myArmyVector[i].characterMoveImage->getFrameY();;
							_myArmyVector[i].currentFrameY++;
							//_myArmyVector[i].characterMoveImage->setFrameY(4);
							if (_myArmyVector[i].currentFrameY > 1)
								_myArmyVector[i].currentFrameY = 0;
							_myArmyVector[i].count = 0;
						}
						break;
					}
				}

				//}

				//}

			}
		}//end of !isAttackMotion
	}

	if (_myArmyVector[_selectNum].isAttack)
	{
		switch (_myArmyVector[_selectNum].direction)
		{
		case CHARACTER_DIRECTION_LEFT:
			_myArmyVector[_selectNum].currentFrameY = 10;
			break;
		case CHARACTER_DIRECTION_RIGHT:
			_myArmyVector[_selectNum].currentFrameY = 11;
			break;
		case CHARACTER_DIRECTION_TOP:
			_myArmyVector[_selectNum].currentFrameY = 9;
			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_myArmyVector[_selectNum].currentFrameY = 8;
			break;
		}
	}
	if (_myArmyVector[_selectNum].isDone)
	{
		switch (_myArmyVector[_selectNum].direction)
		{
		case CHARACTER_DIRECTION_LEFT:
			_myArmyVector[_selectNum].doneFrameY = 2;
			_myArmyVector[_selectNum].currentFrameY = 10;
			break;
		case CHARACTER_DIRECTION_RIGHT:
			_myArmyVector[_selectNum].doneFrameY = 3;
			_myArmyVector[_selectNum].currentFrameY = 11;
			break;
		case CHARACTER_DIRECTION_TOP:
			_myArmyVector[_selectNum].doneFrameY = 1;
			_myArmyVector[_selectNum].currentFrameY = 9;
			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_myArmyVector[_selectNum].doneFrameY = 0;
			_myArmyVector[_selectNum].currentFrameY = 8;
			break;
		}
	}
	else if (_myArmyVector[_selectNum].isAttackMotion)
	{
		switch (_myArmyVector[_selectNum].direction)
		{
		case CHARACTER_DIRECTION_LEFT:

			_myArmyVector[_selectNum].attackCount++;
			if (_myArmyVector[_selectNum].currentFrameY < 0 || _myArmyVector[_selectNum].currentFrameY > 3)
				_myArmyVector[_selectNum].currentFrameY = 0;
			_myArmyVector[_selectNum].characterMoveImage->setFrameY(4);
			if (_myArmyVector[_selectNum].count % (25 % moveSpeedIndex) == 0)

				if (!strcmp(_myArmyVector[_selectNum].classType, "궁병") || !strcmp(_myArmyVector[_selectNum].classType, "궁기병"))
				{
					if (_myArmyVector[_selectNum].attackCount <= 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 8;
					}
					if (_myArmyVector[_selectNum].attackCount <= 60 && _myArmyVector[_selectNum].attackCount > 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 9;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 60)
					{
						_myArmyVector[_selectNum].attackFrameY = 10;
						attackStart = true;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
					{
						_myArmyVector[_selectNum].attackFrameY = 11;

					}
					if (_myArmyVector[_selectNum].attackCount > 100)
					{
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;
						//attackFinish = true;
						//_enemyVector[_hitNum]._beHitMotion = false;
						_doneCount++;
					}
				}
				else
				{
					if (_myArmyVector[_selectNum].attackCount <= 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 8;
					}
					if (_myArmyVector[_selectNum].attackCount <= 48 && _myArmyVector[_selectNum].attackCount > 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 9;
					}
					if (_myArmyVector[_selectNum].attackCount <= 51 && _myArmyVector[_selectNum].attackCount > 48)
					{
						_myArmyVector[_selectNum].attackFrameY = 10;
						attackStart = true;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 51)
					{
						_myArmyVector[_selectNum].attackFrameY = 11;

					}
					if (_myArmyVector[_selectNum].attackCount > 83)
					{
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;
						//attackFinish = true;
						//_enemyVector[_hitNum]._beHitMotion = false;
						_doneCount++;
					}
				}


			break;
		case CHARACTER_DIRECTION_RIGHT:
			_myArmyVector[_selectNum].attackCount++;
			if (_myArmyVector[_selectNum].currentFrameY < 0 || _myArmyVector[_selectNum].currentFrameY > 3)
				_myArmyVector[_selectNum].currentFrameY = 0;
			_myArmyVector[_selectNum].characterMoveImage->setFrameY(4);
			if (_myArmyVector[_selectNum].count % (25 % moveSpeedIndex) == 0)
				if (!strcmp(_myArmyVector[_selectNum].classType, "궁병") || !strcmp(_myArmyVector[_selectNum].classType, "궁기병"))
				{
					if (_myArmyVector[_selectNum].attackCount <= 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 12;
					}
					if (_myArmyVector[_selectNum].attackCount <= 60 && _myArmyVector[_selectNum].attackCount > 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 13;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 60)
					{
						_myArmyVector[_selectNum].attackFrameY = 14;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
						attackStart = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
					{
						_myArmyVector[_selectNum].attackFrameY = 15;

					}
					if (_myArmyVector[_selectNum].attackCount > 100)
					{
						//attackFinish = true;
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;
						//_enemyVector[_hitNum]._beHitMotion = false;

						_doneCount++;
					}
				}
				else
				{
					if (_myArmyVector[_selectNum].attackCount <= 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 12;
					}
					if (_myArmyVector[_selectNum].attackCount <= 48 && _myArmyVector[_selectNum].attackCount > 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 13;
					}
					if (_myArmyVector[_selectNum].attackCount <= 51 && _myArmyVector[_selectNum].attackCount > 48)
					{
						_myArmyVector[_selectNum].attackFrameY = 14;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
						attackStart = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 51)
					{
						_myArmyVector[_selectNum].attackFrameY = 15;

					}
					if (_myArmyVector[_selectNum].attackCount > 83)
					{
						//attackFinish = true;
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;
						//_enemyVector[_hitNum]._beHitMotion = false;

						_doneCount++;
					}
				}

			break;
		case CHARACTER_DIRECTION_TOP:
			_myArmyVector[_selectNum].attackCount++;
			if (_myArmyVector[_selectNum].currentFrameY < 0 || _myArmyVector[_selectNum].currentFrameY > 3)
				_myArmyVector[_selectNum].currentFrameY = 0;
			_myArmyVector[_selectNum].characterMoveImage->setFrameY(4);
			if (_myArmyVector[_selectNum].count % (25 % moveSpeedIndex) == 0)
				if (!strcmp(_myArmyVector[_selectNum].classType, "궁병") || !strcmp(_myArmyVector[_selectNum].classType, "궁기병"))
				{
					if (_myArmyVector[_selectNum].attackCount <= 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 4;
					}
					if (_myArmyVector[_selectNum].attackCount <= 60 && _myArmyVector[_selectNum].attackCount > 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 5;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 60)
					{
						_myArmyVector[_selectNum].attackFrameY = 6;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
						attackStart = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
					{
						_myArmyVector[_selectNum].attackFrameY = 7;

					}
					if (_myArmyVector[_selectNum].attackCount > 100)
					{
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;

						//_enemyVector[_hitNum]._beHitMotion = false;
						//attackFinish = true;
						_doneCount++;
					}
				}
				else
				{
					if (_myArmyVector[_selectNum].attackCount <= 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 4;
					}
					if (_myArmyVector[_selectNum].attackCount <= 48 && _myArmyVector[_selectNum].attackCount > 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 5;
					}
					if (_myArmyVector[_selectNum].attackCount <= 51 && _myArmyVector[_selectNum].attackCount > 48)
					{
						_myArmyVector[_selectNum].attackFrameY = 6;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
						attackStart = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 51)
					{
						_myArmyVector[_selectNum].attackFrameY = 7;

					}
					if (_myArmyVector[_selectNum].attackCount > 83)
					{
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;

						//_enemyVector[_hitNum]._beHitMotion = false;
						//attackFinish = true;
						_doneCount++;
					}
				}

			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_myArmyVector[_selectNum].attackCount++;
			if (_myArmyVector[_selectNum].currentFrameY < 0 || _myArmyVector[_selectNum].currentFrameY > 3)
				_myArmyVector[_selectNum].currentFrameY = 0;
			_myArmyVector[_selectNum].characterMoveImage->setFrameY(4);
			if (_myArmyVector[_selectNum].count % (25 % moveSpeedIndex) == 0)

				if (!strcmp(_myArmyVector[_selectNum].classType, "궁병") || !strcmp(_myArmyVector[_selectNum].classType, "궁기병"))
				{
					if (_myArmyVector[_selectNum].attackCount <= 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 0;
					}
					if (_myArmyVector[_selectNum].attackCount <= 60 && _myArmyVector[_selectNum].attackCount > 30)
					{
						_myArmyVector[_selectNum].attackFrameY = 1;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 60)
					{
						_myArmyVector[_selectNum].attackFrameY = 2;
						attackStart = true;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
					{
						_myArmyVector[_selectNum].attackFrameY = 3;
					}
					if (_myArmyVector[_selectNum].attackCount > 100)
					{
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;
						//attackFinish = true;
						//_enemyVector[_hitNum]._beHitMotion = false;
						_doneCount++;
					}
				}
				else
				{
					if (_myArmyVector[_selectNum].attackCount <= 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 0;
					}
					if (_myArmyVector[_selectNum].attackCount <= 48 && _myArmyVector[_selectNum].attackCount > 45)
					{
						_myArmyVector[_selectNum].attackFrameY = 1;
					}
					if (_myArmyVector[_selectNum].attackCount <= 51 && _myArmyVector[_selectNum].attackCount > 48)
					{
						_myArmyVector[_selectNum].attackFrameY = 2;
						attackStart = true;
						//_enemyVector[_hitNum]._beHitMotion = true;
						//_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount > 51)
					{
						_myArmyVector[_selectNum].attackFrameY = 3;
					}
					if (_myArmyVector[_selectNum].attackCount > 83)
					{
						_myArmyVector[_selectNum].isAttackMotion = false;
						_myArmyVector[_selectNum].isDone = true;
						//attackFinish = true;
						//_enemyVector[_hitNum]._beHitMotion = false;
						_doneCount++;
					}
				}

			break;
		default:
			break;
		}
	}

	if (!_myArmyVector[_selectNum].isAttackMotion)
	{
		_myArmyVector[_selectNum].attackCount = 0;
		//_myArmyVector[_selectNum].isDone = true;
	}
}

void myArmyClass::equipItem(tagItem nextEquipItem, int num)
{

	_myArmyVector[num].characterItemVector.push_back(nextEquipItem);

	if (nextEquipItem.itemType == ITEM_SWORD ||
		nextEquipItem.itemType == ITEM_BOW ||
		nextEquipItem.itemType == ITEM_FAN ||
		nextEquipItem.itemType == ITEM_SPEAR)
	{
		_myArmyVector[num].atk += nextEquipItem.stat;
	}
	else if (nextEquipItem.itemType == ITEM_ARMOR ||
		nextEquipItem.itemType == ITEM_CLOTH)
	{
		_myArmyVector[num].def += nextEquipItem.stat;
	}
}

void myArmyClass::minusStat(tagItem beforeItem, int num)
{
	if (beforeItem.itemType == ITEM_SWORD ||
		beforeItem.itemType == ITEM_BOW ||
		beforeItem.itemType == ITEM_FAN ||
		beforeItem.itemType == ITEM_SPEAR)
	{
		_myArmyVector[num].atk -= beforeItem.stat;
	}
	else if (beforeItem.itemType == ITEM_ARMOR ||
		beforeItem.itemType == ITEM_CLOTH)
	{
		_myArmyVector[num].def -= beforeItem.stat;
	}
}

tagItem myArmyClass::unEquipItem(int num, int vectorNum)
{
	tagItem unEquip;
	unEquip = _myArmyVector[vectorNum].characterItemVector[num];
	if (unEquip.itemType == ITEM_SWORD ||
		unEquip.itemType == ITEM_BOW ||
		unEquip.itemType == ITEM_FAN ||
		unEquip.itemType == ITEM_SPEAR)
	{
		_myArmyVector[num].atk -= unEquip.stat;
	}
	else if (unEquip.itemType == ITEM_ARMOR ||
		unEquip.itemType == ITEM_CLOTH)
	{
		_myArmyVector[num].def -= unEquip.stat;
	}
	_myArmyVector[vectorNum].characterItemVector.erase(_myArmyVector[vectorNum].characterItemVector.begin() + num);



	return unEquip;

}


void myArmyClass::load()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (gameSystemMap->getMap()[i].dis == DISTIN_NONE)continue;
		char fileName[128];
		strcpy(fileName, gameSystemMap->getMap()[i].tileCharacter.name);
		strcat(fileName, ".dat");
		file = CreateFile
		(fileName,				//생성할 파일또는 열 장치나 파일이름
			GENERIC_READ,			//파일이나 장치를 만들거나 열때 사용할 권한
			0,						//파일 공유 모드입력
			NULL,					//파일또는 장치를 열때 보안 및 특성
			OPEN_EXISTING,			//파일이나 장치를 열때 취할 행동
			FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
			NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
		ReadFile(file, &_character, sizeof(tagCharacter), &read, NULL);
		_character.characterFaceImage = _faceSelectVector[_character.faceImageNum];
		_character.characterMoveImage = _characterSelectVector[_character.moveImageNum];
		_character.characterAttackImage = _characterAttackVector[_character.moveImageNum];
		_character.characterDefImage = _characterDefVector[_character.moveImageNum];
		_character.characterDoneImage = _characterDoneVector[_character.moveImageNum];
		_character.rc.left = gameSystemMap->getMap()[i].rc.left;
		_character.rc.top = gameSystemMap->getMap()[i].rc.top;
		_character.rc.right = gameSystemMap->getMap()[i].rc.right;
		_character.rc.bottom = gameSystemMap->getMap()[i].rc.bottom;
		_character.maxHp = _character.currentHp = _character.hp;
		_character.maxMp = _character.currentMp = _character.mp;

		//_maxHP = _currentHP = _character.hp;
		if (gameSystemMap->getMap()[i].dis == DISTIN_MINE)
			_myArmyVector.push_back(_character);
		CloseHandle(file);

	}
}

void myArmyClass::tempFunction()
{

	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face0", "images/캐릭터 얼굴/0.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face1", "images/캐릭터 얼굴/1.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face2", "images/캐릭터 얼굴/2.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face3", "images/캐릭터 얼굴/3.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face4", "images/캐릭터 얼굴/4.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face5", "images/캐릭터 얼굴/5.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face6", "images/캐릭터 얼굴/6.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face7", "images/캐릭터 얼굴/7.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face8", "images/캐릭터 얼굴/8.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face9", "images/캐릭터 얼굴/9.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face10", "images/캐릭터 얼굴/10.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face11", "images/캐릭터 얼굴/11.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face12", "images/캐릭터 얼굴/12.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face13", "images/캐릭터 얼굴/13.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face14", "images/캐릭터 얼굴/14.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face15", "images/캐릭터 얼굴/15.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face16", "images/캐릭터 얼굴/16.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face17", "images/캐릭터 얼굴/17.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face18", "images/캐릭터 얼굴/18.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face19", "images/캐릭터 얼굴/19.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face20", "images/캐릭터 얼굴/20.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face21", "images/캐릭터 얼굴/21.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face22", "images/캐릭터 얼굴/22.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face23", "images/캐릭터 얼굴/23.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face24", "images/캐릭터 얼굴/24.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face25", "images/캐릭터 얼굴/25.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face26", "images/캐릭터 얼굴/26.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face27", "images/캐릭터 얼굴/27.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face28", "images/캐릭터 얼굴/28.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face29", "images/캐릭터 얼굴/29.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face30", "images/캐릭터 얼굴/30.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face31", "images/캐릭터 얼굴/31.bmp", 64, 80, true, RGB(255, 0, 255)));

	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit0", "images/유닛/0.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit1", "images/유닛/1.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit2", "images/유닛/2.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit3", "images/유닛/3.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit4", "images/유닛/4.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit5", "images/유닛/5.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit6", "images/유닛/6.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit7", "images/유닛/7.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit8", "images/유닛/8.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit9", "images/유닛/9.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit10", "images/유닛/10.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit11", "images/유닛/11.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit12", "images/유닛/12.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit13", "images/유닛/13.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit14", "images/유닛/14.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit15", "images/유닛/15.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit16", "images/유닛/16.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit17", "images/유닛/17.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit18", "images/유닛/18.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit19", "images/유닛/19.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit20", "images/유닛/20.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit21", "images/유닛/21.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit22", "images/유닛/22.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit23", "images/유닛/23.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit24", "images/유닛/24.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit25", "images/유닛/25.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit26", "images/유닛/26.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit27", "images/유닛/27.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));

	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack0", "images/유닛/공격모션/0.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack1", "images/유닛/공격모션/1.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack2", "images/유닛/공격모션/2.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack3", "images/유닛/공격모션/3.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack4", "images/유닛/공격모션/4.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack5", "images/유닛/공격모션/5.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack6", "images/유닛/공격모션/6.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack7", "images/유닛/공격모션/7.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack8", "images/유닛/공격모션/8.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack9", "images/유닛/공격모션/9.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack10", "images/유닛/공격모션/10.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack11", "images/유닛/공격모션/11.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack12", "images/유닛/공격모션/12.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack13", "images/유닛/공격모션/13.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack14", "images/유닛/공격모션/14.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack15", "images/유닛/공격모션/15.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack16", "images/유닛/공격모션/16.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack17", "images/유닛/공격모션/17.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack18", "images/유닛/공격모션/18.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack19", "images/유닛/공격모션/19.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack20", "images/유닛/공격모션/20.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack21", "images/유닛/공격모션/21.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack22", "images/유닛/공격모션/22.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack23", "images/유닛/공격모션/23.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack24", "images/유닛/공격모션/24.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack25", "images/유닛/공격모션/25.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack26", "images/유닛/공격모션/26.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack27", "images/유닛/공격모션/27.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));

	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def0", "images/유닛/막기모션/0.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def1", "images/유닛/막기모션/1.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def2", "images/유닛/막기모션/2.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def3", "images/유닛/막기모션/3.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def4", "images/유닛/막기모션/4.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def5", "images/유닛/막기모션/5.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def6", "images/유닛/막기모션/6.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def7", "images/유닛/막기모션/7.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def8", "images/유닛/막기모션/8.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def9", "images/유닛/막기모션/9.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def10", "images/유닛/막기모션/10.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def11", "images/유닛/막기모션/11.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def12", "images/유닛/막기모션/12.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def13", "images/유닛/막기모션/13.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def14", "images/유닛/막기모션/14.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def15", "images/유닛/막기모션/15.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def16", "images/유닛/막기모션/16.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def17", "images/유닛/막기모션/17.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def18", "images/유닛/막기모션/18.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def19", "images/유닛/막기모션/19.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def20", "images/유닛/막기모션/20.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def21", "images/유닛/막기모션/21.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def22", "images/유닛/막기모션/22.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def23", "images/유닛/막기모션/23.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def24", "images/유닛/막기모션/24.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def25", "images/유닛/막기모션/25.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def26", "images/유닛/막기모션/26.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def27", "images/유닛/막기모션/27.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));

	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done0", "images/유닛/대기상태/0.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done1", "images/유닛/대기상태/1.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done2", "images/유닛/대기상태/2.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done3", "images/유닛/대기상태/3.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done4", "images/유닛/대기상태/4.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done5", "images/유닛/대기상태/5.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done6", "images/유닛/대기상태/6.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done7", "images/유닛/대기상태/7.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done8", "images/유닛/대기상태/8.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done9", "images/유닛/대기상태/9.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done10", "images/유닛/대기상태/10.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done11", "images/유닛/대기상태/11.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done12", "images/유닛/대기상태/12.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done13", "images/유닛/대기상태/13.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done14", "images/유닛/대기상태/14.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done15", "images/유닛/대기상태/15.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done16", "images/유닛/대기상태/16.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done17", "images/유닛/대기상태/17.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done18", "images/유닛/대기상태/18.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done19", "images/유닛/대기상태/19.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done20", "images/유닛/대기상태/20.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done21", "images/유닛/대기상태/21.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done22", "images/유닛/대기상태/22.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done23", "images/유닛/대기상태/23.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done24", "images/유닛/대기상태/24.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done25", "images/유닛/대기상태/25.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done26", "images/유닛/대기상태/26.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done27", "images/유닛/대기상태/27.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));

}