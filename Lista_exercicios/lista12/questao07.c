#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em Imprimir todos os elementos que estão tanto em p1 como em p2.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro para cima para o no pai.
  Analise: a funçao que resolver essa questao é a intersecao,
  como o algoritmo percorre td a arvore1 n vezes e percorre a arvore2 em log(m), o tempo é O(n log m).*/

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

void buscar(ArvoreNoCima* l,int k){
    if (l==NULL){
        printf("Vazio");
        return;
    }
    else{
        ArvoreNoCima* atual=l;

        while (atual!=NULL){
            if (atual->id==k){
                printf(" - %d",atual->id);
                return;
            }
            
            if (atual->id< k){
                atual=atual->dir;
            }
            else if(atual->id> k){
                atual=atual->esq;
            }
            
            
        }
    }
    

}


void intersecao(ArvoreNoCima* p1,ArvoreNoCima* p2){
    if (p1==NULL || p2== NULL){
        printf("Vazio");
    }
    else{
        ArvoreNoCima* atual1=p1;
        ArvoreNoCima* ant1=NULL;

        while (atual1!=NULL){
            if (ant1==atual1->pai){
                ant1=atual1;
                buscar(p2,atual1->id);
                if(atual1->esq!=NULL){
                    atual1=atual1->esq;
                }
                else if(atual1->dir!=NULL){
                    atual1=atual1->dir;
                }
                else{
                    atual1=atual1->pai;
                }
                

            }
            else if(ant1==atual1->esq){
                ant1=atual1;
                if (atual1->dir!=NULL){
                    atual1=atual1->dir;
                }
                else{
                    atual1=atual1->pai;
                }
                

            }
            else if (ant1==atual1->dir){
                ant1=atual1;
                atual1=atual1->pai;
                
            }
            
              
                
        }


    }    


}

int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(5,r);
    r=inserirNoCima(3,r);
    r=inserirNoCima(8,r);
    r=inserirNoCima(1,r);
    r=inserirNoCima(4,r);
    r=inserirNoCima(7,r);
    r=inserirNoCima(9,r);
    imprimir(r);
    printf("\n");
    ArvoreNoCima* r2=NULL;
    r2=inserirNoCima(6,r2);
    r2=inserirNoCima(2,r2);
    r2=inserirNoCima(9,r2);
    r2=inserirNoCima(1,r2);
    r2=inserirNoCima(5,r2);
    r2=inserirNoCima(8,r2);
    r2=inserirNoCima(11,r2);
    imprimir(r2); 
    printf("\n"); 
    intersecao(r,r2);

    r=liberarArvoreNoCima(r);

    return 0;
}