#include <stdio.h>
#include <stdlib.h>
int *f(int x, int y, int *p, int *z) {
int *w;
(*p)++; //  *p = *p + 1 
*p=y;
x+=10; // x = x + 10
w=(int *)malloc(sizeof(int));
(*p)+=y; // *p = *p + y
*w=*p+5;
*z++=x; // primeiro *z= x e depois z++
x-=50;// x = x-50
p=&x;
p=&y;
(*p)--; //*p = *p-1
*z+=y; //*z = *z + y 
y*=10; // y = y*10
*++z=*p; //  z++  e depois *z= *p
return w; }

int main() {
int a=10, b=7, c=50, d[3]={1,2,3};
int *e=f(a, b, &c, d);
printf("a=%d b=%d c=%d *e=%d\n", a, b, c, *e);
for(int i=0; i<3; i++)
printf("d[%i]=%d\n",i,d[i]);
free(e);
return 0; }











