#pragma once
#include "gameNode.h"

class Tile : public gameNode
{
private:
	image* _tileImage;

	bool _isTileID;

	int _x, _y;
	int _tileX;
	int _tileY;
	float _tileWidth;
	float _tileHeight;
	int _tileID;



	RECT _rc;

	vector<Tile> _vTile;
	vector<Tile>::iterator _viTile;

public:
	Tile();
	~Tile();
	void init(int tileX, int tileY, int width, int height, int arr[]);
	void render();
	void release();

	Tile createTile(int x, int y, int width, int height, int tileID);


	RECT getRect() { return _rc; }
	bool getBool() { return _isTileID; }

	vector<Tile> getVTile() { return _vTile; }

};

class Bullet : public gameNode
{
private:
	image* _bulletImage;
	RECT _rc;
	float _x, _y;
	float _fireX, _fireY;
	float _angle;
	float _radius;
	float _speed;
	float _range;

	float _bulletSpeedY;
	float _bulletSpeedX;

	bool _isActive;
	bool _isDroppingBullet;
public:
	Bullet();
	~Bullet();

	void init(image* image, float radius, float range);
	void release();
	void update();
	void render();

	void bulletFire(float x, float y, float angle, float speed);

	void droppingBullet(float x, float y, float speed, float accel);

	void bulletMove();


public:

	void setActive(bool isActive) { _isActive = isActive; }
	bool getActive() const { return _isActive; }

	RECT getRC() const { return _rc; }
};

class objectPool
{
private:
	float _defaultRange;
	float _defaultRadius;
	const char* _imageName;

	typedef vector<Bullet*> disableBullet;
	typedef vector<Bullet*> enableBullet;
	typedef vector<Bullet*>::iterator viBullet;

private:
	disableBullet _disableBullet;
	enableBullet _enableBullet;
	viBullet _viBullet;

public:
	objectPool();
	~objectPool();

	//void release();
	//HRESULT init();


	//vBullet getVBullet() { return _vBullet; }
	//viBullet getVIBullet() { return _viBullet; }
	//void setVBullet(float x, float y, float speed, float angle);
	//bool pushPoolBullet(Bullet bullet) { _vBullet.push_back(bullet); return true; }

	void init(const char* imageName, int createBullet = 16000, float range = 1000.0f, float radius = 10.0f);
	void release();
	void update();
	void render();

	void droppingBullet(float x, float y, float speed, float accel);
	void fire(float x, float y, float angle, float speed);

	vector<Bullet*> getActiveBullet() { return _enableBullet; }

	RECT getBulletRect()
	{
		for (int i = 0; i < _enableBullet.size(); i++)
		{
			return _enableBullet.at(i)->getRC();
		}
	}
};




//#pragma once
//#include "singletonBase.h"
//
//struct tagBullet
//{
//	image* bulletImage;
//	RECT rc;
//	float x, y;
//	float fireX, fireY;
//	float radius;
//	float angle;
//	float speed;
//	bool fire;
//	int count;
//
//};
//
//class objectPool : public singletonBase<objectPool>
//{
//private:
//	typedef vector<tagBullet> vBullet;
//	typedef vector<tagBullet>::iterator viBullet;
//
//private:
//	vBullet _vBullet;
//	viBullet _viBullet;
//
//public:
//	objectPool();
//	~objectPool();
//
//	//»ý·«??
//	void release();
//	HRESULT init();
//
//
//	vBullet getVBullet() { return _vBullet; }
//	viBullet getVIBullet() { return _viBullet; }
//	void setVBullet(float x, float y, float speed, float angle);
//	bool pushPoolBullet(tagBullet bullet) { _vBullet.push_back(bullet); return true; }
//};
//
