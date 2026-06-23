/*
ENUNCIADO

Um mercado possui 1 caixa de pagamento em que os clientes são
atendidos por ordem de chegada na fila. No início, a fila está
vazia. C clientes estão a efetuar compras neste supermercado.
Cada cliente é identificado por um nome, um tempo de chegada
(em segundos) ao caixa e número de produtos para pagar. Um
cliente com P produtos demora 10+P*K segundos a ser
atendido na caixa, onde K é uma constante que define quantos
segundos o operador da caixa demora a registrar um único
produto, e 10 é o tempo constante necessário para o cliente
efetuar o pagamento.

Entrada: A primeira linha contém um inteiro que representa K, a rapidez de
atendimento da caixa. A segunda linha contém um inteiro C, o número de clientes.
Seguem-se C linhas, cada uma contendo a descrição de um cliente no formato
"NOME SEGUNDO_CHEGADA NUMERO_PRODUTOS", onde NOME, é uma
sequência contíguas de caracteres (sem espaços) e SEGUNDO_CHEGADA e
NUMERO_PRODUTOS números inteiros indicando, respectivamente, o segundo de
chegada e o número de produtos do cliente. É garantido que os clientes são
informados por ordem estritamente crescente do segundo de chegada. As
informações sobre cada cliente devem ser armazenadas em uma estrutura de fila.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {

char NOME[50];
int SEGUNDO_CHEGADA;
int NUMERO_PRODUTOS;

}CLIENTE;

typedef struct aux {

CLIENTE reg;
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

int inserirNaFila(FILA* f,CLIENTE reg , int C) {

      //inserir cada cliente por vez
      // numero de clientes 
      while( C != 0 ){

            //reservar espaco na memoria para cada cliente
            PONT novo = (PONT) malloc(sizeof(ELEMENTO));

            if (novo == NULL){
            //erro de alocacao
            return 0;

            }

            //caso contrario
            scanf("%s" , reg.NOME);
            scanf("%d %d" , &reg.SEGUNDO_CHEGADA , &reg.NUMERO_PRODUTOS);

            novo->reg = reg;
            novo->prox = NULL;//entrou na fila,agora ele é o ultimo elemento da fila

            //agora eu encaixo em relacao ao inicio e fim da fila
            if (f->inicio==NULL){// nao tem ninguem na fila

                  f->inicio = novo; // o inicio agora é esse cara
            
            }

            else {//tem elementos na fila?
            
            f->fim->prox = novo; 
            }// o pronteiro prox do antigo ultimo elemento agora recebe 
            //o endereco do novo elemento inserido na fila
            f->fim = novo;// agora o novo fim é o endereco do elemento adicionado a fila

            C--;
      }
            return 1;

}
void exibirFila(FILA* f , int K ){

      PONT end = f->inicio;
      int TEMPO_SAIDA = 0;

      int caixa_Livre = 0 ;

      while (end != NULL) {

      TEMPO_SAIDA = (10 + (end->reg.NUMERO_PRODUTOS * K) );

      //o caixa estava livre quando o cliente chegou
      if( end->reg.SEGUNDO_CHEGADA > caixa_Livre){ 

            TEMPO_SAIDA = TEMPO_SAIDA + end->reg.SEGUNDO_CHEGADA;
           
            printf("\n%s %d %d", end->reg.NOME , end->reg.SEGUNDO_CHEGADA , TEMPO_SAIDA);

             caixa_Livre = TEMPO_SAIDA;
      }

      else{
            TEMPO_SAIDA = TEMPO_SAIDA + caixa_Livre;

      printf("\n%s %d %d", end->reg.NOME , end->reg.SEGUNDO_CHEGADA , TEMPO_SAIDA);
 }
      end = end->prox; 
}
     
}

//fila
//inicializar Fila ,inserir 3 clientes 
//calculo do tempo de saida e imprimir

int main(){

FILA f;
CLIENTE reg;
int K; //rapidez de atendimento
int C; //numero de clientes->tamanho da fila

inicializarFila(&f);

      scanf("%d" , &K );
      scanf("%d" , &C );

      inserirNaFila(&f , reg , C );
           
      printf("tamanho da fila:%d\n" , tamanho(&f));

      exibirFila(&f , K );


      return 0;
}