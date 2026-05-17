/*• Considere a estrutura de dados a seguir:

• E implemente a seguinte função:
void tempoatual(int percorrido, t_Momento
*momento);
• A função deve ter os seguintes parâmetros: (i) percorrido
é o tempo em minutos que se passou desde o início do dia; (ii)
momento é um ponteiro para uma estrutura de dados que
deve ser atualizada pela função com a hora e o minuto atuais.
*/

#include <stdio.h>

 typedef struct {

int hora;
int minuto;

}t_Momento;

/*(i) percorrido é o tempo em minutos que se 
passou desde o início do dia; (ii)
momento é um ponteiro para uma estrutura de dados que
deve ser atualizada pela função com a hora e o minuto atuais.
*/

void tempoatual(int percorrido, t_Momento *momento){

 /*t_Momento x;
 momento = &x;*/
 (*momento).hora = (percorrido / 60 ); // momento->hora
 (*momento).minuto =  ((percorrido % 60) *60) ; //// momento->minuto

}

/* Crie um programa principal que deve receber como
argumento, via linha de comando, um inteiro indicando
número de testes a serem realizados. A seguir, receba do
usuário dois momentos (hora e minuto separadamente)
e um inteiro. O inteiro representa o tempo percorrido em
minutos desde o início do dia. Utilizando a função
implementada, descubra o momento atual e mostre, na
tela, qual dentre os dois momentos (informados pelo
usuário) tem a hora mais próxima do momento atual. No
caso de empate, mostre o primeiro momento.*/


int main(){

t_Momento *m1;
t_Momento *m2; 

int m1_hora;
int m1_minuto;
int m2_hora;
int m2_minuto;
int tempo_percorrido;

      printf("Primeira hora:");
      scanf("%d\n" , &m1_hora);

      printf("Primeiro minuto:");
      scanf("%d\n" , &m1_minuto);

      printf("Segunda hora:");
      scanf("%d\n" , &m2_hora);

      printf("Segundo minuto:");
      scanf("%d\n" , &m2_minuto);

      printf("Tempo em minutos percorrido desde o inicio do dia :");
      scanf("%d\n" , &tempo_percorrido);

      tempoatual (tempo_percorrido, m1 );


return 0;

}