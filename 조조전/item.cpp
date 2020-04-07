#include "stdafx.h"
#include "item.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init()
{
	setItem();
	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
}

void item::setItem()
{
	tagItem _weapon1;
	_weapon1.itemType = ITEM_SWORD;
	_weapon1.itemImage = IMAGEMANAGER->addImage("¥‹∞À", "images/æ∆¿Ã≈€/¥‹∞À.bmp", 32, 32, true, RGB(247, 0, 255));
	_weapon1.itemIcon = IMAGEMANAGER->addImage("¥‹∞À", "images/æ∆¿Ã≈€/¥‹∞À.bmp", 16, 16, true, RGB(247, 0, 255));
	_weapon1.name = "¥‹∞À";
	_weapon1.price = 500;
	_weapon1.stat = 10;
	_weapon1.count = 5;
	_weapon1.number = 0;
	_weapon1.totalNumber = 0;
	_weapon1.exp = 0;
	_weapon1.level = 1;
	_itemVector.push_back(_weapon1);

	tagItem _weapon2;
	_weapon2.itemType = ITEM_SWORD;
	_weapon2.itemImage = IMAGEMANAGER->addImage("¿«√µ∞À", "images/æ∆¿Ã≈€/¿«√µ∞À.bmp", 32, 32, true, RGB(247, 0, 255));
	_weapon2.itemIcon = IMAGEMANAGER->addImage("¿«√µ∞À", "images/æ∆¿Ã≈€/¿«√µ∞À.bmp", 16, 16, true, RGB(247, 0, 255));
	_weapon2.name = "¿«√µ∞À";
	_weapon2.price = 0;
	_weapon2.stat = 16;
	_weapon2.count = 1;
	_weapon2.number = 0;
	_weapon2.totalNumber = 0;
	_weapon2.exp = 0;
	_weapon2.level = 1;
	_itemVector.push_back(_weapon2);

	tagItem _weapon3;
	_weapon3.itemType = ITEM_SPEAR;
	_weapon3.itemImage = IMAGEMANAGER->addImage("¥‹√¢", "images/æ∆¿Ã≈€/¥‹√¢.bmp", 32, 32, true, RGB(247, 0, 255));
	_weapon3.itemIcon = IMAGEMANAGER->addImage("¥‹√¢", "images/æ∆¿Ã≈€/¥‹√¢.bmp", 16, 16, true, RGB(247, 0, 255));
	_weapon3.name = "¥‹√¢";
	_weapon3.price = 500;
	_weapon3.stat = 12;
	_weapon3.count = 5;
	_weapon3.number = 0;
	_weapon3.totalNumber = 0;
	_weapon3.exp = 0;
	_weapon3.level = 1;
	_itemVector.push_back(_weapon3);

	tagItem _weapon4;
	_weapon4.itemType = ITEM_BOW;
	_weapon4.itemImage = IMAGEMANAGER->addImage("π›±√", "images/æ∆¿Ã≈€/π›±√.bmp", 32, 32, true, RGB(247, 0, 255));
	_weapon4.itemIcon = IMAGEMANAGER->addImage("π›±√", "images/æ∆¿Ã≈€/π›±√.bmp", 16, 16, true, RGB(247, 0, 255));
	_weapon4.name = "π›±√";
	_weapon4.price = 500;
	_weapon4.stat = 8;
	_weapon4.count = 5;
	_weapon4.number = 0;
	_weapon4.totalNumber = 0;
	_weapon4.exp = 0;
	_weapon4.level = 1;
	_itemVector.push_back(_weapon4);

	tagItem _weapon5;
	_weapon5.itemType = ITEM_FAN;
	_weapon5.itemImage = IMAGEMANAGER->addImage("¡◊º±", "images/æ∆¿Ã≈€/¡◊º±.bmp", 32, 32, true, RGB(247, 0, 255));
	_weapon5.itemIcon = IMAGEMANAGER->addImage("¡◊º±", "images/æ∆¿Ã≈€/¡◊º±.bmp", 16, 16, true, RGB(247, 0, 255));
	_weapon5.name = "¡◊º±";
	_weapon5.price = 500;
	_weapon5.stat = 12;
	_weapon5.count = 5;
	_weapon5.number = 0;
	_weapon5.totalNumber = 0;
	_weapon5.exp = 0;
	_weapon5.level = 1;
	_itemVector.push_back(_weapon5);

	tagItem _armor1;
	_armor1.itemType = ITEM_ARMOR;
	_armor1.itemImage = IMAGEMANAGER->addImage("∞°¡◊∞©ø ", "images/æ∆¿Ã≈€/∞°¡◊∞©ø .bmp", 32, 32, true, RGB(247, 0, 255));
	_armor1.itemIcon = IMAGEMANAGER->addImage("∞°¡◊∞©ø ", "images/æ∆¿Ã≈€/∞°¡◊∞©ø .bmp", 16, 16, true, RGB(247, 0, 255));
	_armor1.name = "∞°¡◊∞©ø ";
	_armor1.price = 500;
	_armor1.stat = 10;
	_armor1.count = 5;
	_armor1.number = 0;
	_armor1.totalNumber = 0;
	_armor1.exp = 0;
	_armor1.level = 1;
	_itemVector.push_back(_armor1);

	tagItem _armor2;
	_armor2.itemType = ITEM_CLOTH;
	_armor2.itemImage = IMAGEMANAGER->addImage("π´∏Ìø ", "images/æ∆¿Ã≈€/π´∏Ìø .bmp", 32, 32, true, RGB(247, 0, 255));
	_armor2.itemIcon = IMAGEMANAGER->addImage("π´∏Ìø ", "images/æ∆¿Ã≈€/π´∏Ìø .bmp", 16, 16, true, RGB(247, 0, 255));
	_armor2.name = "π´∏Ìø ";
	_armor2.price = 500;
	_armor2.stat = 8;
	_armor2.count = 5;
	_armor2.number = 0;
	_armor2.totalNumber = 0;
	_armor2.exp = 0;
	_armor2.level = 1;
	_itemVector.push_back(_armor2);

	tagItem _assist1;
	_assist1.itemType = ITEM_ASSIST;
	_assist1.itemImage = IMAGEMANAGER->addImage("∞°¡◊πÊ∆–", "images/æ∆¿Ã≈€/∞°¡◊πÊ∆–.bmp", 32, 32, true, RGB(247, 0, 255));
	_assist1.itemIcon = IMAGEMANAGER->addImage("∞°¡◊πÊ∆–", "images/æ∆¿Ã≈€/∞°¡◊πÊ∆–.bmp", 16, 16, true, RGB(247, 0, 255));
	_assist1.name = "∞°¡◊πÊ∆–";
	_assist1.price = 1000;
	_assist1.stat = 10;
	_assist1.count = 5;
	_assist1.number = 0;
	_assist1.totalNumber = 0;
	_assist1.exp = 0;
	_assist1.level = 1;
	_itemVector.push_back(_assist1);

	tagItem _assist2;
	_assist2.itemType = ITEM_ASSIST;
	_assist2.itemImage = IMAGEMANAGER->addImage("π´∏Ì¿Â∞©", "images/æ∆¿Ã≈€/π´∏Ì¿Â∞©.bmp", 32, 32, true, RGB(247, 0, 255));
	_assist2.itemIcon = IMAGEMANAGER->addImage("π´∏Ì¿Â∞©", "images/æ∆¿Ã≈€/π´∏Ì¿Â∞©.bmp", 16, 16, true, RGB(247, 0, 255));
	_assist2.name = "π´∏Ì¿Â∞©";
	_assist2.price = 1000;
	_assist2.stat = 10;
	_assist2.count = 5;
	_assist2.number = 0;
	_assist2.totalNumber = 0;
	_assist2.exp = 0;
	_assist2.level = 1;
	_itemVector.push_back(_assist2);

	tagItem _potion1;
	_potion1.itemType = ITEM_POTION;
	_potion1.itemImage = IMAGEMANAGER->addImage("»∏∫π¿«Ω“", "images/æ∆¿Ã≈€/»∏∫π¿«Ω“.bmp", 32, 32, true, RGB(247, 0, 255));
	_potion1.itemIcon = IMAGEMANAGER->addImage("»∏∫π¿«Ω“", "images/æ∆¿Ã≈€/»∏∫π¿«Ω“.bmp", 16, 16, true, RGB(247, 0, 255));
	_potion1.name = "»∏∫π¿«Ω“";
	_potion1.price = 300;
	_potion1.stat = 50;
	_potion1.count = 50;
	_potion1.totalNumber = 0;
	_itemVector.push_back(_potion1);


}
