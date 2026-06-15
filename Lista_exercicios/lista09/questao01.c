#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em Imprimir o elemento central da lista, onde
- se a lista tem tamanho  ́ımpar, isso corresponde ao elemento do meio
- se a lista tem tamanho par, isso corresponde ao  ́ultimo elemento da primeira metade
 A funçao que responde esta questao é a central,
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

void central(Lista* l){
    if(l == NULL){
         return;
    }
    
    Lista* atual=l;
    int meio=0,k=0;

    while (atual!=NULL){
        k++;
        atual=atual->prox;
    }
    atual=l;
    if (k % 2!=0){//impar
        meio=(k+1)/2;
    }
    else{
        meio=k/2;
    }
    while (meio!=0){
        meio--;
        atual=atual->prox;
    }
    printf("ACHAMOS O MEIO %d ",atual->id);
}

void centralOtimizado(Lista* l){
    if(l == NULL){
         return;
    }
    Lista* atual=l;
    int k=1,meio=-1;
    while (atual!=NULL){
        if (atual->prox != NULL && k>=0){
            k++;
            atual=atual->prox;
        }
        else{
            if (k % 2 != 0 && k>=0){
                meio=(k+1)/2;
                meio--;
                k=-1;
            }
            else if (k % 2 == 0 && k>=0){ 
                meio=k/2;
                meio--;
                k=-1;   
            }
            else if (meio>=0){
                atual=atual->ant;
                meio--; 
                if (meio == 0){
                    printf("ACHAMOS O MEIO %d",atual->id);
                    break;
                }
                

            }
            
            
        }
        
        
        
    }
    


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


int main(){
    Lista* l=NULL;
    l=inserir_comeco(2,l);
    l=inserir_comeco(3,l);
    l=inserir_comeco(9,l);
    l=inserir_comeco(0,l);
    l=inserir_comeco(6,l);
    l=inserir_comeco(8,l);

    central(l);
    centralOtimizado(l);
    imprimir(l);
    l=liberar(l);

    return 0;
}