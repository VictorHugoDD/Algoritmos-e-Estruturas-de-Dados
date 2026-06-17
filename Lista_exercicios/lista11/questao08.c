#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em Combinar os elementos de p1 e p2 em uma única lista encadeada ordenada.
  Analise: Por conta do loop while perceorremos td a 
    lista uma vezes logo no pior caso temos o tempo O(N)*/


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


Lista* inserir_comeco(int id,Lista* l){
    Lista* nv=criarLista(id);

    if(l == NULL){
         return nv;
    }
    nv->prox=l;
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

Lista* intercalar(Lista* l1,Lista* l2){
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

    Lista *l3=NULL,*aux=NULL;
    if (l1->id < l2->id){
        if (l3 == NULL){
            l3=l1;
            aux=l3;
            aux->prox=intercalar(l1->prox,l2);
        }
        
    }
    else{
        if (l3 == NULL){
            l3=l2;
            aux=l3;
            aux->prox=intercalar(l1,l2->prox);

        }
        
    }
    return l3;
}



int main(){
    Lista* l1=NULL;
    Lista* l2=NULL;
    l1=inserir_fim(0,l1);
    l1=inserir_fim(2,l1);
    l1=inserir_fim(3,l1);
    l1=inserir_fim(6,l1);
    l1=inserir_fim(8,l1);
    l1=inserir_fim(9,l1);
    imprimir(l1);

    l2=inserir_fim(0,l2);
    l2=inserir_fim(1,l2);
    l2=inserir_fim(3,l2);
    l2=inserir_fim(4,l2);
    l2=inserir_fim(7,l2);
    l2=inserir_fim(10,l2);
    imprimir(l2);

    l1=intercalar(l1,l2);
    imprimir(l1);




    l1=liberar(l1);

    return 0;
}