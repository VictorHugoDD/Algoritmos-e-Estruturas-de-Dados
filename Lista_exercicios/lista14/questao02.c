#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em Imprimir todos os elementos do nível k.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a imprimirNivelK,
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

void imprimirNivelK(ArvoreB* l,int k, int cont){
    if (l==NULL){
        return;
    }
    if (cont == k){
        printf(" %d -",l->id);
        return;
    }
    imprimirNivelK(l->esq,k,cont+1);
    imprimirNivelK(l->dir,k,cont+1);
    
    return;
    
}


int main(){
    ArvoreB* r=NULL;
    r=inserirArvore(r,25);
    r=inserirArvore(r,16);
    r=inserirArvore(r,29);
    r=inserirArvore(r,27);
    r=inserirArvore(r,54);
    r=inserirArvore(r,24);
    r=inserirArvore(r,3);
    int cont=1;
    imprimirNivelK(r,3,cont);


    liberarArvore(r);
    r=NULL;
    return 0;
}