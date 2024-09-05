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
    void Show_Items() const; // 显示背包中的物品
    void Add_Item(const string& name, int quantity, const string& category); // 添加物品
    void Use_Item(const string& name, int quantity);  // 使用物品
    void Sell_Item(const string& name, int quantity);  // 卖出物品                      
    int Get_Totalitems() const;         // 获取物品总数

    void In_Gold(int amount);                             // 增加金币
    void Out_Gold(int amount);                           // 消耗金币
    void Show_Gold() const;                                // 显示金币数量


    int gold;
    map<string, pair<int, string>> items;// 存储物品名称、数量和类别
};

#endif

/*先判断背包里是否有物品，然后进行输出提示，没有则输出没有，有的话就按顺序输出背包里的物品
和对应的数量，注意输出格式要对齐来保证美观性；然后实现添加物品的功能，保存添加的物品信息
对添加的物品安装武器，防具，饰品，药品进行分类；然后是对使用或卖出的物品进行减少操作，也要记录
物品改动后的数量*/