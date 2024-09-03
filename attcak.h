#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<thread>
#include <chrono>
#include <functional>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <iomanip>
using namespace std;
constexpr auto WIDE = 30;
constexpr auto HIGH = 10;
class Role {
public:
	int HP = 100;
	int define = 10;
	int Attack = 8;
	int Exp = 0;
	int mp = 0;
	int Goods[10] = {0};
	Role();
	~Role();
};
class Enemy {
public:
	int HP = 10;
	int define = 5;
	int Attack = 10+50;
	int Exp_give = 10;
	Enemy();
	~Enemy();

};
class Attack
{
public:
	struct HEART {
		int x;
		int y;
	} Heart;
	struct Enemy_attcak {
		int x;
		int y;
	};
	void Enemy_round();
	void Before_action();
	void Our_round();
	void Show_information();
	void Reply();
	void Magic_attack();
	bool Hurt;
	bool If_attacking=1;
	void New_round();
	void Show_hurt_number();
	void eara();
	bool Time_control();
	void Heart_move();
	void Heart_test();
	void Attack_information();
	struct Attack_range_body {
		int x;
		int y;
	};
	struct Attack_range_head {
		struct Attack_range_body body[WIDE * HIGH];
	}range_1,danger_1,range_2,danger_2, range_3,danger_3, range_4, range_5, range_6, range_7, range_8, range_9, range_10;
	void Range_1();
	void Range_2();
	void Range_3();
	void Initi_Hreat();
	Attack(Role player, Enemy enemy);
	~Attack();
	Role player;//战斗的角色
	Enemy enemy;//战斗的怪物
	double hurt;//战斗产生的伤害值
};
