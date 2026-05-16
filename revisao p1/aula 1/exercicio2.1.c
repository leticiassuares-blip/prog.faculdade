/*Exercício 2

• Faça uma função que receba uma string
como parâmetro e retorne o número de
vogais desta.
– Apresente duas versões da função: uma usando
vetores e outra utilizando ponteiros.*/

//string é um vetor de caracteres

#include <stdio.h>
#define MAX 50
//ponteiros
int numeroVogais( char *nome ){

int conta =0;

for (int i =0 ; *(nome +i) != '\0'  ; i++){

      if(*(nome +i) == 'a' || *(nome +i) == 'e' || *(nome +i) == 'i'
       || *(nome +i) == 'o' ||*(nome +i) == 'u' ){

            conta ++;
      }
}
      return conta;
}

int main (){

      char palavra[MAX];

      printf(" Insira a palavra para contagem de vogais:");
      scanf( "%s" , palavra);
      int num;
      num = numeroVogais(&palavra);
      printf("Numero de vogais desta palavra %d " , num);
      return 0;
}

