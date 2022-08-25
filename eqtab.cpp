#include "eqtab.h"

EQTAB::EQTAB(char key, string s) {
    this->key = key;
    this->s = s;
    this->proximo = NULL;
}

LISTAEQ::LISTAEQ() {
    inicio = NULL;
    fim = NULL;
}

void LISTAEQ::inserir_final(char key, string s) {
    EQTAB* novo = new EQTAB(key, s);
    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }
}

void LISTAEQ::imprimir() {
    EQTAB* aux = inicio;
    while (aux != NULL) {
        cout << aux->key << " " << aux->s << endl;
        aux = aux->proximo;
    }
}