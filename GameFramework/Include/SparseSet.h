#pragma once

#include "ECSFlag.h"
#include "GameInfo.h"

class Entity;
class BaseComponent;

class SparseSet
{
	friend class SparseSetContainer;

public:
	SparseSet(size_t elementsize)
	{
		m_ElementSize = elementsize;
		m_SparseArray.resize(MAX_ENTITIES);
		m_VecDataBuffer = new char[m_ElementSize * MAX_ENTITIES];
	}

	~SparseSet()
	{
		delete[] m_VecDataBuffer;
	}

	// inline void* get(size_t index)
	// {
	// 	// index : Entity id
	// 	// looking up the component at the desired index
	// 	return pData + index * m_ElementSize;
	// }

	// void insert(const Entity* id, const T& component);

	// 이거를 다 template 으로 처리해야 함 ??..... 으아 
	void insert(Entity* const id);

	void erase(EntityId id) {
		// Remove the component from the SparseSet at the entity ID's index
		if (id < sparseSet.size()) {
			sparseSet[id] = T();
		}
	}

	bool contains(EntityId id) const {
		// Check if the SparseSet contains a component at the entity ID's index
		return id < sparseSet.size() && sparseSet[id] != T();
	}

	T& get(EntityId id) {
		// Get a reference to the component at the entity ID's index
		return sparseSet[id];
	}

	const T& get(EntityId id) const {
		// Get a const reference to the component at the entity ID's index
		return sparseSet[id];
	}


private:
	BaseComponent* GetComponentData(Entity* Entity);

	size_t m_Type;			   // 해당 Component Pool 이 다루는 Data 의 Type
	size_t m_ElementSize{ 0 }; // 각 실제 Component Data 크기
	size_t m_PageSize;
	size_t m_Cnt;  // 지금까지 몇개의 Data 가 쌓였는가.
	std::vector<int> m_DenseArray;

	// Entity Idx 정보들을 모아둘 것이다. 
	// 해당 Component 를 들고 있지 않은 Entity Idx 에는 기본적으로 0 이 저장되게 한다.
	// Entity 의 처음 idx 는 1 로 시작하게 세팅
	std::vector<int> m_SparseArray; 

	// pagination 하기 위한 것
	char* m_VecDataBuffer;
};

