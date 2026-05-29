/* 
• aloca_linhas deve alocar dinamicamente os ponteiros para as
linhas da matriz

• aloca_colunas deve alocar dinamicamente os elementos
(colunas) de cada uma das linhas da matriz

• le_dados deve solicitar ao usuário a entrada (a partir do teclado)
de cada um dos elementos da matriz (elementos de cada linha da
matriz)

• imprime_matriz deve exibir (em tela) cada um dos elementos
da matriz (conforme exemplo de saída)

• troca_linhas deve realizar a troca dos elementos da matriz
(alterando os ponteiros das linhas e não substituindo os elementos
em si)*/

#include <stdio.h>
#include <stdlib.h>
/*
int **aloca_linhas(int );
int aloca_colunas (int **, int, int);
void le_dados(int **, int, int );
void imprime_matriz(int **, int, int );
void troca_linhas (int **, int, int);
*/
int **aloca_linhas(int linhas){

int **matriz1;
matriz1 =(int **) malloc(linhas* sizeof(int*));

return matriz1;
}

int aloca_colunas (int **matriz, int linhas, int colunas){

      int i;
      for( i = 0 ; i < linhas ; i++ ){

         *(matriz + i)= (int *)malloc ( colunas * sizeof(int));
         if (! (*(matriz + i))){

printf ("Erro de alocacao de memoria\n");
            return 1;

}
}
return 0;
}

void le_dados(int **matriz, int linhas , int colunas){

int i;
int j;

for ( i = 0 ; i< linhas ; i++){

      for( j = 0 ; j <colunas ; j++){

            printf(" matriz[%d][%d]" , i , j);
            scanf("%d" , *(matriz +i ) +j );

      }
}
}


void imprime_matriz(int **matriz, int linhas , int colunas){

int i;
int j;

for ( i = 0 ; i< linhas ; i++){

      for( j = 0 ; j <colunas ; j++){

            printf("%d" , *(*(matriz +i) +j));

      }
}
}


int main (void){

int **matriz;
int lin, col;
int linha1, linha2;

      scanf("%d",&lin); //número de linhas da matriz

matriz = aloca_linhas(lin);

      if (matriz==NULL)

            return 1; //não foi possível alocar as linhas da matriz

      scanf("%d",&col); //número de colunas da matriz

      if ((aloca_colunas(matriz, lin, col))==1)
            return 1; //não foi possível alocar todas as colunas da matriz

      le_dados(matriz, lin, col); //ler os elementos da matriz
      imprime_matriz(matriz, lin, col); //matriz original

     /* scanf("%d",&linha1); //informar a primeira linha a ser trocada
      scanf("%d",&linha2); //informar a segunda linha a ser trocada

      troca_linhas(matriz, linha1, linha2);

      printf("\n");
      imprime_matriz(matriz, lin, col); //matriz após a troca das linhas*/
      

return 0;
}