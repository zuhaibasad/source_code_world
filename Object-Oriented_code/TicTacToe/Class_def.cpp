#include "Class_header.h"
#include <iostream>
#include <iomanip>

using namespace std;

square::square()
{
    symb = " ";
}
square::square (string tsymb)
{
    symb = tsymb;
}
square::square(square *tOneDArray, int sizeN)
{
    oneDArray = tOneDArray;
}
square & square::operator[](int index)
{
    return oneDArray[index];
}
void square::operator = (string tsymb)
{
    symb = tsymb;
}
bool square::istaken( )
{
    return !(symb == " ");
}
void square::print()
{
    cout << endl << endl;
    for (int i=0; i<3; i++)
    {
        cout << "   " <<"  " << "*" <<"   " << " | " << "      " << " | " << "      " <<endl;
        if (i<2)
        cout << "   " <<"______" << " | " << "______" << " | " << "______" << endl;
    }
}

square* square::getOneDArray(){
    return oneDArray;
}

Player::Player()
{
    fname = "";
    lname = "";
    sym = "";
}

Player::Player(string tfname, string tlname, string tsym)
{
    fname = tfname;
    lname = tlname;
    sym = tsym;
}

void Player::operator = (const Player& p)
{
    fname = p.fname;
    lname = p.lname;
    sym = p.sym;
}
string Player::getsym()
{
    return sym;
}
/*
void operator >> (istream& in, const Player& p)
{
    in >> fname >> " " >> lname >> endl;
    cout << "Enter his/her symbol: ";
    in >> sym >> endl;
}
*/

Game::Game()
{
    size = 3;
    box = new square*[size];
    for (int i=0; i<size; i++)
        box[i] = new square [size];
}

Game::Game(int tsize)
{
    size = tsize;
    box = new square *[size];
    for (int i=0; i<size; i++)
        box[i] = new square[size];
}

Game::Game (Player tp1, Player tp2, int tsize)
{
    size = tsize;
    box = new square*[size];
    for (int i=0; i<size; i++)
        box[i] = new square [size];
    p1 = tp1;
    p2 = tp2;
}

Game::Game(const Game& g)
{
    box = new square*[size];
    for (int i=0; i<size; i++)
        *box = new square [size];
}

square& Game::operator[](int index){
    square s(box[index],size);
    return s;
}

void Game::taketurn(bool isplayer1, int tx, int ty)
{
    if (isplayer1)
    {
        box[tx][ty] = p1.getsym();
    }
    else
    {
        box[tx][ty] = p2.getsym();
    }
}

void Game::print()
{
    for (int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout << box[i][j].symb;
        }
        cout << endl;
    }
}

bool Game::allBoxesFilled()
{
    for(int i =0; i < size; i++)
    {
       for(int j = 0; j < size; j++)
       {
           if(box[i][j].symb == " ")
           {
               return false;
           }
       }
    }

    return true;
}

int Game::whoWins()
{
    int i;
    string symbol;

    for (i=0; i<size; i++)
    {
        //for (int k = 0; k < size - 2; k++)
        int k = 0;
        {
            symbol = box[i][k].symb;

            if(!(symbol == " "))
            {
                bool same = true;

                for (int j=k; j<k+3; j++) // find in i th row
                {
                    if(!(box[i][j].symb == symbol))
                    {
                        same = false;
                    }
                }

                if(same)
                {
                    break;
                }
            }

            symbol = box[k][i].symb;
            if(!(symbol == " "))
            {
                bool same = true;

                for (int j=k; j<k+3; j++) // find i th column
                {
                    if(!(box[j][i].symb == symbol))
                    {
                        same = false;
                    }
                }

                if(same)
                {
                    break;
                }
            }
        }
    }

    if(i == size) // loop did not break
    {
        if(allBoxesFilled())
        {
            return 3; // Tie;
        }
        else
        {
            return 0; // No-one;
        }
    }
    else
    {
        if(p1.getsym() == symbol)
        {
            return 1; // Player1 wins;
        }
        else
        {
            return 2; // Player2 wins;
        }
    }
}

/*
void operator >> (istream &in, const Game& g)
{
    cout << "Enter the dimensions of Board: ";
    in >> g.size;
}
*/
