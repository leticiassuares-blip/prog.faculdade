/*• O que o programa abaixo
faz, caso você digite o
seu primeiro e último
nomes separados por
um espaço em branco?

/*R: Caso seja digitado o primeiro e o segundo
 nome separados por um espaco em branco, o programa 
 exibe apenas o segundo nome,pois
 
 while (*n != ' ')
    n++;
 a condicao do loop será falsa e saimos desse loop.Em seguida,
 o n fora do loop será incrementado e agora o
puts(n) imprime o caractere dessa posicao até encontrar o '\0' e parar.
  
  exemplo: caso eu digite "Ana Lucia", quando chegar no espaco entre o primeiro e
   o segundo nome,o ponteiro chegara no espaco na posicao n[3] e saira do 
   loop pois a condicao é falsa 
   e passa a apontar para  n[4] que é 'L'.
   Assim,será impresso  por completo "Lucia" pois encontrou o '\0' .

• Ele pode acessar regiões
de memória indevidamente? Em quais situações? Corrija-o mesmo para que isto
não aconteça.
R:
Sim, pois caso seja digitado apenas o primeiro nome, o n continua sendo incrementado pois a 
condicao nao será falsa
e ,assim,acessa uma regiao de memoria indevida,com lixo de memoria.

exmplo: Digitei o nome "Ana", quando o ponteiro chegar na posicao n[3]='\0'

 while (*n != ' ')
            n++;

no loop essa condicao nao será FALSA ('\0' != ' ') e o ponteiro continua 
andando e acesa regioes de memoria aleatorias até parar.

versao correta

void misterio (char *n){ // *n é um vetor *n ou n[]

      while (*n != ' ' && *n != '\0' ) {// *n é igual a n[0]
            n++;
      
            if( *n == ' '){
            n++;
      puts(n);
}
      }
      }
      */

#include <stdio.h>

void misterio (char *n);

int main (void){

      char nome [41];
//é usada para ler uma linha de texto da entrada padrão (teclado)
      gets(nome); 
      misterio(nome);
      return 0;
}

void misterio (char *n){ // *n é um vetor *n ou n[]

      while (*n != ' ' ){// *n é igual a n[0]
            n++;
      
      n++;
      puts(n);/*exibe uma string no console e 
      adiciona automaticamente uma quebra de linha ao final

      ex: 'ANA LUCIA'
      Então ela começa em 'L' e imprime tudo até encontrar '\0'.
      */
      
}
}
