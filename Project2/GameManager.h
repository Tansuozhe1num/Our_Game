#pragma once
#ifndef GameManager
#include"Map.h"
#include<string>

class Manager {//������Ϸ����
public:
	Manager() :Scene_now('0') {}

	void Start() {//��Ϸ��ʼ���ã���ʼ���������ݣ��������ܽ�ɫѪ���ȵȣ����ִ��ļ���ȡ�����ֿ��Զ���{���̵꼼�ܺ������б�)
		std::vector<std::string>newMap;
		my_map.createMap(newMap);//������ͼ����ʼ����ͼ
		std::cout << my_map.nowx;
		my_map.show();
	}
	void Change_scene(char Scene_number) {
		Scene_now = Scene_number;
	}
	void Save_Data();//������Ϸ����
	
	char Scene_now;
}manager;
#endif // !GameManager
