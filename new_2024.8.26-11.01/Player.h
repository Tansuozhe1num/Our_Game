#pragma once
#include<map>
#include<string>
#include"PlayerSkill.h"
#include"Weapon.h"
#include<iostream>

class Player {//����ֻ��һ����ʹ�õ���ģʽ
public://��������
    static Player* my_instance;//ʵ��

    int attack;
    int defendce;
    int miss;
    int accumatulate;
    int HP;

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

    void Player_Move(){

    }

    void Showskill() {
        for (auto x : Skills) {
            std::cout << x.second << ' ';
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
