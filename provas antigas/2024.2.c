#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
 char carac; }
  REGISTRO;

typedef struct aux {
 REGISTRO reg;
 struct aux* prox; } 
 ELEMENTO;

typedef struct {
 ELEMENTO* inicio;
 int tamanho; }
  LISTA; 


void insereFim( LISTA *l , REGISTRO e ){

int fim = tamanhoLista(l) - 1; //final da lista é seu tamanho tirando - 1

ELEMENTO* p;

ELEMENTO* novo = (ELEMENTO*)malloc(sizeof(ELEMENTO));
//caso de certo a alocacao,executa a acao de colocar no fim o caracter

p = l->inicio;

      if(novo!= NULL){
       
      //se inicio é o fim,a lista ta vazia
            if( p == NULL){

            novo->reg = e;
            novo->prox = NULL;
            l->inicio = novo;
            l->tamanho++;
            }else{
      
            //percorro até o fim
      for(int i = 0 ; i < fim ;i++){
            p=p->prox;

      }
            novo->reg = e;
            p->prox = novo;
            novo->prox = NULL;
            l->tamanho++;
            
}
}
}

REGISTRO excluiFim(LISTA* l ){

ELEMENTO* apagar; 
ELEMENTO* p = l->inicio;
int fim =  tamanho(l) - 1 ;
REGISTRO *reg = (REGISTRO*)malloc(sizeof(REGISTRO));

//lista ta vazia
      if( p == NULL ){
         return *reg;
      }
      //LISTA TEM 1 ELEMENTO
      else if( p->prox ==NULL){
            
            apagar = p;
            *reg = apagar->reg;
            free(apagar);
            l->inicio = NULL;
            l->tamanho--;
            return *reg;
      }
      for(int i =0 ; i<fim ; i++){

            p=p->prox;
      }

            apagar = p->prox;
            *reg = apagar->reg ;
            free(apagar);
            p->prox = NULL;
            l->tamanho--;

            
return *reg ;
}

void trataNovoCracter( LISTA* l , REGISTRO x){

            if( x.carac == '#'){

                  excluiFim(l);

            }else if(  x.carac == '\'  ){

                  reinicializarLista(l);
                  
            }else if(x.carac == '*'){

            char* linha = geraLinhaString(l);
            printf("%s\n", linha);
            free(linha);

            }else{

                  insereFim(l , x);

            }



}
void ordenaString( char linha[] , int i , int f){

      int meio;

      if(i<f){
            
            meio = (i+ f)/2;

            ordenaString(linha , i ,meio);

            ordenaString(linha ,meio +1 , f);

            intercala(linha , i , meio , f);
      }
}

questao 5-> em q n é o tamanho do vetor
Exato! E por que ela compara no máximo n vezes?
Olha o while:
cwhile (x < t1 && y < t2) {
    if(s1[x] < s2[y]) { x++; }
    else               { y++; }
    i++;
}
A cada iteração, um dos índices avança — ou x ou y. E o while para quando um dos lados esgota. Então o máximo de iterações é t1 + t2 - 1, que é n - 1.
Ou seja, no pior caso faz n-1 comparações — que na notação Big O é O(n).
O n log n apareceria se você contasse todas as chamadas do ordenaString juntas — porque o intercala é chamado log n vezes, cada vez fazendo n comparações. Mas a questão pede só o intercala isolado.
Então a resposta da questão 5 é: O(n).