#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include "doubleHash.h"

using namespace std;

int main ()
{
	ifstream read;
	vector <string> dict;

	read.open("dict.txt");
	while(!read.eof())
	{
		string Buffer;
		getline(read,Buffer,'\n');
		dict.push_back(Buffer);
    }
	read.close();

	int test = 0;

	DoubleHash Dictionary(34);

	long tableSize = Dictionary.getSize();
   // cout << "Size: " << dict.size() << endl;
	for(int i = 0 ; i < dict.size() ; i++)
	{
	 //    cout << "Hello : " << i << endl;
		Dictionary.insertItem(dict[i]);
		string result = Dictionary.lookUp(dict[i]);

		if(result == dict[i])
		{
			test++;
		}
	}

	long newSize = Dictionary.getSize();

	assert(test == dict.size());
	assert(newSize > tableSize);

	cout << "Everything Works!" << endl;

	return 0;
}
