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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*char *s1 == char s1[]
s1 = "gil"
s2 = "berto"
s3 = "gilberto"

→contar tamanho
→ alocar memória
→ copiar s1
→ continuar copiando s2
→ finalizar com '\0'
→ retornar s3*/
char *concatena(char *s1, char *s2){

      int i = 0;
      int j = 0;
      int conta_s1 = 0;
      int conta_s2 = 0;
      char *s3; //s3[]
      
      //descobrir o tamanho de s1
      while ( *(s1+i) != '\0'){

            i++;
            conta_s1 ++;
      }

      //descobrir o tamanho de s2
      while ( *(s2+j) != '\0'){

            j++;
            conta_s2 ++;
      }

      int tam = conta_s1 + conta_s2 + 1; // 1 equivale ao '\0'

      s3 = malloc (tam * sizeof(char));


            for(i = 0 ; i < conta_s1  ; i++){

                  *(s3 + i) = *(s1 + i);

      }

      j=0;

       for( conta_s1  ; j < conta_s2  ; j++  ){

                  *(s3 + conta_s1 +j) = *(s2 + j);
                        
      }


    return s3 ;  
}

int main(){

char *v1 = "gil";
char *v2 = "berto";

char *v3 = concatena(v1,v2);

printf("%s" , v3);
return 0;

}