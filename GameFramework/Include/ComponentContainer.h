#pragma once

#include "GameInfo.h"
#include "Flag.h"
#include "ComponentPool.h"

class ComponentContainer
{
	// entity �� component type �� �Ѱ��ָ� ã���ִ� ���

	// �� entity ������ ���

	// Ư�� entity �� �ش� entity �� component container ���� �����ִ� ���

private :
	// Scene ���� ��� Component Pool
	std::vector<ComponentPool>* m_ComponentPools;

};

