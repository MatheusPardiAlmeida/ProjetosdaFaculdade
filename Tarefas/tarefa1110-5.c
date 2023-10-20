#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Linha 5
#define Caracteres 51

/*ANOTAÇÃO: Sempre que eu digito uma palavra maior que 50 caracteres, ocorre um bug no fgets e é pulada uma linha do for*/

int main()
{
    char matriz[Linha][Caracteres]; /*Definimos o tamanho da nossa matriz, possuindo 5 linhas com no máximo 51 colunas*/
    int i, maiorLinha = 0; /*Teremos nossa variável i para ser as nossas strings e maiorLinha para armazenar a nossa maior string*/

    for (i = 0; i < Linha; i++) 
    /*Como cada coluna é um caracter, e queremos ler uma palavra inteira, não é usado o segundo for para a coluna, já que
    não queremos preencher caracter por caracter*/
    {
        printf("\nDigite uma palavra para a linha %d: ", i+1);
        fgets(matriz[i], Caracteres, stdin); //Utilizamos o fgets para ler strigs de char, com espaço

        if (strlen(matriz[i]) > strlen(matriz[maiorLinha])) /*Aqui faremos a verificação para saber se o tamanho da string atual é maior que o valor da maior string digitada*/
        {
            maiorLinha = i; //Aqui iremos armazenar em qual linha nós temos a maior string
        }     
    }

    printf("\nNossa maior string foi a %d, com %d caracteres.", maiorLinha+1, strlen(matriz[maiorLinha]));
    printf("\n%s", matriz[maiorLinha]);
    
    return 0;
}