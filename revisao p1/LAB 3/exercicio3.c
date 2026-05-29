/*

void * inicializa (Tfunc *, int);
void * inclui_novos(Tfunc *, int, int);
void imprime (Tfunc *, int, int);

• inicializa deve alocar dinamicamente o vetor de
estruturas e armazenar as informações de cada
funcionário solicitadas ao usuário (a partir do teclado)

• inclui_novos deve realocar dinamicamente o vetor
de estruturas para armazenar as informações de mais
usuários

• imprime deve exibir (em tela) as informações dos
funcionários no intervalo de posições indicado; para
mostrar as informações de todos os funcionários, o
intervalo deve ser 0 a funcionarios+adicionais*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func{

char nome[40];
int ano_nasc;
float renda;

} Tfunc ;

//reservando espaco para tantos funcionarios  na estrutura e armazenar
void * inicializa (Tfunc *acesso , int funcionarios ){

      int i ;
      acesso =  (Tfunc *)malloc(funcionarios * sizeof(Tfunc));

            for ( i = 0 ; i < funcionarios ; i++){

                  scanf("%s" ,  (acesso + i)->nome );
                  scanf("%d" ,  &(acesso + i)->ano_nasc );
                  scanf("%f" ,  &(acesso + i)->renda );
     }
     return acesso;
}

//reservando espaco para tantos funcionarios  na estrutura(adiciona espaco)
void * inclui_novos(Tfunc *acesso, int funcionarios, int adicionais){

      acesso = (Tfunc *)realloc (acesso , (funcionarios+adicionais) * sizeof( Tfunc ));

  for ( int i = funcionarios ; i < funcionarios+adicionais ; i++){

                  scanf("%s" ,  (acesso + i)->nome );
                  scanf("%d" ,  &(acesso + i)->ano_nasc );
                  scanf("%f" ,  &(acesso + i)->renda );
     }

return acesso;
}
void imprime (Tfunc *acesso , int inicio , int total){

      for ( inicio = 0; inicio < total ; inicio++ ){

           printf("Nome: %s ,Ano de nascimento:%d , Renda:%2.f\n" ,
      (acesso + inicio)->nome ,   (acesso + inicio)->ano_nasc ,  (acesso + inicio)->renda);


}
}

int main(void){

Tfunc *cadastro;

int funcionarios, adicionais;

printf("Quantos funcionarios? ");
scanf("%d",&funcionarios);

cadastro=inicializa(cadastro, funcionarios);

      if (!cadastro)
            return -1;

printf("Quantos funcionarios a mais deseja adicionar? ");
scanf("%d",&adicionais);

cadastro = inclui_novos(cadastro, funcionarios, adicionais);

      if (!cadastro)
            return -1;

printf("Lista de funcionarios cadastrados\n");
imprime(cadastro, 0, funcionarios+adicionais);

free(cadastro);
return 0;
}