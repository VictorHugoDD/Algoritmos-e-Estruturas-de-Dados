#include <stdio.h>
#include <stdlib.h>

/* a questao consiste em procurar um numero k, e caso ele nao esteja na lista
 deve encontrar o numero mais proximo de k.
*/

void buscaAproximada(int v[],int n,int k){
    int proxK=0,distM=k;
    
    for(int i = 0; i < n ; i++){
        if (k-v[i]==0){
            printf("Achei %d . \n",v[i]);
            return;
        }
        else{
            if (k>v[i] && distM > (k-v[i])){
                proxK=v[i];
                distM=k-v[i];
            }
            else if(k<v[i] && distM > (v[i]-k)){
                proxK=v[i];
                distM=v[i]-k;
            }
            
        }
        

    }
    printf("Achei o mais proximo: %d \n",proxK);

}


int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};

    buscaAproximada(v,n,5);

   return 0; 
}