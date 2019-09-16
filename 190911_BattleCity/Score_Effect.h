#pragma once
#include <KComponent.h>
#include <KVector.h>


class KText_Render;
class Score_Effect : public KComponent
{
public:
	Score_Effect();
	~Score_Effect();




private:
	KOne* MyTarget;
	KText_Render* MyRender;

	float fFloatingCurTime;
	float fFloatingTime;

public:
	void create() override;
	void set_score(const KPos2& _Pos, const int& _Score);

	void update() override;
};
