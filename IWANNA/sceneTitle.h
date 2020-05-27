#pragma once
#include "gameNode.h"
#include "objectPool.h"
#include "player.h"

//class player;
class sceneTitle : public gameNode//, public player
{
private:

	RECT rc;

	int flag;

public:
	sceneTitle();
	~sceneTitle();

	HRESULT init();
	void release();
	void update();
	void render();
	void setFlag(player& player, int flag);

	//bool getStage1_1() {return stage1_1;}

	RECT getRc() { return rc; }

	int getFlag() { return flag; }
};

