#pragma once
#include"Player.h"

/// <summary>
/// 基础攻击
/// </summary>
class BaseSkill {//等待实现，就是boss使用的技能，判断角色是否受到攻击再扣血，实现方式等待挖掘，这个是小兵的攻击
public:
	BaseSkill() {};
	BaseSkill(int BossAtk)
		:BaseAttack(BossAtk) {}

	virtual void Attack() {
		player.Get_Damage(BaseAttack);//角色收到BaseAttack点伤害（平a）
	}

protected:
	int BaseAttack;//初始攻击直接从boss获取
};

class Atk1 : public BaseSkill {//第一种攻击方式，从屏幕上掉下障碍物，每次只能wasd，躲避完全就不扣血，否则一次就扣除 设定的对应血量
	const int Atk = 50;//攻击
	void Attack() override {

	}
};