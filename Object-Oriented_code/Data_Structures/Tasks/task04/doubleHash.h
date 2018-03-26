#include <string.h>
#include "LinkedList.cpp"

class DoubleHash
{
	private:
		long tableSize;
		string *hashTable;				// Include your linked list class for this!
		int a;							// input to the hash function
		int collisions;
		int cap2;
	public:
		DoubleHash(int A);
		void Load(char* file);
		void loading(string key);
		long getSize();
		void resize();
		void insertItem(string Word);	// Takes a hash of 'Word' and inserts it into hashTable accordingly
		int hash1(string);
		int hash2(string);
		string lookUp(string Word);		// Looks for 'Word' and if found, returns it
		int Collisions(); // Return number of collisions in hashTable.
};
