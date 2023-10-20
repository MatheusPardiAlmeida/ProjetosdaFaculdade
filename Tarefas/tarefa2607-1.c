#include <stdio.h>
#define Tam 10

int main()
{
    int num[Tam];

    for (int i = 0; i < Tam; i++)
    {
       printf("\nDigite um numero: ");
       scanf("%d", &num[i]);
    }

    for (int i = 0; i < Tam; i++)
    {
        if (num[i]<0)
        {
            printf("\nO numero e %d\n", num[i]);
        }
 
    }

    printf("\nFinalizado.\n");
    
    return 0;
}