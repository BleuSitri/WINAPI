#pragma once
#include"gameNode.h"
#include "map1_1.h"
class battleScene : public gameNode
{
private:
	map1_1* _map1_1;
public:
	battleScene();
	~battleScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

