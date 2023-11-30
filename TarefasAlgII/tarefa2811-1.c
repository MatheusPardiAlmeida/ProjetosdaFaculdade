/*Implemente, na linguagem de programação C, um programa que contenha duas variáveis: uma do tipo inteiro e outra com ponto flutuante.
Compare os endereços dessas variáveis e exiba, de uma só vez, o maior endereço de memória, junto ao valor que ele armazena.*/

#include <stdio.h>

int main()
{
    int x = 10;
    float y = 20.5;
    int *enderecoX;
    float *enderecoY;

    enderecoX = &x;
    enderecoY = &y;

    if (*(enderecoX) > *(enderecoY))
    {
        printf("Maior endereco de memoria eh: %p. Valor:%d", enderecoX, *enderecoX);
    }
    else
    {
        printf("Maior endereco de memoria eh: %p. Valor:%.2f", enderecoY, *enderecoY);
    }

    return 0;
}