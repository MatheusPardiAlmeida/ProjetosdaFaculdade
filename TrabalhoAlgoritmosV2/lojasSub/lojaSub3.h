int lojaSub3(int *valorRetorno)
{
    int ctrlLoopArmas; /*Variável para controlar o loop do menu*/
    int escolha, continuar, quantidade; /*Variáveis para auxiliar na compra dos produtos*/
    int valorTotal = 0, valorSoma = 0; /*Variáveis para receber os valores das compras*/
    int valorProduto[16] = {800, 1000, 1200, 2000, 4000, 2500, 2700, 1500, 1300, 1800, 1100, 1300, 900, 600, 500, 1800}; /*Array com o preço dos produtos*/
    char string[buffer_tamanho];
    bool validar = true;

 do
 {  
    ctrlLoopArmas = 0;

    do
    {
        printf("=====================================================\n");
        printf("Escolha uma dessas armas, Undead\n");
        printf("0 - Adaga (800 Almas)\n");
        printf("1 - Espada Larga (1000 Almas)\n");
        printf("2 - Espada Longa (1200 Almas)\n");
        printf("3 - Claymore (2000 Almas)\n");
        printf("4 - Espada de Artorias (4000 Almas)\n");
        printf("5 - Grande Espada (2500 Almas)\n");
        printf("6 - Zweihander (2700 Almas)\n");
        printf("7 - Uchigatana (1500 Almas)\n");
        printf("8 - Machado de Mao (1300 Almas)\n");
        printf("9 - Machado de Batalha (1800 Almas)\n");
        printf("10 - Lanca (1100 Almas)\n");
        printf("11 - Partizan (1300 Almas)\n");
        printf("12 - Foice (900 Almas)\n");
        printf("13 - Arco Longo (600 Almas)\n");
        printf("14 - Catalisador do Mago (500 Almas)\n");
        printf("15 - Catalisador de Izalith (1800 Almas)\n");
        printf("16 - Retornar a loja\n");
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

        if (escolha == 16) /*Caso a pessoa deseje finalizar a compra, a variável do valorSoma na função lojaFirelink irá receber o valor desta compra*/
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
            ctrlLoopArmas = 1;
            *valorRetorno = valorTotal;
        }
        
    } while (!validar);
    
 }while(ctrlLoopArmas == 0);

 return *valorRetorno;

}