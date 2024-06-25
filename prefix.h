#include <iostream>
#include <string>
#include <string.h>

using namespace std;
typedef unsigned char mychar;
typedef unsigned long long int myint;     //vem da tabela de frequencia feita de pair<mychar, myint>

class prefix_node{//NO
public:
   prefix_node* prxox;  //proximo        
   prefix_node *left, *right; //esquerda e direita
   unsigned char caractere;
   unsigned long frequencia;
};

class prefix{//LISTA
public:
   prefix_node *list_root;    //inicio
   int tam;
   pair<char, string> tabeqpair[256];

   prefix();
   void inserir_ordenado(prefix_node *no);
   void preencher_lista(pair <mychar, myint> tab[]);
   void imprimir_lista();

   prefix_node* remover_inicio();
   prefix_node* montar_arv();
   void imprimir_arv(prefix_node *raiz, int tam);

   int altura_arv(prefix_node *raiz);
   char** alocar_tabeq(int colunas);
   void gerar_tabeq(char **tabeq, prefix_node *raiz, char *caminho, int colunas);   
   void imprimir_tabeq(char **tabeq);
   void retornar_tabeq_para_tabeqpair(char **tabeq);
};