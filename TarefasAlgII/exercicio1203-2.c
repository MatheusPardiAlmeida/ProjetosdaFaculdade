/*Considere um programa de cadastro (de produtos, clientes, veículos, etc) que contém, no mínimo, 10 registros alocados de forma estática na memória. 
Cada registro deve conter, no mínimo, três variáveis. O programa deve exibir um menu de opções ao usuário, com as seguintes funcionalidades:

Cadastrar um novo item

Listar por nome em ordem crescente

Listar por valor ou quantidade em ordem crescente

Listar por valor ou quantidade em ordem decrescente

Excluir um item */

#include<stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define TAM 10

typedef struct 
{
    char nomeProduto[20];
    int valorEstoque;
    float valorProduto;
    
}REGISTRO;

void listaProdutos(REGISTRO vetor[], int tam)
{
    printf("\n");
    printf("\nLista de todos os produtos: "); /*Iremos apenas mostrar os produtos e em qual posição está armazenado*/
    
    for (int i = 0; i < tam; i++)
    {
        printf("\n");
        printf("\nProduto na posicao[%d]", i);
        printf("\nNome produto: %s\t", vetor[i].nomeProduto);
        printf("Estoque produto: %d\t", vetor[i].valorEstoque);
        printf("Valor produto: %.2f\n", vetor[i].valorProduto);

    }

}

void excluirItem(REGISTRO vetor[], int *tam)
{
    int excluir;

    if (*tam == 0)
    {
        printf("\n");
        printf("\nNao tem nada para excluir!");
        return;
    }

    printf("\n");
    printf("\nLista dos itens disponiveis para exclusao: "); /*Aqui iremos mostrar todos os itens na ordem que estão armazenados na struct*/
    
    for (int i = 0; i < *tam; i++)
    {
        printf("\n");
        printf("\nProduto na posicao[%d]", i);
        printf("\nNome produto: %s", vetor[i].nomeProduto);
        printf("Estoque produto: %d", vetor[i].valorEstoque);
        printf("\nValor produto: %.2f", vetor[i].valorProduto);
    }

    do
    {
        printf("\n");
        printf("\nDigite a posicao que deseja excluir: ");
        scanf("%d", &excluir);

        if (excluir < 0 || excluir > *tam) /*Faremos a verificação para saber se o valor inserido está correto*/
        {
            printf("\n");
            printf("\nOpcao invalida, tente novamente.");
        }
        
    } while (excluir < 0 || excluir > *tam);

    for (int k = excluir; k < *tam - 1; k++)
    {
        vetor[k] = vetor[k+1];
    }
    

    printf("\n");
    printf("\nO item na posicao [%d] foi excluido com sucesso", excluir);
    (*tam)--; /*Assim iremos "excluir" o item e a posição será decrementada*/

}

void listarValor(REGISTRO vetor[], int tam)
{
    REGISTRO temp;

    for (int i = 0; i < tam - 1; i++)
    {
        bool trocou = false; /*Utilizamos o bool para interromper o bubbleSort caso ele não tenha mais nada para ordenar*/

        for (int j = 0; j < tam - i - 1; j++)
        {
            if (vetor[j].valorProduto < vetor[j+1].valorProduto) 
            {
                temp = vetor[j]; /*Para não ficar muito confuso, passaremos toda a struct para uma struct temporária a fim de preservar todos os elementos*/
                vetor[j] = vetor[j+1]; /*Passaremos a struct da próxima posição para a posição atual*/
                vetor[j+1] = temp; /*E a próxima posição irá receber a struct da posição atual*/

                trocou = true; /*Caso ocorra a troca, iremos declarar como true*/
            }
        }

        if (!trocou) /*Caso a bool seja false, irá interromper o bubbleSort*/
        {
            printf("\n");
            printf("\nAqui temos a lista do valor dos produtos em ordem decrescente: ");
            printf("\n");
    
            for (int l = 0; l < tam; l++)
            {
                printf("\nValor %s R$%.2f", vetor[l].nomeProduto, vetor[l].valorProduto);
            }

            break;
        }

    }

}

void listarEstoque(REGISTRO vetor[], int tam)
{
    REGISTRO temp;

    for (int i = 0; i < tam - 1; i++)
    {
        bool trocou = false; /*Utilizamos o bool para interromper o bubbleSort caso ele não tenha mais nada para ordenar*/

        for (int j = 0; j < tam - i - 1; j++)
        {
            if (vetor[j].valorEstoque > vetor[j+1].valorEstoque) 
            {
                temp = vetor[j]; /*Para não ficar muito confuso, passaremos toda a struct para uma struct temporária a fim de preservar todos os elementos*/
                vetor[j] = vetor[j+1]; /*Passaremos a struct da próxima posição para a posição atual*/
                vetor[j+1] = temp; /*E a próxima posição irá receber a struct da posição atual*/

                trocou = true; /*Caso ocorra a troca, iremos declarar como true*/
            }
        }

        if (!trocou) /*Caso a bool seja false, irá interromper o bubbleSort*/
        {
            printf("\n");
            printf("\nAqui temos a lista da quantidade dos produtos em ordem crescente: ");
            printf("\n");
    
            for (int l = 0; l < tam; l++)
            {
                printf("\nQuantidade %s %d", vetor[l].nomeProduto, vetor[l].valorEstoque);
            }

            break;
        }

    }

}

void listarNome(REGISTRO vetor[], int tam)
{
    REGISTRO temp;

    for (int i = 0; i < tam - 1; i++)
    {
        bool trocou = false; /*Utilizamos o bool para interromper o bubbleSort caso ele não tenha mais nada para ordenar*/

        for (int j = 0; j < tam - i - 1; j++)
        {
            if (strncmp(vetor[j].nomeProduto, vetor[j+1].nomeProduto, 10) > 0) /*Caso a primeira string seja maior que a segunda, iremos realizar a operação*/
            {
                temp = vetor[j]; /*Para não ficar muito confuso, passaremos toda a struct para uma struct temporária a fim de preservar todos os elementos*/
                vetor[j] = vetor[j+1]; /*Passaremos a struct da próxima posição para a posição atual*/
                vetor[j+1] = temp; /*E a próxima posição irá receber a struct da posição atual*/

                trocou = true; /*Caso ocorra a troca, iremos declarar como true*/
            }
        }

        if (!trocou) /*Caso a bool seja false, irá interromper o bubbleSort*/
        {
            printf("\n");
            printf("\nAqui temos a lista do nome dos produtos em ordem alfabetica: "); 
            printf("\n");
    
            for (int l = 0; l < tam; l++)
            {
                printf("\nProduto: %s", vetor[l].nomeProduto);
            }

            break;
        }

    }

}

void inserirItem(REGISTRO *vetor)
{
    int verificar; /*Utilizaremos essa variável para saber se os valores inseridos estão corretos*/

    printf("\n");
    printf("\nDigite o nome do produto: ");
    fgets(vetor->nomeProduto, 20, stdin);
    fflush(stdin);

    do
    {
        verificar = 1;

        printf("\n");
        printf("\nDigite o valor do estoque do produto: ");
        scanf("%d", &vetor->valorEstoque);
        getchar();
        
        if (vetor->valorEstoque <= 0)
        {
            verificar = 0;
            printf("\n");
            printf("\nValor invalido, tente novamente.");
        }
        
    } while (verificar == 0);

    do
    {
        verificar = 1;

        printf("\n");
        printf("\nDigite o valor do produto: R$");
        scanf("%f", &vetor->valorProduto);
        getchar();

        
        if (vetor->valorProduto <= 0)
        {
            verificar = 0;
            printf("\n");
            printf("\nValor invalido, tente novamente.");
        }
        
    } while (verificar == 0);

}

void cadastroItem(REGISTRO vetor[], int *pos)
{
    if (*pos >= TAM)
    {
        printf("\n");
        printf("\nA struct esta cheia!!!");
        return;
    }
    else
    {
        inserirItem(&vetor[*pos]);
        (*pos)++; /*Incrementamos o valor da posição atual*/
        
    }

}


int main()
{
    REGISTRO vetor[TAM];
    int pos = 0;

    int opcao;
    
    do
    {
        printf("\n");
        printf("\nBem-vindo ao supermercado FASOASODFOhui");
        printf("\nOpcoes do menu:");
        printf("\n1 - Cadastrar item");
        printf("\n2 - Listar item por nome"); /*Ordem crescente*/
        printf("\n3 - Listar estoque"); /*Ordem crescente*/
        printf("\n4 - Listar valor"); /*Ordem decrescente*/
        printf("\n5 - Excluir item");
        printf("\n6 - Lista de produtos");
        printf("\n7 - Sair do programa");
        printf("\n");
        printf("\nDIGITE: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
            cadastroItem(vetor, &pos);
            break;

            case 2:
            listarNome(vetor, pos);
            break;

            case 3:
            listarEstoque(vetor, pos);
            break;

            case 4:
            listarValor(vetor, pos);
            break;

            case 5:
            excluirItem(vetor, &pos);
            break;

            case 6:
            listaProdutos(vetor, pos);
            break;
            
            case 7:
            printf("\n");
            printf("\nFinalizando programa.......");
            return 0;
            break; 
        
            default:
            printf("\n");
            printf("\nOpcao invalida, tente novamente.");
            break;
        }

    } while (1);
    

}