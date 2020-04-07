#pragma once
#include "item.h"
#include "gameNode.h"
class shop : public gameNode
{
private:
	vector<tagItem> _shopItemVector;
	item* _item;
public:
	shop();
	~shop();
	HRESULT init();
	void release();
	void update();
	void render();

	vector<tagItem> getShopItemVector() { return _shopItemVector; }

	void setVectorRect(RECT rc, int num)
	{
		_shopItemVector[num].rc = rc;
	}

	void setShopToTalNumber(int vectorNumber, int totalNumber)
	{
		_shopItemVector[vectorNumber].totalNumber += totalNumber;
	}

	//void setShopNumber(int vectorNumber, int number)
	//{
	//	_shopItemVector[vectorNumber].number = totalNumber - 
	//}
	void setCanEquip(bool canEquip, int i)
	{
		_shopItemVector[i].canEquip = canEquip;
	}
};

