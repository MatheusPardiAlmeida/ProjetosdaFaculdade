#define Clientes 10

int sorteioAlmas(int *almasClientes, int i) /*A função irá receber o valor do saldo do cliente, e a posição no array*/
{

    printf("=====================================================\n");
    printf("Parabéns, o Undead (%d) ganhou o sorteio.\n", i);
    printf("Seu premio e de 10000 Almas.\n");
    printf("=====================================================\n");
    printf("\n");

    *almasClientes += 10000; /*Iremos dar 10000 almas para o cliente sorteado*/

    return *almasClientes;

}