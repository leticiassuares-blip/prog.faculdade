#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//o maior elemento do vetor é empurrado para o final a
// cada interacao do laco,por isso o ult precisa diminuir
//No bubble sort você troca — 
//dois elementos trocam de lugar diretamente.

/* Compara vizinhos, empurra o maior pro fim. 
A cada passagem, o maior restante chega
 na sua posição final. Diminui o ult porque o final
  já está ordenado.*/

void bolha(int v[], int tam){

int ult, i, aux;

      for (ult=tam-1; ult>0; ult--){
            for (i=0; i<ult; i++){
            
                  //realizo a troca
            if (v[i] > v[i+1]) {
                  aux = v[i];
                  v[i] = v[i+1];
                  v[i+1] = aux; 
            }
      }
}
}