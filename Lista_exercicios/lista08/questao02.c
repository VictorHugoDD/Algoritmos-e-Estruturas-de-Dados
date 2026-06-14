#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em separar os elementos pares e 
ımpares em listas diferentes*/ 
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

void parImpar(Lista* l){
    if (l==NULL){
        printf("Vazio");
        return;
    }
    Lista *par=NULL;
    Lista *impar=NULL;
    Lista *auxImp=NULL,*auxPar=NULL;
    Lista *atual=l;
    while (atual!=NULL){
        if((atual->id % 2) != 0){ //impar
            if (impar ==NULL){
                impar = atual;
                auxImp=atual;
            }
            else{
                auxImp->prox=atual;
                auxImp=atual;
            }
            
        }
        else if((atual->id % 2) == 0){ //par
            if (par ==NULL){
                par = atual;
                auxPar=atual;
                
            }
            else{
                auxPar->prox=atual;
                auxPar=atual;
            }
            
        }
        
        atual=atual->prox;
     }

    if (auxImp !=NULL){ auxImp -> prox =NULL;}
    if (auxPar !=NULL){ auxPar -> prox =NULL;}
    
     printf("Impar: ");
     imprimir(impar);
     printf("\n");
     printf("\n");
     printf("Par: ");
    imprimir(par);


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
    
    parImpar(l);

    l=liberar(l);

    return 0;
}