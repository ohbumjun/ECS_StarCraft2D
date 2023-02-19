#pragma once

#include "BaseComponent.h"
#include "Flag.h"

class Entity
{
	friend class ECS;

public:
	Entity(EntityID pId, ComponentMask pMask)
	{
		m_Id = pId;
		m_Mask = pMask;
	};

	inline const EntityIndex GetEntityIndex()
	{
		return m_Id >> 32;
	}

	inline const EntityVersion GetEntityVersion()
	{
		return (EntityVersion)m_Id;
	}

	// Entity Destroy 여부를 살피기 위함 
	inline void IncEntityVersion()
	{
		m_Id += 1;
	}

	inline bool IsEntityValid()
	{
		return (m_Id >> 32) != (EntityIndex)(-1);
	}

	template<typename T>
	inline void addComponent()
	{
		mask[getComponentTypeID<T>()] = true;
	}

private:
	EntityID m_Id;
	ComponentMask m_Mask;

};
