#include <stdio.h>
#include <stdlib.h>

/*A operacao de varredura consiste em
- percorrer a lista da esquerda para a direita
- trocando o elemento atual de posicao com o proximo, quando este é maior do que aquele
 A funçao que responde esta questao é a varreduraOrd e a funcao troca,
  Analise: Por conta do loop while perceorremos td a 
    lista uma vezes logo no pior caso temos o tempo O(N)*/


typedef struct Lista{
    int id;
    struct Lista *prox;
    struct Lista *ant;
}Lista;

Lista* criarLista(int id){
    Lista* nv=(Lista*) malloc(sizeof(Lista));
    nv->id=id;
    nv->ant=NULL;
    nv->prox=NULL;
    return nv;
}


Lista* inserir_comeco(int id,Lista* l){
    Lista* nv=criarLista(id);

    if(l == NULL){
         return nv;
    }
    nv->prox=l;
    l->ant=nv;
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
    nv->ant=aux;

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

Lista* troca(Lista* l1,Lista* l2){
    Lista* anterior=l1->ant;
    Lista* proximo=l2->prox;

    l2->prox=l1;
    l2->ant=anterior;
    l1->prox=proximo;
    l1->ant=l2;

    if(anterior != NULL){
        anterior->prox=l2;
    }
     if(proximo != NULL){
        proximo->ant=l1;
    }
    
return l2;
}

Lista* varreduraOrd(Lista* l){
    if (l== NULL || l->prox ==NULL){
        return l;
    }

    Lista* atual=l;
    Lista* proximo=NULL;
    while (atual->prox != NULL){
        proximo=atual->prox;
        if(atual->id>proximo->id){
            if(atual ==l){
                l=troca(atual,proximo);
            }
            else{
                atual=troca(atual,proximo);
                atual=atual->ant;
            }
        }
        atual=atual->prox;
    }    
return l;
}


int main(){
    Lista* l=NULL;
    l=inserir_comeco(6,l);
    l=inserir_comeco(9,l);
    l=inserir_comeco(2,l);
    l=inserir_comeco(0,l);
    l=inserir_comeco(8,l);
    l=inserir_comeco(3,l);
    l=varreduraOrd(l);
    imprimir(l);
    l=liberar(l);

    return 0;
}