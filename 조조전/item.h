#pragma once
#include "gameNode.h"
class item : public gameNode
{

private:
	vector<tagItem> _itemVector;
	vector<tagItem>::iterator _itemIVector;

public:
	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();

	void setItem();

	vector<tagItem> _getItemVector() { return _itemVector; }
	vector<tagItem>::iterator _getitemIVector() { return _itemIVector; }

	//void setTotalNumber(int vectorNumber, int vectorTotalNumber)
	//{
	//	_itemVector[vectorNumber].totalNumber = vectorTotalNumber;
	//}
};

