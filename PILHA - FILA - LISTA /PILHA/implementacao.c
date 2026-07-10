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

TIPOCHAVE chave; // TIPOCHAVE é int
//outros campos...

} REGISTRO;

//ex: REGISTRO r ; r.chave = 3;

typedef struct aux {

REGISTRO reg;//cada ELEMENTO tem um REGISTRO
struct aux* prox;
//"um ponteiro para outro elemento da mesma estrutura"
//"ponteiro para uma estrutura do tipo aux"

} ELEMENTO;
/*
END 1000

+-----------+
| reg = 10  |
| prox=2000 |
+-----------+

END 2000

+-----------+
| reg = 20  |
| prox=3000 |
+-----------+

END 3000

+-----------+
| reg = 30  |
| prox=NULL |
+-----------+
1000 ---> 2000 ---> 3000 ---> NULL
*/

typedef ELEMENTO* PONT;
//ponteiro que acessa a estrutura
//elemento

//LIFO

//pilha guarda só quem está no topo
//guarda um ponteiro para o elemento do topo
typedef struct {
PONT topo; // ELEMENTO *topo
} PILHA;
/*

1000 ---> 2000 ---> 3000 ---> NULL

PILHA p

topo
 |
 v
900

novo 900
+----------+
| reg = 9  |
| prox=1000|
+----------+


1000
+----------+
| reg = 8  |
| prox=2000|
+----------+

2000
+----------+
| reg = 5  |
| prox=3000|
+----------+

3000
+----------+
| reg = 2  |
| prox=NULL|
+----------+
*/

void inicializarPilha(PILHA* p) {

p->topo = NULL; //PILHA VAZIA

}

//percorrer a pilha todo
int tamanho(PILHA* p) {

// ELEMENTO *PONT ; 
//PONT end equivale a ELEMENTO *end 
//ponteiro que acessa a estrutura ELEMENTO
PONT end = p->topo; 
//PONT end recebe o endereco de memoria do topo

int tam = 0;
      while (end != NULL) { //ultimo elemento 
      
            tam++;
      end = end->prox; // aponta para o proximo elemento
}

      return tam; 
}

bool estaVazia(PILHA* p) {

      if (p->topo == NULL){

            return true;
      }
      return false;
}

//percorrer a pilha e listar os elementos dela
void exibirPilha(PILHA* p) {

//ELEMENTO *end 
//PONT end recebe o endereco de memoria do topo
PONT end = p->topo;
      printf("Pilha: \" ");

      while (end != NULL) {

      printf("%i ", end->reg.chave);
      end = end->prox; 
}
      printf("\"\n"); 
}

//POP
bool inserirElemPilha(PILHA* p, REGISTRO reg){

//ELEMENTO *novo
//reservar espaco de memoria
PONT novo = (PONT) malloc(sizeof(ELEMENTO));

      if (novo==NULL){//checagem
      return false;
      }

      //insercao
      novo->reg = reg;
      novo->prox = p->topo;// topo da pilha agora será esse
      p->topo = novo;
      return true;

}
//PUSH
bool excluirElemPilha(PILHA* p, REGISTRO* reg){

      //se a pilha ta vazia
      if ( p->topo == NULL) {
            return false;
      }

      *reg = p->topo->reg;//recebe o valor de quem ta no topo em reg
//ELEMENTO *apagar
      PONT apagar = p->topo; //recebe o endereco do topo
      p->topo = p->topo->prox; // o novo endereco do topo é o prox
      free(apagar);
      return true; 
}
/*
PILHA p

topo
 |
 v
2000

*reg = 8
apagar 1000


2000
+----------+
| reg = 5  |
| prox=3000|
+----------+

3000
+----------+
| reg = 2  |
| prox=NULL|
+----------+
*/

void reinicializarPilha(PILHA* p) {

PONT apagar; // ELEMENTO *apagar
PONT posicao = p->topo; // ELEMENTO *posicao
//recebe o endereco de onde topo aponta

      while (posicao != NULL) {

      apagar = posicao;
      posicao = posicao->prox;
      free(apagar);
 }
      p->topo = NULL; 

}
/*

1000 ---> 2000 ---> 3000 ---> NULL

PILHA p

topo
 |
 v
NULL

posicao null

*/

