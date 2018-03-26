#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
using namespace std;

class User
{
protected:
    string fname;
    string lname;
    string password;
    string username;
public:
    User();
    User(string, string, string , string);
    virtual int viewrsrc()=0;
    virtual bool outline(int) = 0;
};

class Student : public User
{
protected:
    string rollno;
    string status;
public:
    Student();
    Student(string trollno, string tstauts, string tfname, string tlname, string tpassword, string tusername);
    int viewrsrc();
    bool outline(int);
};

class Instructor: public User
{
protected:
    string desi;
    string status;
public:
    Instructor();
    Instructor(string, string, string, string , string , string);
    int viewrsrc();
    bool outline(int);
};

class course
{
protected:
    string cname;
    string ccode;
    string school;
    int cap;
    string status;
public:
    course();
    course(string, string, string, string,int);
    string getcname();
    string getschool();
    string getccode();
    string getstatus();
    int getcap();
    string crs1(string);
    string crs2(string);
    string crs3(string);
    string crs4(string);
    string crs5(string);
    string popdata(string, string);
};

#endif // HEADER_H_INCLUDED
