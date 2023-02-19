#pragma once

#include "GameInfo.h"
#include "Flag.h"
#include "BaseComponent.h"

class ComponentPool
{
private :
	std::list<BaseComponent*> m_CompList;

	// 어떤 type 의 Component를 보관하는가
	size_t m_Type;
};

