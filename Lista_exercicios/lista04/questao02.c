#include <stdio.h>
#include <stdlib.h>


/* Questao 2- fazer o algoritmo recursivo da busca binaria
tempo : O(log n)
*/

void buscaBinaria(int v[],int i,int n, int k){

    if(i > n){
        printf("Nao achei!");
        return;
    }

    int m=(i+n)/2;
    if (k> v[m]){
        i=m+1;
        buscaBinaria(v,i,n,k);
    }
    if (k< v[m]){
        n=m-1;
        buscaBinaria(v,i,n,k);
    }
    if (k == v[m]){
        printf("Achei");
        return;
    }

}



int main(){
    int n= 12;
    int v[]={1,2,3,4,5,6,7,8,9,12,13,14};

    buscaBinaria(v,0,n-1,6);

   return 0; 
}