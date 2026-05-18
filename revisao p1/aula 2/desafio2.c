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
#include <stdlib.h>

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


 (*momento).hora = (percorrido / 60 ) ; // momento->hora
 (*momento).minuto =  (percorrido % 60)  ; //// momento->minuto

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

t_Momento m_Atual;

int m1_hora;
int m1_minuto;
int m2_hora;
int m2_minuto;
int tempo_percorrido;

      printf("Primeira hora:");
      scanf("%d" , &m1_hora);

      printf("Primeiro minuto:");
      scanf("%d" , &m1_minuto);

      printf("Segunda hora:");
      scanf("%d" , &m2_hora);

      printf("Segundo minuto:");
      scanf("%d" , &m2_minuto);

      printf("Tempo em minutos percorrido desde o inicio do dia :");
      scanf("%d" , &tempo_percorrido);

      printf("%d:%d\n" , m1_hora, m1_minuto );
      printf("%d:%d\n" , m2_hora, m2_minuto );

      tempoatual (tempo_percorrido, &m_Atual );

      int m1 = ( m1_hora *60 ) + m1_minuto;
      int m2 = ( m2_hora *60 ) + m2_minuto;

      printf("horario mais proximo ");

            if( abs(tempo_percorrido - m1) == abs(tempo_percorrido - m2) ){

                   printf("%d:%d\n" , m1_hora, m1_minuto );


      }else if ( abs(tempo_percorrido - m1) > abs (tempo_percorrido - m2)){

            printf("%d:%d\n" , m2_hora, m2_minuto );
      }else{
            printf("%d:%d\n" , m1_hora, m1_minuto );
      }


return 0;

}