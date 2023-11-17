int lojaSub7(int *valorRetorno)
{
    int ctrlLoopAneis; /*Variável para controlar o loop do menu*/ 
    int escolha, continuar, quantidade; /*Variáveis para auxiliar na compra dos produtos*/ 
    int valorTotal = 0, valorSoma = 0; /*Variáveis para receber os valores das compras*/
    int valorProduto[13] = {10000, 20000, 5000, 6000, 7000, 5000, 10000, 10000, 10000, 10000, 12000, 12000, 25000}; /*Array com o preço dos produtos*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {  
    ctrlLoopAneis = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha um desses aneis, Undead\n");
        printf("0 - Anel de Cloranthy (10000 Almas)\n");
        printf("1 - Anel de Havel (20000 Almas)\n");
        printf("2 - Anel de Sacrifício (5000 Almas)\n");
        printf("3 - Anel de Dragao-Berrante (6000 Almas)\n");
        printf("4 - Anel de Dragao-Persistente (7000 Almas)\n");
        printf("5 - Anel de Dragao-Dormente (5000 Almas)\n");
        printf("6 - Anel do Leao (10000 Almas)\n");
        printf("7 - Anel do Lobo (10000 Almas)\n");
        printf("8 - Anel da Aguia (10000 Almas)\n");
        printf("9 - Anel da Vespa (10000 Almas)\n");
        printf("10 - Anel Dourado da Serpente Ambiciosa (12000 Almas)\n");
        printf("11 - Anel Prateado da Serpente Ambiciosa (12000 Almas)\n");
        printf("12 - Anel de Favor e Protecao (25000 Almas)\n");
        printf("13 - Retornar a loja\n");
        printf("=====================================================\n");
        printf("\n");
        printf("Sua escolha: ");
        fgets(string, buffer_tamanho, stdin);
        printf("\n");

        validar = validar_integer(string, &escolha); /*Aqui iremos fazer a verificação para saber se o que o usuário digitou é realmente um integer*/
        
        if (!validar) /*Utilizamos o ! para indicar um operador de NOT, ou seja, caso não seja o sinal da variável validar não seja TRUE, caíra nesse if*/
        {
            printf("\n");
            printf("Entrada invalida, faca novamente.\n");
            printf("\n");
        }

        if (escolha == 13) /*Caso a pessoa deseje finalizar a compra, a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
        {
            *valorRetorno = valorTotal;
            return *valorRetorno;
        }
        

    } while (!validar); /*Caso a variável validar seja diferente de TRUE, o laço irá se repetir*/

    do
    {
        printf("=====================================================\n");
        printf("Digite a quantidade que deseja levar do produto.\n");
        printf("=====================================================\n");
        printf("\n");
        fflush(stdin);
        printf("Sua escolha: ");
        fgets(string, buffer_tamanho, stdin);
        printf("\n");

        validar = validar_integer(string, &quantidade); /*Aqui iremos fazer a verificação para saber se o que o usuário digitou é realmente um integer*/
        
        if (!validar) /*Utilizamos o ! para indicar um operador de NOT, ou seja, caso não seja o sinal da variável validar não seja TRUE, caíra nesse if*/
        {
            printf("\n");
            printf("Entrada invalida, faca novamente.\n");
            printf("\n");
        }
        else if (quantidade <= 0)
        {
            printf("\n");
            printf("Entrada invalida, faca novamente.\n");
            printf("\n");
        }

    } while (!validar || quantidade <= 0);
    

    switch (escolha)
    {
        case 0: /*Dessa forma, todos os casos irão ter a mesma instrução*/
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        valorSoma = quantidade*valorProduto[escolha];
        valorTotal += valorSoma;
        break;
    
        default:
        printf("\n");
        printf("Entrada invalida, faca novamente.\n");
        printf("\n");
        break;
    }

    do
    {
        printf("=====================================================\n");
        printf("Deseja continuar comprando?.\n");
        printf("Digite 1 para SIM, 0 para NAO.\n");
        printf("=====================================================\n");
        printf("\n");
        fflush(stdin);
        printf("Sua escolha: ");
        fgets(string, buffer_tamanho, stdin);
        printf("\n");

        validar = validar_integer(string, &continuar); /*Aqui iremos fazer a verificação para saber se o que o usuário digitou é realmente um integer*/
        
        if (!validar) /*Utilizamos o ! para indicar um operador de NOT, ou seja, caso não seja o sinal da variável validar não seja TRUE, caíra nesse if*/
        {
            printf("\n");
            printf("Entrada invalida, faca novamente.\n");
            printf("\n");
        }
        
        if (continuar == 0) /*Caso a pessoa deseje finalizar a compra, irá quebrar o loop e a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
        {
            ctrlLoopAneis = 1;
            *valorRetorno = valorTotal;
        }
        
    } while (!validar);
    
 }while(ctrlLoopAneis == 0);

 return *valorRetorno;

}