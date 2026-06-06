/*Faça um programa que:

Pergunte quantos números serão armazenados inicialmente.
Aloque o vetor.
Leia os valores.
Pergunte quantos novos números deseja adicionar.
Utilize realloc.
Leia os novos números.
Exiba todos os valores.
Esse é praticamente o mesmo conceito do Exercício 3, 

mas usando inteiros em vez de estruturas.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

      int n;
      int *v;

      printf("Quantos numeros serão armazenados: ");
      scanf("%d" , &n);

      //qual tamanho do bloco?
      v = (int *)malloc(n * sizeof(int));//reservei espaco na memoria para n

      if( v == NULL ){

        printf("Erro na alocacao de memoria");
        return -1;

      }
      int i;

      //leitura
      for( i = 0 ; i < n ; i++ ){

            printf("\nValor[%d]: " , i);
            scanf("%d" , (v + i ));
      }

      int n_adicionados;

      printf("Quantos novos numeros voce deseja adicionar: ");
      scanf("%d" , &n_adicionados);

      int soma= ( n + n_adicionados);
      //"qual será o novo tamanho total do bloco?"
     int *vetor = (int *)realloc( v , soma * sizeof(int));

      if( vetor  == NULL ){

        printf("Erro na alocacao de memoria");
        return -1 ;

      }
      //leitura
      for( i = n  ; i < soma ; i++ ){

            printf("\nValor[%d]: " , n );
            scanf("%d" , (vetor + i ));
                  n++;
      }

      //escrita

      for( i = 0 ; i < soma ; i++ ){

            printf("\nValor[%d]: %d " , i , *(vetor+i));
      }

      return 0;
}