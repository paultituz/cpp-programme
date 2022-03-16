//
//  DeckCard.hpp
//  s1051553_hw3
//
//  Created by Ip Kinkwan on 24/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#ifndef DECKCARD_hpp
#define DECKCARD_hpp

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NumSuits = 4;
const int NumFaces = 13;

class Card
{
    public:
        Card(int f,int s): face(f),suit(s){}
        string toString();
    private:
        int face,suit;
        static const string suits[NumSuits];
        static const string faces[NumFaces];
};

class DeckOfCards
{
    private:
        vector<Card> deck;
        int currentCard;
    public:
        DeckOfCards();
        void shuffle();
        Card& dealCard();
        bool moreCards();
};

#endif // DECKCARD_hpp
