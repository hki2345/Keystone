#pragma once
#include "KCore.h"
#include "KInitiator.h"

class KEngineinitiator : public KInitiator
{
public:
	KEngineinitiator();
	~KEngineinitiator() override;

public:
	void init() override;
};
