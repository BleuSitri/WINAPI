#pragma once
#include "gameNode.h"

#include "map1_1.h"
#include "item.h"
#include "shop.h"
#include "inventory.h"
#include "myArmyClass.h"

class mainScene : public gameNode
{
private:
	RECT exitRect;
	RECT battleRect;
	RECT itemRect;
	RECT buyRect;
	RECT sellRect;

	image* mainSceneImage;
	image* buyWeaponImage;
	image* buyPotionImage;
	image* sellWeaponImage;
	image* sellPotionImage;
	image* equipImage;
	image* checkImage;
	image* exitMouseOverImage;

	bool _isDebug;

	bool _isBuyShopOn;
	bool _isSellShopOn;
	bool _isInventoryOn;
	bool _isWeaponOn;
	bool _isPotionOn;

	RECT exitMenuRect;
	RECT exitMenuRect2;
	RECT nextRect;
	RECT prevRect;
	RECT weaponRect;
	RECT potionRect;

	RECT itemWeaponRect;
	RECT itemArmorRect;
	RECT itemAssistRect;

	item* _item;
	shop* _shop;
	inventory* _inventory;
	myArmyClass* _myArmyClass;

	vector<image*> _faceSelectVector;

	int gold;
	char str[128];

	bool _exitMouseOver;

	int _vectorCount;

	int increaseAtk;
	int increaseDef;

public:
	mainScene();
	~mainScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void equipCheck();

	void load();
	void tempFunction();


};

