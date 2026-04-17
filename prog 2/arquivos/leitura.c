//objetivos:abrir um arquivo,ler o que ta no arquiv,imprimir e fechar o arquivo

#include <stdio.h>

int main(){

      FILE *arquivo;
      
arquivo = fopen( "arquivo.leitura.txt" , "r+" ); 
//"r+" abro um arquivo para leitura e escrita

      //verifico erro na abertura
      if( arquivo == NULL ){
            printf("Erro ao abrir o arquivo!");
            return 1; //encerro
}
//FAZENDO A LEITURA(POR CARACTERE)
      int c; //variavel para guardar os caracteres DURANTE A LEITURA

      // fgetc - le o caractere,
      c = fgetc(arquivo); // lendo o caractere e guarda em c( e o curso andou)
      
//estrutura de repeticao para percorrer meus caracteres ler eles e imprimir

      while(!feof(arquivo)){ //enquanto eu nao chegar no final do arquivo,continua

            putchar(c); //imprime o que esta guardado em c
            c= fgetc(arquivo); //le e guarda em c

      }
      fclose(arquivo);
      return 0;

}