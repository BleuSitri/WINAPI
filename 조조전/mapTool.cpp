#include "stdafx.h"
#include "mapTool.h"
#pragma warning(disable:4996)
//json���� �޾ƺ���

mapTool::mapTool()
{
}

mapTool::~mapTool()	
{
}

HRESULT mapTool::init()
{
	_isMapToolSceneOn = true;
	IMAGEMANAGER->addImage("mouseSelect", "images/����_���콺Ÿ��.bmp", 48, 48, true, RGB(247, 0, 255));
	IMAGEMANAGER->addFrameImage("tilemap", "images/TileMap4.bmp", 144, 528, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stage", "images/m023_2.bmp", 960, 960, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mapToolImage", "images/�����̹���TEST_2.bmp", 216, 960, true, RGB(255, 0, 255));

	mapToolSetup();
	_currentTile.x = 3;
	_currentTile.y = 0;

	SCENEMANAGER->addScene("titleScene", new titleScene);

	return S_OK;
}

void mapTool::release()
{
	_isMapToolSceneOn = false;
}

void mapTool::update()
{
	if (PtInRect(&_btnTerrainDrawRc, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_ctrSelect = CTRL_TERRAINDRAW;
		}
	}

	//_crtSelect ==CTRL_DISTINCTION�϶�
	//����� ������ �̸� ���̱�
	if (PtInRect(&_btnDistintionDrawRc, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_ctrSelect = CTRL_DISTINCTION;
		}
	}
	if (PtInRect(&_btnEraserDrawRc, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_ctrSelect = CTRL_ERASER;
		}
	}
	
	if (PtInRect(&_btnSaveDrawRc, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			save();
			//_ctrSelect = CTRL_SAVE;
		}
	}

	if (PtInRect(&_btnLoadDrawRc, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			load();
			//_ctrSelect = CTRL_LOAD;
		}
	}

	if (PtInRect(&_btnReturnRc, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			DestroyWindow(_unitNameBox);
			SCENEMANAGER->changeScene("titleScene");
			//_ctrSelect = CTRL_LOAD;
		}
	}
	
	if(KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		setMap();




	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}


}

void mapTool::render()
{
	
	IMAGEMANAGER->render("tilemap", getMemDC(), WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth(), 0);

	IMAGEMANAGER->render("stage", getMemDC());

	
	IMAGEMANAGER->render("mapToolImage", getMemDC(),960, 0);
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_isDebug)
		{
			IMAGEMANAGER->frameRender("tilemap", getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
		}
		if (PtInRect(&_tiles[i].rc, m_ptMouse))
		{
			IMAGEMANAGER->render("mouseSelect", getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top);
		}
		if (_tiles[i].dis == DISTIN_NONE)continue;
		else if (_tiles[i].dis != DISTIN_NONE)
		{
			char str[128];
			IMAGEMANAGER->findImage("tilemap")->alphaFrameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].disFrameX, _tiles[i].disFrameY, 130);
			wsprintf(str, "%s", _tiles[i].tileCharacter.name);
			TextOut(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, str, strlen(str));
		}
		
	}
	//if (_isDebug)
	//{
	//	Rectangle(getMemDC(), _btnTerrainDrawRc.left, _btnTerrainDrawRc.top, _btnTerrainDrawRc.right, _btnTerrainDrawRc.bottom);
	//	//Rectangle(getMemDC(), _btnObjectDrawRc.left, _btnObjectDrawRc.top, _btnObjectDrawRc.right, _btnObjectDrawRc.bottom);
	//	Rectangle(getMemDC(), _btnDistintionDrawRc.left, _btnDistintionDrawRc.top, _btnDistintionDrawRc.right, _btnDistintionDrawRc.bottom);
	//	Rectangle(getMemDC(), _btnSaveDrawRc.left, _btnSaveDrawRc.top, _btnSaveDrawRc.right, _btnSaveDrawRc.bottom);
	//	Rectangle(getMemDC(), _btnLoadDrawRc.left, _btnLoadDrawRc.top, _btnLoadDrawRc.right, _btnLoadDrawRc.bottom);
	//	Rectangle(getMemDC(), _btnEraserDrawRc.left, _btnEraserDrawRc.top, _btnEraserDrawRc.right, _btnEraserDrawRc.bottom);
	//	Rectangle(getMemDC(), _btnReturnRc.left, _btnReturnRc.top, _btnReturnRc.right, _btnReturnRc.bottom);
	//}
	//Rectangle(getMemDC(), _btnUnitNameSaveRc.left, _btnUnitNameSaveRc.top, _btnUnitNameSaveRc.right, _btnUnitNameSaveRc.bottom);
}

void mapTool::mapToolSetup()
{

	_btnTerrainDrawRc = RectMake(WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth(), 0, 144, 480);
	_btnDistintionDrawRc = RectMake(WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth(), 480, 144, 48);
	_btnSaveDrawRc = RectMake(1092, 570, 65, 20);
	_btnLoadDrawRc = RectMake(1092, 595, 65, 20);
	_btnEraserDrawRc = RectMake(1092, 620, 65, 20);
	_btnUnitNameSaveRc = RectMake(WINSIZEX-40, 541, 31, 19);
	_btnReturnRc = RectMake(1092, 645, 65, 20);

	_unitNameBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, WINSIZEX-135, 535, 90, 30, m_hWnd, (HMENU)0, m_hInstance, NULL);



	_ctrSelect = CTRL_TERRAINDRAW;

	//������ ���� �� ����
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTile[i* SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i* SAMPLETILEX + j].terrainFrameY = i;

			//��ǥ�� ����
			SetRect(&_sampleTile[i*SAMPLETILEX + j].rcTile,
				(WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth()) + j * TILESIZE,
				i* TILESIZE, (WINSIZEX - IMAGEMANAGER->findImage("tilemap")->getWidth()) + j * TILESIZE + TILESIZE,
				i*TILESIZE + TILESIZE);
		}
	}
	
	//���� �� ����
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			SetRect(&_tiles[i*TILEX + j].rc,
				j*TILESIZE,
				i*TILESIZE,
				j*TILESIZE + TILESIZE,
				i*TILESIZE + TILESIZE);
		}
	}
	//ó�� ����ִ� Ÿ��
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tiles[i].terrainFrameX = 3;
		_tiles[i].terrainFrameY = 0;


		_tiles[i].disFrameX = 3;
		_tiles[i].disFrameY = 0;

		_tiles[i].terrain = terrainSelect(_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);


		_tiles[i].dis = DISTIN_NONE;
		_tiles[i].canEarthMagic = false;
		_tiles[i].canFireMagic = false;
		_tiles[i].canWaterMagic = false;
		_tiles[i].canWindMagic = false;
		
	}
}

void mapTool::setMap()
{
	//������ ����
	for (int i = 0; i < SAMPLETILEX* SAMPLETILEY; i++)
	{
		if (PtInRect(&_sampleTile[i].rcTile, m_ptMouse))
		{
			_currentTile.x = _sampleTile[i].terrainFrameX;
			_currentTile.y = _sampleTile[i].terrainFrameY;
			break;
		}
	}

	//���� Ÿ��
	for (int i = 0; i < TILEX* TILEY; i++)
	{
		if (PtInRect(&_tiles[i].rc, m_ptMouse))
		{
			if (_ctrSelect == CTRL_TERRAINDRAW)
			{
				_tiles[i].terrainFrameX = _currentTile.x;
				_tiles[i].terrainFrameY = _currentTile.y;

				_tiles[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
				if (_tiles[i].terrain == TR_DITCH)
				{
					_tiles[i].block = true;
					_tiles[i].canFireMagic = false;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_FENCE)
				{
					_tiles[i].block = true;
					_tiles[i].canFireMagic = false;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_RAMPART)
				{
					_tiles[i].block = true;
					_tiles[i].canFireMagic = false;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_SNOWLAND)
				{
					_tiles[i].canFireMagic = false;
					_tiles[i].canWaterMagic = true;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = true;
				}
				if (_tiles[i].terrain == TR_FOREST)
				{
					_tiles[i].canFireMagic = true;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_CASTLELAND)
				{
					_tiles[i].canFireMagic = true;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_HOUSE)
				{
					_tiles[i].canFireMagic = true;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_BRIDGE)
				{
					_tiles[i].canFireMagic = true;
					_tiles[i].canWaterMagic = true;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = true;
				}
				if (_tiles[i].terrain == TR_TREASURE)
				{
					_tiles[i].canFireMagic = true;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}
				if (_tiles[i].terrain == TR_CASTLE)
				{
					_tiles[i].canFireMagic = true;
					_tiles[i].canWaterMagic = false;
					_tiles[i].canEarthMagic = false;
					_tiles[i].canWindMagic = false;
				}

			}
			else if (_ctrSelect == CTRL_DISTINCTION)
			{
				_tiles[i].disFrameX = _currentTile.x;
				_tiles[i].disFrameY = _currentTile.y;

				_tiles[i].dis = disSelect(_currentTile.x, _currentTile.y);
			}
			else if (_ctrSelect == CTRL_ERASER)
			{
				_tiles[i].disFrameX = 0;
				_tiles[i].disFrameY = 0;
				_tiles[i].dis = DISTIN_NONE;

			}

			InvalidateRect(m_hWnd, NULL, false);
			break;
		}
	}


	if (_ctrSelect == CTRL_DISTINCTION)
	{
		for (int i = 0; i < TILEX* TILEY; i++)
		{
			if (PtInRect(&_tiles[i].rc, m_ptMouse))
			{
				GetWindowText(_unitNameBox, _tiles[i].tileCharacter.name, 128);
				InvalidateRect(m_hWnd, NULL, false);
				break;
			}
		}
	}


}

void mapTool::save()
{
	file = CreateFile
	("mapData.map",				//������ ���϶Ǵ� �� ��ġ�� �����̸�
		GENERIC_WRITE,			//�����̳� ��ġ�� ����ų� ���� ����� ����
		0,						//���� ���� ����Է�
		NULL,					//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
		CREATE_ALWAYS,			//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL,	//�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);					//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����

	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	CloseHandle(file);
}

void mapTool::load()
{
	file = CreateFile
	("mapData.map",				//������ ���϶Ǵ� �� ��ġ�� �����̸�
		GENERIC_READ,			//�����̳� ��ġ�� ����ų� ���� ����� ����
		0,						//���� ���� ����Է�
		NULL,					//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
		OPEN_EXISTING,			//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL,	//�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);					//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����
	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	CloseHandle(file);



}

TERRAIN mapTool::terrainSelect(int frameX, int frameY)
{
	//�ø�Ʈ
	if (frameX == 0 && frameY == 0)
	{
		return TR_RIVER;
	}
	else if (frameX == 1 && frameY == 0)
	{
		return TR_OCEAN;
	}
	else if (frameX == 2 && frameY == 0)
	{
		return TR_POND;
	}
	else if (frameX == 0 && frameY == 1)
	{
		return TR_DITCH;
	}
	else if (frameX == 1 && frameY == 1)
	{
		return TR_SHIP;
	}
	else if (frameX == 2 && frameY == 1)
	{
		return TR_SNOWLAND;
	}
	else if (frameX == 0 && frameY == 2)
	{
		return TR_FORTRESS;
	}
	else if (frameX == 1 && frameY == 2)
	{
		return TR_TOWN;
	}
	else if (frameX == 2 && frameY == 2)
	{
		return TR_HOUSE;
	}
	else if (frameX == 0 && frameY == 3)
	{
		return TR_BARRACK;
	}
	else if (frameX == 1 && frameY == 3)
	{
		return TR_ALTAR;
	}
	else if (frameX == 2 && frameY == 3)
	{
		return TR_FENCE;
	}
	else if (frameX == 0 && frameY == 4)
	{
		return TR_TREASURE;
	}
	else if (frameX == 1 && frameY == 4)
	{
		return TR_GRASS;
	}
	else if (frameX == 2 && frameY == 4)
	{
		return TR_UNDERGROUND;
	}
	else if (frameX == 0 && frameY == 5)
	{
		return TR_FLATLAND;
	}
	else if (frameX == 1 && frameY == 5)
	{
		return TR_WASTELAND;
	}
	else if (frameX == 2 && frameY == 5)
	{
		return TR_MOUNTAIN;
	}
	else if (frameX == 0 && frameY == 6)
	{
		return TR_FOREST;
	}
	else if (frameX == 1 && frameY == 6)
	{
		return TR_WETLAND;
	}
	else if (frameX == 2 && frameY == 6)
	{
		return TR_RAPIDS;
	}
	else if (frameX == 0 && frameY == 7)
	{
		return TR_CLIFF;
	}
	else if (frameX == 1 && frameY == 7)
	{
		return TR_ROCKMOUNTAIN;
	}
	else if (frameX == 2 && frameY == 7)
	{
		return TR_BRIDGE;
	}
	else if (frameX == 0 && frameY == 8)
	{
		return TR_RAMPART;
	}
	else if (frameX == 1 && frameY == 8)
	{
		return TR_CASTLELAND;
	}
	else if (frameX == 2 && frameY == 8)
	{
		return TR_FIRE;
	}
	else if (frameX == 0 && frameY == 9)
	{
		return TR_GATEWAY;
	}
	else if (frameX == 1 && frameY == 9)
	{
		return TR_CASTLE;
	}
	else if (frameX == 2 && frameY == 9)
	{
		return TR_CASTLEGATE;
	}
	return TR_NONE;
}

OBJECT mapTool::objSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 0)
	{
		return OBJ_MINE;
	}
	else if (frameX == 2 && frameY == 8)
	{
		return OBJ_ALLY;
	}
	else if (frameX == 1 && frameY == 1)
	{
		return OBJ_ENEMY;
	}
	return OBJ_NONE;
}

DISTINCTION mapTool::disSelect(int frameX, int frameY)
{
	if (frameX == 0 && frameY == 10)
	{
		return DISTIN_MINE;
	}
	else if (frameX == 1 && frameY == 10)
	{
		return DISTIN_ALLY;
	}
	else if (frameX == 2 && frameY == 10)
	{
		return DISTIN_ENEMY;
	}
	return DISTIN_NONE;
}
