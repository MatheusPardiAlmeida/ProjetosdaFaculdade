//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "constantes.h" //Chamamos as constantes para este header
extern int estoqueGlobal[eMax]; //Estamos chamando o vetor da função principal para o header

void estoqueProdutos()
{
//aqui teremos que preencher o estoque dos produtos através do procedimento

int codEstoque, ctrlEstoque, quantidadeEstoque;

//utilizando o do e while dessa forma, inpedimos o operador de colocar valores negativos
//fazendo com que sempre que um valor negativo seja inserido, será pedido que a pessoa insira
//um valor válido até que seja finalizado a lista de estoque

  do
   {
      ctrlEstoque = 0;
      printf("\nInsira o produto que deseja repor(0-11): ");
      scanf("%d", &codEstoque);

      if (codEstoque >= 0 && codEstoque < eMax) //Caso o código seja válido, irá passar
      {
        do //Aqui faremos a verificação para saber se é um valor válido a ser digitado
        {
            printf("\n");
            printf("Digite a quantidade que deseja repor para o produto (%d): ", codEstoque);
            scanf("%d", &quantidadeEstoque);

            if (quantidadeEstoque >= 0)
            {
             estoqueGlobal[codEstoque] += quantidadeEstoque;
            }
            else
            {
             printf("\n---------------------------------------------------------------");
             printf("\nQuantidade invalida, tente novamente.");
             printf("\n---------------------------------------------------------------");
             printf("\n");
            }

        } while (quantidadeEstoque < 0);

      }
      else //Enquanto não for digitado corretamente o código, o laço será repetido
      {
        printf("\n---------------------------------------------------------------");
        printf("\nCodigo invalido, tente novamente.");
        printf("\n---------------------------------------------------------------");
        printf("\n");
        ctrlEstoque = 1;

      }

    }while(ctrlEstoque == 1);

}