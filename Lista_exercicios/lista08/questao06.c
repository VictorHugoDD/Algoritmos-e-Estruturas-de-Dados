#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um numero k mover os elementos ≤ k para o inicio da lista
e mover os elementos > k para o final da lista*/ 
  /* A funçao que responde esta questao é a particionar,
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

Lista* particionar(Lista* l,int k){
    if(l==NULL){
        return l;
    }

    Lista *atual=l;
    Lista *menor=NULL;
    Lista *auxMenor=NULL;
    Lista *maior=NULL;
    Lista *auxMaior=NULL;

    while (atual!=NULL){
        Lista *prox=atual->prox;
        atual->prox=NULL;

        if(atual->id > k){
            if(maior == NULL){
                maior=atual;
                auxMaior=maior;
            }
            else{
                auxMaior->prox=atual;
                auxMaior=atual;

            }

        }
        else{
            if(menor == NULL){
                menor=atual;
                auxMenor=menor;
            }
            else{
                auxMenor->prox=atual;
                auxMenor=atual;

            }
        }
        atual=prox;

    }
    if (menor == NULL){
        return maior;
    }
    else{
    
    auxMenor->prox=maior;
    return menor;
    }
}



int main(){
    Lista* l=NULL;
    l=inserir_fim(12,l);
    l=inserir_fim(7,l);
    l=inserir_fim(4,l);
    l=inserir_fim(15,l);
    l=inserir_fim(8,l);
    l=inserir_fim(9,l);
    l=inserir_fim(3,l);
    l=inserir_fim(6,l);

    l=particionar(l,5);
    imprimir(l);
    l=liberar(l);

    return 0;
}