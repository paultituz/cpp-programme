//
//  array.hpp
//  s1051553_hw7
//
//  Created by Ip Kinkwan on 21/4/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

// The example of C++ Class
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

using namespace std;

template <typename T>
class Array {
public:
    Array(int s);
    ~Array();
    void setValue(int index, T value);
    T getValue(int index);
private:
    int Size;
    T *ArrayPtr;
};

#endif /* array_hpp */

template <typename T>
Array<T>::Array(int s) //設定size的大小 取main數值
{
    Size = s;
    ArrayPtr = new T[Size];
}

template <typename T>
Array<T>::~Array()//清除
{
    delete[] ArrayPtr;
}

template <typename T>
void Array<T>::setValue(int index, T value)//取values
{
    ArrayPtr[index] = value;
}

template <typename T>
T Array<T>::getValue(int index)//
{
    return ArrayPtr[index];
}


