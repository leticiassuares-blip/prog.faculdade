#include <stdio.h>
#define MAX 80

int main (void) {

      char linha[MAX]; //vetor de caracteres (char)
      //consigo armazenar varios caracteres ex: "casa"--> "casa\n"
      FILE *pa;   
      char *nome = "texto1.txt";

      //criando,abrindo e checando
if (( pa = fopen(nome, "w+")) == NULL) {
printf("Nao foi possivel abrir o arquivo.\n");
return 1;
}

/*comeca a leitura do teclado

guarda em linha
lê até:
Enter '\n'
ou 79 caracteres*/

//exemplo: digito "casa"
// e como  char linha[MAX]; é um vetor de caracteres (char)
/*linha[5]={'c','a','s','a','\0'}

Lê uma linha do arquivo
Enquanto não acabar:
imprime na tela
lê a próxima linha*/

fgets(linha, MAX, stdin); //lê o teclado - linha → ['c','a','s','a','\0']

      while (!feof(stdin)) {//(stdin)entrada padrão (teclado)

      //escreve- A LINHA INTEIRA- e joga no arquivo (onde pa aponta)
      fputs(linha, pa);//arquivo: [c][a][s][a]
      //                           ˆ
//nesse caso como é um vetor de caracteres- (cursor vai pro final automaticamente)
      fgets(linha, MAX, stdin); // Lê a próxima linha do teclado
      /*linha → (nada novo)
feof(stdin) → verdadeiro*/
}

      rewind(pa); /* volta ao inicio do arquivo */

      printf("Terminei de escrever, agora vou ler.\n");

//Lê a primeira linha do arquivo(le TUDOOO)
//lê o teclado - linha → ['c','a','s','a','\0']
//                                          ˆ
      fgets(linha, MAX, pa);

      while (!feof(pa)) {//enquanto NAO chegar no final do arquivo
      puts(linha);//imprime a linha na tela e já pula linha automaticamente
      fgets(linha, MAX, pa); // Lê a próxima linha do arquivo
}

fclose(pa);
return 0;
}
/*

TECLADO:
casa
 ↓
fgets
 ↓
linha = "casa"
 ↓
fputs
 ↓
ARQUIVO:
casa
 ↓ rewind
 ↓
fgets
 ↓
linha = "casa"
 ↓
puts
 ↓
TELA:
casa

👉 linha sempre guarda uma string inteira
👉 fgets → lê string
👉 fputs → escreve string
👉 puts → imprime string*/

