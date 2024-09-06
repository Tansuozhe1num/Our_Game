#pragma once
#include<map>
#include<string>
#include"PlayerSkill.h"
#include"Weapon.h"
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include"Map.h"
#include"GameManager.h"

#include"Bag.h"
#include"Store.h"


class Player {//主角只有一个
public://基础数据
    //static Player* my_instance;//实例

    int attack = 5;
    int defendce = 0;
    int miss = 0;
    int accumatulate;
    int HP = 100;

    Bag Playerbag;


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

    void Player_Dead() {
        std::cout << "~~Defeat~~" << std::endl;
    }

    void Player_Move() {//控制角色的移动，如果进入某个区域就停止切换另一个区域
        int key1, key2;
        bool ischange = 0;

        while (1) {
            if (key1 = _getch()) {
                key2 = _getch();
            }
            if (manager.Scene_now == '0') {
                switch (key2) {
                case 72:
                    //printf("the key you press is up\n");
                    ischange = my_map.Changepos1(1);
                    break;
                case 80:
                    //printf("the key you press is down\n");
                    ischange = my_map.Changepos1(4);
                    break;
                case 75:
                    //printf("the key you press is right\n");
                    ischange = my_map.Changepos1(3);
                    break;
                case 77:
                    //printf("the key you press is left\n");
                    ischange = my_map.Changepos1(2);
                    break;
                default:
                    break;
                }
                if (ischange) {
                    //切换到商店系统
                    if (my_map.nowx <= 1 && my_map.nowy >= 13 && my_map.nowy <= 16 && manager.Scene_now == '0') {
                        manager.Scene_now = '1';
                        my_map.ResetPos();
                        my_map.show2();
                        std::vector<std::string>new_map;
                        my_map.createMap(new_map);
                    }
                    //切换到塔里
                    else if (my_map.nowx <= 7 && my_map.nowx >= 5 && my_map.nowy <= 5 && my_map.nowy >= 1) {
                        manager.Scene_now = '2'; //地牢
                        my_map.ResetPos();
                        my_map.show3();
                        std::vector<std::string>new_map2;
                        my_map.createMap(new_map2);
                    }
                    //技校,不完美
                    else if ((double)my_map.nowx >=9 && my_map.nowy>=11  && my_map.nowy <= 19&& my_map.nowy >=8 && manager.Scene_now == '0') {
                        manager.Scene_now = '3'; 
                        my_map.ResetPos();
                        my_map.show4();
                        std::vector<std::string>new_map3;
                        my_map.createMap(new_map3);
                    }
                    //到os
                    else if ( my_map.nowx >= 5&&my_map.nowx <= 7 && my_map.nowy <= 30 && my_map.nowy >= 27) {
                        manager.Scene_now = '4'; 
                        my_map.ResetPos();
                        my_map.show5();
                        std::vector<std::string>new_map4;
                        my_map.createMap(new_map4);
                    }
                    else {//显示现在的地图
                        my_map.show1();
                    }
                }
                Sleep(1000 / 64);//每秒64帧
            }
            else if (manager.Scene_now == '1') {
                switch (key2) {
                case 72:
                    //printf("the key you press is up\n");
                    ischange = my_map.Changepos2(1);
                    break;
                case 80:
                    //printf("the key you press is down\n");
                    ischange = my_map.Changepos2(4);
                    break;
                case 75:
                    //printf("the key you press is right\n");
                    ischange = my_map.Changepos2(3);
                    break;
                case 77:
                    //printf("the key you press is left\n");
                    ischange = my_map.Changepos2(2);
                    break;
                default:
                    break;
                }
                if (ischange) {
                    my_map.show2();
                    //切换到说明
                    if (my_map.nowx<=1 && my_map.nowy <= 16 && my_map.nowy >= 13 &&manager.Scene_now == '1') {
                    //到说明的接口

                }
                    //切换到主城
                    else if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_ShopMap(new_map);
                    }
                    else if (my_map.nowx >= 9 && my_map.nowy <= 16 && my_map.nowy >= 10)
                    {
                        //到商店的接口
                        system("cls");
                        Store store;
                        store.displayGoods();
                        cout << endl;
                        cout << "(提示：按下方向键中的上键即可返回商店的界面。)" << endl;
                    }

                }
                Sleep(1000 / 64);//每秒64帧
            }
            else if (manager.Scene_now == '2') {//地牢的地图
                switch (key2) {
                case 72:
                    //printf("the key you press is up\n");
                    ischange = my_map.Changepos3(1);
                    break;
                case 80:
                    //printf("the key you press is down\n");
                    ischange = my_map.Changepos3(4);
                    break;
                case 75:
                    //printf("the key you press is right\n");
                    ischange = my_map.Changepos3(3);
                    break;
                case 77:
                    //printf("the key you press is left\n");
                    ischange = my_map.Changepos3(2);
                    break;
                default:
                    break;
                }
                if (ischange) {
                    my_map.show3();
                    //切换到主城
                    if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_dungeon(new_map);
                    }

                    for (auto x : my_map.Enemypos) {
                        if (my_map.nowx == x.second && my_map.nowy == x.first) {
                            std::cout << "Enemy attack!\n";
                            system("pause");
                        }
                    }
                }
                Sleep(1000 / 64);//每秒64帧
            }
            else if (manager.Scene_now == '3') {//技校
                switch (key2) {
                case 72:
                    //printf("the key you press is up\n");
                    ischange = my_map.Changepos4(1);
                    break;
                case 80:
                    //printf("the key you press is down\n");
                    ischange = my_map.Changepos4(4);
                    break;
                case 75:
                    //printf("the key you press is right\n");
                    ischange = my_map.Changepos4(3);
                    break;
                case 77:
                    //printf("the key you press is left\n");
                    ischange = my_map.Changepos4(2);
                    break;
                default:
                    break;
                }
                if (ischange) {
                    my_map.show4();
                    //说明
                     if (my_map.nowx<=1 && my_map.nowy <= 16 && my_map.nowy >= 13 &&manager.Scene_now == '1') {
                    //到说明的接口

                }

                    //切换到主城
                    if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_TSMap(new_map);
                    }
                    else if (my_map.nowx >= 9 && my_map.nowy <= 16 && my_map.nowy >= 10)
                    {
                        //到学习技能的接口
                        system("cls");
                        
                        cout << endl;
                        cout << "(提示：按下方向键中的上键即可返回商店的界面。)" << endl;
                    }
                }

                Sleep(1000 / 64);//每秒64帧
                }
            else if (manager.Scene_now == '4') {//os的地图
                switch (key2) {
                case 72:
                    //printf("the key you press is up\n");
                    ischange = my_map.Changepos5(1);
                    break;
                case 80:
                    //printf("the key you press is down\n");
                    ischange = my_map.Changepos5(4);
                    break;
                case 75:
                    //printf("the key you press is right\n");
                    ischange = my_map.Changepos5(3);
                    break;
                case 77:
                    //printf("the key you press is left\n");
                    ischange = my_map.Changepos5(2);
                    break;
                default:
                    break;
                }
                if (ischange) {
                    my_map.show5();
                    //切到说明
                    if (my_map.nowx <= 1 && my_map.nowy <= 16 && my_map.nowy >= 13 ) {
                        //到说明的接口

                    }
                    //切换到主城
                    else if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_OSMap(new_map);
                    }
                    //致谢部分
                    else if (my_map.nowx <= 4 && my_map.nowy <= 25 && my_map.nowy >= 23)
                    {
                         //致谢的接口 
                        //测试用cout << "success" << endl;

                        
                    }
                    else if (my_map.nowx >= 7&&my_map.nowx <= 9 && my_map.nowy <= 25 && my_map.nowy >= 22)
                    {
                        //致谢的接口 
                       //测试用cout << "success" << endl;


                    }
                    else if (my_map.nowx >= 9  && my_map.nowy <= 16 && my_map.nowy >= 10)
                    {
                        //存档退出的接口 
                       //cout << "success" << endl;


                    }
                }
                Sleep(1000 / 64);//每秒64帧
                }
        }
    }

    void Showskill() {
        for (auto x : Skills) {
            std::cout << x.first << ' ' << (x.second) ? '$' : ' ' << '\n';
        }
    }

    void PlayerSkill() {//选择技能,遍历技能
        Showskill();
        std::cout << "! : Choose your skill\n";

    }

    void LearnSkill() {//学习新技能,用户输入武器库里的技能 字符串 后把对应map值设置成1。

    }

    void Get_Weapon() {//选择购买武器，直接修改数值

    }

}player;
