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

}


int Skill::getLevel_Max(int skillId) {
	/*
	switch (whatSkill) {
	case '1':return skillLevel_Max_1; break;
	case '2':return skillLevel_Max_2; break;
	case '3':return skillLevel_Max_3; break;
	case '4':return skillLevel_Max_4; break;
	default:return 0;
	}
	*/
	if (skillId == 1)
		return skillLevel_Max_1;
	if (skillId == 2)
		return skillLevel_Max_2;
	if (skillId == 3)
		return skillLevel_Max_3;
	if (skillId == 4)
		return skillLevel_Max_4;
}

string Skill::getSkillName(int skillId) {
	/*
	switch (whatSkill) {		//这种方法不行，程序崩溃。
	case '1':return skill_1Name;
	case '2':return skill_2Name;
	case '3':return skill_3Name;
	case '4':return skill_4Name;
	default:return NULL;
	}
	*/
	if (skillId == 1)
		return skill_1Name;
	if (skillId == 2)
		return skill_2Name;
	if (skillId == 3)
		return skill_3Name;
	if (skillId == 4)
		return skill_4Name;

}

string Skill::getDisc(int skillId) {
	/*
	switch (whatSkill) {
	case '1':return skill_1Disc; break;
	case '2':return skill_2Disc; break;
	case '3':return skill_3Disc; break;
	case '4':return skill_4Disc; break;
	default:return 0;
	}
	*/
	if (skillId == 1)
		return skill_1Disc;
	if (skillId == 2)
		return skill_2Disc;
	if (skillId == 3)
		return skill_3Disc;
	if (skillId == 4)
		return skill_4Disc;
}

int Skill::getNeedMP(int skillId) {
	/*
	switch (whatSkill) {
	case '1':return skill_1NeedMp; break;
	case '2':return skill_2NeedMp; break;
	case '3':return skill_3NeedMp; break;
	case '4':return skill_4NeedMp; break;
	default:return 0;
	}
	*/
	if (skillId == 1)
		return skill_1NeedMp;
	if (skillId == 2)
		return skill_2NeedMp;
	if (skillId == 3)
		return skill_3NeedMp;
	if (skillId == 4)
		return skill_4NeedMp;
}

double Skill::getAttack(int skillId) {
	/*
	switch (whatSkill) {
	case '1':return skill_1AddAttack; break;
	case '2':return skill_2AddAttack; break;
	case '3':return skill_3AddAttack; break;
	case '4':return skill_4AddAttack; break;
	default:return 0;
	}
	*/
	if (skillId == 1)
		return skill_1Attack;
	if (skillId == 2)
		return skill_2Attack;
	if (skillId == 3)
		return skill_3Attack;
	if (skillId == 4)
		return skill_4Attack;
}

int Skill::getRecoverHp(int skillId) {
	/*
	switch (whatSkill) {
	case '1':return skill_1recoverHp; break;
	case '2':return skill_2recoverHp; break;
	case '3':return skill_3recoverHp; break;
	case '4':return skill_4recoverHp; break;
	default:return 0;
	}
	*/
	if (skillId == 1)
		return skill_1recoverHp;
	if (skillId == 2)
		return skill_2recoverHp;
	if (skillId == 3)
		return skill_3recoverHp;
	if (skillId == 4)
		return skill_4recoverHp;
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
			skill_1Attack=+5;//技能造成的伤害增加
			skill_1NeedMp = +5;//技能消耗的蓝增加, 也可以不增加
		}
		if (skillId == 2) {
			skillLevel_2++;
			skill_2Attack=+5;
			skill_2NeedMp = +5;
			skill_2recoverHp += -3;//这个是会给自己扣血的技能,但是伤害大
		}
			
		if (skillId == 3) {
			skillLevel_3++;
			skill_3Attack=+5;
			skill_3NeedMp = +5;
			skill_3recoverHp += 5;//这个是会给自己补血的技能.
		}
			
		if (skillId == 4) {
			skillLevel_4++;
			skill_4Attack=+5;
			skill_4NeedMp = +5;
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
	




