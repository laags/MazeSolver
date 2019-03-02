#ifndef ASSIGNMENT2_STACK_H
#define ASSIGNMENT2_STACK_H

#include <iostream>
#include "StackNode.h"

using namespace std;
enum myerror_code { success, underflow, overflow };

class Stack
{
private:
    StackNode *_top;

public:
    Stack();
    virtual ~Stack();

    myerror_code Push( int row, int col );
    myerror_code PushRight();
    myerror_code PushLeft();
    myerror_code PushStraight();

    bool PeekLeft();
    bool PeekRight();
    bool PeekStraight();
    void setDirection(char direction);
    char getDirection();
    int PeekRow();
    int PeekCol();
    myerror_code Pop();

    friend ostream& operator<<( ostream& output, Stack& stack );
};


#endif //ASSIGNMENT2_STACK_H
