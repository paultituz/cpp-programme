//
//  Rectangle.cpp
//  s1051553_hw1
//
//  Created by Ip Kinkwan on 9/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//
//The project is running for drawing a trangle and calculate area and perimeter
#include "iostream"
#include "Rectangle.hpp"
using namespace std;

Rectangle::Rectangle( unsigned int inputWidth, unsigned int inputLength, char inputCharator)
{
    setWidth( inputWidth );
    setLength( inputLength );
    setFillCharacter( inputCharator );
    
}

void Rectangle::setWidth( unsigned int inputWidth )
{
    if ( inputWidth <= 20 || inputWidth < 0 ){
        width = inputWidth;
    }
    else
        width = 1;
    
}

void Rectangle::setLength( unsigned int inputLength )
{
    if ( inputLength <= 20 || inputLength < 0 ){
        lenght = inputLength;
    }
    else
        lenght = 1;
    
}

void Rectangle::setFillCharacter( char inputCharator )
{
    FillCharacter = inputCharator;
}

void Rectangle::draw()
{
    if( lenght == 1 && width == 1)
    {
        cout << "Draw:" <<endl;
        cout << FillCharacter << endl;
    }
    
    else
    {
    cout << "Draw:" << endl;
        for ( int i = 0; i < lenght; i++)
        {
            cout << FillCharacter;
            
        }
        cout << endl;
    
    for (int j = 0; j < width - 2; j++)
    {
       for (int k = 0; k < lenght; k++)
       {
          if ( k == 0 || k == lenght - 1)
              cout << FillCharacter;
          else
             cout << " ";
       }
       cout << endl;
    }
    for (int i = 0; i < lenght; i++)
        cout << FillCharacter;
    }
    cout << endl;
    
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getLength()
{
    return lenght;
}


void Rectangle::calculatePerimeter()
{
    cout << "Width:" << width << endl;
    cout << "Lenght:" << lenght << endl;
    cout << "Perimeter:" << width * 2 + lenght  * 2 << endl;
}

void Rectangle::calculateArea()
{
    //cout<<width<<"l"<<lenght<<endl;
    cout << "Area:" << width * lenght << endl;
}
