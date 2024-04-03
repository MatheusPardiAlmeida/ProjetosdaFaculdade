#include <stdio.h>
#include <stdlib.h>

int alterarValor(int valor)
{
    valor = 7; /*Aqui mudamos o valor da variável dentro da função int e retornaremos ela para a função int main*/
    printf("\nValor da variavel dentro da funcao int: %d", valor);

    return valor;
}

void alterarValorRef(int *valor)
{
    *valor = 8; /*Mudamos o valor da variável através de ponteiro*/
    printf("\nValor da variavel dentro do procedimento: %d", *valor);
}

int main()
{
    int valor = 5;

    printf("\nValor da variavel no int main: %d", valor);

    alterarValorRef(&valor); /*Aqui passamos o valor da variável por referência (endereço de memória)*/

    printf("\nValor da variavel no int main depois do procedimento void: %d", valor);

    valor = alterarValor(valor); /*Aqui a variável valor receberá o retorno da função int*/

    printf("\nValor da variavel no int depois da funcao: %d", valor);

    /*Podemos ver que utilizar passagem de parâmetro por valor nos é útil quando desejamos alterar apenas um valor, agora
    caso tenhamos que alterar mais de 1 ou múltiplos valores, passagem por referência se torna bem mais eficiente e prático,
    eliminando a necessidade de criar várias funções int para retornar o valor da variável*/

    return 0;
}