/*• Faça um programa que recebe como entrada o nome de um arquivo texto
e o nome de um arquivo de saída. Esses dados devem vir da chamada do
programa (via linha de comando). Cada linha do arquivo de entrada possui
até 200 caracteres. No arquivo de saída, deverá ser escrito o arquivo de
entrada com o conteúdo de cada linha na ordem inversa. Veja um
exemplo:

arquivo de entrada e saida já existem,só preciso inverter o conteudo
-NAO VOU USAR LINHA DE COMANDO-
*/

/*Oi Letícia. Então, para fazer essa função você pode pensar que,
 quando inverte a string, o primeiro elemento dela passa ser o último 
 e vice-versa. Pensando na string como um vetor, o elemento na posição 
 0 você tem que passar para a última posição, o na posição 1 tem que ir 
 para penúltima e assim por diante. Para fazer isso, você precisa do tamanho
  da string como condição de parada desse loop, que pode conseguir usando a 
  função de strlen da biblioteca string.h ou verificando se a sua string na 
  posição i == \0. Nisso, você pode ir escrevendo direto no arquivo caracter
   por caracter conforme for invertendo ou inverter a string inteira e guardar
    ela em outra variável e escrever essa nova variável de uma vez.*/

#include <stdio.h>
#include <string.h>
#define MAX 200

int main(){

      char ent[50];
      char sai[50];
      char linha[MAX];
      FILE *entrada;
      FILE *saida;

      //arquivo de entrada
      printf("Digite o nome do seu arquivo de entrada: ");
      scanf("%s", ent);

      entrada = fopen( ent ,"r"); // "r" abre um arquivo que existe para leitura

      if( entrada == NULL){

            printf("Erro de endereçamento do arquivo");
            return 1;

      }

      //arquivo de saida
      printf("Digite o nome do seu arquivo de saida: ");
      scanf("%s", sai);

      saida = fopen( sai ,"r+"); 
//"r+" abre um arquivo que existe para leitura e *escrita*

      if( saida == NULL){

            printf("Erro de endereçamento do arquivo");
            return 1;

      }


//inverter
       while(!feof(entrada)){//ENQUANTO NAO CHEGAR NO FINAL DO ARQUIVO,
      //CONTINUA LENDO
      
      fgets(linha,MAX,entrada);//cursor esta na letra inicial
      
      //descobrir o tamanho do vetor de caracteres,tamanho da a palavra-> strlen(linha) 
       int tam = strlen(linha);
            char linha2[MAX];//novo vetor de caracteres que pega a palavra invertida

            if(linha[tam-1] == '\n'){
                  linha[tam-1]= '\0';
                  tam --;

            }
                  for( int i = 0 ; i < tam ; i++ ){
                        linha2[i] = linha[tam-i-1];
                  }
                  linha2[tam] = '\0';

                  fputs(linha2 , saida);
                  fputc( '\n' , saida );
            }
      fclose(entrada);
      fclose(saida);
      return 0;

}
