#pragma once
#ifndef STORE_H
#define STORE_H

#include<map>
#include"Goods.h"
#include"Bag.h"
using namespace std;

class Store {

public:
    std::map<int, int> stores; // ���ڿ�����
    Goods goods[999]; // ��Ʒʵ����
    int playerMoney; // ��ҳ��еĽ��

    Store();
    void displayGoods();
    void buyGoods(int id, int quantity);
    void sellGoods(int id, int quantity);

};





#endif