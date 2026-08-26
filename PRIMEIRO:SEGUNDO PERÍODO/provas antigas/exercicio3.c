/*exercício 3: Altere os algoritmos bubble sort, insertion sort e selection sort, vistos em aula,
para que estes ordenem uma lista de inteiros em ordem decrescente ao invés de em
ordem crescente.*/

void bubble_sort( int v[] , int tam){

int i ,ult , aux;

      for( ult = tam -1 ; ult > 0  ; ult-- ){

            for( i = 0 ; i < ult ;i++){
                        
                        if( v[i] < v[i+1]){

                              aux = v[i];
                              v[i] = v[i+1];
                              v[i+1] = aux;
      }
}
}
}

void insertion_sort( int v[] , int tam){

      int i , j , aux ;

      for( i = 1 ; i < tam ; i++ ){

            aux = v[i];
            j = i;


      while( (j > 0) && (aux > v[j-1])){

            v[j] = v[j-1];
            j--;
      }
      v[j] = aux;

}
}

void selection_sort( int v[] , int tam){

int i , p , posMaior, aux ;

      for(i = 0 ; i < tam - 1 ; i++){

            posMaior = i;
         for( p = i+1 ; p < tam ; p++ ){

            if(v[p] > v[posMaior]){

                  posMaior = p;
            }
      } 
      aux = v[i];
      v[i] = v[posMaior];
      v[posMaior] = aux;

      }

}



