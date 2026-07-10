/*Exercício 2: Faça uma função que concatene uma FILA a outra.
Void concatenarFilas(FILA 1, FILA 2);
//Os parâmetros do exercício 2 não está totalmente correto, mas você precisará de duas
filas.*/

//f1-> fim 
int concatenarFilas(FILA *f1, FILA *f2){

      //fila1 vazia
      if( f1->inicio == NULL){

      f1->inicio = f2->inicio;
      f1->fim = f2->fim;
      f2->inicio = NULL;
      f1->fim = NULL;
            return 1;
            
      //fila2 vazia nao há nada para concatenar
      }else if(f2->inicio == NULL){

            return 1;

      }
      //duas filas tem conteudo
      f1->fim-> prox = f2->inicio;
      f1->fim = f2->fim; 
      f2->inicio = NULL;
      f1->fim = NULL;    
      return 1;
}