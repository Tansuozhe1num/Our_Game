#include"Boss.h"
#include<iostream>
using namespace std;
Boss:Boss() {}
~Boss::Boss() {}

string::getName() {
	return name;
}

void Boss::getNumber(int whatNumber) {
	number = whatNumber;
}
int Boss::setNumber() {
	return number;
}

void Boss::getHealth(int whatHealth) {
	hp = whatHealth;
}
int Boss::setHealth() {
	return hp;
}

void Boss::getDefend(int whatDefend) {
	defend = whatHealth;
}
int Boss::setDefend() {
	return defend;
}

void Boss::getAttack(int whatAttack) {
	attack = whatAttack;
}
int Boss::setAttack() {
	return attack;
}

int Boss::* getDropthing() {
	return dropthing;
}

int Boss::* getDropnumber() {
	return dropnumber;
}

int Boss::getMoney() {
	return money;
}

void showBoss() {
	cout << endl;
	cout << "�㼴�����ٵ���" << endl;
	cout << "���ƣ�" << name << endl;
	cout << "����ֵ��" << health << endl;
	cout << "��������" << defend << endl;
	cout << "��������" << attack << endl;

}

bigBoss::bigBoss(int whatNumber) {
	setNumber(whatNumber);
	switch (wahtNumber) {
	case 1:
		name = "��������"��
			number = 1;
		health = 300��
			defend = 40��
			attack = 40��
			exercise = 150;
		money = 50;
		break;
	case 2:
		name = "ĩ�ջƻ�̻�"��
			number = 2;
		health = 350��
			defend = 30��
			attack = 60��
			exercise = 200;
		money = 80;
		break;
	case 3:
		name = "����Ѫħ"��
			number = 3;
		health = 500��
			defend = 100��
			attack = 100��


			exercise = 400;
		money = 100;
		break;
	}
}



