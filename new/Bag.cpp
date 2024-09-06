#include"Bag.h"
#include<iostream>
using namespace std;


// ��ʾ�����е���Ʒ
void Bag::Show_Items() const {
    if (items.empty()) {
        cout << "�����ǿյģ�" << endl;
        return;
    }

    cout << left << setw(20) << "��Ʒ����"
        << setw(20) << "����"
        << "���" << endl;

    cout << string(50, '-') << endl; // ����ָ���

    for (const auto& item : items) {
        cout << left << setw(20) << item.first
            << setw(20) << item.second.first
            << item.second.second << endl;
    }
}

// �����Ʒ
void Bag::Add_Item(const string& name, int quantity, const string& category) {
    if (quantity <= 0) {
        cout << "������������㣡" << endl;
        return;
    }
    items[name] = { items[name].first + quantity, category };
    // �����Ʒ�Ѵ�������������
    cout << "�����Ʒ: " << name << ", ����: " << quantity << ", ���: " << category << endl;
}

// ʹ����Ʒ
void Bag::Use_Item(const string& name, int quantity) {
    if (items.find(name) == items.end()) {
        cout << "������û�и���Ʒ: " << name << endl;
        return;
    }

    if (items[name].first < quantity) {
        cout << "��Ʒ�������㣡" << endl;
        return;
    }

    items[name].first -= quantity; // ������Ʒ����
    cout << "��ʹ����" << name << ", ����: " << quantity << endl;

    // ���ʹ�ú�����Ϊ0�����Ƴ�����Ʒ
    if (items[name].first == 0) {
        items.erase(name);
        cout << "��Ʒ: " << name << " �ѱ�ʹ�û�������" << endl;
    }
}

// ������Ʒ
void Bag::Sell_Item(const string& name, int quantity) {
    if (items.find(name) == items.end()) {
        cout << "������û�и���Ʒ: " << name << endl;
        return;
    }

    if (items[name].first < quantity) {
        cout << "��Ʒ�������㣡" << endl;
        return;
    }

    items[name].first -= quantity; // ������Ʒ����
    cout << "������Ʒ: " << name << ", ����: " << quantity << endl;

    // �������������Ϊ0�����Ƴ�����Ʒ
    if (items[name].first == 0) {
        items.erase(name);
        cout << "��Ʒ: " << name << " ��ʹ�û�������" << endl;
    }
}


// ��ȡ��Ʒ����
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
        cout << "��ý��: " << amount << "����ǰ���: " << gold << endl;
    }
}

// ���Ľ��
void Bag::Out_Gold(int amount) {
    if (amount > 0 && amount <= gold) {
        gold -= amount;
        cout << "���ѽ��: " << amount << "����ǰ���: " << gold << endl;
    }
    else {
        cout << "��Ҳ��㣬�޷����ѣ�" << endl;
    }
}

// ��ʾ�������
void Bag::Show_Gold() const {
    cout << "��ǰ�������: " << gold << endl;
}