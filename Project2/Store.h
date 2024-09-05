#pragma once
#ifndef STORE_H
#define STORE_H

#include<map>
#include"Goods.h"
#include"Bag.h"
using namespace std;

class Store {

public:
    std::map<int, int> stores; // 用于库存管理
    Goods goods[999]; // 商品实例化
    int playerMoney; // 玩家持有的金币

    Store();
    void displayGoods();
    void buyGoods(int id, int quantity);
    void sellGoods(int id, int quantity);

};





#endif