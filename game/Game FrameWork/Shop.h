#pragma once

#ifndef Shop//Shop define
#include<string>
#include<map>;

#define WeaponCount 3
#define SkillCount 4//�����Լ�д��ÿ�������Ĺ��ܺͽ�����������PlayerSkill


/// <summary>
/// Shop class��������Ϸ��������̵�ϵͳ
/// </summary>
class Shop {
public:
	const std::string Total_Skills[SkillCount];//ϵͳ��¼���еļ��ܣ���ɫ���Բ�ѯ���м��ܣ�ѧ�����ö�Ӧ����stringȥ��mapֵ���ó�1
	const std::string Total_Weapon[WeaponCount];

};


#endif // Shop