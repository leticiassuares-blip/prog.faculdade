/*Faça um programa que percorra um arquivo texto, indicado pelo
usuário, e encontre um padrão, também indicado durante a chamada
do programa (via linha de comando). Cada linha do arquivo de
entrada possui colunas de até 80 caracteres. O programa deve
informar o número da linha e exibir a linha na saída padrão.

indicar o arquivo que ja existe
indicar o trecho

retornar a o trecho e o restante da linha (imprimir)*/


#include <stdio.h>
#define MAX 80

int main(){

      char linha[80];
      char nome[50];//vetor de caracteres
      FILE *arquivo;
      
      printf("Insira o nome do arquivo: ");
      scanf("%s" , nome);

      arquivo = fopen ( nome , "r");

      if(arquivo == NULL){

            printf("Erro na abertura do arquivo!");
            return 1;
      }

      char trecho[80];

      printf("Indique o texto que você quer encontrar:");
      scanf("%s",trecho);

//programa precisa ler strings para identificar o trecho

fgets(linha,MAX,arquivo);

      while(!feof(arquivo)){

            if(){
                  puts(linha);
      }
            
            fgets(linha,MAX,arquivo);

      }
      fclose(arquivo);
      return 0;
}