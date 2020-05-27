#include "stdafx.h"
//#include "bullet.h"
//
//
//bullet::bullet()
//{
//}
//
//
//bullet::~bullet()
//{
//}
//
//HRESULT bullet::init(char * imageName,int bulletMax/*int bulletStartNumber, int bulletLastNumber*/, float speed/*, float range*/)
//{
//	_imageName = imageName;
//	//_range = range;
//	//tagBullet bullet;
//
//	//미리 전체 총알을 만들어서 OBJECTPOOL에 넣기
//	for (int i = 0; i < bulletMax; i++)
//	{
//		_bullet.bulletImage = new image;
//		ZeroMemory(&_bullet, sizeof(tagBullet));
//		_bullet.speed = speed;
//		_bullet.fire = false;
//		OBJECTPOOL->pushPoolBullet(_bullet);
//	}
//
//	return S_OK;
//}
//
//void bullet::release()
//{
//}
//
//void bullet::update()
//{
//	move();
//}
//
//void bullet::render()
//{
//	_viBullet = _vBullet.begin();
//
//	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
//	{
//		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
//	}
//}
//
//void bullet::fire(float x, float y, float angle, float speed)
//{
//	//_vBullet = OBJECTPOOL->getVBullet();
//	//_viBullet = OBJECTPOOL->getVIBullet();
//	//ZeroMemory(&_bullet, sizeof(tagBullet));
//	//for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
//	//{
//	//	_vBullet
//	//}
//
//	/*_viBullet = _vBullet.begin();
//	for (_viBullet; _viBullet != _vBullet.end(); ++_viBullet)
//	{
//		_viBullet->bulletImage = IMAGEMANAGER->findImage(_imageName);
//		_viBullet->angle = angle;
//		_viBullet->speed = OBJECTPOOL->getVIBullet()->speed;
//		_viBullet->x = _viBullet->fireX = x;
//		_viBullet->y = _viBullet->fireY = y;
//	}*/
//
//	_bullet.bulletImage = 
//	_bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
//	_bullet.angle = angle;
//	_bullet.speed = speed;
//	_bullet.x = _bullet.fireX = x;
//	_bullet.y = _bullet.fireY = y;
//	_vBullet.push_back(_bullet);
//
//
//	//tagBullet bullet;
//	//ZeroMemory(&bullet, sizeof(tagBullet));
//	//bullet.bulletImage = new image;
//	//bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
//	//bullet.angle = angle;
//	//bullet.speed = speed;
//	//bullet.x = bullet.fireX = x;
//	//bullet.y = bullet.fireY = y;
//	//bullet.rc = RectMakeCenter(bullet.x, bullet.y,
//	//	bullet.bulletImage->getWidth(),
//	//	bullet.bulletImage->getHeight());
//
//	//_vBullet.push_back(bullet);
//}
//
//void bullet::move()
//{
//	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
//	{
//		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
//		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;
//
//		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
//			_viBullet->bulletImage->getWidth(),
//			_viBullet->bulletImage->getHeight());
//
//		if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
//		{
//			_viBullet = _vBullet.erase(_viBullet);
//		}
//		else ++_viBullet;
//
//	}
//}
//
//void bullet::removeMissile(int arrNum)
//{
//	_vBullet.erase(_vBullet.begin() + arrNum);
//}
