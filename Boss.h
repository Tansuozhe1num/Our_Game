#include<iostream>
#include<string>
using namespace std;
class Boss {
public:
	string name;
	int number;
	int health;
	int defend;
	int attack;
	
	
	int exercise;
	int money;

	Boss();
	~Boss();
	string getName();

	int getnumber();
	void setNumber(int number);
	
	int getHealth();
	void setHealth(int hp);
	 
	int getDefend();
	void setDefend(int defend);

	int getattack();
	void setAttack(int attack);
	
	
	int getExercise();
	int getMoney();

	void showBoss();
	
};
class bigBoss::public Boss {
public:
	bigBoss();
	bigBoss(int number);
	~bigBoss() {};
};


