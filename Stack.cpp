#include "Stack.h"
#include <iostream>
#include "StackNode.h"

using namespace std;

// Constructor
Stack::Stack() : _top(NULL)
{
}

// Destructor
Stack::~Stack()
{
    while( _top != NULL )
    {
        Pop();
    }
}

// Push a new node onto the stack, takes a position in the form of two ints
myerror_code Stack::Push( int row, int col )
{
    _top = new StackNode( row, col, _top );
    return(success);
}

// Sets the left flag of the top of the stack to true
myerror_code Stack::PushLeft()
{
    _top->setLeft();
    return(success);
}

// Sets the right flag of the top of the stack to true
myerror_code Stack::PushRight()
{
    _top->setRight();
    return(success);
}

// Sets the straight flag of the top of the stack to true
myerror_code Stack::PushStraight()
{
    _top->setStraight();
    return(success);
}

// Sets the direction of the top of the stack that we are traveling within the grid, example U, L, D, R
void Stack::setDirection(char direction)
{
    _top->_direction = direction;
}

// Get the direction we are traveling from the top of the stack
char Stack::getDirection()
{
    return _top->_direction;
}

// Check the top of the stack to see if we've gone right already
bool Stack::PeekRight()
{
    return _top->_triedRight;
}

// Check the top of the stack to see if we've gone left already
bool Stack::PeekLeft()
{
    return _top->_triedLeft;
}

// Check the top of the stack to see if we've gone straight already
bool Stack::PeekStraight()
{
    return _top->_triedStraight;
}

// Gets the row of the top of the stack
int Stack::PeekRow()
{
    return _top->getRow();
}

// Gets the column of the top of the stack
int Stack::PeekCol()
{
    return _top->getCol();
}

// Pop the top of the stack off
myerror_code Stack::Pop()
{
    if (_top != NULL) {

        StackNode* node = _top;
        _top = _top->getNext();
        delete node;
        return(success);
    }
    else {
        return(underflow);
    }
}

ostream& operator<<( ostream& output, Stack& stack )
{
    StackNode *node = stack._top;

    while( node != NULL )
    {
        cout << node->getRow() << endl;
        cout << node->getCol() << endl;
        node = node->getNext();
    }

    return output;
}
