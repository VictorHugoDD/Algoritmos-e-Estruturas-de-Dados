#include <stdio.h>
#include <stdlib.h>


/* Questao 1- Achar um numero y e substituir por x, td isso em uma lista ordenada,
ou seja apos essa substituiçao devemos manter a lista ordenada.
tempo : O(n)
*/

void upOrd(int v[],int n,int y,int x){
    int i=0, j=0;
    while (i<n){
        if (y == v[i]){
            v[i]=x;
            j=i;
            break;
        }
        i++;        
    }
    i=j;  

    while (i<n){
        if (i < n - 1 && x > v[i + 1]){
            int aux=v[i+1];
            v[i+1]=x;
            v[i]=aux;
            i++;
        }
        else if (i > 0 && x < v[i - 1]){
            int aux=v[i-1];
            v[i-1]=x;
            v[i]=aux;
            i--;
        }
        else{
            break;
        }
        
    }

    for (int i = 0; i < n; i++){
        printf(" %d |",v[i]);
    }    


}

int main(){
    int n= 12;
    int v[]={2,4,5,6,7,8,9,10,13,14,15,16};

    upOrd(v,n,8,1);

    
    

   return 0; 
}