#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k: Encontrar o maior elemento do nível k.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a maiorElementoNivelK,
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

int maiorElementoNivelK(ArvoreB* l,int nivel,int cont){
    if (l==NULL){
        return 0;
    }

    if (nivel == cont){
        return l->id;
    }
    int esq=maiorElementoNivelK(l->esq,nivel,cont+1);
    int dir=maiorElementoNivelK(l->dir,nivel,cont+1);
    return esq > dir ? esq : dir ;
    
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
    r=inserirArvore(r,35);
    r=inserirArvore(r,45);
    int k=3;
    int cont=maiorElementoNivelK(r,k,1); //assumimos que a raiz é nivel 1
    printf(" %d eh o maior no do nivel %d. \n",cont,k);


    liberarArvore(r);
    r=NULL;
    return 0;
}