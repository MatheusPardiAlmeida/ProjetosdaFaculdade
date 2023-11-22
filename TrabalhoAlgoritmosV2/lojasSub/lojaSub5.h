int lojaSub5(int *valorRetorno)
{
    int ctrlLoopArmaduras; /*Variável para controlar o loop do menu*/ 
    int escolha, continuar, quantidade; /*Variáveis para auxiliar na compra dos produtos*/
    int valorTotal = 0, valorSoma = 0; /*Variáveis para receber os valores das compras*/
    int valorProduto[12] = {5000, 14000, 3000, 7000, 8000, 18000, 6000, 10000, 3000, 10000, 2000, 5000}; /*Array com o preço dos produtos*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {  
    ctrlLoopArmaduras = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha uma dessas armaduras, Undead\n");
        printf("0 - Capacete de Cavaleiro de Elite (5000 Almas)\n");
        printf("1 - Peitoral de Cavaleiro de Elite (14000 Almas)\n");
        printf("2 - Manoplas de Cavaleiro de Elite (3000 Almas)\n");
        printf("3 - Perneiras de Cavaleiro de Elite (7000 Almas)\n");
        printf("4 - Capacete de Catarina (8000 Almas)\n");
        printf("5 - Peitoral de Catarina (18000 Almas)\n");
        printf("6 - Manoplas de Catarina (6000 Almas)\n");
        printf("7 - Perneiras de Catarina (10000 Almas)\n");
        printf("8 - Capacete de Andarilho (3000 Almas)\n");
        printf("9 - Peitoral de Andarilho (10000 Almas)\n");
        printf("10 - Manoplas de Andarilho (2000 Almas)\n");
        printf("11 - Perneiras de Andarilho (5000 Almas)\n");
        printf("12 - Retornar a loja\n");
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

        if (escolha == 12) /*Caso a pessoa deseje finalizar a compra, a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
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
            ctrlLoopArmaduras = 1;
            *valorRetorno = valorTotal;
        }
        
    } while (!validar);
    
 }while(ctrlLoopArmaduras == 0);

 return *valorRetorno;

}