#include <stdio.h>
#define Tamanho 3

int main()
{
    int nota[Tamanho];
    float peso[Tamanho], divisaoMedia=0.0, somaMedia=0.0, resultadoMedia;

    for (int i = 0; i < Tamanho;)
    //Podemos tirar uma das três condições dentro do laço for (a de tamanho limite ou incremento)
    //Com isso podemos colocar o incremento dentro do laço de repetição, sem que ocorra o incremento caso a nota seja menor que 0 ou maior que 10
    //E dentro do próprio laço já podemos definir qual será o peso de cada posição
    {
        printf("\n");
        printf("\nInsira a nota %d do aluno: ", i+1);
        scanf("%d", &nota[i]);
        
        if ((nota[i]<0) || (nota[i]>10))
        {
            printf("\nNota invalida, escreva novamente.");
        }
        else if (nota[i] % 2 == 0)
        {
            peso[i] = 5.5;
            i++;
        }
        else
        {
            peso[i] = 4.5;
            i++;
        } 

    }

    for (int i = 0; i < Tamanho; i++)
    {
        //Aqui faremos a soma dos divisores e a soma da multiplicação das notas com o peso
        divisaoMedia = divisaoMedia + peso[i];

        somaMedia = (somaMedia + (nota[i]*peso[i]))*1.0;
    }
    
    resultadoMedia = somaMedia/divisaoMedia;

    printf("\n");
    printf("\nO resultado da media: %.2f", resultadoMedia);

    return 0;
}