/*Uma estudante de Algoritmos e Estrutura de Dados II deseja implementar com conjunto de funções/procedimentos para facilitar a criação
de vetores alocados dinamicamente na memória, oferecendo recursos que possibilitem:

a) a criação de um novo vetor;
b) a inserção de valores no vetor, lidos do teclado;
c) a impressão do vetor;
d) a mudança da capacidade de armazenamento do vetor, para mais ou para menos;
e) a liberação do espaço de memória ocupado pelo vetor;*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int criacaoVetor()
{
    int tamanhoVetor;

    do
    {
        printf("\n");
        printf("Diga o tamanho do vetor (maior que 1!!!!!): ");
        scanf("%d", &tamanhoVetor);

        if (tamanhoVetor <= 1)
        {
            printf("\n");
            printf("Digite um valor maior que 1!!!!!!!!!");
        }
        
    } while (tamanhoVetor <= 1);
    
    int *vetor = (int*) calloc(tamanhoVetor, sizeof(int));

}

int preencherVetor(int *vetor, int tamanhoVetor)
{

    for (int i = 0; i < tamanhoVetor; i++)
    {

        printf("\n");
        printf("Digite o valor do vetor na pos[%d]: ", i);
        scanf("%d", &vetor[i]);
    
    }

    return *vetor;
    
}

void imprimirVetor(int *vetor, int tamanhoVetor)
{
    printf("\nVetor: ");

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\t%d", *(vetor+i));
    }

    printf("\n");

}

void alterarVetor(int *vetor, int *tamanhoVetor)
{
    int novoTamanho;
    
    do
    {
        printf("\n");
        printf("Digite um novo tamanho para o vetor: ");
        scanf("%d", &novoTamanho);

        if (novoTamanho <= 1)
        {
            printf("\n");
            printf("O tamanho deve ser maior que 1!!!!!!!\n");
        }
        
    } while (novoTamanho <= 1);

    *tamanhoVetor = novoTamanho;

    int *novoVetor = (int*) realloc(vetor, novoTamanho * sizeof(int));

    if (novoVetor != vetor)
    {
        printf("\n");
        printf("Mudou de local\n");
    }
    else
    {
        printf("\n");
        printf("Nao mudou de local\n");
    }

    if (novoVetor != NULL)
    {
        vetor = novoVetor;
    }
    
} 

void limparVetor(int *vetor)
{

    free(vetor);
    vetor = NULL;
}

int main()
{
    int escolhaMenu;
    int loopMenu;

    do
    {
        loopMenu = 0;

        printf("\n");
        printf("========================================\n");
        printf("1 - Criar vetor\n");
        printf("2 - Preencher vetor\n");
        printf("3 - Imprimir vetor\n");
        printf("4 - Alterar vetor\n");
        printf("5 - Limpar vetor\n");
        printf("6 - Finalizar programa\n"); 
        printf("========================================\n");
        printf("Sua escolha: ");
        scanf("%d", &escolhaMenu);

        switch (escolhaMenu)
        {
            case 1:
            
            criacaoVetor();
            
            break;

            case 2:
            
            break;

            case 3:
            
            break;

            case 4:
            
            break;

            case 5:
            
            break;

            case 6:

            printf("\n");
            printf("Finalizando programa.....\n");
            printf("\n");
            
            loopMenu = 1;

            break;

        
            default:
            printf("\n");
            printf("Escolha invalida, tente novamente.\n");
            break;
        }



    } while (loopMenu == 0);
    
    

    criacaoVetor(preencherVetor, imprimirVetor, alterarVetor, limparVetor);
    

    return 0;
}