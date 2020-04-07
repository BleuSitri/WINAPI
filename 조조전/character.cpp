#include "stdafx.h"
#include "character.h"
#pragma warning(disable:4996)

character::character()
{
}

character::~character()
{
}

HRESULT character::init()
{
	gameSystemMap = new gameSystem;
	gameSystemMap->init();

	tempFunction();
	load();

	startTile = endTile = -1;
	isFind = false;
	noPath = false;
	startAstar = false;

	currentSelect = SELECT_NONE;

	for (int i = 0; i < _myArmyVector.size(); i++)
	{
		_myArmyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
	}
	for (int i = 0; i < _enemyVector.size(); i++)
	{
		_enemyVector[i].direction = CHARACTER_DIRECTION_BOTTOM;
	}

	return S_OK;
}

void character::release()
{
	SAFE_DELETE(gameSystemMap);
}

void character::update()
{
}

void character::render()
{
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

	}

}

void character::load()
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

		if (gameSystemMap->getMap()[i].dis == DISTIN_ENEMY)
			_enemyVector.push_back(_character);
		else if (gameSystemMap->getMap()[i].dis == DISTIN_MINE)
			_myArmyVector.push_back(_character);
		CloseHandle(file);

	}
}

void character::tempFunction()
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

void character::astar()
{
}
