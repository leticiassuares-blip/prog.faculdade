/* Escopo local = onde a variáel existe

Escopo é o “lugar onde uma variável existe e pode ser usada”.

O x da main só existe dentro da main
O x da função soma só existe dentro da função soma

 Eles têm o mesmo nome, mas são variáveis completamente diferentes*/


#include <stdio.h>

void soma(int x){
// Escopo Local: a variável 'x' só existe aqui
x = x+1; // O x da função soma só existe dentro da função soma

}

int main(void){ 
// Outra variável local com o mesmo nome, mas escopo diferente
 int x=8; //O x da main só existe dentro da main


 soma(x);
 printf("O valor de x NA MAIN é de %d",x);
 return 0;

}

/*#include <stdio.h>

void minhaFuncao() {
    // Escopo Local: a variável 'x' só existe aqui
    int x = 10; 
    printf("Dentro da funcao: x = %d\n", x);
}

int main() {
    minhaFuncao();
    
    // printf("%d", x); // ERRO: 'x' não foi declarada neste escopo
    
    int x = 20; // Outra variável local com o mesmo nome, mas escopo diferente
    printf("No main: x = %d\n", x);
    
    return 0;
}*/
