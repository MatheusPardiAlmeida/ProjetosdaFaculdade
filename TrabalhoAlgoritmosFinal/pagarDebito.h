//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "constantes.h" //Chamamos as constantes para este header
extern double clientes[cMax]; //Estamos chamando o vetor da função principal para o header

void pagarDebito()
{
    //Aqui faremos o pagamento do débito dos clientes
    //Variável cod será a leitura do código do cliente, ctrlValor e CtrlCodPagamento para o controle do laço de repetição
    int cod, ctrlValor, ctrlCodPagamento;
    double valorPagar;

    do
    {
        //Aqui faremos a repetição do código até que o operador digite um código válido
        ctrlCodPagamento = 0;

        printf("\n");
        printf("\nDigite seu codigo: ");
        scanf("%d", &cod);

        if (cod >= 0 && cod < eMax)
        {
            ctrlCodPagamento = 1;
        }
        else
        {
            printf("\n");
            printf("\nCodigo invalido, faca novamente.");
            printf("\n");
        }

    } while (ctrlCodPagamento == 0);

    if (clientes[cod] > 0)
    {
     do
     {
      //Aqui faremos a verificação do valor de pagamento
      //Sempre que o laço se repetir, ctrl voltará para 0
      ctrlValor = 0;

      printf("\n");
      printf("\nSeu debito e de: R$%.2lf", clientes[cod]);
      printf("\nDigite o valor que deseja pagar do seu debito: ");
      scanf("%lf", &valorPagar);
      printf("\n");

     if (valorPagar > clientes[cod] || valorPagar <= 0)
     {
        printf("\nValor invalido, tente novamente.");
     }
    
     else
     {
        clientes[cod] = clientes[cod] - valorPagar;

      printf("\n---------------------------------------------------------------");
      printf("\nSeu debito foi pago. O valor atual e de: R$%.2lf", clientes[cod]);
      printf("\n---------------------------------------------------------------");
      printf("\n");
      ctrlValor = 1;

     }
    
     } while (ctrlValor == 0);
    }
    else
    {
        printf("\nO cliente nao possui nenhum debito.");
        printf("\n");
    }
      
}