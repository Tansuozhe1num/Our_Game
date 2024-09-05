#ifndef SKILL_H
#define SKILL_H

#include<string>
#include"player.h"
#include"Boss.h"
using namespace std;
class Skill {
protected:

	//这个技能较为基础,攻击能力一般,消耗蓝一般
	const string skill_1Name = "裂空斩";

	//这个技能攻击力较大,但是会扣自身的血量和蓝.
	const string skill_2Name = "星辰裂影";

	//这个技能吸敌人的血, 但是消耗蓝较多,攻击一般
	const string skill_3Name = "血光复苏";


	const string skill_4Name = "";


	const string skill_1Disc = "施展者以极快的速度挥动剑刃，施展剑法，对前方的敌人造成不小的伤害";
	const string skill_2Disc = "剑刃划过天空，仿佛星辰碎片飞舞，强力的剑气波穿透敌人的防御，造成广泛的伤害,但对施术者自身有一定的反噬";
	const string skill_3Disc = "剑刃在光辉下闪烁血红色的星光，将敌人的生命力转化为施术者的恢复能力。";
	const string skill_4Disc = "";

	//技能当前等级
	int skillLevel_1 = 0;			//在基类构造函数里初始化
	int skillLevel_2 = 0;
	int skillLevel_3 = 0;
	int skillLevel_4 = 0;

	//每个技能的最高等级
	int skillLevel_Max_1 = 5;		//每个技能的最高等级
	int skillLevel_Max_2 = 5;		//在基类构造函数里初始化
	int skillLevel_Max_3 = 5;
	int skillLevel_Max_4 = 5;

	//技能耗蓝
	int skill_1NeedMp = 10;
	int skill_2NeedMp = 15;
	int skill_3NeedMp = 20;
	int skill_4NeedMp = 0;

	//技能伤害
	int skill_1Attack = 20;
	int skill_2Attack = 35;
	int skill_3Attack = 25;
	int skill_4Attack = 0;

	//技能回复血量
	int skill_1recoverHp = 0;
	int skill_2recoverHp = -15;
	int skill_3recoverHp = +10;
	int skill_4recoverHp = 0;

	//每个技能用的钱
	int skill_1money = 50;
	int skill_2money = 60;
	int skill_3money = 70;
	int skill_4money = 100;

	//每个技能升级用的钱
	int skill_1upgerademoney = 15;
	int skill_2upgerademoney = 20;
	int skill_3upgerademoney = 30;
	int skill_4upgerademoney = 50;
public:
	Skill();

	//用来读取存档时的构造函数
	Skill(int skillId_1, int skillLevel_1, int skillId_2, int skillLevel_2, int skillId_3, int skillLevel_3, int skillId_4, int skillLevel_4);

	~Skill() {};

	int getLevel(int skillId);		//判断技能等级（是否为零尚未习得）对应伤害
	bool addLevel(int skillId);	    //增加技能等级，每次一级,每次增加的时候其他属性也会变化


	//得到技能的各种属性
	int getLevel_Max(int skillId);	//得到技能的最高等级
	string getSkillName(int skillId);		//得到技能名字
	string getDisc(int skillId);		//得到技能描述
	int getNeedMP(int skillId);		//得到技能耗蓝
	int getAttack(int skillId);	//得到技能的攻击力加强
	int getRecoverHp(int skillId);	//得到技能恢复的生命值
	int getSkillMoney(int skillId);//得到学习每个技能用的钱
	int getSkillUpgradeMoney(int skillId);//得到每个技能升级用的钱

	//设置技能等级,等级设置完其他属性也会同步设置
	void setLevel(int skillId, int l);

	//每个技能对敌人HP影响,对自己HP的影响,蓝的消耗.
	void useSkill(Player& pl, Boss& bo);

	//因为不清楚要用谁调用,就没有写
	void skillShow();
	


	//学习技能
	void learnSkill(int &money);
}mySkill;
#endif // !SKILL_H