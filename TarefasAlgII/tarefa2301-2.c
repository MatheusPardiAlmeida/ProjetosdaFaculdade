#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
#define TAXA 5
#define BUFFER 25

typedef struct 
{

    char placa[BUFFER];
    char marca[BUFFER];
    char modelo[BUFFER];
    char cor[BUFFER];
    int horasEstacionadas;

} veiculos;

void visualizarVeiculos(veiculos estacionados[], int *posicao)
{
    for (int i = 0; i < *posicao; i++)
    {
        printf("\nPlaca: %s", estacionados[i].placa);
        printf("\nMarca: %s", estacionados[i].marca);
        printf("\nModelo: %s", estacionados[i].modelo);
        printf("\nCor: %s", estacionados[i].cor);
        printf("\n");
    }
    
}

void removeVeiculos(veiculos estacionados[], int *posicao)
{
    int indice;

    do
    {
        printf("\n");
        printf("Digite o indice do veiculo para remover: ");
        scanf("%d", &indice);

        if (indice < 0 || indice >= *posicao)
        {
            printf("\n");
            printf("Invalido, tente novamente.\n");
        }  

    } while (indice < 0 || indice >= *posicao);

    for (int i = indice; i < *posicao - 1; i++)
    {
        estacionados[i] = estacionados[i+1];
    }

    (*posicao)--;

    printf("\n");
    printf("Veiculo removido com sucesso!\n");

}

void atualizarHoras(veiculos *estacionados)
{
    do
    {
        printf("\n");
        printf("Digite quantas horas o veiculo se encontra estacionado: ");
        scanf("%d", &estacionados->horasEstacionadas);

        if (estacionados->horasEstacionadas <= 0)
        {
            printf("\n");
            printf("Invalido, tente novamente.\n");
        }
    
    } while (estacionados->horasEstacionadas <= 0);

    printf("\n");
    printf("\nA tarifa total do veiculo com placa %s", estacionados->placa);
    printf("\nO total ficou no valor de R$%d", (estacionados->horasEstacionadas*TAXA));
    printf("\n");

}

void horasEstacionadas(veiculos estacionados[], int *posicao)
{
    int indice;

    do
    {
        printf("\n");
        printf("Digite o indice do veiculo para atualizar as horas: ");
        scanf("%d", &indice);

        if (indice < 0 || indice >= *posicao)
        {
            printf("\n");
            printf("Invalido, tente novamente.\n");
        }  

    } while (indice < 0 || indice >= *posicao);

    atualizarHoras(&estacionados[indice]);
    
}

void preencherVagas(veiculos *estacionados)
{
    int continuar;

    getchar();/*Utilizamos o getchar() para que ele armazene o \n criado pelo scanf dentro do input, que pode causar problemas 
    ao utilizar a função fgets(), que irá receber \n como input e não irá parar o código para que o input seja lido*/

    /*A segurança para previnir o buffer overflow não está perfeita mas está funcionando, perguntar ao professor depois*/

    do
    {
        continuar = 0;

        printf("\n");
        printf("\nDigite a placa do carro: ");
        fgets(estacionados->placa, BUFFER, stdin);
        fflush(stdin); 

        for (int i = 0; i < BUFFER; i++)
        {
            if (estacionados->placa[i] == '\n') //Caso a string possua o caractere newline, o buffer não está cheio
            {
                continuar = 1;
                break;
            }
            else if (i == BUFFER) //Caso o valor de i, seja igual ao tamanho da string, o buffer está cheio
            {
                printf("\n");
                printf("\nBUFFER OVERFLOW!!");
            }
            
        }
        
    } while (continuar == 0);
    

    do
    {
        continuar = 0;

        printf("\n");
        printf("\nDigite a marca do carro: ");
        fgets(estacionados->marca, BUFFER, stdin);
        fflush(stdin);  

        for (int i = 0; i < BUFFER; i++)
        {
            if (estacionados->marca[i] == '\n') //Caso a string possua o caractere newline, o buffer não está cheio
            {
                continuar = 1;
                break;
            }
            else if (i == BUFFER) //Caso o valor de i, seja igual ao tamanho da string, o buffer está cheio
            {
                printf("\n");
                printf("\nBUFFER OVERFLOW!!");
            }
            
        }
        
    } while (continuar == 0);

    do
    {
        continuar = 0;

        printf("\n");
        printf("\nDigite o modelo do carro: ");
        fgets(estacionados->modelo, BUFFER, stdin);
        fflush(stdin);  

        for (int i = 0; i < BUFFER; i++)
        {
            if (estacionados->modelo[i] == '\n') //Caso a string possua o caractere newline, o buffer não está cheio
            {
                continuar = 1;
                break;
            }
            else if (i == BUFFER) //Caso o valor de i, seja igual ao tamanho da string, o buffer está cheio
            {
                printf("\n");
                printf("\nBUFFER OVERFLOW!!");
            }
            
        }
        
    } while (continuar == 0);

    do
    {
        continuar = 0;

        printf("\n");
        printf("\nDigite a cor do carro: ");
        fgets(estacionados->cor, BUFFER, stdin); 
        fflush(stdin); 

        for (int i = 0; i < BUFFER; i++)
        {
            if (estacionados->cor[i] == '\n') //Caso a string possua o caractere newline, o buffer não está cheio
            {
                continuar = 1;
                break;
            }
            else if (i == BUFFER) //Caso o valor de i, seja igual ao tamanho da string, o buffer está cheio
            {
                printf("\n");
                printf("\nBUFFER OVERFLOW!!");
            }
            
        }
        
    } while (continuar == 0);

}

void addVeiculos(veiculos estacionados[], int *posicao)
{
    if (*posicao < TAM)
    {
        preencherVagas(&estacionados[*posicao]);
        (*posicao)++;
    }
    else
    {
        printf("\n");
        printf("Estacionamento lotado!\n");
    }

}

int main()
{
    veiculos estacionados[TAM];
    int opcao;
    int posicao = 0;

    do
    {
        printf("\n");
        printf("Menu do Supermercado!\n");
        printf("1 - Adicionar veiculos\n");
        printf("2 - Horas estacionadas\n");
        printf("3 - Saida veiculos\n");
        printf("4 - Ver veiculos\n");
        printf("5 - Finalizar programa\n");
        printf("\n");
        printf("Digite: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            addVeiculos(estacionados, &posicao);
            break;

            case 2:
            horasEstacionadas(estacionados, &posicao);
            break;

            case 3:
            removeVeiculos(estacionados, &posicao);
            break;

            case 4:
            visualizarVeiculos(estacionados, &posicao);
            break;

            case 5:
            printf("\n");
            printf("\nPrograma finalizado........");
            return 0;
            break;
        
            default:
            printf("\n");
            printf("Opcao invalida, tente novamente.\n");
            break;
        }
        
    } while (1);
    
}