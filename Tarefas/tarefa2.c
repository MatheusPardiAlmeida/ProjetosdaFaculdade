#include <stdio.h>

int verificarPrimo(int numero) 
{   
  //Nesta função faremos a verificação para saber se o número é primo ou não, se for primo ele retornará o valor 1, caso contrário será 0
    int divisor = 0;

    for (int denominador = 1; denominador <= numero; denominador++)
    {
        if (numero % denominador == 0)
        {
            divisor++;
        } 
    }

    if (divisor == 2)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{

    int num[10];

    for (int i = 0; i < 10; i++)
    {
      do
      { //Aqui faremos a verificação para saber se é um número válido
        printf("\n");
        printf("\nDigite o %d numero: ", i + 1);
        scanf("%d", &num[i]);

       if (num[i] < 0)
       {
        printf("\n");
        printf("\nNumero invalido, faca novamente: ");
       }

      } while (num[i] < 0);
    
    }

    for (int i = 0; i < 10; i++)
    {  //Aqui faremos a verificação para saber se o número que a função nos retornou é primo ou não
       if (verificarPrimo(num[i]) == 1)
      {
        printf("\n");
        printf("\nO número %d e primo e a posicao e %d\n", num[i], i);
      } //Aqui o programa irá imprimir os números primos e a posição do vetor
    }

    return 0;
}