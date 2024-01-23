/*Crie um sistema para gerenciar os funcionários de uma empresa. Cada funcionário tem um ID, nome, departamento e um registro de horas trabalhadas por mês.
Em seguida, implemente funções para adicionar e atualizar horas trabalhadas de um funcionário. Crie uma função para calcular o total de horas
trabalhadas no ano por um funcionário.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define tamFuncionarios 3
#define meses 12

typedef struct 
{
    char nome[30];
    char departamento[30];
    int horasPorMes[meses]; 
    char ID[4];  

}FUNCIONARIO;

FUNCIONARIO listaFuncionarios[tamFuncionarios];

bool validarID(char *verifyID)
{
    if ((strlen(verifyID) >= 4))
    {
        return false;
    }
    
    for (int o = 0; *verifyID != '\0'; o++)
    {
        if (!isdigit(*verifyID))
        {
            return false;
        }
        
    }

    return true;  

}

void horasAnuais()
{

    int totalHorasAno = 0;
    int verificar;
    int k;
    int a = 0;
    char verificarID[4];

    do
    {
        verificar = 0;

        printf("\n");
        printf("========================================================\n");
        printf("Digite o ID do funcionario que deseja verificar as horas.\n");
        printf("========================================================\n");
        printf("\n");
        printf("ID: ");
        fgets(verificarID, 4, stdin);
        fflush(stdin);

        for (k = 0; k < tamFuncionarios; k++)
        {
            if ((strcmp(verificarID, listaFuncionarios[k].ID)) == 0)
            {
                verificar = 1;
                continue;
            }
            else
            {
                printf("\n");
                printf("Funcionario nao encontrado, tente novamente.\n");
                printf("\n");
            }  
        }
        
    } while (verificar == 0);

    while (a < meses)
    {
        totalHorasAno += listaFuncionarios[k].horasPorMes[a];
        a++;
    }

    printf("\n");
    printf("\nO funcionario trabalhou por um total de: %d hrs no ano.", totalHorasAno);
    printf("\n");

}

void dadosFuncionario()
{
    int verificar;
    int k;
    char verificarID[4];

    do
    {
        verificar = 0;

        printf("\n");
        printf("========================================================\n");
        printf("Digite o ID do funcionario que deseja verificar os dados.\n");
        printf("========================================================\n");
        printf("\n");
        printf("ID: ");
        fgets(verificarID, 4, stdin);
        fflush(stdin);

        for (k = 0; k < tamFuncionarios; k++)
        {
            if ((strcmp(verificarID, listaFuncionarios[k].ID)) == 0)
            {
                verificar = 1;
                continue;
            }
            else
            {
                printf("\n");
                printf("Funcionario nao encontrado, tente novamente.\n");
                printf("\n");
            }  
        }
        
    } while (verificar == 0);


    printf("\nNome do funcionario: %s", listaFuncionarios[k].nome);
    printf("\nDepartamento do funcionario: %s", listaFuncionarios[k].departamento);
    printf("\nID do funcionario: %d", listaFuncionarios[k].ID);
    printf("\n");
    printf("\nHORAS DE TRABALHO DO FUNCIONARIO %s.\n", listaFuncionarios[k].nome);

    for (int i = 0; i < meses; i++)
    {
        printf("\nMes[%d]: %d hrs", i+1, listaFuncionarios[k].horasPorMes);
    }

    printf("\n");
    
}

void horasTrabalho()
{
    char verificarID[4];
    int verificar;
    int j;
    int mes;
    int loop;

    do
    {
        verificar = 0;

        printf("\n");
        printf("========================================================\n");
        printf("Digite o ID do funcionario que deseja atualizar as horas.\n");
        printf("========================================================\n");
        printf("\n");
        printf("ID: ");
        fgets(verificarID, 4, stdin);
        fflush(stdin);

        for (j = 0; j < tamFuncionarios; j++)
        {
            if ((strcmp(verificarID, listaFuncionarios[j].ID)) == 0)
            {
                verificar = 1;
                continue;
            }
            else
            {
                printf("\n");
                printf("Funcionario nao encontrado, tente novamente.\n");
                printf("\n");
            }  
        }
        
    } while (verificar == 0);
    
    do
    {
        loop = 0;

        printf("\n");
        printf("========================================================\n");
        printf("Digite o mes que deseja atualizar as horas de trabalho.\n");
        printf("========================================================\n");
        printf("\n");
        printf("Mes: ");
        scanf("%d", &mes);

        switch (mes)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:

            do
            {
                verificar = 0;

                printf("\n");
                printf("Digite as horas de trabalho do mes[%d]: ", mes);
                scanf("%d", &listaFuncionarios[j].horasPorMes[mes]);

                if (listaFuncionarios[j].horasPorMes[mes] < 0 || listaFuncionarios[j].horasPorMes[mes] > 200)
                {
                    printf("\n");
                    printf("Horas de trabalho invalida, tente novamente.\n");
                    printf("\n");
                }
                else
                {
                    verificar = 1;
                }
                
            } while (verificar == 0);

            printf("\n");
            printf("Deseja continuar? (1 = Sim, 0 = Nao): ");
            scanf("%d", &loop);

            if (loop != 0 || loop != 1)
            {
                printf("\n");
                printf("Valor invalido, tente novamente: ");
                scanf("%d", &loop);
            }         
            
            break;
        
            default:
            printf("\n");
            printf("Mes invalido, tente  novamente.");
            printf("\n");
            break;
        }

    } while (loop == 0);
    
}

int main()
{ 
    /*PRECISO FAZER UMA VERIFICAÇÃO PARA QUE TENHA EXATAMENTE 4 DÍGITOS NO ID DO FUNCIONÁRIO, SENDO SOMENTE NÚMEROS E EXATOS 4 DÍGITOS*/

    int opcao;
    char verifyID[4];
    bool validacaoID = true;

    printf("\n");
    printf("========================================================\n");
    printf("Preencha a lista de funcionarios cadastrados na empresa.\n");
    printf("========================================================\n");
    printf("\n");

    for (int i = 0; i < tamFuncionarios; i++)
    {
        printf("Dados do Funcionarios[%d]: \n", i+1);
        printf("\n");
        
        printf("Nome: ");
        fgets(listaFuncionarios[i].nome, 30, stdin);
        fflush(stdin);
        printf("\n");

        printf("Departamento: ");
        fgets(listaFuncionarios[i].departamento, 30, stdin);
        fflush(stdin);
        printf("\n");

        do
        {

            printf("ID: ");
            fgets(listaFuncionarios[i].ID, 4, stdin);
            fflush(stdin);
            printf("\n");

            /*DESCOBRIR COMO PASSAR O VALOR DA STRUCT PRA OUTRA VARIÁVEL E VERIFICAR SE TEM 4 DÍGITOS E SOMENTE NÚMEROS*/

            validacaoID = validarID(&listaFuncionarios[i].ID);

            if (!validacaoID)
            {
                printf("\n");
                printf("ID invalido, precisa ser 4 digitos e apenas numeros.\n");
                printf("\n");
            }        
            
        } while (!validacaoID);
    
    }

    printf("\n");
    printf("===================================================================\n");
    printf("Cadastro concluido com sucesso, continue para nosso menu de opcoes.\n");
    printf("===================================================================\n");
    printf("\n");

    do
    {
        printf("\nMenu de opçoes");
        printf("\n");
        printf("1 - Atualizar/Adicionar horas de trabalho.\n");
        printf("2 - Calcular horas de trabalho anual.\n");
        printf("3 - Mostrar dados dos funcionarios.\n");
        printf("4 - Encerrar programa.\n");
        printf("\n");
        printf("Opçao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            horasTrabalho();
            break;

            case 2:
            horasAnuais();
            break;

            case 3:
            dadosFuncionario();
            break;

            case 4:
            printf("\n");
            printf("Encerrando programa.....\n");
            printf("\n");
            return 0;
            break;
        
            default:
            printf("\n");
            printf("Opcao invalida, tente novamente.\n");
            printf("\n");
            break;
        }

    } while (1);

}