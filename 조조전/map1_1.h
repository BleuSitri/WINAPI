#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include "defeatScene.h"
#include "victoryScene.h"
#define PHEONIXTILEX 7
#define PHEONIXTILEY 7

class map1_1 : public gameNode
{
private:

	HANDLE file;
	DWORD write;
	DWORD read;


	tagCurrentTile _currentTile;
	tagTile _tiles[TILEX* TILEY];

	image* pheonixSkillImage;
	int pheonixSkillCurrentFrameX;
	int pheonixSkillCurrentFrameY;
	int pheonixCount;
	bool fireEffectOn;

	int fireEffectCurrentFrameX;
	int fireEffectCurrentFrameY;
	int	fireEffectCount;
	int skillHitNum;

	bool showSkillDmg;

	bool isMagicMotion;

	bool isPheonixSkill;
	bool _canMagic;
	RECT skillRect;
	RECT skillCancleRect;
	bool isMagicRangeOn;
	int pheonixSkillArray[49] = { 0,0,0,1,0,0,0,
0,0,1,1,1,0,0,
0,1,1,1,1,1,0,
1,1,1,1,1,1,1,
0,1,1,1,1,1,0,
0,0,1,1,1,0,0,
0,0,0,1,0,0,0, };

	bool _isDebug;

	tagCharacter _character;

	//일단 포인터를 없애서 테스트중
	vector<tagCharacter> _myArmyVector;
	vector<tagCharacter> _enemyVector;

	vector<tagCharacter>::iterator _imyArmyVector;
	vector<tagCharacter>::iterator _ienemyVector;

	//속성부여
	DWORD _attribute[TILEX* TILEY];


	//저장오류 떠서 이렇게라도 했다. 이미지 저장하고 불러오는거 다시 고치자!
	vector<image*> _faceSelectVector;
	vector<image*> _characterSelectVector;
	vector<image*> _characterAttackVector;
	vector<image*> _characterDefVector;
	vector<image*> _characterDoneVector;




	vector<int> openList;
	vector<int>closeList;
	vector<int>::iterator iter;
	stack<int> moveStack;


	Select currentSelect;

	int startTile;
	int endTile;
	int currentTile;
	bool isFind;
	bool noPath;
	bool startAstar;


	RECT rc[6];


	HBRUSH brush;
	HFONT font, oldFont;
	char str[128];
	int temp;


	vector<int> _floodFillTilesVector;
	int _testNum;

	bool _canMove;
	bool _moveComplete;
	int _selectNum;

	int _hitNum;

	vector<int> _attackRangeTilesVector;
	vector<RECT> _attackRangeTilesRectVector;

	bool _attackOptionMenu;

	int _weatherCount;
	int _weatherFrameX;
	int _weatherFrameY;

	bool _isShowState;

	RECT _battleOption;
	RECT _battleOptionAttack;
	RECT _battleOptionMagic;
	RECT _battleOptionItem;
	RECT _battleOptionDone;
	RECT _battleOptionCancle;

	bool _canAttack;
	image* _attackTileImage;

	//int moveSpeed[10] = { 1,2,3,4,6,8,12,16,24,48 };
	int moveSpeed[7] = { 1,2,3,4,6,8,12 };
	int moveSpeedIndex = 0;

	int attackArrayCount;

	bool showRange;

	int prevTile;
	CHARACTERDIRECTION prevDirection;

	int attackDeltaTime;
	int _attackCount;

	int count;


	progressBar* _hpBar;
	progressBar* _mpBar;
	progressBar* _expBar;
	vector<progressBar*> _hpBarEnemyVector;
	vector<progressBar*> _mpBarEnemyVector;
	vector<progressBar*> _expBarEnemyVector;

	vector<progressBar*> _hpBarMyVector;
	vector<progressBar*> _mpBarMyVector;
	vector<progressBar*> _expBarMyVector;

	progressBar* _dmgBar;
	float _maxDMG;
	float _currentDMG;

	int fontSize;
	int _turnFlag;
	int _doneCount;

	bool _myTurnImage;
	bool _enemyTurnImage;
	float _turnImageTime;


	vector<int> _tileVector;
	vector<int> _fNumVector;
	int gg;
	int ggCount;
	int minTileF;
	int minTile;
	int minTileNumber;

	bool AIisFind;
	bool AInoPath;
	bool AIstartAstar;
	vector<int> _AIopenList;
	vector<int> _AIcloseList;

	vector<int> AIaStarOpenList;
	vector<int> AIaStarCloseList;

	

	stack<int> AImoveStack;
	int AIendTile;
	int AIcurrentTile;

	int AICount;
	int AIFloodFillCount;

	bool AIFloodFillCheck;
	bool AIMoveStart;
	//int AIendTile;

	bool AIClear;
	//아군 맞는거 체크
	int beHitTileNum;
	int beHitNum;
	bool isAttach;
	int stackTop;

	vector<int> AIendTileVector;
	int aiVectorCount;

	int mostDmg;

	int clickCount;
	int doubleClickTile;

	int myArmyDeadCount;
	int enemyDeadCount;

	bool isVictory;
	bool isDefeat;

	int turnCount;

	bool myArmyShowState;

public:
	map1_1();
	~map1_1();

	HRESULT init();
	void release();
	void update();
	void render();

	void load();


	void tileCheck();

	void Astar();

	void floodFill(int tile, int moveCount);


	void animation();

	void move(int i);
	//void enemyMove(int i);
	void enemyVectorMove(int i);

	tagTile* getMap() { return _tiles; }


	void AI();
	void AIAstar();
	int AIgetTile(int tile);
	void AIfloodFill(int tile, int moveCount);

	//속성
	DWORD* getAttribute() { return _attribute; }
	
	
	
	
	void tempFunction();

	void pheonixSkill();
	void fireEffect();
};

