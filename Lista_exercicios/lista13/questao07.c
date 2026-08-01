#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k: Contar o número de elementos ímpares no nível k.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a contImparNivelK,
  como o algoritmo percorre a arvore ate nivel k o tempo é O(2^k).*/

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

int contImparNivelK(ArvoreB* l,int k,int cont){
    if (l==NULL){
        return 0;
    }

    if (cont==k){
        if (l->id % 2 != 0){
            return 1;
            
        }
        return 0;

    }
    else if ( cont < k){
        return contImparNivelK(l->esq,k,cont + 1) + contImparNivelK(l->dir,k,cont+1);
    }
    
    return 0;
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
    int k=4,j=1;
    int cont=contImparNivelK(r,k,j);
    printf(" %d quantidade de nos impares no nivel %d. \n",cont, k);


    liberarArvore(r);
    r=NULL;
    return 0;
}