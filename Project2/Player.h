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

class Player {//����ֻ��һ����ʹ�õ���ģʽ
public://��������
    static Player* my_instance;//ʵ��

    int attack = 5;
    int defendce = 0;
    int miss = 0;
    int accumatulate;
    int HP = 100;

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

    void Player_Move(){//���ƽ�ɫ���ƶ����������ĳ�������ֹͣ�л���һ������
        int key1, key2;
        bool ischange = 0;
        while (1) {
            if (key1 = _getch()) {
                key2 = _getch();
            }
            switch (key2) {
            case 72:
                //printf("the key you press is up\n");
                ischange = my_map.Changepos(1);
                break;
            case 80:
                //printf("the key you press is down\n");
                ischange = my_map.Changepos(4); 
                break;
            case 75:
                //printf("the key you press is right\n");
                ischange = my_map.Changepos(3); 
                break;
            case 77:
                //printf("the key you press is left\n");
                ischange = my_map.Changepos(2);
                break;
            default:
                break;
            }
            if (ischange) {
                my_map.show();

                //�л����̵�ϵͳ
                if (my_map.nowx <= 1 && my_map.nowy >= 13 && my_map.nowy <= 16) {

                }
                //�л�������

            }
            Sleep(1000 / 64);//ÿ��64֡
        }
    }

    void Showskill() {
        for (auto x : Skills) {
            if (x.second == 1) {
                std::cout << x.first << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    void PlayerSkill() {//ѡ����,��������

    }

    void LearnSkill() {//ѧϰ�¼���,�û�������������ļ��� �ַ��� ��Ѷ�Ӧmapֵ���ó�1��

    }

    void Get_Weapon() {//ѡ����������ֱ���޸���ֵ

    }

}player;
