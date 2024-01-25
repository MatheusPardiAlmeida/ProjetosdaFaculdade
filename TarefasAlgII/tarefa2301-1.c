/*Crie um programa em C que utilize uma struct para armazenar informações sobre um produto em um sistema de inventário. 
A struct deve conter o nome do produto, preço e quantidade em estoque. 
O programa deve permitir ao usuário adicionar novos produtos ao sistema, atualizar a quantidade em estoque e o preço, 
listar todos os produtos com suas informações ou excluir um produto a partir do índice.
Além disso, implemente uma função para calcular o valor total em estoque de um produto, multiplicando o preço pela quantidade disponível.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 4 /*O tamanho do vetor*/

typedef struct 
{
    char nome[20];
    float preco;
    int quantidade;

}produtos;

void repreencherProdutos(produtos *mercadorias, int opcao) /*Criei uma função responsável por mudar individualmente cada parte da Struct
tirando a necessidade de reescrever ela totalmente*/
{
    char nomeAtualizado[20];

    switch (opcao)
    {
        case 1:
        getchar();
        printf("\n");
        printf("Digite o novo nome do produto: ");
        fgets(nomeAtualizado, 20, stdin);
       
        strcpy(mercadorias->nome, nomeAtualizado); /*Precisamos passar o novo nome como string para a struct através do strcpy*/

        break;

        case 2:

        do
        {
            printf("\n");
            printf("Preco do produto: R$");
            scanf("%f", &mercadorias->preco); /*Apenas sobreescrevemos os valores para o novo valor*/

            if (mercadorias->preco <= 0)
            {
                printf("\n");
                printf("Valor invalido, tente novamente.\n");
            }
        
        } while (mercadorias->preco <= 0);
        
        break;

        case 3:

        do
        {
            printf("\n");
            printf("Quantidade do produto: ");
            scanf("%d", &mercadorias->quantidade); /*Apenas sobreescrevemos os valores para o novo valor*/

            if (mercadorias->quantidade <= 0)
            {
                printf("Valor invalido, tente novamente.\n");
            }
        
        } while (mercadorias->quantidade <= 0);
        
        break;

    }

}

void preencherProdutos(produtos *mercadorias)
{
    getchar(); /*Utilizamos o getchar() para que ele armazene o \n criado pelo scanf dentro do input, que pode causar problemas 
    ao utilizar a função fgets(), que irá receber \n como input e não irá parar o código para que o input seja lido*/

    printf("Nome do produto: ");
    fgets(mercadorias->nome, 20, stdin);
    printf("\n");

    do
    {
        printf("\n");
        printf("Preco do produto: R$");
        scanf("%f", &mercadorias->preco);

        if (mercadorias->preco <= 0)
        {
            printf("\n");
            printf("Valor invalido, tente novamente.\n");
        }
        
    } while (mercadorias->preco <= 0);

    do
    {
        printf("\n");
        printf("Quantidade do produto: ");
        scanf("%d", &mercadorias->quantidade);

        if (mercadorias->quantidade <= 0)
        {
            printf("\n");
            printf("Valor invalido, tente novamente.\n");
           
        }
        
    } while (mercadorias->quantidade <= 0);

}

void addProdutos(produtos mercadorias[], int *posicao) /*Não utilizei a struct como ponteiro já que estava dando erro*/
{
    if (*posicao < TAM) /*Primeiro verificamos se a posição do vetor é menor que o tamanho do vetor*/
    {
        preencherProdutos(&mercadorias[*posicao]);
        (*posicao)++;
        
    }
    else
    {
        printf("Nao ha mais espaco para produtos!!!\n"); /*Caso contrário, o vetor está cheio*/
    }

}

void atualizarProdutos(produtos mercadorias[], int posicao)
{
    int loopMenu;
    int indice;
    int opcaoAtualizar;

    do
    {
        printf("\n");
        printf("Digite o indice do produto que deseja atualizar: ");
        scanf("%d", &indice); /*Indice sendo a posição do vetor*/

        if (indice >= posicao) /*Como a posição está sempre apontada para um vetor vazio que será preenchido futuramente, precisamos fazer
        a verificação para saber se o indice está sendo apontado para uma posição válida do vetor*/
        {
            printf("Indice invalido, tente novamente.\n");
            printf("\n");
        }
        

    } while (indice >= posicao);
    

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
        getchar();/*Utilizamos o getchar() para que ele armazene o \n criado pelo scanf dentro do input, que pode causar problemas 
        ao utilizar a função fgets(), que irá receber \n como input e não irá parar o código para que o input seja lido*/

        switch (opcaoAtualizar)
        {
            case 1:
            repreencherProdutos(&mercadorias[indice], opcaoAtualizar); /*Aqui teremos a função para escolher qual parte da struct irá reescrever*/
            break;

            case 2:
            repreencherProdutos(&mercadorias[indice], opcaoAtualizar);
        
            break;

            case 3:
            repreencherProdutos(&mercadorias[indice], opcaoAtualizar);
            
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

    do
    {
        printf("\n");
        printf("Digite o indice do produto que deseja excluir[0-%d]: ", TAM-1);
        scanf("%d", &indice);

        if (indice < 0 || indice >= *posicao) /*Mesma coisa da função "atualizarProdutos"*/
        {
            printf("\nValor invalido, tente novamente.");
            printf("\n");
        }
        
    } while (indice < 0 || indice >= *posicao);

    for (int i = indice ; i < *posicao - 1; i++) /*Sempre vamos limitar a variável i para que ela percorra até a última posição válida do vetor, já que
    a variável posição armazena a próxima posição que será preenchida, e não a última posição que foi escrita*/
    {
        mercadorias[i] = mercadorias[i+1]; /*Dessa forma passamos todas as informações da struct para outro sem precisar escolher 1 por 1*/
    }

    (*posicao)--; /*Iremos decrementar a posição em 1*/
    
}

void visualizarProdutos(produtos mercardorias[], int posicao)
{

    for (int i = 0; i < posicao; i++)
    {
        printf("\n");
        printf("\nNome: %s", mercardorias[i].nome);
        printf("\n");
        printf("\nPreco: %.2f", mercardorias[i].preco);
        printf("\n");
        printf("\nQuantidade: %d", mercardorias[i].quantidade);
        printf("\n");
    }

}

int main()
{   
    int opcao;
    int posicao = 0;
    produtos mercadorias[TAM];

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

        switch (opcao)
       {
            case 1:
            addProdutos(mercadorias, &posicao);
            break;

            case 2:
            atualizarProdutos(mercadorias, posicao);
            break;

            case 3:
            excluirProdutos(mercadorias, &posicao);
            break;

            case 4:
            visualizarProdutos(mercadorias, posicao);
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