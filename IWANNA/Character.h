#pragma once
#include "gameNode.h"
#include"progressBar.h"


class Character : public gameNode
{

private:
//	vector<tagBullet> _vBullet;
//	vector<tagBullet>::iterator _viBullet;

protected:
	//RECT rc;
public:
	Character();
	~Character();

	virtual HRESULT init();
	virtual void release();
	virtual void move();
	virtual void fire();
	virtual void jump();
	virtual void update();
	virtual void render();

//	vector<tagBullet> getVBullet() { return _vBullet; }
//	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }
};

