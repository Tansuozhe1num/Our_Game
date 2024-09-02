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

	void Enemy_dead() {//怪物死了，把他删点，把场景里的敌人数量减一
		
	}
};

