#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int matriz[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    for (int i = 0; i < 4; i++)
    {
        printf("\nLinha %d\t", i);

        for (int j = 0; j < 4; j++)
        {
            printf("\t%d", *(*(matriz+i)+j));
        }

    }

    return 0;
}