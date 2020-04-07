#pragma once
#include "gameNode.h"
#include "titleScene.h"
class victoryScene : public gameNode
{
private:
	BYTE alpha;
	int count;
	bool isVictorySceneTime;
public:
	victoryScene();
	~victoryScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

