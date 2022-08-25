#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;
typedef unsigned char mychar;
typedef unsigned long long int myint;

class prefix_node;
class prefix;

class BQUEUE {
    queue<char> fila;
    string tabela;
public:
    BQUEUE(); 
    char* caminho(char **tabeq, const char* filename);
    void pushString(string s, pair<mychar, myint> tab[], const char* namearq);
    void descompactar(prefix_node *raiz, pair<mychar, myint> tab[], const char* filename, const char* namearq);
    unsigned int b_um(unsigned char b, int i);
};