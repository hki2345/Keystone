#pragma once
#include "Tank.h"

class EnemyTank : public Tank
{
public:
	EnemyTank();
	~EnemyTank();


private:
	float fDirChangeCurTime;
	float fDirChangeTime;

	float fShootCurTime;
	float fShootTime;

public:
	void create() override;
	bool init() override;
	void update() override;

private:
	void update_AI();
	void update_move();
	void update_collisiontile();


	void stay_tile(KOne* _Tile) override;
	void exit_tile(KOne* _Tile) override;
};
