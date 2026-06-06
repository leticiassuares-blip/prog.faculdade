/*Crie a estrutura:

typedef struct {
    char nome[50];
    float nota;
} Aluno;

Implemente uma função:

Aluno *cadastra(int n);
que:

aloca dinamicamente um vetor de alunos;
lê os dados;
retorna o ponteiro.

Depois implemente:

float media(Aluno *v, int n);
para calcular a média das notas.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char nome[50];
    float nota;

}Aluno;

/*aloca dinamicamente um vetor de alunos;
lê os dados;
retorna o ponteiro

//O que a função faz internamente?

Ela é responsável por construir os alunos.
O enunciado diz:

lê os dados

Ou seja, dentro da função você vai perguntar:
nome e nota
*/
Aluno *cadastra(int n){

    Aluno *acessa;
    acessa = (Aluno*) malloc (n *sizeof(Aluno));

    int i;

    for(i = 0 ; i < n ; i++ ){

        printf("\nAluno[%d]\n" , i );
        printf("Nome: ");
        scanf("%s" , (acessa + i )->nome); //acessa->nome
        printf("Nota: ");
        scanf("%f" , &(acessa + i )->nota); //acessa->nota
    }

return acessa;
}


float media(Aluno *v, int n){

float soma = 0;
float media;
int i ;

    for( i = 0 ; i < n ; i++){

        soma += (v + i )->nota;

}
media = soma / n;

return media;
}

int main(){

    int quant;
    printf("Quantos alunostem na turma?");
    scanf("%d", &quant );
    Aluno *turma;

    turma =cadastra( quant );

    printf("%2.f", media(turma ,quant ));

    return 0;
}
