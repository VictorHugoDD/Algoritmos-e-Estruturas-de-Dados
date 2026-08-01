#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em: Imprimir os n/2 maiores elementos da árvore.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a imprimirMetadeMaior,
  como o algoritmo percorre td a arvore o tempo é O(n/2).*/

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

int altura(ArvoreB* l){
    if(l==NULL){
        return 0;
    }
    int esq=  altura(l->esq);
    int dir=  altura(l->dir);

    if (esq > dir){
        return 1 + esq;
    }
    

    return 1 + dir;
}

int totalElementos(ArvoreB* l){
    if (l==NULL){
        return 0;
    }

    int esq= totalElementos(l->esq);
    int dir= totalElementos(l->dir);

    return 1 + esq + dir;
    
}

void imprimirMetadeMaior(ArvoreB* l,int n,int* cont){
    if (l==NULL || *cont >= n/2){
        return;
    }
    imprimirMetadeMaior(l->dir,n,cont);

    if (*cont  < n/2){
        printf(" %d -",l->id);
        (*cont)++;
    }

    imprimirMetadeMaior(l->esq,n,cont);
    
}


int main(){
    ArvoreB* r=NULL;
    r=inserirArvore(r,14);
    r=inserirArvore(r,28);
    r=inserirArvore(r,8);
    r=inserirArvore(r,4);
    r=inserirArvore(r,13);
    r=inserirArvore(r,25);
    r=inserirArvore(r,40);
    r=inserirArvore(r,2);
    r=inserirArvore(r,6);
    r=inserirArvore(r,11);
    r=inserirArvore(r,27);
    r=inserirArvore(r,26);
    int n=totalElementos(r);
    int cont=0;
    printf("%d total de elementos. \n",n);
    imprimirMetadeMaior(r,n,&cont);


    liberarArvore(r);
    r=NULL;
    return 0;
}