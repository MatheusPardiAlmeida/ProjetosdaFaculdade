/*Escreva um programa com um vetor de tamanho N (informado pelo usuário via teclado),
com dados de tipo inteiro ou ponto flutuante (a seu critério),
também informados pelo usuário final via teclado. 
Em seguida, implemente uma função que receba esse vetor e crie uma matriz de tamanho N por N.
A primeira coluna da matriz deve conter os valores originais do vetor.
As colunas restantes devem conter o resultado da multiplicação por 2, 3… n-1.*/

#include <stdio.h>
#include <stdlib.h>

void transformarMatriz(int vetor[], int tam)
{
    int matriz[tam][tam];

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (j == 0)
            {
                *(*(matriz+i)+j) = *(vetor+i);
            }
            else
            {
                *(*(matriz+i)+j) = *(vetor+i)*(j+1);
            }
            
        }
        
    }

    for (int k = 0; k < tam; k++)
    {
        printf("\nLinha %d\t", k);

        for (int l = 0; l < tam; l++)
        {
            printf("\t%d", *(*(matriz+k)+l));
        }
        
    }

}

int main()
{
    int tam;
    int tipo;

    do
    {
        printf("\nDetermine o tamanho do vetor(Maior que 1): ");
        scanf("%d", &tam);

        if (tam <= 1)
        {
            printf("\n");
            printf("\nO valor deve ser maior que 1!!!!!");
            printf("\n");
        }
        
    } while (tam <= 1);

    int vetor[tam];

    for (int i = 0; i < tam; i++)
    {
        printf("\nValor do vetor na posicao[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    transformarMatriz(vetor, tam);

    return 0;

}