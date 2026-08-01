#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em: Encontrar a menor folha ímpar da árvore.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a menorFolhaImpar,
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

int menorFolhaImpar(ArvoreB* l){
    if (l==NULL){
        return -1;
    }
    
    if (l->esq == NULL && l->dir == NULL){
        if (l->id % 2 !=0){
            return l->id;
        }
        return -1;
        
    }
    int esq=menorFolhaImpar(l->esq);
    int dir=menorFolhaImpar(l->dir);

    if (esq == -1 && dir == -1){
        return -1; // nao ha impar folha
    }
    else if (esq == -1){
        return dir;
    }
    else if (dir == -1){
        return esq;
    }
    
    return esq < dir ? esq : dir;
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

    int impar=menorFolhaImpar(r);
    if (impar > 0){
        printf(" %d eh o menor impar folha\n",impar);    
    }
    else{
        printf(" Nao existe menor impar folha ");
    }
    


    liberarArvore(r);
    r=NULL;
    return 0;
}