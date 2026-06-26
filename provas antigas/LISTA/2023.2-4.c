/*Considere a estrutura de dados abaixo que implementa uma lista ligada, bem como a função
exibirLista que mostra em tela os elementos da lista ligada. Escreva uma função que remova
todos os números repetidos da lista ligada, ou seja, mantém apenas uma cópia do(s) número(s) que
aparecer(em) mais de uma vez e elimina todas as demais repetições. Para o desenvolvimento de sua
solução, considere que os registros já se encontram armazenados em ordem crescente do valor do
campo numero.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int numero;
} REGISTRO;

typedef struct aux {
REGISTRO reg;
struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
PONT inicio;
} LISTA;

void exibirLista (LISTA* l){

      PONT end = l->inicio;

      printf("Lista: \" ") ;

      while (end != NULL) {

      printf("%i ", end->reg.numero);
      end = end->prox;
      }
      printf("\"\n"); 
}

//percorrer a lista e checo as repeticoes
//se repetir,dou free e reorganizo a ordem
int RemocaoRepetidos( LISTA *l){

PONT percorre = l->inicio;
//percorrer a lista e checar cada posicao

//a lista ta vazia? nao consigo remover ninguem
            if( percorre == NULL){

                  return -1;

            }
PONT seguinte = percorre->prox;
PONT apagar; //remove o que está repetido

                  while(seguinte != NULL){

      if( percorre -> reg.numero == seguinte ->reg.numero ){
                  
                  apagar = seguinte;
                  seguinte = seguinte->prox;
                  percorre->prox = seguinte;
                  free(apagar);

                  }else{
                  
                  percorre = seguinte;
                  seguinte = seguinte ->prox;
                  
                  }

            }
            return 0;
}


