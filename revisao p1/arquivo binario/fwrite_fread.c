//fwrite(buffer, tamanho, quantidade, arquivo);
//buffer-Endereço da variável que será gravada.
//tamanho-Quantos bytes cada elemento possui.
//quantidade-Quantos elementos escrever.

#include <stdio.h>

/*typedef struct {

    int idade;
    float altura;

} Pessoa;

int main() {

    FILE *arq;

    Pessoa p;

    p.idade = 20;
    p.altura = 1.75;

    arq = fopen("dados.bin", "wb");

    fwrite(&p, sizeof(Pessoa), 1, arq);

    fclose(arq);

    return 0;
}*/


typedef struct {

char nome [50];
int idade;
char sexo; } Tpessoa;

int main()
{

FILE *parq;
Tpessoa p;
if (!(parq = fopen ("dados.bin", "rb")))

return -1;

fread (&p, sizeof(Tpessoa), 1, parq);
printf("%s %d %c\n",p.nome,p.idade,p.sexo);
fclose (parq);
return 0;

}