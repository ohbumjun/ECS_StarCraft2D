#pragma once

#include <bitset>

class Component;

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentMask = std::bitset<MAX_COMPONENTS>; // 32bit ¥�� ������ 

// Component ������ ���� ID
using ComponentTypeID = std::size_t;
using EntityID = unsigned long long;
using EntityIndex = unsigned int;
using EntityVersion = unsigned int;

inline ComponentTypeID getUniqueComponentID()
{
	static ComponentTypeID lastID = 1;
	return lastID++;
}

// �� Type �� ���� getComponentTypeID() �Լ��� �Ѱ��� ���������.
// �Լ� ���� static ������ ��� �Լ� �ϳ��� ���� �ѹ����� �޸𸮿� �Ҵ�ȴ�. (�ش� �Լ� ó�� ȣ���� ���� �Ҵ�ȴ� !!)
// ���� ���� Type �� ���� getComponentTypeID() �� ȣ���ϸ� �̹� static const �� ���� ������ �״�� �����ϴ� ���̴�.
// ��, Type ���� �ѹ��� getUniqueComponentID() �� ȣ���Ѵٴ� ���̴�.
// ������ �޸𸮿� �Ҵ�� �༮�̰�, ��� �Լ����� �����ϴ� ���̱� �����̴�.
template<typename T>
inline ComponentTypeID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value, "Type not base on component!");

	static  ComponentTypeID typeID = getUniqueComponentID();

	return typeID;
}

// Entity ID
inline EntityID CreateEntityId(EntityIndex index, EntityVersion version)
{
	return ((EntityID)index << 32) | ((EntityID)version);
}

// ECS Recyle Flag �� ���� Node ����ü
struct DestroyedEntity
{
	DestroyedEntity* m_Next;

	// Entity �� idx ������ ��� �ְ� �ϱ�
	EntityIndex idx;
};

/*
inline EntityIndex GetEntityIndex(EntityID id)
{
	return id >> 32;
}

inline EntityVersion GetEntityVersion(EntityID id)
{
	return (EntityVersion)id;
}

inline bool IsEntityValid(EntityID id)
{
	return (id >> 32) != (EntityIndex)(-1);
}
*/

