#pragma once
#include "gameNode.h"

#include "titleScene.h"


class mapTool : public gameNode
{
private:

	HWND _unitNameBox;

	HANDLE file;
	DWORD write;
	DWORD read;

	tagCurrentTile _currentTile;
	tagTile _tiles[TILEX* TILEY];
	tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY];

	bool _isMapToolSceneOn;

	RECT _btnTerrainDrawRc;
	RECT _btnObjectDrawRc;
	RECT _btnEraserDrawRc;
	RECT _btnDistintionDrawRc;
	RECT _btnSaveDrawRc;
	RECT _btnLoadDrawRc;
	RECT _btnUnitNameSaveRc;
	RECT _btnReturnRc;

	bool _isDebug;



public:
	mapTool();
	~mapTool();
	HRESULT init();	
	void release();
	void update();
	void render();

	void mapToolSetup();
	void setMap();

	void save();
	void load();


	int _ctrSelect;
	void setCtrSelect(int num) { _ctrSelect = num; }





	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objSelect(int frameX, int frameY);
	DISTINCTION disSelect(int frameX, int frameY);

	bool getIsMapToolSceneOn() { return _isMapToolSceneOn; }
};

