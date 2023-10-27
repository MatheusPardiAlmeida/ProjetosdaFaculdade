/*Uma rede atacadista de supermercados utiliza duas formas de conceder descontos
para seus clientes: quando a quantidade comprada é igual ou superior a X itens ou
quando o cliente faz o pagamento utilizando o cartão da própria rede atacadista. Caso
o cliente possua o cartão da própria rede atacadista, ele sempre paga o valor de
atacado, mesmo que ele compra apenas 1 item. Elabore um programa que simule a
operação de um caixa, de acordo com a tabela abaixo. Seu programa deve ser
finalizado quando o usuário teclar “-1” ao ler o */

#include <stdio.h>
#include <ctype.h>

int main()
{
    /*Nossa variável para verificar se a pessoa possui ou não cartão do mercado*/
    char verificarCartao; 
    /*Nossas variáveis de controle do sistema de compras do programa do mercado*/
    int codMenu, quantidade, pagamento, ctrlCompra, ctrlMenu, ctrlCartao, ctrlPagamento, ctrlSwitch, confirmarCompra;
    /*Nossa variável para armazenar o valor total da compra*/
    float valorTotal = 0;
    
    do /*Aqui temos o laço de repetição de todo o menu de compras, caso o operador deseja inserir mais um produto*/
    {

     do /*laço de repetição para que a pessoa digite o código certo no menu*/
     {
        ctrlSwitch = 1; 

        printf("\nBem-vindo ao Mercadinho Paulista!");
        printf("\nNosso menu: ");
        printf("\n1 - Sabonete (R$2.10)");
        printf("\n2 - Pao de Forma (R$8.39)");
        printf("\n3 - Espaguete (R$4.21)");
        printf("\n4 - Oleo de Soja (R$4.99)");
        printf("\n5 - Arroz 5KG (R$21.00)");
        printf("\n6 - Feijao 1KG (R$5.99)");
        printf("\n7 - Milho de Pipoca (R$2.15)");
        printf("\n-1 - Finalizar.");
        printf("\n");
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &codMenu);
      

        switch (codMenu)
        {
            case -1: /*Caso o operador deseja encerrar o programa, ele erá finalizado imediatamente*/

            printf("\nFinalizando programa........");
            return 0;

            break;

            case 1:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o cliente possui cartão ou não*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao);

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente.");
                    printf("\n");                    
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 3 || verificarCartao == 83)
            {
                valorTotal += (quantidade*1.95)*1.0; /*Valor com desconto de atacado*/
            }
            else
            {
                valorTotal += (quantidade*2.10)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;

            case 2:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: "); 
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o cliente possui cartão ou não*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao);

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente."); 
                    printf("\n");                  
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 2 || verificarCartao == 83)
            {
                valorTotal += (quantidade*8.20)*1.0; /*Valor com desconto de atacado*/
            }
            else
            {
                valorTotal += (quantidade*8.39)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;

            case 3:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o cliente possui cartão ou não*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao);

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente.");   
                    printf("\n");                 
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 4 || verificarCartao == 83)
            {
                valorTotal += (quantidade*3.99)*1.0; /*Valor com desconto de atacado*/
            }
            else
            {
                valorTotal += (quantidade*4.21)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;

            case 4:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o cliente possui cartão ou não*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao);

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente.");
                    printf("\n");                    
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 3 || verificarCartao == 83)
            {
                valorTotal += (quantidade*4.80)*1.0; /*Valor com desconto de atacado*/
            }
            else
            {
                valorTotal += (quantidade*4.99)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;

            case 5:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o cliente possui cartão ou não*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao);

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente.");    
                    printf("\n");                
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 2 || verificarCartao == 83)
            {
                valorTotal += (quantidade*19.85)*1.0; /*Valor com desconto de atacado*/
            } 
            else
            {
                valorTotal += (quantidade*21.00)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;
            
            case 6:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o cliente possui cartão ou não*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao);

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente."); 
                    printf("\n");                   
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 5  || verificarCartao == 83)
            {
                valorTotal += (quantidade*5.55)*1.0; /*Valor com desconto de atacado*/
            }
            else
            {
                valorTotal += (quantidade*5.99)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;

            case 7:

            do /*Faremos a verificação para saber se a quantia é um valor válido*/
            {
                printf("\nInsira a quantia do produto: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0)
                {
                    printf("\nQuantia invalida, tente novamente.");
                    printf("\n");
                }

            } while (quantidade <= 0);

            do /*Faremos a verificação para saber se o comprador possuí cartão do mercado*/
            {
                ctrlCartao = 0;

                printf("\nVoce possui cartao do mercado? (S/N): ");
                scanf("%s", &verificarCartao);

                verificarCartao = toupper(verificarCartao); /*Aqui iremos colocar a letra em maiúscula e verificar seu valor em ASCII*/

                if (verificarCartao == 83 || verificarCartao == 78)
                {
                    ctrlCartao = 1;
                }
                else
                {
                    printf("\nInvalido, tente novamente.");    
                    printf("\n");                
                }
                
            } while (ctrlCartao == 0);

            if (quantidade >= 7 || verificarCartao == 83)
            {
                valorTotal += (quantidade*1.99)*1.0; /*Valor com desconto de atacado*/
            }
            else
            {
                valorTotal += (quantidade*2.15)*1.0; /*Valor sem desconto de atacado*/
            }
            
            break;
        
            default:
            printf("\nCodigo invalido, tente novamente.");
            printf("\n");
            ctrlSwitch = 0; /*Utilizaremos essa variável para que o operador tenha que digitar um código válido antes de continuar o programa*/
            break;
        }

     }while(ctrlSwitch == 0);

            do /*Faremos a verificação para saber se é um valor válido*/
            {
                printf("\nDeseja continuar as compras?");
                printf("\n1 - Sim");
                printf("\n2 - Nao");
                printf("\nInsira: ");
                scanf("%d", &confirmarCompra);

                if (confirmarCompra < 1 || confirmarCompra > 2)
                {
                    printf("\nCodigo invalido, tente novamente");
                    printf("\n");
                }
                
            } while (confirmarCompra < 1 || confirmarCompra > 2);
            
            if (confirmarCompra == 2)
            {
                ctrlMenu = 1; /*Caso a pessoa deseja encerrar as compras, o ctrlMenu receberá 1*/

                do /*Faremos a verificação para saber se é um valor válido*/
                {
                    ctrlPagamento = 0;

                    printf("\nO valor total da compra foi de: R$%.2f", valorTotal);
                    printf("\n");
                    printf("\nComo deseja fazer o pagamento?");
                    printf("\n1 - Dinheiro");
                    printf("\n2 - Cartao Debito ou Credito");
                    printf("\n3 - Pix");
                    printf("\nInsira: ");
                    scanf("%d", &pagamento);
                    
                    if (pagamento >= 1 && pagamento <= 3)
                    {
                        ctrlPagamento = 1;
                        printf("\nObrigado pela preferencia, tenha um bom dia!");
                        printf("\n");
                        printf("\nFinalizando programa.........");
                    }
                    else
                    {
                        printf("\nCodigo invalido, tente novamente");
                    }
                
                } while (ctrlPagamento == 0);

            }
            else
            {
                ctrlMenu = 0; /*Caso a pessoa deseja continuar as compras, a variável será colocada em 0 novamente*/
            }
        
    } while (ctrlMenu == 0);
    
    return 0;
}