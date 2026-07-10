#include <stdio.h>
#include <stdlib.h>
/*#define true 1
#define false 0
typedef int bool;*/

typedef struct{

int numero;
char naipe;

} tCarta;

// estrutura q acessa as informacoes das cartas
typedef struct aux {

tCarta CARTA;
struct aux* prox; //acessa o endereco de memoria do prox

} ELEMENTO;

typedef ELEMENTO* PONT;


typedef struct {

PONT topo; // ELEMENTO *topo

} PILHA;

void inicializarPilha(PILHA* p) {

p->topo = NULL; //PILHA VAZIA

}

void exibeCarta(tCarta carta){

      if(carta.numero >=2 && carta.numero <= 10){
            printf("%d", carta.numero);
      }

      else{
            switch(carta.numero){

            case 11:

            printf("Valete");
            break;

            case 12:

            printf("Dama");
            break;

            case 13:

            printf("Rei");
            break;

            case 1:

            printf("As");
            break;

            default: // 14

            printf("Invalida");

            }
      }

            printf(" de ");

            switch(carta.naipe){

            case 'o':

            printf("Ouros\n");
            break;

            case 'c':

            printf("Copas\n");
            break;

            case 'p':
            
            printf("Paus\n");
            break;

            case 'e':

            printf("Espadas\n");
            }
}

/*empilha baralho (POP)
//busca carta 
//(PUSH-contagem até encontrara a carta desejada e ela ser o novo topo)

Seu programa deverá ler do teclado uma carta no seguinte
formato: <número> <naipe> e imprimir na tela a carta
e quantas cartas precisaram ser descartadas da pilha para
ela ser encontrada, conforme exemplos a seguir (ver
formatação esperada).*/

void EmpilhaBaralho(PILHA *p ){

PONT novo; //ELEMENTO *novo

//char naipes = { 'o' , 'p' , 'c', 'e'};
// 1 ao 13 ouros
            for( int i = 1 ; i <=13 ; i++ ){

                  //reservar espaco de memoria
      novo = (PONT)malloc(sizeof(ELEMENTO));

            if(novo == NULL ){

            printf("Erro de alocacao!");

      }
                  novo->CARTA.numero = i; 
                  novo->CARTA.naipe = 'o';
                  novo->prox = p->topo; 
                  p->topo = novo;//topo agora recebe o endereco do novo

            }
            // 1 ao 13 paus
             for( int i = 1 ; i <= 13 ; i++ ){

                  //reservar espaco de memoria
      novo = (PONT)malloc(sizeof(ELEMENTO));

            if(novo == NULL ){

            printf("Erro de alocacao!");

      }

                  novo->CARTA.numero = i;
                  novo->CARTA.naipe = 'c';
                  novo->prox = p->topo;
                  p->topo = novo;

            }
            // 1 ao 13 copas
             for( int i = 1 ; i <= 13 ; i++ ){

                  //reservar espaco de memoria
      novo = (PONT)malloc(sizeof(ELEMENTO));

            if(novo == NULL ){

            printf("Erro de alocacao!");

      }

                  novo->CARTA.numero = i;
                  novo->CARTA.naipe = 'p';
                  novo->prox = p->topo;
                  p->topo = novo;

            }
            // 1 ao 13 espadas
             for( int i = 1 ; i <= 13 ; i++ ){

                  //reservar espaco de memoria
      novo = (PONT)malloc(sizeof(ELEMENTO));

            if(novo == NULL ){

            printf("Erro de alocacao!");

      }

                  novo->CARTA.numero = i;
                  novo->CARTA.naipe = 'e';
                  novo->prox = p->topo;
                  p->topo = novo;

            }

}

//numero e naipe
int BuscaCarta(PILHA *p , tCarta carta_buscada ){

      if( p -> topo == NULL ){

            printf("Carta nao encontrada \nO baralho está vazio");
}

int contagem = 0 ;

//enquanto nao encontrar a carta desejada, retiro da pilha uma carta
//excluo e realizo a contagem de quantas vezes eu fiz tantas retirada

 while((carta_buscada.numero != p->topo-> CARTA.numero) || (carta_buscada.naipe != p->topo-> CARTA.naipe)){

                  PONT apagar = p->topo; //recebe o endereco do topo
                  p->topo = p->topo->prox; // o novo endereco do topo é o prox
                  free(apagar);

                  contagem++;

}
return contagem;
}

void exibirPilha(PILHA* p) {

//ELEMENTO *end 
//PONT end recebe o endereco de memoria do topo
PONT end = p->topo;
      printf("\nPilha: \n \" ");

      while (end != NULL) {

      printf("%d ", end->CARTA.numero);
      printf("%c", end->CARTA.naipe);
      printf("\n");
      end = end->prox; 
}
      printf("\"\n"); 
}

int main(){

      tCarta carta;
      PILHA p;
      tCarta *Topo;

      scanf("%d" , &carta.numero );
      scanf("%s" , &carta.naipe );

      exibeCarta(carta);

      inicializarPilha(&p);

      EmpilhaBaralho( &p );
      //exibirPilha(&p);

      int b = BuscaCarta( &p , carta );
      printf("%d" ,  b);

      return 0;

}