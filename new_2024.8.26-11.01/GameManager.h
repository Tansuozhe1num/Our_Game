#pragma once
#include<string>
#ifndef GameManager
#include"Map.h"

class Manager {//控制游戏进程
public:
	Manager() {}

	void Start() {//游戏开始调用，初始化所有数据，包括技能角色血量等等（部分从文件读取，部分可以定死{像商店技能和武器列表)
		std::vector<std::string>newMap;
		my_map.createMap(newMap);//建立地图，初始化地图

		my_map.show();
	}
	void Save_Data();//保存游戏数据
	
}manager;
#endif // !GameManager
