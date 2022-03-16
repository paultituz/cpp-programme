//
//  main.cpp
//  s1051553_hw12
//
//  Created by Ip Kinkwan on 8/6/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#include "iostream"
#include "StackType.h"
#include "string"

using namespace std;

bool isOpening(char input); //左括號
bool isClosing(char input); //右括號
bool isMatch(char first, char second); // 有對應正確括號

int main() {
    StackType stack = StackType();
    string inputline;
    cin >> inputline; // user input
    try {
        for (int i = 0; i < inputline.length(); ++i) { // for 跑loop
            if (isOpening(inputline[i])) { //是opening 就push
                stack.Push(inputline[i]);
            }
            else if (isClosing(inputline[i])) {//closing
                if (!stack.IsEmpty() && isMatch(stack.Top(), inputline[i])) {//空或者match 就pop
                    stack.Pop();
                }
                else {//else 就push
                    stack.Push(inputline[i]);
                }
            }
        }
    }
    catch (exception ex) {
        cout << ex.what() << endl; // error
    }
    if (stack.IsEmpty()) {
        cout << "Well formed" << endl; // well formed
    }
    else {
        cout << "Not well formed" << endl; // not well
    }
    system("pause");
}

bool isOpening(char input) { // 有哪些是opening
    return input == '{' || input == '[' || input == '('; 
}

bool isClosing(char input) { // 有哪些是closing
    return input == '}' || input == ']' || input == ')';
}

bool isMatch(char first, char second) {// 正確括號
    if (first == '[' && second == ']') {
        return true;
    }
    else if (first == '{' && second == '}') {
        return true;
    }
    else if (first == '(' && second == ')') {
        return true;
    }
    else {
        return false;
    }
}





