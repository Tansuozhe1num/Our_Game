#ifndef SKILL_H
#define SKILL_H

#include<string>
#include"player.h"
#include"Boss.h"
using namespace std;
class Skill {
protected:

	//������ܽ�Ϊ����,��������һ��,������һ��
	const string skill_1Name = "�ѿ�ն";

	//������ܹ������ϴ�,���ǻ�������Ѫ������.
	const string skill_2Name = "�ǳ���Ӱ";

	//������������˵�Ѫ, �����������϶�,����һ��
	const string skill_3Name = "Ѫ�⸴��";


	const string skill_4Name = "";


	const string skill_1Disc = "ʩչ���Լ�����ٶȻӶ����У�ʩչ��������ǰ���ĵ�����ɲ�С���˺�";
	const string skill_2Disc = "���л�����գ��·��ǳ���Ƭ���裬ǿ���Ľ�������͸���˵ķ�������ɹ㷺���˺�,����ʩ����������һ���ķ���";
	const string skill_3Disc = "�����ڹ������˸Ѫ��ɫ���ǹ⣬�����˵�������ת��Ϊʩ���ߵĻָ�������";
	const string skill_4Disc = "";

	//���ܵ�ǰ�ȼ�
	int skillLevel_1 = 0;			//�ڻ��๹�캯�����ʼ��
	int skillLevel_2 = 0;
	int skillLevel_3 = 0;
	int skillLevel_4 = 0;

	//ÿ�����ܵ���ߵȼ�
	int skillLevel_Max_1 = 5;		//ÿ�����ܵ���ߵȼ�
	int skillLevel_Max_2 = 5;		//�ڻ��๹�캯�����ʼ��
	int skillLevel_Max_3 = 5;
	int skillLevel_Max_4 = 5;

	//���ܺ���
	int skill_1NeedMp = 10;
	int skill_2NeedMp = 15;
	int skill_3NeedMp = 20;
	int skill_4NeedMp = 0;

	//�����˺�
	int skill_1Attack = 20;
	int skill_2Attack = 35;
	int skill_3Attack = 25;
	int skill_4Attack = 0;

	//���ܻظ�Ѫ��
	int skill_1recoverHp = 0;
	int skill_2recoverHp = -15;
	int skill_3recoverHp = +10;
	int skill_4recoverHp = 0;

	//ÿ�������õ�Ǯ
	int skill_1money = 50;
	int skill_2money = 60;
	int skill_3money = 70;
	int skill_4money = 100;

	//ÿ�����������õ�Ǯ
	int skill_1upgerademoney = 15;
	int skill_2upgerademoney = 20;
	int skill_3upgerademoney = 30;
	int skill_4upgerademoney = 50;
public:
	Skill();

	//������ȡ�浵ʱ�Ĺ��캯��
	Skill(int skillId_1, int skillLevel_1, int skillId_2, int skillLevel_2, int skillId_3, int skillLevel_3, int skillId_4, int skillLevel_4);

	~Skill() {};

	int getLevel(int skillId);		//�жϼ��ܵȼ����Ƿ�Ϊ����δϰ�ã���Ӧ�˺�
	bool addLevel(int skillId);	    //���Ӽ��ܵȼ���ÿ��һ��,ÿ�����ӵ�ʱ����������Ҳ��仯


	//�õ����ܵĸ�������
	int getLevel_Max(int skillId);	//�õ����ܵ���ߵȼ�
	string getSkillName(int skillId);		//�õ���������
	string getDisc(int skillId);		//�õ���������
	int getNeedMP(int skillId);		//�õ����ܺ���
	int getAttack(int skillId);	//�õ����ܵĹ�������ǿ
	int getRecoverHp(int skillId);	//�õ����ָܻ�������ֵ
	int getSkillMoney(int skillId);//�õ�ѧϰÿ�������õ�Ǯ
	int getSkillUpgradeMoney(int skillId);//�õ�ÿ�����������õ�Ǯ

	//���ü��ܵȼ�,�ȼ���������������Ҳ��ͬ������
	void setLevel(int skillId, int l);

	//ÿ�����ܶԵ���HPӰ��,���Լ�HP��Ӱ��,��������.
	void useSkill(Player& pl, Boss& bo);

	//��Ϊ�����Ҫ��˭����,��û��д
	void skillShow();
	


	//ѧϰ����
	void learnSkill(int &money);
}mySkill;
#endif // !SKILL_H