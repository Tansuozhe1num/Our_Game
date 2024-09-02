#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include<cstdlib>
#include<cstdlib>
#include<vector>
#include<set>
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
	std::vector<std::string>mp3;

	std::set<std::pair<int, int>>Enemypos;//敌人位置
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
	void create_Enemy(int Enemycount) {
		int g = Enemycount;
		while (g--) {
			int x, y;
			x = rand() % (M - 4) + 3;
			y = rand() % (N - 4) + 3;
			if (Enemypos.find(std::pair<int, int>(x, y)) == Enemypos.end())
				Enemypos.insert(std::pair<int, int>(x, y));
			else
				g++;
		}
	}
	inline void create_dungeon(std::vector<std::string>& a) {//建立地牢
		mp3 = a;
		mp3.push_back("-------------------------------");
		std::string c = "                              ";
		for (int i = 1; i <= N; i++) {
			mp3.push_back(c);
		}
		mp3.push_back("-------------------------------");

		for (int i = 1; i <= N; i++) {
			mp3[i][0] = '|';
			mp3[i][M - 1] = '|';
		}

		srand(time(0));
		int Enemycount = rand() % 5 + 1;

		Enemypos.clear();
		create_Enemy(Enemycount);
		for (auto x : Enemypos) {
			if(!(x.second <= 4 && x.first >= 5 && x.first <= 7))
			    mp3[x.second][x.first] = '!';
		}
		//std::cerr << "Ok" << '\n';
		//system("pause");
		// 
	
		// 建立出口位置
		std::string to = "exit";
		for (int i = 1; i <= 4; i++) {
			mp3[5][i] = '-';
			mp3[7][i] = '-';
			mp3[6][i] = to[i - 1];//固定在第6行
		}
		//初始化主角位置
		mp3[startX][startY] = 'B';
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

	void show3() {
		system("cls");
		for (int i = 0; i <= 11; i++) {
			std::cout << mp3[i] << '\n';
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

	bool Changepos3(int Key_Way) {//地牢
		bool ok = 0;
		switch (Key_Way) {
		case 1:
			if (nowx - 1 <= 0)break;
			mp3[nowx][nowy] = ' ';
			nowx--;
			mp3[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 2:
			if (nowy + 1 >= M)break;
			mp3[nowx][nowy] = ' ';
			nowy++;
			mp3[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 3:
			if (nowy - 1 <= 0)break;
			mp3[nowx][nowy] = ' ';
			nowy--;
			mp3[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 4:
			if (nowx + 1 >= N)break;
			mp3[nowx][nowy] = ' ';
			nowx++;
			mp3[nowx][nowy] = 'B';
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

