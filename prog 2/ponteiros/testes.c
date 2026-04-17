/*#include <stdio.h>
int main ()
{

int *i, j;
puts("Digite um numero inteiro:");
scanf("%d", i);//ponteiro nao foi inicializado,aponta para um lixo na memoria
printf("%d\n", *i);
return 0;

}

#include <stdio.h>
int main (){

int *i, j;
i = &j;// i recebe o endereco de memoria de j
puts("Digite um numero inteiro:");
scanf("%d", i);// i aponta para j, então o valor será armazenado em j
printf("%d\n", *i);//imprime o valor de j,só que nao diretamente mas SIM apontado por i
return 0;

}

NULL-VALOR NULO

Exercício • O que será impresso pelo programa abaixo?

#include <stdio.h>

int main () {

int i, j, *ip, *jp;
char c, *cp;
cp = &c;// ponteiro cp recebe o endereco de memoria de c(APONTAAAAAAAA para c )
c = 'a';
*cp = 'z';  

printf("c = %c\n", c); //RESPOSTA:'z' 
//(cp aponta para c, c ='a' mas cp agora é ='z')
i = 10;
ip = &i; //ip Recebe o endereco de memoria de i 

printf("ip=%p\n", ip); //RESPOSTA: ex 1000(ENDERECO DE MEMORIA ALEATORIO)
printf("*ip=%d\n", *ip); //RESPOSTA: 10(valor)

jp = NULL;//NAO APONTA PARA NENHUMA REGIAO DE MEMORIA
*jp = i; //incorreto pois jp não aponta para uma variável!!!

return 0;

}*/

#include <stdio.h>

//exemplo de definição de vetor
int main(){
      
int a[5]={ 15,8,6,2,0}; //definiu um vetor a de tamanho 5(DECLARANDO)

int *pa;//DECLAREI O PONTEIRO

pa = &a[0]; //fez pa APONTAR para o primeiro elemento de a
//(RECEBE O END DE MEMOR. DE a[0] )
int x;
x = *(pa+2) ; //copia conteúdo de a[i] para x
//(x RECEBE O VALOR DE pa+2 ,OU SEJA, posicoes a frente de onde pa APONTA)

printf("O valor de a[%d] é:%d", 2  , x);
return 0;
}