/*Escolha uma dentre as estruturas de dados a seguir: (i) pilha ou (ii) fila; indicando
explicitamente a estrutura de dados escolhida. A seguir, faça a declaração da estrutura de dados
escolhida, utilizando uma versão com alocação dinâmica de memória (incluindo ponteiros), onde
cada registro é do tipo Tpessoa (conforme apresentada na questão 1). Além disso, implemente as
seguintes funções sobre a estrutura de dados escolhida: (i) uma função para sua inicialização; e (ii)
uma função para inserção de um novo elemento.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//A estrutura escolhida foi  (ii) fila

typedef struct pessoa {
 char nome [30];
 int idade;
 } Tpessoa;

typedef struct aux {

Tpessoa reg;
struct aux* prox;

} ELEMENTO;

typedef ELEMENTO * PONT;

typedef struct {

PONT inicio;
PONT fim;

}FILA; //FIFO- first in first out

// (i) uma função para sua inicialização -> fila vazia , inicio e fim recebem nulo

void inicializacaoFILA( FILA *f){

      f->inicio = NULL;
      f->fim = NULL;

}

//(ii) uma função para inserção de um novo elemento

//LOGICA DA FILA É O PRIMEIRO A ENTRAR É SEMPRE O PRIMEIRO A SAIR
//objetivo:acessar o fim e vou inserir o Tpessoa no fim da fila
int inserirFila( FILA *f , Tpessoa pessoa ){

//RESERVANDO MEMORIA PARA UM NOVO ELEMENTO
PONT novo = (PONT)malloc(sizeof(ELEMENTO));

      if(novo == NULL){
      return -1;//erro de alocacao
      }

//fila ta vazia.
            if( f->inicio == NULL){
                  
            f-> inicio = novo ; //inicio recebe o endereco do novo elemento
            novo->reg = pessoa;
            novo->prox = NULL;
            f->
            

}//caso contrario
//chegamos no fim, ultimo elemento, só acessar o fim da fila
else{
            f->fim->prox = novo;
            novo->reg = pessoa;
            novo->prox = NULL;
            f->fim = novo;
}
                  return 1;
}

int main(){

FILA f;
Tpessoa p;


inicializacaoFILA(&f);
inserirFila(&f , p);


}