/*Exercício 4 – 
Inverter String
Implemente a função char *inverte(char *s); A função deve receber uma string, criar uma nova
string alocada dinamicamente

A função deve:
receber uma string s;
criar uma nova string alocada dinamicamente;
armazenar nela os caracteres de s em ordem inversa;
retornar o ponteiro para a nova string.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *inverte(char *s){

    //percorrer a string antiga ,contar a quantidade de letras e coloca na nova
int tamanho = 0;
char *aux = s; //ponteirio auxiliar percorre a string até o '\0'

            // 0 1 2 3 4  5
            // V A S C O '\0' --> TAMANHO 5

    while ( *aux != '\0'){
            aux ++ ; // VAI APONTANDO PARA A PROXIMA POSICAO
            tamanho++;
    }

//string que será a palavra invertida
char *nova_string;
tamanho++; // RESERVANDO UM ESPACO PARA O '\0' --> POR CONTA DA ALOCACAOO DINAMICA

//reservando espaco na memória
nova_string = (char *)malloc(tamanho * sizeof(char));

//CASO A ALOCACAO DE ERRO
    if( nova_string == NULL){

        printf("Erro na alocacao de memoria");
        return NULL;

}

tamanho--; // TIRO O '\0'
int i ;//percorrer a string nova 

int j = tamanho - 1;//referente a posicao da string antiga de tras para frente

//Em cada posicao eu vou passar a letra que esta no final da string original para o inicio da nova string 
    for( i = 0 ;  i < tamanho ; i++ ){

        //nova_string[0] = s[tamanho]
        *(nova_string + i)  = *(s + j); // s[j]
                        j --;

    }
            i = tamanho++;
             *(nova_string + i) ='\0'; // ADICIONO '\0' AO FINAL

        

return nova_string;

}

int main(){

    char palavra[100];

    printf("Insira a palavra que deseja inverter:\n");
    scanf("%s" , palavra);

    printf("%s" , inverte(palavra));

    
    return 0;
}