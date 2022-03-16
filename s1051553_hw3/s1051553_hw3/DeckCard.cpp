//
//  DeckCard.cpp
//  s1051553_hw3
//
//  Created by Ip Kinkwan on 24/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include <iostream>
#include <cstring> // use cstring function
#include <time.h> //use time.h funciton
#include "DeckCard.hpp"
using namespace std;

const string Card::suits[4] = { " Hearts ", " Diamonds ", " Spades ", " Clubs " }; //4
const string Card::faces[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

string Card::toString()
{
    string CardName = suits[ suit ] + " " + faces[ face ]; //output formet
    return CardName;
}

DeckOfCards::DeckOfCards()
{
    for ( int i = 0; i < 13; i++ ){
        for ( int j = 0; j < 4; j++ ){
            deck.push_back( Card( i, j ) );
        }
    }
}

void DeckOfCards::shuffle()
{
    srand( (unsigned) time( NULL ) ); // initialization random
    for ( int currentCard = 0; currentCard < 52; currentCard++ )
    {
        int i = rand() % 52; //random 52 case
    
        Card temp = deck[ currentCard ]; //conversion
        deck[ currentCard ] = deck[ i ];
        deck[ i ] = temp;
    }
    currentCard = -1;
}

Card& DeckOfCards::dealCard()
{
    return deck[ currentCard ];
}

bool DeckOfCards::moreCards()
{
    if ( currentCard < 51 ){ // calculate how many card it print and when stop
        currentCard++;
        return true;
    }
    else
        return false;
}
