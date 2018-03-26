#include <iostream>

using namespace std;

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class square
{
    private:

    square *oneDArray;

    public:

    string symb;
    square();
    square(string tsymb);
    square(square *oneDArray,int sizeN);
    void operator = (string tsymb);
    square& operator[](int index);
    void print();
    bool istaken();
    square *getOneDArray();
};

class Player
{
    private:

    string fname;
    string lname;
    string sym;

    public:

    Player();
    Player(string tfname, string tlname, string tsym);
    void operator = (const Player& p);
    string getsym();
   // friend void operator >> (istream &in, const Player& p);
};

class Game
{
private:
    square **box;
    Player p1;
    Player p2;
    int size;
public:
    Game ();
    Game (int tsize);
    Game (Player tp1, Player tp2, int tsize);
    Game (const Game& g);
    void taketurn(bool temp, int x, int y);
    //friend void operator >> (istream& in, const Game& g);
    void print();
    square& operator[](int index);
    bool allBoxesFilled();
    int whoWins();
};
#endif // HEADER_H_INCLUDED
