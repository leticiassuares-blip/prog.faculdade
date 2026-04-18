/*Faça um programa que recebe como entrada o nome de um arquivo texto.
Seu programa deve calcular e exibir a quantidade de vezes que cada uma
das vogais aparecem no arquivo (deve ser case insensitive e não precisa
incluir vogais acentuadas na contagem).

Ideia principal do programa
Você não precisa criar o arquivo dentro do programa
O arquivo já deve existir
O usuário só informa o nome dele
*/



#include <stdio.h>

int main(){

    char nome[100];
    FILE *arquivo;

    printf("Insira o nome do seu arquivo: ");
    scanf("%s",nome);

    arquivo = fopen( nome ,"r+");
    //"r+" abrir o arquivo de texto para leitura e escrita

    if( arquivo == NULL){
        
        printf("Erro de abertura do arquivo");
        return 1;

        }

    int c; //variavel aux para guardar cada caracter

    //realizar a leitura do que foi escrito e checar as vogais
    c = fgetc(arquivo);

//vetor que faz a contagem de cada vogal,e a quantidade de 
//cada vogal em relacao a posicao

int vetor[5]={ 0 , 0 , 0 , 0 , 0};

    while(!feof(arquivo)){ // ENQUANTO NAO CHEGAR NO FINAL DO ARQUIVO,
      //CONTINUA LENDO CARA CARACTER

         if(c == 'a' || c == 'A' ){

            vetor[0]++;
        
         }else if (c == 'e'|| c == 'E'){
                
            vetor[1]++;

      }else if (c =='i' || c == 'I'){
            
            vetor[2]++;

        }else if (c == 'o' || c == 'O'){
        
            vetor[3]++;

        }else if (c == 'u' || c == 'U'){
        
            vetor[4]++;
    }
        c= fgetc(arquivo);//faz a leitura do prox caracter e guarda em c

    }

    printf("\n a: %d", vetor[0]);
    printf("\n e: %d", vetor[1]);
    printf("\n i: %d", vetor[2]);
    printf("\n o: %d", vetor[3]);
    printf("\n u: %d", vetor[4]);

    fclose(arquivo);
    return 0;


}