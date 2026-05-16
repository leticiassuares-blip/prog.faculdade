/*Exercício 1

• Implemente uma função que recebe dois
parâmetros: o salário atual de uma pessoa (por
referência) e o percentual de aumento (por
valor). A função deve alterar o valor do salário
acrescentando o percentual correspondente
de aumento. Mostre como a função poderia
ser chamada a partir da função main.*/

#include <stdio.h>
void aumento ( int *salarioAtual , float percentual){

      percentual = percentual / 100;
      *salarioAtual = *salarioAtual + (percentual * (*salarioAtual));
}

int main(){

int salario ;
float porcentagem ;

printf("Insira o valor do seu salario: R$ " );
scanf("%d" , &salario);

printf("Insira a porcentagem do aumento recebido: " );
scanf("%f" , &porcentagem );

aumento (&salario , porcentagem );

printf(" Seu novo slario será de  = R$ %d " , salario );
return 0;

}