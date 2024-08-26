#pragma once

#ifndef Shop//Shop define
#include<string>
#include<map>;

#define WeaponCount 3
#define SkillCount 4//个数自己写，每个武器的功能和介绍能力等在PlayerSkill


/// <summary>
/// Shop class，管理游戏里里面的商店系统
/// </summary>
class Shop {
public:
	const std::string Total_Skills[SkillCount];//系统记录所有的技能，角色可以查询所有技能，学技能拿对应技能string去把map值设置成1
	const std::string Total_Weapon[WeaponCount];

};


#endif // Shop