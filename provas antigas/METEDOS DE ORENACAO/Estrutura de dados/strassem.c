#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*argc -> representa a quantidade de argumentos passados
argv -> representa quais foram os argumentos passados
argv[0] -> nome do programa 

argc == 3 
argv[0] = ""./strassem"
argv[1] = "-k"
argv[2] = 1024 (potência de 2, representará o tamanho da matriz , N = 1024)

//verificar se é potencia de 2(binario)
N       = 1000
N - 1   = 0111

N & (N-1) = 0000


ROTEIRO MAIN

1. Receber argumentos
2. Verificar se os argumentos estão corretos
3. Obter N
4. Verificar se N é potência de 2
5. Alocar/criar A e B
6. Preencher A e B com números aleatórios

7. Medir início
8. Chamar multiplicação tradicional
9. Medir fim
10. Calcular tempo tradicional

11. Medir início
12. Chamar Strassen
13. Medir fim
14. Calcular tempo Strassen

15. Comparar resultado tradicional com resultado Strassen

16. Mostrar os resultados/tempos
17. Liberar memória

*/
void multipComum ( int N , int *A , int *B ,int *C1){

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){
            int soma = 0;

                  for(int k = 0 ; k < N ; k++){

      soma +=(*(A + ( (i * N) + k))) * (*(B + ( (k * N) + j))) ;

      }
      *(C1 + ( (i * N) + j)) = soma ;
}}
}
/*falta
Matriz A e B
      ↓
dividir em 4 blocos
      ↓
fazer somas/subtrações entre blocos
      ↓
7 multiplicações
      ↓
combinar os 7 resultados
      ↓
C
*/
void multipStrassem ( int N ,int *A , int *B ,int *C2){

int *x = (int *) malloc(N/2 * N/2 * sizeof(int));
      
      if (x == NULL){
printf ("Erro de alocacao de memoria\n");    
}
int *y = (int *) malloc(N/2 * N/2 * sizeof(int));
     
      if (y == NULL){
printf ("Erro de alocacao de memoria\n");      
}
int *z = (int *) malloc(N/2 * N/2 * sizeof(int));
     
      if (z == NULL){
printf ("Erro de alocacao de memoria\n");
}
int *w = (int *) malloc(N/2 * N/2 * sizeof(int));
     
      if (w == NULL){
printf ("Erro de alocacao de memoria\n");
}
int *M1 = (int *) malloc(N/2 * N/2 * sizeof(int));
     
      if (M1 == NULL){
printf ("Erro de alocacao de memoria\n");
}

   for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( (i * N) + j))) + (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + j))) + (*(B + ( ((i+N/2) * N) + (j+N/2))));
 
multipComum(N/2 , x , y , M1);

(*(x + ( (i * N/2) + j))) = (*(A + ( ((i+N/2) * N) + j))) + (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + j)));

multipComum(N/2 , x , y , M1);

(*(x + ( (i * N/2) + j))) = (*(A + ( (i * N) + j)));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + (j+N/2)))) - (*(B + ( ((i+N/2) * N) + (j+N/2))));
 
multipComum(N/2 , x , y , M1);

(*(x + ( (i * N/2) + j))) =  (*(A + ( ((i+N/2) * N) + j)));
(*(y + ( (i * N/2) + j))) = (*(B + ( ((i+N/2) * N) + j))) - (*(B + ( (i * N) + j)));

multipComum(N/2 , x , y , M1);

(*(x + ( (i * N/2) + j))) = (*(A + ( (i * N) + j))) + (*(A + ( (i * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) =  (*(B + ( ((i+N/2) * N) + (j+N/2))));

multipComum(N/2 , x , y , M1);

(*(x + ( (i * N/2) + j))) = (*(A + ( ((i+N/2) * N) + j))) - (*(A + ( (i * N) + j)));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + j))) + (*(B + ( (i * N) + (j+N/2))));

multipComum(N/2 , x , y , M1);

(*(x + ( (i * N/2) + j))) = (*(A + ( ((i+N/2) * N) + j))) - (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + (j+N/2)))) + (*(B + ( ((i+N/2) * N) + (j+N/2))));

multipComum(N/2 , x , y , M1);

      }
}

/*
 for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){
       (*(C2 + ( (i * N/2) + j))) = (*(M1 + ( (i * N/2) + j)));

      }
}
*/

}

int main( int argc , char *argv[]){

      if(argc != 3 ){

      printf("Erro ao executar o programa,argumentos passados estão incorretos");
            return -1;
      }
      int N;
      N = atoi( argv[2]); //transforma texto em numero

      //verificar se é potencia de 2
      if(( N & (N-1) ) > 0){

      printf("%d : Valor inválido!\n O valor inserido não é uma potência de 2\n" , N);
            return -1;
      }

//alocar memória->criando uma matriz com ponteiros

int *A = (int *) malloc(N * N * sizeof(int));
      
      if (A == NULL){
printf ("Erro de alocacao de memoria\n");
      return -1;
}
int *B = (int *) malloc(N * N * sizeof(int));
     
      if (B == NULL){
printf ("Erro de alocacao de memoria\n");
      return -1;
}
//preencher as matrizes com valores aleatorios

srand(time(NULL));//inicializar com o tempo atual

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

                  *(A + ( (i * N) + j)) = rand() % 100; // cada matriz tem valores aleatrorios de 0 a 99
                  *(B + ( (i * N) + j)) = rand() % 100;

      }
}

printf("A:\n");

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

               printf(" %d " ,  *(A + ( (i * N) + j)) );
      }
      printf("\n");
}

printf("B:\n");

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

               printf(" %d " ,  *(B + ( (i * N) + j)) );
      }
      printf("\n");
}

//recebe o resultado da multip. por metodo comum
int *C1 = (int *) malloc(N * N * sizeof(int));
    
      if (C1 == NULL){
printf ("Erro de alocacao de memoria\n");
      return -1;
}

//recebe o resultado da multip por metodo de strassem
int *C2 = (int *) malloc(N * N * sizeof(int));
    
      if (C2 == NULL){
printf ("Erro de alocacao de memoria\n");
      return -1;
}

multipComum(N,A,B,C1);

printf("C1:\n");

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

               printf(" %d " ,  *(C1 + ( (i * N) + j)) );
      }
      printf("\n");
}

multipStrassem(N ,A,B,C2);

printf("C2:\n");

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

               printf(" %d " ,  *(C2 + ( (i * N) + j)) );
      }
      printf("\n");
}
/*
 preencher A

preencher B
marca o inicio
chamar funcao multip. por metodo comum
marca o fim

marca o inicio
chamar funcao multip. por metodo  de strassem
marca o fim

compara os resultados
saber o tempo de execucao das multiplicacoes

funcao strassem
marcar tempo
comparar os resultados finais

*/
//liberando memória

free(A);
free(B);
free(C1);
free(C2);

      return 0;
      
}