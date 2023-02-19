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

	// �̰Ÿ� �� template ���� ó���ؾ� �� ??..... ���� 
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

	size_t m_Type;			   // �ش� Component Pool �� �ٷ�� Data �� Type
	size_t m_ElementSize{ 0 }; // �� ���� Component Data ũ��
	size_t m_PageSize;
	size_t m_Cnt;  // ���ݱ��� ��� Data �� �׿��°�.
	std::vector<int> m_DenseArray;

	// Entity Idx �������� ��Ƶ� ���̴�. 
	// �ش� Component �� ��� ���� ���� Entity Idx ���� �⺻������ 0 �� ����ǰ� �Ѵ�.
	// Entity �� ó�� idx �� 1 �� �����ϰ� ����
	std::vector<int> m_SparseArray; 

	// pagination �ϱ� ���� ��
	char* m_VecDataBuffer;
};

