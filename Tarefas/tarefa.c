#include <stdio.h>
#define Gado 15

int main()
{
    //Declaramos as variáveis para o cálculo do peso do rebanho
    //A variável rebanho serve para cortar o número de gado, resultadoPesagem é o valor total do peso e resultadoMedia é a média final de todos os pesos dividido
    //pelo tamanho do rebanho
    double rebanho[Gado],resultadoPesagem,resultadoMedia;
    int i=0, media = 700;
 
    do
    {   //Aqui faremos a repetição do laço enquanto o valor digitado for inválido
        printf("\n");
        printf("\nDigite o valor da massa total do gado %d: ", i);
        scanf("%lf", &rebanho[i]);

        if (rebanho[i] < 1)
        {
            printf("\nValor invalido, tente novamente: ");
            printf("\n");
        }
        else
        {
            i++;
        }
    } while (i < Gado);

    for (i = 0; i < Gado; i++)
    {
        resultadoPesagem = resultadoPesagem + rebanho[i];
        //Aqui faremos a soma dos pesos e a verificação para saber se eles estão acima ou abaixo da média
        if (rebanho[i] < media)
        {
            printf("\n");
            printf("\nO gado %d esta abaixo da media com %.2lfKG.", i,rebanho[i]);
        }
        else
        {
            printf("\n");
            printf("\nO gado %d esta acima da media com %.2lfKG.", i, rebanho[i]); 
        }
    }

    resultadoMedia = resultadoPesagem / Gado;

    printf("\n");
    printf("\nA media total e: %.2lf", resultadoMedia);

    return 0;
}