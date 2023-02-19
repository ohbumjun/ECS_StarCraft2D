#pragma once

class Entity;

class SparseSetHandle
{
	friend class SparseSetContainer;

private :
	// �ش� Handle �� ������ �ִ� Component �� ����ϴ� Sparse Set �� ������ ���̴�.
	size_t m_SparseSetIdx;

	// �ش� Component �� ���ϰ� �ִ� Entity ����.
	Entity* m_Entity;
};

