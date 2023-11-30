/*Crie um programa contendo dois vetores (A e B), de tamanho igual, cujos valores foram lidos do teclado. 
Em seguida, implemente uma função que recebe esses vetores e troque os valores do vetor A com os valores do vetor B. Use aritmética de ponteiros para efetuar essas operações.*/

#include <stdio.h>
#include <stdlib.h>

void trocarVetores(int *vetorA, int *vetorB)
{
    int vetorAuxiliar[3];

    for (int i = 0; i < 3; i++)
    {
        vetorAuxiliar[i] = *(vetorA+i);
    }

    for (int j = 0; j < 3; j++)
    {
        *(vetorA+j) = *(vetorB+j);
    }

    for (int k = 0; k < 3; k++)
    {
        *(vetorB+k) = vetorAuxiliar[k];
    }


    for (int l = 0; l < 3; l++)
    {
        printf("\nVetor A na pos %d : %d", l, *(vetorA+l));
    }
    
    printf("\n");

    for (int m = 0; m < 3; m++)
    {
        printf("\nVetor B na pos %d : %d", m, *(vetorB+m));
    }

}

int main()
{
    int vetorA[3];
    int vetorB[3];

    for (int i = 0; i < 3; i++)
    {
        printf("\nDigite o valor para o vetorA na pos %d: ", i);
        scanf("%d", &vetorA[i]);
        printf("\n");
    }

    for (int j = 0; j < 3; j++)
    {
        printf("\nDigite o valor para o vetorB na pos %d: ", j);
        scanf("%d", &vetorB[j]);
        printf("\n");
    }

    trocarVetores(vetorA, vetorB);

    return 0;
}