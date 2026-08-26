/*• Crie um programa e leia do teclado a quantidade de inteiros N e, após,
os valores dos N inteiros. Você deverá escrever a função
max_index(...) que receba dois parâmetros: um vetor de inteiros e
seu tamanho. A função deverá retornar o índice do maior número
encontrado. Imprima na tela o resultado. Sua função não deverá acessar
diretamente os índices do vetor (Ex.: v[i]) durante a execução, ao
invés disso, acesse-os via uso de ponteiro.
• Exemplo de E/S:
ENTRADA SAÍDA
10 7
5 1 8 3 6 -2 8 10 4 2
• Obs: Caso o maior número apareça mais de uma vez, retorne o índice do primeiro
encontrado.*/

#include <stdio.h>
//com ponteiro
int max_index( int vetor[], int tam){

int *p; //ponteiro que acessa os indices do vetor
p=vetor;// p = &vetor[0];
int guarda;
guarda= *p; //guarda = vetor[0]
int indice;
indice= 0;

      for(int i=0; i<tam ; i++){

            if(guarda < *(p+i) ){ // p[i]

                  guarda= *(p+i);
                  indice = i;
}}
     
return printf("o valor do indice do numero de maior valor é %d ",indice);

}
/*sem ponteiro
int max_index( int vetor[], int tam){

int guarda;
int indice;
indice= 0;
guarda=vetor[0];

      for(int i=0; i<tam ; i++){

            if(guarda<vetor[i]){

                  guarda= vetor[i];
                        indice = i;
}}
      printf("O indice do maior numero encontrado é %d",indice );
return 0;

}*/


int main(){

int n;

printf(" Insira a quantidade de inteiros:" );
scanf("%d", &n);

int v[n];

printf(" Insira os valores dos inteiros:\n" );
      for(int i=0 ; i<n ; i++){
            printf("v[%d]= ",i );
            scanf("%d", &v[i]);
}


max_index(v,n);
return 0;


}