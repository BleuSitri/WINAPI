#pragma once
#include "gameNode.h"
#include "titleScene.h"

class defeatScene : public gameNode
{
private:
	BYTE alpha;
	int count;
	bool isDefeatSceneTime;
public:
	defeatScene();
	~defeatScene();
	HRESULT init();
	void release();
	void update();
	void render();
};

