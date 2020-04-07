#include "stdafx.h"
#include "shop.h"

shop::shop()
{
}

shop::~shop()
{
}

HRESULT shop::init()
{
	_item = new item;
	_item->init();
	_item->_getitemIVector() = _item->_getItemVector().begin();

	//for (vector<tagItem>::size_type i = 0; i < _item->_getItemVector().size; i++)
	//{
	//	_shopItemVector.push_back(_item->_getItemVector()[i]);
	//}

	//for (_item->_getitemIVector(); _item->_getitemIVector() != _item->_getItemVector().end();++_item->_getitemIVector())
	//{
	//	_shopItemVector.pop_back();
	//}

	//for (vector<tagItem>::size_type i = 0; i < _item->_getItemVector().size; i++)
	//{
	//	_shopItemVector.push_back(_item->_getItemVector()[i]);
	//}

	for (int i = 0; i < _item->_getItemVector().size(); i++)
	{
		_shopItemVector.push_back(_item->_getItemVector()[i]);
	}
	//	_item->_getItemVector().size();

	return S_OK;
}

void shop::release()
{
}

void shop::update()
{
}

void shop::render()
{
}
