/*Implemente, na linguagem de programação C, um programa que contenha duas variáveis: uma do tipo inteiro e outra com ponto flutuante.
Compare os endereços dessas variáveis e exiba, de uma só vez, o maior endereço de memória, junto ao valor que ele armazena.*/

#include <stdio.h>

int main()
{
    int x;
    int *y;
    
    if (&x > &y)
    {
        printf("Maior endereco de memoria eh: x, (%p),(%d)", &x, x);
    }
    else
    {
        printf("Maior endereco de memoria eh: y (%p), (%d)", &y, y);
    }

    return 0;
}