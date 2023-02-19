#pragma once

#include "ECSFlag.h"
#include "GameInfo.h"

class BaseComponent
{
	class Entity;

public:
	BaseComponent() = default;
	virtual ~BaseComponent() = default;

	Entity* entity = nullptr;

	virtual bool init() { return true; }
	virtual void draw() {};
	virtual void update() {};
};

