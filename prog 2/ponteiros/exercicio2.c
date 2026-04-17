/*Faça uma função que receba uma string
como parâmetro e retorne o número de
vogais desta.
– Apresente duas versões da função: uma usando
vetores e outra utilizando ponteiros

#include <stdio.h>

//versao string
int conta_vogais(char v[]){ //vetor de caracteres

    int i;//percorre a string(vetor de caracteres)
    int n=0; //contador de vogais

        for(i=0 ; v[i]!='\0' ; i++ ){

            if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u'){
                n++;
            }

}
    return n;
}

//teste
int main(){

    char nome[]="neto";

    conta_vogais(nome);
    printf(" o numero de vogais é:%d", conta_vogais(nome));
    return 0;

}*/


#include <stdio.h>

//versao ponteiro
int conta_vogais(char v[]){ // string(vetor de caracteres)

//int i; // nao uso isso pois percorre a string(vetor de caracteres)

    char *i; //ponteiro que vai acessar o vetor de caracteres(VAI PERCORRER A STRING)
    int n=0 ; //contador de vogais 
    
/*COMENTARIOS PARA O FOR
        i = &v[0]; //aponta para o endereco v[0] ; 
        *i !='\0' condicao de parada é quando o conteudo do 
        vetor apontado tem que ser != de \0 ; i++ 
        i++ 'pula pra v[1]... v[2]'
        */

        for( i = &v[0] ; *i !='\0' ; i++){

            if( *i=='a' || *i=='e' || *i=='i' || *i=='o' || *i=='u'){
                // *i verifica o conteudo de onde i aponta

                 n++;
            }

}
 
    return n;
}

//teste
int main(){
    
    char nome[]="leticia";
    conta_vogais(nome);
    printf(" o numero de vogais é:%d", conta_vogais(nome));

    return 0;

}










