#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Dizemos que um nível está completo quando contém todos os 2^(k−1) nós possíveis.
A tarefa consiste em, dado um número k: Verificar se o nível k da árvore está completo.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a verificarNivelK,
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

int contNivelK(ArvoreB* l,int nivel,int cont){
    if (l==NULL){
        return 0;
    }

    if (nivel == cont){
        return 1;
    }

    return contNivelK(l->esq,nivel,cont+1) + contNivelK(l->dir,nivel,cont+1);
    
}

void verificarNivelK(ArvoreB* l, int nivel,int raiz){
    int cont =contNivelK(l,nivel,raiz);
    int cal=pow(2,nivel-1);
    if (cal==cont){
        printf("O nivel esta completo com %d nos",cal);
        return;
    }
    
    printf("O nivel nao esta completo");
    return;
    

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
    int k=4;
    int cont=contNivelK(r,k,1); //assumimos que a raiz é nivel 1
    printf(" %d quantidade de nos no nivel %d. \n",cont,k);
    verificarNivelK(r,k,1);


    liberarArvore(r);
    r=NULL;
    return 0;
}