#include <stdio.h>

int main()
{
    float peso, altura, IMC;

    do
    {
      printf("\n");
      printf("\nInsura seu peso em KG: ");
      scanf("%f", &peso);

      if (peso < 1)
      {
        printf("\n");
        printf("\nPeso invalido, digite novamente.");
      }
      
    } while (peso < 1);

    do
    {
      printf("\n");
      printf("\nINSTRUCOES: Use o . para separar entre m e cm (Exemplo: 1 metro e 60 cm = 1.60)");
      printf("\nInsura sua altura: ");
      scanf("%f", &altura);

      if (altura < 0)
      {
        printf("\n");
        printf("\nPeso invalido, digite novamente.");
      }

    }while(altura < 0);

    IMC = peso/(altura*altura)*1.0;

    if ((IMC > 0) && (IMC < 17))
    {
      printf("\n");
      printf("\nVoce esta muito abaixo do peso.");
    }
    else if ((IMC >= 17) && (IMC < 18.49))
    {
      printf("\n");
      printf("\nVoce esta abaixo do peso.");
    }
    else if ((IMC > 18.5) && (IMC < 24.99))
    {
      printf("\n");
      printf("\nVoce esta no peso normal.");
    }
    else if ((IMC > 25) && (IMC < 29.99))
    {
      printf("\n");
      printf("\nVoce esta acima do peso.");
    }
    else if ((IMC > 30) && (IMC < 34.99))
    {
      printf("\n");
      printf("\nVoce esta com Obesidade I.");
    }
    else if ((IMC > 35.5) && (IMC < 39.99))
    {
      printf("\n");
      printf("\nVoce esta com Obesidade II (severa).");
    }
    else if (IMC > 40)
    {
      printf("\n");
      printf("\nVoce esta com Obesidade III (morbida).");
    }
    else
    {
      printf("\n");
      printf("\nValor fora da tabela.");
    }
    
    return 0;
}