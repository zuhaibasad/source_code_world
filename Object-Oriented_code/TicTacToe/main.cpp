#include "Class_def.cpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand (time(NULL));
    int size;
    string player1f, player1l, player2f, player2l, sym1, sym2;
    do{
        if (!(size == 3 || size == 5 || size == 7 || size == 9))
            cout << "Please enter the correct size! " << endl;
        cout << "Enter the dimensions of Board! ";
        cin >> size;
    }while(!(size == 3 || size == 5 || size == 7 || size == 9));
    cout << "Enter name of first Player: ";
    cin >> player1f >> player1l;
    cout << "Enter his/her symbol: ";
    cin >> sym1;
    cout << "Enter name of second Player: ";
    cin >> player2f >> player2l;
    cout << "Enter his/her symbol: ";
    cin >> sym2;

    Player p1(player1f,player1l,sym1);
    Player p2(player2f, player2l, sym2);
    Game gm(p1,p2,size);
    bool rs = rand()%2;

    if (rs == 0)
    {
        cout << player1f << " will start the Game!" << endl;
    }
    else if (rs == 1)
    {
        cout << player2f << " will start the Game!" << endl;
    }

    gm.print();

    int x,y;
    while (1)
    {
        if (rs == 0)
        {
            cout << player1f << "'s Turn!" << endl;
        }
        else if (rs == 1)
        {
            cout << player2f << "'s Turn!" << endl;
        }

        bool firstTime = true;
        do
        {
            if(firstTime == false)
            {
                if((!(x >=0 && x < size)) || (!(y >=0 && y < size)))
                {
                    cout<< "Position specified is out of range!" << endl;
                }
                else if(gm[x][y].istaken())
                {
                    cout<< "Position already marked! " << endl;
                }
            }

            cout << "Enter the x-coordinate : ";
            cin >> x;
            cout << "Enter the y-coordinate : ";
            cin >> y;

            firstTime = false;
        }
        while((!(x >=0 && x < size)) || (!(y >=0 && y < size)) || gm[x][y].istaken() );

        gm.taketurn(rs, x, y);

        gm.print();

        if ( gm.whoWins() == 1  )
        {
                cout << player1f << " WINS! " << endl;
                break;
        }
        else if ( gm.whoWins() == 2  )
        {
                cout << player2f << " WINS! " << endl;
                break;
        }
        else if ( gm.whoWins() == 3  )
        {
                cout << "Game is tied! " << endl;
                break;
        }
        rs = !rs;
    }



    /*
    if (choice == "3")
    {
        Game start(3);
    }
    else if (choice == "5")
    {
        Game start(5);
    }
    else if (choice == "7")
    {
        Game start(7);
    }
    else if (choice == "9")
    {
        Game start(9);
    }
    else
    {
        cout << "Please type the correct Size! " << endl;
    }

    Game start(3);
    cout <<s1.symb<<endl;
    start[0][1] = s1;
    start.print();

    //cout<< (start[0][0]).symb << endl;
    */
}
