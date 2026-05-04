#include <stdio.h>
#include <stdlib.h>

/* a primeira funçao localiza o maior valor impar, a funçao tem o tempo de O(n)
 a segunda funçao localiza o segundo valor impar,a funçao tem o tempo de O(n).

*/

void maiorImpar(int v[], int n){
    int maiorIm=0,imparAtual=0;
    for (int i = 0; i < n; i++){
        if (v[i] % 2 != 0){
            imparAtual=v[i];
            if(maiorIm <= imparAtual){
                maiorIm=imparAtual;
            }
        }
        
    }
    printf("O maior Impar: %d \n",maiorIm);
}

void segundoMaiorImpar(int v[], int n){
    int maiorIm=0,imparAtual=0, segundoIm=0;
    for (int i = 0; i < n; i++){
        if (v[i] % 2 != 0){
            imparAtual=v[i];
            if(maiorIm <= imparAtual){
                segundoIm=maiorIm;
                maiorIm=imparAtual;
            }
            if(segundoIm < imparAtual && imparAtual< maiorIm){
                segundoIm=imparAtual;
            }
        }
        
    }
    printf("O segundo maior Impar: %d \n",segundoIm);
}

int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};

    maiorImpar(v,n);
    segundoMaiorImpar(v,n);

   return 0; 
}