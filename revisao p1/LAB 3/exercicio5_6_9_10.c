/*Exercício 5 ,6 , 9  e 10— Soma dos Elementos da Matriz
Implemente as funções:

int **cria_matriz(int L, int C);
void le_matriz(int **mat, int L, int C);
int soma_elementos(int **mat, int L, int C);
A função soma_elementos deve retornar a soma de todos os valores armazenados na matriz.

Exemplo
Matriz:

1 2
3 4
5 6
Resultado:

21

exercicio 6
int maior_valor(int **mat, int L, int C);
A função deve retornar o maior valor presente na matriz.

exercicio 9 
void troca_colunas(int **mat, int L, int col1, int col2);
Ela deve trocar os elementos de duas colunas da matriz.

Exemplo
Antes:

1 2 3
4 5 6
7 8 9
Troca das colunas 0 e 2:

3 2 1
6 5 4
9 8 7
*/

#include <stdio.h>
#include <stdlib.h>

//reservar espaco de memoria para as linhas e para as colunas
//funcao do tipo ponteiro de ponteiro
int** cria_matriz(int linhas, int colunas){

    int **matriz;// ponteiro para a matriz,para reservar memoria nela

        //reservando espaco de memoria para as linhas
    matriz = (int**)malloc(linhas * sizeof(int*));

    //checagem de erro de alocacao das linhas
    if ( matriz == NULL){

        printf("Erro na alocacao de memoria");
        return NULL;

    }

    //alocando memoria para as colunas
    int i;

        for( i = 0 ; i < linhas ; i++ ){

    *(matriz +i) = (int*) malloc( colunas * sizeof(int));

        if (*(matriz +i) == NULL){

        printf("Erro na alocacao de memoria");
        return NULL;

    }}

return matriz;
}


//preencher a matriz
void le_matriz(int **mat, int linhas, int colunas){

int i ;
int j ; 


        for( i = 0 ; i < linhas ; i++ ){

        for( j = 0 ; j < colunas ; j++ ){

            printf("Matriz[%d][%d] = " , i , j);
            scanf("%d"  , ( *(mat +i) +j ) );  //   *(mat +i) +j referente endereco da coluna
            //endereço da célula

    }}
}

void imprime_matriz(int **mat, int linhas, int colunas){

int i ;
int j ; 


       for( i = 0 ; i < linhas ; i++ ){

        for( j = 0 ; j < colunas ; j++ ){

            printf("%d " , *(*(mat +i) +j) ); //  *(*(mat +i) +j) referente o conteudo

    }
            printf("\n");
}


}
int soma_elementos(int **mat, int linhas, int colunas){

    int i;
    int j;
    int soma = 0;

        for( i = 0 ; i < linhas ; i++){
        for( j = 0 ; j < colunas ; j++){

            soma = soma + *(*(mat + i)+j);
    }
    }
    return soma;
}

int maior_valor(int **mat, int linhas , int colunas ){

int i;
int j;

int guarda = 0 ;
int maior  = *(*(mat)) ;


    for( i = 0 ; i < linhas ; i++){
        for( j= 0 ; j< colunas ; j++){
        
             guarda = *(*( mat + i) + j) ;

            if( maior <= guarda  ){

                maior = guarda ;
            }

        }
    }
    return maior;

}

void troca_colunas(int **mat, int linhas , int coluna1, int coluna2){

int i;
int guarda = 0;

        for( i = 0 ; i < linhas ; i++){
           
            guarda = *(*(mat +i) + coluna1);
            *(*(mat +i) + coluna1) = *(*(mat +i) + coluna2);
            *(*(mat +i) + coluna2) = guarda;

        }


}

int soma_borda(int **mat, int linhas , int colunas ){

int soma = 0;

    for( int i = 0 ; i < linhas ; i++){
        for( int j= 0 ; j < colunas ; j++){
        
            if( ( i == 0 || i == linhas-1 ) || (j == 0 || j == colunas-1 )){

                soma += *(*(mat + i ) + j);
            }
        }
    }

return soma;
}

/*que retorna a soma apenas dos elementos da borda da matriz.

Exemplo
1 2 3 
4 5 6 
7 8 9 
Soma:

1+2+3+4+6+7+8+9 = 40*/

int main(){

    int linhas;
    int colunas;
    int **matriz;

    printf("Insira a quantidade de linhas: ");
    scanf("%d" , &linhas);

    printf("Insira a quantidade de colunas: ");
    scanf("%d" , &colunas);

    matriz = cria_matriz( linhas , colunas );

        le_matriz( matriz , linhas , colunas);
        imprime_matriz(matriz , linhas , colunas);
        printf("\nResultado: \n %d\n" , soma_elementos( matriz , linhas , colunas) );

        printf("\nMaior valor: \n %d\n" , maior_valor( matriz , linhas , colunas ));

        printf("\nSoma da borda \n %d\n" , soma_borda(matriz,linhas, colunas));

        printf("\n");

        int coluna1 , coluna2;

        printf("Insira a primeira coluna que deseja trocar: ");
        scanf("%d" , &coluna1);

        printf("Insira a segunda coluna que deseja trocar: ");
        scanf("%d" , &coluna2);

        troca_colunas(matriz, linhas , coluna1 , coluna2);
        imprime_matriz(matriz , linhas , colunas);

    return 0;
}