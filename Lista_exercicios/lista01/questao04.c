#include <stdio.h>
#include <stdlib.h>

/* a questao consiste em verificar se um numero impar
 da lista se repete em uqnatidade impares.

 Utilizei o metodo de marcaçao, para que mais na frente da lista
  ele nao conte novamente os numeros. O tempo de execuçao é O(n²).
*/

void reImpar(int v[],int n){
    int rep=0, impar=0;

    for (int i = 0; i < n; i++){
        if (v[i] % 2 != 0){
            impar=v[i];
            rep++;
            for (int j = i+1; j < n; j++){
                if(impar == v[j]){
                    rep++;
                    v[j]=0;
                }
            }
            if (rep % 2 !=0){
                printf("O numero %d se repete %d .\n ",impar,rep);
            }
            impar=0,rep=0;
            
            
            
        }
        
    }
    
}



int main(){
    int n= 12;
    int v[]={1,4,8,2,6,9,4,2,6,9,9,3};

    reImpar(v,n);

   return 0; 
}