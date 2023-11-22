int lojaSub6(int *valorRetorno)
{
    int ctrlLoopMagias; /*Variável para controlar o loop do menu*/ 
    int escolha, continuar, quantidade; /*Variáveis para auxiliar na compra dos produtos*/ 
    int valorTotal = 0, valorSoma = 0; /*Variáveis para receber os valores das compras*/
    int valorProduto[18] = {1000, 2000, 10000, 20000, 20000, 30000, 3000, 4000, 3000, 4000, 2000, 2000, 5000, 2000, 30000, 40000, 20000, 50000}; 
    /*Array com o preço dos produtos*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {  
    ctrlLoopMagias = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha uma dessas magias, Undead\n");
        printf("0 - Flecha de Alma (1000 Almas)\n");
        printf("1 - Grande Flecha de Alma (2000 Almas)\n");
        printf("2 - Massa de Alma Teleguiado (10000 Almas)\n");
        printf("3 - Massa de Alma Cristalizada Teleguiado (20000 Almas)\n");
        printf("4 - Lanca de Alma (20000 Almas)\n");
        printf("5 - Lanca de Alma Cristalizada (30000 Almas)\n");
        printf("6 - Encantamento Magico (3000 Almas)\n");
        printf("7 - Encantamento Cristalizado (4000 Almas)\n");
        printf("8 - Escudo Magico (3000 Almas)\n");
        printf("9 - Forte Escudo Magico (4000 Almas)\n");
        printf("10 - Silencio (2000 Almas)\n");
        printf("11 - Controle de Queda (2000 Almas)\n");
        printf("12 - Reparo (5000 Almas)\n");
        printf("13 - Camaleao (2000 Almas)\n");
        printf("14 - Orbe Negro (30000 Almas)\n");
        printf("15 - Perola Negra (40000 Almas)\n");
        printf("16 - Nevoa Negra (20000 Almas)\n");
        printf("17 - Perseguidores (50000 Almas)\n");
        printf("18 - Retornar a loja\n");
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

        if (escolha == 18) /*Caso a pessoa deseje finalizar a compra, a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
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
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
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
            ctrlLoopMagias = 1;
            *valorRetorno = valorTotal;
        }
        
    } while (!validar);
    
 }while(ctrlLoopMagias == 0);

 return *valorRetorno;

}