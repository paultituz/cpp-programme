//
//  main.cpp
//  s1051553_hw6
//
//  Created by Ip Kinkwan on 14/4/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include <iostream>
#include "monster.hpp"
#include <time.h>
using namespace std;

int main(int argc, const char *argv[])
{
    
    Dragon m1(0.6);
    Unicorn m2;
    int cnt = 1;
    srand(time(NULL));//隨機種子
    int fight = rand() % 2;//隨機先攻
    
    
    while(true){
        
        if (fight==1){
        
            cout << "Round " << cnt << endl;
            m2.attack(m1);
            m1.showStats();
            if( m2.getHP() <= 0 )
            {
                cout << ">>> Unicorn died, Dragon win! <<<" << endl;
            m1.showStats();
                break;
            }
            
            m1.attack(m2);
            m2.showStats();
            if( m1.getHP() <= 0 )
            {
                cout << ">>> Dragon died, Unicorn win <<<" << endl;
            m2.showStats();
                break;
            }
                cout << "===============================" << endl;
            cnt++;
        }
        
    else
    {
        cout << "Round " << cnt << endl;
        m1.attack(m2);
        m2.showStats();
        if( m2.getHP() <= 0 )
        {
            cout << ">>> Unicorn died, Dragon win! <<<" << endl;
        m1.showStats();
            break;
        }
        m2.attack(m1);
        m1.showStats();
        if( m1.getHP() <= 0 )
        {
            cout << ">>> Dragon died, Unicorn win <<<" << endl;
        m2.showStats();
            break;
        }
            cout << "===============================" << endl;
        cnt++;
        }
    }
    return 0;
}
