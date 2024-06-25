#include <iostream>

using namespace std;
typedef unsigned char mychar;
typedef unsigned long long int myint;

class  ftab {
    string cmd;
public:
    unsigned char *texto;
    pair <mychar, myint> tab[256];
    ftab(const char* filename, char *comando);

    void BubbleSort();
    myint operator[](unsigned char  key);
    void print();
};