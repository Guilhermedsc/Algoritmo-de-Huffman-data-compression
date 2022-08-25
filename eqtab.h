#include <iostream>
#include <string>

using namespace std;

class EQTAB/*no*/ {
public:
   string s;
   char key;
   EQTAB* proximo;
   
   EQTAB(char key, string s);
};

class LISTAEQ{
private:
   EQTAB* inicio;
   EQTAB* fim;

public:
   LISTAEQ();
   void inserir_final(char key, string s);
   void imprimir();
};
