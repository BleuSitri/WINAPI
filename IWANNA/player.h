#pragma once
#include "Character.h"
#include "objectPool.h"
//#include "scene1_1.h"

#define PLAYERSPEED 5
#define JUMPPOWER 3
#define GRAVITY 2

//class scene1_1;
class bossClass;
class player : public Character
{
protected:
	//Character* _player;
private:
	//Character* _player;
	image* _player;
	image* _scene1_1MG;
	image* _scene1_2MG;
	image* _scene1_3MG;
	image* _scene1_4MG;
	image* _bossMapMG;
	image* _gameOver;

	bossClass* _bc;

	RECT rc;
	RECT tempGroundRc;
	MOVEDIRECTION playerMove;
	
	Tile* _tile;

	objectPool* _bulletPool;

	int jFlag;

	float jumpCount;
	float jumpSpeed;

	float jumpPower;
	float _gravity;

	bool _isDrop;

	bool _isLeft;
	bool _isGround;
	bool _isJump;
	bool _isBool;
	//int _stageFlag;
	bool _isDead;

	bool _moveBackScene;

	int _currentFrameX;
	int _currentFrameY;
	int _count;
	int _index;
	int _deadIndex;

	int _stageFlag;

	float fallSpeed;

	bool secondJump;
	bool firstJump;
	bool _isSJump;
	bool _canMove;
	//scene1_1* _scene11;

	bool _isLoad;
	bool _pCollision;


	POINT pt;
	RECT mouseRECT;
	float deltaTime;
	float x;
	float y;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void move();
	void fire();
	void jump();
	void Doublejump();
	void render();

	int deadCount;

	bool getGroundBool() { return _isGround; }
	bool getJumpBool() { return _isJump; }
	bool getLeftBool() { return _isLeft; }
	

	image* getPlayerImage() { return _player; }

	void setCollision(bool isBool)
	{
		_isBool = isBool;
	}

	void setDrop(bool isDrop)
	{
		_isDrop = isDrop;
	}

	void setGravity(float gravity)
	{
		_gravity = gravity;
	}

	void dead();
	void gameOver();

	//int getPlayerBool() { return _stageFlag; }

	void setStageFlag(int stageFlag) { _stageFlag = stageFlag; }

	COLORREF characterPixelbottomMove();
	COLORREF characterPixelrightMove();
	COLORREF characterPixeltopMove();
	COLORREF characterPixelleftMove();
	COLORREF bulletMove();

	void setEnemyMemoryLink(bossClass* bc) { _bc = bc; }
	//void setScene1_1MemoryLink(scene1_1* scene11) { _scene11 = scene11; }


	int getStageFlag() { return _stageFlag; }

	RECT getRect() { return rc; }

	void collision();

	//bool getLoad() { return _isLoad; }
	//void setLoad(bool isLoad) { _isLoad = isLoad; }

	int getDeadCount() { return deadCount; }

	//void mouseMove(float speed, float x, float y);
	void setBoolDead(bool isDead) { _isDead = isDead; }
	bool getBoolDead() { return _isDead; }

	bool getpCollision() { return _pCollision; }

	void setBack(bool moveBackScene) { _moveBackScene = moveBackScene; }
	bool getBack() { return _moveBackScene; }

	RECT bulletRECT()
	{
		for (int i = 0; i < _bulletPool->getActiveBullet().size(); i++)
		{
			return _bulletPool->getActiveBullet().at(i)->getRC();
		}
	}
	
};

