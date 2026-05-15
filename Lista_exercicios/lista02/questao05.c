#include <stdio.h>
#include <stdlib.h>


/* Questao 5-  Encontrar um elemento no qual se repita k-vezes
tempo : O(n²)

*/

void kRepeticoes(int v[],int n,int k){
    int cont=0;
    int aux=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[j]== v[i]){
                cont++;
            }
            
        }
        if (cont == k){

            for (int t = 0; t < i; t++){
                if (v[t] == v[i]){
                    aux=1;
                    break;
                }
                
            }
            if (!aux){
                printf(" %d aparece %d vezes\n", v[i], k);
            }
            
        }
        cont=0;
    }
    
}



int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,6,7};

    kRepeticoes(v,n,3);

   return 0; 
}