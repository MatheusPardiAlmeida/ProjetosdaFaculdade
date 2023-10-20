#include <stdio.h>
#define Tam 5

int main()
{
    /*Declaramos todas as nossas variaveis, sendo a variável maiorValor utilizada para armazenar o maiorValor da nossa matriz,
    a variável maiorLinha e maiorColuna para armazenar a localização do nosso maior valor*/
    int matriz[Tam][Tam], maiorValor = 0, maiorLinha, maiorColuna;

    printf("\nPreencha os valores");

    for (int i = 0; i < Tam; i++) //Linha
    {
        for (int j = 0; j < Tam; j++) //Coluna
        {
            printf("\nPosicao[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            
            if (matriz[i][j] > maiorValor)
            {
                maiorValor = matriz[i][j];
                maiorLinha = i;
                maiorColuna = j;
            }
            
        }
        
    }

    printf("\nO maior valor e %d na linha %d e coluna %d", maiorValor, maiorLinha, maiorColuna);
    
    return 0;
}