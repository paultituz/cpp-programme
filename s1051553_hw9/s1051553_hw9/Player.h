//
//  Player.hpp
//  s1051553_hw9
//
//  Created by Ip Kinkwan on 12/5/2020.
//  Copyright @ 2020 Ip Kinkwan. All rights reserved.
//
#ifndef Player_hpp
#define Player_hpp
#include "monster.h"
#include <stdio.h>
#include <iostream>
using namespace std;
class Player {
public:
	string Name;
	Monster *MonsterList[3];
	Player(string name) {
		Name = name;

		for (int i = 0; i < 3; i++) {
			int random = rand() % 3;
			if (random == 0) { //random = 0 mean dragon
				Dragon *mons = new Dragon(0.6);
				MonsterList[i] = mons;
			}
			else if (random == 1) { // random = 1 mean unicorn
				Unicorn *mons = new Unicorn();
				MonsterList[i] = mons;
			}
			else {
				Hedgehog *mons = new Hedgehog(); // else = hedgehog
				MonsterList[i] = mons;
			}
		}
	}
	string getName() { return Name; } // return name
	Monster * getCurrentMonster() { // cueerntmonster function
		for (int i = 0; i < 3; i++) {
			if (MonsterList[i]->getHP() > 0) { // check 0-2 monster hp 
				return MonsterList[i]; // alive return monster infor
			}
		}
		return nullptr; // all deid return nullptr
	}
	void showAliveMonster() {
		for (int i = 0; i < 3; i++) {
			if (MonsterList[i]->getHP() > 0) { // check 0-2 monster hp 
				MonsterList[i]->showStats(); // use monster.h  show stats function to show infor
			}
		}
	}
};
#endif /* Player_hpp */