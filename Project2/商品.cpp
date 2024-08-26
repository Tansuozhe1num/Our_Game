/*
帮我生成6把刀，5个护具，6个饰品，4种药品，虚构名称用于小说写作
*/
/*刀具

黑铁农夫刀
龙啸战斧
喵喵手套
吗喽棍
附魔麒麟刺
深渊冰龙爪
血月斩魔刀
黄金幽灵之刃
护具

藤甲
烈焰马甲
银月护肩
巨人之力护甲
迷雾披风
饰品

增益戒指 coin
狂风之耳环
魂灵水晶项链+coin
光辉之星胸针  蓝
幽灵渡渡鸟手链 coin
镇静之心手环 蓝
药品

生命之露 血 80
基础恢复药水 血20
强效愈合药膏 血40
愈合之花精华  血60
星辰药剂 蓝65
魔力之酒 蓝45
活力果汁 蓝25
*/

#include"商品.h"
#include<iostream>
Goods::Goods(int id)
{
	switch (id)
	{
	case 0: {
		Id = id;
		name = "黑铁战刀";
		description = "造型和用料都一般般的普通刀器";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 1: {
		Id = id;
		name = "龙啸战斧";
		description = "斧身带有整条龙的手斧，造型精美，威力惊人";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 2: {
		Id = id;
		name = "喵喵手套";
		description = "和猫爪相同的手套，外形可爱，在攻击时还会发出喵喵声";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 3: {
		Id = id;
		name = "吗喽棍";
		description = "据说是和齐天大圣同款的棍棒，威力不俗";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 4: {
		Id = id;
		name = "附魔麒麟刺";
		description = "利用神兽麒麟的鳞甲制成的高威力近战武器，能在敌人露出破绽时给予致命一击";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 5: {
		Id = id;
		name = "黄金幽灵之刃";
		description = "锋利的刀口见证无数亡灵，黄金的外观承载非凡品质";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 6: {
		Id = id;
		name = "深渊冰龙爪";
		description = "来自极寒之地的裂缝里的冰龙的利爪，寒气凛冽，威力惊人";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 7: {
		Id = id;
		name = "血月斩魔刀";
		description = "非凡的品质和名称注定不凡的使命，在夜晚会有特殊效果";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 8: {
		Id = id;
		name = "柴刀";
		description = "山林樵夫用来砍柴的刀,做工粗糙,勉强可以用作武器";
		thing = 'W';
		addAttack = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 9: {
		Id = id;
		name = "藤甲";
		description = "使用最普通的藤曼制作而成的护甲";
		thing = 'P';
		reduceDam = 5;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 10: {
		Id = id;
		name = "烈焰马甲";
		description = "由火焰附魔而成的马甲，同时也能很好地保存核心温度";
		thing = 'P';
		reduceDam = 5;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 11: {
		Id = id;
		name = "银月护肩";
		description = "银月造型的护肩，外观和防御都不错";
		thing = 'P';
		reduceDam = 5;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 12: {
		Id = id;
		name = "巨人之力护甲";
		description = "穿上它，你也能拥有巨人的防御力";
		thing = 'P';
		reduceDam = 5;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 13: {
		Id = id;
		name = "迷雾披风";
		description = "作用和它的名字一样，充满神秘感和轻盈";
		thing = 'P';
		reduceDam = 5;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 14: {
		Id = id;
		name = "增益戒指";
		description = "正如其名，戴上以后可以增加击败怪物时的金币收入";
		thing = 'A';
		addIncome = 1.25;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 15: {
		Id = id;
		name = "狂风之耳环";
		description = "戴上它，在耳边聆听狂风的声音（增加少量气血）";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 16: {
		Id = id;
		name = "魂灵水晶项链";
		description = "由水晶构成的同时包含无数魂灵的精美项链，能增加收益";
		thing = 'A';
		addIncome = 1.5;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 17: {
		Id = id;
		name = "光辉之星胸针";
		description = "亮眼的胸针，也能增加你的气血";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 18: {
		Id = id;
		name = "渡渡鸟手环";
		description = "听说没有几个人见过渡渡鸟，但它能吸引渡渡鸟（增加你的血气）";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 19: {
		Id = id;
		name = "镇静之心手环";
		description = "当你遇到危机时能够帮助你保持镇静的神奇手环，也能增加你的气血";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 20: {
		Id = id;
		name = "基础恢复药水";
		description = "能够治疗一些轻伤，恢复20点生命值";
		thing = 'M';
		addHP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 21: {
		Id = id;
		name = "强效恢复药膏";
		description = "用料更加扎实的药品，恢复40点生命值";
		thing = 'M';
		addHP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 22: {
		Id = id;
		name = "愈合之花精华";
		description = "从稀有的愈合之花提取的产物，恢复60点生命值";
		thing = 'M';
		addHP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 23: {
		Id = id;
		name = "生命之露";
		description = "从生命之泉并经过数月提取制成的药品，恢复80点生命值";
		thing = 'M';
		addHP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 24: {
		Id = id;
		name = "活力果汁";
		description = "美味可口的果汁，还能放松心情，恢复25点气血值";
		thing = 'M';
		addMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 25: {
		Id = id;
		name = "魔力之酒";
		description = "魔法师酿造的美酒，恢复45点气血值";
		thing = 'M';
		addMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	case 26: {
		Id = id;
		name = "星辰药剂";
		description = "好像是从外太空带回来的产物，恢复65点气血值";
		thing = 'M';
		addMP = 10;
		buyprice = 200;
		sellprice = 50;
		break;
	}
	default:
		break;
	}
}

Goods::~Goods()
{

}

string Goods::Goods_Name()
{
	return string(name);
}

int Goods::Goods_Id()
{
	return Id;
}

string Goods::Goods_Description()
{
	return string(description)
}
//int Goods::Goods_Type()

int Goods::Add_Attack()
{
	return addAttack;
}

int Goods::Reduce_Dam()
{
	return reduceDam;
}

int Goods::Add_HP()
{
	return addHP;
}
//int Goods::Add_MaxHP()

int Goods::Add_MP()
{
	return addMP;
}
int Goods::Add_MaxMP()
{
	return addMaxMP;
}

int Goods::Buy_Price()
{
	return buyprice;
}

int Goods::Sell_Price()
{
	return sellprice;
}

void Goods::Goods_List()
{
	cout << name << endl;
	cout << description<< endl;
	if (thing == 'W') //武器
	{
		cout << "攻击力:" << addAttack << endl;
	}
	else if (thing == 'P') //防具
	{
		cout << "减伤:" << reduceDam << endl;
	}
	else if (thing == 'A') //饰品
	{
		cout << "增加收益:" << addIncome << endl;
		cout << "回复气血:" << addMP << endl;
	}
	else//药品
	{
		cout << "回复生命值:" << addHP << endl;
		cout << "回复气血:" << addMP << endl;
	}
}