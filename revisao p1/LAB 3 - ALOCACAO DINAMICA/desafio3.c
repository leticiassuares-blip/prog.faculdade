

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Alocando espaco na memoria
int** cria_matriz( int **matriz , int L , int C){

      matriz = (int **)malloc( L * sizeof(int*));

      if ( matriz == NULL){
            return NULL;
      }
      //percorra cada linha e armazene espaco 
      //pra cada valor  da coluna
int i ;

      for( i = 0 ; i < L ; i++){
      
      *(matriz + i)  = (int *)malloc( C * sizeof(int));

            if ( *(matriz + i ) == NULL){
                  return NULL;
      }
      }

return matriz;
}

void le_matriz (int **matriz , int L , int C ){

int i , j ;

      for( i = 0 ; i < L ; i++){
            for( j = 0 ; j < C ; j++){

                  scanf("%d" , (*(matriz + i) + j) );

      }
      }

}

void imprime_matriz (int **matriz , int L , int C ){

int i , j ;

      for( i = 0 ; i < L ; i++){
            for( j = 0 ; j < C ; j++){

                  printf("%d " , *(*(matriz + i) + j) );
      }
             printf("\n");
      }

}

//funcao que acessa cada lote,compara e ve qual tem o maior numero
// de margaridas pronta para as vendas
int acessa_soma(int **matriz , int L , int C , int M ,int  N ){

int soma = 0;// soma cada valor do lote e compara
int guarda_maior = 0; //guarda o maior valor
                  
int repeticoes = (L * C) / (M * N) ; 

      while(  repeticoes != 0 ){

            for( int i = 0 ; i < M ; i++){
            for( int j = 0 ; j < N ; j++){

             soma +=  *(*(matriz + i )+ j );
                 
             if( soma >= guarda_maior ){
                  guarda_maior = soma;

            }
            repeticoes--;
            N--;
            }
            M++;
            N--;
      }
      }
   return guarda_maior;         
}

int main(){

      int L , C , M , N ;

      scanf("%d" , &L);
       if(L < 1){

          printf("Valor nao permitido");
          return -1;
      }

      scanf("%d" , &C);
      if(C < 1){

          printf("Valor nao permitido");
          return -1;
      }

      scanf("%d" , &M);
      if( ( M < 1 ) || ( M > L ) ){

          printf("Valor nao permitido");
          return -1;
      }

      scanf("%d" , &N);
      if( ( N < 1 ) || ( N > C ) ){

          printf("Valor nao permitido");
          return -1;
      }

      int** matriz = cria_matriz (matriz , L , C);
      le_matriz (matriz , L , C);
      printf("\n");
      imprime_matriz (matriz , L , C);

      printf("%d" , acessa_soma(matriz , L ,C , M ,N ));

      return 0;


}