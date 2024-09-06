/*
��������6�ѵ���5�����ߣ�6����Ʒ��4��ҩƷ���鹹��������С˵д��
*/
/*����

����ũ��
��Хս��
��������
��ඹ�
��ħ�����
��Ԩ����צ
Ѫ��նħ��
�ƽ�����֮��
����

�ټ�
�������
���»���
����֮������
��������
��Ʒ

�����ָ coin
���֮����
����ˮ������+coin
���֮������  ��
����ɶ������� coin
��֮���ֻ� ��
ҩƷ

����֮¶ Ѫ 80
�����ָ�ҩˮ Ѫ20
ǿЧ����ҩ�� Ѫ40
����֮������  Ѫ60
�ǳ�ҩ�� ��65
ħ��֮�� ��45
������֭ ��25
*/

#include"Goods.h"
#include<iostream>

//Goods::Goods()
//{
//	Id = 0;
//	name = "";
//	description = "";
//	thing = ' ';
//	addAttack = 0;
//	buyprice = 0;
//	sellprice = 0;
//}

Goods::Goods() 
	: Id(0), name(""), description(""), thing(' '), addAttack(0), buyprice(0.0), sellprice(0.0) {}

Goods::Goods(int id)
{

	switch (id)
	{
	case 0: {
		Id = id;
		name = "����ս��";
		description = "���ͺ����϶�һ������ͨ����";
		thing = 'W';
		addAttack = 10;
		buyprice = 5;
		sellprice = 2;
		break;
	}
	case 1: {
		Id = id;
		name = "��Хս��";
		description = "����������������ָ������;�������������";
		thing = 'W';
		addAttack = 10;
		buyprice = 9;
		sellprice = 4;
		break;
	}
	case 2: {
		Id = id;
		name = "��������";
		description = "��èצ��ͬ�����ף����οɰ����ڹ���ʱ���ᷢ��������";
		thing = 'W';
		addAttack = 12;
		buyprice = 12;
		sellprice = 6;
		break;
	}
	case 3: {
		Id = id;
		name = "��ඹ�";
		description = "��˵�Ǻ������ʥͬ��Ĺ�������������";
		thing = 'W';
		addAttack = 10;
		buyprice = 15;
		sellprice = 9;
		break;
	}
	case 4: {
		Id = id;
		name = "��ħ�����";
		description = "��������������ۼ��Ƴɵĸ�������ս���������ڵ���¶������ʱ��������һ��";
		thing = 'W';
		addAttack = 10;
		buyprice = 17;
		sellprice = 10;
		break;
	}
	case 5: {
		Id = id;
		name = "�ƽ�����֮��";
		description = "�����ĵ��ڼ�֤�������飬�ƽ����۳��طǷ�Ʒ��";
		thing = 'W';
		addAttack = 10;
		buyprice = 17;
		sellprice = 12;
		break;
	}
	case 6: {
		Id = id;
		name = "��Ԩ����צ";
		description = "���Լ���֮�ص��ѷ���ı�������צ��������������������";
		thing = 'W';
		addAttack = 10;
		buyprice = 20;
		sellprice = 14;
		break;
	}
	case 7: {
		Id = id;
		name = "Ѫ��նħ��";
		description = "�Ƿ���Ʒ�ʺ�����ע��������ʹ������ҹ���������Ч��";
		thing = 'W';
		addAttack = 10;
		buyprice = 24;
		sellprice = 18;
		break;
	}

	case 8: {
		Id = id;
		name = "�ټ�";
		description = "ʹ������ͨ�������������ɵĻ���";
		thing = 'P';
		reduceDam = 5;
		buyprice = 3;
		sellprice = 1;
		break;
	}
	case 9: {
		Id = id;
		name = "�������";
		description = "�ɻ��渽ħ���ɵ���ף�ͬʱҲ�ܺܺõر�������¶�";
		thing = 'P';
		reduceDam = 5;
		buyprice = 7;
		sellprice = 3;
		break;
	}
	case 10: {
		Id = id;
		name = "���»���";
		description = "�������͵Ļ��磬��ۺͷ���������";
		thing = 'P';
		reduceDam = 5;
		buyprice = 11;
		sellprice = 5;
		break;
	}
	case 11: {
		Id = id;
		name = "����֮������";
		description = "����������Ҳ��ӵ�о��˵ķ�����";
		thing = 'P';
		reduceDam = 5;
		buyprice = 20;
		sellprice = 10;
		break;
	}
	case 12: {
		Id = id;
		name = "��������";
		description = "���ú���������һ�����������ظк���ӯ";
		thing = 'P';
		reduceDam = 5;
		buyprice = 30;
		sellprice = 15;
		break;
	}
	case 13: {
		Id = id;
		name = "�����ָ";
		description = "���������������Ժ�������ӻ��ܹ���ʱ�Ľ������";
		thing = 'A';
		addIncome = 1.25;
		buyprice = 30;
		sellprice = 20;
		break;
	}
	case 14: {
		Id = id;
		name = "���֮����";
		description = "���������ڶ���������������������������Ѫ��";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 20;
		sellprice = 10;
		break;
	}
	case 15: {
		Id = id;
		name = "����ˮ������";
		description = "��ˮ�����ɵ�ͬʱ������������ľ�������������������";
		thing = 'A';
		addIncome = 1.5;
		buyprice = 40;
		sellprice = 30;
		break;
	}
	case 16: {
		Id = id;
		name = "���֮������";
		description = "���۵����룬Ҳ�����������Ѫ";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 15;
		sellprice = 7;
		break;
	}
	case 17: {
		Id = id;
		name = "�ɶ����ֻ�";
		description = "��˵û�м����˼����ɶ��񣬵����������ɶ����������Ѫ����";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 22;
		sellprice = 11;
		break;
	}
	case 18: {
		Id = id;
		name = "��֮���ֻ�";
		description = "��������Σ��ʱ�ܹ������㱣���򾲵������ֻ���Ҳ�����������Ѫ";
		thing = 'A';
		addMaxMP = 10;
		buyprice = 25;
		sellprice = 15;
		break;
	}
	case 19: {
		Id = id;
		name = "�����ָ�ҩˮ";
		description = "�ܹ�����һЩ���ˣ��ָ�20������ֵ";
		thing = 'M';
		addHP = 10;
		buyprice = 6;
		sellprice = 4;
		break;
	}
	case 20: {
		Id = id;
		name = "ǿЧ�ָ�ҩ��";
		description = "���ϸ�����ʵ��ҩƷ���ָ�40������ֵ";
		thing = 'M';
		addHP = 10;
		buyprice = 10;
		sellprice = 7;
		break;
	}
	case 21: {
		Id = id;
		name = "����֮������";
		description = "��ϡ�е�����֮����ȡ�Ĳ���ָ�60������ֵ";
		thing = 'M';
		addHP = 10;
		buyprice = 15;
		sellprice = 10;
		break;
	}
	case 22: {
		Id = id;
		name = "����֮¶";
		description = "������֮Ȫ������������ȡ�Ƴɵ�ҩƷ���ָ�80������ֵ";
		thing = 'M';
		addHP = 10;
		buyprice = 20;
		sellprice = 15;
		break;
	}
	case 23: {
		Id = id;
		name = "������֭";
		description = "��ζ�ɿڵĹ�֭�����ܷ������飬�ָ�25����Ѫֵ";
		thing = 'M';
		addMP = 10;
		buyprice = 6;
		sellprice = 3;
		break;
	}
	case 24: {
		Id = id;
		name = "ħ��֮��";
		description = "ħ��ʦ��������ƣ��ָ�45����Ѫֵ";
		thing = 'M';
		addMP = 10;
		buyprice = 9;
		sellprice = 6;
		break;
	}
	case 25: {
		Id = id;
		name = "�ǳ�ҩ��";
		description = "�����Ǵ���̫�մ������Ĳ���ָ�65����Ѫֵ";
		thing = 'M';
		addMP = 10;
		buyprice = 25;
		sellprice = 15;
		break;
	}
	default:
		Id = id;
		name = "δ֪��Ʒ";
		description = "û����������Ʒ";
		thing = ' ';
		addAttack = 0;
		buyprice = 0;
		sellprice = 0;
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
	return string(description);
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
	cout << description << endl;
	if (thing == 'W') //����
	{
		cout << "������:" << addAttack << endl;
	}
	else if (thing == 'P') //����
	{
		cout << "����:" << reduceDam << endl;
	}
	else if (thing == 'A') //��Ʒ
	{
		cout << "��������:" << addIncome << endl;
		cout << "�ظ���Ѫ:" << addMP << endl;
	}
	else//ҩƷ
	{
		cout << "�ظ�����ֵ:" << addHP << endl;
		cout << "�ظ���Ѫ:" << addMP << endl;
	}
}