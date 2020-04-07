#include "stdafx.h"
#include "mainScene.h"



mainScene::mainScene()
{
}


mainScene::~mainScene()
{
}

HRESULT mainScene::init()
{
	_item = new item;
	_item->init();

	_shop = new shop;
	_shop->init();

	_inventory = new inventory;
	_inventory->init();

	_myArmyClass = new myArmyClass;
	_myArmyClass->init();

	tempFunction();
	load();
	_vectorCount = 0;

	IMAGEMANAGER->addImage("Å¸ÀÌÆ²¾À¹è°æ", "images/Å¸ÀÌÆ²¾À¹è°æ.bmp", 1176, 960, true, RGB(255, 0, 255));
	buyWeaponImage = IMAGEMANAGER->addImage("±¸ÀÔ¾À_¹«±â", "images/±¸ÀÔ¾À_¹«±â.bmp", 595, 368, true, RGB(255, 0, 255));
	buyPotionImage = IMAGEMANAGER->addImage("±¸ÀÔ¾À_µµ±¸", "images/±¸ÀÔ¾À_µµ±¸.bmp", 595, 368, true, RGB(255, 0, 255));
	sellWeaponImage = IMAGEMANAGER->addImage("¸Å°¢¾À_¹«±â", "images/¸Å°¢¾À_¹«±â.bmp", 472, 368, true, RGB(255, 0, 255));
	sellPotionImage = IMAGEMANAGER->addImage("¸Å°¢¾À_µµ±¸", "images/¸Å°¢¾À_µµ±¸.bmp", 472, 368, true, RGB(255, 0, 255));
	equipImage = IMAGEMANAGER->addImage("Àåºñ¾À", "images/Àåºñ¾À.bmp", 589, 365, true, RGB(255, 0, 255));
	mainSceneImage = IMAGEMANAGER->addImage("¸ÞÀÎ¾À", "images/¸ÞÀÎ¾À.bmp", 644, 445, true, RGB(255, 0, 255));
	exitMouseOverImage = IMAGEMANAGER->addImage("X", "images/¸Þ´ºX.bmp", 31, 24, true, RGB(255, 0, 255));

	checkImage = IMAGEMANAGER->addImage("È®ÀÎÃ¢", "images/È®ÀÎÃ¢.bmp", 185, 69, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ÀåÂøO", "images/ÀåÂøO.bmp", 10, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÀåÂøX", "images/ÀåÂøX.bmp", 10, 10, true, RGB(255, 0, 255));


	mainSceneImage->setX(266);
	mainSceneImage->setY(257);
	equipImage->setX(mainSceneImage->getX() + 26);
	equipImage->setY(mainSceneImage->getY() + 15);
	buyWeaponImage->setX(mainSceneImage->getX() + 23);
	buyWeaponImage->setY(mainSceneImage->getY() + 13);
	buyPotionImage->setX(mainSceneImage->getX() + 23);
	buyPotionImage->setY(mainSceneImage->getY() + 13);
	sellWeaponImage->setX(mainSceneImage->getX() + 85);
	sellWeaponImage->setY(mainSceneImage->getY() + 13);
	sellPotionImage->setX(mainSceneImage->getX() + 85);
	sellPotionImage->setY(mainSceneImage->getY() + 13);
	checkImage->setX(mainSceneImage->getX() + 228);
	checkImage->setY(mainSceneImage->getY() + 163);


	exitRect = RectMake(mainSceneImage->getX() + 2, mainSceneImage->getY() + 8, 30, 32);
	battleRect = RectMake(mainSceneImage->getX() + 441, mainSceneImage->getY() + 393, 50, 50);
	itemRect = RectMake(mainSceneImage->getX() + 491, mainSceneImage->getY() + 393, 50, 50);
	buyRect = RectMake(mainSceneImage->getX() + 541, mainSceneImage->getY() + 393, 50, 50);
	sellRect = RectMake(mainSceneImage->getX() + 591, mainSceneImage->getY() + 393, 50, 50);
	gold = 8000;
	SCENEMANAGER->addScene("map1_1", new map1_1);
	return S_OK;
}

void mainScene::release()
{
}

void mainScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&exitRect, m_ptMouse))
		{
			PostQuitMessage(0);
		}
		else if (PtInRect(&battleRect, m_ptMouse))
		{
			SCENEMANAGER->changeScene("map1_1");
		}
		else if (PtInRect(&itemRect, m_ptMouse))
		{
			_isInventoryOn = true;

		}
		else if (PtInRect(&buyRect, m_ptMouse))
		{
			_isBuyShopOn = true;
			_isWeaponOn = true;
			_isPotionOn = false;
		}
		else if (PtInRect(&sellRect, m_ptMouse))
		{
			_isSellShopOn = true;
			_isWeaponOn = true;
			_isPotionOn = false;
		}
		else if (PtInRect(&exitMenuRect, m_ptMouse))
		{
			_isInventoryOn = false;
			_isBuyShopOn = false;
			_isSellShopOn = false;
			_isPotionOn = false;
			_vectorCount = 0;
			exitMenuRect = RectMake(0, 0, 0, 0);
			exitMenuRect2 = RectMake(0, 0, 0, 0);
			prevRect = RectMake(0, 0, 0, 0);
			nextRect = RectMake(0, 0, 0, 0);
			weaponRect = RectMake(0, 0, 0, 0);
			potionRect = RectMake(0, 0, 0, 0);
			itemWeaponRect = RectMake(0, 0, 0, 0);
			itemArmorRect = RectMake(0, 0, 0, 0);
			itemAssistRect = RectMake(0, 0, 0, 0);
			for (int i = 0; i < _shop->getShopItemVector().size(); i++)
			{
				_shop->setVectorRect(RectMake(0, 0, 0, 0), i);
			}
			for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
			{
				_inventory->setVectorRect(RectMake(0, 0, 0, 0), i);
			}

			//delete &exitMenuRect;
		}
		else if (PtInRect(&exitMenuRect2, m_ptMouse))
		{
			_isInventoryOn = false;
			_isBuyShopOn = false;
			_isSellShopOn = false;
			_isPotionOn = false;
			_vectorCount = 0;
			exitMenuRect = RectMake(0, 0, 0, 0);
			exitMenuRect2 = RectMake(0, 0, 0, 0);
			prevRect = RectMake(0, 0, 0, 0);
			nextRect = RectMake(0, 0, 0, 0);
			weaponRect = RectMake(0, 0, 0, 0);
			potionRect = RectMake(0, 0, 0, 0);
			itemWeaponRect = RectMake(0, 0, 0, 0);
			itemArmorRect = RectMake(0, 0, 0, 0);
			itemAssistRect = RectMake(0, 0, 0, 0);
			for (int i = 0; i < _shop->getShopItemVector().size(); i++)
			{
				_shop->setVectorRect(RectMake(0, 0, 0, 0), i);
			}
			for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
			{
				_inventory->setVectorRect(RectMake(0, 0, 0, 0), i);
			}

			//delete &exitMenuRect;
		}
		else if (PtInRect(&nextRect, m_ptMouse))
		{
			if (_vectorCount < _myArmyClass->getMyArmyVector().size() - 1)
			{
				_vectorCount++;
			}
			else if (_vectorCount >= _myArmyClass->getMyArmyVector().size())
			{
				_vectorCount = _myArmyClass->getMyArmyVector().size();
			}
		}
		else if (PtInRect(&prevRect, m_ptMouse))
		{
			if (_vectorCount > 0)
			{
				_vectorCount--;
			}
			else if (_vectorCount <= 0)
			{
				_vectorCount = 0;
			}
		}
		else if (PtInRect(&weaponRect, m_ptMouse))
		{
			_isWeaponOn = true;
			_isPotionOn = false;
			for (int i = 0; i < _shop->getShopItemVector().size(); i++)
			{
				_shop->setVectorRect(RectMake(0, 0, 0, 0), i);
			}
			for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
			{
				_inventory->setVectorRect(RectMake(0, 0, 0, 0), i);
			}
		}
		else if (PtInRect(&potionRect, m_ptMouse))
		{
			_isPotionOn = true;
			_isWeaponOn = false;
			for (int i = 0; i < _shop->getShopItemVector().size(); i++)
			{
				_shop->setVectorRect(RectMake(0, 0, 0, 0), i);
			}
			for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
			{
				_inventory->setVectorRect(RectMake(0, 0, 0, 0), i);
			}
		}
		//»¬¶§´Â ÁÙ¾îµå´Âµ¥ ´Ù½Ã ³¢¿ï¶§´Â ¾È´Ã¾î³­´Ù.
		if (_isInventoryOn)
		{
			for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
			{
				if (PtInRect(&_inventory->getInventoryVector()[i].rc, m_ptMouse) && _inventory->getInventoryVector()[i].canEquip)
				{
					_myArmyClass->equipItem(_inventory->equipitem(i), _vectorCount);
					if (_inventory->getBeforeItemBack())
					{
						_myArmyClass->minusStat(_inventory->getBeforeItem(), _vectorCount);
					}
				}
			}
			if (!_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector.empty())
			{
				for (int i = 0; i < _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector.size(); i++)
				{
					if (PtInRect(&itemWeaponRect, m_ptMouse))
					{
						_inventory->addItem(_myArmyClass->unEquipItem(i, _vectorCount));
					}
					else if (PtInRect(&itemArmorRect, m_ptMouse))
					{
						_inventory->addItem(_myArmyClass->unEquipItem(i, _vectorCount));
					}
					else if (PtInRect(&itemAssistRect, m_ptMouse))
					{
						_inventory->addItem(_myArmyClass->unEquipItem(i, _vectorCount));
					}
				}
			}



		}
		if (_isBuyShopOn)
		{
			for (int i = 0; i < _shop->getShopItemVector().size(); i++)
			{
				if (_isWeaponOn)
				{
					if (PtInRect(&_shop->getShopItemVector()[i].rc, m_ptMouse) && gold >= _shop->getShopItemVector()[i].price)
					{
						_inventory->addItem(_shop->getShopItemVector()[i]);
						//_inventory->setInventoryToTalNumber(i, 1);
						_shop->setShopToTalNumber(i, 1);
						//ÅäÅ» number´Â ÀÎº¥Åä¸®+Àåºñ°³¼ö·Î ¹Ù²ã¾ßÇÑ´Ù.
						gold -= _shop->getShopItemVector()[i].price;
					}
				}

			}
			if (_isPotionOn)
			{
				if (PtInRect(&_shop->getShopItemVector()[0].rc, m_ptMouse) && gold >= _shop->getShopItemVector()[9].price)
				{
					_inventory->addItem(_shop->getShopItemVector()[9]);
					_shop->setShopToTalNumber(9, 1);
					gold -= _shop->getShopItemVector()[9].price;
				}
			}
		}
		if (_isSellShopOn)
		{
			for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
			{
				if (_isWeaponOn)
				{
					if (PtInRect(&_inventory->getInventoryVector()[i].rc, m_ptMouse))
					{
						_inventory->sellItem(i);
						gold += _inventory->getInventoryVector()[i].price / 4;


					}
				}
				

			}
			
		}


	}



	if (_isInventoryOn)
	{
		exitMenuRect = RectMake(equipImage->getX() + 558, equipImage->getY() + 1, 31, 24);
		exitMenuRect2 = RectMake(equipImage->getX() + 288, equipImage->getY() + 335, 62, 23);
		//prevRect = RectMake(equipImage->getX() + 311, equipImage->getY() + 337, 75, 21);
		prevRect = RectMake(exitMenuRect2.right + 23, exitMenuRect2.top + 2, 75, 21);
		//nextRect = RectMake(equipImage->getX() + 387, equipImage->getY() + 337, 75, 21);
		nextRect = RectMake(prevRect.right + 1, prevRect.top, 75, 21);
		itemWeaponRect = RectMake(equipImage->getX() + 472, equipImage->getY() + 84, 32, 32);
		itemArmorRect = RectMake(equipImage->getX() + 472, equipImage->getY() + 180, 32, 32);
		itemAssistRect = RectMake(equipImage->getX() + 472, equipImage->getY() + 276, 32, 32);
		int rcItemCount = 0;
		for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
		{
			_inventory->setVectorRect(RectMake(0, 0, 0, 0), i);
			_inventory->setVectorRect(RectMake(buyWeaponImage->getX() + 33, buyWeaponImage->getY() + 90 - 23 + 16 * rcItemCount, 319, 16), rcItemCount);
			rcItemCount++;

		}


	}
	else if (_isBuyShopOn)
	{
		exitMenuRect = RectMake(buyWeaponImage->getX() + 563, buyWeaponImage->getY() + 1, 31, 24);
		exitMenuRect2 = RectMake(buyWeaponImage->getX() + 297, buyWeaponImage->getY() + 340, 62, 23);
		weaponRect = RectMake(buyWeaponImage->getX() + 11, buyWeaponImage->getY() + 45, 70, 22);
		potionRect = RectMake(buyWeaponImage->getX() + 81, buyWeaponImage->getY() + 45, 70, 22);
		prevRect = RectMake(exitMenuRect2.right + 17, exitMenuRect2.top, 60, 21);
		nextRect = RectMake(prevRect.right + 1, prevRect.top, 60, 21);
		int rcItemCount = 0;
		for (int i = 0; i < _shop->getShopItemVector().size(); i++)
		{

			_shop->setVectorRect(RectMake(0, 0, 0, 0), i);
			if (_isWeaponOn)
			{
				if (_shop->getShopItemVector()[i].itemType != ITEM_POTION)
				{
					_shop->setVectorRect(RectMake(buyWeaponImage->getX() + 33, buyWeaponImage->getY() + 90 + 16 * rcItemCount, 319, 16), rcItemCount);
					rcItemCount++;
				}

			}
			if (_isPotionOn)
			{
				if (_shop->getShopItemVector()[i].itemType == ITEM_POTION)
				{
					_shop->setVectorRect(RectMake(buyWeaponImage->getX() + 33, buyWeaponImage->getY() + 90 + 16 * rcItemCount, 319, 16), rcItemCount);
					rcItemCount++;
				}

			}
		}


	}
	else if (_isSellShopOn)
	{
		exitMenuRect = RectMake(sellWeaponImage->getX() + 440, sellWeaponImage->getY(), 31, 24);
		exitMenuRect2 = RectMake(sellWeaponImage->getX() + 387, sellWeaponImage->getY() + 340, 75, 23);
		weaponRect = RectMake(sellWeaponImage->getX() + 11, sellWeaponImage->getY() + 45, 70, 22);
		potionRect = RectMake(sellPotionImage->getX() + 81, sellPotionImage->getY() + 45, 70, 22);

		int rcItemCount = 0;
		for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
		{
			_inventory->setVectorRect(RectMake(0, 0, 0, 0), i);
			if (_isWeaponOn)
			{
				if (_inventory->getInventoryVector()[i].itemType != ITEM_POTION)
				{
					_inventory->setVectorRect(RectMake(sellWeaponImage->getX() + 33, sellWeaponImage->getY() + 90 + 16 * rcItemCount, 422, 16), rcItemCount);
					rcItemCount++;
				}

			}

			else if (_isPotionOn)
			{
				if (_inventory->getInventoryVector()[i].itemType == ITEM_POTION)
				{
					_inventory->setVectorRect(RectMake(sellWeaponImage->getX() + 33, sellWeaponImage->getY() + 90, 422, 16), rcItemCount);
					rcItemCount++;
				}

			}
		}
	}

	wsprintf(str, "%d", gold);
	if (PtInRect(&exitMenuRect, m_ptMouse))
	{
		_exitMouseOver = true;
	}
	else
	{
		_exitMouseOver = false;
	}

	equipCheck();


}

void mainScene::render()
{
	IMAGEMANAGER->render("Å¸ÀÌÆ²¾À¹è°æ", getMemDC());
	IMAGEMANAGER->render("¸ÞÀÎ¾À", getMemDC(), mainSceneImage->getX(), mainSceneImage->getY());


	if (_isInventoryOn)
	{
		equipImage->render(getMemDC(), equipImage->getX(), equipImage->getY());
	}

	else if (_isBuyShopOn)
	{
		if (_isWeaponOn)
		{
			buyWeaponImage->render(getMemDC(), buyWeaponImage->getX(), buyWeaponImage->getY());
		}
		else if (_isPotionOn)
		{
			buyPotionImage->render(getMemDC(), buyPotionImage->getX(), buyPotionImage->getY());
		}
		HFONT myFont1 = CreateFont(12, 0, 0, 0, 300, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "³ª´®°íµñ");
		HFONT oldFont1 = (HFONT)SelectObject(getMemDC(), myFont1);
		SetTextColor(getMemDC(), RGB(0, 0, 0));


		TextOut(getMemDC(), buyWeaponImage->getX() + 247, buyWeaponImage->getY() + 346, str, strlen(str));

		SelectObject(getMemDC(), oldFont1);
		DeleteObject(myFont1);
	}
	else if (_isSellShopOn)
	{
		if (_isWeaponOn)
		{
			sellWeaponImage->render(getMemDC(), sellWeaponImage->getX(), sellWeaponImage->getY());
		}
		else if (_isPotionOn)
		{
			sellPotionImage->render(getMemDC(), sellPotionImage->getX(), sellPotionImage->getY());
		}
		HFONT myFont1 = CreateFont(12, 0, 0, 0, 300, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "³ª´®°íµñ");
		HFONT oldFont1 = (HFONT)SelectObject(getMemDC(), myFont1);
		SetTextColor(getMemDC(), RGB(0, 0, 0));


		TextOut(getMemDC(), sellWeaponImage->getX() + 329, sellWeaponImage->getY() + 346, str, strlen(str));

		SelectObject(getMemDC(), oldFont1);
		DeleteObject(myFont1);
	}
	if (_exitMouseOver)
	{
		exitMouseOverImage->render(getMemDC(), exitMenuRect.left, exitMenuRect.top);
	}
	if (_isDebug)
	{
		Rectangle(getMemDC(), exitRect.left, exitRect.top, exitRect.right, exitRect.bottom);
		Rectangle(getMemDC(), battleRect.left, battleRect.top, battleRect.right, battleRect.bottom);
		Rectangle(getMemDC(), itemRect.left, itemRect.top, itemRect.right, itemRect.bottom);
		Rectangle(getMemDC(), buyRect.left, buyRect.top, buyRect.right, buyRect.bottom);
		Rectangle(getMemDC(), sellRect.left, sellRect.top, sellRect.right, sellRect.bottom);
		Rectangle(getMemDC(), exitMenuRect.left, exitMenuRect.top, exitMenuRect.right, exitMenuRect.bottom);
		Rectangle(getMemDC(), exitMenuRect2.left, exitMenuRect2.top, exitMenuRect2.right, exitMenuRect2.bottom);
		Rectangle(getMemDC(), prevRect.left, prevRect.top, prevRect.right, prevRect.bottom);
		Rectangle(getMemDC(), nextRect.left, nextRect.top, nextRect.right, nextRect.bottom);
		Rectangle(getMemDC(), weaponRect.left, weaponRect.top, weaponRect.right, weaponRect.bottom);
		Rectangle(getMemDC(), potionRect.left, potionRect.top, potionRect.right, potionRect.bottom);
		Rectangle(getMemDC(), itemWeaponRect.left, itemWeaponRect.top, itemWeaponRect.right, itemWeaponRect.bottom);
		Rectangle(getMemDC(), itemArmorRect.left, itemArmorRect.top, itemArmorRect.right, itemArmorRect.bottom);
		Rectangle(getMemDC(), itemAssistRect.left, itemAssistRect.top, itemAssistRect.right, itemAssistRect.bottom);

		for (int i = 0; i < _shop->getShopItemVector().size(); i++)
		{
			char str[128];
			Rectangle(getMemDC(), _shop->getShopItemVector()[i].rc.left, _shop->getShopItemVector()[i].rc.top, _shop->getShopItemVector()[i].rc.right, _shop->getShopItemVector()[i].rc.bottom);
			wsprintf(str, "%d", i);
			TextOut(getMemDC(), 0, 500 + 10 * i, str, strlen(str));
		}
		for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
		{
			Rectangle(getMemDC(), _inventory->getInventoryVector()[i].rc.left, _inventory->getInventoryVector()[i].rc.top, _inventory->getInventoryVector()[i].rc.right, _inventory->getInventoryVector()[i].rc.bottom);
		}
	}
	HFONT myFont2 = CreateFont(12, 0, 0, 0, 300, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, "³ª´®°íµñ");
	HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), myFont2);
	SetTextColor(getMemDC(), RGB(0, 0, 0));


	if (_isInventoryOn)
	{
		int itemCount = 0;
		for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
		{
			if (_item->_getItemVector()[i].itemType == ITEM_POTION) continue;
			char itemName[128];
			char itemLv[128];
			char itemExp[128];
			char itemStat[128];
			//char itemAttr[128];
			if (_item->_getItemVector()[i].itemType != ITEM_POTION)
			{
				//_item->_getItemVector()[i].itemIcon->render(getMemDC(), equipImage->getX() + 17, equipImage->getY() + 65 + 16 * itemCount, 16, 16);
				wsprintf(itemName, "%s", _inventory->getInventoryVector()[i].name);
				TextOut(getMemDC(), equipImage->getX() + 35, equipImage->getY() + 65 + 16 * itemCount, itemName, strlen(itemName));

				wsprintf(itemLv, "%d", _inventory->getInventoryVector()[i].level);
				TextOut(getMemDC(), equipImage->getX() + 203, equipImage->getY() + 65 + 16 * itemCount, itemLv, strlen(itemLv));

				wsprintf(itemExp, "%d", _inventory->getInventoryVector()[i].exp);
				TextOut(getMemDC(), equipImage->getX() + 235, equipImage->getY() + 65 + 16 * itemCount, itemExp, strlen(itemExp));

				wsprintf(itemStat, "+%d", _inventory->getInventoryVector()[i].stat);
				TextOut(getMemDC(), equipImage->getX() + 270, equipImage->getY() + 65 + 16 * itemCount, itemStat, strlen(itemStat));

				if (_inventory->getInventoryVector()[i].canEquip)
					IMAGEMANAGER->render("ÀåÂøO", getMemDC(), equipImage->getX() + 318, equipImage->getY() + 65 + 16 * itemCount);
				else if (!_inventory->getInventoryVector()[i].canEquip)
					IMAGEMANAGER->render("ÀåÂøX", getMemDC(), equipImage->getX() + 318, equipImage->getY() + 65 + 16 * itemCount);

				for (int i = 0; i < _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector.size(); i++)
				{
					char itemNameWeapon[128];
					char itemNameArmor[128];
					char itemNameAssist[128];
					char itemAtk[128];
					char itemDef[128];
					char itemAssist[128];
					if (_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_SWORD ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_BOW ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_FAN ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_SPEAR)
					{
						wsprintf(itemNameWeapon, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].name);
						wsprintf(itemAtk, "+%d", _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].stat);
						increaseAtk = _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].stat;
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemImage->render(getMemDC(), equipImage->getX() + 472, equipImage->getY() + 84);
						TextOut(getMemDC(), equipImage->getX() + 513, equipImage->getY() + 122, itemAtk, strlen(itemAtk));
						TextOut(getMemDC(), equipImage->getX() + 513, equipImage->getY() + 65, itemNameWeapon, strlen(itemNameWeapon));
					}
					else if (_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_ARMOR ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_CLOTH)
					{
						wsprintf(itemNameArmor, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].name);
						wsprintf(itemDef, "+%d", _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].stat);
						increaseDef = _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].stat;
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemImage->render(getMemDC(), equipImage->getX() + 472, equipImage->getY() + 180);
						TextOut(getMemDC(), equipImage->getX() + 513, equipImage->getY() + 218, itemDef, strlen(itemDef));
						TextOut(getMemDC(), equipImage->getX() + 513, equipImage->getY() + 161, itemNameArmor, strlen(itemNameArmor));
					}
					else if (_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_ASSIST)
					{
						wsprintf(itemNameAssist, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].name);
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemImage->render(getMemDC(), equipImage->getX() + 472, equipImage->getY() + 276);
						TextOut(getMemDC(), equipImage->getX() + 513, equipImage->getY() + 257, itemNameAssist, strlen(itemNameAssist));
					}
				}

			}



			switch (_inventory->getInventoryVector()[i].itemType)
			{
			case ITEM_SWORD:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "°Ë", strlen("°Ë"));
				break;
			case ITEM_SPEAR:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "Ã¢", strlen("Ã¢"));
				break;
			case ITEM_BOW:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "È°", strlen("È°"));
				break;
			case ITEM_FAN:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "ºÎÃ¤", strlen("ºÎÃ¤"));
				break;
			case ITEM_ARMOR:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "°©¿Ê", strlen("°©¿Ê"));
				break;
			case ITEM_CLOTH:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "¿Ê", strlen("¿Ê"));
				break;
			case ITEM_ASSIST:
				TextOut(getMemDC(), equipImage->getX() + 155, equipImage->getY() + 65 + 16 * itemCount, "º¸Á¶", strlen("º¸Á¶"));
				break;
			}
			itemCount++;
		}


		char myArmyName[128];
		char myArmyClassType[128];
		char myArmyLv[128];
		char myArmyHp[128];
		char myArmyMp[128];
		char myArmyAtk[128];
		char myArmyIntelligence[128];
		char myArmyDef[128];
		char myArmyDex[128];
		char myArmyMoreale[128];
		char myArmyMove[128];
		wsprintf(myArmyName, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].name);
		wsprintf(myArmyClassType, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].classType);
		wsprintf(myArmyLv, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].level);
		wsprintf(myArmyHp, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].hp);
		wsprintf(myArmyMp, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].mp);
		wsprintf(myArmyAtk, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].atk);
		wsprintf(myArmyIntelligence, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].intelligence);
		wsprintf(myArmyDef, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].def);
		wsprintf(myArmyDex, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].dex);
		wsprintf(myArmyMoreale, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].morale);
		wsprintf(myArmyMove, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].move);
		_myArmyClass->getMyArmyVector()[_vectorCount].characterFaceImage->render(getMemDC(), equipImage->getX() + 383, equipImage->getY() + 62);
		TextOut(getMemDC(), equipImage->getX() + 400, equipImage->getY() + 39, myArmyName, strlen(myArmyName));
		TextOut(getMemDC(), equipImage->getX() + 460, equipImage->getY() + 39, myArmyClassType, strlen(myArmyClassType));
		TextOut(getMemDC(), equipImage->getX() + 539, equipImage->getY() + 38, myArmyLv, strlen(myArmyLv));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 154, myArmyHp, strlen(myArmyHp));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 175, myArmyMp, strlen(myArmyMp));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 205, myArmyAtk, strlen(myArmyAtk));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 226, myArmyIntelligence, strlen(myArmyIntelligence));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 247, myArmyDef, strlen(myArmyDef));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 268, myArmyDex, strlen(myArmyDex));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 289, myArmyMoreale, strlen(myArmyMoreale));
		TextOut(getMemDC(), equipImage->getX() + 415, equipImage->getY() + 310, myArmyMove, strlen(myArmyMove));
	}


	else if (_isBuyShopOn)
	{
		int itemCount = 0;
		for (int i = 0; i < _shop->getShopItemVector().size(); i++)
		{

			char itemName[128];
			char itemLv[128];
			char itemExp[128];
			char itemStat[128];
			char itemPrice[128];
			char totalNumber[128];

			if (_isWeaponOn)
			{
				if (_shop->getShopItemVector()[i].itemType == ITEM_POTION)continue;
				_shop->getShopItemVector()[i].itemIcon->render(getMemDC(), buyWeaponImage->getX() + 17, buyWeaponImage->getY() + 90 + 16 * itemCount, 16, 16);
				wsprintf(itemName, "%s", _shop->getShopItemVector()[i].name);
				TextOut(getMemDC(), buyWeaponImage->getX() + 33, buyWeaponImage->getY() + 90 + 16 * itemCount, itemName, strlen(itemName));

				//Àåºñ ¿©ºÎ : 175

				//Àç°í(Âø¿ë¾ÈÇÑ °³¼ö)
				//ÃÑ¼ö(ÀüÃ¼ °³¼ö)

				wsprintf(totalNumber, "%d", _shop->getShopItemVector()[i].totalNumber);
				TextOut(getMemDC(), buyWeaponImage->getX() + 285, buyWeaponImage->getY() + 90 + 16 * itemCount, totalNumber, strlen(totalNumber));

				wsprintf(itemStat, "+%d", _shop->getShopItemVector()[i].stat);
				TextOut(getMemDC(), buyWeaponImage->getX() + 215, buyWeaponImage->getY() + 90 + 16 * itemCount, itemStat, strlen(itemStat));

				wsprintf(itemPrice, "%d", _shop->getShopItemVector()[i].price);
				TextOut(getMemDC(), buyWeaponImage->getX() + 327, buyWeaponImage->getY() + 90 + 16 * itemCount, itemPrice, strlen(itemPrice));

				if (_shop->getShopItemVector()[i].canEquip)
					IMAGEMANAGER->render("ÀåÂøO", getMemDC(), buyWeaponImage->getX() + 177, buyWeaponImage->getY() + 90 + 16 * itemCount);
				else if (!_shop->getShopItemVector()[i].canEquip)
					IMAGEMANAGER->render("ÀåÂøX", getMemDC(), buyWeaponImage->getX() + 177, buyWeaponImage->getY() + 90 + 16 * itemCount);

				for (int i = 0; i < _myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector.size(); i++)
				{
					if (_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_SWORD ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_BOW ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_FAN ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_SPEAR)
					{
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemImage->render(getMemDC(), equipImage->getX() + 472, equipImage->getY() + 84);
					}
					else if (_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_ARMOR ||
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_CLOTH)
					{
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemImage->render(getMemDC(), equipImage->getX() + 472, equipImage->getY() + 180);
					}
					else if (_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemType == ITEM_ASSIST)
					{
						_myArmyClass->getMyArmyVector()[_vectorCount].characterItemVector[i].itemImage->render(getMemDC(), equipImage->getX() + 472, equipImage->getY() + 276);
					}
				}

				switch (_shop->getShopItemVector()[i].itemType)
				{
				case ITEM_SWORD:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "°Ë", strlen("°Ë"));
					break;
				case ITEM_SPEAR:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "Ã¢", strlen("Ã¢"));
					break;
				case ITEM_BOW:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "È°", strlen("È°"));
					break;
				case ITEM_FAN:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "ºÎÃ¤", strlen("ºÎÃ¤"));
					break;
				case ITEM_ARMOR:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "°©¿Ê", strlen("°©¿Ê"));
					break;
				case ITEM_CLOTH:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "¿Ê", strlen("¿Ê"));
					break;
				case ITEM_ASSIST:
					TextOut(getMemDC(), buyWeaponImage->getX() + 135, buyWeaponImage->getY() + 90 + 16 * itemCount, "º¸Á¶", strlen("º¸Á¶"));
					break;
				}
				itemCount++;

				char myArmyName[128];
				char myArmyClassType[128];
				char myArmyLv[128];
				char myArmyHp[128];
				char myArmyMp[128];
				char myArmyAtk[128];
				char myArmyIntelligence[128];
				char myArmyDef[128];
				char myArmyDex[128];
				char myArmyMoreale[128];
				char myArmyMove[128];
				wsprintf(myArmyName, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].name);
				wsprintf(myArmyClassType, "%s", _myArmyClass->getMyArmyVector()[_vectorCount].classType);
				wsprintf(myArmyLv, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].level);
				wsprintf(myArmyHp, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].hp);
				wsprintf(myArmyMp, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].mp);
				wsprintf(myArmyAtk, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].atk);
				wsprintf(myArmyIntelligence, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].intelligence);
				wsprintf(myArmyDef, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].def);
				wsprintf(myArmyDex, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].dex);
				wsprintf(myArmyMoreale, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].morale);
				wsprintf(myArmyMove, "%d", _myArmyClass->getMyArmyVector()[_vectorCount].move);
				_myArmyClass->getMyArmyVector()[_vectorCount].characterFaceImage->render(getMemDC(), buyWeaponImage->getX() + 389, buyWeaponImage->getY() + 61);
				TextOut(getMemDC(), buyWeaponImage->getX() + 408, buyWeaponImage->getY() + 38, myArmyName, strlen(myArmyName));
				TextOut(getMemDC(), buyWeaponImage->getX() + 468, buyWeaponImage->getY() + 38, myArmyClassType, strlen(myArmyClassType));
				TextOut(getMemDC(), buyWeaponImage->getX() + 545, buyWeaponImage->getY() + 37, myArmyLv, strlen(myArmyLv));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 153, myArmyHp, strlen(myArmyHp));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 174, myArmyMp, strlen(myArmyMp));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 204, myArmyAtk, strlen(myArmyAtk));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 225, myArmyIntelligence, strlen(myArmyIntelligence));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 246, myArmyDef, strlen(myArmyDef));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 267, myArmyDex, strlen(myArmyDex));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 288, myArmyMoreale, strlen(myArmyMoreale));
				TextOut(getMemDC(), buyWeaponImage->getX() + 421, buyWeaponImage->getY() + 309, myArmyMove, strlen(myArmyMove));


			}
			else if (_isPotionOn)
			{
				itemCount = 0;
				if (_shop->getShopItemVector()[i].itemType == ITEM_POTION)
				{
					_shop->getShopItemVector()[i].itemIcon->render(getMemDC(), buyWeaponImage->getX() + 17, buyWeaponImage->getY() + 90 + 16 * itemCount, 16, 16);
					wsprintf(itemName, "%s", _shop->getShopItemVector()[i].name);
					TextOut(getMemDC(), buyWeaponImage->getX() + 35, buyWeaponImage->getY() + 90 + 16 * itemCount, itemName, strlen(itemName));



					wsprintf(itemStat, "+%d", _shop->getShopItemVector()[i].stat);
					TextOut(getMemDC(), buyWeaponImage->getX() + 255, buyWeaponImage->getY() + 90 + 16 * itemCount, itemStat, strlen(itemStat));
					TextOut(getMemDC(), buyWeaponImage->getX() + 140, buyWeaponImage->getY() + 90 + 16 * itemCount, "HPÈ¸º¹", strlen("HPÈ¸º¹"));

					wsprintf(itemPrice, "%d", _shop->getShopItemVector()[i].price);
					TextOut(getMemDC(), buyWeaponImage->getX() + 327, buyWeaponImage->getY() + 90 + 16 * itemCount, itemPrice, strlen(itemPrice));
				}
				itemCount++;
			}
		}

	}




	else if (_isSellShopOn)
	{
		char itemName[128];
		char itemLv[128];
		char itemExp[128];
		char itemStat[128];
		char itemPrice[128];
		char itemTotalNumber[128];
		int itemCount = 0;
		for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
		{



			if (_isWeaponOn)
			{
				if (_inventory->getInventoryVector()[i].itemType == ITEM_POTION)continue;
				_inventory->getInventoryVector()[i].itemIcon->render(getMemDC(), sellWeaponImage->getX() + 17, sellWeaponImage->getY() + 90 + 16 * itemCount, 16, 16);// , 0, 0, 16, 16);
				wsprintf(itemName, "%s", _inventory->getInventoryVector()[i].name);
				
				
				TextOut(getMemDC(), sellWeaponImage->getX() + 33, sellWeaponImage->getY() + 90 + 16 * itemCount, itemName, strlen(itemName));

				wsprintf(itemLv, "%d", _inventory->getInventoryVector()[i].level);
				TextOut(getMemDC(), sellWeaponImage->getX() + 255, sellWeaponImage->getY() + 90 + 16 * itemCount, itemLv, strlen(itemLv));

				wsprintf(itemExp, "%d", _inventory->getInventoryVector()[i].exp);
				TextOut(getMemDC(), sellWeaponImage->getX() + 300, sellWeaponImage->getY() + 90 + 16 * itemCount, itemExp, strlen(itemExp));
				//Àåºñ ¿©ºÎ : 175

				//Àç°í(Âø¿ë¾ÈÇÑ °³¼ö)
				//ÃÑ¼ö(ÀüÃ¼ °³¼ö)
				wsprintf(itemStat, "+%d", _inventory->getInventoryVector()[i].stat);
				TextOut(getMemDC(), sellWeaponImage->getX() + 347, sellWeaponImage->getY() + 90 + 16 * itemCount, itemStat, strlen(itemStat));

				wsprintf(itemPrice, "%d", _inventory->getInventoryVector()[i].price / 4);
				TextOut(getMemDC(), sellWeaponImage->getX() + 405, sellWeaponImage->getY() + 90 + 16 * itemCount, itemPrice, strlen(itemPrice));


				switch (_inventory->getInventoryVector()[i].itemType)
				{
				case ITEM_SWORD:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "°Ë", strlen("°Ë"));
					break;
				case ITEM_SPEAR:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "Ã¢", strlen("Ã¢"));
					break;
				case ITEM_BOW:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "È°", strlen("È°"));
					break;
				case ITEM_FAN:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "ºÎÃ¤", strlen("ºÎÃ¤"));
					break;
				case ITEM_ARMOR:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "°©¿Ê", strlen("°©¿Ê"));
					break;
				case ITEM_CLOTH:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "¿Ê", strlen("¿Ê"));
					break;
				case ITEM_ASSIST:
					TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90 + 16 * itemCount, "º¸Á¶", strlen("º¸Á¶"));
					break;
				}
				itemCount++;
			}
			else if (_isPotionOn)
			{
				itemCount = 0;
				if (_inventory->getInventoryVector()[i].itemType == ITEM_POTION)
				{
					_inventory->getInventoryVector()[i].itemIcon->render(getMemDC(), sellWeaponImage->getX() + 17, sellWeaponImage->getY() + 90 + 16 * itemCount, 16, 16);// , 0, 0, 16, 16);
					wsprintf(itemName, "%s", _inventory->getInventoryVector()[i].name);
					


					wsprintf(itemStat, "+%d", _inventory->getInventoryVector()[i].stat);


					wsprintf(itemTotalNumber, "%d", _inventory->getInventoryVector()[i].totalNumber);


					wsprintf(itemPrice, "%d", _inventory->getInventoryVector()[i].price);

				}
				itemCount++;
			}
		}
		if (_isPotionOn)
		{

			TextOut(getMemDC(), sellWeaponImage->getX() + 383, sellWeaponImage->getY() + 90, itemTotalNumber, strlen(itemTotalNumber));
			TextOut(getMemDC(), sellWeaponImage->getX() + 423, sellWeaponImage->getY() + 90, itemPrice, strlen(itemPrice));
			TextOut(getMemDC(), sellWeaponImage->getX() + 325, sellWeaponImage->getY() + 90, itemStat, strlen(itemStat));
			TextOut(getMemDC(), sellWeaponImage->getX() + 195, sellWeaponImage->getY() + 90, "HPÈ¸º¹", strlen("HPÈ¸º¹"));
			TextOut(getMemDC(), sellWeaponImage->getX() + 33, sellWeaponImage->getY() + 90, itemName, strlen(itemName));
		}

	}

	SelectObject(getMemDC(), oldFont2);
	DeleteObject(myFont2);



}

void mainScene::equipCheck()
{
	for (int i = 0; i < _inventory->getInventoryVector().size(); i++)
	{
		if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "±Ãº´") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_BOW)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ARMOR)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "±º¿õ") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_SWORD)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ARMOR)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "°æº¸º´") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_SWORD)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ARMOR)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "°æ±âº´") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_SPEAR)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ARMOR)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "±Ã±âº´") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_BOW)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ARMOR)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "Ã¥»ç") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_FAN)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_CLOTH)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "¹«¿ë¼ö") == 0)
		{
			if (_inventory->getInventoryVector()[i].itemType == ITEM_FAN)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_CLOTH)
			{
				_inventory->setCanEquip(true, i);
			}
			else if (_inventory->getInventoryVector()[i].itemType == ITEM_ASSIST)
			{
				_inventory->setCanEquip(true, i);
			}
			else
				_inventory->setCanEquip(false, i);
		}
	}


	for (int i = 0; i < _shop->getShopItemVector().size(); i++)
	{
		if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "±Ãº´") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_BOW)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ARMOR)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "±º¿õ") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_SWORD)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ARMOR)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "°æº¸º´") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_SWORD)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ARMOR)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "°æ±âº´") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_SPEAR)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ARMOR)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "±Ã±âº´") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_BOW)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ARMOR)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "Ã¥»ç") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_FAN)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_CLOTH)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
		else if (strcmp(_myArmyClass->getMyArmyVector()[_vectorCount].classType, "¹«¿ë¼ö") == 0)
		{
			if (_shop->getShopItemVector()[i].itemType == ITEM_FAN)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_CLOTH)
			{
				_shop->setCanEquip(true, i);
			}
			else if (_shop->getShopItemVector()[i].itemType == ITEM_ASSIST)
			{
				_shop->setCanEquip(true, i);
			}
			else
				_shop->setCanEquip(false, i);
		}
	}
}

void mainScene::load()
{

}

void mainScene::tempFunction()
{

	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face0", "images/Ä³¸¯ÅÍ ¾ó±¼/0.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face1", "images/Ä³¸¯ÅÍ ¾ó±¼/1.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face2", "images/Ä³¸¯ÅÍ ¾ó±¼/2.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face3", "images/Ä³¸¯ÅÍ ¾ó±¼/3.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face4", "images/Ä³¸¯ÅÍ ¾ó±¼/4.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face5", "images/Ä³¸¯ÅÍ ¾ó±¼/5.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face6", "images/Ä³¸¯ÅÍ ¾ó±¼/6.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face7", "images/Ä³¸¯ÅÍ ¾ó±¼/7.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face8", "images/Ä³¸¯ÅÍ ¾ó±¼/8.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face9", "images/Ä³¸¯ÅÍ ¾ó±¼/9.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face10", "images/Ä³¸¯ÅÍ ¾ó±¼/10.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face11", "images/Ä³¸¯ÅÍ ¾ó±¼/11.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face12", "images/Ä³¸¯ÅÍ ¾ó±¼/12.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face13", "images/Ä³¸¯ÅÍ ¾ó±¼/13.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face14", "images/Ä³¸¯ÅÍ ¾ó±¼/14.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face15", "images/Ä³¸¯ÅÍ ¾ó±¼/15.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face16", "images/Ä³¸¯ÅÍ ¾ó±¼/16.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face17", "images/Ä³¸¯ÅÍ ¾ó±¼/17.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face18", "images/Ä³¸¯ÅÍ ¾ó±¼/18.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face19", "images/Ä³¸¯ÅÍ ¾ó±¼/19.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face20", "images/Ä³¸¯ÅÍ ¾ó±¼/20.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face21", "images/Ä³¸¯ÅÍ ¾ó±¼/21.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face22", "images/Ä³¸¯ÅÍ ¾ó±¼/22.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face23", "images/Ä³¸¯ÅÍ ¾ó±¼/23.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face24", "images/Ä³¸¯ÅÍ ¾ó±¼/24.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face25", "images/Ä³¸¯ÅÍ ¾ó±¼/25.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face26", "images/Ä³¸¯ÅÍ ¾ó±¼/26.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face27", "images/Ä³¸¯ÅÍ ¾ó±¼/27.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face28", "images/Ä³¸¯ÅÍ ¾ó±¼/28.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face29", "images/Ä³¸¯ÅÍ ¾ó±¼/29.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face30", "images/Ä³¸¯ÅÍ ¾ó±¼/30.bmp", 64, 80, true, RGB(255, 0, 255)));
	_faceSelectVector.push_back(IMAGEMANAGER->addImage("Face31", "images/Ä³¸¯ÅÍ ¾ó±¼/31.bmp", 64, 80, true, RGB(255, 0, 255)));

}
