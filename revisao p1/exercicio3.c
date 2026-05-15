/*Exercício 3

• Implemente e teste uma função com a
seguinte assinatura:
void pares(int *v, int *n)
• que atualize o valor do argumento passado
através do parâmetro n com a quantidade de
números pares dentre os n primeiros
elementos de um vetor (acessado a partir do
ponteiro v)*/

#include <stdio.h>

void pares(int *v, int *n){

      int i  ;
      int contador = 0 ;

      for ( i = 0; i < *n ; i++){ //*(v+i) = v[i]

            if( *(v+i) % 2 == 0 ){

                  contador ++;
      }
}
      *n = contador;
}

int main(){

 int vetor[6] = { 1 , 2 , 3 ,4 , 5 ,6};

      int  n = 4;
      pares (vetor ,&n);

            printf("%d" , n);
      return 0;
}