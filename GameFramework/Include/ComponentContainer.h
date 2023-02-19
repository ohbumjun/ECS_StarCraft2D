#pragma once

#include "GameInfo.h"
#include "Flag.h"
#include "ComponentPool.h"

class ComponentContainer
{
	// entity 와 component type 을 넘겨주면 찾아주는 기능

	// 빈 entity 만들어내는 기능

	// 특정 entity 와 해당 entity 의 component container 들을 지워주는 기능

private :
	// Scene 내의 모든 Component Pool
	std::vector<ComponentPool>* m_ComponentPools;

};

