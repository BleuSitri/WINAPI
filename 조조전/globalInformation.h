#pragma once
//#include "progressBar.h"

//================맵툴==============================
#define TILESIZE 48 //오른쪽 화면 타일 사이즈
#define TILEX 20	//왼쪽화면 타일 사이즈 X
#define TILEY 20	//왼쪽화면 타일 사이즈 Y


#define TILESIZEX TILEX * TILESIZE
#define TILESIZEY TILEY * TILESIZE

//화면 오른쪽 이미지 타일 갯수
#define SAMPLETILEX 3
#define SAMPLETILEY 11


//비트연산을 하기 위해 
#define ATTR_UNMOVABLE 0x00000001
#define ATTR_POSITION 0x00000002

#define ATTACKTILEX 7
#define ATTACKTILEY 7

enum Select
{
	SELECT_START,
	SELECT_END,
	SELECT_BLOCK,
	SELECT_NONE
};
enum Direction
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFTUP,
	DIRECTION_RIGHTDOWN,
	DIRECTION_LEFTDOWN,
	DIRECTION_RIGHTUP
};

enum State
{
	STATE_NONE,
	STATE_OPEN,
	STATE_CLOSE,
	STATE_PATH
};


//맵툴에서 사용할 녀석
enum CTRL
{
	CTRL_SAVE,
	CTRL_LOAD,
	CTRL_TERRAINDRAW,
	CTRL_OBJDRAW,
	CTRL_ERASER,
	CTRL_DISTINCTION,
	CTRL_MAP1,
	CTRL_MAP2,
	CTRL_END
};

//지형(EX.밟을때 사운드를 나게 하거나 이동할 수 없는 지역등등)
enum TERRAIN
{
	TR_RIVER, TR_OCEAN, TR_POND, TR_DITCH, TR_SHIP, TR_SNOWLAND, TR_FORTRESS,
	TR_TOWN, TR_HOUSE, TR_BARRACK, TR_ALTAR, TR_FENCE, TR_TREASURE, TR_GRASS, TR_UNDERGROUND,
	TR_FLATLAND, TR_WASTELAND, TR_MOUNTAIN, TR_FOREST, TR_WETLAND, TR_RAPIDS, TR_CLIFF,
	TR_ROCKMOUNTAIN, TR_BRIDGE, TR_RAMPART, TR_CASTLELAND, TR_FIRE, TR_GATEWAY,
	TR_CASTLE, TR_CASTLEGATE, TR_NONE
};

//오브젝트(EX :지형위쪽에 배치. 움직이거나 부서지거나 하는 녀석 등등 변화를 줄수 있는 물체)
enum OBJECT
{
	OBJ_MINE,
	OBJ_ALLY,
	OBJ_ENEMY,
	OBJ_NONE,
};

enum DISTINCTION
{
	DISTIN_MINE,
	DISTIN_ALLY,
	DISTIN_ENEMY,
	DISTIN_NONE,
};
//위치 좌표
enum POS
{
	POS_CHARACTER1,
	POS_CHARACTER2
};

//캐릭터 enum
enum CHARACTERTYPE
{
	CHARACTER_MINE,
	CHARACTER_ALLY,
	CHARACTER_ENEMY,
	CHARACTER_NONE,
};

enum CHARACTERDIRECTION
{
	CHARACTER_DIRECTION_LEFT,
	CHARACTER_DIRECTION_RIGHT,
	CHARACTER_DIRECTION_TOP,
	CHARACTER_DIRECTION_BOTTOM,
};

//이걸 굳이??
//enum ACTIONDIRECTION
//{
//	ACTIONDIRECTION_LEFT,
//	ACTIONDIRECTION_RIGHT,
//	ACTIONDIRECTION_TOP,
//	ACTIONDIRECTION_BOTTOM,
//};


enum ITEMTYPE
{
	ITEM_SWORD,
	ITEM_SPEAR,
	ITEM_BOW,
	ITEM_FAN,
	ITEM_ARMOR,
	ITEM_CLOTH,
	ITEM_ASSIST,
	ITEM_POTION,
};

struct tagItem
{
	//char name[128];
	const char* name;
	image* itemImage;
	image* itemIcon;
	ITEMTYPE itemType;
	int price;
	int level;
	int exp;
	int stat;
	int count;

	//장비하고 있는 개수
	int number;
	//가지고 있는 총 개수
	int totalNumber;

	bool canEquip;
	RECT rc;

};

struct tagCharacter
{
	//string name;
	char name[128];
	char classType[128];

	CHARACTERDIRECTION direction;
	//string classType;
	image* characterFaceImage;
	image* characterMoveImage;
	image* characterAttackImage;
	image* characterDefImage;
	image* characterDoneImage;

	//vector<int> attackTileVector;
	int attackArray[49];
	//int attackTileVectorSize;

	char faceImageKey[128];
	char moveImageKey[128];
	char attackImageKey[128];
	char defImageKey[128];
	char doneImageKey[128];

	int faceImageNum;
	int moveImageNum;
	int attackImageNum;
	int defImageNum;
	int doneImageNum;

	int level;
	int hp;
	int mp;
	int str;
	int dex;
	int intelligence;
	int luck;
	int cmd;

	int atk;
	int mAtk;
	int def;
	int spd;
	int morale;
	int move;

	int increaseAtk;
	int increaseMAtk;
	int increaseDef;
	int increaseSpd;
	int increaseMorale;

	RECT rc;
	int x;
	int y;
	int count;
	int currentFrameX;
	int currentFrameY;

	int prevPosition;
	int currentPosition;

	bool isAttack;
	bool isAttackMotion;
	bool isMagic;
	bool isMagicMotion;
	bool isItem;
	bool isItemMotion;
	bool isDone;
	bool isDoneMotion;
	bool isCancle;

	bool isSelect;

	int attackFrameX;
	int attackFrameY;
	int attackCount;

	int itemFrameX;
	int itemFrameY;
	int itemCount;

	int magicFrameX;
	int magicFrameY;
	int magicCount;

	int doneFrameX;
	int doneFrameY;
	int doneCount;
	//image* characterAttackImage;
	//image* characterDefImage;
	//image* characterDoneImage;

	//char attackImageKey[128];
	//char defImageKey[128];
	//char doneImageKey[128];

	//int attackImageNum;
	//int defImageNum;
	//int doneImageNum;

	int currentHp;
	int maxHp;
	int currentMp;
	int maxMp;
	int currentExp;
	int maxExp;

	int currentDmg;
	int maxDmg;

	int tile;

	bool _beHitMotion;
	bool _beHit;
	//int exp;
	//int currentExp;
	//int maxExp;

	//bool isMove;
	bool normalState;
	bool canCounterAttack;
	bool levelUp;
	bool classUp;

	int increaseHp;
	int increaseMp;

	bool isErase;
	bool isDead;
	bool isRun;

	//아이템도 넣어야한다.
	vector<tagItem> characterItemVector;
	//vector<tagItem*> characterItemVector;
};



//타일 구조체
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	DISTINCTION dis;

	//
	tagCharacter tileCharacter;

	RECT rc;


	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
	int disFrameX;
	int disFrameY;

	bool block;

	int node;

	int showState;

	int f, g, h;

	bool floodFill;
	bool attackRange;
	bool itemRange;
	bool magicRange;

	bool canMove;
	//tagCharacter tileCharacter;

	bool canFireMagic;
	bool canWaterMagic;
	bool canEarthMagic;
	bool canWindMagic;

	bool teamBlock;

	bool isMagicMotion;

};
//이미지 타일 구조체
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
//현재 타일 구조체
struct tagCurrentTile
{
	int x;
	int y;
};


enum ATTACKTILETYPE
{
	ATTACKTILE_NONE,
	ATTACKTILE_ATTACKRANGE
};

struct tagAttackTile
{
	ATTACKTILETYPE attackTileType;
	int node;
	int attackTileFrameX;
	int attackTileFrameY;
	RECT rc;
};



//vector<tagCharacter*> _myArmyVector;
//vector<tagCharacter*> _enemyVector;