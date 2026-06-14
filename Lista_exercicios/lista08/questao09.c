#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em determinar se a lista contem algum elemento repetido ou nao*/ 
  /* A funçao que responde esta questao é a repetido,
  Analise: Por conta do loop while perceorremos td a 
    lista n vezes logo no pior caso temos o tempo O(N²)*/


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

void repetido(Lista* l){
    if (l == NULL){
        return;
    }
    int cont =0 ;
    Lista *atual=l;
    Lista *proxim=NULL;

    while (atual!=NULL){
        proxim=atual->prox;
        while (proxim!=NULL){
            if (atual->id == proxim->id){
                cont++;
            }
            proxim=proxim->prox;
            
        }

        if (cont>0){
            printf("Tem elementos repetidos");
            break;
        }
        cont=0;
        atual=atual->prox;
    }
    return;
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

    repetido(l);
    imprimir(l);
    l=liberar(l);

    return 0;
}