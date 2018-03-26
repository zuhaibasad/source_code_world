#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "doubleHash.h"

using namespace std;

DoubleHash::DoubleHash(int A)
{
    a = A;
    collisions = 0;
    cap2 = 0;
    tableSize = 10;
    hashTable = new string[tableSize];
    for (int i=0; i<tableSize; i++)
        hashTable[i] = " ";
}

void DoubleHash::Load(char* filename)
{
    ifstream file;
    file.open(filename);
    string key;

    while(getline(file,key))
    {
        loading(key);
    }

}

int DoubleHash::hash1(string key)
{
    int hash1=0;
    for (int i=0; i<key.size(); i++)
        hash1 ^= (hash1 << 5) + (hash1 >> 2) + (int)key[i];
    return hash1%tableSize;
}

int DoubleHash::hash2(string key)
{
    int keysize = key.size();
    keysize--;
    int i = 0;
    int P = 0;
    unsigned long long int Sum = 0;
    while(keysize >= 0)
    {
        P = (int)key[keysize];
        Sum += (pow(a,i))*P;
        i++;
        keysize-- ;
    }
    return (tableSize/2) - (Sum%(tableSize/2));

}

void DoubleHash::loading(string key)
{
    //cout << "Before resizing : " << endl;
    if ( cap2 == (tableSize/2) )
        resize();
    //cout << "After resizing: " << endl;
    int i=0;
    int hash_1 = hash1(key);
    int hash_2 = hash2(key);
    unsigned int index = hash_1 + i*hash_2;
    index = index%tableSize;
    //cout << "TABLE SIZE: Index: cap : " << tableSize << " , " << index << " , " << cap2 << endl;
   // cout << "Hash1: " << hash_1 << " hash2: " << hash_2 << endl;
    while(hashTable[index] != " ")
    {
        i++;

        index = hash_1 + i*hash_2;
        index = index%tableSize;
        //cout << "hash1, hash2, i , index : " << hash_1 << " , " << hash_2 << " , " << i << " , " << index << endl;
        collisions++;
    }

    //cout << "Index : tableSize : cap : " << index << ", " << tableSize << " , "<< cap2 << endl;
    hashTable[index] = key;
    cap2++;
}

long DoubleHash::getSize()
{
    return tableSize;
}

void DoubleHash::resize()
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

    unsigned int index;
    int x=0;
    int hash_1;
    long long int hash_2;
    for (int i=0; i<cap2; i++)
    {
        hash_1 = hash1(tempkeys[i]);
        hash_2 = hash2(tempkeys[i]);
        index = hash_1 + x*hash_2;
        index = index%tableSize;
        while(hashTable[index] != " ")
        {
            x++;
            index = hash_1 + x*hash_2;
            index = index%tableSize;
      //      cout << "JAMMED! " << endl;
        }
        hashTable[index] = tempkeys[i];
    }
}

void DoubleHash::insertItem(string key)
{
    loading(key);
}

string DoubleHash::lookUp(string key)
{
    for(int i=0; i<tableSize; i++)
        if (hashTable[i] == key)
           return hashTable[i];
}
