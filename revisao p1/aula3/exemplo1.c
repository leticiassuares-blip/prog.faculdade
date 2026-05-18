#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{

int tam,i;
char *g[3];

tam = sizeof(char); //calcula o tamanho de um char em bytes


g[0] = (char *)malloc(13*tam); //reservo espaco para 13 caracteres
strcpy(g[0], "Computacao I");

g[1] = (char *)malloc(23*tam);//reservo espaco para 23 caracteres
strcpy(g[1], "Sistemas de Informacao");

g[2] = (char *)malloc(14*tam);///reservo espaco para 14 caracteres
strcpy(g[2], "Computacao II");// strcpy (dest, fonte)

for (i=0;i<3;i++)

free(g[i]); //libero o espaco da memoria

return 0;

}