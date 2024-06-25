#include "bqueue.h"
#include "prefix.h"
#include <math.h>
#include <fstream>

BQUEUE::BQUEUE() {
}

char* BQUEUE::caminho(char **tabeq, const char* filename){
    FILE *arq1 = fopen(filename, "rb");
    int tam=0;
    
    mychar x{0};
    while(!feof(arq1)){
        fread(&x, sizeof(mychar), 1, arq1);
        tam = tam + strlen(tabeq[x]);
    }
    fclose(arq1);
    tam = tam + 1;

    char* codigo = (char*)calloc(tam, sizeof(char));
    
    FILE *arq2 = fopen(filename, "rb");
    
    mychar c{0};
    while(!feof(arq2)){
        fread(&c, sizeof(mychar), 1, arq2);
        strcat(codigo, tabeq[c]);
    }
    fclose(arq2);
    return codigo;
}

void BQUEUE::pushString(string s, pair<mychar, myint> tab[], const char* namearq){
    
    FILE *arquivo = fopen(namearq, "wb");

    for(int i=0; i<256; i++){   //imprimir tabela de frequencia
        if(tab[i].second != 0){
            tabela += (unsigned char)tab[i].first;
            tabela += ' ' + to_string(tab[i].second) + '\n';
        }
    }
    tabela = tabela + "fim" + '\n';
    fwrite(tabela.c_str(), sizeof(unsigned char), tabela.length(), arquivo);

    for (int i = 0; i < (int) s.size(); i++) {  //compactação
        fila.push(s[i]);
    
        if(fila.size() == 8){
            int num = 0;
            
            for(int j = 0; j < 8; j++){
                num += (fila.front() - '0') * pow(2, 7 - j);
                fila.pop();
            }
            fwrite(&num, sizeof(unsigned char), 1, arquivo);
        }
    }   
    fclose(arquivo);
}

unsigned int BQUEUE::b_um(unsigned char b, int i){
    unsigned char mask = (1 << i);
    return b & mask;
}

void BQUEUE::descompactar(prefix_node *raiz, pair<mychar, myint> tab[], const char* filename, const char* namearq){ 
    FILE *arquivo_comp = fopen(filename, "rb");
    FILE *arquivo_texto = fopen(namearq, "wb");
    unsigned char b;
    int i;
    prefix_node *aux = raiz;

    if(tabela.length() == 0){   //preenche a string tabela para o fseek funcionar
        for(int i=0; i<256; i++){
            if(tab[i].second != 0){
                tabela += (unsigned char)tab[i].first;
                tabela += ' ' + to_string(tab[i].second) + '\n';
            }
        }
        tabela = tabela + "fim" + '\n';
    } 

    if(arquivo_comp){
        //fseek(arquivo_comp, sizeof(unsigned long int) * (256), SEEK_SET); 
        fseek(arquivo_comp, sizeof(unsigned char) * (tabela.length()), SEEK_SET); 
        while(fread(&b, sizeof(unsigned char), 1, arquivo_comp)){
            for(i = 7; i >= 0; i--){
                if(b_um(b, i)){
                    aux = aux->right;
                }else{
                    aux = aux->left;
                }

                if(aux->left == NULL && aux->right == NULL){
                    fwrite(&aux->caractere, sizeof(unsigned char), 1, arquivo_texto);
                    aux = raiz;
                }
            }
        }
        fclose(arquivo_comp);
        fclose(arquivo_texto);
    }else{
        cout << "Erro ao abrir arquivo para descompressao, funcao: descompactar" << endl;
    }
}