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


class Player {//����ֻ��һ��
public://��������
    //static Player* my_instance;//ʵ��

    int attack = 5;
    int defendce = 0;
    int miss = 0;
    int accumatulate;
    int HP = 100;

    Bag Playerbag;


    Weapon* weapon;
    std::map<std::string, bool> Skills;//��һ��map��¼���ܣ�һ��ʼ��һ���������ֶ�Ӧһ��bool,1��ʾ��������ܣ�0��ʾû��������ܣ�

public:
    Player() {}
    ~Player() {}

    void PlayerAttack() {//�ҵ�boss��GetDamage���ã���boss�۳�����Ѫ��

    }

    void Get_Damage(int Damage) {//�ܵ������۳���ӦѪ����������boss������
        if (Damage <= this->defendce) {//������С�ڷ���������Ϊ1
            Damage = 1;
        }
        HP -= Damage;
    }

    void Player_Dead() {
        std::cout << "~~Defeat~~" << std::endl;
    }

    void Player_Move() {//���ƽ�ɫ���ƶ����������ĳ�������ֹͣ�л���һ������
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
                    //�л����̵�ϵͳ
                    if (my_map.nowx <= 1 && my_map.nowy >= 13 && my_map.nowy <= 16 && manager.Scene_now == '0') {
                        manager.Scene_now = '1';
                        my_map.ResetPos();
                        my_map.show2();
                        std::vector<std::string>new_map;
                        my_map.createMap(new_map);
                    }
                    //�л�������
                    else if (my_map.nowx <= 7 && my_map.nowx >= 5 && my_map.nowy <= 5 && my_map.nowy >= 1) {
                        manager.Scene_now = '2'; //����
                        my_map.ResetPos();
                        my_map.show3();
                        std::vector<std::string>new_map2;
                        my_map.createMap(new_map2);
                    }
                    //��У,������
                    else if ((double)my_map.nowx >=9 && my_map.nowy>=11  && my_map.nowy <= 19&& my_map.nowy >=8 && manager.Scene_now == '0') {
                        manager.Scene_now = '3'; 
                        my_map.ResetPos();
                        my_map.show4();
                        std::vector<std::string>new_map3;
                        my_map.createMap(new_map3);
                    }
                    //��os
                    else if ( my_map.nowx >= 5&&my_map.nowx <= 7 && my_map.nowy <= 30 && my_map.nowy >= 27) {
                        manager.Scene_now = '4'; 
                        my_map.ResetPos();
                        my_map.show5();
                        std::vector<std::string>new_map4;
                        my_map.createMap(new_map4);
                    }
                    else {//��ʾ���ڵĵ�ͼ
                        my_map.show1();
                    }
                }
                Sleep(1000 / 64);//ÿ��64֡
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
                    //�л���˵��
                    if (my_map.nowx<=1 && my_map.nowy <= 16 && my_map.nowy >= 13 &&manager.Scene_now == '1') {
                    //��˵���Ľӿ�

                }
                    //�л�������
                    else if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_ShopMap(new_map);
                    }
                    else if (my_map.nowx >= 9 && my_map.nowy <= 16 && my_map.nowy >= 10)
                    {
                        //���̵�Ľӿ�
                        system("cls");
                        Store store;
                        store.displayGoods();
                        cout << endl;
                        cout << "(��ʾ�����·�����е��ϼ����ɷ����̵�Ľ��档)" << endl;
                    }

                }
                Sleep(1000 / 64);//ÿ��64֡
            }
            else if (manager.Scene_now == '2') {//���εĵ�ͼ
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
                    //�л�������
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
                Sleep(1000 / 64);//ÿ��64֡
            }
            else if (manager.Scene_now == '3') {//��У
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
                    //˵��
                     if (my_map.nowx<=1 && my_map.nowy <= 16 && my_map.nowy >= 13 &&manager.Scene_now == '1') {
                    //��˵���Ľӿ�

                }

                    //�л�������
                    if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_TSMap(new_map);
                    }
                    else if (my_map.nowx >= 9 && my_map.nowy <= 16 && my_map.nowy >= 10)
                    {
                        //��ѧϰ���ܵĽӿ�
                        system("cls");
                        
                        cout << endl;
                        cout << "(��ʾ�����·�����е��ϼ����ɷ����̵�Ľ��档)" << endl;
                    }
                }

                Sleep(1000 / 64);//ÿ��64֡
                }
            else if (manager.Scene_now == '4') {//os�ĵ�ͼ
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
                    //�е�˵��
                    if (my_map.nowx <= 1 && my_map.nowy <= 16 && my_map.nowy >= 13 ) {
                        //��˵���Ľӿ�

                    }
                    //�л�������
                    else if (my_map.nowx >= 5 && my_map.nowx <= 7 && my_map.nowy >= 0 && my_map.nowy <= 4) {
                        manager.Scene_now = '0';
                        my_map.ResetPos();
                        my_map.show1();
                        std::vector<std::string>new_map;
                        my_map.create_OSMap(new_map);
                    }
                    //��л����
                    else if (my_map.nowx <= 4 && my_map.nowy <= 25 && my_map.nowy >= 23)
                    {
                         //��л�Ľӿ� 
                        //������cout << "success" << endl;

                        
                    }
                    else if (my_map.nowx >= 7&&my_map.nowx <= 9 && my_map.nowy <= 25 && my_map.nowy >= 22)
                    {
                        //��л�Ľӿ� 
                       //������cout << "success" << endl;


                    }
                    else if (my_map.nowx >= 9  && my_map.nowy <= 16 && my_map.nowy >= 10)
                    {
                        //�浵�˳��Ľӿ� 
                       //cout << "success" << endl;


                    }
                }
                Sleep(1000 / 64);//ÿ��64֡
                }
        }
    }

    void Showskill() {
        for (auto x : Skills) {
            std::cout << x.first << ' ' << (x.second) ? '$' : ' ' << '\n';
        }
    }

    void PlayerSkill() {//ѡ����,��������
        Showskill();
        std::cout << "! : Choose your skill\n";

    }

    void LearnSkill() {//ѧϰ�¼���,�û�������������ļ��� �ַ��� ��Ѷ�Ӧmapֵ���ó�1��

    }

    void Get_Weapon() {//ѡ����������ֱ���޸���ֵ

    }

}player;
