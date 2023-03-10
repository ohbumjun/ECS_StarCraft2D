#pragma once

#include <bitset>

class Component;

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentMask = std::bitset<MAX_COMPONENTS>; // 32bit 짜리 데이터 

// Component 각각의 고유 ID
using ComponentTypeID = std::size_t;
using EntityID = unsigned long long;
using EntityIndex = unsigned int;
using EntityVersion = unsigned int;

inline ComponentTypeID getUniqueComponentID()
{
	static ComponentTypeID lastID = 1;
	return lastID++;
}

// 각 Type 에 따라 getComponentTypeID() 함수는 한개씩 만들어진다.
// 함수 내의 static 변수의 경우 함수 하나에 대해 한번씩만 메모리에 할당된다. (해당 함수 처음 호출할 때만 할당된다 !!)
// 이후 같은 Type 에 따라 getComponentTypeID() 를 호출하면 이미 static const 인 변수 정보를 그대로 리턴하는 것이다.
// 즉, Type 별로 한번만 getUniqueComponentID() 를 호출한다는 것이다.
// 어차피 메모리에 할당된 녀석이고, 모든 함수들이 공유하는 것이기 때문이다.
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

// ECS Recyle Flag 를 위한 Node 구조체
struct DestroyedEntity
{
	DestroyedEntity* m_Next;

	// Entity 의 idx 정보만 들고 있게 하기
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

