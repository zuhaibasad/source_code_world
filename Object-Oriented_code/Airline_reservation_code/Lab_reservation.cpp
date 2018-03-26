/////    Computer Lab Reservation System /////

/////    Contributor: Zuhaib Asad
/////    No part of this code is derived from any other source code

#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>


using namespace std;

void login(int [][8], string [][8], string [33], string [10], string [33],int, int);
void logoff(int [][8], string [][8], string [33], string [10], int, string [33], int);
void passreset(string [33], string [10], string [10], string [10]);
void seatingplan(string [][8], int);
void helpdesk(string [10], string [10], string [10]);
void trace (int [][8], string [][8], string [10], string [33], int);
void requests(string [10]);
void changepassword(string [10], string [10], string [10]);
void studentdata(string [10]);

string switchmode(int [][8], string [][8], string [10], string [10],string [33], string [10],int);
string rollnum(string [10]);
string pswrdcheck(string [10],string);



int main()
{
    // Initializing Variables //
    int seatplan[4][8] = {0};
    int sum=1;
    int pcno = 0;
    int rows = 4;
    int logflag=0;

    string detail[5][8];
    string check[33] = "*";
    string request[10] = "*";
    string choice = " " ;
    string error[10] = "Dear 19100001,Thank you for contacting IST Help desk. It is our top priority to resolve your issue in the most timely manner.";
    string sdata[10] = "*";
    string pcbook[33] = "*";
    ///////////////////////////

    studentdata(sdata); // storing the data of registered students

    for (int i=0;i<rows;i++)
    {
        for (int j =0;j<8;j++)
        {
            seatplan[i][j] = sum;    //Inserting all "*" in arrays
            sum++;
            detail[i][j] = '*';
        }
    }

    do{
    cout << endl;
    cout << endl <<"\t\t\t**** Student Mode **** "<< endl << endl;
    cout << "- Press 1 to log in to a computer" << endl;
    cout << "- Press 2 to log off from a computer" << endl;
    cout << "- Press 3 to request for password reset" << endl;
    cout << "- Press 4 to view message from Helpdesk" << endl;
    cout << "- Press 5 to view Lab seating arrangement" << endl;
    cout << "- Press 6 to switch mode" << endl;
    cout << "- Press -1 to exit" << endl << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;
        if  (choice == "1")
           login(seatplan, detail, check, sdata, pcbook,rows, logflag);
        else if (choice == "2")
            logoff(seatplan, detail, check, sdata, rows, pcbook, logflag);
        else if (choice == "3")
            passreset(pcbook, sdata, request, error);
        else if (choice == "4")
            helpdesk(request, sdata, error);
        else if (choice == "5")
            seatingplan(detail, rows);
        else if (choice == "6")
            choice = switchmode(seatplan, detail, sdata, request, pcbook, error,rows);
        else if (choice != "-1")
            cout << "Invalid Input! Type Again..." << endl;

        logflag++; // use to indicate the number of times program has run and used in login function

    }while(choice != "-1");
}

void login(int seatplan[][8], string detail[][8], string check[33], string sdata[10], string pcbook[33],int rows, int logflag)
{
    //this function logins the user and gives all necessary errors on wrong inputs

    //// Initializations

    string rolno = " ";
    string password = " ";
    int pcno=0;
    int rnum=1;
    int cnum=1;
    int flag=0;
    int stop=0;

    rolno = rollnum(sdata);

     for (int i=0; i<10; i++)
     {
         if (sdata[i].substr(14,6) == "change")
           {
            cout << "\nYou cannot login because your password request is pending!" << endl;
            return;
           }
     }

     password = pswrdcheck(sdata, rolno);
     check[logflag] = rolno+password;  //to check the user not login more than once

    for (int i=0; i<logflag;i++)
    {
        if(check[i] == check[logflag])
            stop = 1;
    }
    if (stop == 1)
    {
        cout << "\nError...! You cannot login on more than one PCs." << endl;
        check[logflag] = " ";
        return;
    }
    do{
        if ( !(rnum>=1 && rnum<=4) )
            cout << "\nThis row is not available in this Lab!" << endl;
        cout << "\nEnter row number: ";
        cin >> rnum;
    }while((!(rnum>=1 && rnum<=4)));                                //rows and columns taking from user with check of errors
    do{
        if ( !(cnum>=1 && cnum<=8) )
            cout << "\nThis column is not available in this Lab!" << endl;
        cout << "\nEnter column number: ";
        cin >> cnum;
    }while((!(cnum>=1 && cnum<=8)));

    if (detail[rnum-1][cnum-1] == "o")
        cout << "\nThis Computer is already in use!" << endl;
    else
    {
        pcno = seatplan[rnum-1][cnum-1];
        cout << "\nYou have been logged in to PC # " << pcno << endl;
        detail[rnum-1][cnum-1] = 'o';
    }
    pcbook[pcno] = rolno;

}


void studentdata(string sdata[10])
{
    //this function is the controller of the data for registered users.

    string rolno[10];
    string password[10];

    rolno[0] = "19100001"; password[0] = "abc123";
    rolno[1] = "19100002"; password[1] = "abc456";
    rolno[2] = "19100003"; password[2] = "abc789";
    rolno[3] = "19100004"; password[3] = "def123";
    rolno[4] = "19100005"; password[4] = "def456";
    rolno[5] = "19100006"; password[5] = "def789";
    rolno[6] = "19100007"; password[6] = "xyz123";
    rolno[7] = "19100008"; password[7] = "xyz456";
    rolno[8] = "19100009"; password[8] = "xyz789";
    rolno[9] = "19100010"; password[9] = "xyz123";

    for (int i=0; i<10; i++)
    {
        sdata[i] = rolno[i]+password[i];
    }
}

void logoff (int seatplan[][8], string detail[][8], string check[33], string sdata[10],int rows, string pcbook[33], int logflag)
{
    string rolno;
    int flag = 0;
    int rnum=0;
    int cnum=0;
    int pcno=0;

    rolno = rollnum(sdata);

    for (int i=1; i<33 ; i++)
    {
        if(pcbook[i] == rolno)
           {
               pcno = i;
           }
    }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<8; j++)
        {
            if(seatplan[i][j] == pcno)
            {
                rnum = i;
                cnum = j;
            }
        }
    }

    if (pcno == 0 || detail[rnum][cnum] == "*")
    {
        cout << "\nYou are not logged in any PC!" << endl;
        return;
    }


    for (int i=0; i<logflag; i++)
    {
        if(check[i].substr(0,8) == rolno)
           {
               flag = 1;
               logflag = i ;
           }
    }

    if (flag == 1)
    {
        detail[rnum][cnum] = '*';
        cout << "\nYou have been successfully signed out of PC # " << pcno << endl;
        pcbook[pcno] = "*";
        check[logflag] = "*";
    }
    else
    {
        cout << "\nYou are not logged into any PC!" << endl;
        return;
    }
}

void passreset(string pcbook[33], string sdata[10], string request[10], string error[10])
{
    string rolno;
    int flag = 0;

    rolno = rollnum(sdata);

    for (int i=0; i<10; i++)
    {

        if (request[i] == rolno)
        {
            cout << "\nYou have already pending password request!" << endl;
            return;
        }
    }

    for (int i=0; i<33; i++)
    {
        if (pcbook[i] == rolno)
        {
            cout << "\nError...! You cannot change password while logged in." << endl;
            return;
        }
    }

    for (int i=0; i<10; i++)
    {
       if( sdata[i].substr(0,8) == rolno)
            flag = i;
    }

    request[19100010-(atoi(rolno.c_str()))] = rolno;
    cout << "\nYou have requested for password change successfully. " << endl;

    sdata[flag] = sdata[flag] + "change"; //this is used in login function to check user cant login while his request is pending.

    error[0] = "Dear 19100001,Thank you for contacting IST Help desk. It is our top priority to resolve your issue in the most timely manner.";
}

void seatingplan(string detail[][8], int rows)
{
    cout << "                               Lab3" <<endl << endl;
    cout << "       ";

    for (int i=0; i<8; i++)
    {
      cout <<"  [col " << i+1 << "]";
    }

    cout << endl<<endl;

    for (int i = 0; i<rows ; i++)
    {
        cout<< "[row" << i+1 << "]  ";
        for (int j=0; j<8; j++)
        {
            cout << "    " << detail[i][j] << setw(4)<<"  ";
            if (j==7)
                cout << endl<<endl;
        }
    }
}

void helpdesk(string request[10], string sdata[10], string error[10])
{
    string rolno;
    string message = "Dear 19100001,Thank you for contacting IST Help desk. It is our top priority to resolve your issue in the most timely manner.";
    int flag=0, check = 0;

    rolno = rollnum(sdata);

    for (int i=0; i<10; i++)
    {
        if(request[i] == rolno)
        {
            check = 1;
            if (error[i] != message)
                cout << "\n[no new message!]" << endl;
            else
            {
                cout << message << endl;
                error[i] = "[no new message!]";

            }
        }
        else if (request[i] == "r")
        {
            request[i] = '*';
            cout << error[1] << endl;
            check = 2;
        }
    }

    if (check !=1 && check != 2) //this conditions gives messages to those who have not requested password change.
    {
        cout << "\n[no new message!]" << endl;
    }
}

string switchmode(int seatplan[][8], string detail[][8], string sdata[10], string request[10], string pcbook[33], string error[10],int rows)
{

    string ans;

    do{
    cout << "\n \t\t\t**** Administrator Mode ****" << endl << endl;
    cout << "- Press 1 to trace a student" << endl;
    cout << "- Press 2 to view change password requests" << endl;
    cout << "- Press 3 to change password for a student" << endl;
    cout << "- Press 4 to view seating arrangement of Lab" << endl;
    cout << "- Press 5 to switch mode" << endl;
    cout << "- Press -1 to exit" << endl;
    cout << "\nEnter your choice: ";
    cin >> ans;

    if (ans == "1")
        trace (seatplan, detail, sdata, pcbook, rows);
    else if (ans == "2")
        requests(request);
    else if (ans == "3")
        changepassword(request, sdata, error);
    else if (ans == "4")
        seatingplan(detail, rows);
    else if (ans == "5")
        return 0;
    else if (ans == "-1")
        return "-1";
    else if (ans != "-1")
        cout << "\nInvalid Input!" << endl;

    }while(ans!="-1");
}

void trace (int seatplan[][8], string detail[][8], string sdata[10], string pcbook[33], int rows)
{
    string rolno;


    int flag=0, pcno = 0;
    int rnum = 0, cnum = 0;

    rolno = rollnum(sdata);

    for (int i=1; i<33; i++)
    {
        if(pcbook[i] == rolno)
           {
             pcno = i;
           }
    }

    if (pcno == 0)
    {
        cout << "The provided roll no. is not logged into any PC!" << endl << endl;
        return;
    }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (seatplan[i][j] == pcno)
            {
                rnum = i;
                cnum = j;
            }
        }
    }

    cout << "\nStudent, " << rolno << " is currently logged in PC # " << pcno << " in row " << rnum+1 << " and column " << cnum+1 << endl;

}

void requests(string request[10])
{
    cout << "\nFollowing Students have requested for Password Change" << endl;
    for (int i=0; i<10; i++)
        {
            if (request[i] != "*")
                cout << request[i] << endl;
        }
}

void changepassword (string request[10], string sdata[10], string error[10])
{
    string rolno;
    string password = "*";
    string message = "";
    int flag=0;
    int check = 0;
    int temp = 0;

    rolno = rollnum(sdata);

    for (int i=0; i<10; i++)
    {
        if( request[i] == rolno )
        {
            cout << "\nEnter new password for " << rolno << ": ";
            cin >> password;
        }
    }

    do {
            check = 0;
        for (int i=0; i<10; i++)
        {
            if ( sdata[i] == rolno+password )
            {
                check = 1;
                cout << "\nYou entered the old password! Please enter the new one!" << endl;
            }
            if (request[i] == rolno)
                check = 2;

            if (sdata[i].substr(0,8) == rolno)
                temp = i;
        }

        if (check == 1)
        {
            cout << "\nEnter password Again: ";
            cin >> password;
        }
    }while(check==1);

        if ( check == 2 )
        {
            sdata[temp] = sdata[temp].substr(0,8);
            sdata[temp] = sdata[temp] + password;
            message = "Your password has been reset. Your new password is: ";
            message = message + password;
            cout << "\nPassword has been changed successfully." << endl;
            for (int i=0; i<10; i++)
            {
                if (request[i] == rolno)
                    request[i] = 'r';   //this is used to generate password reset messages to those whom password has been reset.
            }
            error[1] = message;
        }

}

string rollnum(string sdata[10])
{
    int flag=0;
    string rolno = " ";

    do{
        cout << "\nEnter your roll no.: ";
        cin >> rolno;

        for (int i=0; i<10; i++)
        {
            if(sdata[i].substr(0,8)==rolno)
                flag = 1;
        }
        if (flag!=1)
            cout << "\nYour roll no. is wrong! Type Again..." << endl;
    }while(flag!=1);
    return rolno;
}

string pswrdcheck(string sdata[10], string rolno)
{
    int flag=0;
    string password = " ";

    do{
        cout << "\nEnter your password.: ";
        cin >> password;

        for (int i=0; i<10; i++)
        {
            if(sdata[i]==rolno+password)
                flag = 1;
        }
        if (flag!=1)
        {
            string ans = " ";
            cout << "\nIncorrect password!" << endl;
            cout << "\nEnter any key to Type Again OR -1 to exit current function.";
            cin >> ans;
            if (ans == "-1")
                return 0;
        }
    }while(flag!=1);
    return password;
}
