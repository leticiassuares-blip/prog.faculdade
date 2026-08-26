#include <stdio.h>
#include <stdlib.h>

typedef struct {

int codigo;
char nome[50];
double preco;
int quantidade; 

} Produto;

/* Implementação das funções solicitadas */

void quantidadeProdutosArquivo(FILE *fbin , int *n){

      Produto p;
      *n = 0;
      rewind(fbin);

      while( fread ( &p , sizeof(Produto) , 1 , fbin) == 1 ){

           (*n) ++; // *n = *n + 1;
      }
}

Produto *alocarProdutos( int n){

Produto *p = (Produto*) malloc( sizeof(Produto)*n );
      if( p != NULL){
            return p;
      }//else

            return NULL;
      
}

int lerArquivoBinario( FILE *fbin , Produto *p  , int n){

int lidos = 0;
rewind(fbin);

      for(int i = 1 ; i <= n ; i++){
            
      if (fread( p , sizeof(Produto) , 1 , fbin) == 1){ 

      p++;//aponta para o proximo e armazena
      lidos++;

}
      }

return lidos;
}

int gravarRelatorioTexto( char nome[100] , Produto *p , int n){

     FILE *arq = fopen( nome , "w+");
     if(arq == NULL){
      return 0;
     }

float v_estoque ;
float total = 0 ;
int i = 0 ;

      while(i < n ){

            v_estoque = (p+i)->preco * (p+i)->quantidade;

if(fprintf(arq, "%d %s %.2f\n", (p+i)->codigo , (p+i)->nome ,v_estoque )< 0 ){

     return 0; //erro
} 
total += v_estoque;
i++;
    
}  
if(fprintf(arq , "---\nTotal = %.2f" , total) < 0 ){

      return 0;
}
fclose(arq);
return 1;

}

int main() {

FILE *fbin;
Produto *produtos;
int n;

fbin = fopen("produtos.dat", "rb");

      if (fbin == NULL) {
      printf("Erro ao abrir arquivo binario.\n");
      return 1; }

quantidadeProdutosArquivo(fbin, &n);

      if (n <= 0) {
      printf("Arquivo vazio.\n");
      fclose(fbin);
      return 1;
      }

produtos = alocarProdutos(n);

      if (produtos == NULL) {
      printf("Erro de alocacao de memoria para produtos.\n");
      fclose(fbin);
      return 1; 
}

int lidos=lerArquivoBinario(fbin, produtos, n);

      fclose(fbin);
      if (lidos != n) {
      printf("Erro na leitura do arquivo binario.\n");
      free(produtos);
      return 1; 
}

int verifica=gravarRelatorioTexto("relatorio.txt", produtos, n);

free(produtos);

if (verifica == 0)

printf("Problemas na geração do relatorio.\n");
else

printf("Relatorio gerado com sucesso.\n");

return 0;
}