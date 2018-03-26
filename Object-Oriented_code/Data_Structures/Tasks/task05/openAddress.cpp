#include<iostream>
#include<string>
#include<cstring>
#include "task1.cpp"
#include<fstream>
#include "openAddress.h"


using namespace std;

OpenAddress::OpenAddress(int A)
{
    a= A;
    collisions = 0;
    cap2=0;
    tableSize = 10;
    hashTable = new string[tableSize];
    for (int i = 0; i<tableSize; i++)
        hashTable[i] = " ";
}
int OpenAddress::hash(string key)
{
    unsigned long long int k = hashcode(key,a);
    return compression(k, tableSize);
}

void OpenAddress::Load(char* filename)
{
    ifstream file;
    file.open(filename);
    int index;
    string key;

    while(getline(file, key))
    {
        loading(key);
    }

}

long OpenAddress::getSize()
{
    return tableSize;
}

void OpenAddress::resize()
{
    string tempkeys[cap2];
    int j=0;

    for (int i=0; i<tableSize; i++)
    {
        if (hashTable[i] != " ")
            {
                tempkeys[j] = hashTable[i];
                j++;
            }
    }

    delete [] hashTable;
    tableSize *= 2;
    hashTable = new string[tableSize];

    for (int i=0; i<tableSize; i++)
    {
        hashTable[i] = " ";
    }

    int index;
    for (int i=0; i<cap2; i++)
    {
        index = hash(tempkeys[i]);
        while(hashTable[index] != " ")
        {
            if (index<tableSize)
                index++;
            else
                index = 0;
        }
        hashTable[index] = tempkeys[i];
    }
}

string OpenAddress::lookUp(string Word)
{
    for(int i=0; i<tableSize; i++)
        if (hashTable[i] == Word)
           return hashTable[i];
}

void OpenAddress::insertItem(string Word)
{
    loading(Word);
}

void OpenAddress::loading(string key)
{
    if ( cap2 == (tableSize/2) )
        resize();
    unsigned int index = hash(key);
    while(hashTable[index] != " ")
    {
        if (index < (tableSize-1))
            index++;
        else
            index = index%(tableSize/2);
        collisions++;
    }
    hashTable[index] = key;
    cap2++;
}
int OpenAddress::Collisions()
{
    return collisions;
}
