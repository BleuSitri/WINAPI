#pragma once
#include "enemy.h"
#include "bullet.h"
#include "objectPool.h"
#include "progressBar.h"
#include <math.h>


#define BULLETMAX 10000


//struct pt
//{
//	POINT wayPT;
//	bool isattach;
//};
class player;
class bossClass : public enemy
{
private:
	RECT rc;
	RECT rc1;
	RECT sigongRect;
	image* bossImage;
	image* sigongImage;
	player* _player;
	float angle;
	float angle2;
	int timeCount;
	POINT pt[9] = { {100,140},{100,350},{100,510},{450,140},{450,350},{450,510},{850,140},{850,350},{850,510} };
	
	//pt PT[9];
	BYTE alpha;
	BYTE alphaPlus;

	float deltaTime;

	float moveSpeed;
	float lerp(float startPosition, float endPosition, float value) { return (startPosition + value * (endPosition - startPosition)); }

	float bulletSpeedX;
	float bulletSpeedY;
	float accel;

	bool _bossLive;
	bool _hitDamage;
	bool _onHit;


	//프로그레스바 
	progressBar* _hpBar;
	float _maxHP;
	float _currentHP;
	
	
	objectPool* _bulletPool;
	objectPool* _bulletPool_YellowSTAR;
	//objectPool* _bulletPool_BLUEBUBBLE;
	objectPool* _bulletPool_BIGREDBUBBLE;
	objectPool* _bulletPool_VERYLUEBUBBLE;

	bool bCollision;
	int _count;
	float startTime;
	float endTime;

//	vector<tagBullet> _vBullet;
//	vector<tagBullet>::iterator _viBullet;

//	bullet* _bullet;

public:
	bossClass();
	~bossClass();

	HRESULT init();
	void release();
	void update();
	void fire();
	void render();

	void droppingBullet(float bulletX, float bulletY, float accel, float bulletSpeedX, float bulletSpeedY);

	void setPlayerMemoryLink(player* player) { _player = player; }

	void imageMove(image * image, float x, float y, float speed);

	image* getBossImage() { return bossImage; }

	void collision();

	void hitDamage(float damage);

	int getCurrentHP() { return _currentHP; }
	void setCurrentHP(float currentHP) { _currentHP = currentHP; }

	bool getCollision() { return bCollision; }

	void setHitDamage(bool hitDamage) { _hitDamage = hitDamage; }

	RECT getRECT() { return rc; }
	
	void AAA();

};

