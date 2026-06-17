/*• Faça um programa que percorra um arquivo texto, indicado pelo
usuário, e encontre um padrão, também indicado durante a chamada
do programa (via linha de comando). Cada linha do arquivo de
entrada possui colunas de até 80 caracteres. O programa deve
informar o número da linha e exibir a linha na saída padrão. 
The C library function char *strstr(const
char *haystack, const char
*needle) function finds the first occurrence of
the substring needle in the string haystack.
The terminating '\0' characters are not compared.
• This function returns a pointer to the first
occurrence in haystack of any of the entire
sequence of characters specified in needle, or a null
pointer if the sequence is not present in haystack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* char *strstr(const char *haystack, const char *needle);

procura a agulha no palheiro, ou seja procura 
o que eu quero/preciso em tal lugar(*haystrack)

linha de comando
int argc ; quantidade de caracter
 char *argv[] ; cada caracter -referente a posicao*/

int main( int argc , char *argv[]){

      if( argc != 3){

            printf("Erro de execução! Insira argumentos validos!");
            return -1;
      }

      FILE *arquivo;

      arquivo = fopen( argv[2] , "r");//arquivo já existe

      if( arquivo == NULL ){

            printf("Erro");
            return -1;
      }

      //contador para as linhas 
int lin = 1;
char linha[81];// maximo de caracteres de cada linha do arquivo,contando '/0'

//a cada verificacao do while eu leio o conteudo da linha
      while( fgets( linha , 81 , arquivo) != NULL ){
     
      char *p = strstr( linha , argv[1]); // realiza a primeira busca
            //se encontrou
      if( p != NULL){

            printf("%d " , lin);//posicao da linha q encontrou
            printf("%s" , linha);//linha toda

      }

      lin++;
      }
      
fclose(arquivo);
return 0;

}