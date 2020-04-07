#pragma once
#include "gameSystem.h"
#include "gameNode.h"
#include "progressBar.h"



class myArmyClass : public gameNode
{
private:
	HANDLE file;
	DWORD read;

	gameSystem* gameSystemMap;

	tagCharacter _character;

	//프로그레스바
	progressBar* _hpBar;
	progressBar* _mpBar;
	progressBar* _expBar;

	vector<progressBar*> _hpBarMyVector;
	vector<progressBar*> _mpBarMyVector;
	vector<progressBar*> _expBarMyVector;



	vector<tagCharacter> _myArmyVector;

	vector<image*> _faceSelectVector;
	vector<image*> _characterSelectVector;
	vector<image*> _characterAttackVector;
	vector<image*> _characterDefVector;
	vector<image*> _characterDoneVector;


	int _selectNum;
	int prevTile;
	CHARACTERDIRECTION prevDirection;
	bool showRange;

	bool _canMove;


	int moveSpeed[7] = { 1,2,3,4,6,8,12 };
	int moveSpeedIndex = 0;

	//attackoption
	bool _attackOptionMenu;

	RECT _battleOption;
	RECT _battleOptionAttack;
	RECT _battleOptionMagic;
	RECT _battleOptionItem;
	RECT _battleOptionDone;
	RECT _battleOptionCancle;

	bool _canAttack;

	//aStar
	vector<int> openList;
	vector<int>closeList;
	vector<int>::iterator iter;
	stack<int> moveStack;

	Select currentSelect;

	int startTile;
	int endTile;
	int currentTile;
	bool isFind;
	bool noPath;
	bool startAstar;

	int _doneCount;

	bool attackStart;
	bool attackFinish;

	bool _isShowState;

	int _beHitTileNum;
	int _beHitNum;
	int _attackCount;

	//tagItem _item;
	bool beHit;
	bool beHitMotion;

	//

public:
	myArmyClass();
	~myArmyClass();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();
	void tempFunction();

	void astar();

	void floodFill(int tile, int moveCount);

	void animation();

	void setCanAttack(bool canAttack) { _canAttack = canAttack; }
	//void setIsAttack(bool isAttack, int num) { _myArmyVector[num].isAttack = isAttack; }
	void setIsAttack(bool isAttack) { _myArmyVector[_selectNum].isAttack = isAttack; }
	//void setIsAttackMotion(bool isAttackMotion, int num) { _myArmyVector[num].isAttackMotion = isAttackMotion; }
	void setIsAttackMotion(bool isAttackMotion) { _myArmyVector[_selectNum].isAttackMotion = isAttackMotion; }

	int getDoneCount() { return _doneCount; }

	void setDirection(CHARACTERDIRECTION direction, int i)
	{
		_myArmyVector[i].direction = direction;
	}

	vector<tagCharacter> getMyArmyVector() { return _myArmyVector; }

	int getSelectNum() { return _selectNum; }

	bool getShowRange() { return showRange; }

	tagTile* getMap() { return gameSystemMap->getMap(); }

	bool getIsAttackMotion() { return _myArmyVector[_selectNum].isAttackMotion; }

	bool getAttackStart() { return attackStart; }
	bool getAttackFinish() { return attackFinish; }

	void setAttackStart(bool attackStart)
	{
		this->attackStart = attackStart;
	}
	void setAttackFinish(bool attackFinish)
	{
		this->attackFinish = attackFinish;
	}


	bool getIsShowState() { return _isShowState; }

	void setCurrentDmg(int currentDmg, int num)
	{
		_myArmyVector[num].currentDmg = currentDmg;
	}

	int getCurrentDmg(int num)
	{
		return _myArmyVector[num].currentDmg;
	}

	void setBeHitTileNum(int beHitTileNum)
	{
		_beHitTileNum = beHitTileNum;
	}

	void setBeHitNum(int beHitNum)
	{
		_beHitNum = beHitNum;
	}

	int getBeHitTileNum()
	{
		return _beHitTileNum;
	}

	void equipItem(tagItem nextEquipItem, int num);


	void setAtk(int atk, int num)
	{
		_myArmyVector[num].atk += atk;
	}
	void setDef(int def, int num)
	{
		_myArmyVector[num].def += def;
	}

	void minusStat(tagItem beforeItem, int num);

	tagItem unEquipItem(int num, int vectorNum);


	void setBeHit(bool beHit)
	{
		_myArmyVector[_beHitNum]._beHit = beHit;
	}
	void setBeHitMotion(bool beHitMotion)
	{
		_myArmyVector[_beHitNum]._beHitMotion = beHitMotion;
	}

	int getBeHitNum()
	{
		return _beHitNum;
	}
	void setCurrentHp(int hp)
	{

	}
};

