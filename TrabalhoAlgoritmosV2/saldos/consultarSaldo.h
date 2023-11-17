#define Clientes 10
#define buffer_tamanho 4096
extern int saldoClientes[Clientes];

void consultarSaldo()
{
    int codigo; /*Variável para indicar a posição do array*/
    char string[buffer_tamanho];
    bool validar = true;

    do
    {
        printf("\n");
        printf("=====================================================\n");
        printf("Digite seu codigo para verificar seu saldo.\n");
        printf("=====================================================\n");
        printf("\n");
        printf("Seu codigo: ");
        fgets(string, buffer_tamanho, stdin);

        validar = validar_integer(string, &codigo);

        if (!validar)
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Entrada invalida, tente novamente\n");
            printf("=====================================================\n");
            printf("\n");
        }
        else if (codigo < 0 || codigo > (Clientes - 1))
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Codigo invalido, tente novamente\n");
            printf("=====================================================\n");
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Undead, seu saldo atual e de %d Almas.\n", saldoClientes[codigo]); /*Iremos mostrar o saldo do cliente*/
            printf("=====================================================\n");
            printf("\n");
        }
          
    } while ((!validar) || (codigo < 0 || codigo > (Clientes - 1)));
    
}