#pragma once
#include"gameNode.h"
//#include"Character.h"
#include"player.h"
#include"bossClass.h"

#include "sceneTitle.h"
#include "scene1_1.h"
#include "scene1_2.h"
#include "scene1_3.h"
#include "scene1_4.h"
#include "bossIntro.h"
#include "bossScene.h"

#include "scene1.h"
#include "scene2.h"
class mainGame :  public gameNode
{
private:

	//rocket * _rocket;
	//enemyManager* _enemyManager;

	/*Character* _player;*/

	player* _player;
	bossClass* _boss;
	//scene1 * _scene1;
	sceneTitle* _sceneTitle;
	scene1_1 * _scene1_1;
	scene1_2 * _scene1_2;
	scene1_3 * _scene1_3;
	scene1_4 * _scene1_4;



public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	//void playerSetFlag(player* player);

	//void mouseMove(float speed);
	
};

