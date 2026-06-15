#include <stdio.h>
#include <stdlib.h>

/*A tarefa consiste em, dado um numero k
1. percorrer a lista da esquerda para a direita com o ponteiro q,
at ́e encontrar um elemento > k
2. percorrer a lista da direita para a esquerda com o ponteiro r,
at ́e encontrar um elemento ≤ k
3. trocar os elementos apontados por q, r de posicao
4. Repetir os passos 1 − 3 até que os ponteiros q, r se encontrem
A funçao que responde esta questao é a particao,
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

Lista* particao(Lista* l, int k){
    if (l ==NULL){
        return l;
    }
    Lista* atual=l;
    Lista* menores=NULL;
    Lista* auxMenores=NULL;
    Lista* maiores=NULL;
    Lista* auxMaiores=NULL;
    Lista* proximo=NULL;

    while (atual != NULL){
        proximo=atual->prox;
        if (atual->id <= k){
            if (menores == NULL){
                menores=atual;
                menores->ant=NULL;
                auxMenores=atual;
            }
            else{
                auxMenores->prox=atual;
                atual->ant=auxMenores;
                auxMenores=atual;
                auxMenores->prox=NULL;
            }   
        }
        else{
            if (maiores == NULL){
                maiores=atual;
                maiores->ant=NULL;
                auxMaiores=atual;
                auxMaiores->prox=NULL;
            }
            else{
                auxMaiores->prox=atual;
                atual->ant=auxMaiores;
                auxMaiores=atual;

            }

        }
        atual=proximo;
    }

    if (menores ==NULL){
        if (maiores != NULL){
            auxMaiores->prox= NULL;
        }
        
        return maiores;
    }
    else if(maiores == NULL){
         if (menores != NULL){
            auxMenores->prox= NULL;
        }
        return menores;
    }
    else{
        auxMenores->prox=maiores;
        maiores->ant=auxMenores;
        auxMaiores->prox=NULL;
        return menores;
    }
    
    
}



int main(){
    Lista* l=NULL;
    l=inserir_comeco(6,l);
    l=inserir_comeco(9,l);
    l=inserir_comeco(2,l);
    l=inserir_comeco(0,l);
    l=inserir_comeco(8,l);
    l=inserir_comeco(3,l);
    l=particao(l,7);
    imprimir(l);
    l=liberar(l);

    return 0;
}