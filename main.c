#include "arvore.h"


struct lista {
    struct no *no;
    int valor;
    struct list *prox;
};

struct list * CaminhoUniforme (struct no *arv, struct lista *lista, int destino);
void exibir(struct no *arv);

void main (void) {

}

struct list * CaminhoUniforme (struct no *arv, struct lista *lista, int destino){

    if(arv != NULL){

        if(arv->id == destino){
            exibir(arv);
            return lista;
        }else{

            lista = addList(lista, arv->filhos);

            CaminhoUniforme(Menor(), lista, destino);
        }
    }

    return lista;
}

struct lista * addlista(struct lista *lista, struct no *no){

    if(no == NULL){
        struct no *ax=no;
        struct lista *pecorrer=lista, *novo;
        int soma=0;

        while(ax->pai != NULL){
            soma = soma + no->valor;
            ax = ax->pai;
        }

        while(pecorrer->prox != NULL){
            pecorrer = pecorrer->prox;   
        }

        novo = (struct lista*)malloc(sizeof(struct lista));
        novo->no = no;
        novo->valor = soma;
        novo->prox;
    }
}