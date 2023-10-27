    /*Em uma cidade do interior de Mato Grosso foi realizada uma pesquisa com
    objetivo de coletar dados sobre as características físicas da população. Seu programa deve ler as seguintes características:
    Sexo (masculino e feminino)
    Cor dos olhos (azuis, verdes ou castanhos)
    Cor dos cabelos (louro, castanhos, ruivos ou pretos)
    Idade
    Seu programa deve retornar os seguintes resultados:
    A maior idade
    A média das idades
    A quantidade de indivíduos do sexo masculino cuja idade está entre 20 e 25
    anos e que tenham olhos castanhos e cabelos louros
    A quantidade de indivíduos do sexo feminino cuja idade está entre 34 e 41
    anos e que tenham olhos azuis e cabelos pretos
    Dica: determine um número ou caracter para identificar cada característica e utilize
    variáveis contadoras*/

#include <stdio.h>
 
float mediaIdade(float idades, int divisor) /*Criamos uma função float para calcular a média, inserindo a soma da idade e o divisor*/
{
    float media = 0;

    media = idades/divisor;

    return media; /*Aqui retornamos o valor da média para a função principal*/
}

int main()
{
    int sexo, olho, cabelo, opcao, i = 0;
    int numHomem = 0, numMulher = 0;
    float idade, somaIdade = 0, maiorIdade = 0;

    do /*Temos esse laço de repetição para controlar o loop de todo o menu*/
    {
        do /*Laço de repetição para verificar se o número inserido é valido*/
        {
        
           printf("\nSexo: ");
           printf("\n1 - Masculino");
           printf("\n2 - Feminino");
           printf("\nDigite: ");
           scanf("%d", &sexo);

           if (sexo < 1 || sexo > 2)
           {
               printf("\nInvalido, tente novamente.");
               printf("\n");
           }
        
        } while (sexo < 1 || sexo > 2);

        do /*Laço de repetição para verificar se o número inserido é valido*/
        {
           printf("\nCor dos Olhos: ");
           printf("\n1 - Azul");
           printf("\n2 - Verde");
           printf("\n3 - Castanho");
           printf("\nDigite: ");
           scanf("%d", &olho);

           if (olho < 1 || olho > 3)
           {
               printf("\nInvalido, tente novamente.");
               printf("\n");
           }
            
        } while (olho < 1 || olho > 3);

        do /*Laço de repetição para verificar se o número inserido é valido*/
        {
           printf("\nCor dos Cabelos: ");
           printf("\n1 - Loiro");
           printf("\n2 - Castanho");
           printf("\n3 - Ruivo");
           printf("\n4 - Preto");
           printf("\nDigite: ");
           scanf("%d", &cabelo);

           if (cabelo < 1 || cabelo > 4)
           {
               printf("\nInvalido, tente novamente.");
               printf("\n");
           }
            
        } while (cabelo < 1 || cabelo > 4);

        do /*Laço de repetição para verificar se o número inserido é valido*/
        {
            printf("\nIdade: ");
            scanf("%f", &idade);

            if (idade <= 0)
            {
                printf("\nInvalido, tente novamente.");
                printf("\n");
            }
            else
            {
                somaIdade += idade;
                i++;
            }
            
    
        } while (idade <= 0);

        if (idade > maiorIdade) /*Aqui faremos a verificação para saber qual é a maior idade*/
        {
            maiorIdade = idade;
        }

        if ((sexo == 1) && (idade >= 20 && idade <= 25) && (olho == 3) && (cabelo == 1)) /*Faremos a verificação para saber se atende aos requisitos pedidos pelo exercício*/
        {
            numHomem++;
        }
        
        if ((sexo == 2) && (idade >= 34 && idade <= 41) && (olho == 1) && (cabelo == 4)) /*Faremos a verificação para saber se atende aos requisitos pedidos pelo exercício*/
        {
            numMulher++;
        }

        /*Aqui faremos uma última verificação para saber se o operador irá continuar ou não a pesquisa*/
        printf("\nDeseja continuar a pesquisa?");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        printf("\nResposta: ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    printf("\n");
    printf("\nMaior idade: %.2f", maiorIdade);
    printf("\nMedia das idades: %.2f", mediaIdade(somaIdade, i)); /*Criamos uma função float para calcular a média, inserindo a soma da idade e o divisor*/
    printf("\nHomens entre 20 e 25 anos com olhos castanhos e cabelos loiro: %d", numHomem);
    printf("\nMulheres entre 34 e 41 anos com olhos azuis e cabelos preto: %d", numMulher);
    printf("\n");
    printf("\nFinalizando programa.....");

    return 0;
}