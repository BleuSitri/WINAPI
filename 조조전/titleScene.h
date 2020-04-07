#pragma once
#include "gameNode.h"

#include "mapTool.h"
#include "characterEditor.h"
//#include "map1_1.h"
#include "mainScene.h"
class titleScene : public gameNode
{

private:
	char gameStartStr[128];
	char characterEditStartStr[128];
	char mapToolStartStr[128];
	char exitStr[128];
	image* titleSceneImage;


	RECT gameStartRect;
	RECT characterEditStartRect;
	RECT mapToolStartRect;
	RECT exitRect;
	RECT exitRect2;

	bool _isDebug;
public:
	titleScene();
	~titleScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

