#include "prefix.h"

prefix::prefix(){
    list_root = NULL;
    tam = 0;
}

void prefix::inserir_ordenado(prefix_node *no){       
    prefix_node *aux;

    if(list_root == NULL){
        list_root = no;
    }else if(no->frequencia < list_root->frequencia){
        no->prxox = list_root;
        list_root = no;
    }else{
        aux = list_root;
        while(aux->prxox && aux->prxox->frequencia <= no->frequencia){
            aux = aux->prxox;
        }
        no->prxox = aux->prxox;
        aux->prxox = no;
    }
    tam++;
}

void prefix::preencher_lista(pair <mychar, myint> tab[]){
    int i;
    prefix_node *novo;

    for(i = 0; i < 256; i++){
        if(tab[i].second > 0){
            novo = new prefix_node;

            if(novo){
                novo->caractere = tab[i].first;
                novo->frequencia = tab[i].second;
                novo->left = NULL;
                novo->right = NULL;
                novo->prxox = NULL;
                inserir_ordenado(novo);
            }else{
                cout << "Erro ao alocar memoria, funcao: preencher_lista" << endl;
                break;
            }
        }
    }
}

void prefix::imprimir_lista(){
    prefix_node *aux = list_root;

    cout << "TAM lista " << tam << endl;
    while(aux){
        cout << "Carac: " << (unsigned char)aux->caractere << " Freq: " << aux->frequencia << endl;
        aux = aux->prxox;
    }
}

prefix_node* prefix::remover_inicio(){
    prefix_node *aux = NULL;

    if(list_root){
        aux = list_root;
        list_root = aux->prxox;
        aux->prxox = NULL;
        tam--;
    }
    return aux;
}

prefix_node* prefix::montar_arv(){
    prefix_node *primeiro, *segundo, *novo;

    while(tam > 1){
        primeiro = remover_inicio();
        segundo = remover_inicio();
        novo = new prefix_node;

        if(novo){
            novo->caractere = '+';      //nó pai, não precisa ter caractere definido mas vou usar '+'
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->left = primeiro;
            novo->right = segundo;
            novo->prxox = NULL;
            
            inserir_ordenado(novo);
        }else{
            cout << "Erro ao alocar memoria, funcao: montar_arv" << endl;
            break;
        }
    }
    return list_root;      //nó raiz
}

void prefix::imprimir_arv(prefix_node *raiz, int tam){
    if(raiz->left == NULL && raiz->right == NULL){
        cout << "Carac: " << (char)raiz->caractere << " Altura: " << tam << endl;
    }else{
        imprimir_arv(raiz->left, tam + 1);
        imprimir_arv(raiz->right, tam + 1);
    }
}

int prefix::altura_arv(prefix_node *raiz){
    int esq, dir;
    
    if(raiz == NULL){
        return -1;
    }else{
        esq = altura_arv(raiz->left) + 1;
        dir = altura_arv(raiz->right) + 1;
        if(esq > dir){
            return esq;
        }else{
            return dir;
        }
    }
}

char** prefix::alocar_tabeq(int colunas){
    char **tab;
    int i;
    
    tab = (char**)malloc(256 * sizeof(char*));
    for(i = 0; i < 256; i++){
        tab[i] = (char*)calloc(colunas, sizeof(char));
    }
    return tab;
}

void prefix::gerar_tabeq(char **tabeq, prefix_node *raiz, char *caminho, int colunas){
    char esquerda[colunas], direita[colunas];

    if(raiz->left == NULL && raiz->right == NULL){
        strcpy(tabeq[raiz->caractere], caminho);
    }else{
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);
        strcat(esquerda, "0");
        strcat(direita, "1");
        
        gerar_tabeq(tabeq, raiz->left, esquerda, colunas);
        gerar_tabeq(tabeq, raiz->right, direita, colunas);
    }
}

void prefix::imprimir_tabeq(char **tabeq){    
    int i;
    for(i = 0; i < 256; i++){
        if(strlen(tabeq[i]) > 0){
            cout << "Carac: " << (unsigned char)i << " " << tabeq[i] << endl;
        }
    }
}

void prefix::retornar_tabeq_para_tabeqpair(char **tabeq){
    int i;
    for(i = 0; i < 256; i++){
        if(strlen(tabeq[i]) > 0){
            tabeqpair[i].first = (unsigned char)i;
            tabeqpair[i].second = tabeq[i];
        }
    }
}