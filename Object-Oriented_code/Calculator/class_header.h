#include <iostream>
using namespace std;

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

class fraction
{
private:
    int *num;
    int *denum;
public:
    fraction();
    fraction(const fraction &frc);
    fraction(int tnum, int tdenum);
    ~fraction ( );
    friend void operator>>(istream& in, const fraction& frc);
    friend ostream& operator << (ostream& out, const fraction& frc);
    fraction operator + (const fraction& frc);
    fraction operator - (const fraction& frc);
    fraction operator * (const fraction& frc);
    fraction operator / (const fraction& frc);
    bool operator == (const fraction& frc);
    void operator = (const fraction& frc);
    fraction operator++ ();
    fraction operator++ (int);
    fraction operator-- ();
    fraction operator-- (int);
};

class operation
{
private:
    fraction *oprnd;
    fraction res;
    int opcount;
    string sym;
public:
    operation();
    operation(int topcount, string tsym);
    operation (const operation& op);
    void operator = (const operation& op);
    ~operation ( );
    friend void operator >> (istream& in, const operation &op);
    friend ostream& operator << (ostream& out, const operation& op);
};
class stack
{
private:
    operation *list;
    int size;
public:
    stack();
    void setter(int t_size);
    void push(const operation& op);
    void pop();
    void print();
};
#endif // FRACTION_H_INCLUDED
