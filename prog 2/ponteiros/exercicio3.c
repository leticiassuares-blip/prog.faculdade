/*• Implemente e teste uma função com a
seguinte assinatura:
void pares(int *v, int *n)
• que atualize o valor do argumento passado
através do parâmetro n com a quantidade de
números pares dentre os n primeiros
elementos de um vetor (acessado a partir do
ponteiro v)*/

//NOTAS

/*  n = quantidade de números pares(conta os pares e atualiza a variavel n) (numero ser par => numero/2 == 0 )
dentre os n primeiros elementos de um vetor (acessado a partir do
ponteiro v) */

//n recebe 2 papeis; primeiro n primeiros elementos
// de um vetor e segundo quantidade de números pares
//antes *n = tamanho a percorrer
//ao final *n =quantidade de pares

//ponteiro v-> acessa os elementos do vetor (acessa o conteudo)

#include <stdio.h>

// v acessa o vetor e n = quantidade de numeros a analisar; n ao final=quant de num pares
void pares(int *v, int *n){ // v e n acessam os enderecos

    int i=0;//dita a posicao do vetor v
    
      int contador=0;//vai contar os pares e dps atualiza o ponteiro n

      for( i=0 ;  i< *n ; i++ ){// comeca na posicao i=0

      if ( v[i]%2 == 0 ){ //numero é par(resto 0 na div por 2)

            contador++;
      }
}
    *n = contador; // n vira a quant de num pares
}

int main(void){
    
    int n=5;//quantidade de numeros a analisar

int v[5]={2,7,4,3,8};//declarando e definindo um vetor de tamanho 3

pares(v,&n);//chamo a funcao

printf("A quantidade de numeros pares dentro do vetor é:%d", n ); //quant de pares
return 0;

}
