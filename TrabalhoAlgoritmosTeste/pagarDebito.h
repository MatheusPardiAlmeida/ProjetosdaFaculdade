//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "validarInteiro.h"
#include "constantes.h" //Chamamos as constantes para este header
extern int clientes[cMax]; //Estamos chamando o vetor da função principal para o header

void pagarDebito()
{
    //Aqui faremos o pagamento do débito dos clientes
    //Variável cod será a leitura do código do cliente, ctrlValor e CtrlCodPagamento para o controle do laço de repetição
    int cod = 0, ctrlValor, ctrlCodPagamento, valorPagar = 0;
    char entrada[buffer_tamanho];
    bool validacao;

   do
   {
        printf("\nDigite seu codigo: ");
        fgets(entrada, buffer_tamanho, stdin);
        fflush(stdin);

        validacao = validar_integer(entrada, &cod);

        if (validacao == false)
        {
            printf("\nEntrada invalida, tente novamente");
        }

    }while(validacao == false); 
    

    if (clientes[cod] > 0)
    {
     do
     {
      //Aqui faremos a verificação do valor de pagamento
      //Sempre que o laço se repetir, ctrl voltará para 0
      ctrlValor = 0;

      printf("\n");
      printf("\nSeu debito e de: %d Almas", clientes[cod]);
      printf("\nDigite o valor que deseja pagar do seu debito: ");
      scanf("%d", &valorPagar);
      printf("\n");

     if (valorPagar > clientes[cod] || valorPagar <= 0)
     {
        printf("\n---------------------------------------------------------------");
        printf("\n");
        printf("\nValor invalido, tente novamente.");
        printf("\n");
        printf("\n---------------------------------------------------------------");
     }
    
     else
     {
        clientes[cod] = clientes[cod] - valorPagar;

      printf("\n---------------------------------------------------------------");
      printf("\n");
      printf("\nSeu debito foi pago. O valor atual e de: %d Almas", clientes[cod]);
      printf("\n");
      printf("\n---------------------------------------------------------------");
      ctrlValor = 1;

     }
    
     } while (ctrlValor == 0);
    }
    else
    {
        printf("\n---------------------------------------------------------------");
        printf("\n");
        printf("\nO Undead nao possui nenhum debito.");
        printf("\n");
        printf("\n---------------------------------------------------------------");
    }
      
}