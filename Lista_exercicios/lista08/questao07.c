#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em remover da lista todas as copias de um certo elemento k*/ 
  /* A funçao que responde esta questao é a delCopia,
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

Lista* delCopia(Lista* l,int k){
    if (l == NULL){
        return l;
    }

    Lista *atual=l;
    Lista *aux=NULL;
    Lista *ant=NULL;
    while(atual!=NULL){
        if(atual->id == k){
            if (atual == l){
                aux=l->prox;
                free(l);
                l=aux;
                atual=l;
            }
            else{
                aux=atual;
                ant->prox=atual->prox;
                atual=atual->prox;
                free(aux);

            }
            
        }else{
            
            ant=atual;
            atual=atual->prox;
            
        }
        
        
    }
    return l;

    
}

int main(){
    Lista* l=NULL;
    l=inserir_fim(1,l);
    l=inserir_fim(7,l);
    l=inserir_fim(4,l);
    l=inserir_fim(7,l);
    l=inserir_fim(7,l);
    l=inserir_fim(9,l);
    l=inserir_fim(3,l);
    l=inserir_fim(6,l);

    l=delCopia(l,7);
    imprimir(l);
    l=liberar(l);

    return 0;
}