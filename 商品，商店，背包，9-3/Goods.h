#pragma once

#include<string>
using namespace std;

//��Ʒ��
class Goods
{
public:
	Goods();
	Goods(int id);//��ʼ����Ʒ
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
	//��Ʒ����


	string name;	//��Ʒ����
	int Id;
	string description;	//��Ʒ����
	char thing;//��Ʒ����  W-weapon,P-protector,A-Accessories,M-medicine
	int addAttack = 0;	//���ӹ���
	//int addDefence = 0;	//���ӷ���
	int addHP = 0;		//����Hp
	//int addMaxHP = 0;	//����max HP
	int addMP = 0;		//����Mp
	int addMaxMP = 0;	//����max MP
	int reduceDam = 0;//�����˺�
	double addIncome = 0;//���ӽ��
	int buyprice=0;
	int sellprice=0;
};