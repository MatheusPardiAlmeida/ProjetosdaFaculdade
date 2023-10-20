#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 10

int main()
{
    float mediaValores=0.0, totalValores=0.0;
    int numeros[TAM];
    int par=0,impar=0;

    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
    {
        numeros[i] = rand()%80;

      if (numeros[i] % 2 == 0)
      {
        par++;
      }
     
      else
      {
        impar++;
      }

      printf("\n");
      printf("\nOs valores do vetor sao: %d", numeros[i]);
   
    }
   
    for (int i = 0; i < TAM; i++)
    {
      totalValores = (totalValores + numeros[i])*1.0;
    }

    mediaValores = (totalValores / TAM)*1.0;
   
    printf("\n");
    printf("\nA media total e de: %.2f", mediaValores);
    printf("\n");
    printf("\nQuantidade de par %d e quantidade de impar %d.", par, impar);

    return 0;
}
