#include"attcak.h"
using namespace std;
Attack::Attack(Role player, Enemy enemy) :player(player), enemy(enemy) {}
Attack::~Attack() {}
Role::Role(){};
Role::~Role() {};
Enemy::Enemy() {};
Enemy::~Enemy() {};
//判断敌人种类，用出不同的攻击方式
void Attack::Enemy_round()
{
	srand((unsigned)time(NULL));
	int i = 0;
	i = rand() % 3 + 1;
	if (i == 1)
	{
		Range_1();
	}
	if (i == 2)
	{
		Range_2();
	}
	if (i == 3)
	{
		Range_3();
	}
	
};//敌方回合
//画出作战范围
void Attack::eara()
{
	
	
	for (int i= 0; i<=HIGH; i++)
	{
		for (int j= 0; j<=WIDE; j++)
		{
			if (j == WIDE)
			{
				cout << "┃";
			}
			if (i == HIGH)
			{
				cout << "━";
			}
			else
				cout << " ";
		};
		cout << endl;

	};
};//初始化界面
//角色移动
void Attack::Heart_move() 
{
	
	COORD heart = { 0 };
	heart.X = Heart.x;
	heart.Y = Heart.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), heart);
	cout << "○";
	COORD record = { 0 };
	char p;
	Hurt = 0;
	do
	{
		if (_kbhit())
		{
			record = heart;//存储定位
			p = _getch();
			if (p == 'a')
			{

				if (heart.X == 0)
				{
					heart.X = heart.X;
				}
				else
					heart.X--;

			}
			if (p == 'w')
			{
				if (heart.Y == 0)
				{
					heart.Y = heart.Y;
				}
				else
					heart.Y--;
			}
			if (p == 's')
			{
				if (heart.Y > 8)
				{
					heart.Y = heart.Y;
				}
				else
					heart.Y++;
			}
			if (p == 'd')
			{
				if (heart.X > 28)
				{
					heart.X = heart.X;
				}
				else
					heart.X++;
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), record);
			putchar(' ');
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), heart);
			cout << "○";
			Heart.x = heart.X;
			Heart.y = heart.Y;
		}
	} while (!Hurt);
	Hurt = 0;
};
//展示伤害信息
void Attack:: Show_hurt_number()
{
	if (Hurt)
	{
		 Sleep(500);
		COORD show = { 0,21};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), show);
		int hurt_num = 0;
		hurt_num = enemy.Attack - player.define;
		if (hurt_num > 0)
		{
			player.HP -= hurt_num;
			cout << "被击中，你受到了" << hurt_num << "点伤害" << endl;
		}
		if (hurt_num <= 0)
		{
			cout << "抵挡了攻击，造成1点伤害" << endl;
			player.HP -= 1;
		}
		if (player.HP <= 0)
		{
			If_attacking = 0;
		}
	}
};
//展示可以进行的行动
void Attack::Before_action()
{
	if (If_attacking == 1)
	{
		Hurt = 0;
		system("cls");
		eara();
		Show_information();
		cout << "这是我的回合，要做什么呢" << endl;
		cout << "1-普通攻击，进入下一回合。2-魔法攻击，进入下一回合。3-使用药品。4-逃跑" << endl;
		char choices = '0';
		choices = _getch();
		while (1)
		{
			if (choices != '1' && choices != '2' && choices != '3' && choices != '4')
			{
				cout << "选择错误，请重新选择。" << endl;
				choices = _getch();
			}
			else break;
		}
		if (choices == '1')
		{
			Our_round();
		}
		if (choices == '2')
		{
			Magic_attack();
		}
		if (choices == '3')
		{
			Reply();
		}
		if (choices == '4')
		{
			cout << "逃跑成功" << endl;
			If_attacking = 0;
		}
	}
}
//计算伤害
void Attack::Our_round()
{
	hurt = player.Attack - enemy.define;
	if (hurt <= 0)
	{
		cout << "useless attack" << endl;
		cout << "但是敌人的防御力被削减了" << enemy.define - 3 << endl;
		enemy.define -= 3;


	}
	if (hurt > 0)
	{
		cout << "对敌人造成了" << hurt << "点伤害" << endl;
		enemy.HP = enemy.HP - hurt;
		
	}
	if (enemy.HP <= 0)
	{
		cout << "成功击败XX" << endl;
		If_attacking = 0;
	}
	else
	{
		Sleep(2000);
		return New_round();
	}
	
}
//计算技能伤害 
void Attack::Magic_attack()
{
	cout << "你现在的MP" << player.mp << endl;
	cout << "已经学习的技能" << endl;
	cout << "选择你要使用的技能--1--" << endl;
	int choices = 0;
	cin >> choices;
	if (choices == '1')
	{

	}
	return;
}
//使用技能伤害
void Attack::Reply()
{
	system("cls");
	eara();
	cout << "可以使用的药物" << endl;
	cout << "背包待展示界面——" << endl;
	cout << "1-使用" << endl;
	char p;
	p = _getch();
	if (p == '1')
	{
		cout << "成功使用XX" << "共回复" << endl;
		cout << "即将进入下一回合" << endl;
	}
	Sleep(2000);
	return New_round();
}
void Attack::Range_1()
{
	Sleep(2000);
	COORD attack = { 0 };
	COORD danger = { 0 };
	range_1 = { 0 };
	range_1.body[0] = { 5,2 };
	danger_1.body[0] = range_1.body[0];
	//生成攻击预警区域
	int count = 0;
	for (int j = 1; j < 6; j++)
	{
		count++;
		danger_1.body[count] = { 5 ,2 + j };//记录一次坐标
		danger.X = danger_1.body[count].x;
		danger.Y = danger_1.body[count].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), danger);
		if (danger.X < WIDE && danger.Y < HIGH)
			cout << "!";

		for (int k = 1; k < 6; k++)
		{
			count++;
			danger_1.body[count] = { 5 + k,2 + j };
			danger.X = danger_1.body[count].x;
			danger.Y = danger_1.body[count].y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), danger);
			if (danger.X < WIDE && danger.Y < HIGH)
				cout << "!";
		}
	}
	Sleep(2000);
	count = 0;
	//生成实际攻击区域
	for (int j = 1; j < 6; j++)
	{
		count++;
		range_1.body[count] = { 5 ,2 + j };//记录一次坐标
		attack.X = range_1.body[count].x;
		attack.Y = range_1.body[count].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), attack);
		if (attack.X < WIDE && attack.Y < HIGH)
			cout << "■";

		for (int k = 1; k < 6; k++)
		{
			count++;
			range_1.body[count] = { 5 + k,2 + j };
			attack.X = range_1.body[count].x;
			attack.Y = range_1.body[count].y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), attack);
			if (attack.X < WIDE && attack.Y < HIGH)
				cout << "■";
		}
	}
	count = 0;
	for (int k = 0; k < WIDE * HIGH; k++)
	{
		count++;
		range_2.body[count] = { 33,33 };
		danger_2.body[count] = { 33,33 };
	}
	Sleep(2000);
	Hurt = 1;
}
void Attack::Range_2()
{
	Sleep(2000);
	COORD attack = { 0 };
	COORD danger = { 0 };
	COORD current_position = { 0 };
	current_position.X = Heart.x;
	current_position.Y = Heart.y;
	range_2 = { 0 };
	danger_2.body[0] = { Heart.x, Heart.y };
	//生成攻击预警区域
	int count = 0;
	danger.Y = current_position.Y;
	danger.X = 0;
	for (int i = -1; i < 2; i++)
	{
		count++;
		danger.Y = current_position.Y + i;
		if (danger.Y < HIGH)
		{
			danger_2.body[count - 1].x = 0;
			danger_2.body[count - 1].y = danger.Y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), danger);
			cout << "━━>";
		}
	}
	//生成实际攻击区域
	Sleep(2000);
	count = 0;
	range_2.body[0] = danger_2.body[0];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < WIDE; j++)
		{
			count++;
			range_2.body[count - 1] = { j , danger_2.body[i].y };
			if (range_2.body[count - 1].y < HIGH)
			{
				
				attack.X = range_2.body[count - 1].x;
				attack.Y = range_2.body[count - 1].y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), attack);
				cout << "■";
			}

		}
	}
	count = 0;
	for (int k = 0; k < WIDE * HIGH; k++)
	{
		count++;
		range_2.body[count] = { 33,33 };
		danger_2.body[count] = { 33,33 };
	}
	Sleep(2000);
	Hurt = 1;
}
void Attack::Range_3()
{
	Sleep(2000);
	COORD attack = { 0 };
	COORD danger = { 0 };
	danger_3.body[0] = { 1,0 };
	range_3.body[0] = { 1,0 };
	int count = 0;
	//生成预警范围
	for (int j = 0; j < 2; j++)
	{
		danger.Y = j;
		for (int i = 0; i < WIDE; i++)
		{
			if (i % 2 == 0 && i != 0)
			{
				count++;
				danger_3.body[count].x = i;
				danger.X = danger_3.body[count].x;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), danger);
				if (danger.X < WIDE && danger.Y < HIGH)
				{
					if (danger.Y != 1)
					{
						cout << "┃";
					}
					else
						cout << "∨";
				}

			}

		}
	}
	//生成实际攻击范围
	count = 0;
	Sleep(2000);
	//先存入坐标
	for (int j = 0; j < HIGH; j++)
	{
		for (int i = 0; i < WIDE; i++)
		{
			if (i % 2 == 0 && i != 0)
			{
				count++;
				range_3.body[count].x = i;
				range_3.body[count].y = j;
				attack.X = range_3.body[count].x;
				attack.Y= range_3.body[count].y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), attack);
				if (attack.X < WIDE && attack.Y < HIGH)
				{
					cout << "┃";
				}

			}
		}
	}
	count = 0;
	for (int k = 0; k < WIDE * HIGH; k++)
	{
		count++;
		range_3.body[count] = { 33,33 };
		danger_3.body[count] = { 33,33 };
	}
	Sleep(2000);
	Hurt = 1;
}
//设定初始位置
void Attack::Initi_Hreat()
{
	Heart.x = WIDE / 2;
	Heart.y = HIGH / 2;
	
}
//开始新的回合
void Attack::New_round()
{
	Initi_Hreat();
	system("cls");
	eara();
	thread t1(&Attack::Heart_move,this);
	thread t2(&Attack::Enemy_round,this);
	thread t3(&Attack::Heart_test, this);
	t1.join();
	t2.join();
	t3.join();
	system("cls");
}
//展示双方信息
void Attack::Show_information()
{
	cout << "当前敌人信息" << endl;
	cout << setw(10) << left << "Name:"
		<< setw(10) << left << "HP:"
		<< setw(10) << left << "Attack:"
		<< setw(10) << left << "Defend:" <<endl;
	 cout <<  setw(10) <<  left<<"aa"
		<<  setw(10) <<  left << enemy.HP
		<<  setw(10) <<  left << enemy.Attack
		<<  setw(10) <<  left << enemy.define <<  endl;

	cout << "角色状态" << endl;
	cout <<  setw(10) << left << "HP:"
		<<  setw(15) <<  left << "Attack:"
		<<  setw(15) <<  left << "Defend:" <<  endl;
	 cout <<  setw(10) <<  left << player.HP
		<<  setw(15) <<  left << player.Attack
		<<  setw(15) <<  left << player.define <<  endl;
};
//统计战后信息
void Attack::Attack_information()
{
	system("cls");
	if (player.HP <= 0)
	{
		cout << "你死了" << endl;
	}
	if (enemy.HP <= 0)
	{
		cout << "战斗胜利，并获得以下战利品" << endl;
	}
};
void Attack::Heart_test()
{
	do
	{
		for (int j = 0; j < WIDE * HIGH; j++)
		{
			if (Heart.x == range_1.body[j].x && Heart.y == range_1.body[j].y || Heart.x == range_2.body[j].x && Heart.y == range_2.body[j].y || Heart.x == range_3.body[j].x && Heart.y == range_3.body[j].y)
			{
				Hurt = 1;
				Show_hurt_number();
				Sleep(1000);
				return;
			}
		}
	} while (Hurt == 0);
}
int main()
{
	Role player;
	Enemy boss;
	Attack Test(player,boss);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	do
	{
		Test.Before_action();
	} while (Test.If_attacking == 1);
	Test.Attack_information();
};

