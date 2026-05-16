#include <stdio.h>
void inic(int n, int *v){

int i;
      for (i=0; i<n ; i++){
            *(v+i)=0;
}
}
      
int main(){

      int tam = 4 ;
      int vetor[tam], i;
      inic(tam , vetor );

      for(i=0; i< tam; i++)
      printf("vetor[%d] = %d \n",i, *(vetor +i));
return 0;
}