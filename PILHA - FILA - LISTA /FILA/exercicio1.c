/*Escreva um algoritmo que leia um número indeterminado
de valores inteiros. O valor 0 (zero) finaliza a entrada de
dados. Para cada valor lido, determinar se ele e um
número par ou ímpar. Se o numero for par, então incluí-lo
na FILA PAR; caso contrário, incluí-lo na FILA ÍMPAR. Após
o término da entrada de dados, retirar um elemento de
cada fila alternadamente (iniciando-se pela FILA ÍMPAR)
até que ambas as filas estejam vazias. Seu programa deve
exibir os elementos na ordem em que estão sendo
retirados das filas.*/

#include <stdio.h>
#include <stdlib.h>

//numeros pares

typedef struct {

int num;

} NUMERO;

typedef struct aux {

NUMERO reg;
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

int inserirNaFila(FILA* f,NUMERO valor) {

            //reservar espaco na memoria
            PONT novo = (PONT) malloc(sizeof(ELEMENTO));

            if (novo==NULL) //erro de alocacao
            return 0;

            //caso contrario
            novo->reg = valor;
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

            return 1;

}
void exibirFila(FILA* f){

      PONT end = f->inicio;
      printf("\nFila: \" ");

      if(end == NULL){

            printf("VAZIA");
      }
      while (end != NULL) {

      printf("%i ", end->reg.num);

      end = end->prox; 
}
      printf("\"\n"); 
}

int excluirDaFila(FILA* f, NUMERO* reg) {

      //a fila ta vazia?,se esta vazia nao consigo retirar ninguem
      if (f->inicio == NULL) 
      return 0;

      //caso contrario
  //ponteiro reg recebe as informacoes da estrutura reg q ta no inicio da fila
     while(f-> inicio != NULL ){ //fila vazia

      *reg = f->inicio->reg;
     
      PONT apagar = f->inicio;//recebe o endereco do inicio
      f->inicio = f->inicio->prox;//o  inicio recebe o endereco do prox

      printf("%d " , reg->num);
      free(apagar);

      if (f->inicio == NULL) 
      f->fim = NULL;

     }   
      return 1; 
}


//fila par
//fila impar

int main(){

      FILA NumeroPar;
      FILA NumeroImpar;
      NUMERO valor;
      int num;

      inicializarFila( &NumeroPar );
      inicializarFila(&NumeroImpar );

            scanf("%d" , &num);
      //lê sem parar até vc inserir o zero
      while ( num != 0 ){

            valor.num = num;

            if(num % 2 == 0){

            inserirNaFila(&NumeroPar , valor);

            }else  {
                  
            inserirNaFila(&NumeroImpar , valor);

            }
            
            scanf("%d" , &num);

      }
      exibirFila(&NumeroPar);
      exibirFila(&NumeroImpar);

      printf("\nRetirando elementos da fila ímpar:\n");
      excluirDaFila( &NumeroImpar , &valor);
      
      printf("\nRetirando elementos da fila par:\n");
      excluirDaFila( &NumeroPar , &valor);
      
      exibirFila(&NumeroPar);
      exibirFila(&NumeroImpar);

return 0;

}