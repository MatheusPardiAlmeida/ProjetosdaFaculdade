#include <stdio.h>

/*Faça um programa que receba um número digitado pelo usuário e imprima a
tabuada de multiplicação desse número de 1 a 10. Dica: para formatar visualmente, utilize \n e \t dentro do printf.*/

int main()
{
    int num, numResultado=0;

    printf("\nInsira um numero: ");
    scanf("%d", &num);

    printf("\nTabuada do numero %d:\n", num);

    for (int i = 1; i < 11; i++)
    {
        numResultado = num*i;
        printf("%dx%d: %d\t", num, i, numResultado);
        printf("\n");
    }

    return 0;
}