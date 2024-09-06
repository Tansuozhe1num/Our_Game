#include"Bag.h"
#include<iostream>
using namespace std;


// 显示背包中的物品
void Bag::Show_Items() const {
    if (items.empty()) {
        cout << "背包是空的！" << endl;
        return;
    }

    cout << left << setw(20) << "物品名称"
        << setw(20) << "数量"
        << "类别" << endl;

    cout << string(50, '-') << endl; // 输出分割线

    for (const auto& item : items) {
        cout << left << setw(20) << item.first
            << setw(20) << item.second.first
            << item.second.second << endl;
    }
}

// 添加物品
void Bag::Add_Item(const string& name, int quantity, const string& category) {
    if (quantity <= 0) {
        cout << "数量必须大于零！" << endl;
        return;
    }
    items[name] = { items[name].first + quantity, category };
    // 如果物品已存在则增加数量
    cout << "获得物品: " << name << ", 数量: " << quantity << ", 类别: " << category << endl;
}

// 使用物品
void Bag::Use_Item(const string& name, int quantity) {
    if (items.find(name) == items.end()) {
        cout << "背包中没有该物品: " << name << endl;
        return;
    }

    if (items[name].first < quantity) {
        cout << "物品数量不足！" << endl;
        return;
    }

    items[name].first -= quantity; // 减少物品数量
    cout << "你使用了" << name << ", 数量: " << quantity << endl;

    // 如果使用后数量为0，则移除此物品
    if (items[name].first == 0) {
        items.erase(name);
        cout << "物品: " << name << " 已被使用或卖出！" << endl;
    }
}

// 卖出物品
void Bag::Sell_Item(const string& name, int quantity) {
    if (items.find(name) == items.end()) {
        cout << "背包中没有该物品: " << name << endl;
        return;
    }

    if (items[name].first < quantity) {
        cout << "物品数量不足！" << endl;
        return;
    }

    items[name].first -= quantity; // 减少物品数量
    cout << "卖出物品: " << name << ", 数量: " << quantity << endl;

    // 如果卖出后数量为0，则移除此物品
    if (items[name].first == 0) {
        items.erase(name);
        cout << "物品: " << name << " 已使用或卖出！" << endl;
    }
}


// 获取物品总数
int Bag::Get_Totalitems() const {
    int total = 0;
    for (const auto& item : items) {
        total += item.second.first;
    }
    return total;
}


void Bag::In_Gold(int amount) {
    if (amount > 0) {
        gold += amount;
        cout << "获得金币: " << amount << "，当前金币: " << gold << endl;
    }
}

// 消耗金币
void Bag::Out_Gold(int amount) {
    if (amount > 0 && amount <= gold) {
        gold -= amount;
        cout << "消费金币: " << amount << "，当前金币: " << gold << endl;
    }
    else {
        cout << "金币不足，无法消费！" << endl;
    }
}

// 显示金币数量
void Bag::Show_Gold() const {
    cout << "当前金币数量: " << gold << endl;
}