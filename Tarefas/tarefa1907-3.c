#include <stdio.h>
#define Tam 6

int main()
{
    int cod, quantidade, ctrlMenu;
    float valorTotal = 0.0, valorProd[Tam];

    valorProd[0] = 21.7;
    valorProd[1] = 28.9;
    valorProd[2] = 18.2;
    valorProd[3] = 15.99;
    valorProd[4] = 6.0;
    valorProd[5] = 4.0;
    
       printf("\n------------------------------------------------------------");
       printf("\n");
       printf("\nBem-vindo a lanchonete Komilao.");
       printf("\nEscolha um dos nossos produtos.");
       printf("\n200 - Baguncinha (R$21.70)");
       printf("\n201 - Bagunca Caseiro (R$28.90)");
       printf("\n202 - X-Salada (R$18.20)");
       printf("\n203 - Bauru Simples (R$15.99)");
       printf("\n204 - Refri Lata (R$6.00)");
       printf("\n205 - Agua Mineral (R$4.00)");

   do
   {
       ctrlMenu = 1;

       printf("\nInsira o codigo: ");
       scanf("%d", &cod);

       switch (cod)
       {
           case 200:
           
           do
           {
              printf("\n");
              printf("\nDigite a quantidade que deseja levar: ");
              scanf("%d", &quantidade);

              if (quantidade < 0)
              {
                printf("\n");
                printf("\nCodigo invalido, tente novamente.");
              }

           } while(quantidade < 0);

           valorTotal = valorTotal + (valorProd[0]*quantidade);

           printf("\n");
           printf("\nO produto escolhido foi Baguncinha");
           printf("\nO valor total e de: R$%.2f", valorTotal);
        
           break;

           case 201:

           do
           {
              printf("\n");
              printf("\nDigite a quantidade que deseja levar: ");
              scanf("%d", &quantidade);

              if (quantidade < 0)
              {
                printf("\n");
                printf("\nCodigo invalido, tente novamente.");
              }

           } while(quantidade < 0);

           valorTotal = valorTotal + (valorProd[1]*quantidade);

           printf("\n");
           printf("\nO produto escolhido foi Bagunca Caseiro");
           printf("\nO valor total e de: R$%.2f", valorTotal);
        
           break;

           case 202:

           do
           {
              printf("\n");
              printf("\nDigite a quantidade que deseja levar: ");
              scanf("%d", &quantidade);

              if (quantidade < 0)
              {
                printf("\n");
                printf("\nCodigo invalido, tente novamente.");
              }

           } while(quantidade < 0);

           valorTotal = valorTotal + (valorProd[2]*quantidade);

           printf("\n");
           printf("\nO produto escolhido foi X-Salada");
           printf("\nO valor total e de: R$%.2f", valorTotal);
        
           break;

           case 203:

           do
           {
              printf("\n");
              printf("\nDigite a quantidade que deseja levar: ");
              scanf("%d", &quantidade);

              if (quantidade < 0)
              {
                printf("\n");
                printf("\nCodigo invalido, tente novamente.");
              }

           } while(quantidade < 0);

           valorTotal = valorTotal + (valorProd[3]*quantidade);

           printf("\n");
           printf("\nO produto escolhido foi Bauru");
           printf("\nO valor total e de: R$%.2f", valorTotal);
        
           break;

           case 204:

           do
           {
              printf("\n");
              printf("\nDigite a quantidade que deseja levar: ");
              scanf("%d", &quantidade);

              if (quantidade < 0)
              {
                printf("\n");
                printf("\nCodigo invalido, tente novamente.");
              }

           } while(quantidade < 0);

           valorTotal = valorTotal + (valorProd[4]*quantidade);

           printf("\n");
           printf("\nO produto escolhido foi Refri Lata");
           printf("\nO valor total e de: R$%.2f", valorTotal);
        
           break;

           case 205:

           do
           {
              printf("\n");
              printf("\nDigite a quantidade que deseja levar: ");
              scanf("%d", &quantidade);

              if (quantidade < 0)
              {
                printf("\n");
                printf("\nCodigo invalido, tente novamente.");
              }

           } while(quantidade < 0);

           valorTotal = valorTotal + (valorProd[5]*quantidade);

           printf("\n");
           printf("\nO produto escolhido foi Agua Mineral");
           printf("\nO valor total e de: R$%.2f", valorTotal);
        
           break;
       
           default:

           printf("\nCodigo invalido, insira novamente.");
           printf("\n");
           ctrlMenu = 0;
         
           break;
       }

   } while(ctrlMenu == 0);

    return 0;
}