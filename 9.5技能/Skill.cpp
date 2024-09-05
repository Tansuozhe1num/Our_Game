#include <iostream>
#include "Skill.h"

using namespace std;

Skill::Skill() {}

//�������ͨ��ÿ�����ܵ�ID�͵ȼ��������, �������ڶ�ȡ�浵
Skill::Skill(int skillId_1,int skillLevel_1, int skillId_2, int skillLevel_2,int skillId_3, int skillLevel_3, int skillId_4, int skillLevel_4) {
	setLevel(skillId_1, skillLevel_1);
	setLevel(skillId_2, skillLevel_2);
	setLevel(skillId_3, skillLevel_3);
	setLevel(skillId_4, skillLevel_4);
}

//����ķ����������Ǽ��ܵ�id
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

//չʾ���м�������,���ܺ͵ȼ����б�������
void Skill::skillShow() {
	cout << "����չʾ" << endl;
	for (int i = 1; i < 4; i++) {
		cout << getSkillName(i) << endl << "�ȼ�Ϊ:" << getLevel(i) << endl << getDisc(i) << endl;
		cout << "���ܺ���Ϊ:" << getNeedMP(i) << endl;
		cout << "�����˺�Ϊ:" << getAttack(i) << endl;
		cout << "���ܶ�����Ѫ��Ӱ��Ϊ:" << getRecoverHp(i) << endl;
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
	return "û���������";
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
	return "û���������";
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
		cout << "���ܵȼ��������޷��ӵ㡣" << endl;
		return false;
	}
	else {
	
		//������Щ��ֵ���������õ�,������Ҫ����
		if (skillId == 1) {
			skillLevel_1++;//���ܵȼ�����
			skill_1Attack += 5;//������ɵ��˺�����
			skill_1NeedMp += 5;//�������ĵ�������, Ҳ���Բ�����
		}
		if (skillId == 2) {
			skillLevel_2++;
			skill_2Attack += 5;
			skill_2NeedMp += 5;
			skill_2recoverHp += -3;//����ǻ���Լ���Ѫ�ļ���,�����˺���
		}
			
		if (skillId == 3) {
			skillLevel_3++;
			skill_3Attack += 5;
			skill_3NeedMp += 5;
			skill_3recoverHp += 5;//����ǻ���Լ���Ѫ�ļ���.
		}
			
		if (skillId == 4) {
			skillLevel_4++;
			skill_4Attack += 5;
			skill_4NeedMp += 5;
		}
			
		cout << "�ɹ����һ�㣡" << endl;
		return true;
	}
}

//���ü��ܵȼ�,Ӧ���Ƕ�ȡ�浵��ʱ���õ�.�浵ֻҪ��¼����ID�͵ȼ�,�ٵ�����������Ϳ��Զ�ȡ���ܵ���������,������дһ�����캯��,��֪����û����.
void Skill::setLevel(int skillId, int level) {
	//��ͬ�ļ������ò�ͬ
	if (skillId == 1) {
		skillLevel_1 = level;
		if (level == 0) {
			skill_1NeedMp;
			skill_1Attack;
			skill_1recoverHp;
		}else if (level == 1) {
			//ͬһ�����ܵȼ���ͬʱ��ľ�����ֵ, ��ʱ������
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
			//ͬһ�����ܵȼ���ͬʱ��ľ�����ֵ, ��ʱ������
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
			//ͬһ�����ܵȼ���ͬʱ��ľ�����ֵ, ��ʱ������
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
			//ͬһ�����ܵȼ���ͬʱ��ľ�����ֵ, ��ʱ������
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

//��Boss���ܵ���, ��ֱ�Ӹı������boss��Ѫ��
void Skill::useSkill(Player& pl, Boss& bo) {
	cout << "!: Choose your skill\n" << endl;
	while (1) {
		for (int i = 1; i < 4; i++) {
			if (!(getLevel(i) == 0)) {
				cout << getSkillName(i) << "(" << i << ")\t";
			}
		}
		cout << "����ʹ�ü���(0)";
		int i = -1;
		cin >> i;
		if (i == 1) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "��Ե��������" << getAttack(i) << "�˺�"<<endl;
			cout << "������" << getNeedMP(i) << endl;
			cout << "����Ѫ���仯" << getRecoverHp(i) << endl;

			break;
		}else if (i == 2) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "��Ե��������" << getAttack(i) << "�˺�" << endl;
			cout << "������" << getNeedMP(i) << endl;
			cout << "����Ѫ���仯" << getRecoverHp(i) << endl;
			break;
		}
		else if (i == 3) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "��Ե��������" << getAttack(i) << "�˺�" << endl;
			cout << "������" << getNeedMP(i) << endl;
			cout << "����Ѫ���仯" << getRecoverHp(i) << endl;
			break;
		}
		else if (i == 4) {
			bo.HP -= getAttack(i);
			pl.HP += getRecoverHp(i);
			pl.MP -= getNeedMP(i);
			cout << "��Ե��������" << getAttack(i) << "�˺�" << endl;
			cout << "������" << getNeedMP(i) << endl;
			cout << "����Ѫ���仯" << getRecoverHp(i) << endl;
			break;
		}
		else {
			cout << "ѡ����Ч,������ѡ��"<<endl;
			continue;
		}
	}
}

//ѧϰ����
void Skill::learnSkill(int &money) {
	cout << "��ѡ������Ҫѧϰ�������ļ���" << endl;
	for (int i = 1; i < 4; i++){
		cout << getSkillName(i) << "(" << i << ")" << "\t\t";
	}
	cout << endl;
	int i = 0;
	cin >> i;
	if (getLevel(i)==0) {
		if (money < getSkillMoney(i)) {
			cout << "���Ǯ������ѧϰ�ü���" << endl;
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
			cout << "���Ǯ�����������ü���" << endl;
			return;
		}
		else {
			money -= getSkillUpgradeMoney(i);
			addLevel(i);
			return;
		}
	}
}
	




