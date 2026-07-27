#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em calcular a altura da arvore.
vamos fazer de forma nao recursiva ent implementaremos um ponteiro
 para cima para o no pai.
  Analise: a funçao que resolver essa questao é a altura,
  como o algoritmo percorre td a arvore o tempo é O(n).*/

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

int altura(ArvoreNoCima* l){
    if (l ==NULL){
        return 0;
    }
    else{
        int maiorAltura=1;
        int alturaAtual=1;
        ArvoreNoCima* atual=l;
        ArvoreNoCima* ant=NULL;

        while (atual!= NULL){
            if (ant == atual->pai){
                ant= atual;
                if (atual->esq !=NULL){
                    atual=atual->esq;
                    alturaAtual++;
                }
                else if(atual->dir != NULL){
                    atual=atual->dir;
                    alturaAtual++;
                }
                else{
                    if (alturaAtual > maiorAltura){
                        maiorAltura=alturaAtual;
                    }
                    
                    atual=atual->pai;
                    alturaAtual--;
                }
            }
            else if (ant == atual->esq){
                ant=atual;
                if(atual->dir != NULL){
                    atual=atual->dir;
                    alturaAtual++;
                }
                else{
                    if (alturaAtual > maiorAltura){
                        maiorAltura=alturaAtual;
                    }
                    atual=atual->pai;
                    alturaAtual--;
                }
                
            }
            else if (ant == atual->dir){
                    if (alturaAtual > maiorAltura){
                        maiorAltura=alturaAtual;
                    }
                ant=atual;
                atual=atual->pai;
                alturaAtual--;
            }
            
            
        }
     return maiorAltura;   
    }
    
}

int main(){
    ArvoreNoCima* r=NULL;
    r=inserirNoCima(8,r);
    r=inserirNoCima(5,r);
    r=inserirNoCima(10,r);
    r=inserirNoCima(2,r);
    r=inserirNoCima(7,r);
    r=inserirNoCima(4,r);
    r=inserirNoCima(9,r); 
    int k=altura(r);
    printf("%d , ", k);

    r=liberarArvoreNoCima(r);

    return 0;
}