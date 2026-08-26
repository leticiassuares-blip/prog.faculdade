#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct {

int idade;

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

      printf("%i ", end->reg.idade);
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


void concatenaListas(LISTA* l1 , LISTA* l2){

      //criei um ponteiro para percorrer toda a lista1
      //quando ele chega no ultimo elemento,ele visualiza que o prox é null
      PONT final = l1->inicio;

      //lista 1 vazia
      if( final == NULL ){

      l1->inicio = l2-> inicio;
           
      }
else{
      //lista 1 tem elementos
      while(final->prox != NULL){
            final = final -> prox;

      }
      //entao o prox será o inicio da segunda lista
            final->prox = l2->inicio;
}           
}

//verificar se ambas as listas tem os mesmos conteudos,se sao exatamente iguais
//para serem iguais os conteudos precisam estar na mesma ordem
bool IguaisListas(LISTA* l1 , LISTA* l2){

PONT percorre1 = l1->inicio;
PONT percorre2 = l2->inicio;

 if(percorre1 == NULL && percorre2 == NULL){ //sao iguais,ambas vazias
                  return true;
}
//se uma das listas está vazia,nao tem conteudos em comum
      else if(percorre1 == NULL || percorre2 == NULL){
                  return false;
}    
else{
            while( percorre1 != NULL && percorre2 != NULL  ){

            if ( percorre1->reg.idade ==  percorre2->reg.idade){

                        percorre1 = percorre1->prox;
                        percorre2 = percorre2->prox;

            }else{
                        return false;
                  } 
                  
            }
            if(percorre1 == NULL && percorre2 == NULL){
                              return true ;
            }
            return false;
      }
}
//modifica o registro da lista na pos(seus valores)
bool modificaElem(LISTA* l , REGISTRO reg , int pos){

      PONT anda = l->inicio;

            if( pos < 0 || pos > tamanho(l)-1){

            return false;
      }
int i;
      for(  i = 0 ; i< pos ; i++){

            anda= anda->prox;

      }
       if( i == pos){

            anda->reg = reg;

            }
            return true;

}

int main(){

      LISTA l1;
      LISTA l2;
      REGISTRO reg;

      inicializarLista( &l1 );
      inicializarLista( &l2 );

      for( int i = 0 ; i < 4 ; i++ ){

            reg.idade = i*2;
      insere(&l1 , reg , i);

      }

      exibirLista(&l1);

      for( int i = 0 ; i < 4 ; i++ ){

            reg.idade = i*2;
      insere(&l2 , reg , i);

      }
      exibirLista(&l2);

      printf("%d\n" , IguaisListas(&l1,&l2));

      concatenaListas(&l1,&l2);
      exibirLista(&l1);
      //depois de concatenar 
      printf("%d\n" , IguaisListas(&l1,&l2));

      reg.idade = 7;
      modificaElem(&l1 , reg , 6);
      exibirLista(&l1);
      return 0;
}
