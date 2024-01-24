/*Crie um programa em C que utilize uma struct para armazenar informações sobre um produto em um sistema de inventário. 
A struct deve conter o nome do produto, preço e quantidade em estoque. 
O programa deve permitir ao usuário adicionar novos produtos ao sistema, atualizar a quantidade em estoque e o preço, 
listar todos os produtos com suas informações ou excluir um produto a partir do índice.
Além disso, implemente uma função para calcular o valor total em estoque de um produto, multiplicando o preço pela quantidade disponível.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char nome[20];
    float preco;
    int quantidade;

}produtos;

void addProdutos(produtos mercadorias[], int *posicao) /*Não utilizei a struct como ponteiro já que estava dando erro*/
{
    fflush(stdin); /*Utilzei o fflush() para ter certeza que não terei problemas no input*/
    printf("\n");
    printf("Digite o nome do produto: ");
    fgets(mercadorias[*posicao].nome, 20, stdin);
    

    for (int i = 0; mercadorias[*posicao].nome[i] != '\n'; i++)
    {
        mercadorias[*posicao].nome[i] = toupper(mercadorias[*posicao].nome[i]); /*Para evitar erros com case sensitive, transformarei a string inteira em 
        caracteres maiuscúlos*/
    }
    

    do
    {
        printf("\n");
        printf("Digite o valor do produto: R$");
        scanf("%f", &mercadorias[*posicao].preco);
        fflush(stdin);

        if (mercadorias[*posicao].preco <= 0)
        {
           printf("\n");
           printf("Valor invalido, tente novamente.\n");
           printf("\n");
        }
        

    } while (mercadorias[*posicao].preco <= 0);

    do
    {
        printf("\n");
        printf("Digite a quantidade do produto: ");
        scanf("%d", &mercadorias[*posicao].quantidade);
        fflush(stdin);

        if (mercadorias[*posicao].quantidade <= 0)
        {
           printf("\n");
           printf("Valor invalido, tente novamente.\n");
           printf("\n");
        }
        

    } while (mercadorias[*posicao].quantidade <= 0);

    (*posicao)++; /*Para incrementar a variável como ponteiro, precisamos fazer assim, caso contrário
    iremos incrementar a posição de memória que a variável aponta*/

}

void atualizarProdutos(produtos mercadorias[])
{
    int loopMenu;
    int indice;
    int opcaoAtualizar;
    char nomeAtualizado[20];
    float precoAtualizado;
    int quantidadeAtualizada;

    printf("\n");
    printf("Digite o indice do produto que deseja atualizar: ");
    scanf("%d", &indice);

    do
    {
        loopMenu = 0;

        printf("\n");
        printf("O que deseja atualizar?\n");
        printf("1 - Nome\n");
        printf("2 - Preco\n");
        printf("3 - Quantidade\n");
        printf("4 - Sair\n");
        printf("Digite: ");
        scanf("%d", &opcaoAtualizar);
        getchar();

        switch (opcaoAtualizar)
        {
            case 1:
            
            fflush(stdin);
            printf("\n");
            printf("Digite o nome atualizado: ");
            fgets(nomeAtualizado, 20, stdin);

            for (int i = 0; nomeAtualizado[i] != '\n'; i++)
           {
                nomeAtualizado[i] = toupper(nomeAtualizado[i]); /*Para evitar erros com case sensitive, transformarei a string inteira em 
                caracteres maiuscúlos*/
           }

            strcpy(mercadorias[indice].nome, nomeAtualizado);

            break;

            case 2:

            do
            {
                printf("\n");
                printf("Digite o valor atualizado: R$");
                scanf("%f", &precoAtualizado);

                if (precoAtualizado <= 0)
                {
                    printf("Valor invalido, tente novamente\n");
                    printf("\n");
                }
                
            } while (precoAtualizado <= 0);

            mercadorias[indice].preco = precoAtualizado;
        
            break;

            case 3:

            do
            {
                printf("\n");
                printf("Digite a quantidade atualizada: ");
                scanf("%d", &quantidadeAtualizada);

                if (quantidadeAtualizada <= 0)
                {
                    printf("Valor invalido, tente novamente\n");
                    printf("\n");
                }
                
            } while (quantidadeAtualizada <= 0);

            mercadorias[indice].quantidade = quantidadeAtualizada;
            
            break;
            
            case 4:
            loopMenu = 1;
            break;
        
            default:
            printf("\nOpcao invalida, tente novamente.");
            printf("\n");
            break;
        }


    } while (loopMenu == 0);

}

void excluirProdutos(produtos mercadorias[], int *posicao)
{
    int indice;
    char charAuxiliar[20];
    int verificarPosicao;

    do
    {
        printf("\n");
        printf("Digite o indice do produto que deseja excluir[0-4]: ");
        scanf("%d", &indice);

        if (indice < 0 || indice > 4)
        {
            printf("\nOpcao invalida, tente novamente.");
            printf("\n");
        }
        
    } while (indice < 0 || indice > 4);

    if (indice == 4)
    {
       for (int i = 0; mercadorias[indice].nome[i] != '\n'; i++)
       {
            mercadorias[indice].nome[i] = NULL;
       }

        mercadorias[indice].preco = 0;
        mercadorias[indice].quantidade = 0;
    }
    else
    {
        for (int i = indice; i < 4; i++)
        {
            for (int j = 0; mercadorias[indice].nome[j] != '\n'; j++)
           {
                mercadorias[indice].nome[j] = NULL;
                charAuxiliar[j] = mercadorias[indice+1].nome[j];
                mercadorias[indice+1].nome[j] = NULL;
           }

           strcpy(mercadorias[indice].nome, charAuxiliar);

           mercadorias[indice].preco = mercadorias[indice+1].preco;
           mercadorias[indice+1].preco = 0;

           mercadorias[indice].quantidade = mercadorias[indice+1].quantidade;
           mercadorias[indice+1].quantidade = 0;

        }

        /*O que fazer para saber qual posição a variável posicao deve retornar*/    
    
    }
    
}

void visualizarProdutos(produtos mercardorias[])
{
    int indice;

    do
    {
        printf("\n");
        printf("Digite o indice do produto que deseja ver[0-4]: ");
        scanf("%d", &indice);

        if (indice < 0 || indice > 4)
        {
            printf("\nOpcao invalida, tente novamente.");
            printf("\n");
        }
        
    } while (indice < 0 || indice > 4);

    printf("\n");
    printf("Nome: %s", mercardorias[indice].nome);
    printf("\n");
    printf("Preco: %.2f", mercardorias[indice].preco);
    printf("\n");
    printf("Quantidade: %d", mercardorias[indice].quantidade);
    printf("\n");


}

int main()
{   
    int opcao;
    int posicao = 0;
    produtos mercadorias[5];

    do
    {
        printf("\n");
        printf("Menu do Supermercado!\n");
        printf("1 - Adicionar produtos\n");
        printf("2 - Atualizar produtos\n");
        printf("3 - Excluir produtos\n");
        printf("4 - Ver produtos\n");
        printf("5 - Finalizar programa\n");
        printf("\n");
        printf("Digite: ");
        scanf("%d", &opcao);
        getchar(); /*Utilizamos o getchar() para que ele armazene o \n criado pelo scanf dentro do input, que pode causar problemas 
        ao utilizar a função fgets(), que irá receber \n como input e não irá parar o código para que o input seja lido*/

        switch (opcao)
       {
            case 1:
            if (posicao > 4)
            {
                printf("Numero maximo de produtos atingido.\n");
                printf("\n");
            }
            else
            {
                addProdutos(mercadorias, &posicao);
            }
            
            break;

            case 2:
            atualizarProdutos(mercadorias);
            break;

            case 3:
            excluirProdutos(mercadorias, &posicao);
            break;

            case 4:
            visualizarProdutos(mercadorias);
            break;

            case 5:
            printf("\n");
            printf("Finalizando programa.........\n");
            return 0;
            break;

    
            default:
            printf("\n");
            printf("Opcao invalida, tente novamente.\n");
            break;

        }

    } while (1);
    
}