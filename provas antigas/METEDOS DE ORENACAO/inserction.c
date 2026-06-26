#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// pego na posicao i e comparo com os anteriores
//se for menor eu vou trocando e deslocando pro inicio

//No insertion sort você desloca — os elementos maiores 
//vão andando uma casa pra direita, abrindo espaço,
// e o aux cai no buraco que sobrou no final.
void insercao(int v[], int tam){

int i, aux, j;

      for (i=1; i<tam; i++) {
            aux=v[i];
            j=i;

            //anterior é maior que aux,
            //ent eu tenho q trocar
      while ((j>0)&&(aux<v[j-1])){
            v[j] = v[j-1];
            j--; 
      }
            v[j] = aux; 
} 
}
