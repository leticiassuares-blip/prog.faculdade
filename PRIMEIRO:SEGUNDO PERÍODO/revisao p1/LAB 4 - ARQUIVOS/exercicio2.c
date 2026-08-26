/*Faça um programa que recebe como entrada o nome de um arquivo
texto e o nome de um arquivo de saída. Esses dados devem vir da
chamada do programa (via linha de comando). No arquivo de saída,
deverá ser escrito o arquivo de entrada com os caracteres em
maiúsculo. Veja o exemplo a seguir.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//funcao que converte cada caracter para maiusculo

char converte ( int c){

      if( c >= 'a' && c <= 'z'){

            c = c - 32 ; 
            return c;
      }
      return c;
}


/*linha de comando
int argc ; quantidade de caracter
 char *argv[] ; cada caracter -referente a posicao*/
int main(int argc, char *argv[]){

      //verificar se tem 3 argumentos
      if( argc != 3){

            printf("Erro de execucao! Insira argumentos validos");
            return -1;
      }

      FILE *arqEntrada;
      FILE *arqSaida;

      /*char nomeEntrada[50];
      char nomeSaida[50];

      printf("Insira o nome do arquivo de entrada: ");
      scanf("%s" ,  nomeEntrada);

      //abertura do arquivo de entrada*/

      arqEntrada = fopen(argv[1] , "r");

      if( arqEntrada == NULL){

            printf("ERRO");
            return -1;

      }

     /* printf("Insira o nome do arquivo de saida: ");
      scanf("%s" , nomeSaida);*/

      //abertura do arquivo de saida
      arqSaida = fopen( argv[2] , "w+");

      if( arqSaida ==  NULL ){

            printf("ERRO");
            return -1;

      }
      //pegar cada caracter do arquivo de entrada,chamo a funcao
      //converto e coloco ese caracter no arquivo de saida

      int guarda;

      guarda = getc(arqEntrada);

      while( !feof(arqEntrada)){

            int retorno = converte(guarda);
            putc( retorno , arqSaida);
            guarda = getc(arqEntrada);

      }

      fclose(arqEntrada);
      fclose(arqSaida);
      return 0;
}

