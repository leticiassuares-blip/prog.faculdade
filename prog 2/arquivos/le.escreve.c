//objetivo: criar,abrir ,ler o que o usuario quiser digitar, 
//escrever isso no arquivo e fechar

#include <stdio.h>
#include <stdlib.h>

int main() {

      int c;
      FILE *pa;
      char *nome = "texto.txt";// nem é necessario 
      //alternativa: fopen("texto.txt", "w+")

      //crio, abro um arquivo chamado "texto.txt" e checo caso der erro de enderecamento
      if (( pa = fopen(nome, "w+")) == NULL) {
      printf("Nao foi possivel abrir o arquivo.\n");
      exit(1);
}
//comeco lendo um unico caracter
 // getchar()-->funcao que o usuario pode inserir um unico caracter

//FAZER A ESCRITA NO ARQUIVO
      c = getchar(); 

//estrutura de repeticao--> enquanto o usuario NAO PARAR DE DIGITAR
//o fputc pega cada caracter e joga no arquivo,
//depois de jogar um unico caracter,o cursor anda,le o prox caracter e guarda em c 
//para ir repetindo o processo

      while (!feof(stdin)) { //(stdin)entrada padrão (teclado)
      fputc(c, pa); //funcao que esta lendo e jogando no arquivo
      c = getchar();
}
      rewind(pa); /* volta ao inicio do arquivo */

      printf("\nTerminei de escrever, agora vou ler.\n");

      //realizar a leitura do que foi escrito
      
      c = fgetc(pa);
      while (!feof(pa)) {
      putchar(c);
      c = fgetc(pa);
}
fclose(pa);
return 0;
}