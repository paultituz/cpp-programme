//
//  SortedArray.hpp
//  s1051553_hw8
//
//  Created by Ip Kinkwan on 5/5/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#ifndef SortedArray_hpp
#define SortedArray_hpp

#include "array.hpp"
#include <iostream>

using namespace std;

template <typename T>
class SortedArray :public Array<T> {
public:
    SortedArray(int s);
    //~SortedArray();
    void addValue(T t); //add
    bool isgreater(int left, int right); //for int
    bool isgreater(float left, float right); //for float
    bool isgreater(string left, string right); // for string
};

#endif /* SortedArry_hpp */

template <typename T>
SortedArray<T>::SortedArray(int s)
    :Array<T>(s)
{
    
}

template <typename T>
void SortedArray<T>::addValue(T value)
{
    for (int i = 0; i < this->Size; i++){
        if (isgreater(value, this->ArrayPtr[i])){
            for (int j = this->Size - 1; j > i; j--){ // 當j>i 跑for
                this->ArrayPtr[j] = this->ArrayPtr[j - 1]; //  j = j-1
            }
            this->ArrayPtr[i] = value;
            break;
        }
    }
}

template <typename T>
bool SortedArray<T>::isgreater(int left, int right)
{
    if (left >= right) //左大過右 回傳true 否則 false
        return true;
    else
        return false;
}

template <typename T>
bool SortedArray<T>::isgreater(float left, float right)
{
    if (left >= right) //左大過右 回傳true 否則 false
        return true;
    else
        return false;
}

template <typename T>
bool SortedArray<T>::isgreater(string left, string right)
{
    

    if (left.length() > right.length())//比字串長度
        return true;
    else if (left.length() == right.length()) //如果字串一樣就跑else
    {
        char newleft,newright;//創造兩個新的char
        
        for(int i=0; i<left.length() ; i++)
        {
            newleft = left[i]; //代替left
            newright = right[i]; //代替right
            
            if( newleft<97 ) //用ascii 看他大小寫
            {
                newleft = newleft+32; //加32變小寫
            }
            if( newright<97 )//用ascii 看他大小寫
            {
                newright = newright+32;//加32變小寫
            }
            
            if( newleft > newright ) //比較左大過右
            {
                return true;
            }
            else if ( newright>newleft )
            {
                return false;
            }
            
        }
        return true;
    }
    else
        return false;
}
