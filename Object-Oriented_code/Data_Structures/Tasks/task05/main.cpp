#include <iostream>
#include <fstream>
#include "Chaining.cpp"
#include "openAddress.cpp"
#include "doubleHash.cpp"

using namespace std;

int main()
{
    ifstream file_dict;
    ifstream file_query;
    file_dict.open("dict.txt");
    vector <string> vect_dict;
    string temp;
    while(getline(file_dict,temp))
        vect_dict.push_back(temp);
    file_dict.close();
    file_query.open("queiries.txt");
    vector <string> vect_query;
    while(getline(file_query, temp))
        vect_query.push_back(temp);


}
