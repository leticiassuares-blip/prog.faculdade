#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Primeiro encontre o menor elemento do
arranjo
• Então troque esse elemento de lugar com o
que está na primeira posição
• Encontre o segundo menor do arranjo
• Troque com o da segunda posição
• E assim por diante, até chegar ao fim do
arranjo*/


/* 1. marca v[i] como candidato a menor
2. varre tudo à direita procurando alguém menor q ele — só anotando
3. troca o menor encontrado com v[i]

e o cara q estava em v[i] vai pra posicao antiga do menor*/
void selecao(int v[], int tam) {

int i, p, aux, posMenor;

//"chute " q o menor ta na primeira posicao
      for (i=0; i<tam-1; i++) {
            posMenor = i;

      for (p=i+1; p<tam; p++){

      if (v[p] < v[posMenor]){
            posMenor = p;
      }}
            aux = v[i];
            v[i] = v[posMenor];
            v[posMenor] = aux; 
      
}
 }

