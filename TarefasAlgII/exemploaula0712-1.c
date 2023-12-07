/*Da mesma forma que o exemplo anterior, mas utilizando vetores*/
#include <stdio.h>
void receberPonteiro(void *ponteiro, char tipo)
{
    int numAuxiliar = 0;

    switch (tipo)
    {
        case 'I':
        
        printf("\nVetor X: ");

        for (int i = 0; i < 4; i++)
        {
            if (i >= 1)
            {
                numAuxiliar += 4;
            }
            
            printf("\t%d", *(int*)(ponteiro+numAuxiliar));
        }
        
        break;

        case 'F':

        printf("\nVetor Y: ");
        
        for (int j = 0; j < 4; j++)
        {
            if (j >= 1)
            {
                numAuxiliar += 4;
            }

            printf("\t%.2f", (*(float*)ponteiro+numAuxiliar));
        }

        break;
    }
}

int main()
{
    int vetorX[4] = {4, 5, 3, 2};
    float vetorY[4] = {5.5, 3.4, 9.3, 1.8};
    void *ponteiroA = &vetorX;
    void *ponteiroB = &vetorY;

    receberPonteiro(ponteiroA, 'I');
    receberPonteiro(ponteiroB, 'F');

    return 0;
}