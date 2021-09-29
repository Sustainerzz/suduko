#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include<windows.h>
#include<MMsystem.h>
using namespace std;

const int Size = 9;
char table[Size][Size];
//int timer = 50;

char convetIntIntoChar(int number)
{
    if (number == 1)
        return '1';
    else if (number == 2)
        return '2';
    else if (number == 3)
        return '3';
    else if (number == 4)
        return '4';
    else if (number == 5)
        return '5';
    else if (number == 6)
        return '6';
    else if (number == 7)
        return '7';
    else if (number == 8)
        return '8';
    else return '9';
}

bool checkValidPosition(int row, int column, char number) 
{
    int boxRowPosition = row % 3;
    int boxColumnPosition = column % 3;

    for (int i = 0; i < Size; i++)
    {
        if (table[row][i] == number)
            return false; // number exist already in this row

    }

    for (int i = 0; i < Size; i++)
    {
        if (table[i][column] == number)
            return false; // number exist already in this Column

    }
    // check in box Rows and column
    //
    // if position is left side of box

    if (boxRowPosition == 0 && boxColumnPosition == 0)
    {
        if (table[row + 1][column + 1] == number || table[row + 2][column + 1] == number
            || table[row + 1][column + 2] == number || table[row + 2][column + 2] == number)
            return false;
    }

    if (boxRowPosition == 1 && boxColumnPosition == 0) 
    {
        if (table[row - 1][column + 1] == number || table[row + 1][column + 1] == number
            || table[row - 1][column + 2] == number || table[row + 1][column + 2] == number)
            return false;
    }

    if (boxRowPosition == 2 && boxColumnPosition == 0) 
    {
        if (table[row - 1][column + 1] == number || table[row - 2][column + 1] == number
            || table[row - 1][column + 2] == number || table[row - 2][column + 2] == number)
            return false;
    }
    
    // if position is center of box
    if (boxRowPosition == 0 && boxColumnPosition == 1) 
    {
        if (table[row + 1][column + 1] == number || table[row + 2][column + 1] == number
            || table[row + 1][column - 1] == number || table[row + 2][column - 1] == number)
            return false;
    }

    if (boxRowPosition == 1 && boxColumnPosition == 1) 
    {
        if (table[row - 1][column + 1] == number || table[row + 1][column + 1] == number
            || table[row - 1][column - 1] == number || table[row + 1][column - 1] == number)
            return false;
    }

    if (boxRowPosition == 2 && boxColumnPosition == 1) 
    {
        if (table[row - 1][column + 1] == number || table[row - 2][column + 1] == number
            || table[row - 1][column - 1] == number || table[row - 2][column - 1] == number)
            return false;
    }
    
    // if position is center of box
    if (boxRowPosition == 0 && boxColumnPosition == 2) 
    {
        if (table[row + 1][column - 1] == number || table[row + 1][column - 2] == number
            || table[row + 2][column - 1] == number || table[row + 2][column - 2] == number)
            return false;
    }

    if (boxRowPosition == 1 && boxColumnPosition == 2) 
    {
        if (table[row - 1][column - 1] == number || table[row - 1][column - 2] == number
            || table[row + 1][column - 1] == number || table[row + 1][column - 2] == number)
            return false;
    }

    if (boxRowPosition == 2 && boxColumnPosition == 2) 
    {
        if (table[row - 1][column - 1] == number || table[row - 2][column - 1] == number
            || table[row - 2][column - 1] == number || table[row - 2][column - 2] == number)
            return false;
    }

    return true; // number can write
}

void initializeTable() 
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            table[i][j] = ' ';
        }
    }

    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++) 
        {
            int randRow = rand() % 9;
            int randColumn = rand() % 9;
            int randNumber = rand() % 9;
            char number = convetIntIntoChar(randNumber);

            if (checkValidPosition(randRow, randColumn, number))
            {
                table[randRow][randColumn] = number;
            }
            else {
                table[i][j] = ' ';
            }
        }
    }
}

void displayTable() 
{
    //system("clear");

    cout << "    0   1   2    3   4   5    6   7   8";
    cout << endl << endl;

    for (int i = 0; i < Size; i++) 
    {
        cout << i << "  ";

        for (int j = 0; j < Size; j++)
        {
            cout << " " << table[i][j] << " ";
            if ((j + 1) % 3 == 0) 
            {
                cout << "  ";
            }
            else 
            {
                cout << "|";
            }
        }
        if ((i + 1) % 3 == 0) 
        {
            cout << endl;
        }
        cout << endl;
        if ((i + 1) % 3 != 0) 
        {


            cout << "  ---------    ---------    ---------  " << endl;
        }
    }
}

void userInput()
{
    int row, column, number;
    string wait;

    cout << "Enter Row: "; cin >> row;
    cout << "Enter Column: "; cin >> column;
    cout << "Enter Number: "; cin >> number;

    if (row < 9 && column < 9)
    {
        char num = convetIntIntoChar(number);

        if (table[row][column] != ' ') 
            return;

        if (number != 0 && checkValidPosition(row, column, num)) 
        {
            table[row][column] = num;
        }
        else 
        {
            cout << endl << "Invalid Number; press any key";
            cin >> wait;
        }
    }
    else 
    {
        cout << endl << "Invalid Row OR Column; press any key";
        cin >> wait;
    }
}

bool gameOver()
{
    for (int i = 0; i < Size; i++) 
    {
        for (int j = 0; j < Size; j++)
        {
            if (table[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned)time(0)); // sync code with computer clock
    initializeTable();
    do 
    {
        displayTable();
        userInput();
        if (gameOver()) 
        {
            break;
        }

    } 
    while (true);

    cout << endl << endl << "     GAME OVER" << endl;

    return 0;
}


    
