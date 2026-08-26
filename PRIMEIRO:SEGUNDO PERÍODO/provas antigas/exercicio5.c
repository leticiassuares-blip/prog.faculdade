/*a) Os alunos de uma turma de Ciência de Computaria fizeram três avaliações: duas
provas e um trabalho. 

Escreva um programa que leia do teclado o nome e as três notas
de um aluno dessa turma nas avaliações, ordene elas de forma crescente , salve as notas
em uma lista ligada dinâmica. e as grave em um arquivo texto na seguinte ordem: nome
da materia, nota da primeira prova (P1), nota da segunda prova (P2) e um trabalho T.
Faça isso para as matérias PROG, ORGDADOS e DISCRETA. 
O nome do arquivo de
saída deverão ser solicitados ao usuário. Em seguida, abra o arquivo criado usando um
editor de textos qualquer e verifique o resultado do programa.

LER NOME,TRES NOTAS

ORDENAR AS NOTAS
SALVAR NA LISTA
GRAVAR AS NOTAS EM UM ARQUIVO DE TEXTO

nome
da materia,
 nota da primeira prova (P1),
  nota da segunda prova (P2) 
  e um trabalho T.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bolha ( REGISTRO *m , int n){

int i ,ult ,aux;

      for( ult = n-1 ; ult > 0 ; ult-- ){

        for( i = 0 ; i < ult ; i++ ){

            if( () ){


            }
      }    
      }

}
typedef struct {

char materia[100];
int p1;
int p2;
int trabalho;

} REGISTRO;

typedef struct aux {

REGISTRO reg;
struct aux* prox;

} ELEMENTO;

typedef ELEMENTO* PONT;

//pode inserir e remover
// de qualquer posicao
typedef struct {

PONT inicio;

} LISTA;

void inicializarLista(LISTA* l){
      
l->inicio = NULL;

}
  int main(){

      FILE *arq;
      char nome[100];
      REGISTRO *m;

      int n = 3;

      for( int i = 0 ; i< n ;  i++){

            printf("nome da materia:\n");
            scanf("%s" , (m+i)->materia);

            printf("p1:\n");
            scanf("%d" , &(m+i)->p1);

            printf("p2:\n");
            scanf("%d" , &(m+i)->p2);

            printf("trabalho:\n");
            scanf("%d" , &(m+i)->trabalho);

      }


      printf("NOME DO ARQUIVO DE TEXTO");
      scanf("%s",nome);

      arq = fopen(nome , "w+");

      if( arq == NULL){

            return -1;
      }


      return 0;
  }

/*
b) Crie outra função deve calcular a média de cada aluno considerando a seguinte
equação: média=(((P1+P2)/ 2)∗0.8)+(T∗0.2). Seu programa deverá gravar em um arquivo
binário: uma pilha com o nome de cada matéria e sua respectiva média.*/

