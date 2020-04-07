#pragma once
#include "gameSystem.h"
#include "gameNode.h"
#include "progressBar.h"
//
//enum Select
//{
//	SELECT_START,
//	SELECT_END,
//	SELECT_BLOCK,
//	SELECT_NONE
//};
//enum Direction
//{
//	DIRECTION_LEFT,
//	DIRECTION_RIGHT,
//	DIRECTION_UP,
//	DIRECTION_DOWN,
//	DIRECTION_LEFTUP,
//	DIRECTION_RIGHTDOWN,
//	DIRECTION_LEFTDOWN,
//	DIRECTION_RIGHTUP
//};
//
//enum State
//{
//	STATE_NONE,
//	STATE_OPEN,
//	STATE_CLOSE,
//	STATE_PATH
//};

class enemyClass : public gameNode
{
private:
	HANDLE file;
	DWORD read;

	gameSystem* gameSystemMap;

	tagCharacter _character;

	vector<tagCharacter> _enemyVector;

	vector<image*> _faceSelectVector;
	vector<image*> _characterSelectVector;
	vector<image*> _characterAttackVector;
	vector<image*> _characterDefVector;
	vector<image*> _characterDoneVector;


	//프로그레스바
	progressBar* _hpBar;
	progressBar* _mpBar;
	progressBar* _expBar;
	vector<progressBar*> _hpBarEnemyVector;
	vector<progressBar*> _mpBarEnemyVector;
	vector<progressBar*> _expBarEnemyVector;


	int _doneCount;
	int _attackCount;

	//AI
	int AICount;
	bool showRange;
	int _ggCount;
	int minTileF;
	int mostDmg;
	vector<int> _tileVector;
	vector<int> _fNumVector;

	int gg;

	//aStar
	int startTile;
	int endTile;
	int currentTile;
	int AIcurrentTile;
	bool AIstartAstar;
	vector<int> _AIopenList;
	vector<int> _AIcloseList;
	vector<int> openList;
	vector<int> closeList;
	vector<int>::iterator iter;
	stack<int> AImoveStack;

	vector<int> AIendTileVector;

	vector<int> AIaStarOpenList;
	vector<int> AIaStarCloseList;

	int aiVectorCount;


	bool startAstar;

	bool AIisFind;
	bool AInoPath;

	bool AIClear;
	bool isFind;
	bool noPath;

	int _hitNum;

	bool _isShowState;


	//
	int _beHitTileNum;
	int _beHitNum;

	bool _doAIgetTile;

	int AITile;
	bool _AIminClear;

	int minTileNumber;

	int moveSpeed[7] = { 1,2,3,4,6,8,12 };
	int moveSpeedIndex = 0;

	bool _isDoneCheck;
	int number;

	bool _isStart;

	int totalGG;

	bool attackStart;

	bool endTileSet;

	int AIendTile2;
public:
	enemyClass();
	~enemyClass();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();
	void tempFunction();

	void AI();


	void AIfloodFill(int tile, int moveCount);

	void setGGCount(int ggcount)
	{
		_ggCount = ggcount;
	}

	int getGGCount()
	{
		return _ggCount;
	}

	void setGG(int gg)
	{
		this->gg = gg;
	}

	int getGG() { return gg; }

	vector<tagCharacter> getEnemyVector() { return _enemyVector; }

	int getEnemyTile(int num) { return _enemyVector[num].tile; }

	void setHitNum(int hitNum) { _hitNum = hitNum; }
	void setCurrentDmg(int hitNum, int currentDmg)
	{
		_enemyVector[_hitNum].currentDmg = currentDmg;
	}

	int getHitNum() { return _hitNum; }

	void setBeHit(int hitNum, bool beHit)
	{
		_enemyVector[_hitNum]._beHit = beHit;
	}
	void setBeHitMotion(int hitNum, bool beHitMotion)
	{
		_enemyVector[_hitNum]._beHitMotion = beHitMotion;
	}

	void animation();
	//void setBeHit(int num) { }

	bool getIsShowState() { return _isShowState; }

	tagTile* getMap() { return gameSystemMap->getMap(); }

	void setIsAttack(bool isAttack)
	{
		_enemyVector[AICount].isAttack = isAttack;
	}

	void setMostDmg(int mostDmg)
	{
		this->mostDmg = mostDmg;
	}

	int getMostDmg()
	{
		return mostDmg;
	}


	void setBeHitTileNum(int beHitTileNum)
	{
		_beHitTileNum = beHitTileNum;
	}

	void setBeHitNum(int beHitNum)
	{
		_beHitNum = beHitNum;
	}

	int getBeHitTileNum() { return _beHitTileNum; }
	int getBeHitNum() { return _beHitNum; }

	bool getAIisFind()
	{
		return AIisFind;
	}

	bool getAInoPath()
	{
		return AInoPath;
	}

	bool getAIstartAstar()
	{
		return AIstartAstar;
	}

	int AIgetTile(int tile);

	void setDoAIgetTile(bool doAIgetTile)
	{
		_doAIgetTile = doAIgetTile;
	}

	void setAITile(int tile)
	{
		AITile = tile;
	}

	vector<int> getFNumberVector() { return _fNumVector; }
	vector<int> getTileVector() { return _tileVector; }

	void setAIminClear(bool AIminClear)
	{
		_AIminClear = AIminClear;
	}

	void AIAstar(int endTile);
	void enemyVectorMove();

	void setDirection(CHARACTERDIRECTION direction)
	{
		_enemyVector[AICount].direction;
	}

	void setIsNormalState(bool isNormalState)
	{
		_enemyVector[AICount].normalState = isNormalState;
	}
	void setIsAttackMotion(bool isAttackMotion)
	{
		_enemyVector[AICount].isAttackMotion = isAttackMotion;
	}

	void setAICount(int num)
	{
		AICount = num;
	}
	int getAICount()
	{
		return AICount;
	}

	void setIsDone(bool isDone, int i)
	{
		_enemyVector[i].isDone = isDone;
	}
	void setIsDoneCheck(bool isDoneCheck)
	{
		_isDoneCheck = isDoneCheck;
	}
	bool getIsDoneCheck()
	{
		return _isDoneCheck;
	}

	int getNumber()
	{
		return number;
	}

	void setNumber(int num)
	{
		number = num;
	}

	int AISearchEntile();

	void AIAstarStartFunction(int endTile);

	int getStartTile() {
		return startTile;
	}
	int getEndTile()
	{
		return endTile;
	}

	void setIsStart(bool isStart)
	{
		_isStart = isStart;
	}

	bool getAIClear()
	{
		return AIClear;
	}
	void AIClearFunction();
	void setEndTile(int endtile)
	{
		this->endTile = endTile;
	}

	bool getDoAIgetTile()
	{
		return _doAIgetTile;
	}

	void AIAttack();

	bool getAttackStart()
	{
		return attackStart;
	}
	bool getIsAttackMotion()
	{
		return _enemyVector[AICount].isAttackMotion;
	}

	void setAttackStart(bool isAttackStart)
	{
		attackStart = isAttackStart;
	}

	int getDoneCount()
	{
		return _doneCount;
	}

	bool getEndTileSet()
	{
		return endTileSet;
	}

	void setEndTileSet(bool endTileSet)
	{
		this->endTileSet = endTileSet;
	}

};

