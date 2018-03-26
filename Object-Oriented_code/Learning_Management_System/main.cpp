#include "class_def.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    User *stu;
    User *inst;
    course c;
    bool logflag = 0;
    string username, password, fname;
    string lname = " ";
    do{
        do{
            cout << "Enter UserName: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            fname = c.popdata(username, password);
            if(!(fname == " "))
            {
                cout << "You are logged in " << endl;
            }
            else if (fname == " ")
            {
                cout << "Please provide correct creditanls" << endl;
            }
        }while(fname == " ");

        if ((fname == c.crs1(fname) || fname == c.crs2(fname) || fname == c.crs3(fname) || fname == c.crs4(fname) || fname == c.crs5(fname)) && username != "Professor")
        {
            stu = new Student(username, c.getstatus(), fname, lname, password, username);
            int choice = stu->viewrsrc();
            logflag = stu->outline(choice);
        }
        else if (( "Naveed" == c.crs1(fname) || "Zartash" == c.crs2(fname) || "Aziz" == c.crs3(fname) || "Imdad" == c.crs4(fname) || "Junaid" == c.crs5(fname)) && username == "Professor")
        {
            inst = new Instructor(username, c.getstatus(), fname, lname, password, username);
            int choice = inst->viewrsrc();
            logflag = inst->outline(choice);
        }
        if (logflag == 0)
        	{
	       cout << "You have been Logged out! " << endl;
            cout << "Type your credentials Again " << endl;
            	}
    }while(logflag == 0);
    cout << "You have been Logged out! " << endl;
}
