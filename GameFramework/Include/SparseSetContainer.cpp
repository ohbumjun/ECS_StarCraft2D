#include "SparseSetContainer.h"

BaseComponent* SparseSetContainer::GetComponentData(const SparseSetHandle& handle)
{
	size_t sparseIdx = handle.m_SparseSetIdx;

	return m_vecSparseSets[sparseIdx]->GetComponentData(handle.m_Entity);
}
