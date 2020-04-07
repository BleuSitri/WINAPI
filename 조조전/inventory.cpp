#include "stdafx.h"
#include "inventory.h"

inventory::inventory()
{
}

inventory::~inventory()
{
}

HRESULT inventory::init()
{
	return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
}

void inventory::render()
{
}

void inventory::addItem(tagItem item)
{
	_inventoryVector.push_back(item);
}

void inventory::sellItem(int num)//, int & gold)
{
	_inventoryIVector = _inventoryVector.begin() + num;
	_inventoryVector.erase(_inventoryIVector);
	//_inventoryVector.erase(_inventoryVector.begin() + num-1);


}

/*

	ITEM_SWORD,
	ITEM_SPEAR,
	ITEM_BOW,
	ITEM_FAN,
	ITEM_ARMOR,
	ITEM_CLOTH,
	ITEM_ASSIST,
	ITEM_POTION,

*/
tagItem inventory::equipitem(int num)
{
	tagItem beforeItem;
	tagItem nextEquipItem;
	_inventoryIVector = _inventoryVector.begin() + num;

	switch (_inventoryIVector->itemType)
	{
	case ITEM_SWORD:
		beforeItem = getEquipWeapon();
		setEquipWeapon(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_SWORD)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	case ITEM_SPEAR:
		beforeItem = getEquipWeapon();
		setEquipWeapon(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_SPEAR)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	case ITEM_BOW:
		beforeItem = getEquipWeapon();
		setEquipWeapon(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_BOW)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	case ITEM_FAN:
		beforeItem = getEquipWeapon();
		setEquipWeapon(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_FAN)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	case ITEM_ARMOR:
		beforeItem = getEquipArmor();
		setEquipArmor(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_ARMOR)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	case ITEM_CLOTH:
		beforeItem = getEquipArmor();
		setEquipArmor(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_ARMOR)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	case ITEM_ASSIST:
		beforeItem = getEquipAssist();
		setEquipAssist(*_inventoryIVector);
		nextEquipItem = *_inventoryIVector;
		_inventoryVector.erase(_inventoryIVector);
		if (beforeItem.itemType == ITEM_ASSIST)
		{
			beforeItemBack = true;
			_beforeItem = beforeItem;
			_inventoryVector.push_back(beforeItem);
		}
		break;
	}
	beforeItemBack = false;
	return nextEquipItem;
}
