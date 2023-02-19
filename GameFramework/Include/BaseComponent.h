#pragma once

#include "ECSFlag.h"
#include "GameInfo.h"

class BaseComponent
{
	class Entity;

public:
	BaseComponent() = default;
	virtual ~BaseComponent() = default;

	virtual bool init() { return true; }
	virtual void draw() {};
	virtual void update();
	virtual void updateLogic() {};

	void SetVersion(int v)
	{
		m_Version = v;
	}
	int GetVersion()
	{
		return m_Version;
	}

private :
	Entity* m_Entity = nullptr;
	int m_Version = 0;
};

