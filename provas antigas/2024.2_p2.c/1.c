#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char nome[30];
int vitorias;
int empates; 
} Selecao;

typedef struct No {
Selecao time;
struct No *prox; 
} No;

typedef struct {
No *inicio;
No *fim; }
 Fila;

typedef struct {
char nome[30];
int pontos; 
} Pontuacao;

void sort(Pontuacao *v, int n) {

int i, j, m;
      for (i=0; i<n-1; i++) {

      m = i;

      for (j=i+1; j<n; j++)

      if ((v+j)->pontos > (v+m)->pontos)
      m=j;

      if (m!=i) {
      Pontuacao temp=*(v+i);
      *(v+i)=*(v+m);
      *(v+m)=temp;
 }
}
}

void inicializarFila(Fila *f) {
f->inicio=NULL;
f->fim=NULL;

}

int inserirSelecao(Fila *f , Selecao s ){

No *novo = (No*)malloc(sizeof(No));//reservando espaco para nova selecao

      if(novo == NULL ){//falha na alocacao
            return 0 ;
      }

      //inserir de fato
      novo->time = s;
      if(f->inicio == NULL){

            f->inicio = novo;
            //f->fim = NULL;
            f->fim = novo;

      }else{//inicio nao é nulo,coloco a selecao no fim

            f->fim->prox = novo;
            f->fim = novo;
            
      }
      novo->prox = NULL;
      return 1;

}

int removerSelecao(Fila *f ,Pontuacao *v){
//verificar se a fila tá vazia,SE VOU REMOVER TEM QUE SER DO INICIO

      if( f-> inicio == NULL){

            return 0;//fila vazia
      }

      No *apagar;
      
      apagar = f->inicio;
      f->inicio =f->inicio->prox;

      if(f->inicio == NULL){

            f->fim = NULL;

      }

      strcpy(v->nome , apagar->time.nome);
      v->pontos = ((apagar->time.vitorias)*3 ) + apagar->time.empates ; 
      free(apagar);
     
      return 1;    
}

void carregarPontuacao(Fila *f , Pontuacao *v){
/* percorro a fila ,removo e na medida que removo,eu carrego no array
exibir o nome de cada selecao sendo removida a cada remocao 

dps de remover 

chamar a funcao sort
imprimo ordenado
*/

int i =0;

printf("Selecoes em ordem de remocao da fila: ");

      while( f->inicio != NULL){

            removerSelecao(f,v+i);
            printf("%s - %d pontos\n" , (v+i)->nome , (v+i)->pontos);
            i++;

      }
      sort(v , i);//ordenei

      int j ;

      printf("Selecoes em ordem determinada por sort:");

      for( j= 0 ; j < i ; j++){

            printf("%s - %d pontos\n" , (v+j)->nome , (v+j)->pontos);
      }
}

int main() {

int n, i, total;
Selecao s;
Fila f;

inicializarFila(&f);

printf("Quantas selecoes deseja cadastrar? ");

scanf("%d", &n);

for (i=0; i<n; i++) {

      printf("Nome da selecao: ");
      getchar();
      gets(s.nome);
      printf("Vitorias e Empates: ");
      scanf("%d %d", &s.vitorias, &s.empates);
      int ret=inserirSelecao(&f,s);
      if(ret==0) printf("Erro ao tentar inserir selecao na fila.");

}

Pontuacao *v=(Pontuacao *)malloc(sizeof(Pontuacao)*n);

if (v==NULL){
       printf("Erro de alocacao\n"); return 1;
       }

carregarPontuacao(&f,v);
free(v);
return 0;
}