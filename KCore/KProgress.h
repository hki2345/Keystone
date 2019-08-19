#pragma once
#include "KInitiator.h"
#include "KUpdater.h"
#include "KReleaser.h"



class KProgress : public KInitiator, KUpdater, KReleaser
{
public:
	KProgress();
	KProgress(const KProgress& _Core) = delete;
	KProgress(const KProgress&& _Core) = delete;
	void operator=(const KProgress& _Core) = delete;
	virtual ~KProgress() = 0;

public:
	virtual void init() override = 0;
	virtual void update() override = 0;
	virtual void release() override = 0;
};
