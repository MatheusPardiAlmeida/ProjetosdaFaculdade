int lojaSub2(int *valorRetorno)
{
    int ctrlLoopConsumivel; /*Variável para controlar o loop do menu*/
    int escolha, continuar, quantidade; /*Variáveis para auxiliar na compra dos produtos*/
    int valorTotal = 0, valorSoma = 0; /*Variáveis para receber os valores das compras*/
    int valorProduto[9] = {200, 400, 250, 100, 150, 250, 250, 250, 200}; /*Array com o preço dos produtos*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {  
    ctrlLoopConsumivel = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha um desses itens consumiveis, Undead\n");
        printf("0 - Humanidade (200 Almas)\n");
        printf("1 - Humanidade Gemeas (400 Almas)\n");
        printf("2 - Bencao Divina (250 Almas)\n");
        printf("3 - Po de Reparo (100 Almas)\n");
        printf("4 - Osso de Retorno (150 Almas)\n");
        printf("5 - Resina de Carvao (250 Almas)\n");
        printf("6 - Resina de Veneno (250 Almas)\n");
        printf("7 - Resina de Ouro (250 Almas)\n");
        printf("8 - Flor Verde (2   00 Almas)\n");
        printf("9 - Retornar a loja\n");
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

        if (escolha == 9) /*Caso a pessoa deseje finalizar a compra, a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
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
            ctrlLoopConsumivel = 1;
            *valorRetorno = valorTotal;
        }
        
    } while (!validar);
    
 }while(ctrlLoopConsumivel == 0);

 return *valorRetorno;

}