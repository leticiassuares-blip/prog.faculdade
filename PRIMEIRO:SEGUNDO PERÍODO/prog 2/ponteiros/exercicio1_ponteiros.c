#include <stdio.h>

/*Exercício 1

• Implemente uma função que recebe dois
parâmetros: o salário atual de uma pessoa (por
referência) e o percentual de aumento (por
valor). A função deve alterar o valor do salário(atualizar o
 valor do salario-variavel salario)
acrescentando o percentual correspondente
de aumento. Mostre como a função poderia
ser chamada a partir da função main.

//main -SEM PONTEIRO

int main() {
  
  float salario;
  float percentual;
  
  
  printf("insira seu salario:");
  scanf("%f", &salario);
  
  printf("insira seu percentual de aumento(em porcentagem):");
  scanf("%f", &percentual);

  percentual=percentual/100;

  salario = (1+percentual) * salario ;

   printf("Seu novo salario é de R$%.2f", salario);

  return 0;
}*/


/*Exercício 1

• Implemente uma função que recebe dois
parâmetros: o salário atual de uma pessoa (por
referência) e o percentual de aumento (por
valor). A função deve alterar o valor do salário
(atualiza  o conteudo/valor do ponteiro)
acrescentando o percentual correspondente
de aumento. Mostre como a função poderia
ser chamada a partir da função main.*/

#include <stdio.h>
//funcao

int aumento(int *salario , int percentual)
{

  percentual = percentual/100;
    *salario = (1+percentual) * *salario; //*salario altero o valor
    return *salario;
}


//main

int main() {
  
  int x;
  int percentual;

  printf("insira seu salario:");
  scanf("%d",&x);
  
  printf("insira seu percentual de aumento:");
  scanf("%d", &percentual);
  
  aumento(&x,percentual);// &x representa o endereco de memoria do ponteiro salario
  //x representa o conteudo do ponteiro salario
  printf("%d",x);
  
  
  return 0;
}
