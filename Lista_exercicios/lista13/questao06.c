#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em: Contar o número de folhas ímpares na árvore.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a contFolhasImpar,
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

int contFolhasImpar(ArvoreB* l,int k){
    if (l==NULL){
        return k;
    }
    
    k=contFolhasImpar(l->esq,k);
    k=contFolhasImpar(l->dir,k);

    if (l->esq == NULL && l->dir == NULL){
        if (l->id % 2 != 0){
            k++;
        }
        
    }

    return k;
    
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
    int cont=contFolhasImpar(r,0);
    printf(" %d quantidade de nos folhas impares. \n",cont);


    liberarArvore(r);
    r=NULL;
    return 0;
}