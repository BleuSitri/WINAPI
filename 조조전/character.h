#pragma once
#include "gameNode.h"
#include "gameSystem.h"
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



class character : public gameNode
{
private:
	HANDLE file;
	DWORD read;

	//일단 포인터를 없애서 테스트중
	//tagTile _tiles[TILEX* TILEY];

	gameSystem* gameSystemMap;

	tagCharacter _character;

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


	vector<tagCharacter> _myArmyVector;
	vector<tagCharacter> _enemyVector;

	vector<image*> _faceSelectVector;
	vector<image*> _characterSelectVector;
	vector<image*> _characterAttackVector;
	vector<image*> _characterDefVector;
	vector<image*> _characterDoneVector;

public:
	character();
	~character();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();
	void tempFunction();

	void astar();

};

