#include <stdio.h>
#include <stdlib.h>


void buscaBinaria(int v[],int n, int k){
    int i=0, j=n-1;
    int m=0;
    while (i<=j){
        m= (i+j)/2;
        if(v[m] == k){
            printf("achei %d . \n",v[m]);
            return;
        }
        if(v[m]> k){
            j=m-1;
        } 
        if(v[m] < k){
            i=m+1;
        }
    }
printf("elemento nao encontrado");
}

int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};
    int vOrd[]={0,1,2,2,3,3,4,6,6,7,8,9,10};

    buscaBinaria(vOrd,n,7);

   return 0; 
}