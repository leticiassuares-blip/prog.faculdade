/*• Considere o tipo de dado
tEmpregado definido ao
lado para armazenar
informações sobre um
empregado. Implemente
uma função para reajustar o
salário de um dado
empregado em 10%, caso ele
tenha nascido antes de 1980,
e de 7%, caso ele tenha
nascido a partir de 1980.*/

#include <stdio.h>
typedef struct{

      int dia;
      int mes;
      int ano;

} tData;


typedef struct{

      char nome[40];
      tData dataNascimento; 
      tData dataAdmissao;
      char sexo;
      float salario;

} tEmpregado;

/*
tEmpregado
│
├── nome
├── sexo
├── salario
├── dataNascimento
│     ├── dia
│     ├── mes
│     └── ano
│
└── dataAdmissao
      ├── dia
      ├── mes
      └── ano

*/

//crio um ponteiro que guarda um endereco de um tEmpregado
void reajuste_salarial (tEmpregado *emp){ 

      if ((*emp).dataNascimento.ano<1980){
            /*significa:

pega o empregado apontado por emp
dentro dele pega dataNascimento
dentro dela pega ano e verifica se é < 1980*/

      (*emp).salario=(*emp).salario*1.1;
      }
      else
      (*emp).salario=(*emp).salario*1.07;

}

//OUU

void reajuste_salarial (tEmpregado *emp){

      if (emp->dataNascimento.ano<1980){
      emp->salario=emp->salario*1.1;
      }
      else

      emp->salario=emp->salario*1.07;

}