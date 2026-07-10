
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
char nome[MAX];
int gols;
} tTimeGols;

typedef struct {

tTimeGols time1;
tTimeGols time2;

} tPlacarJogo;

typedef struct {
char nome[MAX];
int jogos;
int saldo;
int pontos;
} tPontos;

/* Implementação das funções solicitadas */

int grava_pontos_time(FILE *parq, tPontos time_grava){

rewind(parq);//curso no inicio do arquivo
tPontos verifica;//sempre verifica a leitura do arquivo referente ao nome

      //analisar se o time já esta no arquivo(preciso ler o arquivo),se tiver vou sobrescrever
      while(fread (&verifica , sizeof(tPontos), 1 , parq) != 1){

            if( strcmp( verifica.nome , time_grava.nome) == 0){ //o time está no arquivo(COMPARO O NOME)

                   fseek(parq , -sizeof(tPontos) , SEEK_CUR);//tenho q voltar para sobrescrever
                  fwrite(&time_grava , sizeof(tPontos), 1 , parq);

                                    return 1;//sobrescrevi,deu certo!
            }
      }
      //o time nao está no arquivo , posiciono o cursor no final do arquivo

      fseek(parq , 0 , SEEK_END);
            fwrite(&time_grava , sizeof(tPontos) , 1 , parq);
                        return 1;
}

int contabiliza_pontuacao(tPlacarJogo *placar , tPontos *time_grava){

      int gols_sofridos = 0;
      int gols_feitos = 0;

if(strcmp (placar->time1.nome , time_grava->nome ) == 0 ){

      gols_sofridos = placar->time2.gols;
      gols_feitos = placar->time1.gols;

}  else if (strcmp ( placar->time2.nome , time_grava->nome ) == 0){


      gols_sofridos = placar->time1.gols;
      gols_feitos = placar->time2.gols;
}else{

return 0;
}
      time_grava->jogos ++ ;
      time_grava->saldo = time_grava->saldo + (gols_feitos - gols_sofridos);
      //vitoria do time
      if( gols_feitos > gols_sofridos ){
            
      time_grava->pontos = time_grava->pontos + 3;

      //empate do time
      }else if(gols_feitos == gols_sofridos){

      time_grava->pontos = time_grava->pontos + 1;

      }
      //derrota nao contabiliza ponto (0)

      return 1;
}

int ler_gravar_resultados(FILE* parq , FILE* parq2 , char *time_desejado){

tPlacarJogo jogo;
tPontos time ;
// nao funciona time->nome = time_desejado;
strcpy (time.nome , time_desejado); //copiando o nome

time.jogos = 0;
time.pontos = 0;
time.saldo = 0 ;

rewind(parq);//cursor no inicio do arquivo de texto
//leitura

      while( fscanf(parq , "%s %d x %d %s\n" , jogo.time1.nome ,jogo.time1.gols ,jogo.time2.gols , jogo.time2.nome ) == 4  ){
      
            contabiliza_pontuacao(&jogo , &time );

      }

grava_pontos_time(parq2 ,time);
return 1 ;
}

void mostra_pontuacao_time( FILE *parq){

tPontos time ;
   
rewind(parq);
while( fread( &time , sizeof(tPontos) , 1 , parq) == 1 ){

printf("time: %s - jogos: %d, saldo de gols: %d, pontos: %d" 
      ,time.nome , time.jogos ,time.saldo , time.pontos);
}
}

int main() {

FILE *parq, *parq2;

char time_buscado[MAX];

parq=fopen("jogos.txt","r");

      if(parq==NULL)
      return -1;

parq2=fopen("pontos.dat","w+");

      if(parq2==NULL) {
      fclose(parq);
      return -1; 
      }

printf("Digite o time desejado: ");
fgets(time_buscado,MAX,stdin);

      while (time_buscado[0]!='\n') {

      time_buscado[strlen(time_buscado)-1]='\0';
      ler_gravar_resultados(parq, parq2, time_buscado);
      mostra_pontuacao_time(parq2);
      printf("Digite o time desejado: ");
      fgets(time_buscado,MAX,stdin);

}
fclose(parq);
fclose(parq2);
return 0; 
}