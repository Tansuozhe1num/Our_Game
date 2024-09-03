#include<iostream>
#include <iomanip>
#include"Store.h"
using namespace std;

Store::Store() {
    // 初始化物品实例
    for (int i = 0; i < 27; ++i) {
        goods[i] = Goods(i); // 使用 Goods 构造函数，根据 ID 初始化商品
        stores[i] = 999; // 假设每种商品初始都有999个库存
    }
}

//void Store::displayGoods() {
//    std::cout << "商店商品列表:" << std::endl;
//    for (int i = 0; i < 27; ++i) {
//        std::cout << "ID: " << goods[i].Id << ", 名称: " << goods[i].name << ", 描述: "
//            << goods[i].description << ", 价格: " << goods[i].buyprice << std::endl;
//    }
//}

void Store::displayGoods() {
    cout << left; // 设置为左对齐
    cout << setw(5) << "ID"
        << setw(20) << "名称"
        << setw(70) << "描述"
                << setw(10) << "价格" << endl;

    cout << string(110, '-') << endl; // 输出分割线

    for (int i = 0; i < 26; ++i) {
        cout << setw(5) << goods[i].Id
            << setw(20) << goods[i].name
            << setw(70) << goods[i].description           
            << setw(10) << goods[i].buyprice
            << endl;
    }
}

void Store::buyGoods(int id,int quantity) {
    if (id < 0 || id >= 27) {
        cout << "无效的商品ID！" << endl;
        return;
    }

    // 进行购买
    else if (playerMoney < goods[id].buyprice) {
        cout << "金币不足，无法购买该商品！" << endl;
        return;
    }

    // 更新库存和玩家金币
    else {
        stores[id] -= quantity;
        playerMoney -= goods[id].buyprice * quantity;
        cout << "成功购买 " << goods[id].name << "！" << endl;
        cout << "你的剩余金币: $" << playerMoney << endl;
    }
    
}

void Store::sellGoods(int id,int quantity) {
    if (id < 0 || id >= 27) {
        cout << "无效的商品ID！" << endl;
        return;
    }

    // 卖出商品，假设玩家持有该商品
    playerMoney += goods[id].sellprice; // 卖出商品获得金币
    stores[id]++; // 增加库存
    cout << "成功出售 " << goods[id].name << "！" << endl;
    cout << "你的当前金币: $" << playerMoney << endl;
}
