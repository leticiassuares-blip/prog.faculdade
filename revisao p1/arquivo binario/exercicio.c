/* O programa:

abre o arquivo
lê os números
compara os valores
guarda o maior
imprime no final */

#include <stdio.h>

int main(){

      float real, maior;
      int lidos;
      char nomearq[100];
      FILE *parq;

      printf("Informe o nome do arquivo: ");
      gets(nomearq);
      if (!(parq = fopen (nomearq, "rb")))
      return -1;

     // lê o PRIMEIRO float do arquivo e coloca em maior.
      lidos=fread(&maior, sizeof(float), 1, parq);
      //ex: [2.5][8.0][3.1][10.2]
      //     ˆ

      //nao conseguiu ler nada,arquivo ta vazio
      if (lidos==0) {
      printf("Erro na leitura dos dados");
      return -1;
      }

       // Continue enquanto não chegar ao fim do arquivo
      while(!feof(parq)){

      //ex: [2.5][8.0][3.1][10.2]
      //          ˆ
      lidos=fread(&real, sizeof(float), 1, parq);

      if (lidos==0){
      printf("Erro na leitura dos dados");
      return -1;

      }

      if(real>maior) // 8.0 > 2.5
      maior=real;
}
      printf("O maior numero armazenado no arquivo eh %f\n",maior);
      fclose(parq);
      return 0;
}