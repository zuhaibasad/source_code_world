#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include "Chaining.h"
#include "task1.cpp"

using namespace std;

HashC::HashC(int _a)
{
    a = _a;
    tableSize = 1001;
    collisions = 0;
    hashTable = new LinkedList<string>[tableSize];
}
void HashC::Load(char* filename)
{
    ifstream file;
    file.open(filename);
    int index;
    string key;
    while(getline(file, key))
    {
        index = hash(key);
        hashTable[index].insertAtHead(key);
    }

}
int HashC::hash(string key)
{
    long long int k = hashcode(key,a);
    return compression(k, tableSize);
}

ListItem<string>* HashC::lookup(string key)
{
    int index = hash(key);
    return hashTable[index].searchFor(key);
}

void HashC::insert(string word)
{
    int index = hash(word);
    hashTable[index].insertAtHead(word);
}

int HashC::Collisions()
{
    int i=0;
    while(i<tableSize)
    {
        if (hashTable[i].length() > 1)
            collisions++;
        i++;
    }
    return collisions;
}

