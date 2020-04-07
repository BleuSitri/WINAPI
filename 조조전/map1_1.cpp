#include "stdafx.h"
#include "map1_1.h"
#pragma warning(disable:4996)

map1_1::map1_1()
{
}

map1_1::~map1_1()
{
}

HRESULT map1_1::init()
{
	fontSize = 15;
	tempFunction();
	load();
	IMAGEMANAGER->addImage("mouseSelect", "images/전투_마우스타일.bmp", 48, 48, true, RGB(247, 0, 255)); 


	IMAGEMANAGER->addFrameImage("mapTiles", "images/TileMap4.bmp", 144, 528, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));

	//맵타일
	//IMAGEMANAGER->addFrameImage("mapTiles", "images/TileMap.bmp", 0, 0, 144, 480, 3, 10, true, RGB(255, 0, 255));

	//배틀맵1_1
	IMAGEMANAGER->addImage("m023", "images/m023_2.bmp", 960, 960, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("m023", "images/m023.bmp", 960, 960, true, RGB(255, 0, 255));
	 
	IMAGEMANAGER->addImage("battleSideScene", "images/battleSideScene_3.bmp", 216, 960, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("battleSideScene", "images/battleSideScene.bmp", 144, 960, true, RGB(255, 0, 255));

	//IMAGEMANAGER->addImage("moveRange", "images/이동범위빗금48_2.bmp", 48, 48, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("moveRange", "images/이동범위빗금48_3.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("enemyMoveRange", "images/이동범위빗금_적.bmp", 48, 48, true, RGB(247, 0, 255));


	IMAGEMANAGER->addImage("맵_지형", "images/지형/맵_지형.bmp", 144, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("다리", "images/지형/다리.bmp", 28, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("도랑", "images/지형/도랑.bmp", 29, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("병영", "images/지형/병영.bmp", 28, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("성내", "images/지형/성내.bmp", 29, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("성벽", "images/지형/성벽.bmp", 28, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("숲", "images/지형/숲.bmp", 13, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("가옥", "images/지형/가옥.bmp", 29, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("보물고", "images/지형/보물고.bmp", 45, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("울타리", "images/지형/울타리.bmp", 44, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("설원", "images/지형/설원.bmp", 28, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("설원", "images/지형/설원.bmp", 28, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("요새", "images/지형/요새.bmp", 29, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("성", "images/지형/성.bmp", 12, 13, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("이동불가지형", "images/지형/이동불가지형.bmp", 69, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("회복있음", "images/지형/회복있음.bmp", 61, 13, true, RGB(255, 0, 255));




	//IMAGEMANAGER->addImage("미니맵", "images/미니맵.bmp", 120, 120, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("미니맵", "images/미니맵.bmp", 144, 144, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("미니맵", "images/미니맵_2.bmp", 144, 144, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격타일", "images/공격타일.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격범위타일", "images/공격범위.bmp", 48, 48, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("공격옵션", "images/공격메뉴_2.bmp", 89, 122, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_공격_비활성화", "images/공격메뉴_공격_비활성화.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_공격_활성화", "images/공격메뉴_공격_활성화.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_도구_비활성화", "images/공격메뉴_도구_비활성화.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_도구_활성화", "images/공격메뉴_도구_활성화.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_책략_비활성화", "images/공격메뉴_책략_비활성화.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_책략_활성화", "images/공격메뉴_책략_활성화.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_대기", "images/공격메뉴_대기.bmp", 83, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("공격메뉴_취소", "images/공격메뉴_취소.bmp", 83, 21, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("날씨_맑음", "images/날씨_맑음.bmp", 216, 200, 1,4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("날씨_흐림", "images/날씨_흐림.bmp", 216, 200, 1,4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("날씨_비", "images/날씨_비.bmp", 216, 200, 1,4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("날씨_폭우", "images/날씨_폭우.bmp", 216, 200, 1,4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("날씨_눈", "images/날씨_눈.bmp", 216, 200, 1,4, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("물마법불가", "images/물마법불가.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("바람마법불가", "images/바람마법불가.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("땅마법불가", "images/땅마법불가.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("불마법불가", "images/불마법불가.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("물마법가능", "images/물마법가능.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("바람마법가능", "images/바람마법가능.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("땅마법가능", "images/땅마법가능.bmp", 16, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("불마법가능", "images/불마법가능.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("유닛정보창", "images/유닛정보창_2.bmp", 192, 262, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("유닛정보창", "images/유닛정보창.bmp", 192, 171, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("유닛정보창_내용", "images/유닛정보창_내용.bmp", 188, 167, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("유닛정보창_내용", "images/유닛정보창_내용_2.bmp", 188, 258, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("체력아이콘", "images/마크/체력아이콘.bmp", 24, 24, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("mp아이콘", "images/마크/mp아이콘.bmp", 24, 24, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("경험치아이콘", "images/마크/경험치아이콘.bmp", 24, 24, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("손해", "images/마크/손해.bmp", 29, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("명중", "images/마크/명중.bmp", 29, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("무기경험치아이콘", "images/마크/무기경험치아이콘.bmp", 16, 16, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("방어구경험치아이콘", "images/마크/방어구경험치아이콘.bmp", 16, 16, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("슬롯", "images/슬롯2.bmp", 34, 34, true, RGB(247, 0, 255));

	IMAGEMANAGER->addImage("backgroundBar", "images/마크/backgroundBar.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("체력바", "images/마크/체력바.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mp바", "images/마크/mp바.bmp", 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("경험치바", "images/마크/경험치바.bmp", 8, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("아군턴", "images/아군턴.bmp", 960, 960, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("적군턴", "images/적군턴.bmp", 960, 960, true, RGB(247, 0, 255));

	IMAGEMANAGER->addImage("가죽갑옷", "images/아이템/가죽갑옷.bmp", 32, 32, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("의천검", "images/아이템/의천검.bmp", 32, 32, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("반궁", "images/아이템/반궁.bmp", 32, 32, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("죽선", "images/아이템/죽선.bmp", 32, 32, true, RGB(247, 0, 255));
	IMAGEMANAGER->addImage("무명옷", "images/아이템/무명옷.bmp", 32, 32, true, RGB(247, 0, 255));
	
	IMAGEMANAGER->addImage("순욱_스킬", "images/스킬/순욱_스킬.bmp", 203, 158, true, RGB(247, 0, 255));

	pheonixSkillImage = IMAGEMANAGER->addFrameImage("주작", "images/스킬/주작.bmp", 300, 9000, 1, 30, true, RGB(247, 0, 255));
	pheonixSkillImage->setX(330);
	pheonixSkillImage->setY(330);
	IMAGEMANAGER->addFrameImage("불스킬이펙트", "images/스킬/불스킬이펙트.bmp", 75, 1045, 1, 11, true, RGB(247, 0, 255));


	SCENEMANAGER->addScene("defeatScene", new defeatScene);
	SCENEMANAGER->addScene("victoryScene", new victoryScene);

	_battleOption = RectMake(0,0,0,0);
	_battleOptionAttack = RectMake(0, 0, 0, 0);
	_battleOptionMagic = RectMake(0, 0, 0, 0);
	_battleOptionItem = RectMake(0, 0, 0, 0);
	_battleOptionDone = RectMake(0, 0, 0, 0);
	_battleOptionCancle = RectMake(0, 0, 0, 0);


	startTile = endTile = -1;

	currentSelect = SELECT_NONE;
	//currentSelect = SELECT_START;

	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		_myArmyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
	}
	for (int i = 0; i < _enemyVector.size(); i++)
	{
		_enemyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
	}

	isFind = false;
	noPath = false;
	startAstar = false;

	for (int i = 0; i < _enemyVector.size(); i++)
	{
		_hpBar = new  progressBar;
		_hpBar->init("images/마크/체력바.bmp", "images/마크/backgroundBar.bmp", 0, 0, 120, 10);
		_hpBar->setGauge(_enemyVector[i].currentHp, _enemyVector[i].maxHp);
		_hpBarEnemyVector.push_back(_hpBar);

		_mpBar = new  progressBar;
		_mpBar->init("images/마크/mp바.bmp", "images/마크/backgroundBar.bmp", 0, 0, 120, 10);
		_mpBar->setGauge(_enemyVector[i].currentMp, _enemyVector[i].maxMp);
		_mpBarEnemyVector.push_back(_mpBar);
	}

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

		_expBar = new  progressBar;
		_expBar->init("images/마크/경험치바.bmp", "images/마크/backgroundBar.bmp", 0, 0, 120, 10);
		_expBar->setGauge(_myArmyVector[i].currentExp, _myArmyVector[i].maxExp);
		_expBarMyVector.push_back(_expBar);

	}


	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tiles[i].floodFill = false;
	}

	_turnFlag = 0;
	_doneCount = 0;
	ggCount = 0;
	minTileF = 100000;
	mostDmg = 0;
	clickCount = 0;
	myArmyDeadCount = 0;
	enemyDeadCount = 0;
	isVictory = false;
	isDefeat = false;
	turnCount = 1;
	attackArrayCount = 0;


	return S_OK;
}

void map1_1::release()
{
	for (int i = 0; i < _hpBarEnemyVector.size(); i++)
	{
		SAFE_DELETE(_hpBar);
		SAFE_DELETE(_mpBar);
		SAFE_DELETE(_expBar);
	}
	for (int i = 0; i < _hpBarMyVector.size(); i++)
	{
		SAFE_DELETE(_hpBar);
		SAFE_DELETE(_mpBar);
	}

	_mpBarEnemyVector.clear();
	_hpBarEnemyVector.clear();
	_mpBarMyVector.clear();
	_hpBarMyVector.clear();
	_expBarMyVector.clear();
	//SAFE_DELETE(_hpBar);
}

void map1_1::update()
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		for (int j = 0; j < _myArmyVector.size(); j++)
		{
			if (_myArmyVector[j].currentHp <= 0)
			{
				_tiles[i].block = false;
			}
		}
		for (int j = 0; j < _enemyVector.size(); j++)
		{
			if (_enemyVector[j].currentHp <= 0)
			{
				_tiles[i].block = false;
			}
		}
	}
	if (enemyDeadCount == _enemyVector.size() - 1)
	{
		isVictory = true;
	}
	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		if (strcmp(_myArmyVector[i].name, "조조") == 0)
		{
			if (_myArmyVector[i].currentHp <= 0)
			{
				isDefeat = true;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		isVictory = true;
	}
	else if (KEYMANAGER->isOnceKeyDown('9'))
	{
		isDefeat = true;
	}
	//씬전환
	if (isVictory)
	{
		turnCount = 1;
		_doneCount = 0;
		myArmyDeadCount = 0;
		enemyDeadCount = 0;
		SCENEMANAGER->changeScene("victoryScene");
	}
	else if (isDefeat)
	{
		turnCount = 1;
		_doneCount = 0;
		myArmyDeadCount = 0;
		enemyDeadCount = 0;
		SCENEMANAGER->changeScene("defeatScene");
	}

	if (_turnFlag == 0)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{   
			for (int j = 0; j < _myArmyVector.size(); j++)
			{
				if (PtInRect(&_myArmyVector[j].rc, m_ptMouse) && _myArmyVector[j].currentHp>0/* && currentSelect != SELECT_END*/ && currentSelect != SELECT_START&& !_attackOptionMenu)// &&clickCount<2)
					// && clickCount <1)/*&&!_myArmyVector[_selectNum].isSelect*///)// && !_attackOptionMenu)
				{
					for (int i = 0; i < TILEX*TILEY; i++)
					{
						_tiles[i].attackRange = false;
					}
					currentSelect = SELECT_START;
					_selectNum = j;
					_myArmyVector[_selectNum].isSelect = true;
				}

			}

			if (!PtInRect(&_myArmyVector[_selectNum].rc, m_ptMouse))
			{
				currentSelect = SELECT_END;
			}


			for (int i = 0; i < TILEX*TILEY; i++)
			{
				if (PtInRect(&_tiles[i].rc, m_ptMouse))// &&!_attackOptionMenu)
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
						_attackRangeTilesRectVector.clear();
						showRange = false;


						if (_tiles[i].floodFill&& _tiles[i].canMove && !_myArmyVector[_selectNum].isDone)
						{

							endTile = i;

							_attackRangeTilesVector.clear();
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
				if (IntersectRect(&temp, &_myArmyVector[_selectNum].rc, &_tiles[j].rc) && currentSelect != SELECT_NONE)
				{
					_myArmyVector[_selectNum].tile = j;
					if (_myArmyVector[_selectNum].attackArray[i] == 1)
					{
						if (j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) > 0 && j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) < 400)
							_tiles[j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX))].attackRange = true;
					}
				}
			}

		}





		//tileCheck();
		while (!isFind && !noPath &&startAstar)
		{
			Astar();
		}

		for (int i = 0; i < TILEX*TILEY; i++)
		{
			RECT temp;
			for (int j = 0; j < _enemyVector.size(); j++)
			{
				if (IntersectRect(&temp, &_tiles[i].rc, &_enemyVector[j].rc) &&_enemyVector[j].currentHp>0)
				{
					_tiles[i].block = true;
					_enemyVector[j].tile = i;
				}
				else
					_tiles[i].block == false;

			}
			for (int j = 0; j < _myArmyVector.size(); j++)
			{
				if (IntersectRect(&temp, &_tiles[i].rc, &_myArmyVector[j].rc))// && !IntersectRect(&temp,&_tiles[i].rc,&_myArmyVector[_selectNum].rc))
				{
					_tiles[i].canMove = false;

				}
				else
				{
					_tiles[i].canMove = true;
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

			if (_myArmyVector[_selectNum].rc.left > _tiles[moveStack.top()].rc.left)
			{
				_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_LEFT;
				_myArmyVector[_selectNum].rc.left -= moveSpeed[moveSpeedIndex];
				_myArmyVector[_selectNum].rc.right -= moveSpeed[moveSpeedIndex];
			}
			if (_myArmyVector[_selectNum].rc.left < _tiles[moveStack.top()].rc.left)
			{
				_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_RIGHT;
				_myArmyVector[_selectNum].rc.left += moveSpeed[moveSpeedIndex];
				_myArmyVector[_selectNum].rc.right += moveSpeed[moveSpeedIndex];
			}
			if (_myArmyVector[_selectNum].rc.top < _tiles[moveStack.top()].rc.top)
			{
				_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_BOTTOM;
				_myArmyVector[_selectNum].rc.top += moveSpeed[moveSpeedIndex];
				_myArmyVector[_selectNum].rc.bottom += moveSpeed[moveSpeedIndex];
			}
			if (_myArmyVector[_selectNum].rc.top > _tiles[moveStack.top()].rc.top)
			{
				_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_TOP;
				_myArmyVector[_selectNum].rc.top -= moveSpeed[moveSpeedIndex];
				_myArmyVector[_selectNum].rc.bottom -= moveSpeed[moveSpeedIndex];
			}
			if (_myArmyVector[_selectNum].rc.left == _tiles[moveStack.top()].rc.left &&
				_myArmyVector[_selectNum].rc.top == _tiles[moveStack.top()].rc.top)
			{
				_moveComplete = true;
				moveStack.pop();
				for (int i = 0; i < TILEX*TILEY; i++)
				{
					_tiles[i].attackRange = false;
				}
			}
		}




		if (startTile != -1)
		{
			if(!_myArmyVector[_selectNum].isDone)
 				floodFill(startTile, _myArmyVector[_selectNum].move);
		}
		if (endTile != -1)
		{
			for (int i = 0; i < TILEX*TILEY; i++)
			{
				if (_tiles[i].floodFill)
					_tiles[i].floodFill = false;
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
			_attackOptionMenu = true;

		}
	}

	animation();



	_weatherCount++;
	if (_weatherCount % 25 == 0)
	{
		_weatherCount = 0;
		_weatherFrameY++;
		if (_weatherFrameY > 3)
			_weatherFrameY = 0;
	}


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
		_battleOptionMagic.right = _battleOptionMagic.left+83;
		_battleOptionMagic.bottom = _battleOptionMagic.top+21;


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


	//렉트를 안만드는것
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		for (int j = 0; j < _enemyVector.size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_tiles[i].rc, &_enemyVector[j].rc) && _tiles[i].attackRange &&_enemyVector[j].currentHp>0)
			{
				_canAttack = true;
			}
		}
	}


	if (currentSelect == SELECT_START)
	{

		//floodFill(_myArmyVector[_selectNum].tile, _myArmyVector[_selectNum].move);
		if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
		{
			startTile = -1;
			endTile = -1;
			for (int i = 0; i < TILEX*TILEY; i++)
			{
				_tiles[i].floodFill = false;
				//_tiles[i].attackRange = false;
			}
		}
	}
	_canMagic = false;
	if (!strcmp(_myArmyVector[_selectNum].name, "순욱"))
	{
		_canMagic = true;
	}
	else
		_canMagic = false;


	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && _attackOptionMenu)
	{
		if (PtInRect(&_battleOption,m_ptMouse) && !_myArmyVector[_selectNum].isDone)
		{
			if (PtInRect(&_battleOptionAttack, m_ptMouse) && _canAttack)
			{
				_myArmyVector[_selectNum].isAttack = true;
			}
			if (PtInRect(&_battleOptionMagic, m_ptMouse) && _canMagic)
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
				_myArmyVector[_selectNum].rc.left = _tiles[prevTile].rc.left;
				_myArmyVector[_selectNum].rc.top = _tiles[prevTile].rc.top;
				_myArmyVector[_selectNum].rc.right = _tiles[prevTile].rc.right;
				_myArmyVector[_selectNum].rc.bottom = _tiles[prevTile].rc.bottom;
				_myArmyVector[_selectNum].direction = prevDirection;

			}
			//_canAttack = false;
			_attackOptionMenu = false;

		}
	}

	if (_myArmyVector[_selectNum].isMagic)
	{
		skillRect = RectMake(_battleOption.left+8, _battleOption.top+41, 188, 16);
		skillCancleRect = RectMake(_battleOption.left + 123, _battleOption.top + 132, 75, 21);
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&skillRect, m_ptMouse))
			{
				isMagicRangeOn = true;
				_myArmyVector[_selectNum].isMagic = false;
			}
			else if (PtInRect(&skillCancleRect, m_ptMouse))
			{
				_myArmyVector[_selectNum].isMagic = false;
				_attackOptionMenu = true;
			}
		}
	}

	if (isMagicRangeOn)
	{
		for (int j = 0; j < TILEX*TILEY; j++)
		{
			for (int i = 0; i < PHEONIXTILEX*PHEONIXTILEY; i++)
			{
				if (_myArmyVector[_selectNum].rc.left == _tiles[j].rc.left
					&& _myArmyVector[_selectNum].rc.top == _tiles[j].rc.top)
				{
					_myArmyVector[_selectNum].tile = j;
					if (pheonixSkillArray[i] == 1)
					{
						if (j + (i - 24) + ((i / PHEONIXTILEX - 3)*(TILEX - PHEONIXTILEX)) > 0 && j + (i - 24) + ((i / PHEONIXTILEX - 3)*(TILEX - PHEONIXTILEX)) < 400)
							_tiles[j + (i - 24) + ((i / PHEONIXTILEX - 3)*(TILEX - PHEONIXTILEX))].magicRange = true;
					}
				}
			}
		}
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				if (_tiles[i].magicRange)
				{
					for (int j = 0; j < _enemyVector.size(); j++)
					{
						if (PtInRect(&_enemyVector[j].rc, m_ptMouse) && _tiles[i].canFireMagic&& _myArmyVector[_selectNum].currentMp>=6)
						{
							_myArmyVector[_selectNum].isMagicMotion = true;
							skillHitNum = j;
							isPheonixSkill = true;
							isMagicRangeOn = false;
						}
					}
				}
			}
		}
	}
	else if (!isMagicRangeOn)
	{
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			_tiles[i].magicRange = false;
		}
	}
	if (isPheonixSkill)
	{
		pheonixSkill();
	}
	if (fireEffectOn)
	{
		fireEffect();
	}

	if (_attackOptionMenu)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_myArmyVector[_selectNum].rc.left = _tiles[prevTile].rc.left;
			_myArmyVector[_selectNum].rc.top = _tiles[prevTile].rc.top;
			_myArmyVector[_selectNum].rc.right = _tiles[prevTile].rc.right;
			_myArmyVector[_selectNum].rc.bottom = _tiles[prevTile].rc.bottom;
			_myArmyVector[_selectNum].direction = prevDirection;
			_attackOptionMenu = false;
		}
	}
	if (!_attackOptionMenu)
	{
		_canAttack = false;
		//_attackRangeTilesVector.clear();
	}
	if (_myArmyVector[_selectNum].isAttack)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_myArmyVector[_selectNum].isAttack = false;
			_attackOptionMenu = true;
		}

	}

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_myArmyVector[_selectNum].isAttack)
		{
			if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
			{
				if (_tiles[i].attackRange)
				{
					for (int j = 0; j < _enemyVector.size(); j++)
					{
						if (PtInRect(&_tiles[i].rc, m_ptMouse) && PtInRect(&_enemyVector[j].rc, m_ptMouse) &&_enemyVector[j].currentHp>0)
						{
							_myArmyVector[_selectNum].isAttack = false;
							_myArmyVector[_selectNum].isAttackMotion = true;							

							if ((_myArmyVector[_selectNum].tile%TILEX) - ( i%TILEX) < 0)
								_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_RIGHT;
							else if ((_myArmyVector[_selectNum].tile%TILEX) - (i%TILEX) > 0)
								_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_LEFT;
							else if (_myArmyVector[_selectNum].tile - i < 0 && (_myArmyVector[_selectNum].tile%TILEX) - (i%TILEX) == 0)
								//if ((i % (TILEX+1)) - (_myArmyVector[_selectNum].tile % (TILEX +1)) == 0 && ((i/TILEX)- (_myArmyVector[_selectNum].tile / TILEX)) <0)
								_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_BOTTOM;
							else if (_myArmyVector[_selectNum].tile - i > 0 && (_myArmyVector[_selectNum].tile%TILEX) - (i%TILEX) == 0)
								//if ((i % (TILEX + 1)) - (_myArmyVector[_selectNum].tile % (TILEX + 1)) == 0 && ((i / TILEX) - (_myArmyVector[_selectNum].tile / TILEX)) > 0)
								_myArmyVector[_selectNum].direction = CHARACTER_DIRECTION_TOP;

							_hitNum = j;
						}
					}

				}
			}
		}
	}

	if (_enemyVector[_hitNum]._beHit)
	{
		_enemyVector[_hitNum].currentDmg = _myArmyVector[_selectNum].atk - _enemyVector[_hitNum].def / 2;// +_myArmyVector[_selectNum].level + 25;
		_attackCount++;
		if (_attackCount < 2)
		{
			/*_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;*/
			_enemyVector[_hitNum]._beHit = false;
			if (_enemyVector[_hitNum].currentHp <= 0)
			{
				enemyDeadCount += 1;
			}
		}

	}
	if (!_enemyVector[_hitNum]._beHitMotion)
	{
		_attackCount = 0;
		_enemyVector[_hitNum].currentDmg = 0;
	}

	for (int i = 0; i < _hpBarEnemyVector.size(); i++)
	{
		_hpBarEnemyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 55);
		_hpBarEnemyVector[i]->setY(405);
		_hpBarEnemyVector[i]->setGauge(_enemyVector[i].currentHp, _enemyVector[i].maxHp);
		_hpBarEnemyVector[i]->update();
		_mpBarEnemyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 55);
		_mpBarEnemyVector[i]->setY(435);
		_mpBarEnemyVector[i]->setGauge(_enemyVector[i].currentMp, _enemyVector[i].maxMp);
		_mpBarEnemyVector[i]->update();
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

		_expBarMyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 55);
		_expBarMyVector[i]->setY(465);
		_expBarMyVector[i]->setGauge(_myArmyVector[i].currentExp, _myArmyVector[i].maxExp);
		_expBarMyVector[i]->update();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}

	//아군턴
	if (_turnFlag == 0)
	{
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			RECT temp;
			for (int j = 0; j < _myArmyVector.size(); j++)
			{
				if (IntersectRect(&temp, &_tiles[i].rc, &_myArmyVector[j].rc))
				{
					_tiles[i].block = false;
				}
			}
			for (int j = 0; j < _enemyVector.size(); j++)
			{
				_enemyVector[j].isDone = false;
				if (IntersectRect(&temp, &_tiles[i].rc, &_enemyVector[j].rc) && _enemyVector[j].currentHp>0)
				{
					_enemyVector[j].tile = i;
					_tiles[i].block = true;
					_tiles[i].teamBlock = false;
				}
			}

		}

		_myTurnImage = true;

		if ((_turnImageTime += TIMEMANAGER->getElapsedTime()) > 2)
		{
			_myTurnImage = false;
		}
		if (_doneCount+myArmyDeadCount == _myArmyVector.size())
		{
			startTile = -1;
			endTile = -1;
			_selectNum = 0;
			_turnFlag++;
			_doneCount = 0;
			_turnImageTime = 0;
			for (int i = 0; i < TILEX*TILEY; i++)
			{
				_tiles[i].attackRange = false;
			}
			for (int i = 0; i < _enemyVector.size(); i++)
			{
				_enemyVector[i].isSelect = false;
			}
		}
	}
	//적군턴
	else if (_turnFlag == 1)
	{
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			RECT temp;
			for (int j = 0; j < _enemyVector.size(); j++)
			{
				if (IntersectRect(&temp, &_tiles[i].rc, &_enemyVector[j].rc) && _enemyVector[j].currentHp>0)
				{
					_tiles[i].block = false;
					_enemyVector[j].tile = i;
					_tiles[i].teamBlock = true;
				}
			}
			for (int j = 0; j < _myArmyVector.size(); j++)
			{
				_myArmyVector[j].isDone = false;
				if (IntersectRect(&temp, &_tiles[i].rc, &_myArmyVector[j].rc) && _myArmyVector[j].currentHp >= 0)
				{
					_myArmyVector[j].tile = i;
					_tiles[i].block = true;
				}
			}

		}




		_enemyTurnImage = true;
		if ((_turnImageTime += TIMEMANAGER->getElapsedTime()) > 2)
		{
			_enemyTurnImage = false;
		}

		if (!_enemyTurnImage)
		{
			//floodFill(_enemyVector[0].tile, 5/*_enemyVector[0].move*/);
			AI();


		}
		if (_doneCount + enemyDeadCount == _enemyVector.size())
		{
			turnCount++;
			AICount = 0;
			startTile = -1;
			endTile = -1;
			_turnFlag = 0;
			_doneCount = 0;
			_turnImageTime = 0;
			currentSelect = SELECT_NONE;
			for (int i = 0; i < TILEX*TILEY; i++)
			{
				_tiles[i].attackRange = false;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_turnFlag = 1;
	}

	//if (KEYMANAGER->isOnceKeyDown('3')&&currentSelect == SELECT_START && _myArmyVector[_selectNum].isDone)
	//{
	//	for (int i = 0; i < TILEX*TILEY; i++)
	//	{
	//		_tiles[i].floodFill = false;
	//		_tiles[i].attackRange = false;
	//	}
	//}

}

void map1_1::render()
{

	//맵 렌더
	IMAGEMANAGER->render("m023", getMemDC());
	IMAGEMANAGER->render("battleSideScene", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("battleSideScene")->getWidth(), 0);

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_isDebug)
		{
			IMAGEMANAGER->frameRender("mapTiles", getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}
		if (PtInRect(&_tiles[i].rc, m_ptMouse))
		{
			IMAGEMANAGER->render("mouseSelect", getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top);
		}

	}


	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_tiles[i].floodFill)
		{
			if (_turnFlag == 0)
				IMAGEMANAGER->render("moveRange", getMemDC(), i% TILEX*TILESIZE, i / TILEX * TILESIZE);
			else if (_turnFlag == 1)
				IMAGEMANAGER->render("enemyMoveRange", getMemDC(), i% TILEX*TILESIZE, i / TILEX * TILESIZE);
		}
		if (_turnFlag == 0)
		{
			if (_tiles[i].attackRange&&showRange && !_myArmyVector[_selectNum].isAttack)
				IMAGEMANAGER->render("공격타일", getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE);
			else if (_tiles[i].attackRange && _myArmyVector[_selectNum].isAttack)
				IMAGEMANAGER->render("공격범위타일", getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE);
		}

		else if (_turnFlag == 1)
		{
			//적군턴 테스트
			if (_tiles[i].attackRange && _turnFlag == 1 && showRange)
				IMAGEMANAGER->render("공격타일", getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE);
		}


		
		//IMAGEMANAGER->render("공격범위타일", getMemDC(), i% TILEX*TILESIZE, i / TILEX * TILESIZE);
	}
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_tiles[i].magicRange)
		{
			if (_tiles[i].magicRange && isMagicRangeOn)
				IMAGEMANAGER->render("공격범위타일", getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE);
		}
	}

	for (int i = 0; i < _enemyVector.size(); i++)
	{
		if (_enemyVector[i].currentHp > 0)
		{
			if (_enemyVector[i].isDone)
			{
				_enemyVector[i].characterMoveImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].currentFrameX, _enemyVector[i].currentFrameY);
				//_enemyVector[i].characterDoneImage->alphaFrameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].doneFrameX, _enemyVector[i].doneFrameY, 100);
			}
			//else if (!_enemyVector[i].isDone && !_enemyVector[i].isAttackMotion && !_enemyVector[i]._beHitMotion)
				//_enemyVector[i].characterMoveImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].currentFrameX, _enemyVector[i].currentFrameY);

			if (_enemyVector[AICount].isAttackMotion)
			{
				_enemyVector[AICount].characterAttackImage->frameRender(getMemDC(), _enemyVector[AICount].rc.left - 8, _enemyVector[AICount].rc.top - 8, _enemyVector[AICount].attackFrameX, _enemyVector[AICount].attackFrameY);
			}

			//if (!_enemyVector[i]._beHitMotion && !_enemyVector[i].isAttackMotion)
			if (!_enemyVector[i]._beHitMotion && !_enemyVector[i].isAttackMotion && !_enemyVector[i].isDone && !_enemyVector[i].isAttackMotion && !_enemyVector[i]._beHitMotion)
				_enemyVector[i].characterMoveImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].currentFrameX, _enemyVector[i].currentFrameY);
			else if (_enemyVector[i]._beHitMotion)
			{
				_enemyVector[i].characterDefImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, 0, 4);

				HFONT myFont5 = CreateFont(15, 0, 0, 0, 1000, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "나눔고딕");
				HFONT oldFont5 = (HFONT)SelectObject(getMemDC(), myFont5);
				SetTextColor(getMemDC(), RGB(255, 0, 0));
				if (showSkillDmg)
				{
					char skillDmgStr[128];
					//wsprintf(dmgStr, "%d",100);
					wsprintf(skillDmgStr, "100");
					TextOut(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, skillDmgStr, strlen(skillDmgStr));
					//skillHitNum = -1;
				}
				else if (!showSkillDmg)
				{
					char dmgStr[128];
					wsprintf(dmgStr, "%d", _enemyVector[_hitNum].currentDmg);
					TextOut(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, dmgStr, strlen(dmgStr));
				}

				





				SelectObject(getMemDC(), oldFont5);
				DeleteObject(myFont5);
			}

		}

	}
	for (int i = 0; i < _myArmyVector.size(); i++)
	{
	
		if (_myArmyVector[i].currentHp > 0)
		{
			if (_myArmyVector[i].isDone)
			{
				_myArmyVector[i].characterMoveImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].currentFrameX, _myArmyVector[i].currentFrameY);
				_myArmyVector[i].characterDoneImage->alphaFrameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].doneFrameX, _myArmyVector[i].doneFrameY, 130);
			}
			//else if (!_myArmyVector[i].isDone && !_myArmyVector[i].isAttackMotion && !_myArmyVector[i]._beHitMotion && !_myArmyVector[i].isMagicMotion)//&&!isPheonixSkill&&!fireEffectOn)
			//{
			//	_myArmyVector[i].characterMoveImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].currentFrameX, _myArmyVector[i].currentFrameY);
			//}


			if (_myArmyVector[_selectNum].isAttackMotion)
			{
				_myArmyVector[_selectNum].characterAttackImage->frameRender(getMemDC(), _myArmyVector[_selectNum].rc.left - 8, _myArmyVector[_selectNum].rc.top - 8, _myArmyVector[_selectNum].attackFrameX, _myArmyVector[_selectNum].attackFrameY);
			}

			//if (!_myArmyVector[i]._beHitMotion && !_myArmyVector[i].isAttackMotion && !_myArmyVector[i].isMagicMotion)
			if (!_myArmyVector[i]._beHitMotion && !_myArmyVector[i].isAttackMotion && !_myArmyVector[i].isMagicMotion&& !_myArmyVector[i].isDone && !_myArmyVector[i].isAttackMotion && !_myArmyVector[i]._beHitMotion)
				_myArmyVector[i].characterMoveImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, _myArmyVector[i].currentFrameX, _myArmyVector[i].currentFrameY);
			else if (_myArmyVector[i]._beHitMotion)
			{
				HFONT myFont6 = CreateFont(15, 0, 0, 0, 1000, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "나눔고딕");
				HFONT oldFont6 = (HFONT)SelectObject(getMemDC(), myFont6);
				SetTextColor(getMemDC(), RGB(255, 0, 0));
				_myArmyVector[i].characterDefImage->frameRender(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, 0, 4);
				char dmgStr[128];
				wsprintf(dmgStr, "%d", _myArmyVector[i].currentDmg);
				TextOut(getMemDC(), _myArmyVector[i].rc.left, _myArmyVector[i].rc.top, dmgStr, strlen(dmgStr));
				SelectObject(getMemDC(), oldFont6);
				DeleteObject(myFont6);
			}
			if (isPheonixSkill)
			{
				_myArmyVector[_selectNum].characterAttackImage->frameRender(getMemDC(), _myArmyVector[_selectNum].rc.left-8, _myArmyVector[_selectNum].rc.top-8, 0, 0);
			}
			if (fireEffectOn)
			{
				_myArmyVector[_selectNum].characterAttackImage->frameRender(getMemDC(), _myArmyVector[_selectNum].rc.left-8, _myArmyVector[_selectNum].rc.top-8, 0, 3);
			}
		}


	}


	if (_isShowState)
	{
		IMAGEMANAGER->findImage("유닛정보창")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth(), 300);
		IMAGEMANAGER->findImage("유닛정보창_내용")->alphaRender(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 1, 301, 160);

		IMAGEMANAGER->findImage("체력아이콘")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 15, 400);
		IMAGEMANAGER->findImage("mp아이콘")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 15, 430);
		if(myArmyShowState)
		IMAGEMANAGER->findImage("경험치아이콘")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 15, 460);
		//IMAGEMANAGER->findImage("손해")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 20, 500);
		//IMAGEMANAGER->findImage("명중")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 110, 500);
		//IMAGEMANAGER->findImage("무기경험치아이콘")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 20, 530);
		//IMAGEMANAGER->findImage("방어구경험치아이콘")->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 110, 530);
	}

	//test
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		char str[128];
		char str2[128];
		//wsprintf(str, "tileNum");
		//NONE 과 바로 아래 tile도 같이 나온다
		if (PtInRect(&_tiles[i].rc, m_ptMouse))
		{
			IMAGEMANAGER->findImage("맵_지형")->alphaRender(getMemDC(), 1032, 204, 160);
			IMAGEMANAGER->render("m023", getMemDC(), 1040, 212, _tiles[i].rc.left, _tiles[i].rc.top, 48, 48);
			//wsprintf(str, "tileNum : %d", _tiles[i].terrain);
			//불,물,암석,바람
			if (_tiles[i].canEarthMagic)
			{
				IMAGEMANAGER->render("땅마법가능", getMemDC(), 1112, 272);
			}
			else if (!_tiles[i].canEarthMagic)
			{
				IMAGEMANAGER->render("땅마법불가", getMemDC(), 1112, 272);
			}
			if (_tiles[i].canFireMagic)
			{
				IMAGEMANAGER->render("불마법가능", getMemDC(), 1048, 272);
			}
			else if (!_tiles[i].canFireMagic)
			{
				IMAGEMANAGER->render("불마법불가", getMemDC(), 1048, 272);
			}
			if (_tiles[i].canWaterMagic)
			{
				IMAGEMANAGER->render("물마법가능", getMemDC(), 1080, 272);
			}
			else if (!_tiles[i].canWaterMagic)
			{
				IMAGEMANAGER->render("물마법불가", getMemDC(), 1080, 272);
			}
			if (_tiles[i].canWindMagic)
			{
				IMAGEMANAGER->render("바람마법가능", getMemDC(), 1144, 272);
			}
			else if (!_tiles[i].canWindMagic)
			{
				IMAGEMANAGER->render("바람마법불가", getMemDC(), 1144, 272);
			}

			switch (_tiles[i].terrain)
			{
			case TR_RIVER:
				break;
			case TR_OCEAN:
				break;
			case TR_POND:
				break;
			case TR_DITCH:
				//wsprintf(str, "%s", "도랑");
				IMAGEMANAGER->render("도랑", getMemDC(), 1098, 217);
				IMAGEMANAGER->render("이동불가지형", getMemDC(), 1098, 245);
				break;
			case TR_SHIP:
				break;
			case TR_SNOWLAND:
				IMAGEMANAGER->render("설원", getMemDC(), 1098, 217);
				break;
			case TR_FORTRESS:
				break;
			case TR_TOWN:
				break;
			case TR_HOUSE:
				IMAGEMANAGER->render("가옥", getMemDC(), 1098, 217);
				break;
			case TR_BARRACK:
				IMAGEMANAGER->render("병영", getMemDC(), 1098, 217);
				IMAGEMANAGER->render("회복있음", getMemDC(), 1098, 245);
				break;
			case TR_ALTAR:
				break;
			case TR_FENCE:
				IMAGEMANAGER->render("울타리", getMemDC(), 1098, 217);
				IMAGEMANAGER->render("이동불가지형", getMemDC(), 1098, 245);
				break;
			case TR_TREASURE:
				IMAGEMANAGER->render("보물고", getMemDC(), 1098, 217);
				break;
			case TR_GRASS:
				break;
			case TR_UNDERGROUND:
				break;
			case TR_FLATLAND:
				break;
			case TR_WASTELAND:
				break;
			case TR_MOUNTAIN:
				break;
			case TR_FOREST:
				//wsprintf(str, "%s", "숲");
				IMAGEMANAGER->render("숲", getMemDC(), 1098, 217);
				break;
			case TR_WETLAND:
				break;
			case TR_RAPIDS:
				break;
			case TR_CLIFF:
				break;
			case TR_ROCKMOUNTAIN:
				break;
			case TR_BRIDGE:
				IMAGEMANAGER->render("다리", getMemDC(), 1098, 217);
				break;
			case TR_RAMPART:
				IMAGEMANAGER->render("성벽", getMemDC(), 1098, 217);
				IMAGEMANAGER->render("이동불가지형", getMemDC(), 1098, 245);
				break;
			case TR_CASTLELAND:
				IMAGEMANAGER->render("성내", getMemDC(), 1098, 217);
				break;
			case TR_FIRE:
				break;
			case TR_GATEWAY:
				break;
			case TR_CASTLE:
				IMAGEMANAGER->render("성", getMemDC(), 1098, 217);
				IMAGEMANAGER->render("회복있음", getMemDC(), 1098, 245);

				break;
			case TR_CASTLEGATE:
				break;
			case TR_NONE:
				break;
			default:
				break;
			}
			//TextOut(getMemDC(), 1043, 200, str, strlen(str));

		}



	}

	_isShowState = false;
	myArmyShowState = false;
	for (int j = 0; j < _enemyVector.size(); j++)
	{
		if (PtInRect(&_enemyVector[j].rc, m_ptMouse) && _enemyVector[j].currentHp > 0 )
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
			//char expStr[128];

			_isShowState = true;

			_enemyVector[j].characterFaceImage->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 9, 309);


			_hpBarEnemyVector[j]->render();
			_mpBarEnemyVector[j]->render();

			wsprintf(levelStr, "Lv %d", _enemyVector[j].level);
			wsprintf(nameStr, "%s", _enemyVector[j].name);


			
			wsprintf(hpStr, "%d / %d", _enemyVector[j].currentHp, _enemyVector[j].maxHp);
			wsprintf(mpStr, "%d / %d", _enemyVector[j].currentMp,_enemyVector[j].maxMp);
			wsprintf(strStr, "무력 : %d", _enemyVector[j].str);
			wsprintf(dexStr, "민첩 : %d", _enemyVector[j].dex);
			wsprintf(intelligenceStr, "지력 : %d", _enemyVector[j].intelligence);
			wsprintf(luckStr, "운 : %d", _enemyVector[j].luck);
			wsprintf(cmdStr, "통솔 : %d", _enemyVector[j].cmd);
			wsprintf(atkStr, "공격력 : %d", _enemyVector[j].atk);
			wsprintf(mAtkStr, "정신력 : %d", _enemyVector[j].mAtk);
			wsprintf(defStr, "방어력 : %d", _enemyVector[j].def);

			wsprintf(spdStr, "순발력 : %d", _enemyVector[j].spd);
			wsprintf(moveStr, "이동력 : %d", _enemyVector[j].move);
			//wsprintf(expStr, "%d", _enemyVector[j].exp);
			HFONT myFont = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "궁서");
			HFONT oldFont = (HFONT)SelectObject(getMemDC(), myFont);
			SetTextColor(getMemDC(), RGB(60, 80, 255));
			TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 85, 309, nameStr, strlen(nameStr));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(myFont);

			HFONT myFont1 = CreateFont(15, 0, 0, 0, 600, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "궁서");
			HFONT oldFont1 = (HFONT)SelectObject(getMemDC(), myFont1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));

			TextOut(getMemDC(), WINSIZEX -  60, 309, levelStr, strlen(levelStr));


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
	for (int j = 0; j < _myArmyVector.size(); j++)
	{
		if (PtInRect(&_myArmyVector[j].rc, m_ptMouse) && _myArmyVector[j].currentHp >= 0)
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
			myArmyShowState = true;
			_myArmyVector[j].characterFaceImage->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("유닛정보창")->getWidth() + 9, 309);

			wsprintf(levelStr, "Lv %d", _myArmyVector[j].level);
			wsprintf(nameStr, "%s", _myArmyVector[j].name);

			_hpBarMyVector[j]->render();
			_mpBarMyVector[j]->render();
			_expBarMyVector[j]->render();


			wsprintf(hpStr, "%d / %d", _myArmyVector[j].currentHp, _myArmyVector[j].maxHp);
			wsprintf(mpStr, "%d / %d", _myArmyVector[j].currentMp, _myArmyVector[j].maxMp);
			wsprintf(strStr, "무력 : %d", _myArmyVector[j].str);
			wsprintf(dexStr, "민첩 : %d", _myArmyVector[j].dex);
			wsprintf(intelligenceStr, "지력 : %d", _myArmyVector[j].intelligence);
			wsprintf(luckStr, "운 : %d", _myArmyVector[j].luck);
			wsprintf(cmdStr, "통솔 : %d", _myArmyVector[j].cmd);
			wsprintf(atkStr, "공격력 : %d", _myArmyVector[j].atk);
			wsprintf(mAtkStr, "정신력 : %d", _myArmyVector[j].mAtk);
			wsprintf(defStr, "방어력 : %d", _myArmyVector[j].def);
			wsprintf(spdStr, "순발력 : %d", _myArmyVector[j].spd);
			wsprintf(moveStr, "이동력 : %d", _myArmyVector[j].move);
			//wsprintf(expStr, "%d", _enemyVector[j].exp);
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

			IMAGEMANAGER->render("슬롯", getMemDC(), 999, 499);
			IMAGEMANAGER->render("슬롯", getMemDC(), 1063, 499);



			if (strcmp(_myArmyVector[j].name, "조조") == 0)
			{
				IMAGEMANAGER->render("의천검", getMemDC(), 1000, 500);
				IMAGEMANAGER->render("가죽갑옷", getMemDC(), 1064, 500);
			}
			if (strcmp(_myArmyVector[j].name, "서황") == 0)
			{
				IMAGEMANAGER->render("반궁", getMemDC(), 1000, 500);
				IMAGEMANAGER->render("가죽갑옷", getMemDC(), 1064, 500);
			}
			if (strcmp(_myArmyVector[j].name, "순욱") == 0)
			{
				IMAGEMANAGER->render("죽선", getMemDC(), 1000, 500);
				IMAGEMANAGER->render("무명옷", getMemDC(), 1064, 500);
			}

		}
	}



	//IMAGEMANAGER->render("미니맵", getMemDC(), 973, 20);
	//IMAGEMANAGER->render("미니맵", getMemDC(), 1032, 60);
	IMAGEMANAGER->findImage("m023")->render(getMemDC(), 1032, 40, IMAGEMANAGER->findImage("m023")->getWidth() / 6, IMAGEMANAGER->findImage("m023")->getHeight() / 6);
	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		BeginSolidColor(getMemDC(), &brush, RGB(255, 0, 0));
		if(_myArmyVector[i].currentHp>0)
		Rectangle(getMemDC(), 1032 + _myArmyVector[i].rc.left / 6, 40 + _myArmyVector[i].rc.top / 6, 1032 + _myArmyVector[i].rc.left / 6 + 8, 40 + _myArmyVector[i].rc.top / 6 + 8);
		DeleteObject(brush);
	}

	for (int i = 0; i < _enemyVector.size(); i++)
	{
		BeginSolidColor(getMemDC(), &brush, RGB(0, 0, 255));
		if (_enemyVector[i].currentHp > 0)
		Rectangle(getMemDC(), 1032 + _enemyVector[i].rc.left / 6, 40 + _enemyVector[i].rc.top / 6, 1032 + _enemyVector[i].rc.left / 6 + 8, 40 + _enemyVector[i].rc.top / 6 + 8);
		DeleteObject(brush);
	}
	//if (currentSelect == SELECT_START)
	//{
	//	TextOut(getMemDC(), 0, 800, "currentSelect == SELECT_START", strlen("currentSelect == SELECT_START"));
	//}
	//else if (currentSelect == SELECT_END)
	//{
	//	TextOut(getMemDC(), 0, 800, "currentSelect == SELECT_END", strlen("currentSelect == SELECT_END"));
	//}

	//if (_attackOptionMenu)
	//{
	//	TextOut(getMemDC(), 0, 830, "_attackOptionMenu == true", strlen("_attackOptionMenu == true"));
	//}
	//else if (!_attackOptionMenu)
	//{
	//	TextOut(getMemDC(), 0, 830, "_attackOptionMenu == false", strlen("_attackOptionMenu == false"));
	//}
	//char flagStr[128];
	//wsprintf(flagStr, "turnFlag : %d", _turnFlag);
	//TextOut(getMemDC(), 0, 850, flagStr, strlen(flagStr));





	if (_attackOptionMenu)
	{
		IMAGEMANAGER->render("공격옵션", getMemDC(), _battleOption.left, _battleOption.top);
		if(!_canAttack)
			IMAGEMANAGER->render("공격메뉴_공격_비활성화", getMemDC(), _battleOptionAttack.left, _battleOptionAttack.top);
		else if(_canAttack)
			IMAGEMANAGER->render("공격메뉴_공격_활성화", getMemDC(), _battleOptionAttack.left, _battleOptionAttack.top);
		if(!_canMagic)
			IMAGEMANAGER->render("공격메뉴_책략_비활성화", getMemDC(), _battleOptionMagic.left, _battleOptionMagic.top);
		else if(_canMagic)
			IMAGEMANAGER->render("공격메뉴_책략_활성화", getMemDC(), _battleOptionMagic.left, _battleOptionMagic.top);
		IMAGEMANAGER->render("공격메뉴_도구_비활성화", getMemDC(), _battleOptionItem.left, _battleOptionItem.top);
		IMAGEMANAGER->render("공격메뉴_대기", getMemDC(), _battleOptionDone.left, _battleOptionDone.top);
		IMAGEMANAGER->render("공격메뉴_취소", getMemDC(), _battleOptionCancle.left, _battleOptionCancle.top);
	}



	if (_isDebug)
	{
		//Rectangle(getMemDC(), _battleOption.left, _battleOption.top, _battleOption.right, _battleOption.bottom);
		//Rectangle(getMemDC(), _battleOptionAttack.left, _battleOptionAttack.top, _battleOptionAttack.right, _battleOptionAttack.bottom);
		//Rectangle(getMemDC(), _battleOptionMagic.left, _battleOptionMagic.top, _battleOptionMagic.right, _battleOptionMagic.bottom);
		//Rectangle(getMemDC(), _battleOptionItem.left, _battleOptionItem.top, _battleOptionItem.right, _battleOptionItem.bottom);
		//Rectangle(getMemDC(), _battleOptionDone.left, _battleOptionDone.top, _battleOptionDone.right, _battleOptionDone.bottom);
		//Rectangle(getMemDC(), _battleOptionCancle.left, _battleOptionCancle.top, _battleOptionCancle.right, _battleOptionCancle.bottom);
		//
		//for (int i = 0; i < _attackRangeTilesRectVector.size(); i++)
		//{
		//	Rectangle(getMemDC(), _attackRangeTilesRectVector[i].left, _attackRangeTilesRectVector[i].top, _attackRangeTilesRectVector[i].right, _attackRangeTilesRectVector[i].bottom);

		//}
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			char str[128];
			wsprintf(str, "%d", i);
			TextOut(getMemDC(), i%TILEX*TILESIZE, i / TILEX * TILESIZE, str, strlen(str));
		}
	}


	IMAGEMANAGER->findImage("날씨_맑음")->frameRender(getMemDC(), 960, 0, _weatherFrameX, _weatherFrameY);

	/*
	"공격옵션"
	"공격메뉴_공격_비활성화"
	"공격메뉴_공격_활성화", 
	"공격메뉴_도구_비활성화"
	"공격메뉴_도구_활성화", 
	"공격메뉴_책략_비활성화"
	"공격메뉴_책략_활성화", 

	*/
	char turnCountStr[128];
	wsprintf(turnCountStr, "제 %d턴", turnCount);

	HFONT myFont4 = CreateFont(70, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "나눔고딕");
	HFONT oldFont4 = (HFONT)SelectObject(getMemDC(), myFont4);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	if (_myTurnImage)
	{


		IMAGEMANAGER->render("아군턴", getMemDC());
		TextOut(getMemDC(), 375, 540, turnCountStr, strlen(turnCountStr));


		//IMAGEMANAGER->findImage("아군턴")->render(getMemDC());
	}
	else if (_enemyTurnImage)
	{
		IMAGEMANAGER->render("적군턴", getMemDC());
		TextOut(getMemDC(), 375, 540, turnCountStr, strlen(turnCountStr));
		//IMAGEMANAGER->findImage("적군턴")->render(getMemDC());
	}
	SelectObject(getMemDC(), oldFont4);
	DeleteObject(myFont4);
	if (_myArmyVector[_selectNum].isMagic)
	{
		IMAGEMANAGER->render("순욱_스킬", getMemDC(), _battleOption.left, _battleOption.top);

		//Rectangle(getMemDC(), skillRect.left, skillRect.top, skillRect.right, skillRect.bottom);
		//Rectangle(getMemDC(), skillCancleRect.left, skillCancleRect.top, skillCancleRect.right, skillCancleRect.bottom);

	}
	if(isPheonixSkill)
		IMAGEMANAGER->frameRender("주작", getMemDC(), pheonixSkillImage->getX(), pheonixSkillImage->getY(), pheonixSkillCurrentFrameX, pheonixSkillCurrentFrameY);
	if(fireEffectOn)
		IMAGEMANAGER->frameRender("불스킬이펙트", getMemDC(), _enemyVector[skillHitNum].rc.left-15, _enemyVector[skillHitNum].rc.top-43, fireEffectCurrentFrameX, fireEffectCurrentFrameY);
}

//적벡터 아군벡터를 놓고 .dat을 load.
//그렇게 해서 나온 tagCharacter를 벡터에 담기
//담은 벡터에 rc를 한번더 그리고 render하기
void map1_1::load()
{
	file = CreateFile
	("mapData.map",				//생성할 파일또는 열 장치나 파일이름
		GENERIC_READ,			//파일이나 장치를 만들거나 열때 사용할 권한
		0,						//파일 공유 모드입력
		NULL,					//파일또는 장치를 열때 보안 및 특성
		OPEN_EXISTING,			//파일이나 장치를 열때 취할 행동
		FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
		NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	CloseHandle(file);

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_tiles[i].dis == DISTIN_NONE)continue;
		char fileName[128];
		strcpy(fileName, _tiles[i].tileCharacter.name);
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
		_character.rc.left = _tiles[i].rc.left;
		_character.rc.top = _tiles[i].rc.top;
		_character.rc.right = _tiles[i].rc.right;
		_character.rc.bottom = _tiles[i].rc.bottom;
		_character.maxHp = _character.currentHp = _character.hp;
		_character.maxMp = _character.currentMp = _character.mp;
		_character.maxExp = 100;

		//_maxHP = _currentHP = _character.hp;

		if (_tiles[i].dis == DISTIN_ENEMY)
			_enemyVector.push_back(_character);
		else if (_tiles[i].dis == DISTIN_MINE)
			_myArmyVector.push_back(_character);
		CloseHandle(file);

	}


	//속성정의를 하자.
	//탱크에서 tile속성설정 해줘야함.
	memset(_attribute, 0, sizeof(DWORD)*TILEX*TILEY);

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_tiles[i].terrain == TR_DITCH)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
		}
		if (_tiles[i].terrain == TR_FENCE)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
		}
		if (_tiles[i].terrain == TR_RAMPART)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
		}

	}
}


void map1_1::Astar()
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
			if (_tiles[y * TILEX + x].block) tempBlock[i] = true;
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
					_tiles[y * TILEX + x].g = 10;
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
					_tiles[y * TILEX + x].g = 14;

				}
				//abs절대값

				_tiles[y * TILEX + x].h = (abs(endX - x) + abs(endY - y)) * 10;
				_tiles[y * TILEX + x].f = _tiles[y * TILEX + x].g + _tiles[y * TILEX + x].h;

				// 오픈리스트에 있으면 g 비용 비교 후 처리
				isOpen = false;
				for (int i = 0; i < openList.size(); i++)
				{
					if (openList[i] == y * TILEX + x)
					{
						isOpen = true;
						if (_tiles[openList[i]].g > _tiles[y * TILEX + x].g)
						{
							_tiles[openList[i]].h = _tiles[y * TILEX + x].h;
							_tiles[openList[i]].g = _tiles[y * TILEX + x].g;
							_tiles[openList[i]].f = _tiles[y * TILEX + x].f;
							_tiles[openList[i]].node = currentTile;
						}
					}
				}
				// 없으면 그냥 넣고 부모 설정
				if (!isOpen)
				{
					openList.push_back(y * TILEX + x);
					_tiles[y * TILEX + x].node = currentTile;
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
		int min = _tiles[*openList.begin()].h;
		currentTile = *openList.begin();
		for (iter = openList.begin(); iter != openList.end(); ++iter)
		{
			if (min > _tiles[(*iter)].h)
			{
				min = _tiles[(*iter)].h;
				currentTile = *iter;
			}
		}
	}
	//}

	// 타일 렌더를 위해 상태 저장
	for (int i = 0; i < openList.size(); i++)
	{
		_tiles[openList[i]].showState = STATE_OPEN;
	}
	for (int i = 0; i < closeList.size(); i++)
	{
		_tiles[closeList[i]].showState = STATE_CLOSE;
	}
	// 길 찾기 성공시 각 타일에 길찾기 상태 저장
	int tempTile = endTile;
	//if(_turnFlag == 0)
	moveStack.push(endTile);
	while (_tiles[tempTile].node != startTile
		&& isFind)
	{
		tempTile = _tiles[tempTile].node;
		moveStack.push(tempTile);
		_tiles[tempTile].showState = STATE_PATH;
	}

}

void map1_1::floodFill(int tile, int moveCount)
{
	//베이스
	//if (tile >= 0 && tile <= 400)
	//{
	//	//bool recursionContinue = true;
	//	if (moveCount > 0)
	//	{
	//		//testCircle = RectMake(tile%TILEX*48, tile/TILEX*48,48,48);
	//		_tiles[tile].showState = STATE_PATH;
	//		floodFill(tile - 20, moveCount - 1);
	//		floodFill(tile + 20, moveCount - 1);
	//		floodFill(tile - 1, moveCount - 1);
	//		floodFill(tile + 1, moveCount - 1);
	//		//testCircleVector.push_back(testCircle);
	//	}
	//}
	int count;



	//이 타일들만 canMove true가 되고
	//이동 후에는 다시 false
	if (tile >= 0 && tile <= 400)
	{
		if (_tiles[tile].terrain == TR_CASTLELAND)
		{
			count = moveCount - 2;
		}
		else
		{
			count = moveCount - 1;
		}
		//bool recursionContinue = true;
		if (count >= 0 && !_tiles[tile].block)
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
			_tiles[tile].floodFill = true;
		}
	}
}

void map1_1::animation()
{

	if (!_attackOptionMenu)
	{
		if (!_myArmyVector[_selectNum].isAttackMotion)// || !_myArmyVector[_selectNum].isDone)
		{
			for (int i = 0; i < _myArmyVector.size(); i++)
			{
				if (!_myArmyVector[i].isDone)
				{
					switch (_myArmyVector[i].direction)
					{
					case CHARACTER_DIRECTION_LEFT:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 4 || _myArmyVector[i].currentFrameY > 5)
							_myArmyVector[i].currentFrameY = 4;
						if (_myArmyVector[i].count % 25 == 0)
						{
							_myArmyVector[i].currentFrameY++;
							if (_myArmyVector[i].currentFrameY > 5)
								_myArmyVector[i].currentFrameY = 4;
							_myArmyVector[i].count = 0;
						}
						break;
					case CHARACTER_DIRECTION_RIGHT:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 6 || _myArmyVector[i].currentFrameY > 7)
							_myArmyVector[i].currentFrameY = 6;
						if (_myArmyVector[i].count % 25 == 0)
						{
							_myArmyVector[i].currentFrameY++;
							if (_myArmyVector[i].currentFrameY > 7)
								_myArmyVector[i].currentFrameY = 6;
							_myArmyVector[i].count = 0;
						}
						break;
					case CHARACTER_DIRECTION_TOP:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 2 || _myArmyVector[i].currentFrameY > 3)
							_myArmyVector[i].currentFrameY = 2;
						if (_myArmyVector[i].count % 25 == 0)
						{
							_myArmyVector[i].currentFrameY++;
							if (_myArmyVector[i].currentFrameY > 3)
								_myArmyVector[i].currentFrameY = 2;
							_myArmyVector[i].count = 0;
						}
						break;
					case CHARACTER_DIRECTION_BOTTOM:
						_myArmyVector[i].count++;
						if (_myArmyVector[i].currentFrameY < 0 || _myArmyVector[i].currentFrameY > 1)
							_myArmyVector[i].currentFrameY = 0;
						if (_myArmyVector[i].count % 25 == 0)
						{
							_myArmyVector[i].currentFrameY++;
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
		}

		for (int i = 0; i < _enemyVector.size(); i++)
		{
			switch (_enemyVector[i].direction)
			{
			case CHARACTER_DIRECTION_LEFT:
				_enemyVector[i].count++;
				if (_enemyVector[i].currentFrameY < 4 || _enemyVector[i].currentFrameY > 5)
					_enemyVector[i].currentFrameY = 4;
				if (_enemyVector[i].count % 25 == 0)
				{
					_enemyVector[i].currentFrameY++;
					if (_enemyVector[i].currentFrameY > 5)
						_enemyVector[i].currentFrameY = 4;
					_enemyVector[i].count = 0;
				}
				break;
			case CHARACTER_DIRECTION_RIGHT:
				_enemyVector[i].count++;
				if (_enemyVector[i].currentFrameY < 6 || _enemyVector[i].currentFrameY > 7)
					_enemyVector[i].currentFrameY = 6;
				if (_enemyVector[i].count % 25 == 0)
				{
					_enemyVector[i].currentFrameY++;
					if (_enemyVector[i].currentFrameY > 7)
						_enemyVector[i].currentFrameY = 6;
					_enemyVector[i].count = 0;
				}
				break;
			case CHARACTER_DIRECTION_TOP:
				_enemyVector[i].count++;
				if (_enemyVector[i].currentFrameY < 2 || _enemyVector[i].currentFrameY > 3)
					_enemyVector[i].currentFrameY = 2;
				if (_enemyVector[i].count % 25 == 0)
				{
					_enemyVector[i].currentFrameY++;
					if (_enemyVector[i].currentFrameY > 3)
						_enemyVector[i].currentFrameY = 2;
					_enemyVector[i].count = 0;
				}
				break;
			case CHARACTER_DIRECTION_BOTTOM:
				_enemyVector[i].count++;
				if (_enemyVector[i].currentFrameY < 0 || _enemyVector[i].currentFrameY > 1)
					_enemyVector[i].currentFrameY = 0;
				if (_enemyVector[i].count % 25 == 0)
				{
					_enemyVector[i].currentFrameY++;
					if (_enemyVector[i].currentFrameY > 1)
						_enemyVector[i].currentFrameY = 0;
					_enemyVector[i].count = 0;
				}
				break;
			}
		}

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

			if (!strcmp(_myArmyVector[_selectNum].classType, "궁병") || !strcmp(_myArmyVector[_selectNum].classType, "궁기병"))
			{
				if (_myArmyVector[_selectNum].attackCount <= 30)
				{
					_myArmyVector[_selectNum].attackFrameY = 8;
				}
				if (_myArmyVector[_selectNum].attackCount <= 60&& _myArmyVector[_selectNum].attackCount > 30)
				{
					_myArmyVector[_selectNum].attackFrameY = 9;
				}
				if (_myArmyVector[_selectNum].attackCount <= 65 && _myArmyVector[_selectNum].attackCount >60)
				{
					_myArmyVector[_selectNum].attackFrameY = 10;
					_enemyVector[_hitNum]._beHitMotion = true;
					_enemyVector[_hitNum]._beHit = true;
				}
				if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount >65)
				{
					_myArmyVector[_selectNum].attackFrameY = 11;

				}
				if (_myArmyVector[_selectNum].attackCount <= 95 && _myArmyVector[_selectNum].attackCount >85)
				{
					_myArmyVector[_selectNum].isAttackMotion = false;
					_myArmyVector[_selectNum].isDone = true;
					_enemyVector[_hitNum]._beHitMotion = false;
					_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
					_myArmyVector[_selectNum].currentExp += 12;
					if (_myArmyVector[_selectNum].currentExp >= 100)
					{
						_myArmyVector[_selectNum].currentExp = 0;
						_myArmyVector[_selectNum].level += 1;
					}
					_doneCount++;
				}
			}
			else
			{
				if (_myArmyVector[_selectNum].attackCount <= 30)
				{
					_myArmyVector[_selectNum].attackFrameY = 8;
				}

				if (_myArmyVector[_selectNum].attackCount > 30 && _myArmyVector[_selectNum].attackCount % 5 == 0)
				{
					_myArmyVector[_selectNum].attackFrameY++;
					if (_myArmyVector[_selectNum].attackFrameY == 10)
					{
						_enemyVector[_hitNum]._beHitMotion = true;
						_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackFrameY > 11)
					{
						_myArmyVector[_selectNum].attackFrameY = 11;
						if (_myArmyVector[_selectNum].attackCount > 90)
						{
							_myArmyVector[_selectNum].isAttackMotion = false;
							_myArmyVector[_selectNum].isDone = true;
							_enemyVector[_hitNum]._beHitMotion = false;
							_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
							_myArmyVector[_selectNum].currentExp += 12;
							if (_myArmyVector[_selectNum].currentExp >= 100)
							{
								_myArmyVector[_selectNum].currentExp = 0;
								_myArmyVector[_selectNum].level += 1;
							}
							_doneCount++;

						}
					}
				}
			}


			break;
		case CHARACTER_DIRECTION_RIGHT:
			_myArmyVector[_selectNum].attackCount++;
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
					_enemyVector[_hitNum]._beHitMotion = true;
					_enemyVector[_hitNum]._beHit = true;
				}
				if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
				{
					_myArmyVector[_selectNum].attackFrameY = 15;

				}
				if (_myArmyVector[_selectNum].attackCount <= 95 && _myArmyVector[_selectNum].attackCount > 85)
				{
					_myArmyVector[_selectNum].isAttackMotion = false;
					_myArmyVector[_selectNum].isDone = true;

					_enemyVector[_hitNum]._beHitMotion = false;
					_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
					_myArmyVector[_selectNum].currentExp += 12;
					if (_myArmyVector[_selectNum].currentExp >= 100)
					{
						_myArmyVector[_selectNum].currentExp = 0;
						_myArmyVector[_selectNum].level += 1;
					}
					_doneCount++;
				}
			}
			else
			{
				if (_myArmyVector[_selectNum].attackCount <= 40)
				{
					_myArmyVector[_selectNum].attackFrameY = 12;
				}

				if (_myArmyVector[_selectNum].attackCount > 40 && _myArmyVector[_selectNum].attackCount % 5 == 0)
				{
					_myArmyVector[_selectNum].attackFrameY++;
					if (_myArmyVector[_selectNum].attackFrameY == 14)
					{
						_enemyVector[_hitNum]._beHitMotion = true;
						_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackFrameY > 15)
					{
						_myArmyVector[_selectNum].attackFrameY = 15;
						if (_myArmyVector[_selectNum].attackCount > 70)
						{
							_myArmyVector[_selectNum].isAttackMotion = false;
							_myArmyVector[_selectNum].isDone = true;
							_enemyVector[_hitNum]._beHitMotion = false;
							_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
							_myArmyVector[_selectNum].currentExp += 12;
							if (_myArmyVector[_selectNum].currentExp >= 100)
							{
								_myArmyVector[_selectNum].currentExp = 0;
								_myArmyVector[_selectNum].level += 1;
							}
							_doneCount++;

						}
					}
				}
			}

			break;
		case CHARACTER_DIRECTION_TOP:
			_myArmyVector[_selectNum].attackCount++;
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
					_enemyVector[_hitNum]._beHitMotion = true;
					_enemyVector[_hitNum]._beHit = true;
				}
				if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
				{
					_myArmyVector[_selectNum].attackFrameY = 7;

				}
				if (_myArmyVector[_selectNum].attackCount <= 95 && _myArmyVector[_selectNum].attackCount > 85)
				{
					_myArmyVector[_selectNum].isAttackMotion = false;
					_myArmyVector[_selectNum].isDone = true;

					_enemyVector[_hitNum]._beHitMotion = false;
					_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
					_myArmyVector[_selectNum].currentExp += 12;
					if (_myArmyVector[_selectNum].currentExp >= 100)
					{
						_myArmyVector[_selectNum].currentExp = 0;
						_myArmyVector[_selectNum].level += 1;
					}
					_doneCount++;
				}
			}
			else
			{
				if (_myArmyVector[_selectNum].attackCount <= 40)
				{
					_myArmyVector[_selectNum].attackFrameY = 4;
				}

				if (_myArmyVector[_selectNum].attackCount > 40 && _myArmyVector[_selectNum].attackCount % 5 == 0)
				{
					_myArmyVector[_selectNum].attackFrameY++;
					if (_myArmyVector[_selectNum].attackFrameY == 6)
					{
						_enemyVector[_hitNum]._beHitMotion = true;
						_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackFrameY > 7)
					{
						_myArmyVector[_selectNum].attackFrameY = 7;
						if (_myArmyVector[_selectNum].attackCount > 70)
						{
							_myArmyVector[_selectNum].isAttackMotion = false;
							_myArmyVector[_selectNum].isDone = true;
							_enemyVector[_hitNum]._beHitMotion = false;
							_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
							_myArmyVector[_selectNum].currentExp += 12;
							if (_myArmyVector[_selectNum].currentExp >= 100)
							{
								_myArmyVector[_selectNum].currentExp = 0;
								_myArmyVector[_selectNum].level += 1;
							}
							_doneCount++;

						}
					}
				}
			}

			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_myArmyVector[_selectNum].attackCount++;

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
					_enemyVector[_hitNum]._beHitMotion = true;
					_enemyVector[_hitNum]._beHit = true;
				}
				if (_myArmyVector[_selectNum].attackCount <= 85 && _myArmyVector[_selectNum].attackCount > 65)
				{
					_myArmyVector[_selectNum].attackFrameY = 3;
				}
				if (_myArmyVector[_selectNum].attackCount <= 95 && _myArmyVector[_selectNum].attackCount > 85)
				{
					_myArmyVector[_selectNum].isAttackMotion = false;
					_myArmyVector[_selectNum].isDone = true;

					_enemyVector[_hitNum]._beHitMotion = false;
					_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
					_myArmyVector[_selectNum].currentExp += 12;
					if (_myArmyVector[_selectNum].currentExp >= 100)
					{
						_myArmyVector[_selectNum].currentExp = 0;
						_myArmyVector[_selectNum].level += 1;
					}
					_doneCount++;
				}
			}
			else
			{
				if (_myArmyVector[_selectNum].attackCount <= 40)
				{
					_myArmyVector[_selectNum].attackFrameY = 0;
				}

				if (_myArmyVector[_selectNum].attackCount > 40 && _myArmyVector[_selectNum].attackCount % 5 == 0 && _myArmyVector[_selectNum].attackCount <= 90)
				{
					_myArmyVector[_selectNum].attackFrameY++;
					if (_myArmyVector[_selectNum].attackFrameY == 2)
					{
						_enemyVector[_hitNum]._beHitMotion = true;
						_enemyVector[_hitNum]._beHit = true;
					}
					if (_myArmyVector[_selectNum].attackFrameY > 3)
					{
						_myArmyVector[_selectNum].attackFrameY = 3;
						if (_myArmyVector[_selectNum].attackCount > 70)
						{
							_myArmyVector[_selectNum].isAttackMotion = false;
							_myArmyVector[_selectNum].isDone = true;
							_enemyVector[_hitNum]._beHitMotion = false;
							_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
							_myArmyVector[_selectNum].currentExp += 12;
							if (_myArmyVector[_selectNum].currentExp >= 100)
							{
								_myArmyVector[_selectNum].currentExp = 0;
								_myArmyVector[_selectNum].level += 1;
							}
							_doneCount++;

						}
					}
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
	}


	if (_enemyVector[AICount].isAttack)
	{
		switch (_enemyVector[AICount].direction)
		{
		case CHARACTER_DIRECTION_LEFT:
			_enemyVector[AICount].currentFrameY = 10;
			break;
		case CHARACTER_DIRECTION_RIGHT:
			_enemyVector[AICount].currentFrameY = 11;
			break;
		case CHARACTER_DIRECTION_TOP:
			_enemyVector[AICount].currentFrameY = 9;
			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_enemyVector[AICount].currentFrameY = 8;
			break;
		}
	}
	if (_enemyVector[AICount].isDone)
	{
		switch (_enemyVector[AICount].direction)
		{
		case CHARACTER_DIRECTION_LEFT:
			_enemyVector[AICount].doneFrameY = 2;
			_enemyVector[AICount].currentFrameY = 10;
			break;
		case CHARACTER_DIRECTION_RIGHT:
			_enemyVector[AICount].doneFrameY = 3;
			_enemyVector[AICount].currentFrameY = 11;
			break;
		case CHARACTER_DIRECTION_TOP:
			_enemyVector[AICount].doneFrameY = 1;
			_enemyVector[AICount].currentFrameY = 9;
			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_enemyVector[AICount].doneFrameY = 0;
			_enemyVector[AICount].currentFrameY = 8;
			break;
		}
	}

	else if (_enemyVector[AICount].isAttackMotion)
	{

		switch (_enemyVector[AICount].direction)
		{
		case CHARACTER_DIRECTION_LEFT:

			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 40)
			{
				_enemyVector[AICount].attackFrameY = 8;
			}

			if (_enemyVector[AICount].attackCount > 40 && _enemyVector[AICount].attackCount % 5 == 0)
			{
				_enemyVector[AICount].attackFrameY++;
				if (_enemyVector[AICount].attackFrameY == 10)
				{
						_myArmyVector[beHitNum]._beHitMotion = true;
						_myArmyVector[beHitNum]._beHit = true;

				}
				if (_enemyVector[AICount].attackFrameY > 11)
				{
					_enemyVector[AICount].attackFrameY = 11;
					if (_enemyVector[AICount].attackCount > 70)
					{
						_enemyVector[AICount].isAttackMotion = false;
						_myArmyVector[beHitNum]._beHitMotion = false;

						_enemyVector[AICount].isDone = true;
					}
				}
			}


			break;
		case CHARACTER_DIRECTION_RIGHT:
			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 40)
			{
				_enemyVector[AICount].attackFrameY = 12;
			}

			if (_enemyVector[AICount].attackCount > 40 && _enemyVector[AICount].attackCount % 5 == 0)
			{
				_enemyVector[AICount].attackFrameY++;
				if (_enemyVector[AICount].attackFrameY == 14)
				{
						_myArmyVector[beHitNum]._beHitMotion = true;
						_myArmyVector[beHitNum]._beHit = true;
				}
				if (_enemyVector[AICount].attackFrameY > 15)
				{
					_enemyVector[AICount].attackFrameY = 15;
					if (_enemyVector[AICount].attackCount > 70)
					{
						_enemyVector[AICount].isAttackMotion = false;
						_myArmyVector[beHitNum]._beHitMotion = false;
						_enemyVector[AICount].isDone = true;

					}
				}
			}

			break;
		case CHARACTER_DIRECTION_TOP:
			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 40)
			{
				_enemyVector[AICount].attackFrameY = 4;
			}

			if (_enemyVector[AICount].attackCount > 40 && _enemyVector[AICount].attackCount % 5 == 0)
			{
				_enemyVector[AICount].attackFrameY++;
				if (_enemyVector[AICount].attackFrameY == 6)
				{
						_myArmyVector[beHitNum]._beHitMotion = true;
						_myArmyVector[beHitNum]._beHit = true;
				}
				if (_enemyVector[AICount].attackFrameY > 7)
				{
					_enemyVector[AICount].attackFrameY = 7;
					if (_enemyVector[AICount].attackCount > 70)
					{
						_enemyVector[AICount].isAttackMotion = false;
						_myArmyVector[beHitNum]._beHitMotion = false;
						_enemyVector[AICount].isDone = true;

					}
				}
			}

			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 40)
			{
				_enemyVector[AICount].attackFrameY = 0;
			}

			if (_enemyVector[AICount].attackCount > 40 && _enemyVector[AICount].attackCount % 5 == 0 && _enemyVector[AICount].attackCount <= 90)
			{
				_enemyVector[AICount].attackFrameY++;
				if (_enemyVector[AICount].attackFrameY == 2)
				{
						_myArmyVector[beHitNum]._beHitMotion = true;
						_myArmyVector[beHitNum]._beHit = true;
				}
				if (_enemyVector[AICount].attackFrameY > 3)
				{
					_enemyVector[AICount].attackFrameY = 3;
					if (_enemyVector[AICount].attackCount > 70)
					{
						_enemyVector[AICount].isAttackMotion = false;
						_myArmyVector[beHitNum]._beHitMotion = false;
						_enemyVector[AICount].isDone = true;

					}
				}
			}

			break;
		default:
			break;
		}
	}

	if (!_enemyVector[AICount].isAttackMotion)
	{
		_enemyVector[AICount].attackCount = 0;
	}

}

void map1_1::move(int i)
{
	if (isFind && !moveStack.empty() )// && _canMove)
	{
		if (_myArmyVector[i].rc.left > _tiles[moveStack.top()].rc.left)
		{
			_myArmyVector[i].direction = CHARACTER_DIRECTION_LEFT;
			_myArmyVector[i].rc.left -= 8;
			_myArmyVector[i].rc.right -= 8;
		}
		if (_myArmyVector[i].rc.left < _tiles[moveStack.top()].rc.left)
		{
			_myArmyVector[i].direction = CHARACTER_DIRECTION_RIGHT;
			_myArmyVector[i].rc.left += 8;
			_myArmyVector[i].rc.right += 8;
		}
		if (_myArmyVector[i].rc.top < _tiles[moveStack.top()].rc.top)
		{
			_myArmyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
			_myArmyVector[i].rc.top += 8;
			_myArmyVector[i].rc.bottom += 8;
		}
		if (_myArmyVector[i].rc.top > _tiles[moveStack.top()].rc.top)
		{
			_myArmyVector[i].direction = CHARACTER_DIRECTION_TOP;
			_myArmyVector[i].rc.top -= 8;
			_myArmyVector[i].rc.bottom -= 8;
		}
		if (_myArmyVector[i].rc.left == _tiles[moveStack.top()].rc.left &&
			_myArmyVector[i].rc.top == _tiles[moveStack.top()].rc.top)
		{
			_moveComplete = true;
			_myArmyVector[i].tile = moveStack.top();
			moveStack.pop();
		}

	}
}

void map1_1::enemyVectorMove(int i)
{

	if (isFind && aiVectorCount < AIendTileVector.size() && !_enemyVector[i].isAttack)// && _canMove)//(AIMoveStart) 
	{
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			_tiles[i].attackRange = false;
		}
		moveSpeedIndex = _enemyVector[i].move;
		if (moveSpeedIndex > 6)
		{
			moveSpeedIndex = 6;
		}

		if (_enemyVector[i].rc.left > _tiles[AIendTileVector[aiVectorCount]].rc.left)
		{
			_enemyVector[i].direction = CHARACTER_DIRECTION_LEFT;
			_enemyVector[i].rc.left -= moveSpeed[moveSpeedIndex];
			_enemyVector[i].rc.right -= moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[i].rc.left < _tiles[AIendTileVector[aiVectorCount]].rc.left)
		{
			_enemyVector[i].direction = CHARACTER_DIRECTION_RIGHT;
			_enemyVector[i].rc.left += moveSpeed[moveSpeedIndex];
			_enemyVector[i].rc.right += moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[i].rc.top < _tiles[AIendTileVector[aiVectorCount]].rc.top)
		{
			_enemyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
			_enemyVector[i].rc.top += moveSpeed[moveSpeedIndex];
			_enemyVector[i].rc.bottom += moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[i].rc.top > _tiles[AIendTileVector[aiVectorCount]].rc.top)
		{
			_enemyVector[i].direction = CHARACTER_DIRECTION_TOP;
			_enemyVector[i].rc.top -= moveSpeed[moveSpeedIndex];
			_enemyVector[i].rc.bottom -= moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[i].rc.left == _tiles[AIendTileVector[aiVectorCount]].rc.left  &&
			_enemyVector[i].rc.top == _tiles[AIendTileVector[aiVectorCount]].rc.top)
		{
	
			_moveComplete = true;
			aiVectorCount++;

			for (int j = 0; j < ATTACKTILEX*ATTACKTILEY; j++)
			{
				if (_enemyVector[i].attackArray[j] == 1)
				{
					if (_enemyVector[i].tile + (j - 24) + ((j / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) > 0 && _enemyVector[i].tile + (j - 24) + ((j / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) < 400)
						_tiles[_enemyVector[i].tile + (j - 24) + ((j / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX))].attackRange = true;
				}
			}

			if (aiVectorCount >= AIendTileVector.size())
			{
				for (int j = 0; j < _myArmyVector.size(); j++)
				{
					if (!_tiles[_myArmyVector[j].tile].attackRange)
						_enemyVector[i].isDone = true;
				}
			}
		}
	}


	if (_enemyVector[i].isDone)
	{
		AIClear = true;
	}
}

void map1_1::AI()
{

	if (!_enemyVector[AICount].isSelect)
	{
		_enemyVector[AICount].normalState = true;
		showRange = true;
		startTile = _enemyVector[AICount].tile;
		AIfloodFill(startTile, _enemyVector[AICount].move);
		_enemyVector[AICount].isSelect = true;
	}

	if (startTile != -1)
	{
		AIstartAstar = true;
		AIcurrentTile = startTile;
		_AIopenList.push_back(AIcurrentTile);
	}


	for (int j = 0; j < TILEX*TILEY; j++)
	{
		for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
		{
			if (_enemyVector[AICount].rc.left == _tiles[j].rc.left
				&& _enemyVector[AICount].rc.top == _tiles[j].rc.top)
			{
				_enemyVector[AICount].tile = j;
				if (_enemyVector[AICount].attackArray[i] == 1)
				{
					if (j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) > 0 && j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) < 400)
						_tiles[j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX))].attackRange = true;
				}
			}
		}
	}

	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		if (_tiles[_myArmyVector[i].tile].attackRange && _myArmyVector[i].currentHp>0)//&&!_enemyVector[AICount].isDone)
		{
			_enemyVector[AICount].isAttack = true;
			_myArmyVector[i].currentDmg = _enemyVector[AICount].atk - _myArmyVector[i].def / 2;// +_enemyVector[AICount].level + 25;
			if (mostDmg < _myArmyVector[i].currentDmg)
			{
				mostDmg = _myArmyVector[i].currentDmg;
				beHitTileNum = _myArmyVector[i].tile;
				beHitNum = i;
			}
		}
	}


	if (_myArmyVector[beHitNum]._beHit)
	{
		_attackCount++;
		if (_attackCount < 2)
		{
			_myArmyVector[beHitNum].currentHp -= _myArmyVector[beHitNum].currentDmg;
			_myArmyVector[beHitNum]._beHit = false;
			if (_myArmyVector[beHitNum].currentHp <= 0)
			{
				myArmyDeadCount += 1;
			}
		}
	}
	if (!_myArmyVector[beHitNum]._beHitMotion)
	{
		_attackCount = 0;
		_myArmyVector[beHitNum].currentDmg = 0;

	}


	if (ggCount < _myArmyVector.size())
	{
		while (!AIisFind && !AInoPath &&AIstartAstar && _myArmyVector[ggCount].currentHp>0)
		{
			AIgetTile(_myArmyVector[ggCount].tile);
		}
		//_fNumVector.push_back(number);
		_tileVector.push_back(_myArmyVector[ggCount].tile);
		if (AIisFind && !_tileVector.empty())
		{
			if (minTileF > gg)
			{
				minTileF = gg;
				minTileNumber = ggCount;
			}
			AIisFind = false;
			AInoPath = false;
			_AIopenList.clear();
			_AIcloseList.clear();
			gg = 0;
			ggCount++;
		}
	}
	else
	{
		endTile = _tileVector[minTileNumber];
		_AIopenList.clear();
		_AIcloseList.clear();

	}

	if (startTile != -1 && endTile != -1)
	{
		startAstar = true;
		currentTile = startTile;
		//시작지점을 오픈리스트에 넣자
		openList.push_back(currentTile);

	}


	while (!isFind && !noPath &&startAstar && !AIClear)//&& !_enemyVector[AICount].isAttack)
	{
		AIAstar();
	}

	for (int i = 0; i < AImoveStack.size(); i++)
	{
		if (_tiles[AImoveStack.top()].floodFill)
		{
			AIendTileVector.push_back(AImoveStack.top());
			AImoveStack.pop();
		}
	}


	for (int i = 0; i < _enemyVector.size(); i++)
	{
		if (!AIendTileVector.empty())
		{
			if (AIendTileVector.back() == _enemyVector[AICount].tile)continue;
			if (AIendTileVector.back() == _enemyVector[i].tile)
			{


				AIendTileVector.pop_back();
				if (AIendTileVector.empty())
				{
					_enemyVector[AICount].isDone = true;
				}

			}
		}
	}


	//enemyMove(AICount);
	enemyVectorMove(AICount);

	if (AIClear)
	{
		showRange = true;
		startAstar = false;
		openList.clear();
		closeList.clear();
		AIaStarOpenList.clear();
		AIaStarCloseList.clear();
		isFind = false;
		noPath = false;
		startTile = -1;
		endTile = -1;
		_canMove = false;
		//AIFloodFillCheck = false;
		AIClear = false;
		//AInoPath = false;
		//AIisFind = false;
		isAttach = false;

		ggCount = 0;
		minTileF = 100000;
		minTileNumber = 0;
		aiVectorCount = 0;
		while (!AImoveStack.empty())
		{
			AImoveStack.pop();
		}
		AIendTileVector.clear();
		/*for (int i = 0; i < moveStack.size(); i++)
		{
			moveStack.pop();
		}*/

		
		mostDmg = 0;

		_tileVector.clear();

		for (int i = 0; i < TILEX*TILEY; i++)
		{
			_tiles[i].floodFill = false;
			//_tiles[i].attackRange = false;
		}

	}


	if (_enemyVector[AICount].isAttack)
	{
		_enemyVector[AICount].normalState = false;
		_enemyVector[AICount].isAttack = false;
		_enemyVector[AICount].isAttackMotion = true;
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			_tiles[i].attackRange = false;
		}

		if ((_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) < 0)
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_RIGHT;
		else if ((_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) > 0)
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_LEFT;
		else if (_enemyVector[AICount].tile - beHitTileNum < 0 && (_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) == 0)
			//if ((i % (TILEX+1)) - (_myArmyVector[_selectNum].tile % (TILEX +1)) == 0 && ((i/TILEX)- (_myArmyVector[_selectNum].tile / TILEX)) <0)
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_BOTTOM;
		else if (_enemyVector[AICount].tile - beHitTileNum > 0 && (_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) == 0)
			//if ((i % (TILEX + 1)) - (_myArmyVector[_selectNum].tile % (TILEX + 1)) == 0 && ((i / TILEX) - (_myArmyVector[_selectNum].tile / TILEX)) > 0)
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_TOP;

	

	}


	if (_enemyVector[AICount].isDone)//&& AICount < _enemyVector.size() - 1)
	{
		//AIClear = true;
		_enemyVector[AICount].normalState = true;
		_enemyVector[AICount].isAttackMotion = false;
		_enemyVector[AICount].isAttack = false;

		_doneCount++;
		if(AICount < _enemyVector.size() - 1)
			AICount++;
	}

}



void map1_1::AIAstar()
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
			if (_tiles[y * TILEX + x].block && y*+TILEX + x != endTile) tempBlock[i] = true;
			else {
				// check closeList z
				bool isClose = false;
				for (int j = 0; j < AIaStarCloseList.size(); j++)
				{
					if (AIaStarCloseList[j] == y * TILEX + x)
					{
						isClose = true;
						break;
					}
				}
				if (isClose) continue;

				if (i < 4)
				{
					_tiles[y * TILEX + x].g = 10;
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
					_tiles[y * TILEX + x].g = 14;

				}
				//abs절대값

				_tiles[y * TILEX + x].h = (abs(endX - x) + abs(endY - y)) * 10;
				_tiles[y * TILEX + x].f = _tiles[y * TILEX + x].g + _tiles[y * TILEX + x].h;

				// 오픈리스트에 있으면 g 비용 비교 후 처리
				isOpen = false;
				for (int i = 0; i < AIaStarOpenList.size(); i++)
				{
					if (AIaStarOpenList[i] == y * TILEX + x)
					{
						isOpen = true;
						if (_tiles[AIaStarOpenList[i]].g > _tiles[y * TILEX + x].g)
						{
							_tiles[AIaStarOpenList[i]].h = _tiles[y * TILEX + x].h;
							_tiles[AIaStarOpenList[i]].g = _tiles[y * TILEX + x].g;
							_tiles[AIaStarOpenList[i]].f = _tiles[y * TILEX + x].f;
							_tiles[AIaStarOpenList[i]].node = currentTile;
						}
					}
				}
				// 없으면 그냥 넣고 부모 설정
				if (!isOpen)
				{
					AIaStarOpenList.push_back(y * TILEX + x);
					_tiles[y * TILEX + x].node = currentTile;
				}

				// find
				if (y * TILEX + x == endTile)
					isFind = true;

			}
		}
	}

	// 선택 지점 열린목록에서 빼기
	for (iter = AIaStarOpenList.begin(); iter != AIaStarOpenList.end(); ++iter)
	{
		if ((*iter) == currentTile)
		{
			iter = AIaStarOpenList.erase(iter);
			break;
		}
	}

	// not Find
	if (AIaStarOpenList.size() == 0)
	{

		noPath = true;

	}

	// 현재 타일 클로즈리스트에 넣기
	AIaStarCloseList.push_back(currentTile);

	if (AIaStarOpenList.size() != 0)
	{
		// find minimum f cost in openList
		int min = _tiles[*AIaStarOpenList.begin()].h;
		currentTile = *AIaStarOpenList.begin();
		for (iter = AIaStarOpenList.begin(); iter != AIaStarOpenList.end(); ++iter)
		{
			if (min > _tiles[(*iter)].h)
			{
				min = _tiles[(*iter)].h;
				currentTile = *iter;
			}
		}
	}
	//}
	//gg += _tiles[closeList.back()].f;

	// 타일 렌더를 위해 상태 저장
	for (int i = 0; i < AIaStarOpenList.size(); i++)
	{
		_tiles[AIaStarOpenList[i]].showState = STATE_OPEN;
	}
	for (int i = 0; i < _AIcloseList.size(); i++)
	{
		_tiles[_AIcloseList[i]].showState = STATE_CLOSE;
	}
	// 길 찾기 성공시 각 타일에 길찾기 상태 저장
	int tempTile = endTile;
	//if(_turnFlag == 0)

	//if(!_tiles[endTile].teamBlock)
	AImoveStack.push(endTile);
	while (_tiles[tempTile].node != startTile
		&& isFind)
	{
		tempTile = _tiles[tempTile].node;
		AImoveStack.push(tempTile);
		_tiles[tempTile].showState = STATE_PATH;
	}
}

int map1_1::AIgetTile(int tile)
{
	//int currentTile = startTile;
	int endX = tile % TILEX;
	int endY = tile / TILEX;


	int currentX = AIcurrentTile % TILEX;
	int currentY = AIcurrentTile / TILEX;
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
			if (_tiles[y * TILEX + x].block && y*TILEX + x != tile) tempBlock[i] = true;
			else {
				// check closeList z
				bool isClose = false;
				for (int j = 0; j < _AIcloseList.size(); j++)
				{
					if (_AIcloseList[j] == y * TILEX + x)
					{
						isClose = true;
						break;
					}
				}
				if (isClose) continue;

				if (i < 4)
				{
					_tiles[y * TILEX + x].g = 10;
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
					_tiles[y * TILEX + x].g = 14;

				}
				//abs절대값

				_tiles[y * TILEX + x].h = (abs(endX - x) + abs(endY - y)) * 10;
				_tiles[y * TILEX + x].f = _tiles[y * TILEX + x].g + _tiles[y * TILEX + x].h;

				// 오픈리스트에 있으면 g 비용 비교 후 처리
				isOpen = false;
				for (int i = 0; i < _AIopenList.size(); i++)
				{
					if (_AIopenList[i] == y * TILEX + x)
					{
						isOpen = true;
						if (_tiles[_AIopenList[i]].g > _tiles[y * TILEX + x].g)
						{
							_tiles[_AIopenList[i]].h = _tiles[y * TILEX + x].h;
							_tiles[_AIopenList[i]].g = _tiles[y * TILEX + x].g;
							_tiles[_AIopenList[i]].f = _tiles[y * TILEX + x].f;
							_tiles[_AIopenList[i]].node = AIcurrentTile;
						}
					}
				}
				// 없으면 그냥 넣고 부모 설정
				if (!isOpen)
				{
					_AIopenList.push_back(y * TILEX + x);
					_tiles[y * TILEX + x].node = AIcurrentTile;
				}

				// find
				if (y * TILEX + x == tile)
					AIisFind = true;

			}
		}
	}

	// 선택 지점 열린목록에서 빼기
	for (iter = _AIopenList.begin(); iter != _AIopenList.end(); ++iter)
	{
		if ((*iter) == AIcurrentTile)
		{
			iter = _AIopenList.erase(iter);
			break;
		}
	}

	// not Find
	if (_AIopenList.size() == 0)
	{

		AInoPath = true;

	}

	// 현재 타일 클로즈리스트에 넣기
	_AIcloseList.push_back(AIcurrentTile);

	if (_AIopenList.size() != 0)
	{
		// find minimum f cost in openList
		int min = _tiles[*_AIopenList.begin()].h;
		AIcurrentTile = *_AIopenList.begin();
		for (iter = _AIopenList.begin(); iter != _AIopenList.end(); ++iter)
		{
			if (min > _tiles[(*iter)].h)
			{
				min = _tiles[(*iter)].h;
				AIcurrentTile = *iter;
			}
		}
	}
	//}
	gg += _tiles[_AIcloseList.back()].f;



	return gg;
}

void map1_1::AIfloodFill(int tile, int moveCount)
{

	int count;

	if (tile >= 0 && tile <= 400)
	{
		if (_tiles[tile].terrain == TR_CASTLELAND)
		{
			count = moveCount - 2;
		}
		else
		{
			count = moveCount - 1;
		}
		if (moveCount > 0 && !_tiles[tile].block)
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
			_tiles[tile].floodFill = true;
		}
	}
}
void map1_1::tempFunction()
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

void map1_1::pheonixSkill()
{
	pheonixCount++;
	if (pheonixCount % 5 == 0)
	{
		pheonixSkillCurrentFrameY++;
		if (pheonixSkillCurrentFrameY > 29)
		{
			pheonixCount = 0;
			pheonixSkillCurrentFrameY = 0;
			isPheonixSkill = false;
			_myArmyVector[_selectNum].currentMp -= 6;
			fireEffectOn = true;
			_enemyVector[skillHitNum]._beHitMotion = true;

			showSkillDmg = true;
		}
	}
}

void map1_1::fireEffect()
{
	fireEffectCount++;
	if (fireEffectCount % 5 == 0)
	{
		fireEffectCurrentFrameY++;
		if (fireEffectCurrentFrameY > 10)
		{
			fireEffectCount = 0;
			fireEffectCurrentFrameY = 0;
			fireEffectOn = false;
			_enemyVector[skillHitNum]._beHitMotion = false;
			_enemyVector[skillHitNum].currentDmg = 100;
			_enemyVector[skillHitNum].currentHp -= 100;
			_myArmyVector[_selectNum].isDone = true;

			showSkillDmg = false;
			_myArmyVector[_selectNum].isMagicMotion = false;
			_doneCount++;
		}
	}
}


