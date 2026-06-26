#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {

TIPOCHAVE chave;
// outros campos...

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
/*
LISTA
┌────────┐
│ inicio │──── NULL
└────────┘
*/

int tamanho(LISTA* l) {

      PONT end = l->inicio;
      int tam = 0;

      while (end != NULL){

            tam++;
            end = end->prox;
}
return tam; 

}

void exibirLista(LISTA* l){

PONT end = l->inicio; 
printf("Lista: \" ");

      while (end != NULL) {

      printf("%i ", end->reg.chave);
      end = end->prox; 

}
      printf("\"\n"); 

}
/* PONT end //ELEMENTO *end
PONT end aponta para a estrutura elemento
end-> reg aponta para a estrutura REGISTRO dentro de ELEMENTO
end->reg.chave acessa a chave dentro da estrutura REGISTRO

*/

bool insere(LISTA* l, REGISTRO reg, int pos) {

      //checando se a posicao é valida
      if (pos<0 || pos>tamanho(l)) {

            return false;

      }

ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
//PONT novo = (PONT) malloc(sizeof(ELEMENTO));
            if (novo==NULL){ 
            return false;//verificando a alocacao

            }

/* copia o registro que o usuário passou 
como parâmetro para dentro 
do novo nó que você acabou de alocar.*/
            novo->reg = reg;
            int i;
            ELEMENTO* p;//PONT p

//caso 1: inserir no inicio da lista
            if (pos == 0){

// o campo prox de novo recebe o enderceo
// de quem ta no inicio
            novo->prox = l->inicio;
            l->inicio = novo;

//estou inserindo
// no meio ou no fim
            }else{

//ponteiro p vai percorrer a lista
            p = l->inicio;

      for (i=0;i<pos-1;i++) {
//caminho do inicio até uma posicao anterior da
// onde eu quero ser inserido            
            p = p->prox;

        }  novo->prox = p->prox;
            p->prox = novo;

            }

return true; 
}


bool exclui(LISTA* l, int pos) {

//verifico se a posicao é valida
if (pos<0 || pos>tamanho(l)-1){
      return false;
}
int i;
ELEMENTO* p; //PONT p
ELEMENTO* apagar;//aponta par onde quero remover

//remover alguem q é o primeiro elemento
      if (pos == 0) {

//o endereco do primeiro no está em apagar
      apagar = l->inicio;
// inicio da lista passa a ser o prox,quem era o primeiro antes
      l->inicio = apagar->prox;

//caso de remover do meio ou fim
      }else {

//recebe o endereco do inicio            
      p = l->inicio;
      
for (i=0;i<pos-1;i++){
       p = p->prox;
}
      apagar = p->prox;
      p->prox = apagar->prox;

 }
      free(apagar);
      return true; 

}



void reinicializarLista(LISTA* l) {

      PONT end = l->inicio;

      while (end != NULL) {

      PONT apagar = end;
      end = end->prox;
      free(apagar);

 }
      l->inicio = NULL;
}