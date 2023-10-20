//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "constantes.h" //Chamamos as constantes para este header
extern double clientes[cMax]; //Estamos chamando o vetor da função principal para o header
extern int estoqueGlobal[eMax]; //Estamos chamando o vetor da função principal para o header

void menuCompras()
{
    //Todas as variáveis utilizadas no procedimento
    //A variável cod é utilizada para ler qual é o código do cliente no crediário
    //As variáveis codProd e opcaopagamento serão utilizadas para ler o código das opções disponibilizadas
    //As variáveis controlePagamento e ctrlCompra são declaradas fora do laço de repetição, e dentro do laço de repetição será dados os valores
    //para que o laço continue ou pare
    //A variável ctrlQuantidade é usada para que o valor inserido seja maior que 0 e menor que a quantidade no estoque do produto
    //A variável confirmar e ctrlConfirmar servem para fazer a verificação do laço de repetição do menu de compras

    int cod, codProd, quantidade, opcaopagamento, controlePagamento, ctrlCompra, ctrlQuantidade, ctrlCodMenu, confirmar, ctrlConfirmar;
    float valorTotal=0.0;
    //definir os valores de cada produto
    float valorProd[12] = {4.99, 10.99, 19.99, 3.99, 3.95, 6.99, 7.99, 8.99, 4.95, 5.95, 6.96, 2.99};
    
    do
    {
        //Aqui estamos fazendo um laço de repetição para que quando a pessoa digite um código inválido, ocorra a repetição do menu
        //Sem que a função vá até a confirmação da compra e ocorra um erro

        do
        {
           //Declaramos a variável fora do laço e sempre que o laço se repetir o valor dela voltará a ser 0
           ctrlCompra = 0;
                      
         printf("\n---------------------------------------------------------------");
         printf("\n");
         printf("\nBem vindo ao menu de compras.");
         printf("\n0 - Frasco de Estus.");
         printf("\n1 - Humanidade.");
         printf("\n2 - Bencao Divina.");
         printf("\n3 - Osso do Regresso.");
         printf("\n4 - Flor Verde.");
         printf("\n5 - Musgo Vermelho-Sangue.");
         printf("\n6 - Musgo Roxo.");
         printf("\n7 - Musgo Roxo Florescente.");
         printf("\n8 - Resina de Pinho Dourado.");
         printf("\n9 - Resina de Carvão.");
         printf("\n10 - Resina de Veneno.");
         printf("\n11 - Po de Reparo.");
         printf("\n");
         printf("\n---------------------------------------------------------------");
         printf("\nDigite o codigo do item: ");
         scanf("%d", &codProd);
    
      if (codProd >= 0 && codProd < eMax)
      {
        printf("\nDigite a quantidade que deseja levar: ");
        scanf("%d", &quantidade);

        do
        {
            ctrlQuantidade = 1;

            if (quantidade > estoqueGlobal[codProd] || quantidade < 0)
            {
                printf("\nQuantidade insuficiente! Digite uma quantia valida: ");
                scanf("%d",&quantidade);
            }
            else
            {
                ctrlQuantidade = 0;
            }
        
        } while (ctrlQuantidade == 1);

        if (quantidade >= 10)
        {
            estoqueGlobal[codProd] = estoqueGlobal[codProd] - quantidade;
            valorTotal = (valorTotal + (valorProd[codProd]*quantidade))*0.94;
            //Aqui estamos aplicando um desconto de 6% para uma quantia acima de 10
        }
        else
        {
            estoqueGlobal[codProd] = estoqueGlobal[codProd] - quantidade;
            valorTotal = valorTotal + (valorProd[codProd]*quantidade);
        } 
        
      }
      else
      {
        printf("\nOpcao invalida, tente novamente.");
        printf("\n");
        ctrlCompra = 1;
      }
    
       } while (ctrlCompra == 1);

    //Aqui faremos a verificação para saber se a pessoa deseja continuar ou não fazendo as compras    
    do
    {
       ctrlConfirmar = 0;
      
       printf("\n");
       printf("\nDeseja continuar as compras?");
       printf("\nDigite 0 para SIM ou 1 para NAO: ");
       scanf("%d", &confirmar); 

       if ((confirmar < 0) || (confirmar > 1))
       {

        printf("\nConfirmacao invalida, faca novamente.");
        printf("\n");

       }
       else
       {
           ctrlConfirmar = 1;
       }   
            
    } while (ctrlConfirmar == 0);
   //A função deste laço de repetição é para que os valores de confirmação sejam 0 ou 1 e não outro número qualquer fora desses valores para verificação 

    } while (confirmar == 0);
    //Aqui termina o laço de repetição do menu de compras

    //Aqui começaremos o menu da forma de pagamento
    
    do
    {
        //Mesmo caso do ctrlCompra, mudamos o valor para 0 sempre que o laço é repetido.
        controlePagamento = 1;

       printf("\n");
       printf("\nO valor total da compra foi de: R$%.2f", valorTotal);
       printf("\n");
       printf("\n");
       printf("\nBem-vindo a Firelink Share, escolha sua forma de pagamento. \n");
       printf("\n0 - Pix");
       printf("\n1 - Cartao Debito ou Credito");
       printf("\n2 - Dinheiro");
       printf("\n3 - Crediario\n");
       printf("\nForma do pagamento: ");
       scanf("%d", &opcaopagamento);
   
      switch (opcaopagamento)
      {
        case 0:

        valorTotal = ((valorTotal*0.95)*1.0);

        printf("\nVoce escolheu a opcao Pix e recebera um desconto de 5 por cento!");
        printf("\nO valor total da compra foi de: R$%.2f", valorTotal);

        break;

        case 1:

        printf("\nVoce escolheu a opcao Cartao.");
        printf("\nO valor total da compra foi de: R$%.2f", valorTotal);

        break;

        case 2:
        
        valorTotal = ((valorTotal*0.98)*1.0);

        printf("\nVoce escolheu a opcao Dinheiro e recebera um desconto de 2 por cento!");
        printf("\nO valor total da compra foi de: R$%.2f", valorTotal);

        break;

        case 3:

        printf("\nVoce escolheu a opcao Crediario");
        printf("\n"); 
        printf("\nO valor total da compra foi de: R$%.2f", valorTotal);
   
        do
        {
           //Aqui está sendo feito a verificação para saber o código inserido é válido
           ctrlCodMenu = 0;

           printf("\n");
           printf("\nDigite seu código: ");
           scanf("%d", &cod);
           
           //caso o código seja entre 0 e o valor máximo de clientes, irá passar.
           if ((cod >= 0) && (cod < cMax))
           {
               clientes[cod] = clientes[cod] + valorTotal;
        
              printf("\nCompra realizada com sucesso, seu novo débito é de: R$%.2lf ", clientes[cod]);
        
              ctrlCodMenu = 1;       
           }
        
           else
           {
              printf("\n");
              printf("Codigo invalido, tente novamente.");
           }

        } while (ctrlCodMenu == 0);

        break;
    
        default:

        printf("\nOpcao invalida, tente novamente.\n");
        controlePagamento = 0;

        break;
      }

    }while(controlePagamento == 0);

}