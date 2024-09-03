#include<iostream>
#include <iomanip>
#include"Store.h"
using namespace std;

Store::Store() {
    // ��ʼ����Ʒʵ��
    for (int i = 0; i < 27; ++i) {
        goods[i] = Goods(i); // ʹ�� Goods ���캯�������� ID ��ʼ����Ʒ
        stores[i] = 999; // ����ÿ����Ʒ��ʼ����999�����
    }
}

//void Store::displayGoods() {
//    std::cout << "�̵���Ʒ�б�:" << std::endl;
//    for (int i = 0; i < 27; ++i) {
//        std::cout << "ID: " << goods[i].Id << ", ����: " << goods[i].name << ", ����: "
//            << goods[i].description << ", �۸�: " << goods[i].buyprice << std::endl;
//    }
//}

void Store::displayGoods() {
    cout << left; // ����Ϊ�����
    cout << setw(5) << "ID"
        << setw(20) << "����"
        << setw(70) << "����"
                << setw(10) << "�۸�" << endl;

    cout << string(110, '-') << endl; // ����ָ���

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
        cout << "��Ч����ƷID��" << endl;
        return;
    }

    // ���й���
    else if (playerMoney < goods[id].buyprice) {
        cout << "��Ҳ��㣬�޷��������Ʒ��" << endl;
        return;
    }

    // ���¿�����ҽ��
    else {
        stores[id] -= quantity;
        playerMoney -= goods[id].buyprice * quantity;
        cout << "�ɹ����� " << goods[id].name << "��" << endl;
        cout << "���ʣ����: $" << playerMoney << endl;
    }
    
}

void Store::sellGoods(int id,int quantity) {
    if (id < 0 || id >= 27) {
        cout << "��Ч����ƷID��" << endl;
        return;
    }

    // ������Ʒ��������ҳ��и���Ʒ
    playerMoney += goods[id].sellprice; // ������Ʒ��ý��
    stores[id]++; // ���ӿ��
    cout << "�ɹ����� " << goods[id].name << "��" << endl;
    cout << "��ĵ�ǰ���: $" << playerMoney << endl;
}
