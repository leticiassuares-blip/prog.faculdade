#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{

int tam,i;
char *g[3];
tam = sizeof(char);
g[0] = (char *)malloc(13*tam);
strcpy(g[0], "Computacao I");
g[1] = (char *)malloc(23*tam);
strcpy(g[1], "Sistemas de Informacao");
g[2] = (char *)malloc(14*tam);
strcpy(g[2], "Computacao II");
for (i=0;i<3;i++)
free(g[i]);

return 0;

}