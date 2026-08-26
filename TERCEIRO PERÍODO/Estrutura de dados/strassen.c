#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void multipStrassen ( int N ,int *A , int *B ,int *C2){

      //caso base
  if(N == 1 ){
            *C2 = (*A) * (*B);
            return ;
 }
//nao eh o caso base

//matrizes temporarias
int *x = (int *) malloc(N/2 * N/2 * sizeof(int));
int *y = (int *) malloc(N/2 * N/2 * sizeof(int));
//strassem
int *M1 = (int *) malloc(N/2 * N/2 * sizeof(int));
int *M2 = (int *) malloc(N/2 * N/2 * sizeof(int));
int *M3 = (int *) malloc(N/2 * N/2 * sizeof(int));
int *M4 = (int *) malloc(N/2 * N/2 * sizeof(int));
int *M5 = (int *) malloc(N/2 * N/2 * sizeof(int));
int *M6 = (int *) malloc(N/2 * N/2 * sizeof(int));
int *M7 = (int *) malloc(N/2 * N/2 * sizeof(int));

      if(x==NULL|| y==NULL || M1==NULL|| M2== NULL|| M3==NULL|| M4 ==NULL ||
            M5==NULL||  M6 ==NULL  ||M7 == NULL){

printf ("Erro de alocacao de memoria\n");

free(x);
free(y);

free(M1);
free(M2);
free(M3);
free(M4);
free(M5);
free(M6);
free(M7);
return;
}

   for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( (i * N) + j))) + (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + j))) + (*(B + ( ((i+N/2) * N) + (j+N/2))));
            }
      }
multipStrassen(N/2 , x , y , M1);
 

for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( ((i+N/2) * N) + j))) + (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + j)));

            }
      }
multipStrassen(N/2 , x , y , M2);
 

for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( (i * N) + j)));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + (j+N/2)))) - (*(B + ( ((i+N/2) * N) + (j+N/2))));
      }
}
multipStrassen(N/2 , x , y , M3);

for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) =  (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( ((i+N/2) * N) + j))) - (*(B + ( (i * N) + j)));
            }}
multipStrassen(N/2 , x , y , M4);

for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( (i * N) + j))) + (*(A + ( (i * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) =  (*(B + ( ((i+N/2) * N) + (j+N/2))));
            }}
multipStrassen(N/2 , x , y , M5);

for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( ((i+N/2) * N) + j))) - (*(A + ( (i * N) + j)));
(*(y + ( (i * N/2) + j))) = (*(B + ( (i * N) + j))) + (*(B + ( (i * N) + (j+N/2))));
            }}

multipStrassen(N/2 , x , y , M6);

for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

(*(x + ( (i * N/2) + j))) = (*(A + ( i * N) + (j+N/2))) - (*(A + ( ((i+N/2) * N) + (j+N/2))));
(*(y + ( (i * N/2) + j))) = (*(B + ( ((i+N/2) * N) + j))) + (*(B + ( ((i+N/2) * N) + (j+N/2))));
            
}

      }
multipStrassen(N/2 , x , y , M7);

     for(int i = 0 ; i < N/2 ;i++){
            for(int j = 0 ; j < N/2 ;j++){

      (*(C2 + ((i * N) + j ))) = (*(M1 + ((i * N/2) + j ))) +(*(M4 + ((i * N/2) + j ))) 
      - (*(M5 + ((i * N/2) + j ))) +(*(M7 + ((i * N/2) + j )));

      (*(C2 + (((i+N/2) * N) + j ))) = (*(M2 + ((i * N/2) + j )))+(*(M4 + ((i * N/2) + j )));

      (*(C2 + ((i * N) + (j+N/2 )))) =  (*(M3 + ((i * N/2) + j )))+ (*(M5 + ((i * N/2) + j )));

      (*(C2 + (((i+N/2) * N) + (j+N/2) ))) = (*(M1 + ((i * N/2) + j ))) -(*(M2 + ((i * N/2) + j ))) 
      +(*(M3 + ((i * N/2) + j ))) +(*(M6 + ((i * N/2) + j )));

            }} 

free(x);
free(y);

free(M1);
free(M2);
free(M3);
free(M4);
free(M5);
free(M6);
free(M7);
}

int comparaResultado ( int N , int *C1 , int *C2){

for( int i = 0 ; i < N ; i++){
      for( int j = 0 ; j < N ; j++ ){

            if( (*(C1 + ( (i * N) + j))) != (*(C2 + ( (i * N) + j))) ){
 
                        return 0;
            }}}//else
return 1;
}

int main( int argc , char *argv[]){

      if(argc != 3 ){

      printf("Erro ao executar o programa,argumentos passados estão incorretos");
            return -1;
      }
      int N;
      N = atoi( argv[2]); //transforma texto em numero

      //verificar se é potencia de 2
      if(  N <= 0 ||( N & (N-1) ) != 0){

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

//medicao do tempo
clock_t inicio , fim;
double tempoMcomum , tempoStrassen;

inicio = clock();
multipComum(N,A,B,C1);
fim = clock();

tempoMcomum = (double) (fim - inicio ) /CLOCKS_PER_SEC;
printf("Tempo de execução com a multiplicação comum : %f segundos" ,tempoMcomum );

printf("\nC1:\n");

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

               printf(" %d " ,  *(C1 + ( (i * N) + j)) );
      }
      printf("\n");
}


inicio = clock();
multipStrassen(N ,A,B,C2);
fim = clock();

tempoStrassen= (double) (fim - inicio ) /CLOCKS_PER_SEC;
printf("Tempo de execução com a multiplicação por Strassen : %f segundos" ,tempoStrassen );


printf("\nC2:\n");

      for(int i = 0 ; i < N ;i++){
            for(int j = 0 ; j < N ;j++){

               printf(" %d " ,  *(C2 + ( (i * N) + j)) );
      }
      printf("\n");
}

printf("As matrizes resultado de cada método de Multiplicacao sao iguais?\n(TRUE-> 1 ou FALSE->0) : %d", comparaResultado( N , C1,C2));

free(A);
free(B);
free(C1);
free(C2);
      return 0;
      
}