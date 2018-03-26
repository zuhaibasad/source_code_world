
// Contributor: Zuhaib Asad
// Not any part of code is derived from any other source code.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

void deck(string **table);
void shuffle(string **table);
void newgame(string**);
string mainpage(string*);
int game(string ***, string **, string ***,int, int&);
int extend(string***,int, int ,int, int );
int extend2(string ***, int,int);
int colcolmov(string ***, string **, int);
void indicator(string**);
bool checkmove(string ***table, int rsrc, int rdest, int csrc, int cdest, int numcrd);
void display(string*** , string **, string ***,int, int);
void colfremov(string ***, string **);
int frecolmov(string ***, string **, int);
bool checkfrecolmov(string ***, string **, int, int, int);
bool checkcolhommov(string ***, string ***, int, int, int ,int);
bool checkfrehommov(string **, string ***, int, int ,int);
int colhommov(string ***, string ***, int);
int frehommov(string **, string ***, int);
void savegame(string ***, string **, string ***, int, int);
int resume(string ***, string **, string ***, int, int&);
int wingame(string ***);

int main()
{
    srand(time(0));
    ifstream infile;
    string *selection;
    string choice;
    string choicemain;
    int checksize = 8;          //initial number of rows of table of cards.
    int checksize2 = 2;

    // **********Dynamic Array Production Unit********** //
        string **table = new string*[checksize];
        for(int i=0; i<checksize; i++)
            table[i] = new string[8];       // 8-by-8 dynamic array
        string *freecell = new string[4];
        for (int i=0; i<4; i++)
            freecell[i] = " ";
        string **homecell = new string*[checksize2];
            for (int i=0; i<checksize2; i++)
                homecell[i] = new string[4];
        for (int i=0; i<checksize2; i++)
        {
            for (int j=0; j<4; j++)
            {
                if (i == 0)
                    homecell[i][j] = "";
                else
                    homecell[i][j] = " ";
            }
        }
    // ************************************************* //

    do{
    choicemain = mainpage(selection);
    if (choicemain == "1")
    {
        deck(table);
        shuffle(table);
        display(&table, &freecell, &homecell,checksize,checksize2);
        checksize = game(&table, &freecell, &homecell,checksize, checksize2);
    }
    else if (choicemain == "2")
    {
        resume(&table, &freecell, &homecell, checksize, checksize2);
        display(&table, &freecell, &homecell,checksize,checksize2);
        checksize = game(&table, &freecell, &homecell,checksize, checksize2);
    }
    else if (choicemain != "-1")
        cout << "Invalid Choice!..." << endl;
    }while(choicemain != "-1" );

}

int wingame(string ***homecell)
{
    int i,j,k,l;
    for (i=0; (*(*(*(homecell)+i)+0)) != " "; i++);
    for (j=0; (*(*(*(homecell)+i)+1)) != " "; j++);
    for (k=0; (*(*(*(homecell)+i)+2)) != " "; k++);
    for (l=0; (*(*(*(homecell)+i)+3)) != " "; l++);
    if (i==12 || j==12 ||k==12 ||l==12)
        return 1;
}

int game(string ***table, string **freecell, string ***homecell, int checksize, int &checksize2)
{
    string choice;
    do{
    cout << "Enter 1 for column to column move" << endl;
    cout << "Enter 2 for column to free-cell move" << endl;
    cout << "Enter 3 for free-cell to column move" << endl;
    cout << "Enter 4 for column to home move" << endl;
    cout << "Enter 5 for free-cell to home move" << endl;
    cout << "Enter 6 to save your current game" << endl;
    cout << "Enter -1 to exit the game " << endl;
    cout << "Enter you choice: ";
    cin >> choice;

    if (choice == "1")
        checksize = colcolmov(&*table, &*freecell,checksize);
    else if (choice == "2")
        colfremov(&*table, &*freecell);
    else if (choice == "3")
        checksize = frecolmov(&*table, &*freecell, checksize);
    else if (choice == "4")
        checksize2 = colhommov(&*table, &*homecell, checksize2);
    else if (choice == "5")
        checksize2 = frehommov(&*freecell, &*homecell, checksize2);
    else if (choice == "6")
        savegame(&*table, &*freecell, &*homecell, checksize, checksize2);
    else if (choice != "-1")
        cout << "Invalid Choice !..." << endl;
    display (&*table, &*freecell, &*homecell,checksize,checksize2);
    int win = wingame(&*homecell);
    if (win == 1)
        cout << "You WIN ! ! ! " << endl;
    }while(choice != "-1");
    return checksize;
}
void deck(string **table)
{ //this function creates the deck in the dynamic array

    string cardno = "KQJA2345678910";   //numbers on card
    string cardtype = {3,4,5,6,'\0'};           //types of card

    int xcor=0,ycor=0;  // x co-ordinate and y co-ordinate used for array named table later in loops below

    for (int i=0; i<=13; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(i!=0&&i%2==0&&j==0)  //want to make 8-by-8 array(dropped last 4 elements) so using xcor
                xcor++;                // to increase only when 2 values of i has increased and at begining of every j;
            if(i!=0&&i%2==0&&j==0)
                ycor=0;                //make b 0 after two iterations of i and at start of j;
            if (i==13)
            {   // copying 10 from cardno which is 13th element
                table[xcor][j] = cardno.substr(i-1,2)+cardtype.substr(j,1);
            }
            else if (i < 12)
            {
                table[xcor][ycor] = cardno.substr(i,1) + cardtype.substr(j,1);
            }
            ycor++;
        }
    }
    for (int i=0; i<4; i++)
    {
        table[6][i+4] = " ";
        table[7][i] = " ";
        table[7][i+4] = " ";
    }
}

void shuffle(string **table)
{ //this function does the complete randomly shuffling of deck of cards!
  //using random_shuffle built-in function...

    for (int i=0; i<6; i++)                         //this loop randomly shuffles each rows element in that row only
        random_shuffle(&table[i][0], &table[i][6]); //because random_shuffle function working only for single row
    for (int i=1; i<6; i++)
    {
        for (int j=1; j<8; j++)
        {
            swap(table[i][j],table[i-1][j-1]);  //now shuffling rows into columns
        }
    }
    for (int i=0; i<4; i++)
    {
        swap(table[6][i],table[i][i]);          //shuffling the last row of 4 elements into the above array elements
    }
    for (int i=0; i<6; i++)                     //again randomly shuffling to ensure Randomness
        random_shuffle(&table[i][0], &table[i][6]);
}

int colcolmov(string ***table, string **freecell, int checksize)
{
    int csrc,cdest,numcrd;
    int rsrc=0, rdest=0;
    cout << "Enter the column number as source ";
    cin >> csrc;
    cout << "Enter the column number as destination ";
    cin >> cdest;
    cout << "Enter the number of cards to be moved ";
    cin >> numcrd;

    csrc--; cdest--;        //-1 for use in indexing

    if (csrc>7)
        {
            cout << "Invalid Move!..." << endl;
            return checksize;
        }
    if (cdest>7)
    {
        cout << "Invalid Move!..." << endl;
        return checksize;
    }

    for (int i=0; (*(*(*(table)+i)+csrc)) != " "; i++)      //loop to know in which row the most exposed card is.
                                                            //spaces are the indicators to know the end has reached
    {
        rsrc = i;
    }

    for (int i=0; (*(*(*(table)+i)+cdest)) != " "; i++)     //similarly knowing where the target card is placed
    {
            rdest = i;
    }
    bool flag = checkmove(&*table, rsrc, rdest, csrc, cdest, numcrd);       //function that checks various conditions of sequence of card# and colors
    if (flag == 1)                      // if all sequence are OK
    {
        checksize = extend(&*table,numcrd,rdest,cdest,checksize);                 //function which expands the size of dynamic array if needed
        for (int i=1; i<=numcrd; i++)
        {
            swap ((*(*(*(table)+(rdest+i))+cdest)),(*(*(*(table)+(rsrc-(numcrd-i)))+csrc)));        //swapping elements to the desired locations
        }
        //display(&*table, &*freecell, checksize);                                        //display the progress on screen
    }
    else
    {
        cout << "Invalid Move!!..." << endl;
    }
    return checksize;     //if the table size has increased then returning its new size is necessary to be able to guess that in next turn
}                         // size of table needs to be increased or not..
void colfremov(string***table, string** freecell)
{
    int csrc,cdest,numcrd;
    int rsrc=0, rdest=0;
    cout << "Enter the column number of tableau as source: ";
    cin >> csrc;
    cout << "Enter the column number of free-cell as destination: ";
    cin >> cdest;

    csrc--; cdest--;        //-1 for use in indexing

    if (csrc>7)
        {
            cout << "Invalid Move!..." << endl;
            return;
        }
    if (cdest>3)
    {
        cout << "Invalid Move!..." << endl;
        return;
    }

    for (int i=0; (*(*(*(table)+i)+csrc)) != " "; i++)      //loop to know in which row the most exposed card is.
                                                            //spaces are the indicators to know the end has reached
    {
        rsrc = i;
    }
    if ( (*(*(freecell)+cdest)) != " " || cdest > 3)        //check if there is already element there and the freecells are only first 4 columns
    {
        cout << "Invalid Move!..." <<endl;
    }
    else
        swap((*(*(*(table)+rsrc)+csrc)),(*(*(freecell)+cdest)));
}

int frecolmov(string ***table, string **freecell, int checksize)
{
    int csrc,cdest,numcrd;
    int rdest=0;

    cout << "Enter the column number of free-cell as source: ";
    cin >> csrc;
    cout << "Enter the column number of tableau as destination: ";
    cin >> cdest;
    csrc--; cdest--;        //-1 for use in indexing

    if (csrc>3)
        {
            cout << "Invalid Move!..." << endl;
            return checksize;
        }
    if (cdest>7)
    {
        cout << "Invalid Move!..." << endl;
        return checksize;
    }

    if ((*(*(freecell)+csrc)) == " " || csrc > 3)
    {
        cout << "Invalid move!... " << endl;
        return checksize;
    }

    for (int i=0; (*(*(*(table)+i)+cdest)) != " "; i++)     //similarly knowing where the target card is placed
    {
            rdest = i;
    }
    bool flag = checkfrecolmov(&*table, &*freecell, rdest, csrc, cdest);
    if (flag == 1)
    {
        checksize = extend(&*table,1,rdest,cdest,checksize);
        swap((*(*(*(table)+(rdest+1))+cdest)),(*(*(freecell)+csrc)));
    }
    else
    {
        cout << "Invalid Move...! " << endl;
    }
    return checksize;
}

int colhommov(string ***table, string ***homecell, int checksize2)
{
    int csrc, rsrc, cdest, rdest;
    cout << "Enter the column number of tableau as source: ";
    cin >> csrc;
    cout << "Enter the column number of home-cell as destination: ";
    cin >> cdest;

    csrc--; cdest--;        //-1 for use in indexing

    if (csrc>7)
        {
            cout << "Invalid Move!..." << endl;
            return checksize2;
        }
    if (cdest>3)
    {
        cout << "Invalid Move!..." << endl;
        return checksize2;
    }

    for (int i=0; (*(*(*(table)+i)+csrc)) != " "; i++)      //loop to know in which row the most exposed card is.
                                                            //spaces are the indicators to know the end has reached
    {
        rsrc = i;
    }
    cout << "Here outside break! " << endl;

    for (int i=0; (*(*(*(homecell)+i)+cdest)) != " "; i++)     //similarly knowing where the target card is placed
    {       cout << "Here break! " << endl;
            rdest = i;
    }
    bool flag = checkcolhommov(&*table, &*homecell, rsrc, rdest, csrc, cdest);
    if (flag == 1)
    {
        checksize2 = extend2(&*homecell, rdest, checksize2);
        if ((*(*(*(table)+rsrc)+csrc)).substr(0,1)== "A")
            swap((*(*(*(table)+rsrc)+csrc)),(*(*(*(homecell)+(rdest))+cdest)));
        else
            swap((*(*(*(table)+rsrc)+csrc)),(*(*(*(homecell)+(rdest+1))+cdest)));
    }
    else
    {
        cout << "Invalid Move!..." << endl;
    }
    return checksize2;
}

int frehommov(string **freecell, string ***homecell, int checksize2)
{
    int csrc, rsrc, cdest, rdest;
    cout << "Enter the column number of free-cell as source: ";
    cin >> csrc;
    cout << "Enter the column number of home-cell as destination: ";
    cin >> cdest;

    csrc--; cdest--;        //-1 for use in indexing

    if (csrc>3)
        {
            cout << "Invalid Move!..." << endl;
            return checksize2;
        }
    if (cdest>3)
    {
        cout << "Invalid Move!..." << endl;
        return checksize2;
    }

    for (int i=0; (*(*(*(homecell)+i)+cdest)) != " "; i++)     //similarly knowing where the target card is placed
    {
            rdest = i;
    }
    bool flag = checkfrehommov(&*freecell, &*homecell, rdest, csrc, cdest);
    if (flag == 1)
    {
        checksize2 = extend2(&*homecell, rdest, checksize2);
        if ((*(*(freecell)+csrc)).substr(0,1)== "A")
            {
                swap((*(*(freecell)+csrc)),(*(*(*(homecell)+(rdest))+cdest)));
            }
        else
            swap((*(*(freecell)+csrc)),(*(*(*(homecell)+(rdest+1))+cdest)));
    }
    else
    {
        cout << "Invalid Move!..." << endl;
    }
    return checksize2;
}

bool checkfrehommov(string **freecell, string ***homecell, int rdest, int csrc, int cdest)
{
    //This function checks the sequences of source card and destination cards and their colors
    //Also checks if the multiple cards are to be moved then their sequence and colors are OK to move

    int temp1s = 0, temp1d=0;         //these temporary variables used to check the alternativity of colors and sequence of card no.
    string src;
    string dest;
    string cardno = "A234567891JQK";               //this string is made in a special sequence which will be explained in Viva.(if required)
    string cardtype = {3,4,5,6,'\0'};              // 3=heart-red,4=diamond-red,5=club-black,6=spades-black

    src = (*(*(freecell)+csrc));
    dest = (*(*(*(homecell)+rdest)+cdest));
    if ((*(*(*(homecell)+rdest)+cdest)) == "")
    {
        if (src[0] != 'A')                             //Ace cards should be moved first
            return 0;
        else if (src[0] == 'A')
            return 1;                 //Ace is first card so no comparing just return and swap in calling function
    }
    else
    {
        for (int i=0; cardno[i]!='\0'; i++)
        {
            if(src[0] == cardno[i])                 //getting the index of # of source-card in cardno string
                temp1s = i;
            if(dest[0] == cardno[i])                //similar to above
                temp1d = i;
        }
            if (cardno[temp1d+1] == cardno[temp1s])         //that the destination-column card and source-column card are Sequential and colors are OK...
            {
                if (src[0] == '1')                          //if source card is 10 then third character that matters
                {
                    if ((src[2]==3&&dest[1]==3)||(src[2]==4&&dest[1]==4)||(src[2] == 5 && dest[1]==5) || (src[2] == 6 && dest[1] == 6))
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else if (dest[0] == '1')                    //if target card is 10 then third character that matters
                {
                    if ((src[1]==3&&dest[2]==3)||(src[1]==4&&dest[2]==4)||(src[1] == 5 && dest[2]==5) || (src[1] == 6 && dest[2] == 6))
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                {
                    if ((src[1]==3&&dest[1]==3)||(src[1]==4&&dest[1]==4)||(src[1] == 5 && dest[1]==5) || (src[1] == 6 && dest[1] == 6))
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
            }
            else
                return 0;
    }
}



bool checkcolhommov(string ***table, string ***homecell, int rsrc, int rdest, int csrc, int cdest)
{
    //This function checks the sequences of source card and destination cards and their colors
    //Also checks if the multiple cards are to be moved then their sequence and colors are OK to move

    int temp1s = 0, temp1d=0;         //these temporary variables used to check the alternativity of colors and sequence of card no.
    string src;
    string dest;
    string cardno = "A234567891JQK";               //this string is made in a special sequence which will be explained in Viva.(if required)
    string cardtype = {3,4,5,6,'\0'};              // 3=heart-red,4=diamond-red,5=club-black,6=spades-black

    src = (*(*(*(table)+rsrc)+csrc));
    dest = (*(*(*(homecell)+rdest)+cdest));
    if ((*(*(*(homecell)+rdest)+cdest)) == "")
    {
        if (src[0] != 'A')                             //Ace cards should be moved first
            return 0;
        else if (src[0] == 'A')
            return 1;                 //Ace is first card so no comparing just return and swap in calling function
    }
    else
    {
        for (int i=0; cardno[i]!='\0'; i++)
        {
            if(src[0] == cardno[i])                 //getting the index of # of source-card in cardno string
                temp1s = i;
            if(dest[0] == cardno[i])                //similar to above
                temp1d = i;
        }
            if (cardno[temp1d+1] == cardno[temp1s])         //that the destination-column card and source-column card are Sequential and colors are OK...
            {
                if (src[0] == '1')                          //if source card is 10 then third character that matters
                {
                    if ((src[2]==3&&dest[1]==3)||(src[2]==4&&dest[1]==4)||(src[2] == 5 && dest[1]==5) || (src[2] == 6 && dest[1] == 6))
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else if (dest[0] == '1')                    //if target card is 10 then third character that matters
                {
                    if ((src[1]==3&&dest[2]==3)||(src[1]==4&&dest[2]==4)||(src[1] == 5 && dest[2]==5) || (src[1] == 6 && dest[2] == 6))
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
                else
                {
                    if ((src[1]==3&&dest[1]==3)||(src[1]==4&&dest[1]==4)||(src[1] == 5 && dest[1]==5) || (src[1] == 6 && dest[1] == 6))
                    {
                        return 1;
                    }
                    else
                        return 0;
                }
            }
            else
                return 0;
    }
}


bool checkfrecolmov(string ***table, string **freecell, int rdest, int csrc, int  cdest)
{
    string src, dest;
    int temp1s = 0, temp1d=0;         //these temporary variables used to check the alternativity of colors and sequence of card no.
    string cardno = "A234567891JQK";               //this string is made in a special sequence which will be explained in Viva.(if required)
    string cardtype = {3,4,5,6,'\0'};              // 3=heart-red,4=diamond-red,5=club-black,6=spades-black

    src = (*(*(freecell)+csrc));
    dest = dest = (*(*(*(table)+rdest)+cdest));

    for (int i=0; cardno[i]!='\0'; i++)
    {
        if(src[0] == cardno[i])                 //getting the index of # of source-card in cardno string
            temp1s = i;
        if(dest[0] == cardno[i])                //similar to above
            temp1d = i;
    }

    if (cardno[temp1s+1] == cardno[temp1d])         //that the destination-column card and the most above source-column card are Sequential and colors are OK...
        {
            if (src[0] == '1')                          //if source card is 10 then third character that matters
            {
                if (((src[2]==3||src[2]==4)&&(dest[1]==5||dest[1]==6))||(src[2]==5||src[2]==6)&&(dest[1]==3||dest[1]==4))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else if (dest[0] == '1')                    //if target card is 10 then third character that matters
            {
                if (((src[1]==3||src[1]==4)&&(dest[2]==5||dest[2]==6))||(src[1]==5||src[1]==6)&&(dest[2]==3||dest[2]==4))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else
            {
                if (((src[1]==3||src[1]==4)&&(dest[1]==5||dest[1]==6))||(src[1]==5||src[1]==6)&&(dest[1]==3||dest[1]==4))
                {
                    return 1;
                }
                else
                    return 0;
            }
        }
        else
            return 0;
}

bool checkmove(string ***table, int rsrc, int rdest, int csrc, int cdest, int numcrd)
{
    //This function checks the sequences of source card and destination cards and their colors
    //Also checks if the multiple cards are to be moved then their sequence and colors are OK to move

    int flag = 1;               //flag used to determine certain condition is true or not later in code.
    int temp1s = 0, temp1d=0;         //these temporary variables used to check the alternativity of colors and sequence of card no.
    string src;
    string dest;
    string cardno = "A234567891JQK";               //this string is made in a special sequence which will be explained in Viva.(if required)
    string cardtype = {3,4,5,6,'\0'};              // 3=heart-red,4=diamond-red,5=club-black,6=spades-black

    src = (*(*(*(table)+rsrc)+csrc));
    dest = (*(*(*(table)+rdest)+cdest));

    if (src[0] == 'A')                             //Ace cards cannot be moved in columns so return false
        return 0;

    for (int i=0; cardno[i]!='\0'; i++)
    {
        if(src[0] == cardno[i])                 //getting the index of # of source-card in cardno string
            temp1s = i;
        if(dest[0] == cardno[i])                //similar to above
            temp1d = i;
    }
    for (int i=0; i<numcrd-1 ;i++)              //if number of cards to be moved are more than 1, then checking the sequence of cards in source-column
    {
            flag = 0;
            if ((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(0,1) == cardno.substr(temp1s+1,1))        //here it is being checked that the # of both upper card of the exposed card are consecutive i.e. if the index of lower card in cardno string is some then +1 should give the # of upper card in the cardno string
            {
                if ((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(0,1) == "1")          //condition to check that the upper card is 10, if it is then the third character that matters
                {
                    if(((src[1]==3||src[1]==4)&&((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(2,1) == cardtype.substr(2,1) || (*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(2,1) == cardtype.substr(3,1))) || ((src[1]==5||src[1]==6)&&((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(2,1) == cardtype.substr(0,1) || (*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(2,1) == cardtype.substr(1,1))) )
                    {
                        src = (*(*(*(table)+(rsrc-(i+1)))+csrc));
                        flag = 1;
                    }
                    else
                        return 0;
                }
                else if (src[0] == '1')
                {
                        if(((src[2]==3||src[2]==4)&&((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(2,1) || (*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(3,1))) || ((src[2]==5||src[2]==6)&&((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(0,1) || (*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(1,1))) )
                        {
                            src = (*(*(*(table)+(rsrc-(i+1)))+csrc));
                            flag = 1;
                        }
                        else
                            return 0;
                }
                else
                {
                    if(((src[1]==3||src[1]==4)&&((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(2,1) || (*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(3,1))) || ((src[1]==5||src[1]==6)&&((*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(0,1) || (*(*(*(table)+(rsrc-(i+1)))+csrc)).substr(1,1) == cardtype.substr(1,1))) )
                    {
                        src = (*(*(*(table)+(rsrc-(i+1)))+csrc));
                        flag = 1;
                    }
                    else
                        return 0;
                }
            }
            else
            {
                return 0;
            }
        for (int i=0; cardno[i]!='\0'; i++)
        {
            if(src[0] == cardno[i])
                temp1s = i;
            if(dest[0] == cardno[i])
                temp1d = i;
        }
    }
    if (flag == 1)                      //if multiple cards are OK to move to target column then checking
    {
        if (cardno[temp1s+1] == cardno[temp1d])         //that the destination-column card and the most above source-column card are Sequential and colors are OK...
        {
            if (src[0] == '1')                          //if source card is 10 then third character that matters
            {
                if (((src[2]==3||src[2]==4)&&(dest[1]==5||dest[1]==6))||(src[2]==5||src[2]==6)&&(dest[1]==3||dest[1]==4))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else if (dest[0] == '1')                    //if target card is 10 then third character that matters
            {
                if (((src[1]==3||src[1]==4)&&(dest[2]==5||dest[2]==6))||(src[1]==5||src[1]==6)&&(dest[2]==3||dest[2]==4))
                {
                    return 1;
                }
                else
                    return 0;
            }
            else
            {
                if (((src[1]==3||src[1]==4)&&(dest[1]==5||dest[1]==6))||(src[1]==5||src[1]==6)&&(dest[1]==3||dest[1]==4))
                {
                    return 1;
                }
                else
                    return 0;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

string mainpage(string *selection)
{
    string choice;
    cout << "Enter 1 to start a new game "<<endl;
    cout << "Enter 2 to resume a game " << endl;
    cout << "Enter -1 to exit: " << endl;
    cout << "enter your choice: ";
    cin >> choice;
    selection = &choice;
    return *selection;
}

void newgame(string **table)
{
    ofstream outfile;
    outfile.open("input.txt");

    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            outfile<< table[i][j] << " ";
            if (j==7)
                outfile << endl;
        }
    }
    outfile.close();

    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            cout<< table[i][j] << " ";
            if (j==7)
                cout << endl;
        }
    }
}

void display(string*** table, string **freecell, string ***homecell,int checksize, int checksize2)
{
    string **uprdis = new string*[checksize2];      //making dynamic array to display free cell and home cell in one line
    uprdis[0] = new string[8];
    for (int i=1; i<checksize2; i++)
        uprdis[i] = new string[4];
    for (int j=0; j<4; j++)
        uprdis[0][j] = (*(*(*(homecell)+0)+j));
    for (int i=4; i<8; i++)
        uprdis[0][i] = (*(*(freecell)+(i-4)));
    for (int i=1; i<checksize2; i++)
    {
        for (int j=0; j<4; j++)
        {
            uprdis[i][j] = (*(*(*(homecell)+i)+j));
        }
    }

    cout << left <<setw(10) << " " <<setw(10)<< " ****Home cell**** " << setw(10)<< " " << "****Free-cell****" << setw(10) << endl;
    for (int i=0;i<8;i++)
    {
        if (uprdis[0][i] != " " && uprdis[0][i] != "")
            cout << setw(3) << "|" << setw(3) <<uprdis[0][i] << setw(3) << "|";
        if (uprdis[0][i] == " ")
            cout << setw(3) << "" << setw(3) << "" << setw(3) << "";
        else if (uprdis[0][i] == "")
            cout << setw(3) << "" << setw(3) << "" << setw(3) << "";

    }
    cout << endl;
    for (int i=1; i<checksize2; i++)
        {
            for (int j=0; j<4 ; j++)
            {
            if (uprdis[i][j] != " ")
                    cout  << setw(3) << "|" <<setw(3) << uprdis[i][j] << setw(3) << "|";
            else if (uprdis[i][j] == " ")
                    cout << setw(3) << "" <<setw(3) << "" << setw(3) << "";
                    if (j==4)
                        cout << endl;
            }
    }
    cout << endl << endl;
    for (int i=0; i<checksize; i++)
    {
        for (int j=0; j<8; j++)
        {
            if ((*(*(*(table)+i)+j)) != " " && (*(*(*(table)+i)+j)) != "")
                cout<< setw(3)<< "|" << setw(3) <<(*(*(*(table)+i)+j)) << setw(3)<<"|";
            else if ((*(*(*(table)+i)+j)) == " " )
                cout << setw(3) << "" << setw(6) << "" << setw(3);
            else if ((*(*(*(table)+i)+j)) == "")
                cout << setw(3) << "" << setw(6) << "" << setw(3);
            if (j==7)
                cout << endl;
        }
    }
    for (int i=1; i<checksize2; i++)
        delete [] uprdis[i];
    delete [] uprdis[0];
    delete[] uprdis;
}

int extend(string ***table, int numcrd, int rdest ,int cdest, int checksize)
{
    int rowsize = rdest+numcrd+2;       //calculating and storing the row-size needed for new bigger table
    if (rowsize > checksize)            // checking if there is a need to expand the rows. CHECKSIZE is the size of old table
    {
        string **temp = new string*[rowsize];       //creating bigger temporary dynamic array
        for (int i=0; i<rowsize ;i++)
            temp[i] = new string[8];
        for (int i=0; i<rowsize; i++)
        {
            for (int j=0; j<8; j++)
            {
                if (i<checksize)                //check to limit the iteration to the size of old-table
                {
                    temp[i][j] = *(*(*(table)+i)+j);        //copying the elements of old table to temporary d-array
                }
                else
                {
                    temp[i][j] = " ";                       //now introducing the spaces for expanded sizes
                                                            //spaces are the indicators to check a specific column's size
                }
            }
        }
        for(int k = 0; k < checksize; k++)                  //deleting old-table elements
        {
            delete [] *(*table+k);
        }
        delete [] *table;

        *table = temp;                                      //now pointing the table to initial value of temp.
        checksize = rowsize;                                //updating new size of table
    }
    return checksize;
}

int extend2(string ***homecell, int rdest, int checksize2)
{
    int rowsize = rdest+1+2;       //calculating and storing the row-size needed for new bigger table
    if (rowsize > checksize2)            // checking if there is a need to expand the rows. CHECKSIZE is the size of old table
    {
        string **temp = new string*[rowsize];       //creating bigger temporary dynamic array
        for (int i=0; i<rowsize ;i++)
            temp[i] = new string[8];
        for (int i=0; i<rowsize; i++)
        {
            for (int j=0; j<4; j++)
            {
                if (i<checksize2)                            //check to limit the iteration to the size of old-table
                {
                    temp[i][j] = *(*(*(homecell)+i)+j);        //copying the elements of old table to temporary d-array
                }
                else
                {
                    temp[i][j] = " ";                       //now introducing the spaces for expanded sizes
                                                            //spaces are the indicators to check a specific column's size
                }
            }
        }
        for(int k = 0; k < checksize2; k++)                  //deleting old-table elements
        {
            delete [] *(*homecell+k);
        }
        delete [] *homecell;

        *homecell = temp;                                      //now pointing the table to initial value of temp.
        checksize2 = rowsize;                                //updating new size of table
    }
    return checksize2;
}

void savegame(string ***table, string **freecell, string ***homecell, int checksize, int checksize2)
{
    ofstream otable, ofreecell, ohomecell, sizetable, sizehomecell;
    otable.open("table.txt");
    ofreecell.open("freecell.txt");
    ohomecell.open("homecell.txt");
    sizetable.open("sizet.txt");
    sizehomecell.open("sizeh.txt");

    sizetable << checksize;
    sizehomecell << checksize2;

    for (int i=0; i<checksize; i++)
    {
        for (int j=0; j<8; j++)
        {
            if ((*(*(*(table)+i)+j)) == " ")
                otable << "*" << " ";
            else
                otable << (*(*(*(table)+i)+j)) << " ";
            if (j==7)
                otable << endl;
        }
    }

    for (int i=0; i<checksize2; i++)
    {
        for (int j=0; j<4; j++)
        {
            ohomecell << (*(*(*(homecell)+i)+j)) << " ";
            if (j==3)
                ohomecell << endl;
        }
    }

    for (int i=0; i<4; i++)
    {
        ofreecell << (*(*(freecell)+i)) << " ";
        if (i==3)
            ofreecell << endl;
    }

    otable.close();
    ofreecell.close();
    ohomecell.close();
    sizetable.close();
    sizehomecell.close();
}

int resume(string ***table, string **freecell, string ***homecell, int checksize, int& checksize2)
{
    ifstream itable, ifreecell, ihomecell, sizetable, sizehomecell;
    itable.open("table.txt");
    ifreecell.open("freecell.txt");
    ihomecell.open("homecell.txt");
    sizetable.open("sizet.txt");
    sizehomecell.open("sizeh.txt");

    sizetable >> checksize;
    sizehomecell >> checksize2;

    for (int i=0; i<checksize ; i++)
    {
        for (int j=0; j<8; j++)
        {
            itable >> (*(*(*(table)+i)+j));
            if ((*(*(*(table)+i)+j)) == "*")
                (*(*(*(table)+i)+j)) = " ";
        }
    }

    for (int i=0; i<checksize2; i++)
    {
        for (int j=0; j<4; j++)
        {
            ihomecell >> (*(*(*(homecell)+i)+j));
        }
    }

    for (int i=0; i<4; i++)
    {
        ifreecell >> (*(*(freecell)+i));
    }


    return checksize;

    itable.close();
    ifreecell.close();
    ihomecell.close();
    sizetable.close();
    sizehomecell.close();
}
