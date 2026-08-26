/*Faça um programa que percorra um arquivo texto, indicado pelo
usuário, e encontre um padrão, também indicado durante a chamada
do programa (via linha de comando). Cada linha do arquivo de
entrada possui colunas de até 80 caracteres. O programa deve
informar o número da linha e exibir a linha na saída padrão.

indicar o arquivo que ja existe
indicar o trecho

retornar a o trecho e o restante da linha (imprimir)*/


#include <stdio.h>
#include <string.h>
#define MAX 80

int main(){

      char linha[80];
      char trecho[80];//nome do trecho
      char nome[50];//vetor de caracteres-nome do arquivo
      FILE *arquivo;
      char *encontra;//ponteiro para usar a funcao strstr
      int num = 1;//indica o numero da linha
      
      printf("Insira o nome do arquivo: ");
      scanf("%s" , nome);

      arquivo = fopen ( nome , "r");

      if(arquivo == NULL){

            printf("Erro na abertura do arquivo!");
            return 1;
      }

      printf("Indique o texto que você quer encontrar:");
      scanf("%s",trecho);

//programa precisa ler strings para identificar o trecho
     
fgets(linha,MAX,arquivo);

      while(!feof(arquivo)){

      encontra = strstr(linha ,trecho);

            if(encontra != NULL){
                printf("\n%d %s\n",num , encontra);
      }
            
            fgets(linha,MAX,arquivo);
                  num ++;//a cada fgts é uma linha nova lida
      }
      fclose(arquivo);
      return 0;
}