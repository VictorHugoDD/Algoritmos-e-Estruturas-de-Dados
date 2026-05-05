#include <stdio.h>
#include <stdlib.h>


/* 7- Nos dizemos que o par de elementos V[i] e V[j] formam uma inversao 
se - i < j e V[i] > V[j]. devemos contar o numero de inversoes
tempo O(n²)

8- imprimir tds os numeros que se repetem em ambas as listas
tempo O(n²)

*/

void contInver(int v[],int n){
    int cont=0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (v[i] > v[j]){
                cont++;
            }
            
        }
        
    }
    printf("Total de inversoes: %d .\n",cont );
    
}

void nComuns(int v[],int u[],int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[i]==u[j]){
                printf(" %d -",v[i]);
                break;
            }
            
        }
        
    }
    

}


int main(){
    int n= 12;
    int v[]={3,6,2,6,9,0,4,8,3,2,1,7};
    int u[]={1,5,3,9,17,23,7,2,8,13,20,5};
    //int vOrd[]={0,1,2,2,3,3,4,6,6,7,8,9};

    contInver(v,n);
    nComuns(v,u,n);


   return 0; 
}