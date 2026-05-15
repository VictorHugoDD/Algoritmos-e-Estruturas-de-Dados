#include <stdio.h>
#include <stdlib.h>


/* Questao 6-  Verificar se existem dois elementos repetidos
que se encontram a distˆancia no m ́aximo k um do outro
tempo : O(n²)

*/

void repProx(int v[],int n,int k){
    int cont =0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            cont++;
            if ((v[i]==v[j]) && (cont <=k)){
                printf("O elemento %d esta na posicao %d e %d a %d distancia.\n",v[i],i+1,j+1,cont);
                return;
            }
            
            
        }
        cont=0;
    }
    
  printf("Nao ha elementos repetidos nesta distancia\n");

}



int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,6,7};

    repProx(v,n,9);

   return 0; 
}