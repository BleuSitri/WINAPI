#include "stdafx.h"
#include "objectPool.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::init(int tileX, int tileY, int width, int height, int arr[])
{
	_tileX = tileX;
	_tileY = tileY;
	for (int i = 0; i < _tileX; i++)
	{
		for (int j = 0; j < _tileY; j++)
		{
			_vTile.push_back(createTile(j*width,i*height,width,height,arr[i*_tileX+j]));
		}
	}
}

void Tile::render()
{
	//for (int i=0;i<_vTile.size();i++)
	//{
	//	if (_vTile.at(i)._tileID == 0)
	//	{
	//		//_viTile->_tileImage = IMAGEMANAGER->findImage("floor");
	//		//_isTileID = true;
	//		Rectangle(getMemDC(), _vTile.at(i)., _viTile->_rc.top, _viTile->_rc.right, _viTile->_rc.bottom);
	//	}
	//	//else if (_viTile->_tileID == 1)
	//	//{
	//	//	_viTile->_tileImage = IMAGEMANAGER->findImage("spike");
	//	//}
	//	//else if (_viTile->_tileID == 2)
	//	//{
	//	//	_viTile->_tileImage = IMAGEMANAGER->findImage("floor");
	//	//}

	//	//_viTile->_tileImage->render(getMemDC(), _viTile->_x, _viTile->_y);
	//}


	for (_viTile = _vTile.begin(); _viTile != _vTile.end(); ++_viTile)
	{
		//Rectangle(getMemDC(), _viTile->_rc.left, _viTile->_rc.top, _viTile->_rc.right, _viTile->_rc.bottom);
		
		//char str[128];
		//wsprintf(str, "%d", _viTile->_tileID);
		//TextOut(getMemDC(), _viTile->_x, _viTile->_y, str, strlen(str));

		if (_viTile->_tileID == 0)
		{
			//_viTile->_tileImage = IMAGEMANAGER->findImage("floor");
			//_isTileID = true;
			//Rectangle(getMemDC(), _viTile->_rc.left, _viTile->_rc.top, _viTile->_rc.right, _viTile->_rc.bottom);
		}
		else if (_viTile->_tileID == 1)
		{

			_viTile->_tileImage = IMAGEMANAGER->findImage("spike");
			_viTile->_tileImage->render(getMemDC(), _viTile->_x, _viTile->_y);
			//Rectangle(getMemDC(), _viTile->_rc.left, _viTile->_rc.top, _viTile->_rc.right, _viTile->_rc.bottom);

		}
		else if (_viTile->_tileID == 2)
		{
			_viTile->_tileImage = IMAGEMANAGER->findImage("floor");
			_viTile->_tileImage->render(getMemDC(), _viTile->_x, _viTile->_y);
			//Rectangle(getMemDC(), _viTile->_rc.left, _viTile->_rc.top, _viTile->_rc.right, _viTile->_rc.bottom);
		}
		//_viTile->_tileImage->render(getMemDC(), _viTile->_x, _viTile->_y);

	}

	//for (int i = 0; i < _vTile.size(); i++)
	//{
	//	if (_vTile.at(i)._tileID == 0)
	//	{

	//	}
	//}
}

void Tile::release()
{
}

Tile Tile::createTile(int x, int y, int width, int height, int tileID)
{
	Tile tempTile;
	tempTile._x = x;
	tempTile._y = y;
	tempTile._tileWidth = width;
	tempTile._tileHeight = height;
	tempTile._tileID = tileID;
	tempTile._rc = RectMakeCenter(x, y, x+width, y+height);

	return tempTile;
}



Bullet::Bullet()
	: _bulletImage(NULL), _isActive(false), _radius(10.0f)
{
}

Bullet::~Bullet()
{
}

void Bullet::init(image * image, float radius, float range)
{
	_bulletImage = image;
	_radius = radius;
	_range = range;
	_isActive = false;
}

void Bullet::release()
{
}

void Bullet::update()
{
	bulletMove();
}

void Bullet::render()
{
	_bulletImage->render(getMemDC(), _rc.left, _rc.top);
}

void Bullet::bulletFire(float x, float y, float angle, float speed)
{
	_x = _fireX = x;
	_y = _fireY = y;
	_angle = angle;
	_speed = speed;

	_rc = RectMakeCenter(_x, _y, _bulletImage->getWidth(), _bulletImage->getHeight());

	_isActive = true;
}

void Bullet::droppingBullet(float x, float y, float speed, float accel)
{
	_bulletSpeedY += accel;
	_speed = speed;
	_x = _fireX = x;
	_y = _fireY = y + _bulletSpeedY;


	_rc = RectMakeCenter(_x, _y, _bulletImage->getWidth(), _bulletImage->getHeight());

	_isActive = true;
	_isDroppingBullet = true;
}

void Bullet::bulletMove()
{
	_x += cosf(_angle) * _speed;
	//_y += -sinf(_angle) * accel;
	_y += -sinf(_angle) * _speed;

	_rc = RectMakeCenter(_x, _y,
		_bulletImage->getWidth(),
		_bulletImage->getHeight()
	);

	if (_range < getDistance(_x, _y, _fireX, _fireY)) _isActive = false;
	if (_bulletImage->getX() > WINSIZEX) _isActive = false;
	if (_bulletImage->getX() < 0) _isActive = false;
	if (_bulletImage->getY() < 0 ) _isActive = false;
	if (_bulletImage->getY() > WINSIZEY ) _isActive = false;

}




objectPool::objectPool()
{
}


objectPool::~objectPool()
{
}

void objectPool::init(const char * imageName, int createBullet, float range, float radius)
{
	_defaultRange = range;
	_defaultRadius = radius;

	_enableBullet.reserve(createBullet);
	_disableBullet.reserve(createBullet);

	image* tempImage = IMAGEMANAGER->findImage(imageName);

	for (int i = 0; i < createBullet; i++)
	{
		_disableBullet.push_back(new Bullet);
		_disableBullet[i]->init(tempImage, _defaultRadius, _defaultRange);
	}

}

void objectPool::release()
{
	for (int i = 0; i < _disableBullet.size(); i++)
		SAFE_DELETE(_disableBullet[i]);
	for (int i = 0; i < _enableBullet.size(); i++)
		SAFE_DELETE(_enableBullet[i]);
}

void objectPool::update()
{
	for (int i = 0; i < _enableBullet.size(); ++i)
	{
		if (_enableBullet[i]->getActive())
		{
			_enableBullet[i]->update();
		}
		else
		{
			Bullet* tempBullet = _enableBullet[i];

			_enableBullet.erase(_enableBullet.begin() + i--);

			_disableBullet.push_back(tempBullet);
		}
	}
}

void objectPool::render()
{
	for (int i = 0; i < _enableBullet.size(); ++i)
	{
		_enableBullet[i]->render();
	}
}

void objectPool::droppingBullet(float x, float y, float speed, float accel)
{
	Bullet* tempBullet = NULL;

	if (_disableBullet.size() == 0)
	{
		tempBullet = new Bullet;
		image* tempImage = IMAGEMANAGER->findImage(_imageName);

		tempBullet->init(tempImage, _defaultRadius, _defaultRange);
	}
	else
	{
		tempBullet = _disableBullet.back();
		_disableBullet.pop_back();
	}

	tempBullet->droppingBullet(x, y, speed, accel);

	_enableBullet.push_back(tempBullet);
}

void objectPool::fire(float x, float y, float angle, float speed)
{
	Bullet* tempBullet = NULL;

	if (_disableBullet.size() == 0)
	{
		tempBullet = new Bullet;
		image* tempImage = IMAGEMANAGER->findImage(_imageName);

		tempBullet->init(tempImage, _defaultRadius, _defaultRange);
	}
	else
	{
		tempBullet = _disableBullet.back();
		_disableBullet.pop_back();
	}

	tempBullet->bulletFire(x, y, angle, speed);

	_enableBullet.push_back(tempBullet);
}


//#include "stdafx.h"
//#include "objectPool.h"
//
//
//objectPool::objectPool()
//{
//}
//
//
//objectPool::~objectPool()
//{
//}
//
//void objectPool::release()
//{
//}
//
//HRESULT objectPool::init()
//{
//	return S_OK;
//}
//
//void objectPool::setVBullet(float x, float y, float speed, float angle)
//{
//}

