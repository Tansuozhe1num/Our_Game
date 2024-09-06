#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include<cstdlib>
#include<cstdlib>
#include<vector>
#include<set>

using namespace std;
const int startX = 6;
const int startY = 14;


class Map {
public:
	Map() :
		nowx(startX), nowy(startY) {}
	int nowx = startX;
	int nowy = startY;

	std::vector<std::string>mp;
	std::vector<std::string>mp2;
	std::vector<std::string>mp3;
	std::vector<std::string>mp4;/*��Уר��*/
	std::vector<std::string>mp5;/*OS��*/

	std::set<std::pair<int, int>>Enemypos;//����λ��
	/// <summary>
	/// ������ʼ����
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
			mp[i][M -1] = '|';
		}

		//����shopλ��
		char Shop[4] = { 'S' , 'h' , 'o' , 'p' };
		for (int i = 13; i <= 16; i++) {
			mp[1][i] = Shop[i - 13];//�̶��ڵ�1�е�13 - 16��
		}
		mp[1][11] = '\\';
		mp[1][18] = '/';

		//��������λ��
		std::string to = "Tower";
		for (int i = 1; i <= 5; i++) {
			mp[5][i] = '-';
			mp[7][i] = '-';
			mp[6][i] = to[i - 1];//�̶��ڵ�6��
		}

		/*����os��λ��*/
		char OS[2] = { 'O','S'};
		for (int i = 27; i <= 28; i++) {
			mp[6][i] = OS[i - 27];//�̶��ڵ�1�е�13 - 16��
		}
		for (int i = 27; i <= 28; i++) {
			mp[5][i] = '-';
			mp[7][i] = '-';
			
		}
		/*������У��λ��*/
		char TS[9] = { 'T','e','c','S','c','h','o','o','l'};
		for (int i = 11; i <= 19; i++) {
			mp[10][i] = TS[i - 11];//�̶��ڵ�1�е�13 - 16��
		}
		mp[10][10] = '\\';
		mp[10][20] = '/';
		//��ʼ������λ��
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


		//�������ڵ�λ��
		std::string to = "exit";
		for (int i = 1; i <= 4; i++) {
			mp2[5][i] = '-';
			mp2[7][i] = '-';
			mp2[6][i] = to[i - 1];//�̶��ڵ�6��
		}
		/*����˵���ĵط�*/
		mp2[1][7] = '\\';
		mp2[1][20] = '/';
		std::string in = "Introduction";
		for (int i = 8; i <= 19; i++) {
			
			mp2[1][i] = in[i - 8];//�̶��ڵ�1��
		}
		/*��������ĵط�*/
		mp2[10][9] = '\\';
		mp2[10][16] = '/';
		std::string go = "Goods";
		for (int i = 10; i <= 15; i++) {

			mp2[10][i] = go[i - 10];//�̶��ڵ�1��
		}


		//��ʼ������λ��
		mp2[startX][startY] = 'B';
	}
/*������У�ĵ�ͼ*/
	inline void create_TSMap(std::vector<std::string>& a) {
		mp4 = a;
		mp4.push_back("-------------------------------");
		std::string c = "                              ";
		for (int i = 1; i <= N; i++) {
			mp4.push_back(c);
		}
		mp4.push_back("-------------------------------");

		for (int i = 1; i <= N; i++) {
			mp4[i][0] = '|';
			mp4[i][M - 1] = '|';
		}


		//�������ڵ�λ��
		std::string to = "exit";
		for (int i = 1; i <= 4; i++) {
			mp4[5][i] = '-';
			mp4[7][i] = '-';
			mp4[6][i] = to[i - 1];//�̶��ڵ�6��
		}
		/*����˵���ĵط�*/
		mp4[1][7] = '\\';
		mp4[1][20] = '/';
		std::string in = "Introduction";
		for (int i = 8; i <= 19; i++) {

			mp4[1][i] = in[i - 8];//�̶��ڵ�1��
		}
		/*����ѧϰ�ĵط�*/
		mp4[10][9] = '\\';
		mp4[10][16] = '/';
		std::string le = "Learn";
		for (int i = 10; i <= 15; i++) {

			mp4[10][i] = le[i - 10];//�̶��ڵ�1��
		}


		//��ʼ������λ��
			mp4[startX][startY] = 'B';
	}

	/*os��ͼ*/
	inline void create_OSMap(std::vector<std::string>& a) {
		mp5 = a;
		mp5.push_back("-------------------------------");
		std::string c = "                              ";
		for (int i = 1; i <= N; i++) {
			mp5.push_back(c);
		}
		mp5.push_back("-------------------------------");

		for (int i = 1; i <= N; i++) {
			mp5[i][0] = '|';
			mp5[i][M - 1] = '|';
		}


		//�������ڵ�λ��
		std::string to = "exit";
		for (int i = 1; i <= 4; i++) {
			mp5[5][i] = '-';
			mp5[7][i] = '-';
			mp5[6][i] = to[i - 1];//�̶��ڵ�6��
		}
		/*����˵���ĵط�*/
		mp5[1][7] = '\\';
		mp5[1][20] = '/';
		std::string in = "Introduction";
		for (int i = 8; i <= 19; i++) {

			mp5[1][i] = in[i - 8];//�̶��ڵ�1��
		}
		/*��л��thanks���浵�˳�Archive exit���淨Gmethod*/

		//�浵�˳�ͨ��
		mp5[10][9] = '\\';
		mp5[10][17] = '/';
		std::string AE = "ArcExit";
		for (int i = 10; i <= 16; i++) {

			mp5[10][i] = AE[i - 10];//�̶��ڵ�1��
		}
		//��л
		string th = "Thanks";
		for (int i = 23; i <= 28; i++) {
			mp5[4][i] = th[i - 23];//�̶��ڵ�1�е�13 - 16��
		}
		for (int i = 23; i <= 28; i++) {
			mp5[3][i] = '-';
			mp5[5][i] = '-';

		}

		//�淨
		string gm = "Gmethod";
		for (int i = 22; i <= 28; i++) {
			mp5[7][i] = gm[i - 22];//�̶��ڵ�1�е�13 - 16��
		}
		for (int i = 23; i <= 28; i++) {
			mp5[6][i] = '-';
			mp5[8][i] = '-';

		}
		


		//��ʼ������λ��
		mp5[startX][startY] = 'B';
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


	inline void create_dungeon(std::vector<std::string>& a) {//��������
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
			if (!(x.second <= 4 && x.first >= 5 && x.first <= 7))
				mp3[x.second][x.first] = '!';
		}
		//std::cerr << "Ok" << '\n';
		//system("pause");
		// 

		// ��������λ��
		std::string to = "exit";
		for (int i = 1; i <= 4; i++) {
			mp3[5][i] = '-';
			mp3[7][i] = '-';
			mp3[6][i] = to[i - 1];//�̶��ڵ�6��
		}
		//��ʼ������λ��
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

	void show4() {
		system("cls");
		for (int i = 0; i <= 11; i++) {
			std::cout << mp4[i] << '\n';
		}
	}

	void show5() {
		system("cls");
		for (int i = 0; i <= 11; i++) {
			std::cout << mp5[i] << '\n';
		}
	}

	bool Changepos1(int Key_Way) {//�任��������λ�÷���1��up2��right3��left4��down�����Ƕ�����������޸�
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

	bool Changepos2(int Key_Way) {//�任��������λ�÷���1��up2��right3��left4��down,���Ƕ����̵���޸�
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

	bool Changepos3(int Key_Way) {//����
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

	bool Changepos4(int Key_Way) {//����
		bool ok = 0;
		switch (Key_Way) {
		case 1:
			if (nowx - 1 <= 0)break;
			mp4[nowx][nowy] = ' ';
			nowx--;
			mp4[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 2:
			if (nowy + 1 >= M)break;
			mp4[nowx][nowy] = ' ';
			nowy++;
			mp4[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 3:
			if (nowy - 1 <= 0)break;
			mp4[nowx][nowy] = ' ';
			nowy--;
			mp4[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 4:
			if (nowx + 1 >= N)break;
			mp4[nowx][nowy] = ' ';
			nowx++;
			mp4[nowx][nowy] = 'B';
			ok = 1;
			break;
		default:
			std::cerr << nowx << ' ' << nowy;
		}

		return ok;
	}

	bool Changepos5(int Key_Way) {//����
		bool ok = 0;
		switch (Key_Way) {
		case 1:
			if (nowx - 1 <= 0)break;
			mp5[nowx][nowy] = ' ';
			nowx--;
			mp5[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 2:
			if (nowy + 1 >= M)break;
			mp5[nowx][nowy] = ' ';
			nowy++;
			mp5[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 3:
			if (nowy - 1 <= 0)break;
			mp5[nowx][nowy] = ' ';
			nowy--;
			mp5[nowx][nowy] = 'B';
			ok = 1;
			break;
		case 4:
			if (nowx + 1 >= N)break;
			mp5[nowx][nowy] = ' ';
			nowx++;
			mp5[nowx][nowy] = 'B';
			ok = 1;
			break;
		default:
			std::cerr << nowx << ' ' << nowy;
		}

		return ok;
	}




	void ResetPos() {//����Ϊ��ʼλ��
		nowx = startX;
		nowy = startY;
	}


private:
	const int N = 10;
	const int M = 30;
}my_map;



/*�����ڿ�����Ҫ���changpos4��5*/