#pragma once
#include<map>
#include<string>
#include"PlayerSkill.h"
#include"Weapon.h"
#include<iostream>

class Player {//主角只有一个，使用单例模式
public://基础数据
    static Player* my_instance;//实例

    int attack;
    int defendce;
    int miss;
    int accumatulate;
    int HP;

    Weapon* weapon;
    std::map<std::string, bool> Skills;//开一个map记录技能，一开始（一个技能名字对应一个bool,1表示有这个技能，0表示没有这个技能）

public:
    Player() {}
    ~Player() {}

    void PlayerAttack() {//找到boss的GetDamage调用，让boss扣除对于血量
       
    }

    void Get_Damage(int Damage) {//受到攻击扣除对应血量，等着让boss来调用
        if (Damage <= this->defendce) {//攻击力小于防御，设置为1
            Damage = 1;
        }
        HP -= Damage;
    }

    void Player_Move(){

    }

    void Showskill() {
        for (auto x : Skills) {
            std::cout << x.second << ' ';
        }
        std::cout << '\n';
    }
    void PlayerSkill() {//选择技能,遍历技能

    }

    void LearnSkill() {//学习新技能,用户输入武器库里的技能 字符串 后把对应map值设置成1。

    }

    void Get_Weapon() {//选择购买武器，直接修改数值

    }

}player;
