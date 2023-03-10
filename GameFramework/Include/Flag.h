#pragma once

#include <bitset>

class Component;

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentMask = std::bitset<MAX_COMPONENTS>;
using ComponentTypeID = std::size_t;
using EntityID = unsigned long long;
using EntityIndex = unsigned int;
using EntityVersion = unsigned int;


enum EKeyState
{
	KeyState_Down,
	KeyState_Push,
	KeyState_Up,
	KeyState_Max
};

enum class ETexture_Type
{
	Atlas,
	Frame
};

enum ETexture_Dir
{
	Texture_Left,
	Texture_Right,
	Texture_End
};

enum class ECollider_Type
{
	Box,
	Sphere,
	Point
};

enum class EBullet_Type
{
	Light,
	Medium,
	Heavy,
	Boss
};

enum class EGun_Type
{
	Pistol,
	ShotGun,
	BossGun
};

enum EGunClass
{
	Light,
	Medium,
	Heavy,
	Boss,
	End
};


enum ECollision_Channel
{
	Channel_Object,
	Channel_Player,
	Channel_Monster,
	Channel_PlayerAttack,
	Channel_MonsterAttack,
	Channel_Wall,
	Channel_Max
};

enum class ECollision_State
{
	Ignore,
	Collision
};

enum class EButton_State
{
	Normal,
	MouseOn,
	Click,
	Disable,
	End
};

enum class EChar_Type
{
	Ass,
	Biu,
	Jimmy,
	Pinky,
	Punny,
	Raff
};

enum class EObject_Type
{
	GameObject,
	Character,
	Monster,
	Player,
	Potion,
	Weapon,
	Obstacle,
	Coin,
	Equipment,
	Bullet,
	WallObject,
	NPC,
	Effect
};

enum class ESceneStage
{
	One,
	Two,
	Boss
};

enum class EMonster_Type
{
	Duck1,
	Duck2,
	Duck3,
	Turtle1,
	Turtle2,
	Turtle3,
	KamiKaze1,
	KamiKaze2,
	KamiKazeCage1,
	KamiKazeCage2,
	Tentacle,
	Boss
};

enum class EShield_Type
{
	Turtle,
	Player,
	Boss
};

enum class EPotion_Type
{
	HP,
	MP
};

enum class EEquip_Type
{
	Attack,
	Armor
};

enum class ENpc_Type
{
	Hp,
	Mp,
	Shield
};

enum class EDoorStage_Type
{
	Stage_Default,
	Stage_Home,
	Stage_One,
	Stage_Two,
	Stage_Three
};

enum class ETileOption
{
	Normal,
	Wall,
	MonsterLight,
	MonsterMedium,
	MonsterHard,
	End
};

enum class ETileEditMode
{
	Option,
	Image,
	End
};