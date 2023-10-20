#include <stdio.h>

int main()
{
    float media, mediaFinal, menorMedia=10, maiorMedia=0, somaMedia=0; //Aqui temos todas as variáveis para armazenar os valores
    int i; //Utilizaremos a variável i para utilizar como contador
     
    for (i = 0; ; ) //Iremos omitir as duas cláusulas do for para manter o laço infinito e controlar o incremento
    {
        do //Enquanto o valor foi maior que 10, ou igual a 0, pediremos para o usuário repetir até inserir um valor válido
        {
            printf("\nDigite a media do aluno %d: ", i);
            scanf("%f", &media);

        } while (media == 0 || media > 10);

        if (media < 0)
        {
            break;
        }
        else if (media < menorMedia)
        {
            menorMedia = media;
        }
        else if (media > maiorMedia)
        {
            maiorMedia = media;
        }
    
        i++;
        somaMedia += media;
    }

    if (i > 0) //Caso o usuário tenha inserido ao menos uma nota, será mostrado o resultado
    {
        mediaFinal = somaMedia / i;

        printf("\nA menor media foi: %.2f", menorMedia);
        printf("\nA maior media foi: %.2f", maiorMedia);
        printf("\nA media aritmetica foi: %.2f", mediaFinal);
    }
    else //Caso não tenha sido inserido nenhuma nota, o programa acabará aqui
    {
        printf("\nNenhuma media foi inserida.");
    }

    return 0;
}