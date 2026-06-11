
#include <stdio.h>
#include <stdlib.h>
#define LIN 3
#define COL 2

intmain(){

int *matriz2[LIN], i, j;
for (i=0; i<LIN; i++)
{

matriz2[i] = (int *) malloc (COL * sizeof (int));
if (!matriz2[i])
{

printf ("Erro de alocacao de memoria\n");
return -1;

}

}
for (i=0; i<LIN; i++)

for (j=0; j<COL; j++)
{

printf ("Matriz[%d][%d]: ",i,j);
scanf ("%d", matriz2[i] + j); // acessa as posicoes

}

for (i=0; i<LIN; i++)
{

for (j=0; j<COL; j++)

printf ("[%d] ", *(matriz2[i] + j)); // acessa os conteudos

printf("\n");
return 0;
}
}