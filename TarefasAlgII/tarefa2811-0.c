/*Escreva, usando ponteiros, uma função que recebe duas variáveis do tipo inteiro: uma representa a idade de uma pessoa, enquanto a outra representa o sexo.
A função deve atualizar o valor da variável que representa a idade para o tempo que falta para a pessoa se aposentar,
, considerando as seguintes regras hipotéticas:
mulheres podem se aposentar aos 60 anos;
homens podem se aposentar aos 65 anos;*/
#include <stdio.h>
#include <stdlib.h>

int idadeAposentar(int *idade, int *sexo)
{
    if (*sexo == 1)
    {
        *idade = 65 - *idade;
    }
    else
    {
        *idade = 60 - *idade;
    }
    
    return *idade;

}

int main()
{
    int idade;
    int sexo;

    do
    {
        printf("Digite sua idade: ");
        scanf("%d", &idade);
        printf("\n");

        if (idade <= 0)
        {
            printf("Idade invalida, tente novamente.\n");
            printf("\n");
        }
        
    } while (idade <= 0);

    do
    {
        printf("1 - Masculino\n");
        printf("2 - Feminino\n");
        printf("Digite seu sexo: ");
        scanf("%d", &sexo);

        if (sexo < 1 || sexo > 2)
        {
            printf("Entrada invalida, tente novamente.\n");
            printf("\n");
        }
        
    } while (sexo < 1|| sexo > 2);
    
    idade = idadeAposentar(&idade, &sexo);

    if (idade <= 0)
    {
        printf("\n");
        printf("Voce ja tem idade para se aposentar!\n");
    }
    else
    {
        printf("\n");
        printf("Voce tem %d anos ate se aposentar, trabalhe mais!\n", idade);
    }

    return 0;
}