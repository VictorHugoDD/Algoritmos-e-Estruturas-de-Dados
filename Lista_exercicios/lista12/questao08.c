#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k: Verificar se existe um par de elementos na 
árvore cuja soma seja exatamente igual a k.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro para cima para o no pai.
  Analise: a funçao que resolver essa questao é a parSoma,
  como o algoritmo percorre td a arvore o tempo é O(n).*/

typedef struct ArvoreNoCima{
    int id;
    struct ArvoreNoCima *pai;
    struct ArvoreNoCima *dir;
    struct ArvoreNoCima *esq;
}ArvoreNoCima;

ArvoreNoCima* criarArvoreNoCima(int id){
    ArvoreNoCima* nv=(ArvoreNoCima*) malloc(sizeof(ArvoreNoCima));
    nv->id=id;
    nv->esq=NULL;
    nv->dir=NULL;
    nv->pai=NULL;
    return nv;   
}

ArvoreNoCima* inserirNoCima(int id, ArvoreNoCima* l){
    ArvoreNoCima* nv=criarArvoreNoCima(id);
    if(l == NULL){
         return nv;
    }
    else{
        ArvoreNoCima* atual=l;

        while (atual!= NULL){
            if (id<atual->id){
                if (atual->esq == NULL){
                    atual->esq=nv;
                    nv->pai=atual;
                    return l;
                }
                else{
                    atual=atual->esq;
                }
                
            }
            else{
                if (atual->dir == NULL){
                    atual->dir=nv;
                    nv->pai=atual;
                    return l;
                }
                else{
                    atual=atual->dir;
                }

            }
            
        }
        

    }
    return l;


}

ArvoreNoCima* liberarArvoreNoCima(ArvoreNoCima* l){
    if (l == NULL){
        return l;
    }
    else{
        ArvoreNoCima* atual=l;
        ArvoreNoCima* pai=NULL;

        while (atual!= NULL){
            if (atual->esq != NULL){
                atual=atual->esq;
            }
            else if (atual->dir != NULL){
                atual=atual->dir;
            }
            else{
                pai=atual->pai;
                if (pai != NULL){
                    if (pai->esq == atual) {
                        pai->esq = NULL;
                    } 
                    else if (pai->dir == atual) {
                        pai->dir = NULL;
                    }
                
                }
                free(atual);
                atual=pai;
            
            }   
        }
        
        
    }
    return NULL;
    
}

void imprimir(ArvoreNoCima* l){
    if (l == NULL){
        return;
    }
    else{
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        while (atual!=NULL){
            if (ant==atual->pai){
                
                printf("%d ", atual->id);
                ant=atual;
                if (atual->esq != NULL){
                    atual=atual->esq;
                }
                else if (atual->dir != NULL){
                    atual=atual->dir;
                }
                else{
                    atual=atual->pai;
                }
                
            }
            else if (ant==atual->esq){
                ant=atual;
                if (atual->dir!=NULL){
                    atual=atual->dir;
                }
                else{
                    atual=atual->pai;
                }
                
            }
            else if (ant==atual->dir){
                ant=atual;
                atual=atual->pai;
            }
            
            
        }
        return;

        
    }

}

ArvoreNoCima* buscar(ArvoreNoCima* l,int k){
    if (l==NULL){
        return NULL;
    }
    else{
        ArvoreNoCima* atual=l;

        while (atual!=NULL){
            if (atual->id==k){
                return atual;
            }
            
            if (atual->id< k){
                atual=atual->dir;
            }
            else if(atual->id> k){
                atual=atual->esq;
            }
            
            
        }
    }
    return NULL;


}

void parSoma(ArvoreNoCima* l,int k){
    if (l==NULL){
        return;
    }
    else{
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        while (atual!=NULL){
            if (ant==atual->pai){
                ant=atual;
                int resto=k-atual->id;
                ArvoreNoCima* aux=buscar(l,resto);
                if (aux != NULL){
                    int soma=atual->id+aux->id;
                    if (soma==k){
                        printf("Achei %d + %d = %d. ",atual->id,aux->id,k);
                        return;
                    }
                }
                
                
                if (atual->esq!=NULL){
                    atual=atual->esq;
                }
                else if (atual->dir!=NULL){
                    atual=atual->dir; 
                }
                else{
                    atual=atual->pai;
                }
                
            }
            else if (ant==atual->esq){
                ant=atual;
                if (atual->dir!=NULL){
                    atual=atual->dir;
                }
                else{
                    atual=atual->pai;
                }
                
            }
            else if (ant==atual->dir){
                ant=atual;
                atual=atual->pai;
            }
        }
        printf("NAO");
        return;
        
    }
    
}



int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(13,r);
    r=inserirNoCima(5,r);
    r=inserirNoCima(20,r);
    r=inserirNoCima(2,r);
    r=inserirNoCima(6,r);
    r=inserirNoCima(15,r);
    r=inserirNoCima(31,r);
    imprimir(r);
    printf("\n");
    parSoma(r,16);

    r=liberarArvoreNoCima(r);

    return 0;
}