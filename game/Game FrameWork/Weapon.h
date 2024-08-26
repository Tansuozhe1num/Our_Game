#ifndef Weapon//写武器的种类和技能,可以从基础的拳头出发，后把拳头当成基类一步一步升级武器



class Weapon {//武器作为基类，方便player调用
public:
	virtual void Attack() = 0;
};


/// <summary>
/// 拳头,最普通的攻击方式
/// </summary>
class Fist : public Weapon {
public:
	const int Atk = 10;
	void Attack() override;
};


/// <summary>
/// 武器名字等待更改
/// </summary>
class Weapon1 : public Weapon{//第一个武器，等待补充
	const int Atk = 20;
	void Attack() override;
};


/// <summary>
/// 武器名字等待更改
/// </summary>
class Weapon2 : public Weapon {//接下来武器自己定义了

};

//下面等待发挥，看看有没有什么好的武器想法

#endif // !Weapon
