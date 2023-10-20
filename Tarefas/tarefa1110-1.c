#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Tam 4

int main()
{
    srand(time(NULL)); /*Gerar um número aleatório*/
    int matriz[Tam][Tam], i, j; /*Temos a variável da matriz, e as variáveis i e j para linha e coluna respectivamente*/
    int somaAcima = 0, somaAbaixo = 0, multiDiagonal = 1; /*Aqui temos as variáveis para realizer as operações matemáticas*/

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            matriz[i][j] = rand()%50; //A matriz receberá um número aleatório entre 0 e 50
        }      
    }

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            if (i < j)
            {
                somaAcima += matriz[i][j]; //Soma dos valores acima da diagonal principal
            }
            else if (i > j)
            {
                somaAbaixo += matriz[i][j]; //Soma dos valores abaixo da diagonal principal
            }
            else
            {
                multiDiagonal *= matriz[i][j]; //Multiplicação da diagonal principal
            }          
        }    
    }

    printf("\nCol 1\t Col 2\t Col 3\t Col 4\n"); //Para separar as colunas

    for (i = 0; i < Tam; i++)
    {
        for (j = 0; j < Tam; j++)
        {
            printf("%d\t", matriz[i][j]); //Imprimir os valores da matriz
        }    
        printf("\n");  
    }

    printf("\nA soma dos elementos acima: %d", somaAcima);
    printf("\nA soma dos elementos abaixo: %d", somaAbaixo);
    printf("\nA multiplicacao da diagonal principal: %d", multiDiagonal);

    return 0;
}