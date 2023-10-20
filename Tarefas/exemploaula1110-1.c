#include <stdio.h>

int main()
{
    int matriz[4][4], num, i, j;

    for (i = 0; i < 4; i++) //Linha
    {
        for (j = 0; j < 4; j++) //Coluna
        {
            do
            {
                printf("\nPreencha os valores da linha %d, coluna %d: ", i, j); //Fazer leitura dos elementos
                scanf("%d", &matriz[i][j]);
                
                if (matriz[i][j] < 0)
                {
                    printf("Invalido, tente novamente.\n");
                    printf("\n");
                }
                
            } while (matriz[i][j] < 0); 
        }   
    }

    do
    {
        printf("\nDigite o numero a ser encontrado na matriz: "); //Digitar o número para encontrar na matriz
        scanf("%d", &num);

        if (num < 0)
        {
            printf("Invalido, tente novamente.\n");
            printf("\n");
        }
        
    } while (num < 0);

    for (i = 0; i < 4; i++) //Linha
    {
        for (j = 0; j < 4; j++) //Coluna
        {
            if (matriz[i][j] == num)
            {
                printf("\nO numero %d foi encontrado na linha %d, coluna %d.", num, i, j);
                return 0; //Utilizaremos o return 0 para encerrar o programa aqui
            }        
        }    
    }
    
    printf("\nO numero nao foi encontrado."); //Caso não seja encontrado nenhum número, essa mensagem será mostrada.

    return 0;
}