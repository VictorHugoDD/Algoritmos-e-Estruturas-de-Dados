#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em construir uma terceira lista que 
contem todos os elementos que aparecem em ambas as listas*/ 
  /* A funçao que responde esta questao é a intersecao,
  Analise: Por conta do loop while perceorremos td as 
    listas n vezes logo no pior caso temos o tempo O(N²)*/


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

Lista* intersecao(Lista* l1, Lista* l2){
    if (l1 == NULL || l2 == NULL){ // se alguma lista estiver vazia nao tem intersecao
        return NULL;
    }


    Lista *atual=l1;
    Lista *atual2=l2;
    Lista *inter=NULL;
    Lista *auxInter=NULL;

    while (atual != NULL){
        atual2=l2;
        Lista *proximo=atual->prox;
        
        while (atual2 != NULL){
            Lista *proximo2=atual2->prox;
            
            if (atual->id ==atual2->id){
                if (inter == NULL){
                    inter=atual;
                    auxInter=inter;
                }
                else{
                    auxInter->prox=atual;
                    auxInter=atual;
                }
                
                
            }
            atual2=proximo2;
            
        }
        atual=proximo;
    }
    return inter;
    
}

int main(){
    Lista* l=NULL;
    Lista* l2=NULL;
    l=inserir_fim(2,l);
    l=inserir_fim(3,l);
    l=inserir_fim(9,l);
    l=inserir_fim(12,l);
    l=inserir_fim(0,l);
    l=inserir_fim(6,l);
    l=inserir_fim(8,l);

    l2=inserir_fim(1,l2);
    l2=inserir_fim(6,l2);
    l2=inserir_fim(7,l2);
    l2=inserir_fim(2,l2);
    l2=inserir_fim(8,l2);
    l2=inserir_fim(1,l2);

    l=intersecao(l,l2);
    imprimir(l);
    l=liberar(l);
    l2=liberar(l2);

    return 0;
}