#include <stdio.h>
#include <stdlib.h>


/*Achar os elementos mais proximo entre si na lista

tempo de execução O(n²)
*/

void elementProx(int v[], int n){
int k=0,proxK=0,distM=0,dist=0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n; j++){
            if (i==j){
                continue;
            }
            if (v[i] > v[j]){
                if (dist==0){
                    dist=v[i];
                    distM=dist;
                }
                if (v[i]-v[j]<distM && v[i] - v[j]!=0){
                    dist=distM;
                    k=v[i];
                    proxK=v[j];
                    distM=v[i]-v[j];
                }
            }
            if (v[j]> v[i]){
                if (dist == 0){
                    dist=v[j];
                    distM=dist;
                }
                if (v[j]-v[i]<distM && v[j] - v[i]!=0){
                    dist=distM;
                    k=v[i];
                    proxK=v[j];
                    distM=v[j]-v[i];
                }
                
            }
            
            
        }
        
    }
    printf("numero mais proximo de %d eh %d .\n",k,proxK);
    
}


int main(){
    int n= 12;
    int v[]={1,5,3,9,17,23,7};

    elementProx(v,n);


   return 0; 
}