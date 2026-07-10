/*Exercício 1: Faça um programa que leia o arquivo “entrada.bin” , 
copie a string contida
nele, e coloque-a no arquivo “saída.txt”*/

#include <stdio.h>
#include <string.h>

int leitura_bin(FILE *fbin , FILE *arq ){

      char palavra[6];
      char copia[6];
      rewind(fbin);
      rewind(arq);

while(fread( palavra , sizeof(palavra) , 1 , fbin) == 1){

      strcpy(copia , palavra);
       fprintf(arq , "%s\n" , copia );

      

}

return 0;
}

int main(){

      FILE *fbin;
      FILE *arq;

      fbin = fopen("entrada.bin" , "wb+");

      if( fbin == NULL){

            return -1;
      }

      arq = fopen ("saida.txt", "w+");

      if( arq == NULL){

            return -1;
      }
      char palavra[] = "barao" ;
      char palavra2[] = "casao" ;
      
      fwrite(&palavra , sizeof(palavra) , 1 , fbin );
      fwrite(&palavra2 , sizeof(palavra2) , 1 , fbin );


      leitura_bin(fbin ,  arq);
fclose(fbin);
fclose(arq);
      return 0;
}
