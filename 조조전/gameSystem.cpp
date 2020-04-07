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
