#include "SparseSet.h"
#include "Entity.h"

void SparseSet::insert(Entity* const entity)
{
	// 이미 있는지 검색
	int entityIdx = entity->GetEntityIndex();

	if (m_SparseArray[entityIdx] != 0)
		return;

	// Add the component to the SparseSet at the entity ID's index
	if (m_Cnt >= m_DenseArray.capacity()) {
		m_DenseArray.resize(m_Cnt * 2);
	}

	m_DenseArray.push_back(entityIdx);
	m_SparseArray[entityIdx] = m_DenseArray.size() - 1;

	T* comp = new (m_VecDataBuffer[m_ElementSize * m_DenseArray.size()])) T(std::forward<TArgs>(args)...);
	T* comp = new (componentPools[componentId]->get(idx)) T(std::forward<TArgs>(args)...);

	// set bit info
	entities[idx].addComponent<T>(comp);

	return entities[idx].getComponent<T>();
}

BaseComponent* SparseSet::GetComponentData(Entity* Entity)
{
	const int& denseIdx = m_SparseArray[Entity->GetEntityIndex()];

	// 해당 Entity 는 해당 Component 를 사용하지 않는다는 것.
	if (denseIdx == 0)
		assert(false);

	return reinterpret_cast<BaseComponent*>(m_VecDataBuffer[denseIdx * m_ElementSize]);
}
