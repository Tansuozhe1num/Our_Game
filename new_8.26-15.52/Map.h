#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include<cstdlib>

const int startX = 6;
const int startY = 11;
class Map {
public:
	Map() :
		nowx(startX), nowy(startY) {}
	int nowx = startX;
	int nowy = startY;

	std::vector<std::string>mp;
	std::vector<std::string>mp2;

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

	inline void create_ShopMap(std::vector<std::string>& a) {
		mp2 = a;
		mp2.push_back("-------------------------------");
		std::string c = "                              ";
		for (int i = 1; i <= N; i++) {
			mp2.push_back(c);
		}
		mp2.push_back("-------------------------------");

		for (int i = 1; i <= N; i++) {
			mp2[i][0] = '|';
			mp2[i][M - 1] = '|';
		}


		//建立出口的位置
		std::string to = "exit";
		for (int i = 1; i <= 4; i++) {
			mp2[5][i] = '-';
			mp2[7][i] = '-';
			mp2[6][i] = to[i - 1];//固定在第6行
		}


		//初始化主角位置
		mp2[startX][startY] = 'B';
	}

	void show1() {
		system("cls");
		for (int i = 0; i <= 11; i++) {
			std::cout << mp[i] << '\n';
		}
	}

	void show2() {
		system("cls");
		for (int i = 0; i <= 11; i++) {
			std::cout << mp2[i] << '\n';
		}
	}

	bool Changepos1(int Key_Way) {//变换主角所在位置方向，1是up2是right3是left4是down，这是对于主界面的修改
		bool ok = 0;
		switch (Key_Way) {
		case 1:
			if (nowx - 1 <= 0)break;
			mp[nowx][nowy] = ' ';
			nowx--;
			mp[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 2:
			if (nowy + 1 >= M)break;
			mp[nowx][nowy] = ' ';
			nowy++;
			mp[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 3:
			if (nowy - 1 <= 0)break;
			mp[nowx][nowy] = ' ';
			nowy--;
			mp[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 4:
			if (nowx + 1 >= N)break;
			mp[nowx][nowy] = ' ';
			nowx++;
			mp[nowx][nowy] = 'B';
			ok = 1;
			break;
		default:
			std::cerr << nowx << ' ' << nowy;
		}
		
		return ok;
	}

	bool Changepos2(int Key_Way) {//变换主角所在位置方向，1是up2是right3是left4是down,这是对于商店的修改
		bool ok = 0;
		switch (Key_Way) {
		case 1:
			if (nowx - 1 <= 0)break;
			mp2[nowx][nowy] = ' ';
			nowx--;
			mp2[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 2:
			if (nowy + 1 >= M)break;
			mp2[nowx][nowy] = ' ';
			nowy++;
			mp2[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 3:
			if (nowy - 1 <= 0)break;
			mp2[nowx][nowy] = ' ';
			nowy--;
			mp2[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 4:
			if (nowx + 1 >= N)break;
			mp2[nowx][nowy] = ' ';
			nowx++;
			mp2[nowx][nowy] = 'B';
			ok = 1;
			break;
		default:
			std::cerr << nowx << ' ' << nowy;
		}

		return ok;
	}

	void ResetPos() {//设置为初始位置
		nowx = startX;
		nowy = startY;
	}


private:
	const int N = 10;
	const int M = 30;
}my_map;

