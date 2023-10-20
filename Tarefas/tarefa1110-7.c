#include <stdio.h>
#include <ctype.h>
#include <string.h>

void numeroConsoantes(char matriz[4][31]) /*No procedimento, declaramos a variável que será lida, nesse caso as nossas strings*/
{
    int i, j, qtdConsoante = 0, maiorQtdConsoante = 0, maiorPosicao; //Temos as variáveis para armazenamento dos valores
    char letra; //Variável para receber a letra minúscula

    for (i = 0; i < 4; i++) //Linha 
    {
        for (j = 0; matriz[i][j] != '\n'; j++) 
        /*Como a função fgets() armazena também o espaço \n no final da string, paramos a leitura dos caracteres assim que a leitura da string
        chega na parte do \n, assim não precisamos parar a leitura no \0 (NULL)*/
        {
            if (isalpha(matriz[i][j])) //Iremos verfificar se o caracter é do alfabeto
            {
                letra = tolower(matriz[i][j]); //Iremos converter para minúsculo

                if (strchr("aeiou", letra) == NULL)
                /*Utilizando o strchr do string.h, podemos utilizar uma string para verificar se a outra possuí o mesmo caractere, nesse caso estamos verificando se a primeira
                string "aeiou" tem algum desses caracteres presentes na string letra, no caso um caractere da nossa string matriz. Caso a primeira string, possua um caracter na
                segunda string, retornará um valor diferente de NULL, caso não, retornará NULL, e com isso podemos verificar se a nossa string possuí alguma vogal.*/
                {
                    qtdConsoante++;
                }        
            }           
        }  

        if (qtdConsoante > maiorQtdConsoante) //Aqui iremos verificar se a string atual possuí mais consoantes do que a maior string com consoantes
        {
            maiorQtdConsoante = qtdConsoante;
            maiorPosicao = i;
        }

        qtdConsoante = 0; //Aqui iremos zerar o valor da quantidade de consoantes para reiniciar o loop
              
    }

    printf("\nA string com mais consoante e a string %d, com %d consoantes", maiorPosicao, maiorQtdConsoante);
    printf("\n%s", matriz[maiorPosicao]);

}

int main() /*Aqui temos nossa função principal, onde será feita a leitura das strings*/
{
    char matriz[4][31], i; /*Temos nossas variáveis*/

    for (i = 0; i < 4; i++) /*Por estarmos lendo uma string, precisamos ler as penas as linhas, já que ela contém todos os caracteres da coluna*/
    {
        printf("\nDigite uma string: "); 
        fgets(matriz[i], 31, stdin); /*Utilizamos o fgets para ler a string e definimos o tamanho dela, no caso o mesmo valor da matriz*/
    }

    numeroConsoantes(matriz); /*Chamamos nosso procedimento, e nele enviaremos as strings*/
    
    return 0;
}