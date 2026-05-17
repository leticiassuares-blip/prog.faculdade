/*Adicione uma nova função incluiElem ao
exemplo anterior, cujos parâmetros são s, i, j
e num, tal que esta modifique o elemento
s[i][j] com o valor num. Faça um
programa principal que teste a função
incluiElem para i=1, j=2 e num=10. */

#include <stdio.h>
#define DIM 3

/*void incluiElem( int s[DIM][DIM] , int i , int j , int num){

      int x;//linha
      int y;//coluna


      for ( x= 0 ; x < DIM ; x++){

            for (y = 0 ;y < DIM ; y++){
                  *(*(s+x)+y) = 0; //s[i][j]=0

                  if(x == i &&  y== j ){
                        *(s[x]+y) = num ;
                  }

            }
      }
}*/


void incluiElem( int s[DIM][DIM] , int i , int j , int num){

     *(*(s+i)+j) = num;
}

void inicM(int s[ ][DIM]){

int i, j;
      for (i=0;i<DIM;i++){
            for (j=0; j <DIM;j++){
                   s[i][j] = 0;
}
}
}

void mostraM(int s[DIM][DIM]){

int i, j;
      
for (i=0; i<DIM;i++){
      for (j=0;j<DIM;j++){
            printf(" [%d] ",s[i][j]);
      }
      printf("\n");
}
}

int main(){
            
      int s[DIM][DIM];
      inicM(s);
      mostraM(s);
      printf ("\nNova matriz:\n");
      incluiElem(s , 1,2,10);
      mostraM(s);


return 0;
}