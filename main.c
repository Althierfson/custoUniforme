#include "arvore.h"


struct lista {
    struct no *no;
    int valor;
    struct lista *prox;
};

struct list * CaminhoUniforme (struct no *arv, struct lista *lista, int destino);
void exibir(struct no *arv);
struct lista * addlista(struct lista *lista, struct no *no);
struct no * Menor(struct lista *lista);

void main (void) {

}

struct list * CaminhoUniforme (struct no *arv, struct lista *lista, int destino){

    if(arv != NULL){

        if(arv->id == destino){
            exibir(arv);
            return lista;
        }else{

            lista = addList(lista, arv->filhos);

            CaminhoUniforme(Menor(lista), lista, destino);
        }
    }

    return lista;
}

struct lista * addlista(struct lista *lista, struct no *no){

    if(no != NULL){
        struct no *ax=no;
        struct lista *pecorrer=lista, *novo;
        int soma=0;

        while(ax->pai != NULL){
            soma = soma + no->valor;
            ax = ax->pai;
        }

        novo = (struct lista*)malloc(sizeof(struct lista));
        novo->no = no;
        novo->valor = soma;
        novo->prox;

        if(pecorrer != NULL){
            lista = novo;
        }else{
            while(pecorrer->prox != NULL){
                pecorrer = pecorrer->prox;   
            }

            pecorrer->prox = novo;
        }

        lista = addList(lista, no->irmaos);
    }

    return lista;
}

struct no * Menor(struct lista *lista){
    struct lista *ax=lista, *menor=lista, *antMenor;
    struct no *pmenor;
    
    while(ax != NULL){

        if(ax->prox->valor < menor->valor){
            menor = ax->prox;
            antMenor = ax;
        }

        ax = ax->prox;
    }

    if(menor == lista){
        pmenor = menor->no;
    }else if(menor->prox != NULL){
        antMenor->prox = menor->prox;
        pmenor = menor->no;
    }else{
        antMenor->prox = NULL;
    }

    free(menor);
    return pmenor;
}