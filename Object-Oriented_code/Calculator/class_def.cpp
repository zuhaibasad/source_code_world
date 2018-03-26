#include "header.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

fraction::fraction ( )
{
    num = new int;
    denum = new int;
}
fraction::fraction(const fraction& frc)
{
    num = new int;
    denum = new int;

    *num = *frc.num;
    *denum = *frc.denum;
}
fraction::fraction(int tnum, int tdenum)
{
    num = new int;
    denum = new int;

    *num = tnum;
    *denum = tdenum;
}
fraction::~fraction ( )
{
    delete num;
    delete denum;
}

fraction fraction::operator + (const fraction& frc)
{
    fraction temp;

    int n1 = (*num) * (*frc.denum);
    int n2 = (*denum) * (*frc.num);
    int d = (*denum) * (*frc.denum);
    *temp.num = n1+n2;
    *temp.denum = d;

    return (temp);
}
fraction fraction::operator - (const fraction& frc)
{

    fraction temp;
    int n1 = (*num) * *frc.denum;
    int n2 = (*denum) * *frc.num;
    int d = (*denum) * *frc.denum;
    *temp.num = n1-n2;
    *temp.denum = d;
    return temp;
}
fraction fraction::operator * (const fraction& frc)
{
    fraction temp;

    *temp.num = (*num) * *frc.num;
    *temp.denum = (*denum) * *frc.denum;
    return temp;
}
fraction fraction::operator / (const fraction& frc)
{
    if ( *frc.num == 0)
    {
        cout << "Division by zero is undefined ! " << endl;
        exit(0);
    }

    fraction temp;

    *temp.num = (*num) * *frc.denum;
    *temp.denum = (*denum) * *frc.num;

    return temp;
}

bool fraction::operator == (const fraction& frc)
{
    fraction temp;
    if( ( ((*num)% *frc.num) == 0 && ((*denum)% *frc.denum) == 0 ) || (((*frc.num)% *num) == 0 && ((*frc.denum)% *denum) == 0 ) )
    {
        return 1;  //true
    }
    else
        return 0;  //false
}

void fraction::operator =(const fraction& frc)
{
    *num = *frc.num;
    *denum = *frc.denum;
}

fraction fraction::operator ++ ()   //pre-increment
{
    *num += *denum;
    *denum = *denum;
    return *this;
}

fraction fraction::operator ++ (int n)  //post-increment
{
    fraction temp( *this );
    temp = *this;
    operator++();
    return temp;
}

fraction fraction::operator -- ()
{
    *num -= *denum;
    *denum = *denum;
    return *this;
}
fraction fraction::operator -- (int n)
{
    fraction temp( *this );
    temp = *this;
    operator--();
    return temp;
}

void operator >> (istream& in, const fraction& frc)
{
    cout << "Enter The numerator: ";
    in >> (*frc.num);
    *frc.denum = -1;
    do{
        if (*frc.denum == 0)
            cout << "Error!... denominator cannot be zero! " << endl;
        cout << "Enter The denominator: ";
        in >> (*frc.denum);

    }while(*frc.denum == 0);

}

ostream& operator << (ostream& out, const fraction& frc)
{
    out << (*frc.num) << "/" << (*frc.denum);
    return out;
}

operation::operation()
{
    oprnd = new fraction[2];
    opcount = 0;
    sym = "";
}

operation::operation(int topcount, string tsym)
{
    oprnd = new fraction [2];
    opcount = topcount;
    sym = tsym;
}

operation::operation(const operation& op)
{
    oprnd = new fraction[op.opcount];
    for (int i=0; i<op.opcount; i++)
    {
        oprnd[i] = op.oprnd[i];
    }
}
void operation::operator = (const operation& op)
{
    opcount = op.opcount;
    for (int i=0; i<opcount; i++)
        oprnd[i] = op.oprnd[i];
    sym = op.sym;
    if (sym == "+")
    {
        res = oprnd[0] + oprnd[1];
    }
    else if (sym == "-")
    {
        res = oprnd[0] - oprnd[1];
    }
    else if (sym == "*")
    {
        res = oprnd[0] * oprnd[1];
    }
    else if (sym == "/")
    {
        res = oprnd[0] / oprnd[1];
    }
    else if (sym == "p+")
    {
        res = ++oprnd[0];
    }
    else if (sym == "+p")
    {
        res = oprnd[0]++;
    }
    else if (sym == "p-")
    {
        res = --oprnd[0];
    }
    else if (sym == "-p")
    {
        res = oprnd[0]--;
    }
}

operation::~operation()
{
    delete [] oprnd;
}

void operator >> (istream &in, const operation& op)
{
    for (int i=0; i<op.opcount; i++)
    {
        in >> op.oprnd[i];
    }
}
ostream& operator << (ostream &out, const operation &op)
{
    for (int i=0; i< op.opcount; i++)
    {
        out << "operand " << i+1 << " : " << op.oprnd[i];
        out << endl;
    }
    out << "Operation Performed: " << op.sym << endl;
    if (op.sym == "==")
        cout << "Result is: " << (op.oprnd[0] == op.oprnd[1]) << endl;
    else
        cout << "Result is: " << op.res << endl;

    return out;
}
///////////////////************ STACK CLASS ************//////////////////
stack::stack()
{
    size = 1;
    list = new operation [size];
}
void stack::setter(int t_size)
{
    size = t_size;
}
void stack::push(const operation& op)
{
    if (size == 1)
    {
        list[0] = op;
    }
    else
    {
        operation *temp = new operation [size];  //for copy the list
        for (int i=0; i<(size-1); i++)
        {
            temp[i] = list[i];
        }
        temp[size-1] = op;                       //insert latest operation in the list of operations
        delete [] list;
        list = new operation [size];             //increased list
        for (int i=0; i<size; i++)
        {
            list[i] = temp[i];                  //copied temp
        }
    }
}
void stack::pop()
{
    operation *temp = new operation [size];
    for (int i=0; i< size ; i++)
    {
        temp[i] = list[i];
    }
    delete [] list;
    list = NULL;
    list = new operation [size];
    for (int i=0; i<size; i++)
    {
        list[i] = temp[i];
    }
}

void stack::print()
{
    cout << endl <<" \t ****** List of operations ****** " << endl;
    for (int i=0; i<size; i++)
    {
        cout << list[i] << endl;
    }
    cout << endl;
}
