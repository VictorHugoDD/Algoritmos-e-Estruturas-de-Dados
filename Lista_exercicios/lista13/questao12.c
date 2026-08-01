#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em: Imprimir o caminho mais longo da raiz até uma folha.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a imprimirCaminhoK,
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

void imprimirCaminhoLongo(ArvoreB* l){
    if (l==NULL){
        return;
    }
    printf(" %d ",l->id);

    int esq=altura(l->esq);
    int dir=altura(l->dir);

    if (esq > dir){
        printf(" -> ");
        imprimirCaminhoLongo(l->esq);
    }
    else if (dir>0){
        printf(" -> ");
        imprimirCaminhoLongo(l->dir);
    }

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

    imprimirCaminhoLongo(r);


    liberarArvore(r);
    r=NULL;
    return 0;
}