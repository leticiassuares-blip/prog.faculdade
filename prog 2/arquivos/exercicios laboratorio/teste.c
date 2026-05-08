
#include<stdio.h>


int main(){

      int i = 0;
      int tam = 0;
      char linha[4]="LUA";

      //descobrir o tamanho do vetor de caracteres,tamanho da a palavra
      while( linha[tam] != '\0' ) {
            tam++;

       }

//inversao 
char guarda;
      for(i = 0 ; i < tam/2 ; i++){
      
            guarda = linha[i];
          linha[i] = linha[tam - 1 - i];
            linha[tam - 1 - i] = guarda;
            
            }
printf("%s" , linha);
 return 0;
}