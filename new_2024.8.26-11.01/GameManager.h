#pragma once
#include<string>
#ifndef GameManager
#include"Map.h"

class Manager {//������Ϸ����
public:
	Manager() {}

	void Start() {//��Ϸ��ʼ���ã���ʼ���������ݣ��������ܽ�ɫѪ���ȵȣ����ִ��ļ���ȡ�����ֿ��Զ���{���̵꼼�ܺ������б�)
		std::vector<std::string>newMap;
		my_map.createMap(newMap);//������ͼ����ʼ����ͼ

		my_map.show();
	}
	void Save_Data();//������Ϸ����
	
}manager;
#endif // !GameManager
