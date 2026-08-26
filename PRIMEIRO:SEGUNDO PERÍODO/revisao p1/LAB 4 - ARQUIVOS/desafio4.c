/*• Faça um programa que recebe como entrada o nome de um arquivo texto
e o nome de um arquivo de saída. Esses dados devem vir da chamada do
programa (via linha de comando). Cada linha do arquivo de entrada possui
até 200 caracteres. No arquivo de saída, deverá ser escrito o arquivo de
entrada com o conteúdo de cada linha na ordem inversa. Veja um
exemplo:*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 201


int main( int argc , char *argv[]){


      if(argc != 3){

            printf("Erro de execução! Insira argumentos válidos");
            return -1;
      }

      FILE *arq_entrada;
      FILE *arq_saida;

      arq_entrada = fopen( argv[1] , "r");//leitura

      if( arq_entrada == NULL){

            printf("Erro de abertura do arquivo");
            return -1;    
      }

      arq_saida = fopen( argv[2] , "w+");//leitura  escrita

      if( arq_entrada == NULL){

            printf("Erro de abertura do arquivo");
            return -1;    
      }

char linha[201];
char nova_linha[201];
/* A função strlen (abreviação de string length) 
é utilizada para calcular o comprimento de uma cadeia de caracteres,
 retornando a quantidade de caracteres existentes antes 
 do caractere nulo terminador \0 */
int tamanho = 0;


      while (fgets( linha , 201 , arq_entrada) != NULL){

            tamanho = strlen( linha );
            int i ;

      if( linha[tamanho - 1] == '\n'){

            tamanho--;
      }

      for (  i = 0 ; i < tamanho  ; i++ ){

            nova_linha[i] = linha [tamanho - i - 1];

      }
            nova_linha[i] = '\n';
            nova_linha[i+1] = '\0';

               fputs(nova_linha , arq_saida);

}

fclose(arq_entrada);
fclose(arq_saida);
}