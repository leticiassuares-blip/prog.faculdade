#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct {

TIPOCHAVE chave;
//outros campos...
} REGISTRO;


typedef struct aux {

REGISTRO reg;
struct aux* prox;

} ELEMENTO;

typedef ELEMENTO* PONT;

/*Remoção acontece no início.
Inserção acontece no fim. */
typedef struct {

PONT inicio;
PONT fim;

} FILA;

void inicializarFila(FILA* f) {

      f->inicio = NULL;
      f->fim = NULL;

}

int tamanho(FILA* f) {

      PONT end = f->inicio;
      int tam = 0;

      while (end != NULL){

      tam++;
      end = end->prox; 
}
      return tam; 
}


void exibirFila(FILA* f){

      PONT end = f->inicio;
      printf("Fila: \" ");

      while (end != NULL) {

      printf("%i ", end->reg.chave);

      end = end->prox; 
}
      printf("\"\n"); 
}


bool inserirNaFila(FILA* f,REGISTRO reg) {

            //reservar espaco na memoria
            PONT novo = (PONT) malloc(sizeof(ELEMENTO));

            if (novo==NULL) //erro de alocacao
            return false;

            //caso contrario
            novo->reg = reg;
            novo->prox = NULL;//entrou na fila,agora ele é o ultimo elemento da fila

            //agora eu encaixo em relacao ao inicio e fim da fila
            if (f->inicio==NULL){// nao tem ninguem na fila

                  f->inicio = novo; // o inicio agora é esse cara
            
            }

            else //tem elementos na fila?
            
            f->fim->prox = novo; 
            // o pronteiro prox do antigo ultimo elemento agora recebe 
            //o endereco do novo elemento inserido na fila
            f->fim = novo;// agora o novo fim é o endereco do elemento adicionado a fila

            return true;

}
//se vou retirar alguem da fila,tem q ser do inicio
bool excluirDaFila(FILA* f, REGISTRO* reg) {

      //a fila ta vazia?,se esta vazia nao consigo retirar ninguem
      if (f->inicio==NULL) 
      return false;

      //caso contrario

      //ponteiro reg recebe as informacoes da estrutura reg q ta no inicio da fila
      *reg = f->inicio->reg;
     
      PONT apagar = f->inicio;//recebe o endereco do inicio
      f->inicio = f->inicio->prox;//o  inicio recebe o endereco do prox
      free(apagar);

      if (f->inicio == NULL) 
      f->fim = NULL;
      
      return true; 

}

void reinicializarFila(FILA* f) {

      PONT end = f->inicio;

      //percorro a fila toda e apago ela
      while (end != NULL) {

      PONT apagar = end;
      end = end->prox;
      free(apagar);

}
//dps o inicio vira null e o fim tbm
f->inicio = NULL;
f->fim = NULL;
}