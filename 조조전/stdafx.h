// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include<commdlg.h>//�����ۿ�(openFileName)


//STL
#include<vector>
#include<map>
#include<string>
#include<stack>




// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

//======================================
//##���� ���� ��������� �̰��� �߰�����.##
//======================================
#include"commonMacroFunction.h"
#include"keyManager.h"
#include"imageManager.h"
#include"timeManager.h"
#include"sceneManager.h"
#include"soundManager.h"
#include"animationManager.h"
#include"effectManager.h"
#include"randomFunction.h"
#include"utils.h"
#include"textData.h"





using namespace UTIL;



//======================================
//##			�Ŵ�����			  ##
//======================================
#define KEYMANAGER				keyManager::getSingleton()
#define IMAGEMANAGER			imageManager::getSingleton()
#define TIMEMANAGER				timeManager::getSingleton()
#define SCENEMANAGER			sceneManager::getSingleton()
#define SOUNDMANAGER			soundManager::getSingleton()
#define ANIMATIONMANAGER		animationManager::getSingleton()
#define EFFECTMANAGER			effectManager::getSingleton()
#define RND						randomFunction::getSingleton()
#define TEXTDATA				textData::getSingleton()
//======================================
//##			�����ι�				  ##
//======================================

//#define WINNAME		(LPTSTR)(TEXT("���� ���α׷��� 18��"))
#define WINNAME		(LPTSTR)(TEXT("������"))
#define WINSTARTX   100
#define WINSTARTY   0
#define WINSIZEX	1176
#define	WINSIZEY	960
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

//======================================
//## ���ΰ��� ������� ����ϴ� �༮	##
//======================================
#define SAFE_DELETE(p) {if(p) {delete(p); (p) = nullptr;}}



//================================================
//## ��������(�ν��Ͻ�, ������ �ڵ�, ���콺 ��ǥ)	##
//================================================

extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;
