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

};