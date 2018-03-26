#include "header.cpp"
#include <iostream>

using namespace std;

int main()
{
    string choice = "";
    stack temp1; //creating object to insert operations into stack
    int size = 0; //this size is for temp which increase with operations
    do{
        cout << "Enter 1 to add two fractional number" << endl;
        cout << "Enter 2 to subtract two fractional number" << endl;
        cout << "Enter 3 to multiply two fractional number" << endl;
        cout << "Enter 4 to divide two fractional number" << endl;
        cout << "Enter 5 to compare two fractional number" << endl;
        cout << "Enter 6 to pre-increment a fractional number" << endl;
        cout << "Enter 7 to post-increment a fractional number" << endl;
        cout << "Enter 8 to pre-decrement a fractional number" << endl;
        cout << "Enter 9 to post-decrement a fractional number" << endl;
        cout << "Enter 10 to pop last operation from stack" << endl;
        cout << "Enter 11 print stack" << endl;
        cout << "Enter -1 to exit" << endl;
        cout << endl << "Enter your Choice: ";
        cin >> choice;

        if (!(choice == "10" || choice == "11" ))           //increasing size of temp array for each iteration.
            size ++;

        temp1.setter(size);

        if (choice == "1")
        {
            operation temp(2,"+");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);             //here operation is inserted
        }
        else if (choice == "2")
        {
            operation temp(2,"-");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "3")
        {
            operation temp(2,"*");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "4")
        {
            operation temp(2,"/");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "5")
        {
           operation temp(2,"==");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "6")
        {
            operation temp(1,"p+");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "7")
        {
            operation temp(1,"+p");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "8")
        {
            operation temp(1,"p-");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "9")
        {
            operation temp(1,"-p");
            cin >> temp;
            operation op;
            op = temp;
            cout << op << endl;
            temp1.push(op);
        }
        else if (choice == "10")
        {
            size--;
            temp1.pop();
        }
        else if (choice == "11")
        {
            temp1.print();
        }
        else if (choice == "-1")
            return 0;
        else
        {
            cout << "Please type the correct choice!... " << endl;
        }
    }while(choice != "-1");
}
