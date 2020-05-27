#pragma once
#include "gameNode.h"
#include "scene1_1.h"
#include "scene1_2.h"
#include "scene1_3.h"
#include "scene1_4.h"
#include "player.h"

class scene1 : public gameNode
{
private:
	scene1_1* _scene1_1;
	scene1_2* _scene1_2;
	scene1_3* _scene1_3;
	scene1_4* _scene1_4;
	player* _player;
	int flag;

public:
	scene1();
	~scene1();

	HRESULT init();
	void release();
	void update();
	void render();

	void setPlayerMemoryLink(player* player) { _player = player; }
	int getFlag() { return flag; }
};
