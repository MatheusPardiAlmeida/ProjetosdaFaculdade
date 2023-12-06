/*Crie um programa contendo três vetores (A, B e C), de tamanho igual. Para os vetores A e B, os valores devem ser lidos do teclado. 
Em seguida, implemente uma função que recebe os três vetores. Cada posição do vetor C deve ser preenchido com o maior valor do vetor A ou B naquela mesma posição.
Use aritmética de ponteiros para efetuar essas operações. */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int vetorA[3];
    int vetorB[3];
    int vetorC[3];

    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite o valor do vetorA na posicao[%d]: ", i);
        scanf("%d", &vetorA[i]);
    }

    printf("\n");

    for (int j = 0; j < 3; j++)
    {
        printf("\nDigite o valor do vetorB na posicao[%d]: ", j);
        scanf("%d", &vetorB[j]);
    }

    for (int k = 0; k < 3; k++)
    {
        if (*(vetorA+k) > *(vetorB+k))
        {
            *(vetorC+k) = *(vetorA+k);
        }
        else
        {
            *(vetorC+k) = *(vetorB+k);
        }

    }

    printf("\nVetor A: ");

    for (int a = 0; a < 3; a++)
    {
        printf("\t%d", *(vetorA+a));
    }

    printf("\nVetor B: ");
    
    for (int b = 0; b < 3; b++)
    {
        printf("\t%d", *(vetorB+b));
    }

    printf("\nVetor C: ");

    for (int c = 0; c < 3; c++)
    {
        printf("\t%d", *(vetorC+c));
    }

    return 0;
}