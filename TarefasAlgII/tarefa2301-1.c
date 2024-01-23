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

void addProdutos(produtos *mercadorias[], int *posicao)
{
    mercadorias = malloc(sizeof(produtos) * (*posicao+1));
    
    printf("\n");
    printf("Digite o nome do produto: ");
    scanf("%20s", mercadorias[*posicao]->nome);

    do
    {
        printf("\n");
        printf("Digite o valor do produto: R$");
        scanf("%f", mercadorias[*posicao]->preco);

        if (mercadorias[*posicao]->preco < 0)
        {
           printf("\n");
           printf("Valor invalido, tente novamente.\n");
           printf("\n");
        }
        

    } while (mercadorias[*posicao]->preco < 0);

    do
    {
        printf("\n");
        printf("Digite a quantidade do produto: R$");
        scanf("%d", mercadorias[*posicao]->quantidade);

        if (mercadorias[*posicao]->quantidade < 0)
        {
           printf("\n");
           printf("Valor invalido, tente novamente.\n");
           printf("\n");
        }
        

    } while (mercadorias[*posicao]->quantidade <    0);

    (*posicao)++;

}


int main()
{   
    int opcao;
    int posicao = 0 ;
    produtos mercadorias[posicao];

    do
    {
        printf("\n");
        printf("Menu do Supermercado!\n");
        printf("1 - Adicionar produtos\n");
        printf("2 - Atualizar produtos\n");
        printf("3 - Excluir produtos\n");
        printf("4 - Finalizar programa\n");
        printf("\n");
        printf("Digite: ");
        scanf("%d", &opcao);

        switch (opcao)
       {
            case 1:
            addProdutos(&mercadorias, &posicao);
            break;

            case 2:
            //atualizarProdutos();
            break;

            case 3:
            //excluirProdutos();
            break;

            case 4:
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