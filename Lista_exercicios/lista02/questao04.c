#include <stdio.h>
#include <stdlib.h>


/* Questao 4-  Encontrar um elemento no qual tenha a lista tenha o antecessor e sucessor
tempo : O(n²)

*/

void elementIsolado(int v[],int n){
    int ant=0, suc=0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[j]== (v[i] + 1) ){
                suc=v[j];
            }
            else if (v[j] == (v[i]-1)){
                ant=v[j];
            }
            if (ant == (v[i]-1) &&(v[i]+1) == suc){
                printf("N: %d ,\nSucessor: %d Antecessor: %d .\n",v[i],suc,ant);
                break;
            }
            
        }
        ant=0,suc=0;
    }
    
}


int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};

    elementIsolado(v,n);

   return 0; 
}