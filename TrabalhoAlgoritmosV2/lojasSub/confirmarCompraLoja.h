int confirmarCompraLoja(int *valorTotal, int contaCliente)
{
    int ctrlLoopCompra; /*Variável para controlar o loop*/
    int escolha; /*Variável para receber a escolha do menu*/
    int saldoCliente = contaCliente; /*Outra variável auxiliar para receber o valor do saldo do cliente*/
    int deposito; /*Variável para receber o valor do depósito para a conta do cliente*/
    char string[buffer_tamanho];
    bool validar = true;

    do
    {
        ctrlLoopCompra = 0;
        deposito = 0;

        do
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Entregue suas almas para a Firekeeper, Undead.\n");
            printf("O total da sua compra foi de: %d Almas\n", *valorTotal); /*Aqui irá mostrar o valor total da compra*/
            printf("E seu saldo atual e de: %d Almas\n", saldoCliente); /*Aqui irá mostrar o saldo do cliente*/
            printf("=====================================================\n");
            printf("\n");
            printf("=====================================================\n");
            printf("1 - Finalizar compra.\n");
            printf("2 - Cancelar compra.\n");
            printf("3 - Depositar Almas.\n");
            printf("=====================================================\n");
            printf("\n");
            printf("Sua escolha: ");
            fgets(string, buffer_tamanho, stdin);

            validar = validar_integer(string, &escolha);

            if (!validar)
            {
                printf("\n");
                printf("=====================================================\n");
                printf("Entrada invalida, tente novamente\n");
                printf("=====================================================\n");
                printf("\n");
            }
              
        } while ((!validar));
         
        switch (escolha)
        {
            case 1: /*Verificação para saber se a pessoa tem saldo ou não para fazer a compra*/

            if (saldoCliente < *valorTotal) 
            {
                printf("\n");
                printf("=====================================================\n");
                printf("Saldo insuficiente, deposite para finalizar a compra\n");
                printf("Ou cancele a compra caso nao tenha saldo suficiente.\n");
                printf("=====================================================\n");
                printf("\n");

                break;
            }
            else /*Caso a pessoa tenha saldo, irá finalizar normalmente*/
            {
                saldoCliente = saldoCliente - *valorTotal;
                *valorTotal = 0;
                contaCliente = saldoCliente;

                printf("\n");
                printf("=====================================================\n");
                printf("Obrigado pela compra Undead. Seu novo saldo e de: %d Almas\n", contaCliente);
                printf("=====================================================\n");
                printf("\n");
                ctrlLoopCompra = 1;
                return contaCliente; /*O saldo do cliente será atualizado e receberá o valor final da compra*/
            }
            
            break;

            case 2: /*Caso a compra seja cancelada, o valor da compra será zerado e o saldo do cliente continuará o mesmo*/

            *valorTotal = 0;
            printf("\n");
            printf("=====================================================\n");
            printf("Compra cancelada.\n");
            printf("=====================================================\n");
            printf("\n");
            ctrlLoopCompra = 1;
            return contaCliente;

            break;

            case 3: /*Caso o cliente deseja depositar almas, aparecerá esse menu para que ele possa continuar a compra*/
            /*Eu poderia ter utilizado a função, mas fiz ela depois e acabou ficando complicado de adaptar ela*/

            do
            {
                printf("\n");
                printf("=====================================================\n");
                printf("O total da sua compra foi de: %d Almas\n", *valorTotal);
                printf("Seu saldo atual e de: %d Almas\n", saldoCliente);
                printf("Deposite um valor para finalizar a compra.\n");
                printf("=====================================================\n");
                printf("\n");
                printf("Seu deposito: ");
                fgets(string, buffer_tamanho, stdin);

                validar = validar_integer(string, &deposito);

                if (!validar)
                {
                    printf("\n");
                    printf("=====================================================\n");
                    printf("Entrada invalida, tente novamente\n");
                    printf("=====================================================\n");
                    printf("\n");
                }
                else if (deposito <= 0) 
                {
                    printf("\n");
                    printf("=====================================================\n");
                    printf("Valor invalido, tente novamente\n");
                    printf("=====================================================\n");
                    printf("\n");
                }
                else
                {
                    saldoCliente += deposito;
                }
              
            } while ((!validar) || (deposito <= 0));

            break; 
        
            default:

            printf("\n");
            printf("=====================================================\n");
            printf("Codigo invalido, tente novamente\n");
            printf("=====================================================\n");
            printf("\n");
            
            break;
        }

    } while (ctrlLoopCompra == 0);

}