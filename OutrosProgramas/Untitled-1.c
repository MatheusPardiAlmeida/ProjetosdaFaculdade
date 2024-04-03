#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int main()
{
    int vetorA[TAM];
    int vetorB[TAM];

    for (int i = 0; i < TAM; i++)
    {
        printf("\nDigite o valor do vetor na pos[%d]: ", i);
        scanf("%d", &vetorA[i]);
    }

    printf("\nVetor: ");

    for (int j = 0; j < TAM; j++)
    {
        *(vetorB+j) = *(vetorA+j);

        printf("%d\t", *(vetorB+j));
    }

    return 0;
}