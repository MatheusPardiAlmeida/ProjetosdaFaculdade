#include <stdio.h>
#define TamFinal 680
#define TamInicial 450

int main()
{

    for (int i = TamInicial; i < TamFinal; i++)
    {
        if (i % 2 != 0)
        {
            printf("\n%d", i);
        }
    }
    
    return 0;
}