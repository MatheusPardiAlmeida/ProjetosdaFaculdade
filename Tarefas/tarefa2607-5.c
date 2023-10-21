#include <stdio.h>

int main()
{
    double salario, somaSalario=0, media; /*Aqui temos as variáveis para armazenar os valores*/
    int i; /*Utilizaremos a variável i para armazenar a quantia de salários que foi lida*/

    for (i = 0; ;) /*Omitindo a cláusula de parada e incremento, podemos criar um laço infinito, onde controlamos o incremento e a parada*/
    {
        printf("\nDigite o salario %d:R$ ", i);
        scanf("%lf", &salario);

        if (salario < -1)
        {
            printf("\nSalario invalido.");
            printf("\n");
        }
        else if (salario == -1)
        {
            break; /*Utilizando o break, podemos quebrar o laço de repetição e continuar o programa*/
        }
        else
        {
            somaSalario += salario;
            i++;
        }
    }

    if (i > 0)
    {
        media = somaSalario/i; /*Aqui faremos a media de todos os salários*/

        printf("\nO salario total e de: R$%.2lf", somaSalario);
        printf("\nE a media total e de: R$%.2lf", media);

    }
    else
    {
        printf("\nNenhum salario foi inserido.");
    }

    return 0;
}