//objetivos:criar um arquivo,abrir,escrever e fechar

#include <stdio.h>

int main(){

      FILE *arquivo;

arquivo = fopen( "Primeiro_arquivo.txt" , "w" ); 
//"w" crio um arquivo vazio para escrita(escrever do zero)

      //verifico erro na abertura
      if( arquivo == NULL ){
            printf("Erro ao abrir o arquivo!");
            return 1; //encerro
}

      fprintf(arquivo, "Testando escrita no meu primeiro arquivo-teste1\n");
      
      
      fclose(arquivo);
      return 0;

}