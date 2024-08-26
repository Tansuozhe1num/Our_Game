#pragma once
#include<map>
#include<string>
#include"PlayerSkill.h"
#include"Weapon.h"
#include<iostream>
class Player {//主角只有一个，使用单例模式
private://基础数据
    static Player* my_instance;//实例

    int attack;
    int defendce;
    int miss;
    int accumatulate;
    int HP;

    Weapon* weapon;
    std::map<std::string, bool> Skills;//开一个map记录技能，一开始（一个技能名字对应一个bool,1表示有这个技能，0表示没有这个技能）


private://实现功能
    Player() {}
    ~Player() {}

    void PlayerAttack() {//直接调用武器的攻击方式，实现写在weapon里面
        weapon->Attack();
    }

    void PlayerSkill() {//选择技能,遍历技能

    }

    void LearnSkill() {//学习新技能,用户输入武器库里的技能 字符串 后把对应map值设置成1。

    }

    void Get_Weapon() {//选择购买武器，new一个武器对象，开始为拳头

        /*
        int mode;
        std::cin >> mode;
        switch (mode) {
        case 1:
            weapon = new Fist;
            break;
        case 2:
            break;
        }
        */
    }




public://调用实例（通道）
    static Player* instance()
    {
        if (my_instance == nullptr)
        {
            my_instance = new Player();
        }
        return my_instance;
    }
};