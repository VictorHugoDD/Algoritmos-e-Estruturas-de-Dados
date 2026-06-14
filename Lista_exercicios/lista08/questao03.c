#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em inverter a ordem dos elementos da listas*/ 
  /* A funçao que responde esta questao é a parImpar,
  Analise: Por conta do loop while perceorremos td a 
    lista logo no pior caso temos o tempo O(N)*/


typedef struct Lista{
    int id;
    struct Lista *prox;
}Lista;

Lista* criarLista(int id){
    Lista* nv=(Lista*) malloc(sizeof(Lista));
    nv->id=id;
    nv->prox=NULL;
    return nv;
}

Lista* inserir_fim(int id,Lista* l){
    Lista* nv=criarLista(id);

    if(l == NULL){
         return nv;
    }
    Lista* aux=l;

    while(aux->prox != NULL){
       aux=aux->prox;
    }
    aux->prox=nv;

    return l;
}

Lista* liberar(Lista* l){
    Lista *aux=l;
    while (aux!=NULL){
        Lista *proximo = aux->prox; // Guarda a referência do próximo nó
        free(aux);                  // Libera o nó atual com segurança
        aux = proximo;
    }
    return NULL;
    
}

void imprimir(Lista *l){
    Lista* aux = l;
    int i=0;
    while (aux!=NULL){
        printf("No %d: %d\n",++i,aux->id);
        aux=aux->prox;
    }
}

Lista* inverterOrdem(Lista *l){
    Lista *atual=l;
    Lista *ant=NULL;
    Lista *proxim=NULL;
    
    while (atual!=NULL){
        proxim=atual->prox;
        atual->prox=ant;
        ant=atual;
        atual=proxim;
        
    }
    l=ant;
    imprimir(l);
    return l;
    

}



int main(){
    Lista* l=NULL;
    l=inserir_fim(13,l);
    l=inserir_fim(2,l);
    l=inserir_fim(6,l);
    l=inserir_fim(1,l);
    l=inserir_fim(15,l);
    l=inserir_fim(11,l);
    l=inserir_fim(9,l);

    l=inverterOrdem(l);

    l=liberar(l);

    return 0;
}