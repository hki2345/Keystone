#pragma once


class KOne;
class PtrOf_KOne
{
public:
	PtrOf_KOne() : pKOne(nullptr) {};
	PtrOf_KOne(const PtrOf_KOne& _Core) = delete;
	PtrOf_KOne(const PtrOf_KOne&& _Core) = delete;
	void operator=(const PtrOf_KOne& _Core) = delete;
	~PtrOf_KOne() {};

private:
	KOne* pKOne;

public:
	inline KOne* one()
	{
		return pKOne;
	}

	inline void one(KOne* _One)
	{
		pKOne = _One;
	}
};
