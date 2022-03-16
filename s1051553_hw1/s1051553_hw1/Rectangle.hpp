//
//  Rectangle.hpp
//  s1051553_hw1
//
//  Created by Ip Kinkwan on 9/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//
//The project is running for drawing a trangle and calculate area and perimeter
#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
using namespace std;

class Rectangle
{
    private:
        unsigned int lenght;
        unsigned int width;
        char FillCharacter;
    
    public:
        Rectangle( unsigned int = 1, unsigned int = 1, char = '*');
        void setWidth( unsigned int );
        void setLength( unsigned int );
        void setFillCharacter( char );
    
        void draw();
    
        int getWidth();
        int getLength();
    
        void calculatePerimeter();
        void calculateArea();

};

#endif /* Rectangle_hpp */
