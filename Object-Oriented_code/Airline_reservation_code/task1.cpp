////// TASK_1   TASK_1  TASK_1  TASK_1  TASK_1  TASK_1  TASK_1  TASK_1  TASK_1  TASK_1  TASK_1 //////

////// Name : Zuhaib Asad
////// Roll No. : 191000201
////// DISCLAIMER: No part of this code is derived from any other source code. And this code has copyrights reserved



#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

void reserve(string[][4],string[][4],int,int,int,string);
void changeseat(string[][4],string[][4],int, int, int);
void seatreserve(string[][4],string[][4],string,string,string);
void seatreserveconditional(string[][4],string[][4],string,string,string);
void seatingplan(string [][4], int, int, int, string);
void cancelseat(string [][4], string [][4], int , int, int);
void help(string [][4], string [][4]);

string seatinput();
string classinput ();

int main()
{
    //Variables initializations//
     int flag = 0;
     int rows=10;  // total number of rows
     int brows=3; // total business rows
     int economyrows = 7; // total economic rows
     int erows= rows - economyrows; // starting of economic rows
     int colm=4; // total number of columns

     string choice = " ";
     string seatplan[11][4];
     string detail[11][4];
    /////////////////////////////

     for (int i=0; i < 11; i++)
     {
         for (int j=0; j < colm; j++)
         {
             seatplan[i][j] = '*';
             detail[i][j] = '*';
         }
     }

     do{
        cout << endl;
        cout<<"**** Welcome to Reservation System ****"<<endl;
        cout<<"\n\n-Press 1 to reserve a seat"<<endl;
        cout<<"-Press 2 to cancel your seat"<<endl;
        cout<<"-Press 3 to change your seat"<<endl;
        cout<<"-Press 4 to View Seating Plan"<<endl;
        cout<<"-Press 5 to Seek Help"<<endl;
        cout<<"-Press -1 to exit"<<endl<<endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        if (choice == "1")
            reserve(seatplan,detail,rows,brows,erows,choice);
        else if (choice == "2")
            cancelseat(seatplan,detail,rows,3,3);
        else if (choice == "3")
            changeseat(seatplan, detail, rows, 3, 3);
        else if (choice == "4")
        {
            seatingplan(seatplan, rows, 3, 3, "b");
            seatingplan(seatplan, rows, 3, 3, "e");
        }
        else if (choice == "5")
            help(seatplan,detail);
        else if (choice != "-1")
            cout << "\nYour typed wrong value of choice! Enter Again" << endl;

        flag = 1;
     }while (choice != "-1");
}


void reserve(string seatplan[][4],string detail[][4],int rows, int brows,int erows,string choice)
{
    string clas, rolno, name;

    clas = classinput();

    cout << "\nEnter your name: ";
    getline(cin,name);
    getline(cin,name);
    cout <<"\nEnter Your roll no.: ";
    getline(cin,rolno);
    cout << endl;


    if (clas == "b" || clas == "B")
    {
        seatingplan(seatplan, rows, brows, erows, clas);
        seatreserve(seatplan, detail, name, rolno,clas);
        seatingplan(seatplan, rows, brows, erows, clas);
    }
    else if (clas == "e" || "E")
    {   seatingplan(seatplan, rows, brows, erows, clas);
        seatreserve(seatplan, detail, name, rolno, clas);
        seatingplan(seatplan, rows, brows, erows, clas);
    }
}

void changeseat(string seatplan[][4],string detail[][4] ,int rows, int brows, int erows)
{
    string name,rolno,seat,ans;
    string rnum;
    int cnum;
    int flag = 0;

    do{
        cout << "\nEnter your name: ";
        getline(cin,name);
        getline(cin,name);
        cout << "\nEnter your roll no.: ";
        getline(cin,rolno);

        for (int i=0; i<10; i++)
        {
            for (int j=0; j<4; j++)
            {
                if (detail[i][j] == name+rolno)
                    flag=1;
            }
        }

        if (flag == 0)
        {
            cout << "\nThese details do not have any reservation!" << endl;
            cout << "Enter 1: If you want to re-enter your details again?" << endl;
            cout << "Enter 2: If you want to Reserve a seat against your details?" << endl;
            cout << "Enter -1 if you want to exit current function: ";
            cin >> ans;
        do
        {
            if (ans == "1")
            {
                changeseat(seatplan, detail, rows, brows, erows);
                return;
            }
            else if (ans == "2")
            {
                string choice;
                choice = classinput();
                seatingplan(seatplan,rows,brows,erows,choice);
                seatreserve(seatplan,detail,name,rolno,choice);
                seatingplan(seatplan,rows,brows,erows,choice);
                return;
            }
            else if (ans == "-1")
            {
                return;
            }
            else
            {
                cout << "\nInvalid choice!" << endl;
                cout << "Enter choice again: ";
                cin >> ans;
            }
        }while(ans != "-1" && ans != "1" && ans != "2" );
        }

        if ( !(ans == "2") )
        {
            seat = seatinput();

            if ( (seat >= "B10.1" && seat <= "B10.4") || (seat >= "b10.1" && seat <= "b10.4") )
            {
                rnum = seat.substr(1,2).c_str();
                cnum = atoi(seat.substr(4).c_str());
            }
            else
            {
                rnum =  seat.substr(1,1).c_str();
                cnum = atoi(seat.substr(3).c_str());
            }
            string choice = seat.substr(0,1).c_str();

            if (choice == "A" || choice == "a")
                choice = "B";
            else if (choice == "B" || choice == "b")
                choice = "E";

            if (detail[atoi(rnum.c_str())-1][cnum-1] == name+rolno)
            {
                seatingplan(seatplan, rows, brows, erows, choice);
                seatplan[atoi(rnum.c_str())-1][cnum-1] = '*';
                seatreserveconditional(seatplan, detail, name, rolno, choice);
                seatingplan(seatplan, rows, brows, erows, choice);
            }
            else if (detail[atoi(rnum.c_str())-1][cnum-1] == "*")
            {
                cout << "\nSeat is already Vacant! " << endl;
                cout << "Want to reserve a seat against this seat number? Enter Y: " << endl;
                cout << "Or enter any key to exit current function: ";
                cin >> ans;

                if(ans == "Y" || ans == "y")
                {
                    seatingplan(seatplan, rows, brows, erows, choice);
                    seatreserve(seatplan, detail, name, rolno, choice);
                    seatingplan(seatplan, rows, brows, erows, choice);
                }
                else
                    return;
            }
            else
            {
                string ans = "0";
                cout << "\nThis seat is not reserved against your details! " << endl;
                cout << "Enter -1 to exit OR any key to re-enter your details: ";
                cin >> ans;
                if (ans == "-1")
                    return;
                else
                    cout << "\nEnter your details again!" << endl;
            }
        }
    }while( (detail[atoi(rnum.c_str())-1][cnum-1] != name+rolno) && (detail[atoi(rnum.c_str())-1][cnum-1] != "*") );
}


void seatreserve(string seatplan[][4],string detail [][4] ,string name, string rolno,string choice)
{
    int cnum = 1;
    string rnum;

    if (choice == "b" || choice == "B")
    {
        rnum = "A1";
            do{
                if ( (rnum[0]!='A' && rnum[0] != 'a') || (!(rnum[1]> '0' && rnum[1]<='3')) || (rnum[2] != '\0') )
                    cout << "\nThis row is not available in current Plan!" << endl;
                cout << "\nEnter row number: ";
                cin >> rnum;
            }while( (rnum[0]!='A' && rnum[0]!='a') || (!(rnum[1]>'0' && rnum[1]<= '3')) || (rnum[2] != '\0'));

            do{
                if (!(cnum>0 && cnum<5))
                    cout << "\nThis column is not available in current Plan!" << endl;
                cout << "\nEnter column number: ";
                cin >> cnum;
            }while(!(cnum>0 && cnum<5));

            if (seatplan[(atoi(rnum.substr(1).c_str()))-1][cnum-1] == "o")
                cout << "\nSeat already occupied!" << endl;
    }

    else if (choice == "e" || choice == "E")

    {
        rnum = "B10";
            do{
                  if (!(rnum>="B4" || rnum<="B10") && !(rnum>="b4" || rnum<="b10"))
                    cout << "\nThis row is not available in current Plan!" << endl;
                cout << "\nEnter row number: ";
                cin >> rnum;
              }while(!(rnum>="B4" || rnum<="B10") && !(rnum>="b4" || rnum<="b10"));
            do{
                if (!(cnum>0 && cnum<5))
                    cout << "\nThis column is not available in current Plan!" << endl;
                cout << "\nEnter column number: ";
                cin >> cnum;
            }while(!(cnum>0 && cnum<5));

            if (seatplan[(atoi(rnum.substr(1).c_str()))-1][cnum-1] == "o")
                cout << "\nSeat already occupied!" << endl;
    }

    seatplan[(atoi(rnum.substr(1).c_str()))-1][cnum-1] = "o";
    cout << "\nDear " << name << ", the seat " << rnum << "." << cnum << " has been reserved for you!" << endl;
    detail[(atoi(rnum.substr(1).c_str()))-1][cnum-1] = name+rolno;
}

void seatingplan(string seatplan[][4], int rows, int brows, int erows, string choice)
{
    if (choice == "b" || choice == "B")
    {
        cout << endl;
        cout << left << setw(20) << "\n***Business Class current seating plan***\n" << setw(20) <<endl;

    for (int j=0;j<4;j++)
      cout << left << setw(10) <<"          " << "Column[" << j+1 << "] ";

    cout << endl;

    for (int i = 0; i<brows ; i++)
    {
        cout<< "A[" << i+1 << "]      ";
        for (int j=0; j<4; j++)
        {
            cout << left << setw(10)<< seatplan[i][j] << setw(10)<<"          ";
            if (j==3)
                cout << endl;
        }
    }
   cout << left << setw(10) << "\t\t* Available" << "\t\t" << " o Occupied" << setw(10) <<endl;
    }
    else if (choice == "e" || choice == "E")
    {
        cout << endl;
        cout << left << setw(20) <<"***Economy Class current seating plan***\n" << endl;

    for (int j=0;j<4;j++)
        cout << left << setw(10) <<"          " << "Column[" << j+1 << "] ";

    cout << endl;

    for (int i=erows; i<rows ; i++)
    {
        cout<< "B[" << i+1 << "]        ";
        for (int j=0; j<4; j++)
        {
            cout << left << setw(10)<< seatplan[i][j] << setw(10)<<"          ";
            if (j==3)
                cout << endl;
        }
    }
   cout << left << setw(10) << "\t\t* Available" << "\t\t" << " o Occupied" << setw(10) <<endl;
    }
}

void cancelseat(string seatplan[][4], string detail[][4], int rows, int brows, int erows)
{
    string name,rolno,seat,rnum;

    int flag=0,cnum=0,nrow=0,ncol=0;

    cout << "\nEnter your name: ";
    getline(cin,name);
    getline(cin,name);
    cout << "\nEnter your roll no.: ";
    getline(cin,rolno);

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<4; j++)
        {
            if( (detail[i][j] == name+rolno))
            {
                nrow = i;
                ncol = j;
                flag=1;
            }
        }
    }

    if (flag==0)
    {
        cout << "\nYour details do not have any reservations!" << endl;
        return;
    }

    seat = seatinput();

    if ( (seat >= "B10.1" && seat <= "B10.4") || (seat >= "b10.1" && seat <= "b10.4") )
        {
            rnum = seat.substr(1,2).c_str();
            cnum = atoi(seat.substr(4).c_str());
        }
    else
        {
            rnum =  seat.substr(1,1).c_str();
            cnum = atoi(seat.substr(3).c_str());
        }

    string choice = seat.substr(0,1).c_str();

    if (choice == "A" || choice == "a")
        choice = "B";
    else if (choice == "B" || choice == "b")
        choice = "E";

    if (seatplan[atoi(rnum.c_str())-1][cnum-1] == "*")
        cout << "\nSeat is not reserved already!" << endl;
    else if (seatplan[atoi(rnum.c_str())-1][cnum-1] == "o")
    {
        if ( (nrow != (atoi(rnum.c_str())-1)) && (ncol != (cnum-1)) )
            cout << "\nThis seat is not reserved by you!" << endl;
        else
        {
            seatplan[atoi(rnum.c_str())-1][cnum-1] = '*';
            detail[atoi(rnum.c_str())-1][cnum-1] = '*';
            cout << endl << "\nDear " << name << ", your seat " << seat << " has been canceled!" << endl << endl;
        }
    }
}

void help(string seatplan[][4], string detail[][4])
{

    int cnum,rnum,flag=0;
    string choice,name,rolno;

    cout << "\nEnter your name: ";
    getline(cin,name);
    getline(cin,name);
    cout << "\nEnter your roll no.: ";
    getline(cin,rolno);

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<4; j++)
        {
            if( (detail[i][j] == name+rolno))
            {
                flag=1;
                rnum = i;
                cnum = j;
            }
        }
    }

    rnum++;
    cnum++;

    if (flag == 0)
    {
        cout << "\nThere is no reservations against your details!" << endl;
        return;
    }

    if (rnum>=1&&rnum<=3)
        choice = "A";
    else if (rnum>=4&&rnum<=10)
        choice = "B";

    cout << endl <<"\nDear " << name << ", you have reserved seat " << choice << rnum << "." << cnum << endl << endl;
}

void seatreserveconditional(string seatplan[][4],string detail [][4] ,string name, string rolno,string choice)
{
    int cnum = 1;
    string rnum;

    if (choice == "b" || choice == "B")
    {
        rnum = "A1";
            do{
                if ( ((rnum[0]=='B'|| rnum[0]=='b') && (rnum[1]>='4'&& rnum[1]<='9') && (rnum[2]=='\0')) || (rnum=="B10") || (rnum=="b10"))
                    rnum="check";
                if ( !(rnum>="A1" && rnum<="A3") && !(rnum>="a1" && rnum<="a3") )
                {
                    if (rnum=="check")
                        cout << "\nYou cannot change seat from business to economy plan!" << endl;
                    else
                       cout << "\nThis row is not available in current plan!" << endl;
                }

                cout << "\nEnter row number: ";
                cin >> rnum;
            }while(!(rnum>="A1" && rnum<="A3") && !(rnum>="a1" && rnum<="a3"));

            do{
                if (!(cnum>0 && cnum<5))
                    cout << "\nThis column is not available in current Plan!" << endl;
                cout << "\nEnter column number: ";
                cin >> cnum;
            }while(!(cnum>0 && cnum<5));

            if (seatplan[(atoi(rnum.substr(1).c_str()))-1][cnum-1] == "o")
                cout << "\nSeat already occupied!" << endl;
    }

    else if (choice == "e" || choice == "E")
    {
        rnum = "B10";
            do{
                  if ((!(rnum>="A1" && rnum<="A3") && !(rnum>="a1" && rnum<="a3")) && !(((rnum[0]=='B'|| rnum[0]=='b') && (rnum[1]>='4'&& rnum[1]<='9') && (rnum[2]=='\0')) || (rnum=="B10") || (rnum=="b10")))
                    cout << "\nThis row is not available in current Plan!" << endl;
                cout << "\nEnter row number: ";
                cin >> rnum;
            }while(!(rnum>="A1" && rnum<="A3") && !(rnum>="a1" && rnum<="a3") && !(((rnum[0]=='B'|| rnum[0]=='b') && (rnum[1]>='4'&& rnum[1]<='9') && (rnum[2]=='\0')) || (rnum=="B10") || (rnum=="b10")));
            do{
                if (!(cnum>0 && cnum<5))
                    cout << "\nThis column is not available in current Plan!" << endl;
                cout << "\nEnter column number: ";
                cin >> cnum;
            }while(!(cnum>0 && cnum<5));

            if (seatplan[(atoi(rnum.substr(1).c_str()))-1][cnum-1] == "o")
                cout << "\nSeat already occupied!" << endl;
    }

    seatplan[(atoi(rnum.substr(1).c_str()))-1][cnum-1] = "o";
    cout << "\nDear " << name << ", the seat " << rnum << "." << cnum << " has been reserved for you!" << endl;
    detail[(atoi(rnum.substr(1).c_str()))-1][cnum-1] = name+rolno;
    cout << detail[(atoi(rnum.substr(1).c_str()))-1][cnum-1] << endl;
}

string seatinput()
{
    string seat;

     do{
        cout << "\nEnter seat number: ";
        cin >> seat;

        if ( !( seat >= "A1.1" || seat <="B10.4" ) && !( seat >= "a1.1" || seat <="b10.4" ) )
        {
            cout << "\nInvalid Seat Number!" << endl;
            cout << "\nEnter correct one: ";
            cin >> seat;
        }
    }while( !( seat >= "A1.1" || seat <="B10.4" ) && !( seat >= "a1.1" || seat <="b10.4" ) );

    return seat;
}

string classinput ()
{
    string clas = "B";

     do{
        if (clas != "B" && clas != "b" && clas != "E" && clas != "e")
            cout << "\nInvalid class Input! Type correct one..." << endl;
        cout << "\nEnter B for business class and E for Economy Class: ";
        cin >> clas;
    }while(clas != "B" && clas != "b" && clas != "E" && clas != "e");

    return clas;
}
