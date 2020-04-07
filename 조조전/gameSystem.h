#pragma once
#include "gameNode.h"



class gameSystem : public gameNode
{
private:
	HANDLE file;
	DWORD read;

	bool _attackRange;
	bool _floodFill;

	tagCurrentTile _currentTile;

	tagTile _tiles[TILEX*TILEY];
public:
	gameSystem();
	~gameSystem();
	HRESULT init();
	void release();
	void update();
	void render();

	void loadTile();

	tagTile* getMap() { return _tiles; }

	void setAttackRange(bool attackRange, int num)
	{
		_tiles[num].attackRange = attackRange;
	}

	void setFloodFill(bool floodFill, int num)
	{
		_tiles[num].floodFill = floodFill;
	}

	void setG(int g, int num)
	{
		_tiles[num].g = g;
	}
	void setH(int h, int num)
	{
		_tiles[num].h = h;
	}
	void setF(int f, int num)
	{
		_tiles[num].f = f;
	}

	void setNode(int node, int num)
	{
		_tiles[num].node = node;
	}

	void setShowState(State showState, int num)
	{
		_tiles[num].showState = showState;
	}

	void setBlock(bool block, int num)
	{
		_tiles[num].block = block;
	}



};

