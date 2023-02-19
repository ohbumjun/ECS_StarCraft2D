#pragma once

#include "GameInfo.h"
#include "SparseSet.h"
#include "ECSFlag.h"
#include "SparseSetHandle.h"

class BaseComponent;

class SparseSetContainer
{
	friend class ComponentContainer;

private :
	BaseComponent* GetComponentData(const SparseSetHandle& handle);

	std::vector<SparseSet*> m_vecSparseSets;
};

