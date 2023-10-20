#include <stdio.h>
#define tamanho 10
#define tamanhoMaior 20

int main()
{
    int vetorA[tamanho],vetorB[tamanho],vetorC[tamanhoMaior];
    int i, j;

    for (i = 0; i < tamanho; i++)
    {
        do
        {
           printf("\nDigite um inteiro A(%d): ", i);
           scanf("%d", &vetorA[i]);

           if (vetorA[i]<0)
           {
            printf("\n");
            printf("\nCodigo invalido, faca novamente.");
           } 
           
           else
           {
           vetorC[i] = vetorA[i];
           }

        } while (vetorA[i]<0);  

    }

    for (i = 0; i < tamanho; i++)
    {
        do
        {
           printf("\nDigite um inteiro B(%d): ", i);
           scanf("%d", &vetorB[i]);

           if (vetorB[i]<0)
           {
            printf("\n");
            printf("\nCodigo invalido, faca novamente.");
           } 

           else
           {
           vetorC[i+10] = vetorB[i];
           }

        } while (vetorB[i]<0);  

    }
    
    for (i = 0; i < tamanhoMaior; i++)
    {
        for (j = i + 1; j < tamanhoMaior; j++)
        {
            if (vetorC[i] == vetorC[j])
            {
                vetorC[j] = 0;
            }
            
        }

    }

    printf("\nA uniao dos dois vetores");

    for (i = 0; i < tamanhoMaior; i++)
    {
        if (vetorC[i] != 0)
        {
            printf("\nNumero %d", vetorC[i]);
        }
        
    }

    return 0;
}