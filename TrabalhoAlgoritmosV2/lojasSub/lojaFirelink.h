#define Clientes 10
extern int saldoClientes[Clientes];

void lojaFirelink()
{
    int ctrlLoopLoja; /*Variável para controlar o loop*/
    int escolha; /*Variável para escolha do menu*/
    int codigo; /*Variável para código do cliente*/
    int valorCliente; /*Variável auxiliar para receber o saldo do cliente e enviar para a função*/
    int valorTotal = 0, valorSoma; /*Valores auxiliares para as compras*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {
    valorSoma = 0;
    ctrlLoopLoja = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha uma das categorias de itens, Undead\n");
        printf("1 - Municao\n");
        printf("2 - Consumivel\n");
        printf("3 - Armas\n");
        printf("4 - Escudos\n");
        printf("5 - Armaduras\n");
        printf("6 - Magias\n");
        printf("7 - Aneis\n");
        printf("8 - Finalizar Compra\n");
        printf("9 - Retornar ao Menu Principal\n");
        printf("=====================================================\n");
        printf("\n");
        printf("Sua escolha: ");
        fgets(string, buffer_tamanho, stdin);
        printf("\n");

        validar = validar_integer(string, &escolha); /*Aqui iremos fazer a verificação para saber se o que o usuário digitou é realmente um integer*/
        
        if (!validar) /*Utilizamos o ! para indicar um operador de NOT, ou seja, caso não seja o sinal da variável validar não seja TRUE, caíra nesse if*/
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Entrada invalida, faca novamente.\n");
            printf("=====================================================\n");
            printf("\n");
        }

    } while (!validar); /*Caso a variável validar seja diferente de TRUE, o laço irá se repetir*/

    switch (escolha)
    {
        case 1:
        valorTotal += lojaSub1(&valorSoma); /*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 2:
        valorTotal += lojaSub2(&valorSoma);/*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 3:
        valorTotal += lojaSub3(&valorSoma);/*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 4:
        valorTotal += lojaSub4(&valorSoma);/*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 5:
        valorTotal += lojaSub5(&valorSoma);/*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 6:
        valorTotal += lojaSub6(&valorSoma);/*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 7:
        valorTotal += lojaSub7(&valorSoma); /*Iremos chamar a função, que irá receber o endereço do valor de soma e irá nos retornar o valor da soma
        , que será somado ao valor total*/
        break;

        case 8:

        if (valorTotal == 0)
        {
            printf("=====================================================\n");
            printf("Voce nao fez nenhuma compra, tente novamente.\n");
            printf("=====================================================\n");
            printf("\n");
        }
        else
        {

          do
          {
            printf("\n");
            printf("=====================================================\n");
            printf("Antes de finalizar sua compra, por favor, nos diga seu codigo de cliente\n");
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
            
          } while ((!validar) || (codigo < 0 || codigo > (Clientes - 1)));

          valorCliente = saldoClientes[codigo]; /*A variável auxiliar recebe o valor do array na posição código*/

          saldoClientes[codigo] = confirmarCompraLoja(&valorTotal, valorCliente); /*A função irá receber o endereço da variável valorTotal
          e o valor da variável auxiliar*/

        }

        break;

        case 9:
        ctrlLoopLoja = 1; /*Para retornar ao MenuMain*/
        break;
    
        default:
        printf("\n");
        printf("Codigo invalido , faca novamente.\n");
        printf("\n");
        break;
    }

 }while(ctrlLoopLoja == 0);

}