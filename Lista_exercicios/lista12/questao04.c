#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k: Remover todas as cópias do elemento k da árvore.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro para cima para o no pai.
  Analise: a funçao que resolver essa questao é a removerCopias,
  como o algoritmo percorre td a arvore n vezes o tempo é O(n²) no pior caso.*/

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

ArvoreNoCima* menorElemento(ArvoreNoCima* l){
    if (l== NULL){
        return NULL;
    }
    else{
        ArvoreNoCima* atual=l;
        while (atual->esq != NULL){
            atual=atual->esq;
        }

        return atual;
    }
    
}

ArvoreNoCima* remover(ArvoreNoCima* l,int k){
    if (l==NULL){
        return NULL;
    }
    else{
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        while (atual != NULL && atual->id!=k){
            ant=atual;
            if (atual->id<k){
                atual=atual->dir;
            }
            else{
                atual=atual->esq;
            }
            
        }
        if (atual == NULL){
            return l;
        }

        //caso tenha 2 filhos
        if (atual->dir != NULL && atual->esq != NULL){
            ArvoreNoCima* temp=menorElemento(atual->dir);
            atual->id=temp->id;
            ArvoreNoCima* paiTemp=temp->pai;
            if (paiTemp->esq == temp){
                paiTemp->esq=temp->dir;
            }
            else{
                paiTemp->dir=temp->dir;
            }
            if (temp->dir!=NULL){
                temp->dir->pai=paiTemp;
            }

            free(temp);
            return l;
            
        }
        else if (atual->dir != NULL || atual->esq != NULL){ //caso tenha 1 filhos
            if (ant==NULL){ // seja raiz
                if (atual->dir!=NULL){
                    ArvoreNoCima* temp=atual->dir;
                    atual->dir=NULL;
                    temp->pai=NULL;
                    free(atual);
                    return temp;
                    
                }
                else{
                    ArvoreNoCima* temp=atual->esq;
                    atual->esq=NULL;
                    temp->pai=NULL;
                    free(atual);
                    return temp;

                }
            }
            else{
                if (atual->dir!=NULL){
                    ArvoreNoCima* temp=atual->dir;

                    if (ant->dir==atual){
                        ant->dir=temp;
                        temp->pai=ant;
                        atual->dir=NULL;
                        free(atual);
                        return l;
                    }
                    else{
                        ant->esq=temp;
                        temp->pai=ant;
                        atual->dir=NULL;
                        free(atual);
                        return l;

                    }
                    
                }
                else{
                    ArvoreNoCima* temp=atual->esq;

                    if (ant->dir==atual){
                        ant->dir=temp;
                        temp->pai=ant;
                        atual->esq=NULL;
                        free(atual);
                        return l;
                    }
                    else{
                        ant->esq=temp;
                        temp->pai=ant;
                        atual->esq=NULL;
                        free(atual);
                        return l;

                    }
                }

            }
            
        }
        else if (atual->dir == NULL && atual->esq == NULL){ //caso tenha 0 filhos
            if (ant==NULL){
                free(atual);
                return NULL;
            }
            else{
                if (ant->esq==atual){
                    ant->esq=NULL;
                    free(atual);
                    return l;
                }
                else{
                    ant->dir=NULL;
                    free(atual);
                    return l;
                }
                
            }
            
        
            
        }
        
        
        return l;
    }
    
}

ArvoreNoCima* removerCopias(ArvoreNoCima* l,int k){
    if (l==NULL){
        return NULL;
    }
    else{ 
        ArvoreNoCima* atual=l;

        while (atual!=NULL){
            
            if (atual->id == k){
                l=remover(l,k);
                atual=l;
            }
            else if (k < atual->id){
                atual = atual->esq;
            }
            else{
                atual = atual->dir;
            
            }
        }
        
        return l;
    }
    
}

int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(3,r);
    r=inserirNoCima(2,r);
    r=inserirNoCima(8,r);
    r=inserirNoCima(1,r);
    r=inserirNoCima(3,r);
    r=inserirNoCima(10,r);
    r=inserirNoCima(3,r);
    imprimir(r);
    r=removerCopias(r,3);
    printf("\n");
    imprimir(r);

    r=liberarArvoreNoCima(r);

    return 0;
}