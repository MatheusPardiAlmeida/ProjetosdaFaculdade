/*Elabore um programa em C para gerenciar o registro de veículos de uma concessionária. 
Use uma struct chamada Veiculo contendo variáveis para modelo, marca, ano de fabricação, cor e preço.
Guarde vários registros de veículos em um vetor dessa struct. Implemente funções para salvar os registros em um arquivo e carregá-los quando o programa for iniciado. 
Desenvolva uma interface de usuário simples para adicionar novos veículos, exibir todos os registros e atualizar os dados salvos.*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct 
{
    char modelo[20];
    char marca[20];
    char cor[20];
    int anoFabri;
    float preco;

}VEICULO;

void inserirDados(VEICULO *vetor, int *pos)
{
    FILE *arquivo;

    if (*pos == 0)
    {
        arquivo = fopen("registroveiculos.txt", "w");
    }
    else
    {
        arquivo = fopen("registroveiculos.txt", "a");
    }
    
    if (!arquivo)
    {
        printf("\n");
        printf("\nO arquivo nao foi aberto!");
        return 0;
    }
    
    printf("\n");
    printf("\nDigite o modelo do carro: ");
    fgets(vetor->modelo, 20, stdin);
    
    printf("\n");
    printf("\nDigite a marca do carro: ");
    fgets(vetor->marca, 20, stdin);

    printf("\n");
    printf("\nDigite a cor do carro: ");
    fgets(vetor->cor, 20, stdin);

    printf("\n");
    printf("\nDigite o ano de fabricacao do carro: ");
    scanf("%d", &vetor->anoFabri);

    printf("\n");
    printf("\nDigite o valor do carro: R$");
    scanf("%f", &vetor->preco);

    fprintf(arquivo, "Modelo: %s", vetor->modelo);
    fprintf(arquivo, "Marca: %s", vetor->marca);
    fprintf(arquivo, "Cor: %s", vetor->cor);
    fprintf(arquivo, "Ano de Fabricacao: %d", vetor->anoFabri);
    fprintf(arquivo, "Preco: %.2f\n", vetor->preco);

    fclose(arquivo);

}

void registrarVeiculo(VEICULO vetor[], int *pos)
{
    if (*pos > TAM)
    {
        printf("\n");
        printf("\nO vetor se encontra cheio!!!");
    }
    else
    {
        inserirDados(&vetor[*pos], &pos);
        (*pos)++;
    }

}

void imprimirRegistro(VEICULO vetor[])
{
    FILE *arquivo;
    arquivo = fopen("registroveiculo.txt", "r");

    if (!arquivo)
    {
        printf("\n");
        printf("\nO arquivo nao foi aberto!");
        return 0;
    }

    while (fgets)
    {
        /* code */
    }
    
    





}


int main()
{
    VEICULO vetor[TAM];
    int opcoes;
    int pos = 0;

    do
    {
        printf("\n");
        printf("\nBem-vindo!");
        printf("\n1 - Registrar veiculo");
        printf("\n2 - Imprimir registros");
        printf("\n3 - Atualizar registro");
        printf("\n4 - Sair do programa.");
        printf("\n");
        printf("\nDigite: ");
        scanf("%d", &opcoes);
        getchar();

        switch (opcoes)
        {
            case 1:
            registrarVeiculo(vetor, &pos);
            break;
            
            case 2:
            imprimirRegistro(vetor);
            break;

            case 3:
            
            break;

            case 4:
            printf("\n");
            printf("\nFinalizando programa........");
            return 0;
            break;
        
            default:
            printf("\n");
            printf("\nInvalido, tente novamente.");
            break;
        }

    } while (1);
       



}