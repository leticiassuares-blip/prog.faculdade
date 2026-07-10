/*A conversão de números inteiros, na base 10,
para outras bases numéricas se dá através de
sucessivas divisões de um dado valor n pelo
valor da base na qual se queira converter.

Faça uma função para obter a conversão
numérica, utilizando uma pilha, de Decimal
(base 10) para Binário (base 2).
*/

/*Implementação da Pilha DINAMICA
alocaco sob demanda 
*/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE; 

typedef struct {

TIPOCHAVE chave; // valores que entram na pilha

} REGISTRO;


typedef struct aux {

REGISTRO valor;
struct aux* prox; //acessa o endereco de memoria do prox

} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
PONT topo; // ELEMENTO *topo
} PILHA;

/*

1000 ---> 2000 ---> 3000 ---> NULL

PILHA p

topo
 |
 v
1000

1000
+----------+
| valor = 8|
| prox=2000|
+----------+

2000
+----------+
| valor = 5|
| prox=3000|
+----------+

3000
+----------+
|valor = 2 |
| prox=NULL|
+----------+
*/

//POP
bool inserirElemPilha(PILHA* p, REGISTRO reg){

//ELEMENTO *novo
PONT novo = (PONT) malloc(sizeof(ELEMENTO));

      if (novo==NULL){//checagem
      return false;
      }

      novo->valor = reg;
      novo->prox = p->topo;// topo da pilha agora será esse
      p->topo = novo;
      return true;

}

 void base_dois(int n , PILHA* p){

REGISTRO resto;//representa o resto da divisao

      if( n == 0 || n == 1 ){ 

            resto.chave = n;
      inserirElemPilha( p , resto );
              }

      while( n != 1){

            resto.chave = n % 2; //resto
            n = n / 2;
              
        inserirElemPilha( p , resto);

      if( n == 0 || n == 1 ){ //final da divisao,quociente vira o topo da pilha

            resto.chave = n;
      inserirElemPilha( p , resto );
              }

      }
     
}

void exibirPilha(PILHA* p) {

//ELEMENTO *end 
//PONT end recebe o endereco de memoria do topo
PONT end = p->topo;
      printf("Pilha: \" ");

      while (end != NULL) {

      printf("%i ", end->valor.chave);
      end = end->prox; 
}
      printf("\"\n"); 
}

void inicializarPilha(PILHA *p){

      p->topo = NULL;
}

int main(){

      PILHA p;//variavel que acessa a estrutura do tipo pilha
      inicializarPilha(&p);//criando a pilha
      //REGISTRO resto;
      int decimal;

      printf("Troca de base,insira um valor na base 10: ");
      scanf("%d" , &decimal);
      
      base_dois(decimal , &p);

      exibirPilha(&p);

      return 0;
}