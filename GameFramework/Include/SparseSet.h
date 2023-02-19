#pragma once

#include "ECSFlag.h"

class SparseSet
{
public:
	SparseSet(size_t elementsize)
	{
		elementSize = elementsize;
		pData = new char[elementSize * MAX_ENTITIES];
	}

	~SparseSet()
	{
		delete[] pData;
	}

	inline void* get(size_t index)
	{
		// index : Entity id
		// looking up the component at the desired index
		return pData + index * elementSize;
	}

private:
	char* pData{ nullptr };
	size_t elementSize{ 0 };
};

