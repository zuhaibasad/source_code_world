#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long int hashcode(string key, int a)
{
    int keysize = key.size();
    keysize--;
    int i = 0;
    int P = 0;
    long long int Sum = 0;
    while(keysize >= 0)
    {
        P = (int)key[keysize];
        Sum += (pow(a,i))*P;
        i++;
        keysize-- ;
    }
    return Sum;
}

template <class T>
int compression(T key , int N)
{
    int index;
    index = key%N;
    return index;
}
