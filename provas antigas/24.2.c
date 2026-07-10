#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char carac; 
} REGISTRO;

typedef struct aux {
REGISTRO reg;
struct aux* prox; 
} ELEMENTO;

typedef struct {
ELEMENTO* inicio;
int tamanho; 
} LISTA;

void inicializarLista(LISTA* l) {
l->inicio = NULL;
l->tamanho = 0;
}

int tamanhoLista(LISTA* l) {
return l->tamanho; 
}

void reinicializarLista(LISTA* l) {

      ELEMENTO* end = l->inicio;

      while (end != NULL) {
      ELEMENTO* apagar = end;
      end = end->prox;

      free(apagar); 

}
inicializarLista(l); 
}

char* geraLinhaString (LISTA* l) {

int tam=tamanhoLista(l);

char* linha=malloc(sizeof(char)*(tam+1));

      if (linha!=NULL) {

      ELEMENTO* end = l->inicio;

      int i=0;

      while (end != NULL) {
      *(linha+i)=end->reg.carac;
      end = end->prox;
            i++; 
}
      *(linha+tam)='\0';

}

      reinicializarLista(l);

      return linha;
}

//merge sem o mergesort
void intercala(char linha[],int i, int m, int f) {
int t1=m-i+1;
int t2=f-m;
char s1[t1];
char s2[t2];
int x, y, z;
for(x=0; x<t1; x++)
s1[x]=linha[i+x];
for(y=0; y<t2; y++)
s2[y]=linha[m+1+y];
x=0; y=0; z=i;
while (x<t1 && y<t2) {
if(s1[x]<s2[y]) {
linha[i]=s1[x];
x++; }
else {
linha[i]=s2[y];
y++; }
i++; }
for(; x<t1; x++, i++)
linha[i]=s1[x];

}

void inserefim( LISTA *l , REGISTRO carac){

int fim = tamanhoLista(l) - 1;

ELEMENTO *novo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
ELEMENTO *end = l->inicio;

if(novo != NULL){

      if( end == NULL){//lista ta vazia

            l->inicio = novo;
            novo->prox = NULL;
            novo->reg = carac;
            l->tamanho++;

       
      }else{//lista nao esta vazia
      for( int i = 0 ; i < fim ; i++){

            end = end->prox;
            
      }      
      end->prox = novo;
      novo->prox =NULL;
      novo->reg = carac;
      l->tamanho++;
}           
}
}
REGISTRO excluifim( LISTA *l ){

ELEMENTO *apagar = l->inicio;

int fim = tamanhoLista(l) - 1;

      if(apagar == NULL ){//lista vazia


      }


}

int main() {

LISTA et;
REGISTRO x;

char* linha;
inicializarLista(&et);
x.carac = getchar();

      while (x.carac != '~') {

      trataNovoCaracter(&et, x);
      x.carac = getchar(); 
}

      linha=geraLinhaString(&et);
      int tam=strlen(linha);
      ordenaString(linha,0,tam-1);
      printf("[%s]\n",linha);
      free(linha);
return 0; 
}