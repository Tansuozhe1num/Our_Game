#pragma once
#include"EnemyAttack.h"
class Enemy {
public:
	int HP;
	int def;
	int Atk;

	BaseSkill* EnemySkill;

	void EnemyAttack() {
		EnemySkill->Attack();
	}

	void Enemy_Getdamage(int damage) {
		if (damage <= def)damage = 1;
		else damage -= def;

		HP -= damage;
		if (HP <= 0) Enemy_dead();
	}

	void Enemy_dead() {//�������ˣ�����ɾ�㣬�ѳ�����ĵ���������һ
		
	}
};

