#include <stdio.h>
#include <stdlib.h>


/* Questao 5- Escreva o algoritmo de particionamento que retorne, ao fim do procedimento, a posição do primeiro
elemento maior (ou igual a) que k.
tempo : O(n)
*/

void particao(int v[],int n, int k){
    int i=0,j=n-1,aux=0;
    while (i <= j){
        if (v[i]<k){
            i++;
            
        }
        else if (v[j]>=k){
            j--;
            
        }
        else {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
            
        }

    }
    printf(" PRIEMIRO ELEMENTO PROX OU IGUAL A K %d ",v[i]);
    

}

int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};

    particao(v,n,5);

    for (int i = 0; i < n; i++){
        printf(" %d |",v[i]);
    }
    

   return 0; 
}