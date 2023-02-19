#pragma once

#include "GameInfo.h"
#include "Flag.h"
#include "BaseComponent.h"

class ComponentPool
{
private :
	std::list<BaseComponent*> m_CompList;

	// � type �� Component�� �����ϴ°�
	size_t m_Type;
};

