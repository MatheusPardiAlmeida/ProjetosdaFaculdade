#include <stdio.h>
#define VelQuilometro 3.6

int main()
{
    float velocidade, velocidadeFinal; //Iremos declarar a velocidade a ser lida e uma variável auxiliar para receber a soma da velocidade pela multiplicação

    printf("\n");
    printf("\nInsira a velocidade em m/s: ");
    scanf("%f", &velocidade);

    velocidadeFinal = (velocidade*VelQuilometro)*1.0; //Aqui faremos a multiplicação da velocidade em m/s por 3,6 para sabermos a velocidade em km/h

    printf("\n");
    printf("\nA velocidade em km/h sera de %.fkm/h", velocidadeFinal);

    return 0;
}