#include "stdafx.h"
#include "enemyClass.h"
#pragma warning(disable:4996)

enemyClass::enemyClass()
{
}

enemyClass::~enemyClass()
{
}

HRESULT enemyClass::init()
{
	IMAGEMANAGER->addImage("enemyMoveRange", "images/�̵���������_��.bmp", 48, 48, true, RGB(247, 0, 255));
	gameSystemMap = new gameSystem();
	gameSystemMap->init();

	tempFunction();
	load();

	startTile = -1;
	endTile = -1;

	_doneCount = 0;
	_ggCount = 0;
	minTileF = 100000;
	mostDmg = 0;
	AICount = 0;
	for (int j = 0; j < TILEX*TILEY; j++)
	{
		for (int i = 0; i < _enemyVector.size(); i++)
		{
			RECT temp;
			if (IntersectRect(&temp, &gameSystemMap->getMap()[j].rc, &_enemyVector[i].rc))
			{
				_enemyVector[i].tile = j;
			}
		}
	}
	for (int i = 0; i < _enemyVector.size(); i++)
	{
		_enemyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
	}

	for (int i = 0; i < _enemyVector.size(); i++)
	{
		_hpBar = new  progressBar;
		_hpBar->init("images/��ũ/ü�¹�.bmp", "images/��ũ/backgroundBar.bmp", 0, 0, 120, 10);
		_hpBar->setGauge(_enemyVector[i].currentHp, _enemyVector[i].maxHp);
		_hpBarEnemyVector.push_back(_hpBar);

		_mpBar = new  progressBar;
		_mpBar->init("images/��ũ/mp��.bmp", "images/��ũ/backgroundBar.bmp", 0, 0, 120, 10);
		_mpBar->setGauge(_enemyVector[i].currentMp, _enemyVector[i].maxMp);
		_mpBarEnemyVector.push_back(_mpBar);
	}




	return S_OK;
}

void enemyClass::release()
{
	SAFE_DELETE(gameSystemMap);

	for (int i = 0; i < _hpBarEnemyVector.size(); i++)
	{
		SAFE_DELETE(_hpBar);
		SAFE_DELETE(_mpBar);
	}

	_mpBarEnemyVector.clear();
	_hpBarEnemyVector.clear();
}

void enemyClass::update()
{

	_isShowState = false;
	for (int i = 0; i < _enemyVector.size(); i++)
	{
		if (PtInRect(&_enemyVector[i].rc, m_ptMouse))
		{
			_isShowState = true;
		}
	}

	animation();

	if (_enemyVector[_hitNum]._beHitMotion)
	{
		_attackCount++;
	}
	else if (!_enemyVector[_hitNum]._beHitMotion)
	{
		_attackCount = 0;
	}

	if (_enemyVector[_hitNum]._beHit)
	{
		_attackCount++;
		if (_attackCount <= 2)
		{
			_enemyVector[_hitNum].currentHp -= _enemyVector[_hitNum].currentDmg;
			_enemyVector[_hitNum]._beHit = false;
		}
	}

	//if(_isStart)
	//AI(); //�̺κп��� ���Ͱ� ������. ��ġ��

	//AISearchEntile();
	//AI();

	//if(startTile != -1 && endTile !=-1)
	//AIAstarStartFunction();



	//if (_enemyVector[AICount].isDone)
	//{
	//	_enemyVector[AICount].normalState = true;
	//	//_enemyVector[AICount].isAttackMotion = false;
	//	//_enemyVector[AICount].isAttack = false;
	//	number = 0;
	//	_isDoneCheck = false;
	//	AIClearFunction();
	//	_doneCount++;
	//	if (AICount < _enemyVector.size() - 1)
	//	{
	//		AICount++;
	//	}
	//}

	for (int i = 0; i < _hpBarEnemyVector.size(); i++)
	{
		_hpBarEnemyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 55);
		_hpBarEnemyVector[i]->setY(405);
		_hpBarEnemyVector[i]->setGauge(_enemyVector[i].currentHp, _enemyVector[i].maxHp);
		_hpBarEnemyVector[i]->update();
		_mpBarEnemyVector[i]->setX(WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 55);
		_mpBarEnemyVector[i]->setY(435);
		_mpBarEnemyVector[i]->setGauge(_enemyVector[i].currentMp, _enemyVector[i].maxMp);
		_mpBarEnemyVector[i]->update();
	}
}

void enemyClass::render()
{

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (gameSystemMap->getMap()[i].floodFill)
		{
			IMAGEMANAGER->render("enemyMoveRange", getMemDC(), i% TILEX*TILESIZE, i / TILEX * TILESIZE);

		}
	}

	for (int i = 0; i < _enemyVector.size(); i++)
	{
		if (_enemyVector[i].isDone)
		{
			_enemyVector[i].characterMoveImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].currentFrameX, _enemyVector[i].currentFrameY);
			_enemyVector[i].characterDoneImage->alphaFrameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].doneFrameX, _enemyVector[i].doneFrameY, 100);
		}
		else if (!_enemyVector[i].isDone && !_enemyVector[i].isAttackMotion && !_enemyVector[i]._beHitMotion)
			_enemyVector[i].characterMoveImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].currentFrameX, _enemyVector[i].currentFrameY);

		if (_enemyVector[i].isAttackMotion)
		{
			_enemyVector[i].characterAttackImage->frameRender(getMemDC(), _enemyVector[i].rc.left - 8, _enemyVector[i].rc.top - 8, _enemyVector[i].attackFrameX, _enemyVector[i].attackFrameY);
		}

		if (!_enemyVector[i]._beHitMotion && !_enemyVector[i].isAttackMotion)
			_enemyVector[i].characterMoveImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, _enemyVector[i].currentFrameX, _enemyVector[i].currentFrameY);
		else if (_enemyVector[i]._beHitMotion)
			_enemyVector[i].characterDefImage->frameRender(getMemDC(), _enemyVector[i].rc.left, _enemyVector[i].rc.top, 0, 4);

		if (_isShowState)
		{
			if (PtInRect(&_enemyVector[i].rc, m_ptMouse))
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
				//_enemyVector[j].characterFaceImage->render(getMemDC(), 973, 350);

				_enemyVector[i].characterFaceImage->render(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 9, 309);


				//wsprintf(str2, "%s", _enemyVector[j].name);
				//TextOut(getMemDC(), 1043, 350, str2, strlen(str2));



				_hpBarEnemyVector[i]->render();
				_mpBarEnemyVector[i]->render();

				//_hpBar->render();
				//_mpBar->render();
				wsprintf(levelStr, "Lv %d", _enemyVector[i].level);
				wsprintf(nameStr, "%s", _enemyVector[i].name);



				wsprintf(hpStr, "%d / %d", _enemyVector[i].currentHp, _enemyVector[i].maxHp);
				wsprintf(mpStr, "%d / %d", _enemyVector[i].currentMp, _enemyVector[i].maxMp);
				wsprintf(strStr, "���� : %d", _enemyVector[i].str);
				wsprintf(dexStr, "��ø : %d", _enemyVector[i].dex);
				wsprintf(intelligenceStr, "���� : %d", _enemyVector[i].intelligence);
				wsprintf(luckStr, "�� : %d", _enemyVector[i].luck);
				wsprintf(cmdStr, "��� : %d", _enemyVector[i].cmd);
				wsprintf(atkStr, "���ݷ� : %d", _enemyVector[i].atk);
				wsprintf(mAtkStr, "���ŷ� : %d", _enemyVector[i].mAtk);
				wsprintf(defStr, "���� : %d", _enemyVector[i].def);

				wsprintf(spdStr, "���߷� : %d", _enemyVector[i].spd);
				wsprintf(moveStr, "�̵��� : %d", _enemyVector[i].move);
				//wsprintf(expStr, "%d", _enemyVector[i].exp);
				HFONT myFont = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "�ü�");
				HFONT oldFont = (HFONT)SelectObject(getMemDC(), myFont);
				SetTextColor(getMemDC(), RGB(60, 80, 255));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 85, 309, nameStr, strlen(nameStr));
				SelectObject(getMemDC(), oldFont);
				DeleteObject(myFont);

				HFONT myFont1 = CreateFont(15, 0, 0, 0, 600, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "�ü�");
				HFONT oldFont1 = (HFONT)SelectObject(getMemDC(), myFont1);
				SetTextColor(getMemDC(), RGB(255, 255, 255));

				TextOut(getMemDC(), WINSIZEX - 60, 309, levelStr, strlen(levelStr));


				SelectObject(getMemDC(), oldFont1);
				DeleteObject(myFont1);



				HFONT myFont2 = CreateFont(15, 0, 0, 0, 700, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "�ü�");
				HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), myFont2);
				SetTextColor(getMemDC(), RGB(190, 170, 200));

				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 90, 403, hpStr, strlen(hpStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 90, 433, mpStr, strlen(mpStr));

				SelectObject(getMemDC(), oldFont2);
				DeleteObject(myFont2);

				HFONT myFont3 = CreateFont(10, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "�ü�");
				HFONT oldFont3 = (HFONT)SelectObject(getMemDC(), myFont3);
				SetTextColor(getMemDC(), RGB(255, 255, 255));

				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 85, 330, strStr, strlen(strStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 85, 345, dexStr, strlen(dexStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 85, 360, intelligenceStr, strlen(intelligenceStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 85, 375, luckStr, strlen(luckStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 85, 390, cmdStr, strlen(cmdStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 125, 330, atkStr, strlen(atkStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 125, 345, mAtkStr, strlen(mAtkStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 125, 360, defStr, strlen(defStr));

				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 125, 375, spdStr, strlen(spdStr));
				TextOut(getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("��������â")->getWidth() + 125, 390, moveStr, strlen(moveStr));
				SelectObject(getMemDC(), oldFont3);
				DeleteObject(myFont3);


				//TextOut(getMemDC(), 1100, 400, expStr, strlen(hpStr));

			}
		}


	}


}

void enemyClass::load()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (gameSystemMap->getMap()[i].dis == DISTIN_NONE)continue;
		char fileName[128];
		strcpy(fileName, gameSystemMap->getMap()[i].tileCharacter.name);
		strcat(fileName, ".dat");
		file = CreateFile
		(fileName,				//������ ���϶Ǵ� �� ��ġ�� �����̸�
			GENERIC_READ,			//�����̳� ��ġ�� ����ų� ���� ����� ����
			0,						//���� ���� ����Է�
			NULL,					//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
			OPEN_EXISTING,			//�����̳� ��ġ�� ���� ���� �ൿ
			FILE_ATTRIBUTE_NORMAL,	//�����̳� ��ġ�� ���� ���� �� Ư��
			NULL);					//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����
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
		if (gameSystemMap->getMap()[i].dis == DISTIN_ENEMY)
			_enemyVector.push_back(_character);
		CloseHandle(file);

	}
}

void enemyClass::tempFunction()
{

	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face0", "images/ĳ���� ��/0.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face1", "images/ĳ���� ��/1.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face2", "images/ĳ���� ��/2.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face3", "images/ĳ���� ��/3.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face4", "images/ĳ���� ��/4.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face5", "images/ĳ���� ��/5.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face6", "images/ĳ���� ��/6.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face7", "images/ĳ���� ��/7.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face8", "images/ĳ���� ��/8.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face9", "images/ĳ���� ��/9.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face10", "images/ĳ���� ��/10.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face11", "images/ĳ���� ��/11.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face12", "images/ĳ���� ��/12.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face13", "images/ĳ���� ��/13.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face14", "images/ĳ���� ��/14.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face15", "images/ĳ���� ��/15.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face16", "images/ĳ���� ��/16.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face17", "images/ĳ���� ��/17.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face18", "images/ĳ���� ��/18.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face19", "images/ĳ���� ��/19.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face20", "images/ĳ���� ��/20.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face21", "images/ĳ���� ��/21.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face22", "images/ĳ���� ��/22.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face23", "images/ĳ���� ��/23.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face24", "images/ĳ���� ��/24.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face25", "images/ĳ���� ��/25.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face26", "images/ĳ���� ��/26.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face27", "images/ĳ���� ��/27.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face28", "images/ĳ���� ��/28.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face29", "images/ĳ���� ��/29.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face30", "images/ĳ���� ��/30.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face31", "images/ĳ���� ��/31.bmp", 64, 80, true, RGB(255, 0, 255)));

	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit0", "images/����/0.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit1", "images/����/1.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit2", "images/����/2.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit3", "images/����/3.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit4", "images/����/4.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit5", "images/����/5.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit6", "images/����/6.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit7", "images/����/7.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit8", "images/����/8.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit9", "images/����/9.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit10", "images/����/10.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit11", "images/����/11.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit12", "images/����/12.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit13", "images/����/13.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit14", "images/����/14.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit15", "images/����/15.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit16", "images/����/16.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit17", "images/����/17.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit18", "images/����/18.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit19", "images/����/19.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit20", "images/����/20.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit21", "images/����/21.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit22", "images/����/22.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit23", "images/����/23.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit24", "images/����/24.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit25", "images/����/25.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit26", "images/����/26.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit27", "images/����/27.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));

	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack0", "images/����/���ݸ��/0.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack1", "images/����/���ݸ��/1.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack2", "images/����/���ݸ��/2.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack3", "images/����/���ݸ��/3.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack4", "images/����/���ݸ��/4.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack5", "images/����/���ݸ��/5.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack6", "images/����/���ݸ��/6.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack7", "images/����/���ݸ��/7.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack8", "images/����/���ݸ��/8.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack9", "images/����/���ݸ��/9.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack10", "images/����/���ݸ��/10.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack11", "images/����/���ݸ��/11.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack12", "images/����/���ݸ��/12.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack13", "images/����/���ݸ��/13.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack14", "images/����/���ݸ��/14.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack15", "images/����/���ݸ��/15.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack16", "images/����/���ݸ��/16.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack17", "images/����/���ݸ��/17.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack18", "images/����/���ݸ��/18.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack19", "images/����/���ݸ��/19.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack20", "images/����/���ݸ��/20.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack21", "images/����/���ݸ��/21.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack22", "images/����/���ݸ��/22.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack23", "images/����/���ݸ��/23.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack24", "images/����/���ݸ��/24.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack25", "images/����/���ݸ��/25.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack26", "images/����/���ݸ��/26.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack27", "images/����/���ݸ��/27.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));

	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def0", "images/����/������/0.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def1", "images/����/������/1.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def2", "images/����/������/2.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def3", "images/����/������/3.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def4", "images/����/������/4.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def5", "images/����/������/5.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def6", "images/����/������/6.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def7", "images/����/������/7.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def8", "images/����/������/8.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def9", "images/����/������/9.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def10", "images/����/������/10.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def11", "images/����/������/11.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def12", "images/����/������/12.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def13", "images/����/������/13.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def14", "images/����/������/14.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def15", "images/����/������/15.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def16", "images/����/������/16.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def17", "images/����/������/17.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def18", "images/����/������/18.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def19", "images/����/������/19.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def20", "images/����/������/20.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def21", "images/����/������/21.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def22", "images/����/������/22.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def23", "images/����/������/23.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def24", "images/����/������/24.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def25", "images/����/������/25.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def26", "images/����/������/26.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def27", "images/����/������/27.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));

	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done0", "images/����/������/0.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done1", "images/����/������/1.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done2", "images/����/������/2.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done3", "images/����/������/3.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done4", "images/����/������/4.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done5", "images/����/������/5.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done6", "images/����/������/6.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done7", "images/����/������/7.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done8", "images/����/������/8.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done9", "images/����/������/9.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done10", "images/����/������/10.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done11", "images/����/������/11.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done12", "images/����/������/12.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done13", "images/����/������/13.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done14", "images/����/������/14.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done15", "images/����/������/15.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done16", "images/����/������/16.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done17", "images/����/������/17.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done18", "images/����/������/18.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done19", "images/����/������/19.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done20", "images/����/������/20.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done21", "images/����/������/21.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done22", "images/����/������/22.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done23", "images/����/������/23.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done24", "images/����/������/24.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done25", "images/����/������/25.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done26", "images/����/������/26.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done27", "images/����/������/27.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));

}

void enemyClass::AI()
{
	if (!_enemyVector[AICount].isSelect)
	{
		_enemyVector[AICount].normalState = true;
		showRange = true;
		startTile = _enemyVector[AICount].tile;
		AIfloodFill(startTile, _enemyVector[AICount].move);
		_enemyVector[AICount].isSelect = true;
	}

	//if (startTile != -1)
	//{

	//	AIstartAstar = true;
	//	AIcurrentTile = startTile;
	//	_AIopenList.push_back(AIcurrentTile);
	//}

	for (int j = 0; j < TILEX*TILEY; j++)
	{
		for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
		{

			if (_enemyVector[AICount].rc.left == gameSystemMap->getMap()[j].rc.left
				&& _enemyVector[AICount].rc.top == gameSystemMap->getMap()[j].rc.top)
			{
				_enemyVector[AICount].tile = j;
				if (_enemyVector[AICount].attackArray[i] == 1)
				{
					if (j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) > 0 && j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) < 400)
						gameSystemMap->setAttackRange(true, j + (i - 24) + ((i / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)));
				}
			}
		}
	}

	//done�϶� AICount++ �ϱ�


}

void enemyClass::AIfloodFill(int tile, int moveCount)
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
		if (moveCount > 0 && !gameSystemMap->getMap()[tile].block)
		{

			AIfloodFill(tile - 20, count);
			AIfloodFill(tile + 20, count);
			if (tile % TILEX > 0 && tile % TILEX < 19)
			{

				AIfloodFill(tile - 1, count);
				AIfloodFill(tile + 1, count);
			}
			else if (startTile%TILEX == 19)
			{
				AIfloodFill(tile - 1, count);
			}
			else if (startTile%TILEX == 0)
			{
				AIfloodFill(tile + 1, count);
			}
			gameSystemMap->setFloodFill(true, tile);
		}
	}
}

void enemyClass::animation()
{
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

			//if (_enemyVector[AICount].currentFrameY < 0 || _enemyVector[AICount].currentFrameY > 3)
			//	_enemyVector[AICount].currentFrameY = 0;
			//_enemyVector[AICount].characterMoveImage->setFrameY(4);
			//if (_enemyVector[AICount].count % (25 % moveSpeedIndex) == 0)

			if (_enemyVector[AICount].attackCount <= 45)
			{
				_enemyVector[AICount].attackFrameY = 8;
			}
			if (_enemyVector[AICount].attackCount <= 48 && _enemyVector[AICount].attackCount > 45)
			{
				_enemyVector[AICount].attackFrameY = 9;
			}
			if (_enemyVector[AICount].attackCount <= 51 && _enemyVector[AICount].attackCount > 48)
			{
				_enemyVector[AICount].attackFrameY = 10;
				attackStart = true;
				//_enemyVector[_hitNum]._beHitMotion = true;
				//_enemyVector[_hitNum]._beHit = true;
			}
			if (_enemyVector[AICount].attackCount <= 65 && _enemyVector[AICount].attackCount > 51)
			{
				_enemyVector[AICount].attackFrameY = 11;

			}
			if (_enemyVector[AICount].attackCount > 83)
			{
				_enemyVector[AICount].isAttackMotion = false;
				_enemyVector[AICount].isDone = true;
				//attackFinish = true;
				//_enemyVector[_hitNum]._beHitMotion = false;
				_doneCount++;
			}



			//if (_enemyVector[AICount].attackCount <= 40)
			//{
			//	_enemyVector[AICount].attackFrameY = 8;
			//}

			//if (_enemyVector[AICount].attackCount > 40 && _enemyVector[AICount].attackCount % 5 == 0)
			//{
			//	_enemyVector[AICount].attackFrameY++;
			//	if (_enemyVector[AICount].attackFrameY == 10)
			//	{
			//		_myArmyVector[beHitNum]._beHitMotion = true;
			//		_myArmyVector[beHitNum]._beHit = true;

			//	}
			//	if (_enemyVector[AICount].attackFrameY > 11)
			//	{
			//		_enemyVector[AICount].attackFrameY = 11;
			//		if (_enemyVector[AICount].attackCount > 70)
			//		{
			//			_enemyVector[AICount].isAttackMotion = false;
			//			_myArmyVector[beHitNum]._beHitMotion = false;
			//			_enemyVector[AICount].isDone = true;

			//		}
			//	}
			//}


			break;
		case CHARACTER_DIRECTION_RIGHT:
			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 45)
			{
				_enemyVector[AICount].attackFrameY = 12;
			}
			if (_enemyVector[AICount].attackCount <= 48 && _enemyVector[AICount].attackCount > 45)
			{
				_enemyVector[AICount].attackFrameY = 13;
			}
			if (_enemyVector[AICount].attackCount <= 51 && _enemyVector[AICount].attackCount > 48)
			{
				_enemyVector[AICount].attackFrameY = 14;
				attackStart = true;
				//_enemyVector[_hitNum]._beHitMotion = true;
				//_enemyVector[_hitNum]._beHit = true;
			}
			if (_enemyVector[AICount].attackCount <= 65 && _enemyVector[AICount].attackCount > 51)
			{
				_enemyVector[AICount].attackFrameY = 15;

			}
			if (_enemyVector[AICount].attackCount > 83)
			{
				_enemyVector[AICount].isAttackMotion = false;
				_enemyVector[AICount].isDone = true;
				//attackFinish = true;
				//_enemyVector[_hitNum]._beHitMotion = false;
				_doneCount++;
			}

			break;
		case CHARACTER_DIRECTION_TOP:
			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 45)
			{
				_enemyVector[AICount].attackFrameY = 4;
			}
			if (_enemyVector[AICount].attackCount <= 48 && _enemyVector[AICount].attackCount > 45)
			{
				_enemyVector[AICount].attackFrameY = 5;
			}
			if (_enemyVector[AICount].attackCount <= 51 && _enemyVector[AICount].attackCount > 48)
			{
				_enemyVector[AICount].attackFrameY = 6;
				attackStart = true;
				//_enemyVector[_hitNum]._beHitMotion = true;
				//_enemyVector[_hitNum]._beHit = true;
			}
			if (_enemyVector[AICount].attackCount <= 65 && _enemyVector[AICount].attackCount > 51)
			{
				_enemyVector[AICount].attackFrameY = 7;

			}
			if (_enemyVector[AICount].attackCount > 83)
			{
				_enemyVector[AICount].isAttackMotion = false;
				_enemyVector[AICount].isDone = true;
				//attackFinish = true;
				//_enemyVector[_hitNum]._beHitMotion = false;
				_doneCount++;
			}

			break;
		case CHARACTER_DIRECTION_BOTTOM:
			_enemyVector[AICount].attackCount++;
			if (_enemyVector[AICount].attackCount <= 45)
			{
				_enemyVector[AICount].attackFrameY = 0;
			}
			if (_enemyVector[AICount].attackCount <= 48 && _enemyVector[AICount].attackCount > 45)
			{
				_enemyVector[AICount].attackFrameY = 1;
			}
			if (_enemyVector[AICount].attackCount <= 51 && _enemyVector[AICount].attackCount > 48)
			{
				_enemyVector[AICount].attackFrameY = 2;
				attackStart = true;
				//_enemyVector[_hitNum]._beHitMotion = true;
				//_enemyVector[_hitNum]._beHit = true;
			}
			if (_enemyVector[AICount].attackCount <= 65 && _enemyVector[AICount].attackCount > 51)
			{
				_enemyVector[AICount].attackFrameY = 3;

			}
			if (_enemyVector[AICount].attackCount > 83)
			{
				_enemyVector[AICount].isAttackMotion = false;
				_enemyVector[AICount].isDone = true;
				//attackFinish = true;
				//_enemyVector[_hitNum]._beHitMotion = false;
				_doneCount++;
			}

			break;
		default:
			break;
		}
	}
	if (!_enemyVector[AICount].isAttackMotion)
	{
		//beHitNum = 0;
		_enemyVector[AICount].attackCount = 0;
		//_myArmyVector[_selectNum].isDone = true;
	}



}

//int enemyClass::AIgetTile(int tile)
//{
//	//int currentTile = startTile;
//	int endX = tile % TILEX;
//	int endY = tile / TILEX;
//
//
//	int currentX = AIcurrentTile % TILEX;
//	int currentY = AIcurrentTile / TILEX;
//	// left, right, up, down, leftup, rightdown, leftdown, rightup
//	int dx[] = { -1, 1, 0, 0 };// , -1, 1, -1, 1 };
//	int dy[] = { 0, 0, -1, 1 };// , -1, 1, 1, -1 };
//	bool tempBlock[4];
//
//	// ���� ã�� �ݺ���
//	for (int i = 0; i < 4; i++)
//	{
//		int x = currentX + dx[i];
//		int y = currentY + dy[i];
//		tempBlock[i] = false;
//
//		// �ش� �������� ������ Ÿ���� ��ȿ�� Ÿ������ Ȯ��
//		if (0 <= x && x < TILEX && 0 <= y && y < TILEY)
//		{
//			bool isOpen;
//			// �밢�� Ÿ���� �̵� ������ (�ֺ��� ��������� ����) �ӽ÷� ��� ���� ����
//			if (gameSystemMap->getMap()[y * TILEX + x].block && y*TILEX + x != tile) tempBlock[i] = true;
//			else {
//				// check closeList z
//				bool isClose = false;
//				for (int j = 0; j < _AIcloseList.size(); j++)
//				{
//					if (_AIcloseList[j] == y * TILEX + x)
//					{
//						isClose = true;
//						break;
//					}
//				}
//				if (isClose) continue;
//
//				if (i < 4)
//				{
//					gameSystemMap->setG(10, y * TILEX + x);
//				}
//				else
//				{
//					// leftup�� ��� left�� up�� ��������� �ȵ�
//					if (i == DIRECTION_LEFTUP &&
//						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_UP]) continue;
//					// rightdown�� ��� right�� down�� ��������� �ȵ�
//					if (i == DIRECTION_RIGHTDOWN &&
//						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_DOWN]) continue;
//					// rightup�� ��� right�� up�� ��������� �ȵ�
//					if (i == DIRECTION_RIGHTUP &&
//						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_UP]) continue;
//					// leftdown�� ��� left�� down�� ��������� �ȵ�
//					if (i == DIRECTION_LEFTDOWN &&
//						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_DOWN]) continue;
//					gameSystemMap->setG(14, y * TILEX + x);
//
//				}
//				//abs���밪
//				gameSystemMap->setH((abs(endX - x) + abs(endY - y)) * 10, y * TILEX + x);
//				gameSystemMap->setF(gameSystemMap->getMap()[y * TILEX + x].g + gameSystemMap->getMap()[y * TILEX + x].h, y * TILEX + x);
//
//				// ���¸���Ʈ�� ������ g ��� �� �� ó��
//				isOpen = false;
//				for (int i = 0; i < _AIopenList.size(); i++)
//				{
//					if (_AIopenList[i] == y * TILEX + x)
//					{
//						isOpen = true;
//						if (gameSystemMap->getMap()[_AIopenList[i]].g > gameSystemMap->getMap()[y * TILEX + x].g)
//						{
//
//							gameSystemMap->getMap()[_AIopenList[i]].h = gameSystemMap->getMap()[y * TILEX + x].h;
//							gameSystemMap->getMap()[_AIopenList[i]].g = gameSystemMap->getMap()[y * TILEX + x].g;
//							gameSystemMap->getMap()[_AIopenList[i]].f = gameSystemMap->getMap()[y * TILEX + x].f;
//							gameSystemMap->setNode(AIcurrentTile, _AIopenList[i]);
//						}
//					}
//				}
//				// ������ �׳� �ְ� �θ� ����
//				if (!isOpen)
//				{
//					_AIopenList.push_back(y * TILEX + x);
//					gameSystemMap->setNode(AIcurrentTile, y * TILEX + x);
//				}
//
//				// find
//				if (y * TILEX + x == tile)
//					AIisFind = true;
//
//			}
//		}
//	}
//
//	// ���� ���� ������Ͽ��� ����
//	for (iter = _AIopenList.begin(); iter != _AIopenList.end(); ++iter)
//	{
//		if ((*iter) == AIcurrentTile)
//		{
//			iter = _AIopenList.erase(iter);
//			break;
//		}
//	}
//
//	// not Find
//	if (_AIopenList.size() == 0)
//	{
//
//		AInoPath = true;
//
//	}
//
//	// ���� Ÿ�� Ŭ�����Ʈ�� �ֱ�
//	_AIcloseList.push_back(AIcurrentTile);
//
//	if (_AIopenList.size() != 0)
//	{
//		int min = gameSystemMap->getMap()[*_AIopenList.begin()].h;
//		AIcurrentTile = *_AIopenList.begin();
//		for (iter = _AIopenList.begin(); iter != _AIopenList.end(); ++iter)
//		{
//			if (min > gameSystemMap->getMap()[(*iter)].h)
//			{
//				min = gameSystemMap->getMap()[(*iter)].h;
//				AIcurrentTile = *iter;
//			}
//		}
//	}
//	gg += gameSystemMap->getMap()[_AIcloseList.back()].f;
//
//
//
//
//	return gg;
//}

void enemyClass::AIAstar(int endTile)
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

	// ���� ã�� �ݺ���
	for (int i = 0; i < 4; i++)
	{
		int x = currentX + dx[i];
		int y = currentY + dy[i];
		tempBlock[i] = false;

		// �ش� �������� ������ Ÿ���� ��ȿ�� Ÿ������ Ȯ��
		if (0 <= x && x < TILEX && 0 <= y && y < TILEY)
		{
			bool isOpen;
			// �밢�� Ÿ���� �̵� ������ (�ֺ��� ��������� ����) �ӽ÷� ��� ���� ����
			if (gameSystemMap->getMap()[y * TILEX + x].block && y*+TILEX + x != endTile) tempBlock[i] = true;
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
					gameSystemMap->setG(10, y * TILEX + x);
				}
				else
				{
					// leftup�� ��� left�� up�� ��������� �ȵ�
					if (i == DIRECTION_LEFTUP &&
						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_UP]) continue;
					// rightdown�� ��� right�� down�� ��������� �ȵ�
					if (i == DIRECTION_RIGHTDOWN &&
						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_DOWN]) continue;
					// rightup�� ��� right�� up�� ��������� �ȵ�
					if (i == DIRECTION_RIGHTUP &&
						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_UP]) continue;
					// leftdown�� ��� left�� down�� ��������� �ȵ�
					if (i == DIRECTION_LEFTDOWN &&
						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_DOWN]) continue;
					gameSystemMap->setG(14, y * TILEX + x);

				}
				//abs���밪

				gameSystemMap->setH((abs(endX - x) + abs(endY - y)) * 10, y * TILEX + x);
				gameSystemMap->setF(gameSystemMap->getMap()[y * TILEX + x].g + gameSystemMap->getMap()[y * TILEX + x].h, y * TILEX + x);

				// ���¸���Ʈ�� ������ g ��� �� �� ó��
				isOpen = false;
				for (int i = 0; i < AIaStarOpenList.size(); i++)
				{
					if (AIaStarOpenList[i] == y * TILEX + x)
					{
						isOpen = true;
						if (gameSystemMap->getMap()[AIaStarOpenList[i]].g > gameSystemMap->getMap()[y * TILEX + x].g)
						{
							gameSystemMap->getMap()[AIaStarOpenList[i]].h = gameSystemMap->getMap()[y * TILEX + x].h;
							gameSystemMap->getMap()[AIaStarOpenList[i]].g = gameSystemMap->getMap()[y * TILEX + x].g;
							gameSystemMap->getMap()[AIaStarOpenList[i]].f = gameSystemMap->getMap()[y * TILEX + x].f;
							gameSystemMap->setNode(currentTile, AIaStarOpenList[i]);
						}
					}
				}
				// ������ �׳� �ְ� �θ� ����
				if (!isOpen)
				{
					AIaStarOpenList.push_back(y * TILEX + x);
					gameSystemMap->setNode(currentTile, y * TILEX + x);
				}

				// find
				if (y * TILEX + x == endTile)
					isFind = true;

			}
		}
	}

	// ���� ���� ������Ͽ��� ����
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

	// ���� Ÿ�� Ŭ�����Ʈ�� �ֱ�
	AIaStarCloseList.push_back(currentTile);

	if (AIaStarOpenList.size() != 0)
	{
		// find minimum f cost in openList
		int min = gameSystemMap->getMap()[*openList.begin()].h;
		currentTile = *AIaStarOpenList.begin();
		for (iter = AIaStarOpenList.begin(); iter != AIaStarOpenList.end(); ++iter)
		{
			if (min > gameSystemMap->getMap()[(*iter)].h)
			{
				min = gameSystemMap->getMap()[(*iter)].h;
				currentTile = *iter;
			}
		}
	}
	//}
	//gg += _tiles[closeList.back()].f;

	// Ÿ�� ������ ���� ���� ����
	for (int i = 0; i < AIaStarOpenList.size(); i++)
	{
		gameSystemMap->setShowState(STATE_OPEN, AIaStarOpenList[i]);
	}
	for (int i = 0; i < _AIcloseList.size(); i++)
	{
		gameSystemMap->setShowState(STATE_CLOSE, _AIcloseList[i]);
	}
	// �� ã�� ������ �� Ÿ�Ͽ� ��ã�� ���� ����
	int tempTile = endTile;
	//if(_turnFlag == 0)

	//if(!_tiles[endTile].teamBlock)
	AImoveStack.push(endTile);
	while (gameSystemMap->getMap()[tempTile].node != startTile
		&& isFind)
	{
		tempTile = gameSystemMap->getMap()[tempTile].node;
		AImoveStack.push(tempTile);
		gameSystemMap->setShowState(STATE_PATH, tempTile);
	}
}

void enemyClass::enemyVectorMove()
{
	if (isFind && aiVectorCount < AIendTileVector.size())// && attackStart)// && !_enemyVector[AICount].isAttack)// && _canMove)//(AIMoveStart) 
	{
		for (int i = 0; i < TILEX*TILEY; i++)
		{
			gameSystemMap->setAttackRange(false, i);
		}
		//stackTop = moveStack.size();
		//showRange = false;
		moveSpeedIndex = _enemyVector[AICount].move;
		if (moveSpeedIndex > 6)
		{
			moveSpeedIndex = 6;
		}

		if (_enemyVector[AICount].rc.left > gameSystemMap->getMap()[AIendTileVector[aiVectorCount]].rc.left)
		{
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_LEFT;
			_enemyVector[AICount].rc.left -= moveSpeed[moveSpeedIndex];
			_enemyVector[AICount].rc.right -= moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[AICount].rc.left < gameSystemMap->getMap()[AIendTileVector[aiVectorCount]].rc.left)
		{
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_RIGHT;
			_enemyVector[AICount].rc.left += moveSpeed[moveSpeedIndex];
			_enemyVector[AICount].rc.right += moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[AICount].rc.top < gameSystemMap->getMap()[AIendTileVector[aiVectorCount]].rc.top)
		{
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_BOTTOM;
			_enemyVector[AICount].rc.top += moveSpeed[moveSpeedIndex];
			_enemyVector[AICount].rc.bottom += moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[AICount].rc.top > gameSystemMap->getMap()[AIendTileVector[aiVectorCount]].rc.top)
		{
			_enemyVector[AICount].direction = CHARACTER_DIRECTION_TOP;
			_enemyVector[AICount].rc.top -= moveSpeed[moveSpeedIndex];
			_enemyVector[AICount].rc.bottom -= moveSpeed[moveSpeedIndex];
		}
		if (_enemyVector[AICount].rc.left == gameSystemMap->getMap()[AIendTileVector[aiVectorCount]].rc.left  &&
			_enemyVector[AICount].rc.top == gameSystemMap->getMap()[AIendTileVector[aiVectorCount]].rc.top)
		{
			aiVectorCount++;

			for (int j = 0; j < ATTACKTILEX*ATTACKTILEY; j++)
			{
				if (_enemyVector[AICount].attackArray[j] == 1)
				{
					if (_enemyVector[AICount].tile + (j - 24) + ((j / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) > 0 && _enemyVector[AICount].tile + (j - 24) + ((j / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)) < 400)
						gameSystemMap->setAttackRange(true, _enemyVector[AICount].tile + (j - 24) + ((j / ATTACKTILEX - 3)*(TILEX - ATTACKTILEX)));
				}
			}

			if (aiVectorCount >= AIendTileVector.size())
			{
				_isDoneCheck = true;
				number = AICount;
				if (!_enemyVector[AICount].isAttack)
					_enemyVector[AICount].isDone = true;
				//for (int j = 0; j < _myArmyVector.size(); j++)
				//{
				//	if (!_tiles[_myArmyVector[j].tile].attackRange)
				//		_enemyVector[AICount].isDone = true;
				//}
			}

		}
	}



	if (_enemyVector[AICount].isDone)
	{
		AIClear = true;
	}
}

//void enemyClass::enemyVectorMove(int i)
//{
//
//	
//}

int enemyClass::AISearchEntile()
{
	//���⸦ ������.
	if (_doAIgetTile)
	{
		while (!AIisFind && !AInoPath &&AIstartAstar)
		{
			//AIgetTile(AITile);
		}
		//_fNumVector.push_back(gg);
		_tileVector.push_back(AITile);

		//if (AIisFind && !_tileVector.empty())
		//{
		//	if (minTileF > gg) 
		//	{
		//		minTileF = gg;
		//		minTileNumber = _ggCount;
		//	}
		//	AIisFind = false;
		//	AInoPath = false;
		//	_AIopenList.clear();
		//	_AIcloseList.clear();
		//	gg = 0;
		//	_ggCount++;
		//}
		if (_AIminClear)
		{
			if (minTileF > gg)
			{
				minTileF = gg;
				minTileNumber = _ggCount;
			}
			gg = 0;
			AIisFind = false;
			AInoPath = false;
			_AIopenList.clear();
			_AIcloseList.clear();
			_AIminClear = false;
			_ggCount++;
		}
	}
	else if (!_doAIgetTile)
	{
		endTile = _tileVector[minTileNumber];
		_AIopenList.clear();
		_AIcloseList.clear();
		_AIminClear = false;
		_ggCount = 0;
		minTileF = 100000;

	}
	return endTile;

	//if (_enemyVector[AICount].isAttack)
	//{
	//	_enemyVector[AICount].normalState = false;
	//	_enemyVector[AICount].isAttack = false;
	//	_enemyVector[AICount].isAttackMotion = true;
	//	for (int i = 0; i < TILEX*TILEY; i++)
	//	{
	//		_tiles[i].attackRange = false;
	//	}

	//	if ((_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) < 0)
	//		_enemyVector[AICount].direction = CHARACTER_DIRECTION_RIGHT;
	//	else if ((_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) > 0)
	//		_enemyVector[AICount].direction = CHARACTER_DIRECTION_LEFT;
	//	else if (_enemyVector[AICount].tile - beHitTileNum < 0 && (_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) == 0)
	//		//if ((i % (TILEX+1)) - (_myArmyVector[_selectNum].tile % (TILEX +1)) == 0 && ((i/TILEX)- (_myArmyVector[_selectNum].tile / TILEX)) <0)
	//		_enemyVector[AICount].direction = CHARACTER_DIRECTION_BOTTOM;
	//	else if (_enemyVector[AICount].tile - beHitTileNum > 0 && (_enemyVector[AICount].tile%TILEX) - (beHitTileNum%TILEX) == 0)
	//		//if ((i % (TILEX + 1)) - (_myArmyVector[_selectNum].tile % (TILEX + 1)) == 0 && ((i / TILEX) - (_myArmyVector[_selectNum].tile / TILEX)) > 0)
	//		_enemyVector[AICount].direction = CHARACTER_DIRECTION_TOP;
	//}

}

void enemyClass::AIAstarStartFunction(int endTile)//int starTile)//, int endTile)
{
	//AIendTile2 = endTile;
	//endTile = this->getEndTile();
	if (startTile != -1 && endTile != -1)
	{
		startAstar = true;
		currentTile = startTile;
		openList.push_back(currentTile);
	}

	while (!isFind && !noPath &&startAstar && !AIClear)//&& !_enemyVector[AICount].isAttack)
	{
		AIAstar(endTile);
		//showRange = false;
		//for (int i = 0; i < TILEX*TILEY; i++)
		//	_tiles[i].attackRange = false;

	}

	for (int i = 0; i < AImoveStack.size(); i++)
	{
		if (gameSystemMap->getMap()[AImoveStack.top()].floodFill)
		{
			AIendTileVector.push_back(AImoveStack.top());
			AImoveStack.pop();
		}
	}

	for (int i = 0; i < _enemyVector.size(); i++)
	{
		//if (AIendTileVector[AIendTileVector.size()] == _enemyVector[i].tile&& 
		//	AIendTileVector[AIendTileVector.size()]!= _enemyVector[AICount].tile)
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
	enemyVectorMove();

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
		AIendTile2 = -1;
		endTile = -1;
		//_canMove = false;
		//AIFloodFillCheck = false;
		AIClear = false;
		//AInoPath = false;
		//AIisFind = false;
		//isAttach = false;

		//ggCount = 0;
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
		//_tileVector.clear();
		//_AIopenList.clear();
		//_AIcloseList.clear();
		//_moveComplete = false;
		//if(!_enemyVector[AICount].isAttack)
			//_enemyVector[AICount].isDone = true;

		for (int i = 0; i < TILEX*TILEY; i++)
		{
			gameSystemMap->setFloodFill(false, i);
		}

	}


	//if (startTile != -1 && endTile != -1)
	//{
	//	startAstar = true;
	//	currentTile = startTile;
	//	//���������� ���¸���Ʈ�� ����
	//	openList.push_back(currentTile);
	//}

	//while (!isFind && !noPath &&startAstar && !AIClear)
	//{
	//	AIAstar();

	//}

	//for (int i = 0; i < AImoveStack.size(); i++)
	//{
	//	if (gameSystemMap->getMap()[AImoveStack.top()].floodFill)
	//	{
	//		AIendTileVector.push_back(AImoveStack.top());
	//		AImoveStack.pop();
	//	}
	//}

	//for (int i = 0; i < _enemyVector.size(); i++)
	//{
	//	//if (AIendTileVector[AIendTileVector.size()] == _enemyVector[i].tile&& 
	//	//	AIendTileVector[AIendTileVector.size()]!= _enemyVector[AICount].tile)
	//	if (!AIendTileVector.empty())
	//	{
	//		if (AIendTileVector.back() == _enemyVector[AICount].tile)continue;
	//		if (AIendTileVector.back() == _enemyVector[i].tile)
	//		{
	//			AIendTileVector.pop_back();
	//			if (AIendTileVector.empty())
	//			{
	//				_enemyVector[AICount].isDone = true;
	//			}

	//		}
	//	}
	//}
	////if(!_enemyVector[AICount].isDone&& !AIendTileVector.empty())
	//	enemyVectorMove();

	//if (AIClear)
	//{
	//	showRange = true;
	//	startAstar = false;
	//	openList.clear();
	//	closeList.clear();
	//	AIaStarOpenList.clear();
	//	AIaStarCloseList.clear();
	//	isFind = false;
	//	noPath = false;
	//	startTile = -1;
	//	endTile = -1;
	//	//_canMove = false;
	//	AIClear = false;
	//	//isAttach = false;

	//	_ggCount = 0;
	//	minTileF = 100000;
	//	minTileNumber = 0;
	//	aiVectorCount = 0;
	//	while (!AImoveStack.empty())
	//	{
	//		AImoveStack.pop();
	//	}
	//	AIendTileVector.clear();

	//	mostDmg = 0;

	//	_tileVector.clear();

	//	for (int i = 0; i < TILEX*TILEY; i++)
	//	{
	//		gameSystemMap->setFloodFill(false, i);
	//	}
	//}
}

void enemyClass::AIClearFunction()
{
	AITile = -1;
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
	//_canMove = false;
	AIClear = false;
	//isAttach = false;

	_ggCount = 0;
	minTileF = 100000;
	minTileNumber = 0;
	aiVectorCount = 0;
	while (!AImoveStack.empty())
	{
		AImoveStack.pop();
	}
	AIendTileVector.clear();

	mostDmg = 0;

	_tileVector.clear();

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		gameSystemMap->setFloodFill(false, i);
	}
	//if (AIClear)
	//{

	//}
}


