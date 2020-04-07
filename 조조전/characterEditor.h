#pragma once
#include "gameNode.h"

#include "titleScene.h"


class characterEditor : public gameNode
{
private:
	HWND _levelBox;
	HWND _increaseHpBox;
	HWND _increaseMpBox;

	HWND _nameBox;
	HWND _classBox;
	HWND _hpBox;
	HWND _mpBox;
	HWND _strBox;
	HWND _dexBox;
	HWND _intBox;
	HWND _luckBox;
	HWND _cmdBox;

	HWND _atkBox;
	HWND _mAtkBox;
	HWND _defBox;
	HWND _spdBox;
	HWND _moraleBox;
	HWND _moveBox;

	HWND _increaseAtkBox;
	HWND _increaseMAtkBox;
	HWND _increaseDefBox;
	HWND _increaseSpdBox;
	HWND _increaseMoraleBox;
	HWND _increaseMoveBox;
	 
	RECT _saveRect;
	RECT _loadRect;
	RECT _prevFaceRect;
	RECT _nextFaceRect;
	RECT _prevCharacterRect;
	RECT _nextCharacterRect;
	RECT _returnRect;

	HANDLE file;
	DWORD write;
	DWORD read;

	tagCharacter _tempCharacter;
	char fileName[128];
	char _str[128];
	char _temp[128];

	int _faceSelectNum;
	int _characterSelectNum;
	int _characterAttackNum;
	int _characterDefNum;
	int _characterDoneNum;

	vector<image*> _faceSelectVector;
	vector<image*> _characterSelectVector;

	vector<image*> _characterAttackVector;
	vector<image*> _characterDefVector;
	vector<image*> _characterDoneVector;


	tagAttackTile _attackTile[ATTACKTILEX*ATTACKTILEY];
	int _characterTile = 24;
	vector<int> _attackTileVector;

	bool _characterEditorOn;




public:
	characterEditor();
	~characterEditor();

	HRESULT init();
	void release();
	void update();
	void render();

	void save();
	void load();

	void faceSelect();
	void characterSelect();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	//나중에 이미지 저장, 로드 부분 수정하면서 체크해야함.
	void tempFunction();

	void setAttackTile();
	void eraseAttackTile();
};

