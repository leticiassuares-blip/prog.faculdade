/*2.(2,5) Considere a estrutura Tpessoa, apresentada na questão 1, e apresente uma função que
implemente o método de busca binária com base no nome de uma determinada pessoa presente no
arranjo cadastro (Tpessoa cadastro [MAX]). Seu método deve admitir que o cadastro das
pessoas já está ordenado crescentemente pelo valor do campo nome. Sua função deve ter, dentre os
parâmetros, o nome da pessoa a ser buscada; e deve retornar a posição no arranjo em que se
encontra a pessoa. A função deve retornar –1 caso não exista nenhuma pessoa no cadastro com o
nome desejado.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

typedef struct pessoa {

 char nome [30];
 int idade;
 
 } Tpessoa;

 //já está ordenado crescentemente pelo valor do campo nome -> já ta em ordem alfabetica
 //o nome da pessoa a ser buscada;
 //retornar a posição no arranjo em que se encontra a pessoa

 //já ta em ordem alfabetica
 /*VAMOS USAR A FUNCAO STRCMP QUE COMPARA NA TABELA ASCII

 0: Se as duas strings forem idênticas.
 Um valor menor que 0: Se a primeira string for 
 lexicograficamente menor que a segunda (ex: vem antes na ordem alfabética).
 Um valor maior que 0: Se a primeira string for lexicograficamente maior que a segunda
  (ex: vem depois na ordem alfabética).
  */
 int BuscaBin( Tpessoa cadastro [MAX] ,  int tamanho , char nome[30] ){

int inicio = 0 ;
int fim = tamanho - 1;
int meio;

      while( inicio <= fim){

            meio = (inicio + fim) /2;

            if( strcmp(cadastro[meio].nome, nome) < 0 ){

                  inicio= meio +1;

            }else{
                  if(strcmp(cadastro[meio].nome, nome) > 0){

                        fim = meio - 1;
                  }else{
            //strcmp(cadastro[i].nome, nome) == 0 ; sao iguais

                        return meio;
                  }

            } 
             
      }

return -1;//nao encontrou a pessoa
 }