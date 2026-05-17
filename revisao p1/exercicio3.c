/*Implemente a função posicao que tem o seguinte
protótipo:
int posicao(char *substr, char *str);
Esta função deve verificar se a cadeia apontada por
substr está presente na cadeia apontada por str e
retornar a posição em que a sub-cadeia aparece em cadeia
(deve ser retornada a posição em que inicia a primeira
ocorrência, mesmo que a substring se repita na string).
• Faça um programa principal para testar a função
implementada.*/

#include <stdio.h>
#define MAX 100

int posicao(char *substr, char *str){

int i = 0; //percorre onde substr aponta
int j = 0; //percorre onde  str aponta
int inicio; // guarda o inicio 

//percorre onde str aponta
     while( *(str + j) != '\0'){

      if( *(str + j) == *(substr + i) ){

            inicio = j;
      
      //percorrer substr e str toda para verificar
      while( ( *(substr + i) != '\0' ) && ( str[ j +i ] == substr[i])){

            i++;

      }if(*(substr + i) == '\0'  ){

            return inicio;

      }
}    
            j++;     
}
return -1 ;
}


int main(){

char nome1[] = "maria";
char nome2[] = "ana maria maria";

int valor;
valor = posicao (nome1 , nome2);

printf ("%d",valor );
return 0;

}