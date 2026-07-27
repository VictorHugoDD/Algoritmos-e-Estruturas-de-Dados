#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em Imprimir o k-ésimo maior elemento da árvore.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro para cima para o no pai.
  Analise: a funçao que resolver essa questao é a kMaiorElemento,
  como o algoritmo percorre td a arvore n vezes o tempo é O(n).*/

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

void kMaiorElemento(ArvoreNoCima* l,int k){
    if (l==NULL || k==0){
        printf("Vazio");
    }
    else{
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        int cont=0;
        while (atual!=NULL){
            if(ant== atual->pai){
                ant=atual;
                if (atual->dir!=NULL){
                    atual=atual->dir;
                }
                else{
                    cont++;
                    if(cont == k){
                        printf("-%d eh o %d-esimo elemento.",atual->id,cont);
                        return;
                    }

                    if(atual->esq!=NULL){
                        ant=atual;
                        atual= atual->esq;

                    }
                    else{
                        ant=atual;
                        atual=atual->pai;
                    }
                }
                
            }
            else if(ant==atual->dir){
                cont++;
                if (cont == k){
                  printf("-%d eh o %d-esimo elemento.",atual->id,cont);
                  return;  
                }
                
                if(atual->esq!=NULL){
                    ant=atual;
                    atual= atual->esq;
                }
                else{
                    ant=atual;
                    atual=atual->pai;
                }
            }
            else if (ant==atual->esq){
                ant=atual;
                atual=atual->pai;
            }
            
            
        }
        
    printf("Nao existe %d-esimo elemento.",k);
    }
    
}



int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(13,r);
    r=inserirNoCima(20,r);
    r=inserirNoCima(5,r);
    r=inserirNoCima(31,r);
    r=inserirNoCima(15,r);
    r=inserirNoCima(2,r);
    r=inserirNoCima(6,r);
    imprimir(r);
    printf("\n");
    kMaiorElemento(r,5);

    r=liberarArvoreNoCima(r);

    return 0;
}