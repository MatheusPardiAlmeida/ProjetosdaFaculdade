#include <stdio.h>
#define DescValTotal 50000 /*Definimos esse valor para facilitar na hora do cálculo*/

int main()
{
    /*Aqui está todas as variáveis que utilizaremos para o controle do menu, cálculo dos descontos e os valores dos serviços*/
    int opcaoMenu, ctrlMenu, area;
    float valorTotal=0.0, descontoArea=0.0, descontoValorTotal=0.0, valorServico[4];

    valorServico[0] = 75.00;
    valorServico[1] = 98.00;
    valorServico[2] = 108.00;
    valorServico[3] = 202.00;

  do
  {
    ctrlMenu = 1;/*Caso o código passe sem erros, ele irá finalizar sem problemas, caso ocorra erros, no caso que pode dar erro
    iremos definir esse valor para 0, assim o loop será iniciado.*/

    printf("\n------------------------------------------------------");
    printf("\n");
    printf("\nBem-vindo cliente, escolha um de nossos servicos.");
    printf("\n1 - Lagartas");
    printf("\n2 - Gafanhotos");
    printf("\n3 - Ferrugem");
    printf("\n4 - Todos acima");
    printf("\nDigite o codigo: ");
    scanf("%d", &opcaoMenu);
    printf("\n");
    printf("\nDigite o tamanho de area: ");
    scanf("%d", &area);

    if (area < 0)/*Para verificar se o valor da área está correta*/
    {
        printf("\nArea invalida, faca novamente.");
        ctrlMenu = 0;
    }
    

    switch (opcaoMenu)
    {
        case 1:

        valorTotal = (valorServico[0]*area)*1.0;/*Primeiro faremos o cálculo do valor total do serviço*/

        if ((area >= 500) && (valorTotal >= DescValTotal))
        /*Colocaremos esse caso primeiro, já que caso ele não passe, irá para o próximo caso. Se for o contrário
        o primeiro caso a ser aceito será o executado, mesmo se o valor total passar de 50.000*/
        {
            descontoArea = valorTotal*0.05; 
            descontoValorTotal = (valorTotal - DescValTotal)*0.15; /*Aqui será feito todos os cálculos para o desconto e depois o valor total*/
            valorTotal = (valorTotal - descontoArea)-descontoValorTotal;
        }
        else if (area >= 500)
        {
            descontoArea = valorTotal*0.05;
            valorTotal = valorTotal - descontoArea;
        }
    
        printf("\n");
        printf("\nO valor total foi de R$%.2f", valorTotal);
        
        break;

        case 2:

        valorTotal = (valorServico[1]*area)*1.0;

        if ((area >= 500) && (valorTotal >= DescValTotal))
        {
            descontoArea = valorTotal*0.05;
            descontoValorTotal = (valorTotal - DescValTotal)*0.15;
            valorTotal = (valorTotal - descontoArea)-descontoValorTotal;
        }
        else if (area >= 500)
        {
            descontoArea = valorTotal*0.05;
            valorTotal = valorTotal - descontoArea;
        }
    
        printf("\n");
        printf("\nO valor total foi de R$%.2f", valorTotal);
        
        break;

        case 3:

        valorTotal = (valorServico[2]*area)*1.0;

        if ((area >= 500) && (valorTotal >= DescValTotal))
        {
            descontoArea = valorTotal*0.05;
            descontoValorTotal = (valorTotal - DescValTotal)*0.15;
            valorTotal = (valorTotal - descontoArea)-descontoValorTotal;
        }
        else if (area >= 500)
        {
            descontoArea = valorTotal*0.05;
            valorTotal = valorTotal - descontoArea;
        }
    
        printf("\n");
        printf("\nO valor total foi de R$%.2f", valorTotal);
        
        break;

        case 4:

        valorTotal = (valorServico[4]*area)*1.0;

        if ((area >= 500) && (valorTotal >= DescValTotal))
        {
            descontoArea = valorTotal*0.05;
            descontoValorTotal = (valorTotal - DescValTotal)*0.15;
            valorTotal = (valorTotal - descontoArea)-descontoValorTotal;
        }
        else if (area >= 500)
        {
            descontoArea = valorTotal*0.05;
            valorTotal = valorTotal - descontoArea;
        }
    
        printf("\n");
        printf("\nO valor total foi de R$%.2f", valorTotal);
        
        break;
    
        default:

        printf("\n");
        printf("\nCodigo invalido, faca novamente.");
        ctrlMenu = 0;

        break;
    }

  } while(ctrlMenu == 0);  

    return 0;
}