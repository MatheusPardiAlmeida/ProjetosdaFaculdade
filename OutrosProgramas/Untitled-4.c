#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

} calendario;

/*void tamanhoMemoria(int *memoria)
{
    
    printf("\n");
}*/

void Preencher(calendario vetor[], int *posicao, int *tamanho)
{
    if (*posicao > (*tamanho-1))
    {
        printf("\n");
        printf("\nO vetor esta cheio!");
    }
    else
    {
        printf("\nDigite o dia do vetor[%d]: ", *posicao);
        scanf("%d", &vetor[*posicao].dia);
        printf("\nDigite o mes do vetor[%d]: ", *posicao);
        scanf("%d", &vetor[*posicao].mes);
        printf("\nDigite o ano do vetor[%d]: ", *posicao);
        scanf("%d", &vetor[*posicao].ano);
    }
    
}

void apagarVetor(calendario vetor[], int *posicao, int *tamanho)
{
    int indice;

    printf("\n");
    printf("\nDigite o indice que deseja apagar [0-%d]: ", (*tamanho-1));
    scanf("%d", &indice);

    if (indice < 0 || indice > (*tamanho-1))
    {
        printf("\nValor invalido, digite um valor valido [0-%d]: ", (*tamanho-1));
        scanf("%d", &indice);
    }

    for (int i = indice; i < (*tamanho-1); i++)
    {
        vetor[i] = vetor[i+1];
    }
    
    (*posicao)--;

}

int main()
{
    int opcao;
    int posicao = 0;
    int tamanho;

    printf("\nDigite o valor do tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    //tamanhoMemoria(&tamanho);
    calendario *vetor;

    vetor = (calendario*) malloc(sizeof(calendario) * tamanho); 

    do
    {
        printf("\nOpcoes Menu");
        printf("\n1 - Preencher Struct");
        printf("\n2 - Apagar vetor struct");
        printf("\n3 - Finalizar programa");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            Preencher(vetor, &posicao, &tamanho);
            break;
            
            case 2:
            apagarVetor(vetor, &posicao, &tamanho);
            break;

            case 3:
            printf("\n");
            printf("\nFinalizando programa....");
            return 0;
            break;
        
            default:
            printf("\nInvalido, tente novamente.");
            break;
        }


    } while (1);

}