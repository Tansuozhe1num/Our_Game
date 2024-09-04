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
	cout << "Äã¼´½«ÃæÁÙµÄÊÇ" << endl;
	cout << "Ãû³Æ£º" << name << endl;
	cout << "ÉúÃüÖµ£º" << health << endl;
	cout << "·ÀÓùÁ¦£º" << defend << endl;
	cout << "¹¥»÷Á¦£º" << attack << endl;

}

bigBoss::bigBoss(int whatNumber) {
	setNumber(whatNumber);
	switch (wahtNumber) {
	case 1:
		name = "¶éÂäÓÂÕß"£»
			number = 1;
		health = 300£»
			defend = 40£»
			attack = 40£»
			exercise = 150;
		money = 50;
		break;
	case 2:
		name = "Ä©ÈÕ»Æ»è½Ì»Ê"£»
			number = 2;
		health = 350£»
			defend = 30£»
			attack = 60£»
			exercise = 200;
		money = 80;
		break;
	case 3:
		name = "ÄõÈÕÑªÄ§"£»
			number = 3;
		health = 500£»
			defend = 100£»
			attack = 100£»


			exercise = 400;
		money = 100;
		break;
	case 4:
		name = "°µÈÕÁ¶ÓüÁú"£»
			number = 4;
		health = 700£»
			defend = 150£»
			attack = 150£»


			exercise = 600;
		money = 200;
		break;
	case 5:
		name = "Ð¡¹Ö1ºÅ"£»
			number = 5;
		health =100 £»
			defend = 10£»
			attack = 10£»
			exercise = 50;
		money = 10;
		break;
	case 6:
		name = "Ð¡¹Ö2ºÅ"£»
			number = 6;
		health = 100 £»
			defend = 10£»
			attack = 10£»
			exercise = 50;
		money = 10;
		break;
	case 7:
		name = "Ð¡¹Ö3ºÅ"£»
			number = 7;
		health = 100 £»
			defend = 10£»
			attack = 10£»
			exercise = 50;
		money = 10;
		break;
	case 8:
		name = "Ð¡¹Ö4ºÅ"£»
			number = 8;
		health = 100 £»
			defend = 10£»
			attack = 10£»
			exercise = 50;
		money = 10;
		break;
	}
}



