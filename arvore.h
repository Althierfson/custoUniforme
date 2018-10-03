#include <stdio.h>
#include <stdlib.h>

struct no{
    int id;
    int valor;
    struct no *pai;
    struct no *filhos;
    struct no *irmaos;
};

struct no * criarArv(struct no *arv, int id){
    arv = (struct no*)malloc(sizeof(struct no));
    arv->id = id;
    arv->valor = 0;
    arv->pai = NULL;
    arv->filhos = NULL;
    arv->irmaos = NULL;

    return arv;
}

void inserir (struct no *arv, int id, int idPai, int valor) {

    if(arv != NULL){

        inserir(arv->filhos, id, idPai, valor);
        inserir(arv->irmaos, id, idPai, valor);

        if(arv->id == idPai){
            struct no *novo = (struct no*)malloc(sizeof(struct no));
            novo->id = id;
            novo->valor = valor;
            novo->pai = arv;
            novo->filhos = NULL;
            novo->irmaos = NULL;

            if(arv->filhos == NULL){
                arv->filhos = novo;
            }else{
                struct no *lista = arv->filhos;

                while(lista->irmaos != NULL){
                    lista = lista->irmaos;
                }

                lista->irmaos = novo;
            }
        }
    }

}