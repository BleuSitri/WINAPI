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

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	//void mapToolSetup();
	//void setMap();

	//void save();
	//void load();

};

