/*• Escreva uma função concatena que tem o seguinte
protótipo:
char *concatena(char *s1, char *s2);
A função deve, a partir de duas cadeias de caracteres
(acessadas a partir dos ponteiros s1 e s2), criar uma nova
que é a concatenação da segunda cadeia ao final da
primeira. Esta nova cadeia deve ser alocada dinamicamente
pela função cujo retorno será um apontador para esta.
• Faça um programa principal para testar a função
implementada.*/

/*char *s1 == char s1[]
s1 = "gil"
s2 = "berto"
s3 = "gilberto"*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *s1, char *s2){

int tam;
int i = 0 , j = 0;
char *s3;

      while (s1[i] != '\0'){
            i++;

      }
       while (s2[j] != '\0'){
            j++;

      }

      tam = ((i + j ) /  4 ) + 1; //1 -> caracter '\0' 
      
      
      s3 = (char *)malloc(sizeof(tam)) ;

      for( i = 0 ; s1[i] != '\0' ; i++){

            s3[i] = s1[i];

      }

      for( j = 0 ; s2[j] != '\0' ; j++){

            s3[i] = s2[j];
                  i++;
      } s3[i] = '\0';

return s3;
}

int main(){

char *s4 = "ABCD";
char *s5 = "EFGHIJKL";
char *s6;

s6 = concatena( s4 , s5);

printf("%s", s6);
free(s6);
return 0;

}