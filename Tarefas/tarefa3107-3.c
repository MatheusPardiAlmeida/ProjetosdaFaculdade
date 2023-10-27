#include <stdio.h>

/*A altura de Rafael é de 1.50m (ou 150cm) e a altura de Lucas é de 1.20 (ou 120cm). Considerando a taxa anual de crescimento de 2.5 centímetros para Rafael e de 4
centímetros para Lucas, desenvolva um algoritmo que calcule e retorne quantos anos
serão necessários para que Lucas seja maior que Rafael.*/

int main()
{
    int i;
    float alturaRafa = 150, alturaLucas = 120;

    for (i = 0; ; )
    {
        alturaRafa += 2.5;
        alturaLucas += 4.0;

        if (alturaLucas > alturaRafa)
        {
            break;
        }
        else
        {
            i++;
        }  
    }
    
    printf("\nEm %d anos Lucas sera maior que Rafael.", i);
    printf("\n");
    printf("\nFinalizando programa............");

    return 0;
}