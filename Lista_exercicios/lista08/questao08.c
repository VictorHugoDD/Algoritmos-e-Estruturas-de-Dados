#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em encontrar o elemento que aparece mais vezes na lista*/ 
  /* A funçao que responde esta questao é a maisRep,
  Analise: Por conta do loop while perceorremos td a 
    lista n vezes ,logo no pior caso temos o tempo O(N²)*/


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

void maisRep(Lista* l){
    if (l == NULL){
        return;
    }
    int maiorRepeticao=0,antCont=0,cont=1;
    Lista *atual=l;
    Lista *proxim=atual->prox;
    while (atual != NULL){
        proxim=atual->prox;
        while (proxim!=NULL){
            if (atual->id == proxim->id){
                cont++;
            }
            proxim=proxim->prox;
        }
        if (antCont < cont){
            antCont = cont;
            maiorRepeticao=atual->id;
        }
        cont=1;
        atual=atual->prox;
    }
    if ((l->id == l->prox->id)  && l->prox !=NULL){ // caso so tenha dois elementos
        printf("O valor que mais se repete é %d com 2 repetiçoes \n ",atual->id);
        return;
    }
    else if(l->prox ==NULL){
        printf("O valor que mais se repete é %d com 1 repeticao\n ",l->id);
        return;

    }

    printf("O elemento que mais se repete e %d com %d repeticoes",maiorRepeticao,antCont);
    
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

    maisRep(l);
    imprimir(l);
    l=liberar(l);

    return 0;
}