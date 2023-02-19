#pragma once

class Entity;

class SparseSetHandle
{
	friend class SparseSetContainer;

private :
	// 해당 Handle 을 가지고 있는 Component 가 사용하는 Sparse Set 에 접근할 것이다.
	size_t m_SparseSetIdx;

	// 해당 Component 를 지니고 있는 Entity 정보.
	Entity* m_Entity;
};

