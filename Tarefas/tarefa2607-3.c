#include <stdio.h>
#define Tam 5

int main()
{
    int num[Tam], mediaNum;

    for (int i = 0; i < Tam;)
    {
        do
        {
            printf("\nDigite um numero: ");
            scanf("%d", &num[i]);

            if (num[i] < 0)
            {
                printf("Numero invalido.\n");
                printf("\n");
            }
            
        } while (num[i] < 0);

        if (num[i] % 2 != 0)
        {
            mediaNum += num[i];
            i++;
        }
        else
        {
            i++;
        }
        
    }
    
    mediaNum = mediaNum / Tam;

    printf("A media e de %d\n", mediaNum);

    return 0;
}