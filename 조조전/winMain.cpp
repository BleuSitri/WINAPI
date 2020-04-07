
#include"stdafx.h"
#include"mainGame.h"
//#include"mapTool.h"

//�ν��Ͻ�->�޸𸮻� �Ҵ�Ǿ� �������� ���α׷�
//OS Ȯ���ϱ� ���� ��
HINSTANCE m_hInstance;

//������ �ڵ�(���������δ� 32��Ʈ or 64��Ʈ�� ������)
//��� ���� -> ��󳢸� �����ϱ� ����, ���ڿ����� ������ �ӵ��� ������ �����ؼ�
HWND m_hWnd;
POINT m_ptMouse = { 0,0 };

mainGame mg;
//mapTool mt;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);
/*
������ API�� ũ�� WinMain, WndProc�ΰ��� �Լ��� �̷����
����.
winMain�� �츮�� �˰� �ִ� �����̶�� �����ϸ� �ǰ�

WndProc�� �����쿡�� �̷�� ���� ����,
�޽����� ó���Ѵٰ� �����ϸ� �ȴ�.


*/

//������ �����Լ�
//hInstance : �ν��Ͻ� �ڵ�
//hPrevInstance : ������ ����� �ν��Ͻ� �ڵ�(������ ������� ����)
//lpszCmdParam : ��������� �Էµ� ���α׷� �μ�
//nCmdShow : ���α׷��� ���۵� ����(�ּ�ȭ,����ũ�� ���)
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{

	//�ν��ͽ��� m_hInstance(��������) ����ش�
	//�ڵ� �ν��Ͻ�, ���α׷��� �ν��Ͻ� �ĺ���
	//���α׷� ��ü�� ��üȭ�� �ּ�, ���α׷� ��ü�� �ڵ�
	//�ڵ��̶�? �ü���� ���𰡸� �ĺ��ϱ� ���� Ű��
	m_hInstance = hInstance;

	//�������� ����
	//1. ������â ���� �� ȭ�鿡 ����
	//2. �޼��� ����

	//WNDCLASS : ������ â�� ������ �����ϱ� ���� ����ü
	//������â ����ü ���� �� �ʱ�ȭ
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;	//������ Ŭ�������� ����ϰ��� �ϴ� ������ �޸𸮾��� ����Ʈ ������ ����
	wndClass.cbWndExtra = 0;	//cbClsExtra �����ϵ� ���� �����쿡�� ����ϰ��� �ϴ� ������ �޸𸮾��� ����
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//������ �۾������� ĥ�� ��� �귯�ø� ����
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	ShowCursor(false);
	//wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);	//Ŭ���� Ŀ���� ����
	//wndClass.hCursor = (HCURSOR)LoadImage(NULL, "images/���콺Ŀ��.bmp", IMAGE_BITMAP, 26, 26, LR_DEFAULTCOLOR);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	//Ÿ��Ʋ���� �»�ܿ� ������ �����ܰ� �����찡 �ּ�ȭ �Ǿ����� ������ �������� ����
	wndClass.hInstance = hInstance;	//������ Ŭ������ ����� �������α׷��� �ν��Ͻ� �ڵ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;	//�޼����� ó���ϴ� �Լ��� ����(������ ���ν���)
	wndClass.lpszClassName = WINNAME;	//����ϰ��� �ϴ� ������ Ŭ���� �̸�
	wndClass.lpszMenuName = NULL;			//Ŭ�����κ��� ������� �����찡 ����� �޴��� ����
	wndClass.style = CS_HREDRAW | CS_VREDRAW;	//������ Ŭ������ ��Ÿ���� ����

												//������ Ŭ���� ���
												//����� ������ Ŭ������ Ư���� �����ϴ� WNDCLASS ����ü�� ������ ����
	RegisterClass(&wndClass);

	//������ â ����
	m_hWnd = CreateWindow(
		WINNAME,		//������ Ŭ������ �̸�
		WINNAME,		//������ Ÿ��Ʋ�� �̸�
		WS_OVERLAPPEDWINDOW,//������ ��Ÿ��
		WINSTARTX,				//������ ȭ���� x��ǥ
		WINSTARTY,				//������ ȭ���� y��ǥ
		WINSIZEX,				//������ ȭ���� ����ũ��
		WINSIZEY,				//������ ȭ���� ����ũ��
		NULL,				//�θ�������
		(HMENU)NULL,		//�޴��ڵ�
		hInstance,			//�ν��Ͻ� ����
		NULL);				//������� ����

							//ȭ�鿡 ������ �����ֱ�


							//ȭ�� �۾� ������ ���� ���
	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);


	ShowWindow(m_hWnd, nCmdShow);

	//���ΰ��� Ŭ������ �ʱ�ȭ�� �����ϸ� ���� ���Ѷ�
	if (FAILED(mg.init()))
	{

		return 0;
	}

	//if (FAILED(mt.init()))
	//{
	//	return 0;
	//}


	//MSG : �ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
	MSG message;

	//TranslateMessage : Ű���� �Է¸޼����� ó�� ���
	//�Էµ� Ű�� �������� Ȯ�� �� �빮��,�ҹ���,�ѱ�,���� ���
	//WM_CHAR �޼����� �߻���Ų��.

	//DispatchMessage : ������ ���ν����� ���޵� �޼����� ���� ������� 
	//�������ش�.


	/*
	GetMessage�� PeekMessage �� �Լ� ��� WinMain()���� �޼���ť�� ���� �޼����� �����ϴ� �Լ�
	GetMessage()�Լ��� �޼���ť�� �޼����� ������ �׳� �״�� ��ȯ ���� ��ȯ ������ �ʰ�
	�״�� �����·� �ִٰ� �޼����� ����� �ش� �޼����� �����ϰ� ��ȯ ������ 1�� �����Ѵ�.
	���� �޼����� ������ �׻� 1�� �����ϴ� �� �ƴϴ�. WM_QUIT �޼����� �߻��������� 0�� �����Ѵ�.


	�׿� ���� PeekMessage()�Լ��� GetMessage()�� �ٸ���
	�� �����Ӹ��� �Լ��� ����Ǹ� �޼��� ť�� �˻��ϰ� �׻� ��ȯ ������ 1�� ��ȯ �Ѵٴ� ���̴�.
	�� �����°� ���ٴ� ���̴�.
	�� �����Ӹ��� �Լ��� ����ǰ� �޼��� ť�� �˻��ϰ� �޼����� �ֵ� ���� �׻� 1�� ��ȯ�ϴ� ���̴�
	*/

	//���ӿ� ����
	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//�ʴ� 60���������� ������Ʈ ���Ѷ�
			TIMEMANAGER->update(60.0f);
			mg.update();
			mg.render();
			//mt.update();
			//mt.render();
		}
	}






	//GetMessage : ������
	//�޽��� ����
	//while (GetMessage(&message, 0, 0, 0))
	//{
	//	TranslateMessage(&message);//Ű���� �ԷµǴ� ���� �޽��� ó��
	//	DispatchMessage(&message);//������ ������� �޽����� �������ִ� ����
	//}
	//�޽��� ������ �� ���Ҵٸ� ����
	mg.release();
	//mt.release();
	return message.wParam;

}
//������ ���ν��� : �޼����� �ü���� ���� ������ �ü���� ȣ�����ش�.
//hWnd : ��� �����쿡�� �߻��� �޼������� ����
//iMessage : �޼��� ���� ��ȣ
//wParam : unsigned int ���콺 ��ư�� ����, Ű���� ����Ű�� ���¸� �����Ѵ�.
//lParam : unsigned long ���콺 Ŭ�� ��ǥ�� ����
//CALLBACK �Լ��� � �̺�Ʈ�� �߻� ���� �� ������ �˷��޶�� �ϴ� ��!(�� ȣ�� �Ǵ� ���̶�� ������)

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//if (mt.getIsMapToolSceneOn())
	//{
	//	return mt.MainProc(hWnd, iMessage, wParam, lParam);

	//}
	return mg.MainProc(hWnd, iMessage, wParam, lParam);

}

//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	return mt.MainProc(hWnd, iMessage, wParam, lParam);
//
//}

//if (SUCCEEDED(mt.init()))
//{
//	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//	{
//		return mt.MainProc(hWnd, iMessage, wParam, lParam);
//
//	}
//}




//=================================================================
//	## ������ ũ�� ���� ## (Ŭ���̾�Ʈ ������ ����� ��Ȯ�� ����ش�)
//=================================================================
void setWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, false);


	//�� RECT ������ ������ ������ ����
	SetWindowPos(m_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top),
		SWP_NOZORDER | SWP_NOMOVE);


}
