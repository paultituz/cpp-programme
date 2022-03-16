//
//  main.cpp
//  s1051553_hw9
//
//  Created by Ip Kinkwan on 12/5/2020.
//  Copyright @ 2020 Ip Kinkwan. All rights reserved.
//

#include <iostream>
#include "monster.h"
#include "Player.h"
#include <string>
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Player a("Paul"); // player one
	Player b("Cyrus"); // player two 
	cout << a.getName() << ":" << endl; // output player1 name
	a.showAliveMonster(); // show player1 alive monster  (list)
	cout << b.getName() << ":" << endl;// output player2 name
	b.showAliveMonster();// show player2 alive monster  （list）

	int cnt = 1;
	srand(time(NULL));//隨機種子
	int fight = rand() % 2;//隨機先攻

	Monster * player1 = a.getCurrentMonster(); // find the alive  monster to fight
	Monster * player2 = b.getCurrentMonster();// find the alive monster to fight

	while (true) {
		if (fight == 1) {
			cout << "Round " << cnt << endl; // show round
			player1->attack(*player2); // attack
			player2->attack(*player1);// attack
			player1->showStats(); // show monster stats
			player2->showStats();// show monster stats
			if (player2->getHP() <= 0) // find out 
			{
				cout << ">>> Player 2's Monster Died! <<<" << endl;
				cout << a.getName() << ":" << endl;
				a.showAliveMonster();
				cout << b.getName() << ":" << endl;
				b.showAliveMonster();
				player2 = b.getCurrentMonster();
				if (player2 == nullptr) { // player 2 monster all deid return nullptr
					cout << "Player 1 Win!" << endl;
					break;
				}
			}

			if (player1->getHP() <= 0)
			{
				cout << ">>> Player 1's Monster Died! <<<" << endl;
				cout << a.getName() << ":" << endl;
				a.showAliveMonster();
				cout << b.getName() << ":" << endl;
				b.showAliveMonster();
				player1 = a.getCurrentMonster();
				if (player1 == nullptr) {// player 1 monster all deid return nullptr
					cout << "Player 2 Win!" << endl;
					break;
				}
			}
			cout << "===============================" << endl;
			cnt++;
		}

		else
		{
			cout << "Round " << cnt << endl;
			player2->attack(*player1);
			player1->attack(*player2);
			player1->showStats();
			player2->showStats();
			if (player1->getHP() <= 0)
			{
				cout << ">>> Player 1's Monster Died! <<<" << endl;
				cout << a.getName() << ":" << endl;
				a.showAliveMonster();
				cout << b.getName() << ":" << endl;
				b.showAliveMonster();
				player1 = a.getCurrentMonster();
				if (player1 == nullptr) {
					cout << "Player 2 Win!" << endl;
					break;
				}
			}
			if (player2->getHP() <= 0)
			{
				cout << ">>> Player 2's Monster Died! <<<" << endl;
				cout << a.getName() << ":" << endl;
				a.showAliveMonster();
				cout << b.getName() << ":" << endl;
				b.showAliveMonster();
				player2 = b.getCurrentMonster();
				if (player2 == nullptr) {
					cout << "Player 1 Win!" << endl;
					break;
				}
			}
			cout << "===============================" << endl;
			cnt++;
		}
	}
	system("pause");
	return 0;
}

