#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Tam 2

int main()
{
    srand(time(NULL)); /*Gerar um número aleatório*/
    int matriz[Tam][Tam], i, j; /*Temos a variável da matriz, e as variáveis i e j para linha e coluna respectivamente*/
    int multiPrincipal = 1, multiSecundária = 1, resultado; //As variáveis para armazenar os valores dos cálculos

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            matriz[i][j] = rand()%20; //A matriz receberá um número aleatório entre 0 e 20

            if (i == j)
            {
                multiPrincipal *= matriz[i][j]; //Aqui faremos a multiplicação dos valores da diagonal principal
            }
            else
            {
                multiSecundária *= matriz[i][j]; //Aqui faremos a multiplicação dos valores da diagonal secundária
            }
        }      
    }

    resultado = multiPrincipal - multiSecundária; //Aqui faremos o cálculo da determinante

    printf("\nCol 1\t Col 2\n"); //Para separar as colunas

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            printf("%d\t", matriz[i][j]); //Imprimir os valores da matriz
        }    
        printf("\n");  
    }

    printf("\nResultado do determinante: %d", resultado);
    
    return 0;
}