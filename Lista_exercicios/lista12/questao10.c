#include <stdio.h>
#include <stdlib.h>

/* A ideia é que:
- *esq aponta para elementos menores que v1;
- *dir aponta para elementos maiores que v2;
- *meio aponta para elementos entre v1 e v2.
 Apresente um algoritmo que realiza a busca na árvore ternária de busca.
a árvore de modo que esse elemento passe a ser a raiz.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro para cima para o no pai.
  Analise: a funçao que resolver essa questao é a parSoma,
  como o algoritmo percorre metade da arvore a cada interaçao entao o tempo é O(log n).*/

typedef struct ArvoreNoCima{
    int id,id2;
    struct ArvoreNoCima *pai;
    struct ArvoreNoCima *dir;
    struct ArvoreNoCima *meio;
    struct ArvoreNoCima *esq;
}ArvoreNoCima;

ArvoreNoCima* criarArvoreTernariaNoCima(int id){
    ArvoreNoCima* nv=(ArvoreNoCima*) malloc(sizeof(ArvoreNoCima));
    nv->id=id;
    nv->id2=-1;;
    nv->esq=NULL;
    nv->meio=NULL;
    nv->dir=NULL;
    nv->pai=NULL;
    return nv;   
}

ArvoreNoCima* inserirNoCima(int id, ArvoreNoCima* l){
    
    if(l == NULL){
         return criarArvoreTernariaNoCima(id);
    }

    ArvoreNoCima* atual=l;

    while (atual!=NULL){
        
        if (atual->id2 == -1){
            if (atual->id>id){
                atual->id2=atual->id;
                atual->id=id;
            }
            else{
                atual->id2=id;
            }

            return l;
        }
        if (id< atual->id){
            if (atual->esq ==NULL){
                atual->esq=criarArvoreTernariaNoCima(id);
                atual->esq->pai=atual;
                return l;
            }
            atual=atual->esq;
            
        }
        else if(id> atual->id && id<atual->id2){

            if (atual->meio ==NULL){
                atual->meio=criarArvoreTernariaNoCima(id);
                atual->meio->pai=atual;
                return l;
            }

            atual=atual->meio;
            
        }
        else if (id>atual->id2){
            
            if (atual->dir==NULL){
                atual->dir=criarArvoreTernariaNoCima(id);
                atual->dir->pai=atual;
                return l;
            }

            atual=atual->dir;
        }
        else{
            printf("Valor %d já existe.\n", id);
            return l;
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
            else if (atual->meio!=NULL){
                atual=atual->meio;
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
                    else if (pai->meio == atual) {
                        pai->meio = NULL;
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

void imprimirArvoreTernaria(ArvoreNoCima* l){
    if (l==NULL){
        return ;
    }
    else{
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        while (atual!=NULL){
            if (ant==atual->pai){
                printf("[%d", atual->id);

                if (atual->id2 != -1){
                    printf(" | %d", atual->id2);
                }
                printf("] ");
                ant=atual;
                if (atual->esq != NULL){
                    atual=atual->esq;
                }
                else if (atual->meio != NULL){
                    atual=atual->meio;
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
                if (atual->meio != NULL){
                    atual=atual->meio;
                }
                else if (atual->dir!=NULL){
                    atual=atual->dir;
                }
                else{
                    atual=atual->pai;
                }
                
            }
            else if (ant==atual->meio){
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

                if (atual->id == k || atual->id2 == k){
                    printf("Achei %d .\n" ,atual->id == k ? atual->id : atual->id2); 
                    return;
                }
                
                if (k<atual->id){
                    atual=atual->esq;
                }
                else if (k>atual->id2){
                    atual=atual->dir;
                }
                else {
                    atual=atual->meio;
                }
                        
            
        }
        
        return;
    }
    
}



int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(14,r);
    r=inserirNoCima(35,r);
    r=inserirNoCima(6,r);
    r=inserirNoCima(10,r);
    r=inserirNoCima(41,r);
    r=inserirNoCima(52,r);
    r=inserirNoCima(3,r);
    r=inserirNoCima(5,r);
    r=inserirNoCima(20,r);
    r=inserirNoCima(15,r);
    r=inserirNoCima(7,r);
    r=inserirNoCima(9,r);
    r=inserirNoCima(12,r);
    r=inserirNoCima(11,r);
    r=inserirNoCima(40,r);
    r=inserirNoCima(38,r);
    r=inserirNoCima(43,r);
    r=inserirNoCima(50,r);
    r=inserirNoCima(53,r);
    r=inserirNoCima(60,r);
    imprimirArvoreTernaria(r);
    printf("\n");
    buscar(r,9);
    printf("\n");

    r=liberarArvoreNoCima(r);

    return 0;
}