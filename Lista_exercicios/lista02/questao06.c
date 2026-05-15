#include <stdio.h>
#include <stdlib.h>


/* Questao 6-  Verificar se as duas listas sao permutaçoes entre si,
ou seja tenha os mesmos elementos.
tempo : O(n²)

*/

void permutacao(int v[],int n,int u[],int m){

    if(n!=m){ // se a lista nao tiver o mesmo tamanho ja nao é uma permutação
        printf("Nao eh permutacao\n");
        return;
    }

    int cont=0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i]==u[j]){
                cont++;
                break;
            }
            
        }
        
    }
    if (cont==n){
        printf("Eh uma permutacao.\n");
    }
    else{
        
        printf("Nao Eh uma permutacao.\n");

    }
    

    
}



int main(){
    int n= 12;
    int m=13;
    int v[]={3,6,2,6,9,0,4,8,3,2,6,7};
    int u[]={2,6,8,1,0,3,6,2,9,4,6,3};
    int w[]={2,6,8,7,0,3,6,2,9,4,6,3};
    int h[]={2,6,8,7,0,3,6,2,9,4,6,3,1};

    permutacao(v,n,w,n);

   return 0; 
}