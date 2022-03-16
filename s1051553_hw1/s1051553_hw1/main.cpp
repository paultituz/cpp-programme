//
//  main.cpp
//  s1051553_hw1
//
//  Created by Ip Kinkwan on 9/3/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//
//The project is running for drawing a trangle and calculate area and perimeter
#include <iostream>
#include "Rectangle.hpp"
using namespace std;


int main() {
    
    Rectangle CaseOne;

    unsigned int inputWidth;
    unsigned int inputLength;
    char inputCharator;
    
    cout << "Please input width :" <<endl;
    cin >> inputWidth;
    
    cout << "Please input length :" <<endl;
    cin >> inputLength;
    
    cout << "Please input Charator :" <<endl;
    cin >> inputCharator;
    
    CaseOne.setWidth( inputWidth );
    CaseOne.setLength( inputLength );
    CaseOne.setFillCharacter( inputCharator );
    
    CaseOne.draw();
    
    CaseOne.getWidth();
    CaseOne.getLength();
    
    CaseOne.calculatePerimeter();
    CaseOne.calculateArea();
    
    return 0;
}
