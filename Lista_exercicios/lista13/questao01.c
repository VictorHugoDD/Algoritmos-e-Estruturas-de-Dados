#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dados os números k e l:
 Imprimir todos os elementos maiores que k e menores que l.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a imprimirIntervalo,
  como o algoritmo percorre td a arvore o tempo é O(n).*/

typedef struct ArvoreB{
    int id;
    struct ArvoreB *dir;
    struct ArvoreB *esq;
}ArvoreB;

ArvoreB* criarArvoreB(int id){
    ArvoreB* nv=(ArvoreB*) malloc(sizeof(ArvoreB));
    nv->id=id;
    nv->esq=NULL;
    nv->dir=NULL;
    return nv;   
}

ArvoreB* inserirArvore(ArvoreB* l,int id){
    if (l==NULL){
        return criarArvoreB(id);
    }
    
    if (id< l->id){
        l->esq = inserirArvore(l->esq,id);
    }
    else{
        l->dir=inserirArvore(l->dir,id);
    }

    return l;
    
    
}

void imprimir(ArvoreB* l){
    if (l==NULL){
        return;
    }
    imprimir(l->esq);    
    printf("%d ", l->id);
    imprimir(l->dir);

}

void liberarArvore(ArvoreB* l){
    if (l == NULL){
        return;
    }

    liberarArvore(l->esq);
    liberarArvore(l->dir);
    free(l);
}

void imprimirIntervalo(ArvoreB* l,int k,int b){
    if (l==NULL){
        return;
    }

    if (l->id>k && l->id<b){
        printf("%d ",l->id);
        imprimirIntervalo(l->esq,k,b);
        imprimirIntervalo(l->dir,k,b);
    }
    else if (l->id<=k){
        imprimirIntervalo(l->dir,k,b);
    }
    else if (l->id>=b){
        imprimirIntervalo(l->esq,k,b);
    }
    
    return;

}


int main(){
    ArvoreB* r=NULL;
    r=inserirArvore(r,11);
    r=inserirArvore(r,20);
    r=inserirArvore(r,9);
    r=inserirArvore(r,10);
    r=inserirArvore(r,3);
    r=inserirArvore(r,15);
    r=inserirArvore(r,8);

    imprimirIntervalo(r,8,17);

    liberarArvore(r);
    r=NULL;
    return 0;
}