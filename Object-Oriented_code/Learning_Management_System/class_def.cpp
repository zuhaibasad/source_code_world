#include "class_header.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User()
{
    fname = " ";
    lname = " ";
    password = " ";
    username = " ";
}

User::User(string tfname, string tlname, string tpassword, string tusername)
{
    fname = tfname;
    lname = tlname;
    password = tpassword;
    username = tusername;
}

Student::Student()
{
    status = " ";
    rollno = " ";
}

Student::Student(string trollno, string tstatus, string tfname, string tlname, string tpassword, string tusername) : User(tfname, tlname, tpassword, tusername)
{
    status = tstatus;
    rollno = trollno;
}

int Student::viewrsrc()
{
    course c;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    int c5 = 0;
    int choice = 0;
    cout << "You are enrolled in following courses: " << endl;

    do{
        if (fname == c.crs1(fname))
        {
            c1=1;
            cout << "Enter " << c1 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs2(fname))
        {
            c2=2;
            cout << "Enter " << c2 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs3(fname))
        {
            c3=3;
            cout << "Enter " << c3 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs4(fname))
        {
            c4=4;
            cout << "Enter " << c4 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs5(fname))
        {
            c5=5;
            cout << "Enter " << c5 << " to see Course " << c.getcname() << " details: " << endl;
        }
        cout << "Enter -1 to logout! " << endl;
        cin >> choice;
        if (!(choice == c1 || choice == c2 || choice == c3 || choice == c4 || choice == c5 || choice == -1) || choice == 0)
        {
            cout << "Please enter the correct Input Value !!! " << endl;
        }
    }while (!(choice == c1 || choice == c2 || choice == c3 || choice == c4 || choice == c5  || choice == -1) || choice == 0);
    return choice;
}

bool Student::outline(int choice)
{
    course c;
    do{
        if (choice == 1)
        {
            int choice1 = 0;
            int choiceres = 0;
            do{
                do{
                    cout << endl << c.crs1(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to see resources: " << endl;
                    cout << "Enter 2 to view marks: " << endl;
                    cout << "Enter 3 to view Due assignments: " <<endl;
                    cout << "Enter 4 to view rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        ifstream temp;
                        string readres;
                        temp.open("Course1Resources.txt");
                        cout << "Resources  **********************" << endl;
                        while(temp >> readres)
                            cout << readres << endl;
                        temp.close();
                        cout << "Enter -1 to go up: ";
                        cin >> choiceres;
                        if (choiceres != -1)
                            cout << "Error!!! Please enter the correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        ifstream readmarks;
                        string temproll, tempmarks, tempelement;
                        readmarks.open("Course1Marks.txt");
                        while(readmarks >> temproll >> tempelement >> tempmarks)
                        {
                            if (username == temproll)
                            {
                                cout << "INTRODUCTION_TO_PROGRAMMING GRADEBOOK" << endl << endl;
                                cout << tempelement << "\t : " << tempmarks << endl << endl;
                            }
                        }
                        readmarks.close();
                    }
                    else if (choice1 == 3)
                    {
                        ifstream readassi;
                        string tempassi, tempdate;
                        readassi.open("Course1Assignment.txt");
                        cout << "ASSIGNMENTS NUMBER: \t    DUE DATE: " << endl << endl;
                        while(readassi >> tempassi >> tempdate)
                        {
                            cout << tempassi << "\t : " << tempdate << endl;
                        }
                        readassi.close();
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course1.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"INTRODUCTION_TO_PROGRAMMING COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                    {
                        choice = viewrsrc();
                    }
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
                }while(choiceres != -1);
            }while(choice1 != -1);
        }
        else if (choice == 2)
        {
            int choice1 = 0;
            int choiceres = 0;
            do{
                do{
                    cout << endl << c.crs2(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to see resources: " << endl;
                    cout << "Enter 2 to view marks: " << endl;
                    cout << "Enter 3 to view Due assignments: " <<endl;
                    cout << "Enter 4 to view rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        ifstream temp;
                        string readres;
                        temp.open("Course2Resources.txt");
                        cout << "Resources  **********************" << endl;
                        while(temp >> readres)
                            cout << readres << endl;
                        temp.close();
                        cout << "Enter -1 to go up: ";
                        cin >> choiceres;
                        if (choiceres != -1)
                            cout << "Error!!! Please enter the correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        ifstream readmarks;
                        string temproll, tempmarks, tempelement;
                        readmarks.open("Course2Marks.txt");
                        while(readmarks >> temproll >> tempelement >> tempmarks)
                        {
                            if (username == temproll)
                            {
                                cout << "BASIC_ELECTRONICS GRADEBOOK" << endl << endl;
                                cout << tempelement << "\t : " << tempmarks << endl << endl;
                            }
                        }
                        readmarks.close();
                    }
                    else if (choice1 == 3)
                    {
                        ifstream readassi;
                        string tempassi, tempdate;
                        readassi.open("Course2Assignment.txt");
                        cout << "ASSIGNMENTS NUMBER: \t    DUE DATE: " << endl << endl;
                        while(readassi >> tempassi >> tempdate)
                        {
                            cout << tempassi << "\t : " << tempdate << endl;
                        }
                        readassi.close();
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course2.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"BASIC_ELECTRONICS COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                    {
                        choice = viewrsrc();
                    }
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
                }while(choiceres != -1);
            }while(choice1 != -1);
        }
        else if (choice == 3)
        {
            int choice1 = 0;
            int choiceres = 0;
            do{
                do{
                    cout << endl << c.crs3(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to see resources: " << endl;
                    cout << "Enter 2 to view marks: " << endl;
                    cout << "Enter 3 to view Due assignments: " <<endl;
                    cout << "Enter 4 to view rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        ifstream temp;
                        string readres;
                        temp.open("Course3Resources.txt");
                        cout << "Resources  **********************" << endl;
                        while(temp >> readres)
                            cout << readres << endl;
                        temp.close();
                        cout << "Enter -1 to go up: ";
                        cin >> choiceres;
                        if (choiceres != -1)
                            cout << "Error!!! Please enter the correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        ifstream readmarks;
                        string temproll, tempmarks, tempelement;
                        readmarks.open("Course3Marks.txt");
                        while(readmarks >> temproll >> tempelement >> tempmarks)
                        {
                            if (username == temproll)
                            {
                                cout << "INTRODUCTION_TO_BIOLOGY GRADEBOOK" << endl << endl;
                                cout << tempelement << "\t : " << tempmarks << endl << endl;
                            }
                        }
                        readmarks.close();
                    }
                    else if (choice1 == 3)
                    {
                        ifstream readassi;
                        string tempassi, tempdate;
                        readassi.open("Course3Assignment.txt");
                        cout << "ASSIGNMENTS NUMBER: \t    DUE DATE: " << endl << endl;
                        while(readassi >> tempassi >> tempdate)
                        {
                            cout << tempassi << "\t : " << tempdate << endl;
                        }
                        readassi.close();
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course3.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"INTRODUCTION_TO_BIOLOGY COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                    {
                        choice = viewrsrc();
                    }
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
                }while(choiceres != -1);
            }while(choice1 != -1);
        }
        else if (choice == 4)
        {
            int choice1 = 0;
            int choiceres = 0;
            do{
                do{
                    cout << endl << c.crs4(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to see resources: " << endl;
                    cout << "Enter 2 to view marks: " << endl;
                    cout << "Enter 3 to view Due assignments: " <<endl;
                    cout << "Enter 4 to view rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        ifstream temp;
                        string readres;
                        temp.open("Course4Resources.txt");
                        cout << "Resources  **********************" << endl;
                        while(temp >> readres)
                            cout << readres << endl;
                        temp.close();
                        cout << "Enter -1 to go up: ";
                        cin >> choiceres;
                        if (choiceres != -1)
                            cout << "Error!!! Please enter the correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        ifstream readmarks;
                        string temproll, tempmarks, tempelement;
                        readmarks.open("Course4Marks.txt");
                        while(readmarks >> temproll >> tempelement >> tempmarks)
                        {
                            if (username == temproll)
                            {
                                cout << "DISCRETE_MATHEMATICS GRADEBOOK" << endl << endl;
                                cout << tempelement << "\t : " << tempmarks << endl << endl;
                            }
                        }
                        readmarks.close();
                    }
                    else if (choice1 == 3)
                    {
                        ifstream readassi;
                        string tempassi, tempdate;
                        readassi.open("Course4Assignment.txt");
                        cout << "ASSIGNMENTS NUMBER: \t    DUE DATE: " << endl << endl;
                        while(readassi >> tempassi >> tempdate)
                        {
                            cout << tempassi << "\t : " << tempdate << endl;
                        }
                        readassi.close();
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course4.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"DISCRETE_MATHEMATICS COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                    {
                        choice = viewrsrc();
                    }
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
                }while(choiceres != -1);
            }while(choice1 != -1);
        }
        else if (choice == 5)
        {
            int choice1 = 0;
            int choiceres = 0;
            do{
                do{
                    cout << endl << c.crs5(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to see resources: " << endl;
                    cout << "Enter 2 to view marks: " << endl;
                    cout << "Enter 3 to view Due assignments: " <<endl;
                    cout << "Enter 4 to view rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        ifstream temp;
                        string readres;
                        temp.open("Course5Resources.txt");
                        cout << "Resources  **********************" << endl;
                        while(temp >> readres)
                            cout << readres << endl;
                        temp.close();
                        cout << "Enter -1 to go up: ";
                        cin >> choiceres;
                        if (choiceres != -1)
                            cout << "Error!!! Please enter the correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        ifstream readmarks;
                        string temproll, tempmarks, tempelement;
                        readmarks.open("Course5Marks.txt");
                        while(readmarks >> temproll >> tempelement >> tempmarks)
                        {
                            if (username == temproll)
                            {
                                cout << "ASSEMBLY_LANGUAGE GRADEBOOK" << endl << endl;
                                cout << tempelement << "\t : " << tempmarks << endl << endl;
                            }
                        }
                        readmarks.close();
                    }
                    else if (choice1 == 3)
                    {
                        ifstream readassi;
                        string tempassi, tempdate;
                        readassi.open("Course5Assignment.txt");
                        cout << "ASSIGNMENTS NUMBER: \t    DUE DATE: " << endl << endl;
                        while(readassi >> tempassi >> tempdate)
                        {
                            cout << tempassi << "\t : " << tempdate << endl;
                        }
                        readassi.close();
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course5.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"ASSEMBLY_LANGUAGE COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                    {
                        choice = viewrsrc();
                    }
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
                }while(choiceres != -1);
            }while(choice1 != -1);
        }
        else if (choice == -1)
        {
            return 0;
        }
    }while(choice != -1);
}

Instructor::Instructor()
{
    desi = " ";
    status = " ";
}
Instructor::Instructor(string tdesi, string tstatus, string tfname, string tlname, string tpassword, string tusername) : User(tfname, tlname, tpassword, tusername)
{
    desi = tdesi;
    status = tstatus;
}
int Instructor::viewrsrc()
{
    course c;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;
    int c5 = 0;
    int choice = 0;
    cout << "You are teaching following courses: " << endl;

    do{
        if (fname == c.crs1(fname))
        {
            c1=1;
            cout << "Enter " << c1 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs2(fname))
        {
            c2=2;
            cout << "Enter " << c2 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs3(fname))
        {
            c3=3;
            cout << "Enter " << c3 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs4(fname))
        {
            c4=4;
            cout << "Enter " << c4 << " to see Course " << c.getcname() << " details: " << endl;
        }
        if (fname == c.crs5(fname))
        {
            c5=5;
            cout << "Enter " << c5 << " to see Course " << c.getcname() << " details: " << endl;
        }
        cout << "Enter -1 to logout: ";
        cin >> choice;
        if (!(choice == c1 || choice == c2 || choice == c3 || choice == c4 || choice == c5 || choice ==-1) || choice == 0)
        {
            cout << "Please enter the correct Input Value !!! " << endl;
        }
    }while (!(choice == c1 || choice == c2 || choice == c3 || choice == c4 || choice == c5 || choice == -1) || choice == 0);
    return choice;
}
bool Instructor::outline(int choice)
{
    course c;
    do{
        if (choice == 1)
        {
            int choice1;
            int choiceres = 0;
            do{
                    cout << endl << c.crs1(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to edit resources: " << endl;
                    cout << "Enter 2 to edit marks: " << endl;
                    cout << "Enter 3 to edit Due assignments: " <<endl;
                    cout << "Enter 4 to edit rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        string tempres;
                        ifstream temp;
                        ofstream writeres;
                        cout << "Resources  **********************" << endl;
                        cout << endl <<"You want to add or view resources: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeres.open("Course1Resources.txt",ios_base::app);
                            cout << "Enter the resources: ";
                            cin >> tempres;
                            writeres << tempres << endl;
                            writeres.close();
                        }
                        else if (choiceres == 2)
                        {
                            temp.open("Course1Resources.txt");
                            while (temp >> tempres)
                                cout << tempres << endl;
                            temp.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        string temproll, tempelement,tempmarks;
                        ofstream writemarks;
                        ifstream readmarks;
                        cout << "Marks  **********************" << endl;
                        cout << endl <<"You want to add or view marks: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writemarks.open("Course1Marks.txt",ios_base::app);
                            cout << "Enter the Roll Number of the student: ";
                            cin >> temproll;
                            cout << "For which element (i.e. quiz, project etc) you want to enter the marks: ";
                            cin >> tempelement;
                            cout << "Enter the Marks of the student: ";
                            cin >> tempmarks;
                            writemarks << temproll << " " << tempelement << " " << tempmarks <<endl;
                            writemarks.close();
                        }
                        else if (choiceres == 2)
                        {
                            readmarks.open("Course1Marks.txt");
                            cout << "INTRODUCTION_TO_PROGRAMMING GRADEBOOK  *******************" << endl << endl;
                            cout << "Roll Numbers: " << " " << " Element : "<< " " << " Marks: " << endl;
                            while (readmarks >> temproll >> tempelement >> tempmarks)
                                cout << temproll << "\t" << tempelement << "\t" <<tempmarks << endl;
                            readmarks.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 3)
                    {
                        ofstream writeassi;
                        ifstream readassi;
                        string tempassi;
                        string tempdate;
                        cout << "Assignments  **********************" << endl;
                        cout << endl <<"You want to add or view Assignment: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeassi.open("Course1Assignment.txt",ios_base::app);
                            cout << "Enter the Assignment: ";
                            cin >> tempassi;
                            cout << "Enter the Due Date: ";
                            cin >> tempdate;
                            writeassi << tempassi << " " << tempdate << endl;
                            writeassi.close();
                        }
                        else if (choiceres == 2)
                        {
                            readassi.open("Course1Assignment.txt");
                            cout << "Name: " << " " << " Due Date: " << endl;
                            while (readassi >> tempassi >> tempdate)
                                cout << tempassi << " "<< tempdate <<endl;
                            readassi.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course1.txt");
                        temproos >> a >> b >> c >> d;
                        cout<<"INTRODUCTION_TO_PROGRAMMING COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                        choice = viewrsrc();
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
            }while(choice1 != -1);
        }
        else if (choice == 2)
        {
            int choice1;
            int choiceres = 0;
            do{
                    cout << endl << c.crs2(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to edit resources: " << endl;
                    cout << "Enter 2 to edit marks: " << endl;
                    cout << "Enter 3 to edit Due assignments: " <<endl;
                    cout << "Enter 4 to edit rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        string tempres;
                        ifstream temp;
                        ofstream writeres;
                        cout << "Resources  **********************" << endl;
                        cout << endl <<"You want to add or view resources: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeres.open("Course2Resources.txt",ios_base::app);
                            cout << "Enter the resources: ";
                            cin >> tempres;
                            writeres << tempres << endl;
                            writeres.close();
                        }
                        else if (choiceres == 2)
                        {
                            temp.open("Course2Resources.txt");
                            while (temp >> tempres)
                                cout << tempres << endl;
                            temp.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        string temproll, tempelement,tempmarks;
                        ofstream writemarks;
                        ifstream readmarks;
                        cout << "Marks  **********************" << endl;
                        cout << endl <<"You want to add or view marks: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writemarks.open("Course2Marks.txt",ios_base::app);
                            cout << "Enter the Roll Number of the student: ";
                            cin >> temproll;
                            cout << "For which element (i.e. quiz, project etc) you want to enter the marks: ";
                            cin >> tempelement;
                            cout << "Enter the Marks of the student: ";
                            cin >> tempmarks;
                            writemarks << temproll << " " << tempelement << " " << tempmarks <<endl;
                            writemarks.close();
                        }
                        else if (choiceres == 2)
                        {
                            readmarks.open("Course2Marks.txt");
                            cout << "BASIC_ELECTRONICS GRADEBOOK  *******************" << endl << endl;
                            cout << "Roll Numbers: " << " " << " Element : "<< " " << " Marks: " << endl;
                            while (readmarks >> temproll >> tempelement >> tempmarks)
                                cout << temproll << "\t" << tempelement << "\t" <<tempmarks << endl;
                            readmarks.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 3)
                    {
                        ofstream writeassi;
                        ifstream readassi;
                        string tempassi;
                        string tempdate;
                        cout << "Assignments  **********************" << endl;
                        cout << endl <<"You want to add or view Assignment: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeassi.open("Course2Assignment.txt",ios_base::app);
                            cout << "Enter the Assignment: ";
                            cin >> tempassi;
                            cout << "Enter the Due Date: ";
                            cin >> tempdate;
                            writeassi << tempassi << " " << tempdate << endl;
                            writeassi.close();
                        }
                        else if (choiceres == 2)
                        {
                            readassi.open("Course2Assignment.txt");
                            cout << "Name: " << " " << " Due Date: " << endl;
                            while (readassi >> tempassi >> tempdate)
                                cout << tempassi << " "<< tempdate <<endl;
                            readassi.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course2.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"BASIC_ELECTRONICS COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                        choice = viewrsrc();
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
            }while(choice1 != -1);
        }
        else if (choice == 3)
        {
            int choice1;
            int choiceres = 0;
            do{
                    cout << endl << c.crs3(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to edit resources: " << endl;
                    cout << "Enter 2 to edit marks: " << endl;
                    cout << "Enter 3 to edit Due assignments: " <<endl;
                    cout << "Enter 4 to edit rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        string tempres;
                        ifstream temp;
                        ofstream writeres;
                        cout << "Resources  **********************" << endl;
                        cout << endl <<"You want to add or view resources: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeres.open("Course3Resources.txt",ios_base::app);
                            cout << "Enter the resources: ";
                            cin >> tempres;
                            writeres << tempres << endl;
                            writeres.close();
                        }
                        else if (choiceres == 2)
                        {
                            temp.open("Course3Resources.txt");
                            while (temp >> tempres)
                                cout << tempres << endl;
                            temp.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        string temproll, tempelement,tempmarks;
                        ofstream writemarks;
                        ifstream readmarks;
                        cout << "Marks  **********************" << endl;
                        cout << endl <<"You want to add or view marks: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writemarks.open("Course3Marks.txt",ios_base::app);
                            cout << "Enter the Roll Number of the student: ";
                            cin >> temproll;
                            cout << "For which element (i.e. quiz, project etc) you want to enter the marks: ";
                            cin >> tempelement;
                            cout << "Enter the Marks of the student: ";
                            cin >> tempmarks;
                            writemarks << temproll << " " << tempelement << " " << tempmarks <<endl;
                            writemarks.close();
                        }
                        else if (choiceres == 2)
                        {
                            readmarks.open("Course3Marks.txt");
                            cout << "INTRODUCTION_TO_BIOLOGY GRADEBOOK  *******************" << endl << endl;
                            cout << "Roll Numbers: " << " " << " Element : "<< " " << " Marks: " << endl;
                            while (readmarks >> temproll >> tempelement >> tempmarks)
                                cout << temproll << "\t" << tempelement << "\t" <<tempmarks << endl;
                            readmarks.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 3)
                    {
                        ofstream writeassi;
                        ifstream readassi;
                        string tempassi;
                        string tempdate;
                        cout << "Assignments  **********************" << endl;
                        cout << endl <<"You want to add or view Assignment: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeassi.open("Course3Assignment.txt",ios_base::app);
                            cout << "Enter the Assignment: ";
                            cin >> tempassi;
                            cout << "Enter the Due Date: ";
                            cin >> tempdate;
                            writeassi << tempassi << " " << tempdate << endl;
                            writeassi.close();
                        }
                        else if (choiceres == 2)
                        {
                            readassi.open("Course3Assignment.txt");
                            cout << "Name: " << " " << " Due Date: " << endl;
                            while (readassi >> tempassi >> tempdate)
                                cout << tempassi << " "<< tempdate <<endl;
                            readassi.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course3.txt");
                        temproos >> a >> b >> c >> d;
                        cout<<"INTRODUCTION_TO_BIOLOGY COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                        choice = viewrsrc();
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
            }while(choice1 != -1);
        }
        else if (choice == 4)
        {
            int choice1;
            int choiceres = 0;
            do{
                    cout << endl << c.crs4(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to edit resources: " << endl;
                    cout << "Enter 2 to edit marks: " << endl;
                    cout << "Enter 3 to edit Due assignments: " <<endl;
                    cout << "Enter 4 to edit rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        string tempres;
                        ifstream temp;
                        ofstream writeres;
                        cout << "Resources  **********************" << endl;
                        cout << endl <<"You want to add or view resources: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeres.open("Course4Resources.txt",ios_base::app);
                            cout << "Enter the resources: ";
                            cin >> tempres;
                            writeres << tempres << endl;
                            writeres.close();
                        }
                        else if (choiceres == 2)
                        {
                            temp.open("Course4Resources.txt");
                            while (temp >> tempres)
                                cout << tempres << endl;
                            temp.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        string temproll, tempelement,tempmarks;
                        ofstream writemarks;
                        ifstream readmarks;
                        cout << "Marks  **********************" << endl;
                        cout << endl <<"You want to add or view marks: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writemarks.open("Course4Marks.txt",ios_base::app);
                            cout << "Enter the Roll Number of the student: ";
                            cin >> temproll;
                            cout << "For which element (i.e. quiz, project etc) you want to enter the marks: ";
                            cin >> tempelement;
                            cout << "Enter the Marks of the student: ";
                            cin >> tempmarks;
                            writemarks << temproll << " " << tempelement << " " << tempmarks <<endl;
                            writemarks.close();
                        }
                        else if (choiceres == 2)
                        {
                            readmarks.open("Course4Marks.txt");
                            cout << "DISCRETE_MATHEMATICS GRADEBOOK  *******************" << endl << endl;
                            cout << "Roll Numbers: " << " " << " Element : "<< " " << " Marks: " << endl;
                            while (readmarks >> temproll >> tempelement >> tempmarks)
                                cout << temproll << "\t" << tempelement << "\t" <<tempmarks << endl;
                            readmarks.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 3)
                    {
                        ofstream writeassi;
                        ifstream readassi;
                        string tempassi;
                        string tempdate;
                        cout << "Assignments  **********************" << endl;
                        cout << endl <<"You want to add or view Assignment: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeassi.open("Course4Assignment.txt",ios_base::app);
                            cout << "Enter the Assignment: ";
                            cin >> tempassi;
                            cout << "Enter the Due Date: ";
                            cin >> tempdate;
                            writeassi << tempassi << " " << tempdate << endl;
                            writeassi.close();
                        }
                        else if (choiceres == 2)
                        {
                            readassi.open("Course4Assignment.txt");
                            cout << "Name: " << " " << " Due Date: " << endl;
                            while (readassi >> tempassi >> tempdate)
                                cout << tempassi << " "<< tempdate <<endl;
                            readassi.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course4.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"DISCRETE_MATHEMATICS COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                        choice = viewrsrc();
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
            }while(choice1 != -1);
        }
        else if (choice == 5)
        {
            int choice1;
            int choiceres = 0;
            do{
                    cout << endl << c.crs5(fname) << "  **********************" <<endl;
                    cout << c.getcname() << "  **********************" <<endl;
                    cout << "Enter 1 to edit resources: " << endl;
                    cout << "Enter 2 to edit marks: " << endl;
                    cout << "Enter 3 to edit Due assignments: " <<endl;
                    cout << "Enter 4 to edit rooster: " << endl;
                    cout << "Enter -1 to go up: ";
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        string tempres;
                        ifstream temp;
                        ofstream writeres;
                        cout << "Resources  **********************" << endl;
                        cout << endl <<"You want to add or view resources: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeres.open("Course5Resources.txt",ios_base::app);
                            cout << "Enter the resources: ";
                            cin >> tempres;
                            writeres << tempres << endl;
                            writeres.close();
                        }
                        else if (choiceres == 2)
                        {
                            temp.open("Course5Resources.txt");
                            while (temp >> tempres)
                                cout << tempres << endl;
                            temp.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 2)
                    {
                        string temproll, tempelement,tempmarks;
                        ofstream writemarks;
                        ifstream readmarks;
                        cout << "Marks  **********************" << endl;
                        cout << endl <<"You want to add or view marks: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writemarks.open("Course5Marks.txt",ios_base::app);
                            cout << "Enter the Roll Number of the student: ";
                            cin >> temproll;
                            cout << "For which element (i.e. quiz, project etc) you want to enter the marks: ";
                            cin >> tempelement;
                            cout << "Enter the Marks of the student: ";
                            cin >> tempmarks;
                            writemarks << temproll << " " << tempelement << " " << tempmarks <<endl;
                            writemarks.close();
                        }
                        else if (choiceres == 2)
                        {
                            readmarks.open("Course5Marks.txt");
                            cout << "ASSEMBLY_LANGUAGE GRADEBOOK  *******************" << endl << endl;
                            cout << "Roll Numbers: " << " " << " Element : "<< " " << " Marks: " << endl;
                            while (readmarks >> temproll >> tempelement >> tempmarks)
                                cout << temproll << "\t" << tempelement << "\t" <<tempmarks << endl;
                            readmarks.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 3)
                    {
                        ofstream writeassi;
                        ifstream readassi;
                        string tempassi;
                        string tempdate;
                        cout << "Assignments  **********************" << endl;
                        cout << endl <<"You want to add or view Assignment: Enter 1,2 respectively. ";
                        cin >> choiceres;
                        if (choiceres == 1)
                        {
                            writeassi.open("Course5Assignment.txt",ios_base::app);
                            cout << "Enter the Assignment: ";
                            cin >> tempassi;
                            cout << "Enter the Due Date: ";
                            cin >> tempdate;
                            writeassi << tempassi << " " << tempdate << endl;
                            writeassi.close();
                        }
                        else if (choiceres == 2)
                        {
                            readassi.open("Course5Assignment.txt");
                            cout << "Name: " << " " << " Due Date: " << endl;
                            while (readassi >> tempassi >> tempdate)
                                cout << tempassi << " "<< tempdate <<endl;
                            readassi.close();
                        }
                        else
                            cout << "Error!!! Enter correct Input Value! " << endl;
                    }
                    else if (choice1 == 4)
                    {
                        ifstream temproos;
                        string a,b,c,d;
                        string rollno, status, fname, lname , email , password;
                        temproos.open("Course5.txt");
                        temproos >> a >> b >> c >> d;
                        cout <<"ASSEMBLY_LANGUAGE COURSE ROOSTER  *******************" <<endl << endl;
                        while (temproos >> rollno >> status >> fname >> lname >> email >> password)
                        {
                            cout << rollno << "\t" << status << "\t" << fname << "\t" << lname << "\t" << email << endl << endl;
                        }
                    }
                    else if (choice1 == -1)
                        choice = viewrsrc();
                    else
                        cout << "Error!!! Enter correct Input Value! " << endl;
            }while(choice1 != -1);
        }
        else if (choice == -1)
            return 0;
        else
            cout << "Error!!! Enter correct Input Value! " << endl;
    }while(choice != -1);
}

///////////////////////     COURSE CLASS    ///////////////////////////////
course::course()
{
    ccode = " ";
    cap = 0;
    cname = " ";
    school = " ";
    status = " ";
}
course::course(string tcname, string tccode, string tschool, string tstatus, int tcap)
{
    cname = tcname;
    ccode = tccode;
    school = tschool;
    cap = tcap ;
    status = tstatus;
}
string course::getcname()
{
    return cname;
}
string course::getccode()
{
    return ccode;
}
string course::getschool()
{
    return school;
}
int course::getcap()
{
    return cap;
}
string course::getstatus()
{
    return status;
}
string course::crs1(string tfname)
{
    ifstream crs1;
    crs1.open("Course1.txt");
    crs1 >> cname >> ccode >> school >> cap;
    string rollno, status, fname, lname , email , password;
    while (crs1 >> rollno >> status >> fname >> lname >> email >> password)
    {
        if (tfname == fname)
        {
            return fname;
            break;
        }
    }
    return " ";
}
string course::crs2(string tfname)
{
    ifstream crs2;
    crs2.open("Course2.txt");
    crs2 >> cname >> ccode >> school >> cap;
    string rollno, status, fname, lname , email , password;
    while (crs2 >> rollno >> status >> fname >> lname >> email >> password)
    {
        if (tfname == fname)
        {
            return fname;
            break;
        }
    }
    return " ";
}
string course::crs3(string tfname)
{
    ifstream crs3;
    crs3.open("Course3.txt");
    crs3 >> cname >> ccode >> school >> cap;
    string rollno, status, fname, lname , email , password;
    while (crs3 >> rollno >> status >> fname >> lname >> email >> password)
    {
        if (tfname == fname)
        {
            return fname;
            break;
        }
    }
    return " ";
}
string course::crs4(string tfname)
{
    ifstream crs4;
    crs4.open("Course4.txt");
    crs4 >> cname >> ccode >> school >> cap;
    string rollno, status, fname, lname , email , password;
    while (crs4 >> rollno >> status >> fname >> lname >> email >> password)
    {
        if (tfname == fname)
        {
            return fname;
            break;
        }
    }
    return " ";
}
string course::crs5(string tfname)
{
    ifstream crs5;
    crs5.open("Course5.txt");
    crs5 >> cname >> ccode >> school >> cap;
    string rollno, status, fname, lname , email , password;
    while (crs5 >> rollno >> status >> fname >> lname >> email >> password)
    {
        if (tfname == fname)
        {
            return fname;
            break;
        }
    }
    return " ";
}

string course::popdata(string username, string password)
{
    string status, email, tusername, tfname, tlname, tpassword;
    ifstream userdata;
    userdata.open("userList.txt");
    while (userdata >> tusername >> status >> tfname >> tlname >> email >> tpassword)
    {
        if (username == tusername && password == tpassword)
        {
            return tfname;
        }
    }
    return " ";
}
