#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Hud.h"
#include "DuongQua.h"
#include "Global.h"
#include "GLES-Render.h"
#include "EnemyWooder.h"
#include "EnemyToanChanStudent.h"
#include "EnemyToanChanStudent2.h"
#include "boss1\EnemyBoss1.h"
#include "EffectManager.h"
#include "Coin.h"
#include "CollisionListener.h"
#include "InfiniteParallaxNode.h"
#include "CoinBag.h"
#include "CoinBullion.h"


USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
	
	static cocos2d::Scene* createScene();
	virtual bool init();

private:

	// props
	const Size SCREEN_SIZE = Director::getInstance()->getVisibleSize();
	float scaleOfMap;
	TMXTiledMap* tmx_map;
	TMXTiledMap *tmx_mapboss[2];
	int indexOfNextMapBoss;// chi so cua map boss cuoi, khoi dau la -1, khi danh boss chuyen 1 va 0(0101010101)

	b2World *world;
	GLESDebugDraw *debugDraw;
	Mat4 _modelViewMV;
	CustomCommand _customCommand;

	Follow *camera;
	Node* follow;
	CCRect left_corner;


	BaseHero *hero;
	InfiniteParallaxNode *background;

	// skeleton cache
	spSkeletonData *sr_toanchan1;
	spSkeletonData *sr_wooder;
	//end skeleton cache


	// Create Function
	void createDuongQua(string path_Json, string path_Atlas, Point position);


	// function for process box2d
	void draw(Renderer * renderer, const Mat4 & transform, uint32_t flags);
	void onDraw();
	void initB2World();
	void updateB2World(float dt);

	/**
	* Only create ground physic                                                                     
	*/
	void initGroundPhysic(b2World *world, Point pos, Size size);
	void initUnderGroundPhysic(b2World *world, Point pos, Size size);

	// function for process map
	void loadBackground();
	void createInfiniteNode();
	void createGroundBody();
	void createGroundForMapBoss();
	void creatEnemyWooder();
	void creatEnemyToanChanStudent();
	void creatEnemyToanChanStudent2();
	void creatBoss();


	void createCoint();
	void createCointBag();
	void createCoinBullion();
	void createTimCoin();
	void createParapolCoin();
	void createCircleCoin();
	void createSquareCoin();


	//skeleton data
	//spSkeletonData* createSkeletonData(string atlasFile, string jsonFile);
	// sau va cham body cua cac quai khong con static nua
	// do do se bi roi xuong
	// bat su kien roi xuong qua man hinh de don dep map
	
	void danceWithEffect();
	void danceWithCamera();

	// read file Json
	void readWriteJson();

	// touch listener
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

public:
    
	// update functions
	void checkActiveButton();
	void listener();		// attack button listener | see update function
	void update(float dt);
	void updateEnemy();
	void updateBoss();
	//void cleanMap();

	// cache function
	void cachePlist();
	void cacheSkeleton();


	// shaking
	void shakeTheScreen();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
