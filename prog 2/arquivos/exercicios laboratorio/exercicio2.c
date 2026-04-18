/*Faça um programa que recebe como entrada o nome de um arquivo
texto e o nome de um arquivo de saída. Esses dados devem vir da
chamada do programa (via linha de comando). No arquivo de saída,
deverá ser escrito o arquivo de entrada com os caracteres em
maiúsculo. Veja o exemplo a seguir.

os dados devem vir da LINHA DE COMANDO , significa que o usuário vai passar o nome do arquivo
diretamente no terminal, na hora de executar o programa.

*/

#include <stdio.h>

//funcao que converte para maiuscula
char maiuscula(char c){

//caso seja minuscula (add 32 - equivale a letra maiuscula
if (c >= 'a' && c <= 'z'){
      return c - 32;
}
      return c;
}

int main(){

      FILE *entrada;
      FILE *saida;
      char ent[100]; //vetor de caracteres 
      char sai[100];
     
      //entrada 1- nome do arquivo de entrada
      printf("Insira o nome do seu arquivo de entrada: ");
      scanf("%s", ent);

      entrada = fopen( ent ,"r");

      if ( entrada == NULL ){
      //verificacao se houve erro de endereçamento
            printf("Erro na abertura do arquivo");
            return 1;
      }
      //entrada 2- nome do arquivo de saida

      printf("Insira o nome do seu arquivo de saida: ");
      scanf("%s", sai);

        saida = fopen( sai ,"r+");

      if ( saida == NULL ){
      //verificacao se houve erro de endereçamento
            printf("Erro na abertura do arquivo");
            return 1;
      }

      //ler cada caracter escrito e preciso passar pra maiusculo
      int guarda;//variavel aux que vai guardar cada caracter

      guarda = fgetc(entrada);//cursor esta na letra inicial

      while(!feof(entrada)){//ENQUANTO NAO CHEGAR NO FINAL DO ARQUIVO,
      //CONTINUA LENDO
      guarda = maiuscula(guarda);

      fputc(guarda,saida);
      guarda = fgetc(entrada);

      }

      fclose(entrada);
      fclose(saida);
      return 0;
}


