#pragma once
#include"Player.h"

/// <summary>
/// ��������
/// </summary>
class BaseSkill {//�ȴ�ʵ�֣�����bossʹ�õļ��ܣ��жϽ�ɫ�Ƿ��ܵ������ٿ�Ѫ��ʵ�ַ�ʽ�ȴ��ھ������С���Ĺ���
public:
	BaseSkill() {};
	BaseSkill(int BossAtk)
		:BaseAttack(BossAtk) {}

	virtual void Attack() {
		player.Get_Damage(BaseAttack);//��ɫ�յ�BaseAttack���˺���ƽa��
	}

protected:
	int BaseAttack;//��ʼ����ֱ�Ӵ�boss��ȡ
};

class Atk1 : public BaseSkill {//��һ�ֹ�����ʽ������Ļ�ϵ����ϰ��ÿ��ֻ��wasd�������ȫ�Ͳ���Ѫ������һ�ξͿ۳� �趨�Ķ�ӦѪ��
	const int Atk = 50;//����
	void Attack() override {

	}
};