#include "stdafx.h"
#include "characterEditor.h"
#pragma warning(disable:4996)

characterEditor::characterEditor()
{
}

characterEditor::~characterEditor()
{
}

HRESULT characterEditor::init()
{
	tempFunction();
	IMAGEMANAGER->addImage("characterEditorBackground", "images/유닛에디터2_2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));


	//IMAGEMANAGER->addImage("Face0", "images/캐릭터 얼굴/0-0.bmp", 64, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Face1", "images/캐릭터 얼굴/1-1.bmp", 64, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Face2", "images/캐릭터 얼굴/10-1.bmp", 64, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Face3", "images/캐릭터 얼굴/11-1.bmp", 64, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Face4", "images/캐릭터 얼굴/12-1.bmp", 64, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("Face5", "images/캐릭터 얼굴/13-1.bmp", 64, 80, true, RGB(255, 0, 255));

	//IMAGEMANAGER->addImage("attackRange", "images/16-3.bmp", 128, 128,true,RGB(255,0,255));
	IMAGEMANAGER->addFrameImage("attackRange", "images/범위선택.bmp", 60, 20, 3, 1, true, RGB(255, 0, 255));


	_levelBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 230, 80, 30, m_hWnd, (HMENU)20, m_hInstance, NULL);
	_increaseHpBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 456, 80, 30, m_hWnd, (HMENU)21, m_hInstance, NULL);
	_increaseMpBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 492, 80, 30, m_hWnd, (HMENU)22, m_hInstance, NULL);
	_nameBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 95, 80, 30, m_hWnd, (HMENU)0, m_hInstance, NULL);
	_classBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 130, 80, 30, m_hWnd, (HMENU)1, m_hInstance, NULL);
	_hpBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 265, 80, 30, m_hWnd, (HMENU)2, m_hInstance, NULL);
	_mpBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 304, 80, 30, m_hWnd, (HMENU)3, m_hInstance, NULL);

	_strBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 341, 80, 30, m_hWnd, (HMENU)4, m_hInstance, NULL);
	_dexBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 380, 80, 30, m_hWnd, (HMENU)5, m_hInstance, NULL);
	_intBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 419, 80, 30, m_hWnd, (HMENU)6, m_hInstance, NULL);
	_luckBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 457, 80, 30, m_hWnd, (HMENU)7, m_hInstance, NULL);
	_cmdBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 495, 80, 30, m_hWnd, (HMENU)8, m_hInstance, NULL);

	_atkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 532, 80, 30, m_hWnd, (HMENU)9, m_hInstance, NULL);
	_mAtkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 568, 80, 30, m_hWnd, (HMENU)10, m_hInstance, NULL);
	_defBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 605, 80, 30, m_hWnd, (HMENU)11, m_hInstance, NULL);
	_spdBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 642, 80, 30, m_hWnd, (HMENU)12, m_hInstance, NULL);
	_moraleBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 678, 80, 30, m_hWnd, (HMENU)13, m_hInstance, NULL);
	_moveBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 716, 80, 30, m_hWnd, (HMENU)14, m_hInstance, NULL);

	_increaseAtkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 529, 80, 30, m_hWnd, (HMENU)15, m_hInstance, NULL);
	_increaseMAtkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 567, 80, 30, m_hWnd, (HMENU)16, m_hInstance, NULL);
	_increaseDefBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 605, 80, 30, m_hWnd, (HMENU)17, m_hInstance, NULL);
	_increaseSpdBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 642, 80, 30, m_hWnd, (HMENU)18, m_hInstance, NULL);
	_increaseMoraleBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 679, 80, 30, m_hWnd, (HMENU)19, m_hInstance, NULL);


	//_increaseMoveBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 760, 70, 30, m_hWnd, (HMENU)20, m_hInstance, NULL);

	_saveRect = RectMake(727, 88, 147, 60);
	_loadRect = RectMake(727, 162, 147, 60);

	_prevFaceRect = RectMake(210, 171, 22, 16);
	_nextFaceRect = RectMake(252, 171, 22, 16);

	_prevCharacterRect = RectMake(218, 869, 22, 16);
	_nextCharacterRect = RectMake(244, 869, 22, 16);

	_returnRect = RectMake(727, 825, 147, 80);

	SCENEMANAGER->addScene("titleScene",new titleScene);
	 


	_tempCharacter.characterFaceImage = IMAGEMANAGER->findImage("Face0");
	_tempCharacter.characterMoveImage = IMAGEMANAGER->findImage("Unit0");

	for (int i = 0; i < ATTACKTILEY; i++)
	{
		for (int j = 0; j < ATTACKTILEX; j++)
		{
			SetRect(&_attackTile[i*ATTACKTILEX + j].rc, 730 + j * 20, 250+ i * 20, 730 + j * 20 + 20, 250 + i * 20 + 20);
		}
	}

	
	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	{
		_attackTile[i].attackTileFrameX = 0;
		_attackTile[i].attackTileFrameY = 0;
		_attackTile[i].attackTileType = ATTACKTILE_NONE;
	}
	_attackTile[_characterTile].attackTileFrameX = 1;
	_attackTile[_characterTile].attackTileFrameY = 0;
	



	//GetDlgItemText(_nameBox,;
	//GetWindowText(_nameBox,)

	return S_OK;
}

void characterEditor::release()
{
}

void characterEditor::update()
{

	//_tempCharacter.name = GetWindowText(_nameBox, str, 128)/*+".dat"*/;
	//GetWindowText(_nameBox, _tempCharacter.name, 128)/*+".dat"*/;
	//strcat(_tempCharacter.name, ".dat");
	//_tempCharacter.hp = GetDlgItemInt(m_hWnd, 2, NULL, false);
	//_tempCharacter.mp = GetDlgItemInt(m_hWnd, 3, NULL, false);

	//_tempCharacter.str = GetDlgItemInt(m_hWnd, 4, NULL, false);
	//_tempCharacter.dex = GetDlgItemInt(m_hWnd, 5, NULL, false);
	//_tempCharacter.intelligence = GetDlgItemInt(m_hWnd, 6, NULL, false);
	//_tempCharacter.luck = GetDlgItemInt(m_hWnd, 7, NULL, false);
	//_tempCharacter.cmd = GetDlgItemInt(m_hWnd, 8, NULL, false);

	//_tempCharacter.atk = GetDlgItemInt(m_hWnd, 9, NULL, false);
	//_tempCharacter.mAtk = GetDlgItemInt(m_hWnd, 10, NULL, false);
	//_tempCharacter.def = GetDlgItemInt(m_hWnd, 11, NULL, false);
	//_tempCharacter.spd = GetDlgItemInt(m_hWnd, 12, NULL, false);
	//_tempCharacter.morale = GetDlgItemInt(m_hWnd, 13, NULL, false);
	//_tempCharacter.move = GetDlgItemInt(m_hWnd, 14, NULL, false);

	//_tempCharacter.increaseAtk = GetDlgItemInt(m_hWnd, 15, NULL, false);
	//_tempCharacter.increaseMAtk = GetDlgItemInt(m_hWnd, 16, NULL, false);
	//_tempCharacter.increaseDef = GetDlgItemInt(m_hWnd, 17, NULL, false);
	//_tempCharacter.increaseSpd = GetDlgItemInt(m_hWnd, 18, NULL, false);
	//_tempCharacter.increaseMorale = GetDlgItemInt(m_hWnd, 19, NULL, false);


	//GetWindowText(_hpBox, , 128);
	//GetWindowLong(_hpBox, _tempCharacter.hp);
	//GetDlgItemInt(_hpBox, _tempCharacter.hp, false, false);
	//SetWindowText(_mpBox, _itoa(_tempCharacter.hp, temp, 128));
	//if (PtInRect(&_prevFaceRect, m_ptMouse))
	//{
	//	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//	{
	//		if (_faceSelectNum <= 0)
	//			_faceSelectNum = 0;
	//		else
	//			_faceSelectNum--;
	//	}
	//}
	//else if (PtInRect(&_nextFaceRect, m_ptMouse))
	//{
	//	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//	{
	//		if (_faceSelectNum >= 5)
	//			_faceSelectNum = 5;
	//		else
	//			_faceSelectNum++;
	//	}
	//}
	
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		setAttackTile();
	}
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		eraseAttackTile();
	}


	if (PtInRect(&_saveRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			save();
		}
	}
	else if (PtInRect(&_loadRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			load();
		}
	}
	else if (PtInRect(&_returnRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			SCENEMANAGER->changeScene("titleScene");
			DestroyWindow(_levelBox);
			DestroyWindow(_classBox);
			DestroyWindow(_increaseHpBox);
			DestroyWindow(_increaseMpBox);
			DestroyWindow(_nameBox);
			DestroyWindow(_hpBox);
			DestroyWindow(_mpBox);
			DestroyWindow(_strBox);
			DestroyWindow(_dexBox);
			DestroyWindow(_intBox);
			DestroyWindow(_luckBox);
			DestroyWindow(_cmdBox);
			DestroyWindow(_atkBox);
			DestroyWindow(_moveBox);
			DestroyWindow(_mAtkBox);
			DestroyWindow(_defBox);
			DestroyWindow(_spdBox);
			DestroyWindow(_moraleBox);
			DestroyWindow(_increaseAtkBox);
			DestroyWindow(_increaseMAtkBox);
			DestroyWindow(_increaseDefBox);
			DestroyWindow(_increaseSpdBox);
			DestroyWindow(_increaseMoraleBox);
			DestroyWindow(_increaseMoveBox);
		}
	}
	faceSelect();
	characterSelect();





	//if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	//{
	//	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	//	{
	//		if (PtInRect(&_attackTile[i].rc, m_ptMouse) && i != _characterTile)
	//		{
	//			_attackTile[i].attackTileFrameX = 2;
	//			_attackTile[i].attackTileFrameY = 0;

	//			_attackTile[i].attackTileType = ATTACKTILE_ATTACKRANGE;

	//		}
	//	}
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	//{
	//	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	//	{
	//		if (PtInRect(&_attackTile[i].rc, m_ptMouse) && i != _characterTile)
	//		{
	//			_attackTile[i].attackTileFrameX = 0;
	//			_attackTile[i].attackTileFrameY = 0;

	//			_attackTile[i].attackTileType = ATTACKTILE_NONE;
	//		}
	//	}
	//}


	//for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	//{
	//	if (_attackTile[i].attackTileType == ATTACKTILE_ATTACKRANGE)
	//	{
	//		_attackTileVector.push_back(i);
	//	}
	//}

}

void characterEditor::render()
{
	IMAGEMANAGER->render("characterEditorBackground", getMemDC());
	//IMAGEMANAGER->render("Face1",getMemDC());
	//IMAGEMANAGER->addImage("1","images/캐릭터 얼굴/7.bmp", 64, 80, true, RGB(255, 0, 255))->render(getMemDC());
	_tempCharacter.characterFaceImage->render(getMemDC(), 210, 88);
	_tempCharacter.characterMoveImage->render(getMemDC(), 218, 194);
	//IMAGEMANAGER->addImage("rider", "images/아군기병.bmp", 48, 672, true, RGB(255, 0, 255))->render(getMemDC());
	//IMAGEMANAGER->addImage("rider", "images/적보병2.bmp", 48, 672, true, RGB(255, 0, 255))->render(getMemDC());
	//char str[128];
	//wsprintf(str, "_faceSelectVectorSize : %d", _faceSelectVector.size());
	//TextOut(getMemDC(), 0, 500, str,strlen(str));
	
	//Rectangle(getMemDC(), _prevFaceRect.left, _prevFaceRect.top, _prevFaceRect.right, _prevFaceRect.bottom);
	//Rectangle(getMemDC(), _nextFaceRect.left, _nextFaceRect.top, _nextFaceRect.right, _nextFaceRect.bottom);
	//Rectangle(getMemDC(), _prevCharacterRect.left, _prevCharacterRect.top, _prevCharacterRect.right, _prevCharacterRect.bottom);
	//Rectangle(getMemDC(), _nextCharacterRect.left, _nextCharacterRect.top, _nextCharacterRect.right, _nextCharacterRect.bottom);
	//Rectangle(getMemDC(),300,)
	//_tempCharacter.characterFaceImage->render(getMemDC(), );
	//Rectangle(getMemDC(), _saveRect.left, _saveRect.top, _saveRect.right, _saveRect.bottom);
	//Rectangle(getMemDC(), _loadRect.left, _loadRect.top, _loadRect.right, _loadRect.bottom);
	//ShowWindow(_textBox, SW_SHOW);
	//IMAGEMANAGER->render("attackRange", getMemDC(), 730, 250);
	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
		//Rectangle(getMemDC(), _attackTile[i].rc.left, _attackTile[i].rc.top, _attackTile[i].rc.right, _attackTile[i].rc.bottom);
		IMAGEMANAGER->frameRender("attackRange", getMemDC(), _attackTile[i].rc.left, _attackTile[i].rc.top, _attackTile[i].attackTileFrameX, _attackTile[i].attackTileFrameY);
		//IMAGEMANAGER->frameRender("attackRange", getMemDC(), 730 + _attackTile[i].rc.left, 250 + _attackTile[i].rc.top, _attackTile[i].attackTileFrameX, _attackTile[i].attackTileFrameY);
	//Rectangle(getMemDC(), _returnRect.left, _returnRect.top, _returnRect.right, _returnRect.bottom);
}

void characterEditor::save()
{
	//for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	//{
	//	if (_attackTile[i].attackTileType == ATTACKTILE_ATTACKRANGE)
	//	{
	//		_attackTileVector.push_back(i);
	//	}
	//}

	GetWindowText(_nameBox, _tempCharacter.name, 128)/*+".dat"*/;
	//strcat(_tempCharacter.name, ".dat");
	GetWindowText(_classBox, _tempCharacter.classType, 128)/*+".dat"*/;
	_tempCharacter.characterFaceImage = _faceSelectVector[_faceSelectNum];
	_tempCharacter.characterMoveImage = _characterSelectVector[_characterSelectNum];
	_tempCharacter.characterAttackImage = _characterAttackVector[_characterSelectNum];
	_tempCharacter.characterDefImage = _characterDefVector[_characterSelectNum];
	_tempCharacter.characterDoneImage = _characterDoneVector[_characterSelectNum];

	_tempCharacter.hp = GetDlgItemInt(m_hWnd, 2, NULL, false);
	_tempCharacter.mp = GetDlgItemInt(m_hWnd, 3, NULL, false);
	//strcpy(_tempCharacter.faceImageKey, tempFaceLink);
	//_tempCharacter.faceImageNum = _faceSelectNum;
	_tempCharacter.faceImageNum = _faceSelectNum;
	_tempCharacter.moveImageNum = _characterSelectNum;

	_tempCharacter.str = GetDlgItemInt(m_hWnd, 4, NULL, false);
	_tempCharacter.dex = GetDlgItemInt(m_hWnd, 5, NULL, false);
	_tempCharacter.intelligence = GetDlgItemInt(m_hWnd, 6, NULL, false);
	_tempCharacter.luck = GetDlgItemInt(m_hWnd, 7, NULL, false);
	_tempCharacter.cmd = GetDlgItemInt(m_hWnd, 8, NULL, false);

	_tempCharacter.atk = GetDlgItemInt(m_hWnd, 9, NULL, false);
	_tempCharacter.mAtk = GetDlgItemInt(m_hWnd, 10, NULL, false);
	_tempCharacter.def = GetDlgItemInt(m_hWnd, 11, NULL, false);
	_tempCharacter.spd = GetDlgItemInt(m_hWnd, 12, NULL, false);
	_tempCharacter.morale = GetDlgItemInt(m_hWnd, 13, NULL, false);
	_tempCharacter.move = GetDlgItemInt(m_hWnd, 14, NULL, false);

	_tempCharacter.increaseAtk = GetDlgItemInt(m_hWnd, 15, NULL, false);
	_tempCharacter.increaseMAtk = GetDlgItemInt(m_hWnd, 16, NULL, false);
	_tempCharacter.increaseDef = GetDlgItemInt(m_hWnd, 17, NULL, false);
	_tempCharacter.increaseSpd = GetDlgItemInt(m_hWnd, 18, NULL, false);
	_tempCharacter.increaseMorale = GetDlgItemInt(m_hWnd, 19, NULL, false);
	_tempCharacter.level = GetDlgItemInt(m_hWnd, 20, NULL, false);
	_tempCharacter.increaseHp = GetDlgItemInt(m_hWnd, 21, NULL, false);
	_tempCharacter.increaseMp = GetDlgItemInt(m_hWnd, 22, NULL, false);
	


	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	{
		if (_attackTile[i].attackTileType == ATTACKTILE_ATTACKRANGE)
		{
			//_tempCharacter.attackTileVector.push_back(i);
			_tempCharacter.attackArray[i] = 1;
		}
		if (_attackTile[i].attackTileType == ATTACKTILE_NONE)
		{
			//_tempCharacter.attackTileVector.push_back(i);
			_tempCharacter.attackArray[i] = 0;
		}
	}

	//_tempCharacter.attackTileVectorSize = _tempCharacter.attackTileVector.size();

	//for (int i = 0; i < _attackTileVector.size(); i++)
	//	_tempCharacter.attackTileVector.push_back(_attackTileVector[i]);

	strcpy(fileName, _tempCharacter.name);
	strcat(fileName, ".dat");
	file = CreateFile
	(	fileName,//_tempCharacter.name,//_tempCharacter.name.c_str(),				//생성할 파일또는 열 장치나 파일이름
		GENERIC_WRITE,			//파일이나 장치를 만들거나 열때 사용할 권한
		0,						//파일 공유 모드입력
		NULL,					//파일또는 장치를 열때 보안 및 특성
		CREATE_ALWAYS,			//파일이나 장치를 열때 취할 행동
		FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
		NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보

	WriteFile(file, &_tempCharacter, sizeof(tagCharacter), &write, NULL);
	CloseHandle(file);
}

void characterEditor::load()
{
	//_attackTileVector.clear();

	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	{
		_tempCharacter.attackArray[i] = 0;
		if (i != _characterTile)
		{
			_attackTile[i].attackTileFrameX = 0;
			_attackTile[i].attackTileFrameY = 0;
			_attackTile[i].attackTileType = ATTACKTILE_NONE;
		}

	}

	OPENFILENAME ofn;

	char filePathSize[1024] = "";

	ZeroMemory(&ofn, sizeof(OPENFILENAME));


	ofn.lStructSize = sizeof(OPENFILENAME);//구조체 사이즈 지정
	ofn.hwndOwner = NULL;//대화상자 소유자를 지정
	ofn.lpstrFile = filePathSize;//파일이름 에디트에 처음 나타낼 파일명을 지정. 충분한버퍼가 있어야 한다.
	ofn.nMaxFile = sizeof(filePathSize);
	ofn.nFilterIndex = true;//파일 형식 콤보박스에서 사용할 필터의 인덱스를 지정
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = (".dat");//이름(파일형식)


	//대화상자의 모양과 동작을 지정
	//OFN_PATHMUSTEXIST : 존재하는 경로와 파일만 입력
	//OFN_FILEMUSTEXIST :존재하는 파일만 입력
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;


	if (GetOpenFileName(&ofn) == FALSE)return;


	char temp[1024];


	strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));
	char* context = NULL;
	char* token = strtok_s(temp, "\\", &context);

	while (strlen(context))
	{
		token = strtok_s(NULL, "\\", &context);
	}

	file = CreateFile
	(	ofn.lpstrFile,				//생성할 파일또는 열 장치나 파일이름
		GENERIC_READ,			//파일이나 장치를 만들거나 열때 사용할 권한
		0,						//파일 공유 모드입력
		NULL,					//파일또는 장치를 열때 보안 및 특성
		OPEN_EXISTING,			//파일이나 장치를 열때 취할 행동
		FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
		NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
	ReadFile(file, &_tempCharacter, sizeof(tagCharacter), &read, NULL);
	CloseHandle(file);

	
	SetWindowText(_nameBox, _tempCharacter.name);
	SetWindowText(_classBox, _tempCharacter.classType);

	//for (int i = 0; i < _tempCharacter.attackTileVectorSize; i++)
	//{
	//	//_attackTile[_tempCharacter.attackTileVector[i]].attackTileFrameX = 2;
	//	//_attackTile[_tempCharacter.attackTileVector[i]].attackTileFrameX = 0;
	//	//_attackTile[_tempCharacter.attackTileVector[i]].attackTileType = ATTACKTILE_ATTACKRANGE;
	//}

	_faceSelectNum = _tempCharacter.faceImageNum;
	_characterSelectNum = _tempCharacter.moveImageNum;
	//_tempCharacter.characterFaceImage = IMAGEMANAGER->findImage(_tempCharacter.faceImageKey);

	SetDlgItemInt(m_hWnd, 2, _tempCharacter.hp, false);
	SetDlgItemInt(m_hWnd, 3, _tempCharacter.mp, false);
	SetDlgItemInt(m_hWnd, 4, _tempCharacter.str, false);
	SetDlgItemInt(m_hWnd, 5, _tempCharacter.dex, false);
	SetDlgItemInt(m_hWnd, 6, _tempCharacter.intelligence, false);
	SetDlgItemInt(m_hWnd, 7, _tempCharacter.luck, false);
	SetDlgItemInt(m_hWnd, 8, _tempCharacter.cmd, false);

	SetDlgItemInt(m_hWnd, 9, _tempCharacter.atk, false);
	SetDlgItemInt(m_hWnd, 10, _tempCharacter.mAtk, false);
	SetDlgItemInt(m_hWnd, 11, _tempCharacter.def, false);
	SetDlgItemInt(m_hWnd, 12, _tempCharacter.spd, false);
	SetDlgItemInt(m_hWnd, 13, _tempCharacter.morale, false);
	SetDlgItemInt(m_hWnd, 14, _tempCharacter.move, false);

	SetDlgItemInt(m_hWnd, 15, _tempCharacter.increaseAtk, false);
	SetDlgItemInt(m_hWnd, 16, _tempCharacter.increaseMAtk, false);
	SetDlgItemInt(m_hWnd, 17, _tempCharacter.increaseDef, false);
	SetDlgItemInt(m_hWnd, 18, _tempCharacter.increaseSpd, false);
	SetDlgItemInt(m_hWnd, 19, _tempCharacter.increaseMorale, false);

	SetDlgItemInt(m_hWnd, 20, _tempCharacter.level, false);
	SetDlgItemInt(m_hWnd, 21, _tempCharacter.increaseHp, false);
	SetDlgItemInt(m_hWnd, 22, _tempCharacter.increaseMp, false);

	

	//SOUNDMANAGER->addSound(키값, 파일 이름, bgm, loop);
	//SOUNDMANAGER->addSound(token, ofn.lpstrFile, false, false);

	//for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	//{
	//	_attackTile[i].attackTileFrameX = 0;
	//	_attackTile[i].attackTileFrameY = 0;
	//	_attackTile[i].attackTileType = ATTACKTILE_NONE;
	//}

	for (int i = 0; i < 49; i++)
	{
		if (_tempCharacter.attackArray[i] == 1)
		{
			_attackTile[i].attackTileFrameX = 2;
			_attackTile[i].attackTileFrameY = 0;
			_attackTile[i].attackTileType = ATTACKTILE_ATTACKRANGE;
		}
		else if (_tempCharacter.attackArray[i] != 1 && i != _characterTile)
		{
			_attackTile[i].attackTileFrameX = 0;
			_attackTile[i].attackTileFrameY = 0;
			_attackTile[i].attackTileType = ATTACKTILE_NONE;
		}
	}


	//for (int i = 0; i < _tempCharacter.attackTileVector.size(); i++)
	//{
	//	_attackTile[_tempCharacter.attackTileVector[i]].attackTileFrameX = 2;
	//	_attackTile[_tempCharacter.attackTileVector[i]].attackTileFrameY = 0;
	//	_attackTile[_tempCharacter.attackTileVector[i]].attackTileType = ATTACKTILE_ATTACKRANGE;
	//}
}

void characterEditor::faceSelect()
{	
	if (PtInRect(&_prevFaceRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_faceSelectNum <= 0)
				_faceSelectNum = 0;
			else
				_faceSelectNum--;
		}
	}
	else if (PtInRect(&_nextFaceRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_faceSelectNum >= _faceSelectVector.size() - 1)
				_faceSelectNum = _faceSelectVector.size() - 1;
			else
				_faceSelectNum++;
		}
	}
	_tempCharacter.characterFaceImage = _faceSelectVector.at(_faceSelectNum);
}
void characterEditor::characterSelect()
{
	if (PtInRect(&_prevCharacterRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_characterSelectNum <= 0)
				_characterSelectNum = 0;
			else
				_characterSelectNum--;
		}
	}
	else if (PtInRect(&_nextCharacterRect, m_ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_characterSelectNum >= _characterSelectVector.size() - 1)
				_characterSelectNum = _characterSelectVector.size() - 1;
			else
				_characterSelectNum++;
		}
	}
	_tempCharacter.characterMoveImage = _characterSelectVector.at(_characterSelectNum);
	_tempCharacter.characterAttackImage = _characterAttackVector.at(_characterSelectNum);
	_tempCharacter.characterDefImage = _characterDefVector.at(_characterSelectNum);
	_tempCharacter.characterDoneImage = _characterDoneVector.at(_characterSelectNum);
}


//되긴 되는 코드
//HRESULT characterEditor::init()
//{
//	//_nameBox;
//	//_classBox;
//	//_hpBox;
//	//_mpBox;
//	//_strBox;
//	//_dexBox;
//	//_intBox;
//	//_luckBox;
//	//_cmdBox;
//
//	//_atkBox;
//	//_mAtkBox;
//	//_defBox;
//	//_spdBox;
//	//_moraleBox;
//	//_moveBox;
//
//	//_increaseAtkBox;
//	//_increaseMAtkBox;
//	//_increaseDefBox;
//	//_increaseSpdBox;
//	//_increaseMoraleBox;
//	//_increaseMoveBox;
//	IMAGEMANAGER->addImage("characterEditorBackground", "images/유닛에디터.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
//	IMAGEMANAGER->addImage("Face0", "images/캐릭터 얼굴/0-0.bmp", 64, 80, true, RGB(255, 0, 255));
//	IMAGEMANAGER->addImage("Face1", "images/캐릭터 얼굴/1-1.bmp", 64, 80, true, RGB(255, 0, 255));
//	IMAGEMANAGER->addImage("Face2", "images/캐릭터 얼굴/10-1.bmp", 64, 80, true, RGB(255, 0, 255));
//	IMAGEMANAGER->addImage("Face3", "images/캐릭터 얼굴/11-1.bmp", 64, 80, true, RGB(255, 0, 255));
//	//IMAGEMANAGER->addImage("Face4", "images/캐릭터 얼굴/12-1.bmp", 64, 80, true, RGB(255, 0, 255));
//	//IMAGEMANAGER->addImage("Face5", "images/캐릭터 얼굴/13-1.bmp", 64, 80, true, RGB(255, 0, 255));
//
//	//_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face0", "images/캐릭터 얼굴/0-0.bmp", 64, 80, false, RGB(255, 0, 255)));
//	//_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face1", "images/캐릭터 얼굴/1-1.bmp", 64, 80, true, RGB(255, 0, 255)));
//	//_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face2", "images/캐릭터 얼굴/10-1_2.bmp", 64, 80, true, RGB(255, 0, 255)));
//	//_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face3", "images/캐릭터 얼굴/11-1.bmp", 64, 80, true, RGB(255, 0, 255)));
//
//	_nameBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 95, 80, 30, m_hWnd, (HMENU)0, m_hInstance, NULL);
//	_classBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 130, 80, 30, m_hWnd, (HMENU)1, m_hInstance, NULL);
//	_hpBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 265, 80, 30, m_hWnd, (HMENU)2, m_hInstance, NULL);
//	_mpBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 304, 80, 30, m_hWnd, (HMENU)3, m_hInstance, NULL);
//
//	_strBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 341, 80, 30, m_hWnd, (HMENU)4, m_hInstance, NULL);
//	_dexBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 380, 80, 30, m_hWnd, (HMENU)5, m_hInstance, NULL);
//	_intBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 419, 80, 30, m_hWnd, (HMENU)6, m_hInstance, NULL);
//	_luckBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 457, 80, 30, m_hWnd, (HMENU)7, m_hInstance, NULL);
//	_cmdBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 495, 80, 30, m_hWnd, (HMENU)8, m_hInstance, NULL);
//
//	_atkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 532, 80, 30, m_hWnd, (HMENU)9, m_hInstance, NULL);
//	_mAtkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 568, 80, 30, m_hWnd, (HMENU)10, m_hInstance, NULL);
//	_defBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 605, 80, 30, m_hWnd, (HMENU)11, m_hInstance, NULL);
//	_spdBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 642, 80, 30, m_hWnd, (HMENU)12, m_hInstance, NULL);
//	_moraleBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 678, 80, 30, m_hWnd, (HMENU)13, m_hInstance, NULL);
//	_moveBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 460, 716, 80, 30, m_hWnd, (HMENU)14, m_hInstance, NULL);
//
//	_increaseAtkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 529, 80, 30, m_hWnd, (HMENU)15, m_hInstance, NULL);
//	_increaseMAtkBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 567, 80, 30, m_hWnd, (HMENU)16, m_hInstance, NULL);
//	_increaseDefBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 605, 80, 30, m_hWnd, (HMENU)17, m_hInstance, NULL);
//	_increaseSpdBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 642, 80, 30, m_hWnd, (HMENU)18, m_hInstance, NULL);
//	_increaseMoraleBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 802, 679, 80, 30, m_hWnd, (HMENU)19, m_hInstance, NULL);
//	//_increaseMoveBox = CreateWindow("edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 100, 760, 70, 30, m_hWnd, (HMENU)20, m_hInstance, NULL);
//
//	_saveRect = RectMake(727, 88, 147, 60);
//	_loadRect = RectMake(727, 162, 147, 60);
//
//	_prevFaceRect = RectMake(210, 171, 22, 16);
//	_nextFaceRect = RectMake(252, 171, 22, 16);
//
//	_prevCharacterRect = RectMake(218, 869, 22, 16);
//	_nextCharacterRect = RectMake(244, 869, 22, 16);
//
//
//
//
//	_tempCharacter.characterFaceImage = IMAGEMANAGER->findImage("Face0");
//
//
//	//GetDlgItemText(_nameBox,;
//	//GetWindowText(_nameBox,)
//
//	return S_OK;
//}
//
//void characterEditor::release()
//{
//}
//
//void characterEditor::update()
//{
//
//	//_tempCharacter.name = GetWindowText(_nameBox, str, 128)/*+".dat"*/;
//	//GetWindowText(_nameBox, _tempCharacter.name, 128)/*+".dat"*/;
//	//strcat(_tempCharacter.name, ".dat");
//	//_tempCharacter.hp = GetDlgItemInt(m_hWnd, 2, NULL, false);
//	//_tempCharacter.mp = GetDlgItemInt(m_hWnd, 3, NULL, false);
//
//	//_tempCharacter.str = GetDlgItemInt(m_hWnd, 4, NULL, false);
//	//_tempCharacter.dex = GetDlgItemInt(m_hWnd, 5, NULL, false);
//	//_tempCharacter.intelligence = GetDlgItemInt(m_hWnd, 6, NULL, false);
//	//_tempCharacter.luck = GetDlgItemInt(m_hWnd, 7, NULL, false);
//	//_tempCharacter.cmd = GetDlgItemInt(m_hWnd, 8, NULL, false);
//
//	//_tempCharacter.atk = GetDlgItemInt(m_hWnd, 9, NULL, false);
//	//_tempCharacter.mAtk = GetDlgItemInt(m_hWnd, 10, NULL, false);
//	//_tempCharacter.def = GetDlgItemInt(m_hWnd, 11, NULL, false);
//	//_tempCharacter.spd = GetDlgItemInt(m_hWnd, 12, NULL, false);
//	//_tempCharacter.morale = GetDlgItemInt(m_hWnd, 13, NULL, false);
//	//_tempCharacter.move = GetDlgItemInt(m_hWnd, 14, NULL, false);
//
//	//_tempCharacter.increaseAtk = GetDlgItemInt(m_hWnd, 15, NULL, false);
//	//_tempCharacter.increaseMAtk = GetDlgItemInt(m_hWnd, 16, NULL, false);
//	//_tempCharacter.increaseDef = GetDlgItemInt(m_hWnd, 17, NULL, false);
//	//_tempCharacter.increaseSpd = GetDlgItemInt(m_hWnd, 18, NULL, false);
//	//_tempCharacter.increaseMorale = GetDlgItemInt(m_hWnd, 19, NULL, false);
//
//
//	//GetWindowText(_hpBox, , 128);
//	//GetWindowLong(_hpBox, _tempCharacter.hp);
//	//GetDlgItemInt(_hpBox, _tempCharacter.hp, false, false);
//	//SetWindowText(_mpBox, _itoa(_tempCharacter.hp, temp, 128));
//	//if (PtInRect(&_prevFaceRect, m_ptMouse))
//	//{
//	//	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//	//	{
//	//		if (_faceSelectNum <= 0)
//	//			_faceSelectNum = 0;
//	//		else
//	//			_faceSelectNum--;
//	//	}
//	//}
//	//else if (PtInRect(&_nextFaceRect, m_ptMouse))
//	//{
//	//	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//	//	{
//	//		if (_faceSelectNum >= 5)
//	//			_faceSelectNum = 5;
//	//		else
//	//			_faceSelectNum++;
//	//	}
//	//}
//	faceSelect();
//	characterSelect();
//	if (PtInRect(&_saveRect, m_ptMouse))
//	{
//		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//		{
//			save();
//		}
//	}
//	else if (PtInRect(&_loadRect, m_ptMouse))
//	{
//		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//		{
//			load();
//		}
//	}
//
//}
//
//void characterEditor::render()
//{
//	IMAGEMANAGER->render("characterEditorBackground", getMemDC());
//	//IMAGEMANAGER->render("Face1",getMemDC());
//	_tempCharacter.characterFaceImage->render(getMemDC(), 210, 88);
//	char str[128];
//	wsprintf(str, "_faceSelectVectorSize : %d", _faceSelectVector.size());
//	TextOut(getMemDC(), 0, 500, str, strlen(str));
//
//	//Rectangle(getMemDC(), _prevFaceRect.left, _prevFaceRect.top, _prevFaceRect.right, _prevFaceRect.bottom);
//	//Rectangle(getMemDC(), _nextFaceRect.left, _nextFaceRect.top, _nextFaceRect.right, _nextFaceRect.bottom);
//	//Rectangle(getMemDC(), _prevCharacterRect.left, _prevCharacterRect.top, _prevCharacterRect.right, _prevCharacterRect.bottom);
//	//Rectangle(getMemDC(), _nextCharacterRect.left, _nextCharacterRect.top, _nextCharacterRect.right, _nextCharacterRect.bottom);
//	//Rectangle(getMemDC(),300,)
//	//_tempCharacter.characterFaceImage->render(getMemDC(), );
//	//Rectangle(getMemDC(), _saveRect.left, _saveRect.top, _saveRect.right, _saveRect.bottom);
//	//Rectangle(getMemDC(), _loadRect.left, _loadRect.top, _loadRect.right, _loadRect.bottom);
//	//ShowWindow(_textBox, SW_SHOW);
//}
//
//void characterEditor::save()
//{
//	GetWindowText(_nameBox, _tempCharacter.name, 128)/*+".dat"*/;
//	//strcat(_tempCharacter.name, ".dat");
//	GetWindowText(_classBox, _tempCharacter.classType, 128)/*+".dat"*/;
//	_tempCharacter.hp = GetDlgItemInt(m_hWnd, 2, NULL, false);
//	_tempCharacter.mp = GetDlgItemInt(m_hWnd, 3, NULL, false);
//	//strcpy(_tempCharacter.faceImageKey, tempFaceLink);
//	//_tempCharacter.faceImageNum = _faceSelectNum;
//
//	_tempCharacter.str = GetDlgItemInt(m_hWnd, 4, NULL, false);
//	_tempCharacter.dex = GetDlgItemInt(m_hWnd, 5, NULL, false);
//	_tempCharacter.intelligence = GetDlgItemInt(m_hWnd, 6, NULL, false);
//	_tempCharacter.luck = GetDlgItemInt(m_hWnd, 7, NULL, false);
//	_tempCharacter.cmd = GetDlgItemInt(m_hWnd, 8, NULL, false);
//
//	_tempCharacter.atk = GetDlgItemInt(m_hWnd, 9, NULL, false);
//	_tempCharacter.mAtk = GetDlgItemInt(m_hWnd, 10, NULL, false);
//	_tempCharacter.def = GetDlgItemInt(m_hWnd, 11, NULL, false);
//	_tempCharacter.spd = GetDlgItemInt(m_hWnd, 12, NULL, false);
//	_tempCharacter.morale = GetDlgItemInt(m_hWnd, 13, NULL, false);
//	_tempCharacter.move = GetDlgItemInt(m_hWnd, 14, NULL, false);
//
//	_tempCharacter.increaseAtk = GetDlgItemInt(m_hWnd, 15, NULL, false);
//	_tempCharacter.increaseMAtk = GetDlgItemInt(m_hWnd, 16, NULL, false);
//	_tempCharacter.increaseDef = GetDlgItemInt(m_hWnd, 17, NULL, false);
//	_tempCharacter.increaseSpd = GetDlgItemInt(m_hWnd, 18, NULL, false);
//	_tempCharacter.increaseMorale = GetDlgItemInt(m_hWnd, 19, NULL, false);
//
//	strcpy(_fileName, _tempCharacter.name);
//	strcat(_fileName, ".dat");
//	file = CreateFile
//	(_fileName,//_tempCharacter.name,//_tempCharacter.name.c_str(),				//생성할 파일또는 열 장치나 파일이름
//		GENERIC_WRITE,			//파일이나 장치를 만들거나 열때 사용할 권한
//		0,						//파일 공유 모드입력
//		NULL,					//파일또는 장치를 열때 보안 및 특성
//		CREATE_ALWAYS,			//파일이나 장치를 열때 취할 행동
//		FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
//		NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
//
//	WriteFile(file, &_tempCharacter, sizeof(tagCharacter), &write, NULL);
//	CloseHandle(file);
//}
//
//void characterEditor::load()
//{
//	OPENFILENAME ofn;
//
//	char filePathSize[1024] = "";
//
//	ZeroMemory(&ofn, sizeof(OPENFILENAME));
//
//
//	ofn.lStructSize = sizeof(OPENFILENAME);//구조체 사이즈 지정
//	ofn.hwndOwner = NULL;//대화상자 소유자를 지정
//	ofn.lpstrFile = filePathSize;//파일이름 에디트에 처음 나타낼 파일명을 지정. 충분한버퍼가 있어야 한다.
//	ofn.nMaxFile = sizeof(filePathSize);
//	ofn.nFilterIndex = true;//파일 형식 콤보박스에서 사용할 필터의 인덱스를 지정
//	ofn.lpstrFileTitle = NULL;
//	ofn.nMaxFileTitle = NULL;
//	ofn.lpstrInitialDir = NULL;
//	ofn.lpstrFilter = (".dat");//이름(파일형식)
//
//
//	//대화상자의 모양과 동작을 지정
//	//OFN_PATHMUSTEXIST : 존재하는 경로와 파일만 입력
//	//OFN_FILEMUSTEXIST :존재하는 파일만 입력
//	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
//
//
//	if (GetOpenFileName(&ofn) == FALSE)return;
//
//
//	char temp[1024];
//
//
//	strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));
//	char* context = NULL;
//	char* token = strtok_s(temp, "\\", &context);
//
//	while (strlen(context))
//	{
//		token = strtok_s(NULL, "\\", &context);
//	}
//
//	file = CreateFile
//	(ofn.lpstrFile,				//생성할 파일또는 열 장치나 파일이름
//		GENERIC_READ,			//파일이나 장치를 만들거나 열때 사용할 권한
//		0,						//파일 공유 모드입력
//		NULL,					//파일또는 장치를 열때 보안 및 특성
//		OPEN_EXISTING,			//파일이나 장치를 열때 취할 행동
//		FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
//		NULL);					//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
//	ReadFile(file, &_tempCharacter, sizeof(tagCharacter), &read, NULL);
//	CloseHandle(file);
//
//
//	SetWindowText(_nameBox, _tempCharacter.name);
//	SetWindowText(_classBox, _tempCharacter.classType);
//
//	_tempCharacter.characterFaceImage = IMAGEMANAGER->findImage(_tempCharacter.faceImageKey);
//
//	SetDlgItemInt(m_hWnd, 2, _tempCharacter.hp, false);
//	SetDlgItemInt(m_hWnd, 3, _tempCharacter.mp, false);
//	SetDlgItemInt(m_hWnd, 4, _tempCharacter.str, false);
//	SetDlgItemInt(m_hWnd, 5, _tempCharacter.dex, false);
//	SetDlgItemInt(m_hWnd, 6, _tempCharacter.intelligence, false);
//	SetDlgItemInt(m_hWnd, 7, _tempCharacter.luck, false);
//	SetDlgItemInt(m_hWnd, 8, _tempCharacter.cmd, false);
//
//	SetDlgItemInt(m_hWnd, 9, _tempCharacter.atk, false);
//	SetDlgItemInt(m_hWnd, 10, _tempCharacter.mAtk, false);
//	SetDlgItemInt(m_hWnd, 11, _tempCharacter.def, false);
//	SetDlgItemInt(m_hWnd, 12, _tempCharacter.spd, false);
//	SetDlgItemInt(m_hWnd, 13, _tempCharacter.morale, false);
//	SetDlgItemInt(m_hWnd, 14, _tempCharacter.move, false);
//
//	SetDlgItemInt(m_hWnd, 15, _tempCharacter.increaseAtk, false);
//	SetDlgItemInt(m_hWnd, 16, _tempCharacter.increaseMAtk, false);
//	SetDlgItemInt(m_hWnd, 17, _tempCharacter.increaseDef, false);
//	SetDlgItemInt(m_hWnd, 18, _tempCharacter.increaseSpd, false);
//	SetDlgItemInt(m_hWnd, 19, _tempCharacter.increaseMorale, false);
//
//	//SOUNDMANAGER->addSound(키값, 파일 이름, bgm, loop);
//	//SOUNDMANAGER->addSound(token, ofn.lpstrFile, false, false);
//}
//
//void characterEditor::faceSelect()
//{
//	//char tempFaceLink[128] = "Face";
//	//char temp[128];
//	//if (PtInRect(&_prevFaceRect, m_ptMouse))
//	//{
//	//	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//	//	{
//	//		if (_faceSelectNum <= 0)
//	//			_faceSelectNum = 0;
//	//		else
//	//			_faceSelectNum--;
//	//	}
//	//}
//	//else if (PtInRect(&_nextFaceRect, m_ptMouse))
//	//{
//	//	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//	//	{
//	//		if (_faceSelectNum >= _faceSelectVector.size()-1)
//	//			_faceSelectNum = _faceSelectVector.size() - 1;
//	//		else
//	//			_faceSelectNum++;
//	//	}
//	//}
//	//strcat(tempFaceLink, itoa(_faceSelectNum,temp,128));
//	//_tempCharacter.characterFaceImage = IMAGEMANAGER->findImage(tempFaceLink);
//	//_tempCharacter.characterFaceImage = _faceSelectVector.at(_faceSelectNum);
//	//switch (_faceSelectNum)
//	//{
//
//	//}
//	//strcat("face",i)
//	char tempFaceLink[128] = "Face";
//	char temp[128];
//
//	if (PtInRect(&_prevFaceRect, m_ptMouse))
//	{
//		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//		{
//			if (_faceSelectNum <= 0)
//				_faceSelectNum = 0;
//			else
//				_faceSelectNum--;
//		}
//	}
//	else if (PtInRect(&_nextFaceRect, m_ptMouse))
//	{
//		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
//		{
//			if (_faceSelectNum >= _faceSelectVector.size() - 1)
//				_faceSelectNum = _faceSelectVector.size() - 1;
//			else
//				_faceSelectNum++;
//		}
//	}
//	_tempCharacter.faceImageNum = _faceSelectNum;
//	//strcat(tempFaceLink, itoa(_faceSelectNum, temp, 128));
//	strcat(tempFaceLink, itoa(_tempCharacter.faceImageNum, temp, 128));
//	//_tempCharacter.characterFaceImage = IMAGEMANAGER->findImage(tempFaceLink);
//	strcpy(_tempCharacter.faceImageKey, tempFaceLink);
//	//_tempCharacter.characterFaceImage = _faceSelectVector.at(_faceSelectNum);
//	//_tempCharacter.characterFaceImage = _faceSelectVector.at(1);
//}




//void characterEditor::characterSelect()
//{
//}

LRESULT characterEditor::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;

	//switch (iMessage)
	//{
	//case WM_LBUTTONDOWN:
	//	this->setMap();
	//	break;
	//case WM_MOUSEMOVE:
	//	m_ptMouse.x = LOWORD(lParam);
	//	m_ptMouse.y = HIWORD(lParam);
	//	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))this->setMap();
	//	break;
	//case WM_KEYDOWN:
	//	switch (wParam)
	//	{
	//	case VK_ESCAPE:
	//		PostQuitMessage(0);
	//		break;
	//	}
	//	break;
	//	//프로그램 실행중 사용자가 메뉴 항목을 선택하면 발생하는 메세지임.
	//case WM_COMMAND:
	//	switch (LOWORD(wParam))
	//	{
	//	case CTRL_SAVE:
	//		this->save();
	//		break;
	//	case CTRL_LOAD:
	//		this->load();
	//		InvalidateRect(hWnd, NULL, FALSE);
	//		break;
	//	default:
	//		this->setCtrSelect(LOWORD(wParam));
	//		break;
	//	}
	//	break;
	//case WM_DESTROY:
	//	PostQuitMessage(0);
	//	break;
	//}//end of switch

	//return (DefWindowProc(hWnd, iMessage, wParam, lParam));

	//PAINTSTRUCT ps;
	//HDC hdc;
	switch (iMessage)
	{
	case WM_COMMAND:
		break;
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

		//case WM_COMMAND:
		//	switch (LOWORD(wParam))
		//	{
		//	case CTRL_SAVE:
		//		this->save();
		//		break;
		//	case CTRL_LOAD:
		//		this->load();
		//		InvalidateRect(hWnd, NULL, FALSE);
		//		break;
		//	default:
		//		this->setCtrSelect(LOWORD(wParam));
		//		break;
		//	}
		//	break;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));

}

void characterEditor::tempFunction()
{

	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face0", "images/캐릭터 얼굴/0.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face1", "images/캐릭터 얼굴/1.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face2", "images/캐릭터 얼굴/2.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face3", "images/캐릭터 얼굴/3.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face4", "images/캐릭터 얼굴/4.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face5", "images/캐릭터 얼굴/5.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face6", "images/캐릭터 얼굴/6.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face7", "images/캐릭터 얼굴/7.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face8", "images/캐릭터 얼굴/8.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face9", "images/캐릭터 얼굴/9.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face10", "images/캐릭터 얼굴/10.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face11", "images/캐릭터 얼굴/11.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face12", "images/캐릭터 얼굴/12.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face13", "images/캐릭터 얼굴/13.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face14", "images/캐릭터 얼굴/14.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face15", "images/캐릭터 얼굴/15.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face16", "images/캐릭터 얼굴/16.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face17", "images/캐릭터 얼굴/17.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face18", "images/캐릭터 얼굴/18.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face19", "images/캐릭터 얼굴/19.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face20", "images/캐릭터 얼굴/20.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face21", "images/캐릭터 얼굴/21.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face22", "images/캐릭터 얼굴/22.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face23", "images/캐릭터 얼굴/23.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face24", "images/캐릭터 얼굴/24.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face25", "images/캐릭터 얼굴/25.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face26", "images/캐릭터 얼굴/26.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face27", "images/캐릭터 얼굴/27.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face28", "images/캐릭터 얼굴/28.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face29", "images/캐릭터 얼굴/29.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face30", "images/캐릭터 얼굴/30.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face31", "images/캐릭터 얼굴/31.bmp", 64, 80, true, RGB(255, 0, 255)));

	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit0", "images/유닛/0.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit1", "images/유닛/1.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit2", "images/유닛/2.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit3", "images/유닛/3.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit4", "images/유닛/4.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit5", "images/유닛/5.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit6", "images/유닛/6.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit7", "images/유닛/7.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit8", "images/유닛/8.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit9", "images/유닛/9.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit10", "images/유닛/10.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit11", "images/유닛/11.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit12", "images/유닛/12.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit13", "images/유닛/13.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit14", "images/유닛/14.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit15", "images/유닛/15.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit16", "images/유닛/16.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit17", "images/유닛/17.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit18", "images/유닛/18.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit19", "images/유닛/19.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit20", "images/유닛/20.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit21", "images/유닛/21.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit22", "images/유닛/22.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit23", "images/유닛/23.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit24", "images/유닛/24.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit25", "images/유닛/25.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit26", "images/유닛/26.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));
	_characterSelectVector.push_back(IMAGEMANAGER->addFrameImage("Unit27", "images/유닛/27.bmp", 48, 672, 1, 14, true, RGB(247, 0, 255)));

	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack0", "images/유닛/공격모션/0.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack1", "images/유닛/공격모션/1.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack2", "images/유닛/공격모션/2.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack3", "images/유닛/공격모션/3.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack4", "images/유닛/공격모션/4.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack5", "images/유닛/공격모션/5.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack6", "images/유닛/공격모션/6.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack7", "images/유닛/공격모션/7.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack8", "images/유닛/공격모션/8.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack9", "images/유닛/공격모션/9.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack10", "images/유닛/공격모션/10.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack11", "images/유닛/공격모션/11.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack12", "images/유닛/공격모션/12.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack13", "images/유닛/공격모션/13.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack14", "images/유닛/공격모션/14.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack15", "images/유닛/공격모션/15.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack16", "images/유닛/공격모션/16.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack17", "images/유닛/공격모션/17.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack18", "images/유닛/공격모션/18.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack19", "images/유닛/공격모션/19.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack20", "images/유닛/공격모션/20.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack21", "images/유닛/공격모션/21.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack22", "images/유닛/공격모션/22.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack23", "images/유닛/공격모션/23.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack24", "images/유닛/공격모션/24.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack25", "images/유닛/공격모션/25.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack26", "images/유닛/공격모션/26.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	_characterAttackVector.push_back(IMAGEMANAGER->addFrameImage("Attack27", "images/유닛/공격모션/27.bmp", 64, 1024, 1, 16, true, RGB(247, 0, 255)));
	
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def0", "images/유닛/막기모션/0.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def1", "images/유닛/막기모션/1.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def2", "images/유닛/막기모션/2.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def3", "images/유닛/막기모션/3.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def4", "images/유닛/막기모션/4.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def5", "images/유닛/막기모션/5.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def6", "images/유닛/막기모션/6.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def7", "images/유닛/막기모션/7.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def8", "images/유닛/막기모션/8.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def9", "images/유닛/막기모션/9.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def10", "images/유닛/막기모션/10.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def11", "images/유닛/막기모션/11.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def12", "images/유닛/막기모션/12.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def13", "images/유닛/막기모션/13.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def14", "images/유닛/막기모션/14.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def15", "images/유닛/막기모션/15.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def16", "images/유닛/막기모션/16.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def17", "images/유닛/막기모션/17.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def18", "images/유닛/막기모션/18.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def19", "images/유닛/막기모션/19.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def20", "images/유닛/막기모션/20.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def21", "images/유닛/막기모션/21.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def22", "images/유닛/막기모션/22.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def23", "images/유닛/막기모션/23.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def24", "images/유닛/막기모션/24.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def25", "images/유닛/막기모션/25.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def26", "images/유닛/막기모션/26.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	_characterDefVector.push_back(IMAGEMANAGER->addFrameImage("Def27", "images/유닛/막기모션/27.bmp", 48, 288, 1, 6, true, RGB(247, 0, 255)));
	
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done0", "images/유닛/대기상태/0.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done1", "images/유닛/대기상태/1.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done2", "images/유닛/대기상태/2.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done3", "images/유닛/대기상태/3.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done4", "images/유닛/대기상태/4.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done5", "images/유닛/대기상태/5.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done6", "images/유닛/대기상태/6.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done7", "images/유닛/대기상태/7.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done8", "images/유닛/대기상태/8.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done9", "images/유닛/대기상태/9.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done10", "images/유닛/대기상태/10.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done11", "images/유닛/대기상태/11.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done12", "images/유닛/대기상태/12.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done13", "images/유닛/대기상태/13.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done14", "images/유닛/대기상태/14.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done15", "images/유닛/대기상태/15.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done16", "images/유닛/대기상태/16.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done17", "images/유닛/대기상태/17.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done18", "images/유닛/대기상태/18.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done19", "images/유닛/대기상태/19.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done20", "images/유닛/대기상태/20.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done21", "images/유닛/대기상태/21.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done22", "images/유닛/대기상태/22.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done23", "images/유닛/대기상태/23.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done24", "images/유닛/대기상태/24.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done25", "images/유닛/대기상태/25.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done26", "images/유닛/대기상태/26.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));
	_characterDoneVector.push_back(IMAGEMANAGER->addFrameImage("Done27", "images/유닛/대기상태/27.bmp", 48, 192, 1, 4, true, RGB(247, 0, 255)));


}

void characterEditor::setAttackTile()
{

	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	{
		if (PtInRect(&_attackTile[i].rc, m_ptMouse) && i != _characterTile)
		{
			_attackTile[i].attackTileFrameX = 2;
			_attackTile[i].attackTileFrameY = 0;

			_attackTile[i].attackTileType = ATTACKTILE_ATTACKRANGE;

		}
		//InvalidateRect(m_hWnd, NULL, false);
		//break;
	}





}

void characterEditor::eraseAttackTile()
{
	for (int i = 0; i < ATTACKTILEX*ATTACKTILEY; i++)
	{
		if (PtInRect(&_attackTile[i].rc, m_ptMouse) && i != _characterTile)
		{
			_attackTile[i].attackTileFrameX = 0;
			_attackTile[i].attackTileFrameY = 0;

			_attackTile[i].attackTileType = ATTACKTILE_NONE;
		}
	}
}
