//#include "stdafx.h"
#include <iostream>
#include "StackNode.h"

using namespace std;

// Default Constructor
StackNode::StackNode() : _row(0), _col(0), _next(NULL)
{
}

// Constructor
StackNode::StackNode( int row, int col, StackNode* next ) : _row(row), _col(col), _next(next)
{
}

// Destructor
StackNode::~StackNode()
{
}

// Get the row of the node
int StackNode::getRow()
{
    return _row;
}

// Get the column of the node
int StackNode::getCol()
{
    return _col;
}

// Set the nodes left flag to true
void StackNode::setLeft()
{
    _triedLeft = true;
}

// Set the nodes straight flag to true
void StackNode::setStraight()
{
    _triedStraight = true;
}

// Set the nodes right flag to true
void StackNode::setRight()
{
    _triedRight = true;
}

// Set the position of the node in the grid
void StackNode::setPosition( int row, int col )
{
    _row = row;
    _col = col;
}

// Get the next node
StackNode* StackNode::getNext()
{
    return _next;
}

// Set the next node
void StackNode::setNext( StackNode *next )
{
    _next = next;
}
