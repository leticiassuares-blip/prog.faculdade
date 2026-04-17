//objetivos:abrir um arquivo,escrever o que ta no arquivo,imprimir e fechar o arquivo

#include <stdio.h>

int main(){

      FILE *arquivo;
      
arquivo = fopen( "arquivo.escrita.txt" , "w+" ); 
//"w+" crio um arquivo para leitura e escrita

      //verifico erro na abertura
      if( arquivo == NULL ){
            printf("Erro ao abrir o arquivo!");
            return 1; //encerro
}
//FAZENDO A ESCRITA(POR CARACTERE)

fputc('C', arquivo);
fputc('A', arquivo);
fputc('S', arquivo);
fputc('A', arquivo);

      fclose(arquivo);
      return 0;

}