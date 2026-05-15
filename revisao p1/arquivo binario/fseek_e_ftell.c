#include <stdio.h>

int main() {

    FILE *arq;
    char c;

    arq = fopen("dados.txt","r");

    printf("%ld\n", ftell(arq));
    //comeco o cursor no inicio
    // AEIOU
    // ˆ

    fseek(arq ,-2  , SEEK_END );
     // AEIOU
     //    ˆ


    fscanf(arq,"%c",&c);//le o caracter ,anda com o cursor pro prox caracter

    printf("%ld\n", ftell(arq));
    // AEIOU
    //     ˆ

    fclose(arq);

    return 0;
}