#pragma once
#ifndef GameManager
#include"Map.h"
#include<string>

class Manager {//������Ϸ����
public:
	Manager() :Scene_now('0') {} // ��ʼ��Ϊ0��ͼ

	void Start() {//��Ϸ��ʼ���ã���ʼ���������ݣ��������ܽ�ɫѪ���ȵȣ����ִ��ļ���ȡ�����ֿ��Զ���{���̵꼼�ܺ������б�)
		std::vector<std::string>newMap;//��ʱ�Ķ�����ɶ��û��
		my_map.createMap(newMap);//������ͼ����ʼ����ͼ
		my_map.create_ShopMap(newMap);
		my_map.create_dungeon(newMap);
		my_map.create_TSMap(newMap);
		my_map.create_OSMap(newMap);

		my_map.show1();
	}
	void Change_scene(char Scene_number) {
		Scene_now = Scene_number;
	}
	void Save_Data();//������Ϸ����

	char Scene_now;//�����������Ǹ�����,��0���ǳ�ʼ��ͼ��'1'��shop,'2'�ǵ���
	/*3��У     4��os*/
}manager;
#endif // !GameManager
