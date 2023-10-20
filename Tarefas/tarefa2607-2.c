#include <stdio.h>
#define Tam 8

int main()
{
    int num[Tam], numSoma;
    
    for (int i = 0; i < Tam; i++)
    {
      printf("\nDigite um numero: ");
      scanf("%d", &num[i]);
    }
    
    for (int i = 0; i < Tam; i++)
    {
        if (num[i] % 2 == 0)
        {
            numSoma += num[i];
        }    
    }

    printf("\nO total foi de %d", numSoma);
    
    return 0;
}