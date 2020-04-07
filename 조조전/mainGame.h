#pragma once
#include"gameNode.h"
//#include"battleScene.h"
//#include "map1_1.h"
//#include "mapTool.h"
//#include "characterEditor.h"
#include "titleScene.h"
//#include "mainScene.h"
class mainGame : public gameNode
{
private:
	//mapTool* _mapTool;


	//vector<image*> _faceSelectVector;
	//vector<image*> _characterSelectVector;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	//void mapToolSetup();
	//void setMap();

	//void save();
	//void load();

};

