/*Exercício — Histórico de Navegação usando Pilha Estática

Um navegador de internet deseja implementar um sistema 
simples de histórico de páginas visitadas utilizando uma pilha estática.

Cada página visitada deve armazenar:

o título da página;
a URL da página.*/

#include <stdio.h>
#include <string.h> //copiar o historico,nomes das paginas
#include <stdbool.h> //retornar true or false

//#define true 1
//#define false 0
#define MAX 5 // maximo de conteudo da pilha

typedef struct {
    char titulo[50];
    char url[100];
} PAGINA;

typedef struct {
      PAGINA P[MAX];
      int topo;
}PILHA;

//dizer que ta vazia
void inicializarPilha(PILHA *p){
      p->topo = -1;
}

//inserir elemento
bool push(PILHA *p, PAGINA pag){

      if(p-> topo == MAX -1 ){ // a pilha ta cheia? se tiver nao temos como inserer nada
      
            return false;

      }else{

            p-> topo = p-> topo +1;
            p -> P[p->topo] = pag ;
            return true;
      }
}
//remover elemento
bool pop(PILHA *p, PAGINA *pag){

      if(p-> topo == -1){ // a pilha ta vazia? se tiver nao da pra remover nada dela
      
            return false;

      }else{

            *pag = p->P[p-> topo];
            p-> topo = p-> topo -1 ;
            return true;
}
}
void exibirHistorico(PILHA *p){

      printf("Histórico de pesquisa: \n");
      int i;

      for( i = p-> topo ; i>= 0 ; i-- ){

            printf("%s\n" , p->P[i].titulo );
      }

}
 int main(){

      //variaveis que acessa ambas estruturas
      PILHA historico;
      PAGINA conteudo;

      //inicializar a pilha- pilha vazia
      inicializarPilha(&historico);

      //preencher a pilha com coisa
      strcpy( conteudo.titulo , "google" );
      push( &historico , conteudo);
      
      strcpy( conteudo.titulo , "instagram" );
      push( &historico , conteudo);

      strcpy( conteudo.titulo , "X" );
      push( &historico , conteudo);

      strcpy( conteudo.titulo , "Youtube" );
      push( &historico , conteudo);

      printf("\n\nHistorico antes:\n\n");
      exibirHistorico(&historico);

      //remover o conteudo da pilha 
      pop( &historico ,&conteudo );

       printf("\n\nHistorico depois de uma remocao:\n\n");
      exibirHistorico(&historico);
      return 0;

 }