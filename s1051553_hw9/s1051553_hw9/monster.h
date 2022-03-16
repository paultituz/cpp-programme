//
//  monster.hpp
//  s1051553_hw9
//
//  Created by Ip Kinkwan on 12/5/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

class Monster {
private:
	int HP;
	int MaxHP;
	int Attack;
	int Defense;
public:
	Monster(int hp, int mxhp, int atk, int def) :HP(hp), MaxHP(mxhp), Attack(atk), Defense(def) {}
	void setHP(int hp) { HP = hp; }
	int getHP() const { return HP; }
	int getMaxHP() const { return MaxHP; }
	int getAttack() const { return Attack; }
	int getDefense() const { return Defense; }
	//
	virtual int getCounterAttack(int att) { return 0; }
	//
	virtual void showStats()
	{
		cout << setw(10) << "Monster(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl;
	}
	virtual void attack(Monster &m)
	{
		m.setHP(m.getHP() - (getAttack() - m.getDefense()));
	}
};

class Dragon : public Monster {
private:
	double Rate;
public:
	Dragon(double a) :Monster(100, 100, 20, 10) { Rate = a; };//血量 最大血量 攻擊 防禦 附加攻擊
	void showStats()
	{//狀態
		cout << setw(10) << "Dragon(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl;
	}
	void attack(Monster &m)//附加攻擊
	{
		int att = (getAttack() - m.getDefense()) - (rand() % 10 + 1) * Rate;
		m.setHP(m.getHP() - att);
		setHP(getHP() - m.getCounterAttack(att));
	}
};

class Unicorn : public Monster {
public:
	Unicorn() :Monster(100, 100, 20, 10) {};//血量 最大血量 攻擊 防禦
	void showStats()
	{//狀態
		cout << setw(10) << "Unicorn(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl;
	}
	void attack(Monster &m)
	{//特殊攻擊
		int check[4] = { 0, 0, 1, 0 };
		bool spec = true;
		while (spec)
		{
			int att = getAttack() - m.getDefense();
			m.setHP(m.getHP() - att);
			setHP(getHP() - m.getCounterAttack(att));
			if (check[rand() % 4] == 0)
				spec = false;
		}
	}
};


class Hedgehog : public Monster {
public:
	Hedgehog() :Monster(100, 100, 20, 10) {};//血量 最大血量 攻擊 防禦 //攻擊
	void showStats()
	{//狀態
		cout << setw(10) << "Hedgehog(" << setw(3) << getHP() << " / " << setw(3) << getMaxHP() << " )" << endl;
	}

	void attack(Monster &m)//附加攻擊
	{
		int att = getAttack() - m.getDefense();
		m.setHP(m.getHP() - att);
		setHP(getHP() - m.getCounterAttack(att));
	}

	int getCounterAttack(int att)
	{
		return att / 4; // Counterattack 0.25
	}
};


#endif // MONSTER_H
