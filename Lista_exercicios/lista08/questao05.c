#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em combinar os elementos das duas listas 
para produzir uma  ́unica lista ordenada. Detalhe: as listas estao ordenadas*/ 
  /* A funçao que responde esta questao é a intercalacao,
  Analise: Por conta do loop while perceorremos td a 
    lista como temos 2 listas no pior caso temos o tempo 2O(N)*/


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

Lista* intercalacao(Lista* l1,Lista* l2){
    if (l1 ==NULL || l2 ==NULL){
        if(l1 == NULL && l2 == NULL){
            printf("vazio\n");
            return NULL;
        }
        else if(l1 == NULL && l2 != NULL){
            printf("l1 vazio\n");
            return l2;
        }
        else if(l1 != NULL && l2 == NULL){
            printf("l2 vazio\n");
            return l1;
        }
        
    }
    Lista *nv=NULL;
    Lista *atual=l1;
    Lista *atual2=l2;
    
    if (l1->id < l2->id){
        nv=l1;
        atual=l1->prox;
    }
    else{
        nv=l2;
        atual=l2->prox;
    }
    Lista *auxNv=nv; //Sera usado para percorrer a lista auxiliar
    

    while (atual!=NULL && atual2 != NULL){
        if (atual->id < atual2->id){
            auxNv->prox=atual;
            auxNv=atual;                 
            atual=atual->prox;
        }
        else{
            auxNv->prox=atual2;
            auxNv=atual2;
            atual2=atual2->prox;
        }

    }

    while (atual !=NULL){ 
        auxNv->prox=atual;
            auxNv=atual;
        atual=atual->prox;
    }
    while (atual2 !=NULL){
        auxNv->prox=atual2;
        auxNv=atual2;
        atual2=atual2->prox;
    }
    return nv;

}



int main(){
    Lista* l=NULL;
    Lista* l2=NULL;
    l=inserir_fim(2,l);
    l=inserir_fim(3,l);
    l=inserir_fim(6,l);
    l=inserir_fim(8,l);
    l2=inserir_fim(4,l2);
    l2=inserir_fim(5,l2);
    l2=inserir_fim(7,l2);
    l2=inserir_fim(9,l2);

    l=intercalacao(l,l2);
    imprimir(l);
    l=liberar(l);
    l2=liberar(l2);

    return 0;
}