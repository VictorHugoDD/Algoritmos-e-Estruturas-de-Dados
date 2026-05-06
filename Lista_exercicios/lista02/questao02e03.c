#include <stdio.h>
#include <stdlib.h>


/* Questao 2-  Encontrar o k- ́esimo maior elemento da lista
tempo : O(n²)

Questao 3- encontrar o elemento mais proximo da media na lista
tempo : 2O(n)
*/

void kMaiorElemento(int v[],int n,int k){
    int aux=0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1; j++){
            if (v[j]<v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
            
        }
        
    }
    printf("%d \n",v[k-1]);
}

void proxMedia(int v[],int n){
    float med=0,k=0;

    for (int i = 0; i < n; i++){
        med+=v[i];

    }

float dist=med;
med=med/n;

    for (int i = 0; i < n; i++){
        if (v[i]> med && dist > v[i] - med){
            dist=v[i] - med;
            k=v[i];
        }
         if (v[i]< med && dist > med -v[i] ){
            dist=med -v[i];
            k=v[i];
        }
        
    
    }

    printf(" Media: %f . \n Numero mais prox da media: %f .\n",med,k);
    
}

int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};
    
    kMaiorElemento(v,n,5);
    proxMedia(v,n);

   return 0; 
}