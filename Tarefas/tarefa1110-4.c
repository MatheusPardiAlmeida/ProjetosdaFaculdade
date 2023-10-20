#include <stdio.h>
#define Lin 4
#define Col 8

int main()
{
    /*Como precisamos fazer a verificação para saber se o número é par ou impar, aumentaremos em 1 o número de linha e coluna
    para que possamos definir o começo da linha e coluna como 1, assim teremos uma verificação correta para saber se o número
    será par ou ímpar*/

    double matriz[Lin][Col], somaPar=0, somaLinhaPar=0, somaImpar=0, mediaLinhaPar; /*Variável double para matriz*/
    int i, j; /*Variáveis para Linhas e Colunas, respectivamente*/

    for (i = 1; i < Lin; i++) //Linha
    {
        for (j = 1; j < Col; j++) //Coluna
        {
            do //Caso o número seja menor que 0, o loop será reiniciado
            {
                printf("\nDigite o valor para a linha %d, coluna %d: ", i, j);
                scanf("%lf", &matriz[i][j]);

                if (matriz[i][j] < 0) 
                {
                    printf("\nValor invalido.");
                    printf("\n");
                }
                
            } while (matriz[i][j] < 0);
        }      
    }

    for (i = 1; i < Lin; i++) //Linha
    {
        for (j = 1; j < Col; j++) //Coluna
        {                
            if (j % 2 == 0)
            {
                somaPar += matriz[i][j]; //Caso a coluna seja um número par
            }
            else
            {
                somaImpar += matriz[i][j]; //Caso a coluna seja um número ímpar
            }            
        }      
    }

    for (i = 1; i < Lin; i++) //Linha
    {
        for (j = 1; j < Col; j++) //Coluna
        {                
            if (i % 2 == 0)
            {
                somaLinhaPar += matriz[i][j]; 
                /*Como não encontrei uma forma de fazer a soma das linhas dentro do outro par, utilizei outro for
                para fazer a soma dos valores nas linhas pares*/
            }           
        }      
    }

    mediaLinhaPar = somaLinhaPar / 7; /*Depois de finalizar todos os laços de repetição, faremos a média da soma dos valores das linhas pares*/

    printf("\nCol 1\t Col 2\t Col 3\t Col 4\t Col 5\t Col 6\t Col 7\n"); //Para separar as colunas

    for (i = 1; i < Lin; i++) //Linha
    {
        for (j = 1; j < Col; j++) //Coluna
        {
            printf("%.2lf\t", matriz[i][j]); //Imprimir os valores da matriz
        }    
        printf("\n");  
    }

    printf("\nA soma das colunas pares: %.2lf", somaPar);
    printf("\nA soma das colunas impares: %.2lf", somaImpar);
    printf("\nA media das linhas pares: %.2lf", mediaLinhaPar);

    return 0;
}