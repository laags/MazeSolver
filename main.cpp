#include <iostream>
#include <fstream>
#include <ctime>
#include "Stack.h"
#include "FileIO.h"

using namespace std;

// Hardcoded maze filename
const string mazeString = "maze4.txt";

int main() {

    // Read in the maze contents first to get the sizes of the array that we need to create
    char ch;
    int rows = 0;
    int cols = 0;
    bool colsCounted = false;
    fstream fin(mazeString, fstream::in);
    // Loop counting each character in the line until we find a newline char, this count will be our columns
    // Count each newline as a row
    while (fin >> noskipws >> ch) {
        if(ch == '\n') {
            colsCounted = true;
            rows++;
        }
        else if(ch != '\n' && !colsCounted)
            cols++;
    }
    rows ++;
    // END READ

    // Next we create the array and once again read in the maze files contents into the array
    char mazeArr[rows][cols];
    int row = 0, col = 0;
    fstream fin2(mazeString, fstream::in);
    while (fin2 >> noskipws >> ch) {
        if (ch == '\n') {
            col = 0;
            row++;
        }
        else {
            mazeArr[row][col] = ch;
            col++;
        }
    }
    // END MAZE CREATION

    // SOLVE THE MAZE

    // Create the maze and push the start point onto the stack as the first node
    Stack mazeStack;
    mazeStack.Push(1, 0);

    // The direction we are currently moving in the array, this is used so that we can traverse the array
    // valid directions are 'r' = right, 'l' = left, 'u' = up, 'd' = down
    char direction = 'r';

    // Loop until we've found the exit
    while(true)
    {
        // We've found the exit, break out of the loop
        if(mazeStack.PeekCol() >= cols-1) {
            break;
        }

        // Take the direction we are traveling and use it to determine left, right and straight by relation.
        // For example, the direction we are traveling is Up, left in the array is - col, but if we are traveling
        // Down then left is + col. We use this logic to solve the maze by deciding which direction to turn in the
        // order Right, Left, Straight. If none of the directions are an empty space we pop the stack and backtrack
        // until we reach a point where we can turn. Filling where we've been in the array.
        if(direction == 'r') {
            // Right
            if(mazeArr[mazeStack.PeekRow()+1][mazeStack.PeekCol()] == ' ' && !mazeStack.PeekRight()) {
                direction = 'd';
                mazeStack.PushRight();
                mazeStack.Push(mazeStack.PeekRow()+1, mazeStack.PeekCol());
                mazeStack.setDirection(direction);
            }
            // Left
            else if(mazeArr[mazeStack.PeekRow()-1][mazeStack.PeekCol()] == ' ' && !mazeStack.PeekLeft()) {
                direction = 'u';
                mazeStack.PushLeft();
                mazeStack.Push(mazeStack.PeekRow()-1, mazeStack.PeekCol());
                mazeStack.setDirection(direction);
            }
            // Straight
            else if(mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()+1] == ' ' && !mazeStack.PeekStraight()) {
                mazeStack.PushStraight();
                mazeStack.Push(mazeStack.PeekRow(), mazeStack.PeekCol()+1);
                mazeStack.setDirection(direction);
            }
            else {
                mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 9;
                mazeStack.Pop();
                direction = mazeStack.getDirection();
            }
            mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 8;
        }

        else if(direction == 'l') {
            // Right
            if(mazeArr[mazeStack.PeekRow()-1][mazeStack.PeekCol()] == ' ' && !mazeStack.PeekRight()) {
                direction = 'u';
                mazeStack.PushRight();
                mazeStack.Push(mazeStack.PeekRow()-1, mazeStack.PeekCol());
                mazeStack.setDirection(direction);
            }
            // Left
            else if(mazeArr[mazeStack.PeekRow()+1][mazeStack.PeekCol()] == ' ' && !mazeStack.PeekLeft()) {
                direction = 'd';
                mazeStack.PushLeft();
                mazeStack.Push(mazeStack.PeekRow()+1, mazeStack.PeekCol());
                mazeStack.setDirection(direction);
            }
            // Straight
            else if(mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()-1] == ' ' && !mazeStack.PeekStraight()) {
                mazeStack.PushStraight();
                mazeStack.Push(mazeStack.PeekRow(), mazeStack.PeekCol()-1);
                mazeStack.setDirection(direction);
            }
            else {
                mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 9;
                mazeStack.Pop();
                direction = mazeStack.getDirection();
            }
            mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 8;
        }

       else if(direction == 'u') {
            // Right
            if(mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()+1] == ' ' && !mazeStack.PeekRight()) {
                direction = 'r';
                mazeStack.PushRight();
                mazeStack.Push(mazeStack.PeekRow(), mazeStack.PeekCol()+1);
                mazeStack.setDirection(direction);
            }
            // Left
            else if(mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()-1] == ' ' && !mazeStack.PeekLeft()) {
                direction = 'l';
                mazeStack.PushLeft();
                mazeStack.Push(mazeStack.PeekRow(), mazeStack.PeekCol()-1);
                mazeStack.setDirection(direction);
            }
            // Straight
            else if(mazeArr[mazeStack.PeekRow()-1][mazeStack.PeekCol()] == ' ' && !mazeStack.PeekStraight()) {
                mazeStack.PushStraight();
                mazeStack.Push(mazeStack.PeekRow()-1, mazeStack.PeekCol());
                mazeStack.setDirection(direction);
            }
            else {
                mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 9;
                mazeStack.Pop();
                direction = mazeStack.getDirection();
            }
            mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 8;
        }

        else if(direction == 'd') {
            // Right
            if(mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()-1] == ' ' && !mazeStack.PeekRight()) {
                direction = 'l';
                mazeStack.PushRight();
                mazeStack.Push(mazeStack.PeekRow(), mazeStack.PeekCol()-1);
                mazeStack.setDirection(direction);
            }
            // Left
            else if(mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()+1] == ' ' && !mazeStack.PeekLeft()) {
                direction = 'r';
                mazeStack.PushLeft();
                mazeStack.Push(mazeStack.PeekRow(), mazeStack.PeekCol()+1);
                mazeStack.setDirection(direction);
            }
            // Straight
            else if(mazeArr[mazeStack.PeekRow()+1][mazeStack.PeekCol()] == ' ' && !mazeStack.PeekStraight()) {
                mazeStack.PushStraight();
                mazeStack.Push(mazeStack.PeekRow()+1, mazeStack.PeekCol());
                mazeStack.setDirection(direction);
            }
            else{
                mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 9;
                mazeStack.Pop();
                direction = mazeStack.getDirection();
            }
            mazeArr[mazeStack.PeekRow()][mazeStack.PeekCol()] = 8;
        }
    }

    // If we hit this point we have found our way out of the maze and we can write to the file
    string mazeString = "";

    // Loop over the array creating the string that we will write to the text file
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(i == mazeStack.PeekRow() && j == mazeStack.PeekCol())
                mazeArr[i][j] = 'X';
            else if(mazeArr[i][j] == 9)
                mazeArr[i][j] = ' ';
            else if(mazeArr[i][j] == 8)
                mazeArr[i][j] = '#';
            mazeString += mazeArr[i][j];
        }
        mazeString += '\n';
    }

    // Write the solution to the text file and close the program
    FileIO::writeMaze(mazeString, "solution.txt");
    cout << "\nMAZE SUCCESSFULLY COMPLETED!";

    return 0;
}