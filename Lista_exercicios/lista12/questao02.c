#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em Imprimir todos os elementos do nível k.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro
 para cima para o no pai.
  Analise: a funçao que resolver essa questao é a ElementosNivelK,
  como o algoritmo percorre td a arvore o temopo é O(n).*/

//Solução baixo nivel

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

void ElementosNivelK(ArvoreNoCima* l,int k){
    if (l ==NULL || k <= 1){
        if (l ==NULL || k ==0){
            return;
        
        }
        else{
            printf(" %d",l->id);
            return;
        }
        
    }
    else{
        int cont=1;
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        while (atual!= NULL){
            if (ant == atual->pai){
                ant= atual;
                if (k == cont){
                    printf(" %d,",atual->id);
                }
                if (atual->esq !=NULL){
                    atual=atual->esq;
                    cont++;
                }
                else if(atual->dir != NULL){
                    atual=atual->dir;
                    cont++;
                }
                else{
                    atual=atual->pai;
                    cont--;
                }
            }
            else if (ant == atual->esq){
                ant=atual;
                if(atual->dir != NULL){
                    atual=atual->dir;
                    cont++;
                }
                else{
                    atual=atual->pai;
                    cont--;
                }
                
            }
            else if (ant == atual->dir){
                ant=atual;
                atual=atual->pai;
                cont--;
            }
            
            
        }
        
    }
    
}

int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(25,r);
    r=inserirNoCima(16,r);
    r=inserirNoCima(32,r);
    r=inserirNoCima(4,r);
    r=inserirNoCima(19,r);
    r=inserirNoCima(27,r);
    r=inserirNoCima(54,r); 
    imprimir(r);
    printf("\n\n\n\n");
    ElementosNivelK(r,3);
    r=liberarArvoreNoCima(r);

    return 0;
}