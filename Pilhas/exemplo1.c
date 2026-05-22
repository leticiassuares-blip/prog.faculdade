/*Exercício 2 — Sistema de Desfazer Texto (Undo) usando Pilha Estática
Um editor de texto deseja implementar um sistema simples de:
CTRL + Z

para desfazer ações realizadas pelo usuário.

O sistema utilizará uma pilha estática para armazenar:

ações realizadas;
na ordem em que aconteceram.

Como a pilha segue a lógica:

LIFO (Last In First Out)

a última ação realizada será a primeira a ser desfeita.

Cada ação deve armazenar
o tipo da ação;
o texto envolvido;
a posição do texto.


Exemplo esperado

Após registrar:

digitou "Oi"
apagou "A"
digitou "ChatGPT"
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    char tipo[20];
    char texto[50];
} ACAO;

typedef struct {
    ACAO A[MAX];
    int topo;
} PILHA;

void inicializarPilha(PILHA *p){
      p-> topo = -1;
}
//inserindo
bool push(PILHA *p, ACAO acao){

      if(p->topo >= MAX -1){

            return false;

      }else{
            p->topo = p->topo+1;
            p->A[p->topo] = acao;
            return true;
      }
}
//removendo
bool pop(PILHA *p, ACAO *acao){

      if(p->topo == -1){

            return false;

      }else{
            *acao = p->A[p->topo];
            p->topo = p->topo-1;
            return true;
      }

}

void exibirAcoes(PILHA *p){

      printf("As acoes sao: \n");
      int i;

      for( i = p->topo ; i >= 0 ; i--){

             printf(" %s  %s \n" , p->A[i].tipo  , p->A[i].texto );
      }
}
int main(){

      PILHA manipula;
      ACAO ato;

      inicializarPilha(&manipula);//pilha vazia

      strcpy( ato.tipo , "Digitou");
      strcpy( ato.texto , "PROG 2");
      push(&manipula , ato );

      strcpy( ato.tipo , "Apagou");
      strcpy( ato.texto , "teste de pilha");
      push(&manipula , ato );

      strcpy( ato.tipo , "Digitou");
      strcpy( ato.texto , "estudando");
      push(&manipula , ato );

      strcpy( ato.tipo , "Apagou");
      strcpy( ato.texto , "Prova 1");
      push(&manipula , ato );

      exibirAcoes(&manipula);

      
      pop(&manipula , &ato);


      exibirAcoes(&manipula);

      return 0;

}