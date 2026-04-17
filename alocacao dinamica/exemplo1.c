#include <stdio.h>
#include <stdlib.h>

int main(){

int *p;
int i, n;

      printf("Insira o tamanho do vetor:");
      scanf("%d", &n);

p = (int*)calloc(n ,sizeof(int) ); 
//mandando alocar uma regiao de memoria do tipo int( que depende de n ) e essa regiao
//já ta inicializada(zerada)

      if( p==NULL ){
      
      printf("Erro na alocacao de memoria");
      return -1;
}
//preencho no vetor
      for( i=0 ; i<n ; i++ ){

            printf("\nElemento vetor[%d]:",i);
            scanf("%d", p+i);

}

//imprimo
      for( i=0 ; i<n ; i++ ){

      printf("\n vetor[%d]:%d", i , *(p+i) );

}

free(p);
return 0;


}