#include <stdio.h>
#include <stdlib.h>
#define LIN 3
#define COL 2
int main ()
{
//crio um ponteiro do tipo int e reservo 24 bytes e tem lixo de memoria neles
//esoaco para. 6 inteiros
int * matriz1 = (int *) malloc (LIN * COL * sizeof (int)), i, j;
if (!matriz1)
{

printf ("Erro de alocacao de memoria\n");
return -1;

}
for (i=0; i<LIN; i++)

for (j=0; j<COL; j++)
{

printf("Matriz[%d][%d]: ",i,j);
scanf ("%d", matriz1 + ((i * COL) + j));

}

for (i=0; i<LIN; i++)

{

for (j=0; j<COL; j++)

printf ("[%d] ", *(matriz1 + ((i * COL) + j)));

printf("\n");

}
free(matriz1);
return 0;

}