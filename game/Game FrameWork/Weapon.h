#ifndef Weapon//д����������ͼ���,���Դӻ�����ȭͷ���������ȭͷ���ɻ���һ��һ����������



class Weapon {//������Ϊ���࣬����player����
public:
	virtual void Attack() = 0;
};


/// <summary>
/// ȭͷ,����ͨ�Ĺ�����ʽ
/// </summary>
class Fist : public Weapon {
public:
	const int Atk = 10;
	void Attack() override;
};


/// <summary>
/// �������ֵȴ�����
/// </summary>
class Weapon1 : public Weapon{//��һ���������ȴ�����
	const int Atk = 20;
	void Attack() override;
};


/// <summary>
/// �������ֵȴ�����
/// </summary>
class Weapon2 : public Weapon {//�����������Լ�������

};

//����ȴ����ӣ�������û��ʲô�õ������뷨

#endif // !Weapon
