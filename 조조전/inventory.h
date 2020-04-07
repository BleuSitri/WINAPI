#pragma once
#include "gameNode.h"
#include "item.h"
class inventory : public gameNode
{
private:
	vector<tagItem> _inventoryVector;
	vector<tagItem>::iterator _inventoryIVector;

	tagItem _equipArmor;
	tagItem _equipWeapon;
	tagItem _equipAssist;

	tagItem _beforeItem;

	bool beforeItemBack;
public:
	inventory();
	~inventory();
	HRESULT init();
	void release();
	void update();
	void render();

	vector<tagItem> getInventoryVector() { return _inventoryVector; }

	void addItem(tagItem item);
	void sellItem(int num);//, int &gold);

	void setVectorRect(RECT rc, int num)
	{
		_inventoryVector[num].rc = rc;
	}

	void setInventoryToTalNumber(int vectorNumber, int totalNumber)
	{
		_inventoryVector[vectorNumber].totalNumber += totalNumber;
	}

	void setCanEquip(bool canEquip, int i)
	{
		_inventoryVector[i].canEquip = canEquip;
	}

	tagItem equipitem(int num);

	tagItem getEquipArmor() { return _equipArmor; }
	void setEquipArmor(tagItem equipArmor) { _equipArmor = equipArmor; }

	tagItem getEquipWeapon() { return _equipWeapon; }
	void setEquipWeapon(tagItem equipWeapon) { _equipWeapon = equipWeapon; }

	tagItem getEquipAssist() { return _equipAssist; }
	void setEquipAssist(tagItem equipAssist) { _equipAssist = equipAssist; }

	bool getBeforeItemBack() { return beforeItemBack; }
	tagItem getBeforeItem() { return _beforeItem; }
};

