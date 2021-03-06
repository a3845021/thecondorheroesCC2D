#ifndef __STATE_H__
#define __STATE_H__


class BaseHero;

/**
* Class State
*/
class State
{
public:
	State();
	~State();
	virtual void execute(BaseHero* hero);

	static State* m_state;

	static State* getInstance();
};

/**
* Class Running
*/
class Running : public State
{
public:
	Running();
	~Running();

	void execute(BaseHero *hero);

	static Running* m_run;

	static Running* getInstance();
};

/**
* Class Idling
*/
class Idling : public State
{
public:
	Idling();
	~Idling();
	void execute(BaseHero *hero);
	static Idling *m_idle;

	static Idling* getInstance();
};

/**
* Class Jumping
*/
class Jumping : public State
{
public:
	Jumping();
	~Jumping();
	void execute(BaseHero *hero);
	static Jumping* m_jump;

	static Jumping* getInstance();
};

/**
* Double jump                                                                     
*/
class DoubleJumping : public State
{
public:
	DoubleJumping();
	~DoubleJumping();
	void execute(BaseHero *hero);
	static DoubleJumping* m_doubleJump;

	static DoubleJumping* getInstance();
};

/**
* Class Landing
*/
class Landing : public State
{
public:
	Landing();
	~Landing();

	void execute(BaseHero *hero);

	static Landing* m_land;

	static Landing* getInstance();
};


/**
* Class Injured                                                                     
*/
class Injuring : public State
{
public:
	Injuring();
	~Injuring();

	void execute(BaseHero *hero);
	static Injuring * m_injured;
	static Injuring* getInstance();
};


/**
* Class Dead
*/
class Dead : public State
{
public:
	Dead();
	~Dead();

	void execute(BaseHero *hero);
	static Dead * m_dead;
	static Dead* getInstance();
};

/**
* Class Attack                                                                    
*/
class AttackNormal : public State 
{
public:
	AttackNormal();
	~AttackNormal();

	void execute(BaseHero *hero);
	static AttackNormal * m_attack;
	static AttackNormal* getInstance();
};

/**
* Class Revive
*/
class Revive : public State
{
public:
	Revive();
	~Revive();

	void execute(BaseHero *hero);
	static Revive * m_revive;
	static Revive* getInstance();
};


// make life easier
#define MIdle Idling::getInstance()
#define MRun Running::getInstance()
#define MJump Jumping::getInstance()
#define MLand Landing::getInstance()
#define MAttack AttackNormal::getInstance()
#define MRevive Revive::getInstance()
#define MInjured Injuring::getInstance()
#define MDoubleJump DoubleJumping::getInstance()
#define MDie Dead::getInstance()

#endif
