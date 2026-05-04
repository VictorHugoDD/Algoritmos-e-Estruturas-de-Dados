#include <stdio.h>
#include <stdlib.h>

/* nesta questao devemos achar um numero 
na lista no qual tenha o seu dobro na lista.
Deve fazer 2 funçoes uma para uma lista ordenada e uma para uma nao ordenada.
O tempo de execução é O(n²).
*/

void dobroNoOrde(int v[],int n){

    int k=0,dk=0;
    for (int i = 0; i < n; i++){
        k=v[i];
        for (int j = 0; j < n; j++){
            dk=v[j];
            if (2*k == dk){
                printf("Numero : %d e seu Dobro : %d \n",k,dk);
                break;
            }
            
        }
        
    }
    
}

void dobroOrde(int v[],int n){

    int k=0,dk=0;
    for (int i = 0; i < n-1; i++){
        k=v[i];
        for (int j = i+1; j < n; j++){
            dk=v[j];
            if (2*k == dk){
                printf("Numero : %d e seu Dobro : %d \n",k,dk);
                break;
            }
            
        }
        
    }
    
}



int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};
    int vOrd[]={0,1,2,2,3,3,4,6,6,7,8,9};

    dobroNoOrde(v,n);

    printf("\n\n\n\n\n\n\n\n Ordenado: \n");
    dobroOrde(vOrd,n);

   return 0; 
}