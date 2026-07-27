#include <stdio.h>
#include <stdlib.h>

/* A tarefa consiste em, dado um número k: Localizar o elemento k e reorganizar 
a árvore de modo que esse elemento passe a ser a raiz.
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


ArvoreNoCima* rotacionarDireita(ArvoreNoCima* y) {
    ArvoreNoCima* x = y->esq;
    ArvoreNoCima* b = x->dir;

    // Atualiza pai de x para o pai de y
    x->pai = y->pai;

    // Se y tinha pai, atualiza o filho correspondente
    if (x->pai != NULL) {
        if (x->pai->esq == y){
            x->pai->esq = x;
        }
        else{
            x->pai->dir = x;
        }
    }

    // y vira filho direito de x
    x->dir = y;
    y->pai = x;

    // b (subárvore esquerda de y) vira filho esquerdo de y
    y->esq = b;
    if (b != NULL){
        b->pai = y;
    }

    return x;  // nova raiz da subárvore
}

ArvoreNoCima* rotacionarEsquerda(ArvoreNoCima* x){
    ArvoreNoCima* y=x->dir;
    ArvoreNoCima* b=y->esq;

    y->pai=x->pai;

    if (y->pai !=NULL){
        if (y->pai->dir==x){
            y->pai->dir= y;
        }
        else{
            y->pai->esq=y;
        }
        
    }

    y->esq=x;
    x->pai=y;

    x->dir=b;
    if (b!=NULL){
        b->pai=x;
    }

    return y;
}


ArvoreNoCima* mudarRaiz(ArvoreNoCima* l, int k) {
    // 1. Encontra o nó com valor k
    ArvoreNoCima* x = buscar(l, k);
    if (x == NULL || x == l) return l;  // não encontrou ou já é raiz

    // 2. Enquanto x NÃO for a raiz
    while (x->pai != NULL) {
        ArvoreNoCima* pai = x->pai;
        ArvoreNoCima* avo = pai->pai;

        // CASO 1: Zig (pai é a raiz)
        if (avo == NULL) {
            if (pai->esq == x)
                x = rotacionarDireita(pai);   // x é filho esquerdo
            else
                x = rotacionarEsquerda(pai);  // x é filho direito
        }
        // CASO 2: Zig-Zig (mesma direção)
        else if (pai->esq == x && avo->esq == pai) {
            // pai e x são ambos filhos esquerdos
            rotacionarDireita(avo);    // sobe o pai
            x = rotacionarDireita(pai); // sobe o x
        }
        else if (pai->dir == x && avo->dir == pai) {
            // pai e x são ambos filhos direitos
            rotacionarEsquerda(avo);    // sobe o pai
            x = rotacionarEsquerda(pai); // sobe o x
        }
        // CASO 3: Zig-Zag (direções opostas)
        else if (pai->esq == x && avo->dir == pai) {
            // x é esquerdo do pai, pai é direito do avô
            rotacionarDireita(pai);     // primeiro sobe x sobre o pai
            x = rotacionarEsquerda(avo); // depois sobe x sobre o avô
        }
        else { // pai->dir == x && avo->esq == pai
            // x é direito do pai, pai é esquerdo do avô
            rotacionarEsquerda(pai);     // primeiro sobe x sobre o pai
            x = rotacionarDireita(avo);  // depois sobe x sobre o avô
        }
    }

    return x;  // x agora é a nova raiz
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
    r=mudarRaiz(r,20);
    imprimir(r);
    printf("\n");

    r=liberarArvoreNoCima(r);

    return 0;
}