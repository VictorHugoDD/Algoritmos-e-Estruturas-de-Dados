#include <stdio.h>
#include <stdlib.h>

/*A operacao de atualizacao consiste em
- localizar um elemento x na lista
- modificar o seu valor para y
- e depois move-lo para a sua posicao correta
 A funçao que responde esta questao é a atualizacao atualmente essa funçao nao move os menores so maiores,
  Analise: Por conta do loop while perceorremos td a 
    lista uma vezes logo no pior caso temos o tempo O(N)*/


typedef struct Lista{
    int id;
    struct Lista *prox;
    struct Lista *ant;
}Lista;

Lista* criarLista(int id){
    Lista* nv=(Lista*) malloc(sizeof(Lista));
    nv->id=id;
    nv->ant=NULL;
    nv->prox=NULL;
    return nv;
}


Lista* inserir_comeco(int id,Lista* l){
    Lista* nv=criarLista(id);

    if(l == NULL){
         return nv;
    }
    nv->prox=l;
    l->ant=nv;
    return nv;
}

Lista* inserir_fim(int id,Lista* l){
    Lista* nv=criarLista(id);

    if(l == NULL){
         return nv;
    }
    Lista* aux=l;

    while(aux->prox != NULL){
       aux=aux->prox;
    }
    aux->prox=nv;
    nv->ant=aux;

    return l;
}


Lista* liberar(Lista* l){
    Lista *aux=l;
    while (aux!=NULL){
        Lista *proximo = aux->prox; // Guarda a referência do próximo nó
        free(aux);                  // Libera o nó atual com segurança
        aux = proximo;
    }
    return NULL;
    
}

void imprimir(Lista *l){
    Lista* aux = l;
    int i=0;
    while (aux!=NULL){
        printf("No %d: %d\n",++i,aux->id);
        aux=aux->prox;
    }
}

Lista* troca(Lista* l1, Lista* l2){
    Lista* anterior=l1->ant;
    Lista* proximo=l2->prox;

    l2->prox=l1;
    l2->ant=anterior;
    l1->prox=proximo;
    l1->ant=l2;

    if (anterior !=NULL){
        anterior->prox=l2;
    }
    if (proximo !=NULL){
        proximo->ant=l1;
    }
    
    return l2;

}


Lista* atualizacao(Lista* l, int x, int y){
    if (l== NULL){
        return l;
    }

    Lista* atual=l;
    while (atual !=NULL){
        if (x == atual->id){
            atual->id=y;
            break;
        }
        atual=atual->prox;
        
    }
    while (atual!=NULL){
        if (atual->ant == NULL && atual->id < atual->prox->id){
         return atual;
        }
        else if (atual->prox == NULL && atual->id > atual->ant->id){
         return l;
        }
        if (atual->id < atual->ant->id){
            
            atual=troca(atual->ant,atual);
            atual=atual->ant;
        }
        else{
            atual=troca(atual,atual->prox);
            atual=atual->prox;
        }
    }
    
    
return l;
}


int main(){
    Lista* l=NULL;
    l=inserir_fim(0,l);
    l=inserir_fim(2,l);
    l=inserir_fim(3,l);
    l=inserir_fim(6,l);
    l=inserir_fim(8,l);
    l=inserir_fim(9,l);
    l=atualizacao(l,6,15);
    imprimir(l);
    l=liberar(l);

    return 0;
}