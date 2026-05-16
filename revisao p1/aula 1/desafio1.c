/*• Crie um programa e leia do teclado a quantidade de inteiros N 
e, após,
os valores dos N inteiros. Você deverá escrever a função
max_index(...) que receba dois parâmetros: um vetor de inteiros e
seu tamanho. A função deverá retornar o índice do maior número
encontrado. Imprima na tela o resultado. Sua função não deverá acessar
diretamente os índices do vetor (Ex.: v[i]) durante a execução, ao
invés disso, acesse-os via uso de ponteiro.
• Exemplo de E/S:
ENTRADA     SAÍDA
10             7
5 1 8 3 6 -2 8 10 4 2
• Obs: Caso o maior número apareça mais de uma vez, retorne o índice do primeiro
encontrado.*/

#include <stdio.h>

// A função deverá retornar o índice do maior número encontrado
int max_index( int tam ,int vetor[tam] ){

      int *p;//ponteiro que acessa os indices do vetor 
     
      p = vetor; // digo que : p aponta para vetor[0] ; vetor[0] == *p
      int maiorValor = *p; //o maior valor vai ser o inicial
      int maiorIndice = 0;


      for( int i =0 ; i <tam ; i++){

            if( *(p+i) > maiorValor ){

                  maiorValor = *(p+i);
                  maiorIndice = i;
            }
      }
      return maiorIndice;
}

int main(){

      int n;// quantidade de n inteiros ;ex: n=10 o vetor vai de v[0] a v[9]
      int i ;

      printf("Insira a quantidade de inteiros desse vetor: ");
      scanf("%d" , &n);

      //percorrer o vetor e vou preenche-lo em funcao do valor de n escolhido
      int v[n];

      for(i = 0 ; i<n ; i++){
            
            printf("Insira o valor de v[%d]= " , i );
            scanf("%d" , &v[i]);
      }
      printf("\n");

      //imprime o vetor

      for(i = 0 ; i<n ; i++){
            
            printf(" v[%d]= %d\n" , i , v[i] );
      
      }
      max_index (n , v);

      printf("O indice com maior valor é : %d" , max_index (n , v));

return 0;


}
