#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Tam 3

int main()
{
    srand(time(NULL)); /*Gerar um número aleatório*/
    int matrizA[Tam][Tam], matrizB[Tam][Tam], matrizC[Tam][Tam], i, j; /*Temos a variável da matriz, e as variáveis i e j para linha e coluna respectivamente*/

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            matrizA[i][j] = rand()%50; //A matriz receberá um número aleatório entre 0 e 50
        }      
    }

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            matrizB[i][j] = rand()%50; //A matriz receberá um número aleatório entre 0 e 50
        }      
    }

    for (i = 0; i < Tam; i++) //Linha
    {
        for (j = 0; j < Tam; j++) //Coluna
        {
            if (matrizA[i][j] > matrizB[i][j]) //Caso o valor de A seja maior que B, C receberá A
            {
                matrizC[i][j] = matrizA[i][j];
            }
            else
            {
                matrizC[i][j] = matrizB[i][j]; //Caso contrário, C receberá B
            }       
        }      
    }

    printf("\nCol 1\t Col 2\t Col 3\tPara a Matriz A\n"); //Para separar as colunas

    for (i = 0; i < Tam; i++)
    {
        for (j = 0; j < Tam; j++)
        {
            printf("%d\t", matrizA[i][j]); //Imprimir os valores da matriz A
        }    
        printf("\n");  
    }

    printf("\nCol 1\t Col 2\t Col 3\tPara a Matiz B\n"); //Para separar as colunas

    for (i = 0; i < Tam; i++)
    {
        for (j = 0; j < Tam; j++)
        {
            printf("%d\t", matrizB[i][j]); //Imprimir os valores da matriz B
        }    
        printf("\n");  
    }

    printf("\nCol 1\t Col 2\t Col 3\tPara a Matriz C\n"); //Para separar as colunas

    for (i = 0; i < Tam; i++)
    {
        for (j = 0; j < Tam; j++)
        {
            printf("%d\t", matrizC[i][j]); //Imprimir os valores da matriz C
        }     
        printf("\n");  
    }

    return 0;
}