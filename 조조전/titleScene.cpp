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
	IMAGEMANAGER->addImage("Ÿ��Ʋ���", "images/Ÿ��Ʋ�����.bmp", 1176, 960, true, RGB(255, 0, 255));
	titleSceneImage = IMAGEMANAGER->addImage("Ÿ��Ʋ��", "images/Ÿ��Ʋ��3.bmp", 642, 444, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ɼǸ޴�", "images/�ɼǸ޴�.bmp", 176, 30, true, RGB(255, 0, 255));
	titleSceneImage->setX(267);
	titleSceneImage->setY(258);


	gameStartRect = RectMake(503, 415, IMAGEMANAGER->findImage("�ɼǸ޴�")->getWidth(), IMAGEMANAGER->findImage("�ɼǸ޴�")->getHeight());
	characterEditStartRect = RectMake(gameStartRect.left, gameStartRect.bottom + 1, IMAGEMANAGER->findImage("�ɼǸ޴�")->getWidth(), IMAGEMANAGER->findImage("�ɼǸ޴�")->getHeight());
	mapToolStartRect = RectMake(characterEditStartRect.left, characterEditStartRect.bottom + 1, IMAGEMANAGER->findImage("�ɼǸ޴�")->getWidth(), IMAGEMANAGER->findImage("�ɼǸ޴�")->getHeight());
	exitRect = RectMake(mapToolStartRect.left, mapToolStartRect.bottom + 1, IMAGEMANAGER->findImage("�ɼǸ޴�")->getWidth(), IMAGEMANAGER->findImage("�ɼǸ޴�")->getHeight());
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
	wsprintf(gameStartStr, "���� ����");
	wsprintf(characterEditStartStr, "ĳ���� ����");
	wsprintf(mapToolStartStr, "�� ����");
	wsprintf(exitStr, "���� ����");

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
	IMAGEMANAGER->render("Ÿ��Ʋ���", getMemDC());
	HFONT myFont = CreateFont(14, 0, 0, 0, 560, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "����");
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), myFont);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	titleSceneImage->render(getMemDC(), titleSceneImage->getX(), titleSceneImage->getY());
	IMAGEMANAGER->render("�ɼǸ޴�", getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 157);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236 + 53, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 165, gameStartStr, strlen(gameStartStr));
	IMAGEMANAGER->render("�ɼǸ޴�", getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 188);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236 + 46, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 196, characterEditStartStr, strlen(characterEditStartStr));
	IMAGEMANAGER->render("�ɼǸ޴�", getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 219);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236 + 61, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 227, mapToolStartStr, strlen(mapToolStartStr));
	IMAGEMANAGER->render("�ɼǸ޴�", getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 250);// , WINSIZEX / 2, WINSIZEY / 2);
	TextOut(getMemDC(), IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getX() + 236 + 53, IMAGEMANAGER->findImage("Ÿ��Ʋ��")->getY() + 258, exitStr, strlen(exitStr));
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
