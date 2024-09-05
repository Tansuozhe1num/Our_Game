#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill() {}

//这个可以通过每个技能的ID和等级构造对象, 可能用于读取存档
Skill::Skill(int skillId_1,int skillLevel_1, int skillId_2, int skillLevel_2,int skillId_3, int skillLevel_3, int skillId_4, int skillLevel_4) {
	setLevel(skillId_1, skillLevel_1);
	setLevel(skillId_2, skillLevel_2);
	setLevel(skillId_3, skillLevel_3);
	setLevel(skillId_4, skillLevel_4);
}

//下面的方法参数都是技能的id
int Skill::getLevel(int skillId) {

	
	if (skillId == 1)
		return skillLevel_1;
	if (skillId == 2)
		return skillLevel_2;
	if (skillId == 3)
		return skillLevel_3;
	if (skillId == 4)
		return skillLevel_4;
	return -1;
}

//展示所有技能名字,介绍和等级还有本身属性
void Skill::skillShow() {
	cout << "技能展示" << endl;
	for (int i = 1; i < 4; i++) {
		cout << getSkillName(i) << endl << "等级为:" << getLevel(i) << endl << getDisc(i) << endl;
		cout << "技能耗蓝为:" << getNeedMP(i) << endl;
		cout << "技能伤害为:" << getAttack(i) << endl;
		cout << "技能对自身血量影响为:" << getRecoverHp(i) << endl;
	}
}

int Skill::getLevel_Max(int skillId) {
	
	if (skillId == 1)
		return skillLevel_Max_1;
	if (skillId == 2)
		return skillLevel_Max_2;
	if (skillId == 3)
		return skillLevel_Max_3;
	if (skillId == 4)
		return skillLevel_Max_4;
	return -1;
}

string Skill::getSkillName(int skillId) {
	if (skillId == 1)
		return skill_1Name;
	if (skillId == 2)
		return skill_2Name;
	if (skillId == 3)
		return skill_3Name;
	if (skillId == 4)
		return skill_4Name;
	return "没有这个技能";
}

string Skill::getDisc(int skillId) {
	if (skillId == 1)
		return skill_1Disc;
	if (skillId == 2)
		return skill_2Disc;
	if (skillId == 3)
		return skill_3Disc;
	if (skillId == 4)
		return skill_4Disc;
	return "没有这个技能";
}

int Skill::getNeedMP(int skillId) {
	if (skillId == 1)
		return skill_1NeedMp;
	if (skillId == 2)
		return skill_2NeedMp;
	if (skillId == 3)
		return skill_3NeedMp;
	if (skillId == 4)
		return skill_4NeedMp;
	return -1;
}

int Skill::getAttack(int skillId) {
	if (skillId == 1)
		return skill_1Attack;
	if (skillId == 2)
		return skill_2Attack;
	if (skillId == 3)
		return skill_3Attack;
	if (skillId == 4)
		return skill_4Attack;
	return -1;
}

int Skill::getRecoverHp(int skillId) {
	if (skillId == 1)
		return skill_1recoverHp;
	if (skillId == 2)
		return skill_2recoverHp;
	if (skillId == 3)
		return skill_3recoverHp;
	if (skillId == 4)
		return skill_4recoverHp;
	return -1;
}

int Skill::getSkillMoney(int skillId) {
	if (skillId == 1)
		return skill_1money;
	if (skillId == 2)
		return skill_2money;
	if (skillId == 3)
		return skill_3money;
	if (skillId == 4)
		return skill_4money;
	return -1;
}

int Skill::getSkillUpgradeMoney(int skillId) {
	if (skillId == 1)
		return skill_1upgerademoney;
	if (skillId == 2)
		return skill_2upgerademoney;
	if (skillId == 3)
		return skill_3upgerademoney;
	if (skillId == 4)
		return skill_4upgerademoney;
	return -1;
}

bool Skill::addLevel(int skillId) {
	if (getLevel(skillId) >= getLevel_Max(skillId)) {
		cout << "技能等级已满，无法加点。" << endl;
		return false;
	}
	else {
	
		//下面这些数值都是乱设置的,根据需要更改
		if (skillId == 1) {
			skillLevel_1++;//技能等级增加
			skill_1Attack += 5;//技能造成的伤害增加
			skill_1NeedMp += 5;//技能消耗的蓝增加, 也可以不增加
		}
		if (skillId == 2) {
			skillLevel_2++;
			skill_2Attack += 5;
			skill_2NeedMp += 5;
			skill_2recoverHp += -3;//这个是会给自己扣血的技能,但是伤害大
		}
			
		if (skillId == 3) {
			skillLevel_3++;
			skill_3Attack += 5;
			skill_3NeedMp += 5;
			skill_3recoverHp += 5;//这个是会给自己补血的技能.
		}
			
		if (skillId == 4) {
			skillLevel_4++;
			skill_4Attack += 5;
			skill_4NeedMp += 5;
		}
			
		cout << "成功添加一点！" << endl;
		return true;
	}
}

//设置技能等级,应该是读取存档的时候用的.存档只要记录技能ID和等级,再调用这个函数就可以读取技能的所有属性,还可以写一个构造函数,不知道用没有用.
void Skill::setLevel(int skillId, int level) {
	//不同的技能设置不同
	if (skillId == 1) {
		skillLevel_1 = level;
		if (level == 0) {
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}else if (level == 1) {
			//同一个技能等级不同时候的具体数值, 到时候再设
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}
		else if (level == 2) {
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}
		else if (level == 3) {
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}
		else if (level == 4) {
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}
		else if (level == 5) {
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}
	}

	if (skillId == 2) {
		skillLevel_2 = level;
		if (level == 0) {
			skill_2NeedMp;
			skill_2Attack;
			skill_2recoverHp;
		}else if (level == 1) {
			//同一个技能等级不同时候的具体数值, 到时候再设
			skill_2NeedMp;
			skill_2Attack;
			skill_2recoverHp;
		}
		else if (level == 2) {
			skill_2NeedMp;
			skill_2Attack;
			skill_2recoverHp;
		}
		else if (level == 3) {
			skill_2NeedMp;
			skill_2Attack;
			skill_2recoverHp;
		}
		else if (level == 4) {
			skill_2NeedMp;
			skill_2Attack;
			skill_2recoverHp;
		}
		else if (level == 5) {
			skill_2NeedMp;
			skill_2Attack;
			skill_2recoverHp;
		}
	}

	if (skillId == 3) {
		skillLevel_3 = level;
		if (level == 0) {
			skill_3NeedMp;
			skill_3Attack;
			skill_3recoverHp;
		}else if (level == 1) {
			//同一个技能等级不同时候的具体数值, 到时候再设
			skill_3NeedMp;
			skill_3Attack;
			skill_3recoverHp;
		}
		else if (level == 2) {
			skill_3NeedMp;
			skill_3Attack;
			skill_3recoverHp;
		}
		else if (level == 3) {
			skill_3NeedMp;
			skill_3Attack;
			skill_3recoverHp;
		}
		else if (level == 4) {
			skill_3NeedMp;
			skill_3Attack;
			skill_3recoverHp;
		}
		else if (level == 5) {
			skill_3NeedMp;
			skill_3Attack;
			skill_3recoverHp;
		}
	}

	if (skillId == 4) {
		skillLevel_4 = level;
		if (level == 0) {
			skill_4NeedMp;
			skill_4Attack;
			skill_4recoverHp;
		}else if (level == 1) {
			//同一个技能等级不同时候的具体数值, 到时候再设
			skill_4NeedMp;
			skill_4Attack;
			skill_4recoverHp;
		}
		else if (level == 2) {
			skill_4NeedMp;
			skill_4Attack;
			skill_4recoverHp;
		}
		else if (level == 3) {
			skill_4NeedMp;
			skill_4Attack;
			skill_4recoverHp;
		}
		else if (level == 4) {
			skill_4NeedMp;
			skill_4Attack;
			skill_4recoverHp;
		}
		else if (level == 5) {
			skill_4NeedMp;
			skill_4Attack;
			skill_4recoverHp;
		}
	}
}

//打Boss技能调用, 会直接改变人物和boss的血量
void Skill::useSkill(Player& pl, Boss& bo) {
	cout << "!: Choose your skill\n" << endl;
	while (1) {
		for (int i = 1; i < 4; i++) {
			if (!(getLevel(i) == 0)) {
				cout << getSkillName(i) << "(" << i << ")\t";
			}
		}
		cout << "不想使用技能(0)";
		int i = -1;
		cin >> i;
		if (i == 1) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "你对敌人造成了" << getAttack(i) << "伤害"<<endl;
			cout << "消耗蓝" << getNeedMP(i) << endl;
			cout << "自身血量变化" << getRecoverHp(i) << endl;

			break;
		}else if (i == 2) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "你对敌人造成了" << getAttack(i) << "伤害" << endl;
			cout << "消耗蓝" << getNeedMP(i) << endl;
			cout << "自身血量变化" << getRecoverHp(i) << endl;
			break;
		}
		else if (i == 3) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "你对敌人造成了" << getAttack(i) << "伤害" << endl;
			cout << "消耗蓝" << getNeedMP(i) << endl;
			cout << "自身血量变化" << getRecoverHp(i) << endl;
			break;
		}
		else if (i == 4) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "你对敌人造成了" << getAttack(i) << "伤害" << endl;
			cout << "消耗蓝" << getNeedMP(i) << endl;
			cout << "自身血量变化" << getRecoverHp(i) << endl;
			break;
		}
		else {
			cout << "选择无效,请重新选择"<<endl;
			continue;
		}
	}
}

//学习技能
void Skill::learnSkill(int &money) {
	cout << "请选择你想要学习或升级的技能" << endl;
	for (int i = 1; i < 4; i++){
		cout << getSkillName(i) << "(" << i << ")" << "\t\t";
	}
	cout << endl;
	int i = 0;
	cin >> i;
	if (getLevel(i)==0) {
		if (money < getSkillMoney(i)) {
			cout << "你的钱不足以学习该技能" << endl;
			return;
		}
		else {
			money -= getSkillMoney(i);
			addLevel(i);
			return;
		}
	}
	else {
		if (money < getSkillUpgradeMoney(i)) {
			cout << "你的钱不足以升级该技能" << endl;
			return;
		}
		else {
			money -= getSkillUpgradeMoney(i);
			addLevel(i);
			return;
		}
	}
}
	




