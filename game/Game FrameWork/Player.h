#pragma once
#include<map>
#include<string>
#include"PlayerSkill.h"
#include"Weapon.h"
#include<iostream>
class Player {//����ֻ��һ����ʹ�õ���ģʽ
private://��������
    static Player* my_instance;//ʵ��

    int attack;
    int defendce;
    int miss;
    int accumatulate;
    int HP;

    Weapon* weapon;
    std::map<std::string, bool> Skills;//��һ��map��¼���ܣ�һ��ʼ��һ���������ֶ�Ӧһ��bool,1��ʾ��������ܣ�0��ʾû��������ܣ�


private://ʵ�ֹ���
    Player() {}
    ~Player() {}

    void PlayerAttack() {//ֱ�ӵ��������Ĺ�����ʽ��ʵ��д��weapon����
        weapon->Attack();
    }

    void PlayerSkill() {//ѡ����,��������

    }

    void LearnSkill() {//ѧϰ�¼���,�û�������������ļ��� �ַ��� ��Ѷ�Ӧmapֵ���ó�1��

    }

    void Get_Weapon() {//ѡ����������newһ���������󣬿�ʼΪȭͷ

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




public://����ʵ����ͨ����
    static Player* instance()
    {
        if (my_instance == nullptr)
        {
            my_instance = new Player();
        }
        return my_instance;
    }
};