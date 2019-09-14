#pragma once
#include <KComponent.h>
#include <KVector.h>
#include <vector>


class Explosion_Effect;
class KSprite_Animator;
class KRect_Collision;
class Bullet;
class Tile;
class Tank : public KComponent
{
public:
	Tank();
	~Tank();

protected:
	enum TANK_STATUS
	{
		TS_RESPAWN = 0,
		TS_PLAY,
		TS_DIE,
	};

protected:
	TANK_STATUS eCurState;

	std::vector<Bullet*> VectorMyBullet;
	Explosion_Effect* MyEffect;
	KSprite_Animator* MyAnimator;
	KRect_Collision* MyCollider;

	KPos2 vPrevDir;
	KPos2 vDir;
	KPos2 vPrevChecPos;
	float fSpeed;

	bool bTileCol;
	bool bTankCol;

	Tile* PrevColTile;
	Tank* PrevColTank;

	float fRespawnCurTime;
	float fRespawnTime;
public:

	virtual void create() override;
	virtual bool init() override;
	void set_tank(const KPos2& _StartPos);
	virtual void update() override;

protected:
	virtual void update_respawn();
	virtual void update_play();
	virtual void update_die();

	void update_coltile();
	void update_checkingpos();
	void shoot_bullet();

	virtual void update_move();



	virtual void stay_tile(KOne* _Tile);
	virtual void exit_tile(KOne* _Tile);
};
