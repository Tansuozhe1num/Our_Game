#pragma once
#ifndef GameManager
#include"Map.h"
#include<string>

class Manager {//控制游戏进程
public:
	Manager() :Scene_now('0') {} // 初始化为0地图

	void Start() {//游戏开始调用，初始化所有数据，包括技能角色血量等等（部分从文件读取，部分可以定死{像商店技能和武器列表)
		std::vector<std::string>newMap;//临时的东西，啥用没有
		my_map.createMap(newMap);//建立地图，初始化地图
		my_map.create_ShopMap(newMap);
		my_map.create_dungeon(newMap);
		my_map.create_TSMap(newMap);
		my_map.create_OSMap(newMap);

		my_map.show1();
	}
	void Change_scene(char Scene_number) {
		Scene_now = Scene_number;
	}
	void Save_Data();//保存游戏数据

	char Scene_now;//储存现在是那个场景,‘0’是初始地图，'1'是shop,'2'是地牢
	/*3技校     4是os*/
}manager;
#endif // !GameManager
