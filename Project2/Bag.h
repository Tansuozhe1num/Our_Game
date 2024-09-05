#pragma once

#ifndef BAG_H
#define BAG_H

#include <string>
#include"Goods.h"
#include <map>
#include <iomanip>
#include<string>


using namespace std;

class Bag {


public:
    void Show_Items() const; // ��ʾ�����е���Ʒ
    void Add_Item(const string& name, int quantity, const string& category); // �����Ʒ
    void Use_Item(const string& name, int quantity);  // ʹ����Ʒ
    void Sell_Item(const string& name, int quantity);  // ������Ʒ                      
    int Get_Totalitems() const;         // ��ȡ��Ʒ����

    void In_Gold(int amount);                             // ���ӽ��
    void Out_Gold(int amount);                           // ���Ľ��
    void Show_Gold() const;                                // ��ʾ�������


    int gold;
    map<string, pair<int, string>> items;// �洢��Ʒ���ơ����������
};

#endif

/*���жϱ������Ƿ�����Ʒ��Ȼ����������ʾ��û�������û�У��еĻ��Ͱ�˳��������������Ʒ
�Ͷ�Ӧ��������ע�������ʽҪ��������֤�����ԣ�Ȼ��ʵ�������Ʒ�Ĺ��ܣ�������ӵ���Ʒ��Ϣ
����ӵ���Ʒ��װ���������ߣ���Ʒ��ҩƷ���з��ࣻȻ���Ƕ�ʹ�û���������Ʒ���м��ٲ�����ҲҪ��¼
��Ʒ�Ķ��������*/