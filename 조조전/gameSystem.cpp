#include "stdafx.h"
#include "gameSystem.h"

gameSystem::gameSystem()
{
}

gameSystem::~gameSystem()
{
}

HRESULT gameSystem::init()
{
	loadTile();

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tiles[i].attackRange = false;

	}
	return S_OK;
}

void gameSystem::release()
{
}

void gameSystem::update()
{
}

void gameSystem::render()
{
}

void gameSystem::loadTile()
{
	file = CreateFile
	("mapData.map",				//생성할 파일또는 열 장치나 파일이름
		GENERIC_READ,			//파일이나 장치를 만들거나 열때 사용할 권한
		0,						//파일 공유 모드입력
		NULL,					//파일또는 장치를 열때 보안 및 특성
		OPEN_EXISTING,			//파일이나 장치를 열때 취할 행동
		FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
		NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	CloseHandle(file);
}
