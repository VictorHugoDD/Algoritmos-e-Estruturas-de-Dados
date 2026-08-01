#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k:
→ Contar a quantidade de elementos ímpares maiores do que k.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a contarImparMaiorK,
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

int contarImparMaiorK(ArvoreB* l,int k,int cont){
    if (l==NULL){
        return cont;
    }

    if (l->id > k){
        if (l->id % 2 !=0){ //impar
            cont++;
        }
        cont=contarImparMaiorK(l->esq,k,cont);
        cont= contarImparMaiorK(l->dir,k,cont);
        
    }
    else{
        cont=contarImparMaiorK(l->dir,k,cont);
    }
    

    return cont;

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

    int cont=contarImparMaiorK(r,20,0);
    printf("%d vezes",cont);

    liberarArvore(r);
    r=NULL;
    return 0;
}