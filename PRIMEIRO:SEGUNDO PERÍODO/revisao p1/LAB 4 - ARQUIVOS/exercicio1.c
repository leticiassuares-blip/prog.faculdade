/*Faça um programa que recebe como entrada o nome de um arquivo texto.
Seu programa deve calcular e exibir a quantidade de vezes que cada uma
das vogais aparecem no arquivo (deve ser case insensitive e não precisa
incluir vogais acentuadas na contagem).*/

#include <stdio.h>
#include <string.h>

int main(){

      FILE *arq;
      char nome[50];

      printf("Insira o nome do seu arquivo: ");
      scanf("%s" , nome);

      arq = fopen(nome ,"r");

      if( arq == NULL){

            printf("ERRO");
            return -1;

      }
      //fazer a leitura de caracter por caracter e verificar se eh vogal
      int caracter;
      //contadores de vogais
      int a = 0;
      int e = 0;
      int i = 0;
      int o = 0;
      int u = 0;

      caracter = getc(arq);

      //enquanto eu nao chegar no final do arquivo,continuo a verificacao
      while ( !feof(arq) ){

            if( caracter == 'a' || caracter == 'A'){
                  a++ ;
            
            }else if( caracter == 'e' || caracter == 'E' ){
                        e++;

            }else if( caracter == 'i' || caracter == 'I' ){
                        i++;

            }else if( caracter == 'o' || caracter == 'O' ){
                        o++;

            }else if( caracter == 'u' || caracter == 'U' ){
                        u++;

            }

            caracter = getc(arq);

      }
      //    evibindo acontagem 

      printf("\na %d \n e %d \n i %d \n o %d \n u %d \n" ,  a , e , i , o ,u );

      fclose(arq);

      return 0 ;
}