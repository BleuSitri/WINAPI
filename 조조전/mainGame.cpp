#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init(true);
	IMAGEMANAGER->addImage("마우스커서", "images/마우스커서.bmp", 26, 26, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("m023", "images/m023.bmp", 960, 960, true, RGB(255, 0, 255));
	//SCENEMANAGER->addScene("battleScene", new battleScene);
	
	//_mapTool = new mapTool;

	//SCENEMANAGER->addScene("mapToolScene", _mapTool);
	//SCENEMANAGER->addScene("mapToolScene", new mapTool);
	//SCENEMANAGER->addScene("characterEditorScene", new characterEditor);
	//SCENEMANAGER->addScene("map1_1", new map1_1);
	SCENEMANAGER->addScene("titleScene", new titleScene);
	//SCENEMANAGER->changeScene("characterEditorScene");
	//SCENEMANAGER->changeScene("mapToolScene");	
	//SCENEMANAGER->changeScene("map1_1");
	SCENEMANAGER->changeScene("titleScene");
	




	//IMAGEMANAGER->addFrameImage("tank", "images/tank.bmp", 0, 0, 90, 120, 3, 4, true, RGB(255, 0, 255));
	////IMAGEMANAGER->addFrameImage("tank", "images/아군기병.bmp", 0, 0, 48, 672, 1, 14, true, RGB(247, 0, 255));
	//IMAGEMANAGER->addImage("bullet", "images/bullet.bmp", 6, 6, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("mouseSelect", "images/전투_마우스타일.bmp", 48, 48, true, RGB(247, 0, 255));
	//SCENEMANAGER->addScene("tank", new tankGameScene);
	//SCENEMANAGER->changeScene("tank");
	//if (_mapTool->getIsMapToolSceneOn())
	//{
	//	_mapTool->mapToolSetup();
	//}








	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	//_mapTool->release();

}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	//if (_mapTool->getIsMapToolSceneOn() && KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	//{
	//	_mapTool->setMap();
	//}

}

void mainGame::render(/*HDC hdc*/)
{
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//====================================================
	SCENEMANAGER->render();
	//IMAGEMANAGER->render("m023", getMemDC());
	//if (_mapTool->getIsMapToolSceneOn())
	//{
	//	_mapTool->render();
	//}
	TIMEMANAGER->render(getMemDC());

	IMAGEMANAGER->render("마우스커서", getMemDC(), m_ptMouse.x, m_ptMouse.y);
	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


//void mainGame::setMap()
//{
//	if (_mapTool->getIsMapToolSceneOn())
//	{
//		_mapTool->setMap();
//	}
//}
//
//void mainGame::save()
//{
//	if (_mapTool->getIsMapToolSceneOn())
//	{
//		_mapTool->save();
//	}
//}
//
//void mainGame::load()
//{
//	if (_mapTool->getIsMapToolSceneOn())
//	{
//		_mapTool->load();
//	}
//}
