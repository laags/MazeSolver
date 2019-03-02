#ifndef ASSIGNMENT2_STACKNODE_H
#define ASSIGNMENT2_STACKNODE_H


class StackNode {
private:
    int _col;
    int _row;
    StackNode *_next;

public:
    bool _triedLeft = false;
    bool _triedRight = false;
    bool _triedStraight = false;
    char _direction;

    StackNode();
    StackNode( int row, int col, StackNode* next );
    virtual ~StackNode();

    int getRow();
    int getCol();
    void setLeft();
    void setStraight();
    void setRight();
    void setPosition( int row, int col );

    StackNode* getNext();
    void setNext( StackNode *next );
};


#endif //ASSIGNMENT2_STACKNODE_H
