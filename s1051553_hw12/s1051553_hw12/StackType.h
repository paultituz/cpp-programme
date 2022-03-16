//
//  StackType.hpp
//  s1051553_hw12
//
//  Created by Ip Kinkwan on 8/6/2020.
//  Copyright © 2020 Ip Kinkwan. All rights reserved.
//

#ifndef StackType_hpp
#define StackType_hpp
// filename: StackType.h
#include <stdexcept>
using std::runtime_error;
// MAX_ITEMS: the maximum number of items on the stack.
const int MAX_ITEMS = 5;

// Exception class thrown by Push when stack is full.
class FullStack : public runtime_error
{
public:
    // Add exception message(Stack is Full!) when the constructor is initialized
    FullStack() : runtime_error("stack is full") {}
};

// Exception class thrown by Pop and Top when stack is emtpy.
class EmptyStack : public runtime_error
{
public:
    // Add exception message(Stack is Empty!) when the constructor is initialized
    EmptyStack() : runtime_error("stack is empty") {}
};

class StackType
{
public:

    // Class constructor.
    StackType() {
        top = 0;
    }

    // Function: Determines whether the stack is full.
    bool IsFull() const
    {
        return top == MAX_ITEMS;
    }

    // Function: Determines whether the stack is empty.
    bool IsEmpty() const {
        return top == 0;
    }

    // Function: Adds newItem to the top of the stack.
    // If (stack is full), FullStack exception is thrown;
    // otherwise, newItem is at the top of the stack.
    void Push(char item) {
        if (IsFull()) {
            throw FullStack();
        }
        items[top++] = item;
    }

    // Function: Removes top item from the stack.
    // If (stack is empty), EmptyStack exception is thrown;
    // otherwise, top element has been removed from stack.
    void Pop() {
        if (IsEmpty()) {
            throw EmptyStack();
        }
        --top;
    }

    // Function: Returns a copy of top item on the stack.
    // If (stack is empty), EmptyStack exception is thrown;
    // otherwise, top element has been removed from stack.
    char Top() {
        if (IsEmpty()) {
            throw EmptyStack();
        }
        return items[top - 1];
    }

private:
    int top;
    char items[MAX_ITEMS];
};

#endif /* StackType_hpp */
