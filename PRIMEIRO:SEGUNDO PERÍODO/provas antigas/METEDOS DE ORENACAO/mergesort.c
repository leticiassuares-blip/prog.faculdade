/*QUERO ORDENAR:
DIVIDIR PARA CONQUISTAR
caso base= um unico elemento
H.I-> dois ou mais elementos
DIVIDO EM DOIS CONJUNTOS
p=inicio 
q=meio
r=fim

A[6] = { 0 , 6 , 8 ,1 , 7  , 3};
*/
void merge(int A[], int p, int q,int r) {

int i, j, k;

int tamseq1 = q - p + 1; // 2 - 0 + 1 = 3
int tamseq2 = r - q;// 5 - 2 = 3

      int seq1[tamseq1]; //conjunto 1

      //copiando o conteudo de A para seq1
      // do inicio ao meio
      for(i=0; i < tamseq1; i++){ // i < 3
             seq1[i] = A[p+i];
      }
      int seq2[tamseq2];//conjunto 2

      //copiando o conteudo de A para seq2
      //meio+1 ao fim 
      for(j=0; j < tamseq2; j++){//j< 3
            seq2[j] = A[q+1+j];
      }

            k = p; i = 0; j = 0; //k = inicio do arr A 
/* A[6] = { 0 , 6 , 8 ,1 , 7  , 3};
seq1[3] = { 0 , 6 , 8 };
seq2[3] = { 1 , 7  , 3};
*/

      while (i < tamseq1 && j < tamseq2){

            if(seq2[j] <= seq1[i]) {
                  A[k] = seq2[j];
                        j++; 
      }

            else {
                  A[k] = seq1[i];
                  i++; 
            }
                  k++;//sempre incremento k
}
//lacos q sobram
            while (i < tamseq1) {
              A[k] = seq1[i];
                  k++;
                  i++;
            }
            while (j < tamseq2) {
                  A[k] = seq2[j];
                  k++;
                  j++;
}
}

void mergeSort(int numeros[], int ini, int fim) {

int meio;
            if(ini < fim) {

            meio = (ini + fim)/2; //DIVIDE

            mergeSort(numeros, ini, meio);//CONQUISTA
            mergeSort(numeros, meio+1, fim);//CONQUISTA

            merge(numeros, ini, meio, fim);//COMBINA
            }
}