#include "ftab.h"
#include "prefix.h"
#include "eqtab.h"
#include "bqueue.h"
#include <iostream>
#include <locale>

int main(int argc, char* argv[]) {
    char* filename = argv[1];
    char* comando = argv[2];
    char* namearq = argv[3];
    
    setlocale(LC_ALL, "Portuguese");

    cout << "Comando: " << comando << endl;
    string comando_s = comando;

    ftab tab = ftab(filename, comando);
    if(comando_s == "COMPACTAR"){
        //cout << "\nTABELA DE FREQUENCIA: " << endl;
        //tab.print();
    }

    cout << endl;

    prefix lista;
    lista.preencher_lista(tab.tab);
    if(comando_s == "COMPACTAR"){
        //cout << "TABELA DE FREQUENCIA NA LISTA ENCADEADA: " << endl;
        //lista.imprimir_lista();
    }

    cout <<  endl;

    prefix_node *arv = lista.montar_arv();
    if(comando_s == "COMPACTAR"){
        //cout << "ARVORE: " << endl;
        //lista.imprimir_arv(arv, 0); 
    }

    cout << endl;

    int colunas = lista.altura_arv(arv) + 1;
    char **tabeq = lista.alocar_tabeq(colunas);
    lista.gerar_tabeq(tabeq, arv, (char*)"", colunas);
    if(comando_s == "COMPACTAR"){
        //cout << "TABELA DE EQUIVALENCIA: " << endl;
        //lista.imprimir_tabeq(tabeq);
    }
    lista.retornar_tabeq_para_tabeqpair(tabeq);

    cout << endl;

    LISTAEQ L;
    for(int i=0; i<256; i++){
        if(lista.tabeqpair[i].second.length() > 0){
            L.inserir_final(lista.tabeqpair[i].first, lista.tabeqpair[i].second);  
        }   
    }
    if(comando_s == "COMPACTAR"){   
        //cout << "TABELA DE EQUIVALENCIA NA LISTA ENCADEADA: " << endl;
        //L.imprimir();
    }

    cout << endl;

    BQUEUE bq;
    if(comando_s == "COMPACTAR"){
        char* caminho = bq.caminho(tabeq, filename);
        //cout << "CAMINHO: " << caminho << endl;    
        bq.pushString(caminho, tab.tab, namearq);
    }else{
        bq.descompactar(arv, tab.tab, filename, namearq);
    }
    return 0;
}