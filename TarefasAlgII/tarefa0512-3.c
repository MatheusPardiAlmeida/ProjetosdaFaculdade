/*Escreva um programa em C que contém uma matriz N por N. O tamanho pode ser escolhido por você.
Usando exclusivamente a aritmética de ponteiros, o programa deve percorrer e calcular o produto da diagonal principal, bem como produto da diagonal secundária.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ordem 5

int main()
{
    srand(time(NULL));
    int numero;
    int resultadoPrincipal = 1;
    int resultadoSecundaria = 1;
    int matriz[ordem][ordem];

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            numero = rand()%50;

            *(*(matriz+i)+j) = numero;
        }
    }

    for (int k = 0; k < ordem; k++)
    {
        printf("\nLinha %d\t", k);

        for (int l = 0; l < 5; l++)
        {
            printf("\t%d", *(*(matriz+k)+l));
        }
        
    }

    printf("\n");

    for (int n = 0; n < ordem; n++)
    {
        for (int m = 0; m < ordem; m++)
        {

            if (n == m)
            {
                resultadoPrincipal *= *(*(matriz+n)+m);
            }
            else
            {
                continue;
            }    
        }  
    }

    for (int t = 0; t < ordem; t++)
    {
        for (int y = 0; y < ordem; y++)
        {

            if ((t+y+2) == (ordem+1))
            {
                resultadoSecundaria *= *(*(matriz+t)+y);
            } 
            else
            {
                continue;
            }    
        }  
    }
    
    printf("\n");
    printf("Resultado da diagonal principal: %d\n", resultadoPrincipal);
    printf("\n");
    printf("Resultado da diagonal secundaria: %d\n", resultadoSecundaria);

    return 0;
}