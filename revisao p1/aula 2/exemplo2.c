#include <stdio.h>
#include <string.h>

void strcpy1 (char *dest, char *fonte)
{
int i = 0;
while ((dest[i] = fonte[i]) != '\0')
i++;
}

int main()
{
char a[100], b[] = "Ola mundo";
strcpy1(a, b);
printf("a: %s\nb: %s\n", a, b);
return 0;
}