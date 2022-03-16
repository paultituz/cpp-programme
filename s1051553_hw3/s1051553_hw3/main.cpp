//
//  main.cpp
//  s1051553_hw3
//
//  Created by Ip Kinkwan on 24/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//
#include <iostream>
#include "DeckCard.hpp"
using namespace std;

int main ()
{
    DeckOfCards deck;
    deck.shuffle();
    while(deck.moreCards()){
        Card& c = deck.dealCard();
        cout << c.toString() << endl;
    }
}

