//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "constantes.h" //Chamamos as constantes para este header
extern int clientes[cMax]; //Estamos chamando o vetor da função principal para o header

void consultaDebito()
{
    //Variável cod para a leitura do código de cliente e ctrlCodConsulta para o controle do laço de repetição
    int cod, ctrlCodConsulta;

    do
    {
        ctrlCodConsulta = 0;

        printf("\n"); 
        printf("\nDigite seu codigo: ");
        scanf("%d", &cod);

        if (cod >= 0 && cod < eMax)
        {
            ctrlCodConsulta = 1;
        }
        else
        {
            printf("\n---------------------------------------------------------------");
            printf("\nCodigo invalido, tente novamente.");
            printf("\n---------------------------------------------------------------");
        }

    } while (ctrlCodConsulta == 0);
    
    printf("\n");
    printf("\n---------------------------------------------------------------");
    printf("\nSeu debito e de: %d Almas", clientes[cod]);
    printf("\n---------------------------------------------------------------");
    printf("\n");

}