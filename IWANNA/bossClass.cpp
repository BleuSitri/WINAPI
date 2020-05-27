#include "stdafx.h"
#include "bossClass.h"
#include "player.h"


bossClass::bossClass()
{
}


bossClass::~bossClass()
{
}

HRESULT bossClass::init()
{
	//{100,140},{100,350},{100,510},{450,140},{450,350},{450,510},{850,140},{850,350},{850,510}
	//for (int i = 0; i < 9; i++)
	//{
	//	int widthCount = i % 3;
	//	int heightCount = i / 3;
	//	if (i % 3 == 0)
	//		PT[i].wayPT = { 100 + heightCount*350,140 + widthCount*200 };
	//}
	//rc = RectMakeCenter(WINSIZEX / 2, 100, 100, 100);

	_player = new player;
	_player->init();

	bossImage = IMAGEMANAGER->findImage("boss");
	bossImage->setX(WINSIZEX / 2);
	bossImage->setY(200);
	rc = RectMake(bossImage->getX(), bossImage->getY(), bossImage->getWidth(), bossImage->getHeight());
	//rc1 = RectMake(WINSIZEX, 450, 500, 250);
	alpha = 255;
	_bulletPool = new objectPool;

	_bulletPool->init("_bulletPool_BLUEBUBBLE");
	
	_bulletPool_YellowSTAR = new objectPool;
	_bulletPool_YellowSTAR->init("_bulletPool_YellowSTAR");

	//_bulletPool_BLUEBUBBLE = new objectPool;
	//_bulletPool_BLUEBUBBLE->init("_bulletPool_BLUEBUBBLE");

	_bulletPool_BIGREDBUBBLE = new objectPool;
	_bulletPool_BIGREDBUBBLE->init("_bulletPool_BIGREDBUBBLE");

	_bulletPool_VERYLUEBUBBLE = new objectPool;
	_bulletPool_VERYLUEBUBBLE->init("_bulletPool_VERYBIGBLUEBUBBLE");

	

	sigongImage = IMAGEMANAGER->findImage("시공");
	sigongImage->setX(WINSIZEX);
	sigongImage->setY(500);

	_maxHP = _currentHP = 1000;
	_hpBar = new progressBar;
	_hpBar->init("images/체력바.bmp", "images/체력바배경.bmp", 0, 1, WINSIZEX, 20);
	_hpBar->setGauge(_currentHP, _maxHP);

	_bossLive = true;
	

//	_bullet = new bullet;
//	_bullet->init("bullet", BULLETMAX, 5.0f);

	
	return S_OK;
}

void bossClass::release()
{
	SAFE_DELETE(_bulletPool);
	SAFE_DELETE(_bulletPool_YellowSTAR);
	//SAFE_DELETE(_bulletPool_BLUEBUBBLE);
	SAFE_DELETE(_bulletPool_BIGREDBUBBLE);
	SAFE_DELETE(_bulletPool_VERYLUEBUBBLE);
	SAFE_DELETE(_hpBar);
}

void bossClass::update()
{
	deltaTime += TIMEMANAGER->getElapsedTime();


	angle += 2;
	timeCount++;
	//_hpBar->setX(0);
	//_hpBar->setY(1);
	//_hpBar->setGauge(_currentHP, _maxHP);
	//_hpBar->update();
	if (_onHit)
	{
		AAA();
	}
	//_hpBar->setGauge(_currentHP, _maxHP);
	//_hpBar->update();

	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 50; j++)
	//	{
	//		if (i % 2 == 0)
	//		{
	//			//bossImage->setY(bossImage->getY()-j);
	//		}
	//		if (i % 2 == 1)
	//		{

	//		}
	//	}
	//}

	
	//bossImage->setY(bossImage->getY() - getDistance(bossImage->getX(), bossImage->getY(), pt[6].x, pt[6].y)*BOSSSPEED);
	
	//bossImage->setX(lerp(bossImage->getX(), 0, 0.1));
	//if(timeCount<30)
	//bossImage->setCenter(lerp(bossImage->getX()+bossImage->getWidth()/2, pt[7].x, 0.05), lerp(bossImage->getY()+ bossImage->getHeight() / 2,pt[7].y, 0.05));
	//if(timeCount>=30)
	//bossImage->setCenter(lerp(bossImage->getX()+bossImage->getWidth()/2, pt[8].x, 0.05), lerp(bossImage->getY()+ bossImage->getHeight() / 2,pt[8].y, 0.05));
	//bossImage->setCenter(lerp(bossImage->getX()+bossImage->getWidth()/2, pt[0].x, 0.05), lerp(bossImage->getY()+ bossImage->getHeight() / 2,pt[0].y, 0.05));
	//bossImage->setCenter(lerp(bossImage->getX()+bossImage->getWidth()/2, pt[0].x, 0.05), lerp(bossImage->getY()+ bossImage->getHeight() / 2,pt[0].y, 0.05));

	if (_currentHP <= 0)
	{
		_bossLive = false;
	}
	if (_currentHP > 0)
	{
		_bossLive = true;
	}

	if (_bossLive)
	{
		if (timeCount < 20)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[7].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[7].y, 0.15));
		}

		if (timeCount >= 20 && timeCount < 40)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[8].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[8].y, 0.15));
			//_bulletPool_VERYLUEBUBBLE->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 150.0f + angle, 10.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}

		if (timeCount >= 40 && timeCount < 60)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[6].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.15));
			//_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.top + (rc.bottom - rc.top) / 2, 50, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);


			//bulletSpeedY += 2.0f;
			//_bulletPool->fire(rc.right - (rc.right - rc.left) / 2 + bulletSpeedY, rc.bottom + bulletSpeedY, 180, bulletSpeedY);
			//_bulletPool->droppingBullet(rc.right - (rc.right - rc.left) / 2, rc.top + (rc.bottom - rc.top) / 2, -2.0f, -2.0f);
			//if (timeCount == 41)
				//_bulletPool->droppingBullet(rc.right - (rc.right - rc.left) / 2, rc.top + (rc.bottom - rc.top) / 2, -1.0f, 5.0f);
			//droppingBullet(rc.right - (rc.right - rc.left) / 2, rc.top + (rc.bottom - rc.top) / 2, -0.5f, 5.0f, 5.0f);
		}

		if (timeCount >= 60 && timeCount < 80)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[2].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[2].y, 0.15));
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}

		if (timeCount >= 80 && timeCount < 100)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[0].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[0].y, 0.15));
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}

		if (timeCount >= 100 && timeCount < 120)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[8].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[8].y, 0.15));
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}

		if (timeCount >= 120 && timeCount < 140)
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[6].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.15));
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}

		if (timeCount >= 140 && timeCount < 160)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[2].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[2].y, 0.15));
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}

		if (timeCount >= 190 && timeCount < 210)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[8].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[8].y + 150, 0.15));
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 120.0f + angle, 5.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 100.0f + angle, 9.0f);
			_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 80.0f + angle, 15.0f);
		}
		if (timeCount >= 215 && timeCount < 250)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[7].x, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.03));
			if (timeCount >= 215 && timeCount < 230)
				_bulletPool->fire(400, 0, 300, 30.0f);
			if (timeCount >= 230 && timeCount < 240)
				_bulletPool->fire(500, 0, 300, 30.0f);
			if (timeCount >= 240 && timeCount < 250)
				_bulletPool->fire(600, 0, 300, 30.0f);
		}
		if (timeCount >= 250 && timeCount < 300)
		{
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(WINSIZEX / 2 + cos(i), WINSIZEY / 2 + sin(i), angle + cos(i)*sin(i), 20.0f);
			}
			sigongImage->setX(sigongImage->getX() - 27.0f);
		}
		if (timeCount >= 300 && timeCount < 500)
		{
			for (int i = 0; i < 5; i++)
			{
				_bulletPool->fire((200 + i * cos(i)), (200 + i * sin(i)), angle, 20.0f);
				_bulletPool->fire((500 + i * cos(i)), (200 + i * sin(i)), angle, 20.0f);
				_bulletPool->fire((700 + i * cos(i)), (500 + i * sin(i)), angle, 20.0f);
				_bulletPool->fire((900 + i * cos(i)), (200 + i * sin(i)), angle, 20.0f);
			}
		}
		if (timeCount >= 500 && timeCount < 550)
		{
			bulletSpeedX += 10.0f;
			bulletSpeedY += 10.0f;
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(200 + 100 * cos(i) + bulletSpeedX, 650 - (100 * sin(i) + bulletSpeedY), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}

		}

		if (timeCount >= 500 && timeCount < 520)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[0].x, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[0].y, 0.15));
			for (int i = 0; i < 30; i++)
			{
				_bulletPool->fire(bossImage->getX()+bossImage->getFrameWidth()/2, bossImage->getY()+bossImage->getFrameHeight(), angle+i, 20.0f);
			}
		}
		if (timeCount >= 520 && timeCount < 580)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[6].x + 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.03));
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 300, 40.0f);
				//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
			}
		}
			
		if (timeCount >= 580 && timeCount < 640)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[0].x - 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[0].y, 0.03));
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth(), bossImage->getY() + bossImage->getFrameHeight(), 300, 40.0f);
				//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
			}
		}
			
		//for (int i = 0; i < 10; i++)
		//{
		//	_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 300, 20.0f);
		//	//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
		//}
			
		if (timeCount >= 640 && timeCount < 700)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[6].x + 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.03));
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 300, 40.0f);
				//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
			}
		}
			
		if (timeCount >= 700 && timeCount < 760)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[0].x - 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[0].y, 0.03));
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth(), bossImage->getY() + bossImage->getFrameHeight(), 300, 40.0f);
				//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
			}
		}
			
		if (timeCount >= 760 && timeCount < 820)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[6].x + 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.03));
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 300, 40.0f);
				//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
			}
		}
			
		if (timeCount >= 820 && timeCount < 900)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[0].x - 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[0].y, 0.03));
			for (int i = 0; i < 20; i++)
			{
				_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth(), bossImage->getY() + bossImage->getFrameHeight(), 300, 40.0f);
				//_bulletPool->fire(bossImage->getX() + bossImage->getFrameWidth() / 2, bossImage->getY() + bossImage->getFrameHeight(), 0, 20.0f);
			}
		}
			
		if (timeCount >= 900 && timeCount < 960)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[6].x + 100, 0.03), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[6].y, 0.03));
			for (int i = 0; i < 15; i++)
			{
				_bulletPool->fire((200 + i * cos(i)), (200 + i * sin(i)), angle, 20.0f);
				_bulletPool->fire((500 + i * cos(i)), (200 + i * sin(i)), angle, 20.0f);
			}
			for (int i = 0; i < 30; i++)
			{
				_bulletPool->fire(i * 200, 0, 300, 40.f);
			}
		}
			
		if (timeCount >= 960 && timeCount < 980)//slerp 필요
		{
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[7].x + 100, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[7].y, 0.15));

		}
			
		if (timeCount >= 980 && timeCount < 1000)//slerp 필요
			bossImage->setCenter(lerp(bossImage->getX() + bossImage->getWidth() / 2, pt[7].x + 100, 0.15), lerp(bossImage->getY() + bossImage->getHeight() / 2, pt[7].y, 0.15));
		if (timeCount >= 1000 && timeCount < 1040)
		{
			alpha = alphaPlus;
			alphaPlus += 5;

			bossImage->setCenter(pt[3].x, pt[3].y);
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(bossImage->getX() + 100 * cos(i), bossImage->getY() - (100 * sin(i)), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}

		}
		if (timeCount >= 1040 && timeCount < 1080)
		{
			alpha = alphaPlus;
			alphaPlus -= 5;

			bossImage->setCenter(pt[3].x, pt[3].y);
		}
		if (timeCount >= 1080 && timeCount < 1120)
		{
			alpha = alphaPlus;
			alphaPlus += 5;

			bossImage->setCenter(pt[7].x + 100, pt[7].y);
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(bossImage->getX() + 100 * cos(i), bossImage->getY() - (100 * sin(i)), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}
		}
		if (timeCount >= 1120 && timeCount < 1160)
		{
			alpha = alphaPlus;
			alphaPlus -= 5;

			bossImage->setCenter(pt[7].x + 100, pt[7].y);
		}
		if (timeCount >= 1160 && timeCount < 1200)
		{
			alpha = alphaPlus;
			alphaPlus += 5;

			bossImage->setCenter(pt[5].x, pt[5].y);
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(bossImage->getX() + 100 * cos(i), bossImage->getY() - (100 * sin(i)), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}
		}
		if (timeCount >= 1200 && timeCount < 1240)
		{
			alpha = alphaPlus;
			alphaPlus -= 5;

			bossImage->setCenter(pt[5].x, pt[5].y);
		}

		if (timeCount >= 1240 && timeCount < 1280)
		{
			alpha = alphaPlus;
			alphaPlus += 5;

			bossImage->setCenter(pt[7].x - 100, pt[7].y);
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(bossImage->getX() + 100 * cos(i), bossImage->getY() - (100 * sin(i)), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}
		}
		if (timeCount >= 1280 && timeCount < 1320)
		{
			alpha = alphaPlus;
			alphaPlus -= 5;

			bossImage->setCenter(pt[7].x - 100, pt[7].y);
		}
		if (timeCount >= 1320 && timeCount < 1360)
		{
			alpha = alphaPlus;
			alphaPlus += 5;

			bossImage->setCenter(pt[8].x, pt[8].y + 100);
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(bossImage->getX() + 100 * cos(i), bossImage->getY() - (100 * sin(i)), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}
		}
		if (timeCount >= 1360 && timeCount < 1400)
		{
			alpha = alphaPlus;
			alphaPlus -= 5;

			bossImage->setCenter(pt[8].x, pt[8].y + 100);
		}
		if (timeCount >= 1400 && timeCount < 1440)
		{
			alpha = alphaPlus;
			alphaPlus += 5;

			bossImage->setCenter(pt[7].x + 100, pt[7].y);
			for (int i = 0; i < 10; i++)
			{

				_bulletPool->fire(bossImage->getX() + 100 * cos(i), bossImage->getY() - (100 * sin(i)), angle, 20.0f);
				//_bulletPool->getActiveBullet().at(i)->setActive(false);
			}
		}
		if (timeCount >= 1440 && timeCount < 1480)
		{
			alpha = alphaPlus;
			alphaPlus -= 5;

			bossImage->setCenter(pt[7].x + 100, pt[7].y);
		}
		if (timeCount >= 1480 && timeCount < 1520)
		{
			alpha = alphaPlus;
			alphaPlus += 20;
			bossImage->setCenter(pt[8].x, pt[8].y);
		}
		if (timeCount >= 1520 && timeCount < 1700)
		{
			alpha = 255;
			bossImage->setCenter(pt[8].x, pt[8].y);

			angle2+=10;
			if (angle2 > 180)
				angle2 = 0;
			for (int i = 0; i < 5; i++)
			{
				_bulletPool->fire(bossImage->getX() , bossImage->getY() -sin(angle2)*40, 22, 10.0f);
				_bulletPool->fire(bossImage->getX(), bossImage->getY() +bossImage->getHeight() + sin(angle2*2)*40, 22, 10.0f);
			}
			for (int i = 0; i < 10; i++)
			{
				_bulletPool->fire(bossImage->getX(), bossImage->getY() + bossImage->getHeight() / 2, 22+ cos(angle2) * 100*i, (i+1)*10.0f);
			}
		}
		if (timeCount >= 1700 && timeCount < 1740)
		{

			alpha = alphaPlus;
			alphaPlus -= 5;
		}

		if (timeCount >= 1740)
		{
			alpha = 255;

			bulletSpeedX = 0;
			if (_bossLive)
				timeCount = 40;
		}
	}

/*
	if (_bossLive == false)
	{

	}*/

	//if (timeCount < 100)
	//{
		//_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.bottom, 150.0f + angle, 5.0f);
		//_bulletPool->fire(rc.right, rc.top + (rc.bottom - rc.top) / 2, 150.0f + angle, 5.0f);
		//_bulletPool->fire(rc.right - (rc.right - rc.left) / 2, rc.top, 150.0f + angle, 5.0f);
		//_bulletPool->fire(rc.left, rc.top + (rc.bottom - rc.top) / 2, 150.0f + angle, 5.0f);
	//}

	//if (timeCount >= 100 && timeCount < 1000)
	//{
	//	angle++;
	//	_bulletPool->fire(cos(angle)+sin(angle), 500+sin(angle), 150.0f + angle, 5.0f);
	//}

	rc = RectMake(bossImage->getX(), bossImage->getY(), bossImage->getWidth(), bossImage->getHeight());
	_bulletPool->update();
	sigongRect = RectMake(sigongImage->getX(), sigongImage->getY(), sigongImage->getWidth(), sigongImage->getHeight());
	

	collision();
	//_player->collision();
	//_hpBar->setX(0);
	//_hpBar->setY(1);
	//_hpBar->setGauge(_currentHP, _maxHP);
	//setCurrentHP(30);
	//RECT temp1;
	//if(IntersectRect(&temp1, &_player->bulletRECT(), &rc))
		//setCurrentHP(1);
	//_currentHP -= 1;
	_hpBar->setGauge(_currentHP, _maxHP);
	_hpBar->update();


}

//void MoveDroppingBullet(float& x, float& y, float accel, float& vx, float &vy) // 탄환의 좌표xy, 가속도, 속도 벡터의 x성분과 y성분
//{
	//vy += accel;//속도 갱신. X성분은 가만히 두고 Y성분만 변화.
	//x += vx; //좌표 갱신
	//y += vy; //좌표 갱신
//}


void bossClass::fire()
{
}

void bossClass::render()
{

	_bulletPool->render();
	_bulletPool_YellowSTAR->render();
	//_bulletPool_BLUEBUBBLE->render();
	_bulletPool_BIGREDBUBBLE->render();
	_bulletPool_VERYLUEBUBBLE->render();
	bossImage->alphaRender(getMemDC(), bossImage->getX(), bossImage->getY(),alpha);

	_hpBar->render();
	sigongImage->render(getMemDC(),sigongImage->getX(),sigongImage->getY());

	if (_hitDamage)
	{
		TextOut(getMemDC(), 0, 300, "hitdamage : true", strlen("hitdamage : true"));
	}
	else if (!_hitDamage)
	{
		TextOut(getMemDC(), 0, 300, "hitdamage : false", strlen("hitdamage : false"));
	}
	//for (int i = 0; i < _bulletPool->getActiveBullet().size(); i++)
	//{
	//	Rectangle(getMemDC(), _bulletPool->getActiveBullet().at(i)->getRC().left, _bulletPool->getActiveBullet().at(i)->getRC().top,
	//		_bulletPool->getActiveBullet().at(i)->getRC().right, _bulletPool->getActiveBullet().at(i)->getRC().bottom);
	//}


	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
}

void bossClass::droppingBullet(float bulletX, float bulletY, float accel, float bulletSpeedX, float bulletSpeedY)
{
	bulletSpeedY += accel;//속도 갱신. X성분은 가만히 두고 Y성분만 변화.
	bulletX += (bulletSpeedX / bulletSpeedY); //좌표 갱신
	bulletY += (bulletSpeedY / bulletSpeedX); //좌표 갱신
	_bulletPool->fire(bulletX, bulletY, 180, bulletSpeedY);
}

void bossClass::imageMove(image * image, float x, float y, float speed)
{
	RECT rc;
	x += speed;
	image->render(getMemDC(), x, y);
}

void bossClass::collision()
{
	for (int i = 0; i < _bulletPool->getActiveBullet().size(); i++)
	{
		RECT temp;

		if (_bulletPool->getActiveBullet().at(i)->getRC().bottom>550 && IntersectRect(&temp,&_bulletPool->getActiveBullet().at(i)->getRC(), &_player->getRect()))
		{
			_player->setBoolDead(true);
			//bCollision = true;
		}
	}
	RECT temp2;
	if (IntersectRect(&temp2, &sigongRect, &_player->getRect()))
	{
		_player->setBoolDead(true);
	}
}

//void bossClass::hitDamage(float damage)
//{
//
//
//	_currentHP -= damage;
//	if (deltaTime < 2)
//	{
//		alpha -= 10;
//	}
//	if (deltaTime >= 2)
//	{
//		alpha = 255;
//		deltaTime = 0;
//	}
//
//}

void bossClass::hitDamage(float damage)
{

	startTime = deltaTime;
	_currentHP -= damage;
	_onHit = true;
	//deltaTime = TIMEMANAGER->getWorldTime();

}

void bossClass::AAA()
{
	_count++;
	
	if (_count % 2 == 0)
	{
		alpha = 0;
	}
	if (_count % 2 == 1)
	{
		alpha = 255;
	}


	if (startTime + 1 < deltaTime)
	{
		alpha = 255;
		_count = 0;
		_onHit = false;
	}
}
