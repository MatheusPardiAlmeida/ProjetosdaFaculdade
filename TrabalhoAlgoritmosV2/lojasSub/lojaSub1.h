int lojaSub1(int *valorRetorno)
{
    int ctrlLoopMunicao; /*Variável para controlar o loop do menu*/
    int escolha, continuar, quantidade; /*Variáveis para auxiliar na compra dos produtos*/
    int valorTotal = 0, valorSoma = 0; /*Variáveis para receber os valores das compras*/
    int valorProduto[5] = {45,60,35,42,35}; /*Array com o preço dos produtos*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {  
    ctrlLoopMunicao = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha um desses itens de municao, Undead\n");
        printf("0 - Flecha Padrao (45 Almas)\n");
        printf("1 - Flecha Grande (60 Almas)\n");
        printf("2 - Flecha de Fogo (35 Almas)\n");
        printf("3 - Flecha Venenosa (42 Almas)\n");
        printf("4 - Flecha de Madeira (35 Almas)\n");
        printf("5 - Retornar a loja\n");
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

        if (escolha == 5) /*Caso a pessoa deseje finalizar a compra, a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
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
            ctrlLoopMunicao = 1;
            *valorRetorno = valorTotal;
        }
        
    } while (!validar);
    
 }while(ctrlLoopMunicao == 0);

 return *valorRetorno;

}