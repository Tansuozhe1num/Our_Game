#pragma once

#include<iostream>
#include<vector>
#include<string>

class Map {
public:
	std::vector<std::string>mp;
	/// <summary>
	/// 建立初始界面
	/// </summary>
	/// <param name="posx"></param>
	/// <param name="posy"></param>
	/// <param name="mp"></param>
	inline void createMap(std::vector<std::string>& a) {
		mp = a;
		mp.push_back("-------------------------------");
		std::string c = "                              ";
		for (int i = 1; i <= N; i++) {
			mp.push_back(c);
		}
		mp.push_back("-------------------------------");

		for (int i = 1; i <= N; i++) {
			mp[i][0] = '|';
			mp[i][M - 1] = '|';
		}

		//建立shop位置
		char Shop[4] = { 'S' , 'h' , 'o' , 'p' };
		for (int i = 13; i <= 16; i++) {
			mp[1][i] = Shop[i - 13];//固定在第1行的13 - 16格
		}
		mp[1][11] = '\\';
		mp[1][18] = '/';

		//建立塔的位置
		std::string to = "Tower";
		for (int i = 1; i <= 5; i++) {
			mp[5][i] = '-';
			mp[7][i] = '-';
			mp[6][i] = to[i - 1];//固定在第6行
		}

		//初始化主角位置
		mp[startX][startY] = 'B';
	}


	void show() {
		for (int i = 0; i <= 11; i++) {
			std::cout << mp[i] << '\n';
		}
	}

private:
	const int N = 10;
	const int M = 30;
	const int startX = 6;
	const int startY = 11;
}my_map;