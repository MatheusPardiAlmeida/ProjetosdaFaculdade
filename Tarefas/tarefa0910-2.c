#include <stdio.h>

int main()
{
    /*Declaramos todas as variáveis a serem utilizadas no nosso programa, sendo a variável maiorDia para determinar o dia com maior faturamente
    , a variável matrizFaturamento sendo a nossa matriz, a somaFaturamente vai armazenar a soma dos faturamentos de cada dia da semana
    e o maior faturamente será o valor para determinar qual dia da semana teve o maior faturamento*/

    int maiorDia;
    double matrizFaturamento[7][11], somaFaturamento, maiorFaturamento=0;

    for (int i = 0; i < 7; i++) //Dia
    {
        somaFaturamento = 0; /*Toda vez que passar para o próximo dia, a soma do faturamente voltará pra 0*/

        for (int j = 0; j < 10; j++) //Vendas do dia
        {
            do
            {
                printf("\nInsira o faturamento do dia %d, valor numero %d: R$", i+1, j+1);
                scanf("%lf", &matrizFaturamento[i][j]);
                
                if (matrizFaturamento[i][j] < 0) //Faremos a verificação para saber se é maior que 0
                {
                    printf("Valor invalido.\n");
                }
                
            } while (matrizFaturamento[i][j] < 0);

            somaFaturamento += matrizFaturamento[i][j]; //Faremos a soma de cada valor do dia
        }

        matrizFaturamento[i][10] = somaFaturamento / 10; //Na última posição do vetor iremos armazenar a média de cada dia

        if (matrizFaturamento[i][10] > maiorFaturamento) //Caso a média do dia seja maior que o maior faturamento, o valor mudará e o dia também
        {
            maiorFaturamento = matrizFaturamento[i][10];
            maiorDia = i;
        }
        
    }
    
    printf("\nDia 1 \tDia 2 \tDia 3 \tDia 4 \tDia 5 \tDia 6 \tDia 7 \tMedia de cada dia\n");

    for (int i = 0; i < 7; i++)
    {
       printf("R$%.2lf\t", matrizFaturamento[i][10]);
    }
    
    printf("\n");
    printf("\nO maior faturamento foi no dia %d", maiorDia + 1);
    
    return 0;
}