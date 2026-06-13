#include <stdio.h>
#include <stdlib.h>

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

void imprimir(Lista *l){

    Lista* aux = l;
    int i=0;
    while (aux!=NULL){
        printf("No %d: %d\n",++i,aux->id);
        aux=aux->prox;
    }
}

Lista* maiorFinal01(Lista *l){

    /*Por conta do loop while perceorremos td a 
    lista logo no pior caso temo o tempo O(N)*/

    Lista *atual=l;
    Lista *antAtual=NULL;
    Lista *maior=atual;
    Lista *antMaior=NULL;

    while(atual!=NULL){
        if (atual->id > maior->id){
            maior=atual;
            antMaior=antAtual;
        }

        antAtual=atual;
        atual=atual->prox;
        
    }
    
    if(antMaior!= NULL){
        antMaior->prox=maior->prox;
        maior->prox=NULL;
    }
    if (antAtual !=NULL){
        antAtual->prox=maior;
    }
    
     
    return l;
    
}

Lista* maiorFinal(Lista *l){

    /*Por conta do loop while perceorremos td a 
    lista logo no pior caso temo o tempo O(N)*/

    if (l==NULL || l->prox==NULL){
        return l;
    }

    Lista *atual=l->prox;
    Lista *antAtual=l;
    Lista *maior=l;
    Lista *antMaior=NULL;
    Lista *fim=NULL;

    while(atual!=NULL){
        if (atual->id > maior->id){
            maior=atual;
            antMaior=antAtual;
        }
        if(atual->prox == NULL){
            fim=atual;
        }

        antAtual=atual;
        atual=atual->prox;
        
    }
    
    if(antMaior== NULL){
        Lista *aux=maior->prox;
        maior->prox=NULL;
        fim->prox=maior;
        return aux;
    }
    if (maior ==fim){
        return l;
    }
    antMaior->prox=maior->prox;
    fim->prox=maior;
    maior->prox=NULL;
    
     
    return l;
    
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

    imprimir(l);
    printf("\n");
    l=maiorFinal(l);
    printf("\n");
    imprimir(l);


    return 0;
}