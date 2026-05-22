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
    int posicao;
} ACAO;

typedef struct {
    ACAO A[MAX];
    int topo;
} PILHA;

void inicializarPilha(PILHA *p);

bool push(PILHA *p, ACAO acao);

bool pop(PILHA *p, ACAO *acao);

void exibirAcoes(PILHA *p);