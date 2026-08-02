#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k, Mover o elemento k para a raiz da árvore.
vamos fazer de forma recursiva
  Analise: a funçao que resolver essa questao é a kRaiz,
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
    printf("%d ", l->id);
    imprimir(l->esq);    
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

ArvoreB* menor(ArvoreB* l){
    if (l==NULL){
        return NULL;
    }

    if(l->esq != NULL){
        return menor(l->esq);
    }
    
    return l;
}



ArvoreB* remover(ArvoreB* l,int x){
    if (l==NULL){
        return l;
    }
    if (x>l->id){
        l->dir=remover(l->dir,x);
    }
    if (x<l->id){
        l->esq=remover(l->esq,x);
    }
    if (x== l->id){
        if(l->esq == NULL && l->dir ==NULL){
            free(l);
            return NULL;
        }
        if(l->esq != NULL && l->dir ==NULL){
            ArvoreB* aux=l->esq;
            free(l);
            return aux;
        }
        if(l->esq == NULL && l->dir !=NULL){
            ArvoreB* aux=l->dir;
            free(l);
            return aux;
        }
        if(l->esq != NULL && l->dir !=NULL){
            ArvoreB* aux=menor(l->dir);
            l->id=aux->id;
            l->dir=remover(l->dir,aux->id);
        }
        

    }
    
    return l;
    
}

ArvoreB* atualizacao(ArvoreB* l,int x, int y){
    l=remover(l,x);
    l=inserirArvore(l,y);
    return l;
}

ArvoreB* rotacaoEsq(ArvoreB* l){
    if (l==NULL || l->dir==NULL){
        return l;
    }

    ArvoreB* y=l->dir;
    ArvoreB* x=y->esq;

    l->dir=x;
    y->esq=l;
    
    return y;
}

ArvoreB* rotacaoDir(ArvoreB* l){
    if (l==NULL || l->esq == NULL){
        return l;
    }

    ArvoreB* y=l->esq;
    ArvoreB* x=y->dir;
 
    l->esq=x;
    y->dir=l;

    return y;
}

ArvoreB* eliminarFilhosUnicos(ArvoreB* l){
    if (l==NULL){
        return l;
    }
    l->esq = eliminarFilhosUnicos(l->esq);
    l->dir = eliminarFilhosUnicos(l->dir);
    if (l->esq != NULL && l->esq->esq != NULL && l->dir == NULL){

        l= rotacaoDir(l);
        
    }
    else if (l->dir != NULL && l->dir->dir != NULL && l->esq == NULL){
        
        l=rotacaoEsq(l);
    }
    return l;
    
}



int main(){
    ArvoreB* r=NULL;
    r=inserirArvore(r,9);
    r=inserirArvore(r,17);
    r=inserirArvore(r,5);
    r=inserirArvore(r,2);
    r=inserirArvore(r,1);
    r=inserirArvore(r,10);
    imprimir(r);
    printf("\n");
    r=eliminarFilhosUnicos(r);
    imprimir(r);


    liberarArvore(r);
    r=NULL;
    return 0;
}