#define buffer_tamanho 4096

int depositarSaldo(int depositoClientes)
{
    int deposito = 0;
    char string[buffer_tamanho];
    bool validar = true;

    do
    {
        printf("\n");
        printf("=====================================================\n");
        printf("Seu saldo atual e de: %d Almas\n", depositoClientes); /*Aqui irá mostrar o valor atual do saldo do cliente*/
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
            depositoClientes += deposito; /*O valor do saldo do cliente receberá o depósito */
            printf("\n%d", depositoClientes);
        }
            
    } while ((!validar) || (deposito <= 0));

    return depositoClientes; /*Irá retornar um novo valor, sendo esse o valor do saldo + o depósito*/

}