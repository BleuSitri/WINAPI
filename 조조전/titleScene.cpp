#include "stdafx.h"
#include "titleScene.h"



titleScene::titleScene()
{
}


titleScene::~titleScene()
{
}

HRESULT titleScene::init()
{
	IMAGEMANAGER->addImage("타이틀배경", "images/타이틀씬배경.bmp", 1176, 960, true, RGB(255, 0, 255));
	titleSceneImage = IMAGEMANAGER->addImage("타이틀씬", "images/타이틀씬3.bmp", 642, 444, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("옵션메뉴", "images/옵션메뉴.bmp", 176, 30, true, RGB(255, 0, 255));
	titleSceneImage->setX(267);
	titleSceneImage->setY(258);


	gameStartRect = RectMake(503, 415, IMAGEMANAGER->findImage("옵션메뉴")->getWidth(), IMAGEMANAGER->findImage("옵션메뉴")->getHeight());
	characterEditStartRect = RectMake(gameStartRect.left, gameStartRect.bottom + 1, IMAGEMANAGER->findImage("옵션메뉴")->getWidth(), IMAGEMANAGER->findImage("옵션메뉴")->getHeight());
	mapToolStartRect = RectMake(characterEditStartRect.left, characterEditStartRect.bottom + 1, IMAGEMANAGER->findImage("옵션메뉴")->getWidth(), IMAGEMANAGER->findImage("옵션메뉴")->getHeight());
	exitRect = RectMake(mapToolStartRect.left, mapToolStartRect.bottom + 1, IMAGEMANAGER->findImage("옵션메뉴")->getWidth(), IMAGEMANAGER->findImage("옵션메뉴")->getHeight());
	exitRect2 = RectMake(titleSceneImage->getX() + 1, titleSceneImage->getY() + 7, 30, 33);

	SCENEMANAGER->addScene("mapToolScene", new mapTool);
	SCENEMANAGER->addScene("characterEditorScene", new characterEditor);
	SCENEMANAGER->addScene("mainScene", new mainScene);


	return S_OK;
}

void titleScene::release()
{
}

void titleScene::update()
{
	wsprintf(gameStartStr, "게임 시작");
	wsprintf(characterEditStartStr, "캐릭터 편집");
	wsprintf(mapToolStartStr, "맵 편집");
	wsprintf(exitStr, "게임 종료");

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&gameStartRect, m_ptMouse))
		{
			SCENEMANAGER->changeScene("mainScene");
		}
		else if (PtInRect(&characterEditStartRect, m_ptMouse))
		{
			SCENEMANAGER->changeScene("characterEditorScene");
		}
		else if (PtInRect(&mapToolStartRect, m_ptMouse))
		{
			SCENEMANAGER->changeScene("mapToolScene");
		}
		else if (PtInRect(&exitRect, m_ptMouse))
		{
			PostQuitMessage(0);
		}
		else if (PtInRect(&exitRect2, m_ptMouse))
		{
			PostQuitMessage(0);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}
}

void titleScene::render()
{
	IMAGEMANAGER->render("타이틀배경", getMemDC());
	HFONT myFont = CreateFont(14, 0, 0, 0, 560, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "돋움");
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), myFont);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	titleSceneImage->render(getMemDC(), titleSceneImage->getX(), titleSceneImage->getY());
	IMAGEMANAGER->render("옵션메뉴", getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236, IMAGEMANAGER->findImage("타이틀씬")->getY() + 157);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236 + 53, IMAGEMANAGER->findImage("타이틀씬")->getY() + 165, gameStartStr, strlen(gameStartStr));
	IMAGEMANAGER->render("옵션메뉴", getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236, IMAGEMANAGER->findImage("타이틀씬")->getY() + 188);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236 + 46, IMAGEMANAGER->findImage("타이틀씬")->getY() + 196, characterEditStartStr, strlen(characterEditStartStr));
	IMAGEMANAGER->render("옵션메뉴", getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236, IMAGEMANAGER->findImage("타이틀씬")->getY() + 219);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236 + 61, IMAGEMANAGER->findImage("타이틀씬")->getY() + 227, mapToolStartStr, strlen(mapToolStartStr));
	IMAGEMANAGER->render("옵션메뉴", getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236, IMAGEMANAGER->findImage("타이틀씬")->getY() + 250);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("타이틀씬")->getX() + 236 + 53, IMAGEMANAGER->findImage("타이틀씬")->getY() + 258, exitStr, strlen(exitStr));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(myFont);

	if (_isDebug)
	{
		Rectangle(getMemDC(), gameStartRect.left, gameStartRect.top, gameStartRect.right, gameStartRect.bottom);
		Rectangle(getMemDC(), characterEditStartRect.left, characterEditStartRect.top, characterEditStartRect.right, characterEditStartRect.bottom);
		Rectangle(getMemDC(), mapToolStartRect.left, mapToolStartRect.top, mapToolStartRect.right, mapToolStartRect.bottom);
		Rectangle(getMemDC(), exitRect.left, exitRect.top, exitRect.right, exitRect.bottom);
		Rectangle(getMemDC(), exitRect2.left, exitRect2.top, exitRect2.right, exitRect2.bottom);
	}
}
