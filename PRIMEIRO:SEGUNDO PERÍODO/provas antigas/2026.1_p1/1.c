#include <stdio.h>
int main() {
int a[] = {10, 20, 30, 40, 50, 60};
int *pa;
int i = 4;
pa = a;
printf("[1: %d\n", *pa);
pa++;
printf("2: %d\n", *pa);
*(pa+1)=*pa+1;
printf("3: %d\n", *pa);
printf("4: %d\n", *(pa+1));
pa = &a[i];
printf("5: %d\n", *pa);
printf("6: %d\n", *(pa+1));
pa--;
printf("7: %d\n", *pa);
*(pa-1)+=*pa+2;
printf("8: %d\n", *(pa-1));
printf("9: %d\n", *pa-1);
printf("10: %d\n", pa[2]);
return 0;
}