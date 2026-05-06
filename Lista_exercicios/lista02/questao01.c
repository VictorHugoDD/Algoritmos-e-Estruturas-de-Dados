#include <stdio.h>
#include <stdlib.h>


/* Questao 1- achar o terceiro maior elemento
tempo : O(n)
*/

void terceiroMaiorElemento(int v[],int n){
    int maior=0,segMaior=0,terMaior=0;
    for (int i = 0; i < n; i++){
        if (maior < v[i]){
            terMaior=segMaior;
            segMaior=maior;
            maior=v[i];
        }
        else if (segMaior < v[i] && terMaior < v[i]){
            terMaior = segMaior;
            segMaior=v[i];
            
        }
         else if (terMaior < v[i] && segMaior > v[i]){
            terMaior=v[i];
        }
        
    }
    printf(" Terceiro maior: %d . \n", terMaior);
}

int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};

    terceiroMaiorElemento(v,n);

   return 0; 
}