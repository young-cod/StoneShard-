#pragma once
#include "gameNode.h"

#define TILESIZEX 26
#define TILESIZEY 26

#define SAMPLETILEX 11
#define SAMPLETILEY 9

#define TILEX 46
#define TILEY 39

#define OBJMAX 32
#define MAPMAX 2

enum IMAGETYPE
{
	S_DOOR,S_DOOR_LR,S_WINDOW,
	S_STATUE_L,S_STATUE_R,S_B1_EFFECT,
	S_TORCH,S_TRAP,S_BOX,S_FLY,
	NO_F,
	S_DOOR_L
};
enum TILETYPE
{
	STAGE1,
	STAGE2,
	VILLAGE,
	VILLAGEBOSS,
	DUNJEON
};

enum TERRAIN
{
	TR_NORMAL,
	TR_SET,
	WATER,
	TR_INVISIBLE,
	TR_WALL,
	TR_NONE,
	TR_PLAYER,
	TR_OBJ,
	TR_ENEMY
};

enum VISION
{
	V_YES,
	V_MID,
	V_NO
};

enum OBJECT
{
	BLOCK, BOX, TRAP,
	OBJ_WALL,
	OBJ_INVISIBLE,
	OBJ_NONE
};

struct tagObject
{
	OBJECT		object;
	IMAGETYPE	imgType;
	image*		img;
	string		name;
	RECT		rc;
	int			frameX;
	int			count;
};

struct tagTileInfo
{
	TILETYPE	type;
	string		name;
	RECT		rc;
	float	width, height;
};

struct tagTile
{
	string tileType;
	TERRAIN terrain; 
	IMAGETYPE imgType;
	VISION vision;
	image* img;
	RECT rc;
	RECT checkRect;
	int terrainX;
	int terrainY;
	int sizeX;
	int sizeY;
	bool isMove;
};

struct tagSampleTile
{
	string tileType;
	IMAGETYPE imgType;
	RECT rc;
	int frameX;
	int frameY;
};

struct tagButton
{
	image* img;
	IMAGETYPE imgType;
	RECT rc;
	string name;
	bool click;
};

struct tagTool
{
	image* img;
	RECT rc;
	RECT objRc;
	int page;
	int pageMax;
};

struct tagMapTool
{
	tagTool terrain;
	bool TR_isOpen;
	tagTool object;
	bool OBJ_isOpen;
	RECT rc;
	float width, height;
	bool isOn;
};

struct tagMouseDrag
{
	RECT rc;
	POINT start;
	POINT end;
	int currentStartX;
	int currentStartY;
	int currentEndX;
	int currentEndY;
	bool isDrag;
};

struct tagPage
{
	image* img;
	tagSampleTile tile[SAMPLETILEX*SAMPLETILEY];
};

struct tagCurrentObj
{
	image* img;
	string name;
	IMAGETYPE type;
	RECT rc;
	int frameX;
	bool frameOn;
	bool is;
	int count;
	int x, y;
};

class mapmap : public gameNode
{
private:
	//�� ����
	image*								_map;
	int									_cX,_cY;
	tagTileInfo							_tileInfo;
	string								_currentMap;
	
	//�� ����
	tagMapTool							_tool;
	image*								_sampleImg;
	tagMouseDrag						_dragMouse;

	//Ÿ�� ����
	tagTile								_tile[TILEX*TILEY];
	tagSampleTile						_sampleTile[SAMPLETILEX*SAMPLETILEY];

	//������Ʈ ����
	tagObject							_object;
	vector<tagCurrentObj>				_vObjList;
	vector<tagCurrentObj>::iterator		_viObjList;
	int									_objectSize;
	tagCurrentObj						_currentObj;

	//��ư ����(���� ��)
	tagButton							_btnMapList[MAPMAX];
	tagButton							_btnPlay;
	tagButton							_btnSave;
	tagButton							_btnLoad;
	tagButton							_btnMusic;

	//��ư ����(������Ʈ ��)
	tagButton							_btnObjList[OBJMAX];
	tagButton							_btnObjPage;
	tagButton							_btnObjSet;
	tagButton							_btnObjSelect;
	tagButton							_btnObjIV;
	tagButton							_btnObjWALL;
	tagButton							_btnObjPlayer;
	tagButton							_btnObjObject;
	tagButton							_btnObjEnemy;
	tagButton							_btnObjNONE;
	tagButton							_btnEraser;
	tagButton							_btnClear;
	//======================
	image*								light;
	image* statue;
	image* statueEffect;
	int sCount;
	int poolC;
	
public:
	mapmap() {};
	~mapmap() {};

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �ʱ� ���� �� �� ����
	void setup();
	void setImage();
	void setMap();
	void mapClipping();
	void cameraControl();

	//���� ���� �Լ�
	void sampleRender(tagObject object,int x, int y);

	//���̺� �ε�
	void save();
	void load();
	void clear();

	//��ư ����
	void buttonSet();
	void buttonRender();
	void buttonControl();

	//���� ���� �Լ�
	TERRAIN terrainSelect(int frameX, int frameY);
	void setTerrainRect(TERRAIN tr, int num);

	//������Ʈ ���� �Լ�
	OBJECT objSelect(int frameX, int frameY);
	int imgFrameSelect(IMAGETYPE type);
	void setOBJ(int num);
	void objectFrame();

	IMAGETYPE typeSet(int type);
	void mouseDetailControl();
	
	//�� ����
	void openTool();
	void dragField();

	//��Ʈ ������ֱ�
	void selectTileSet(int idX, int idY);
	void deleteRect(int idX, int idY);
};

