#pragma once

#include<string>
using namespace std;

//商品类
class Goods
{
public:
	Goods();
	Goods(int id);//初始化商品
	~Goods();
	
	string Goods_Name();
	int Goods_Id();
	string Goods_Description();
	//int Goods_Type();
	int Add_Attack();
	int Reduce_Dam();
	//int Add_Defence();
	int Add_HP();
	//int Add_MaxHP();
	int Add_MP();
	int Add_MaxMP();
	
	int Buy_Price();
	int Sell_Price();
	void Goods_List();
	//商品属性


	string name;	//物品名称
	int Id;
	string description;	//物品描述
	char thing;//商品类型  W-weapon,P-protector,A-Accessories,M-medicine
	int addAttack = 0;	//增加攻击
	//int addDefence = 0;	//增加防御
	int addHP = 0;		//增加Hp
	//int addMaxHP = 0;	//增加max HP
	int addMP = 0;		//增加Mp
	int addMaxMP = 0;	//增加max MP
	int reduceDam = 0;//减少伤害
	double addIncome = 0;//增加金币
	int buyprice=0;
	int sellprice=0;
};