/*João implementou dois procedimentos em seu programa, um para verificar se um número é divisível por 3, outro para multiplicar o valor recebido por 10.
Ambos os procedimentos recebem um número inteiro com parâmetro e não retornam valores, apenas exibem o resultado na tela.
João deseja criar um vetor com ponteiros para esses procedimentos para, em seguida, passar o vetor como parâmetro para um procedimento especial. 
Este último procedimento acionará os procedimentos recebidos como parâmetro para um conjunto de números inteiros determinados localmente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void verificarDivisao(int vetor) /*Iremos passar o valor individual de cada posição do vetor*/
{

    if (vetor % 3 == 0)
    {
        printf("\n");
        printf("O numero %d e divisivel por 3.\n", vetor);
    }
    else
    {
        printf("\n");
        printf("O numero %d nao e divisivel por 3.\n", vetor);
    }   
}

void multiplicarNumero(int vetor) /*Iremos passar o valor individual de cada posição do vetor*/
{
    int produto = vetor*10;

    printf("\n");
    printf("O resultado da multiplicao do numero %d por 10 e: %d\n", vetor, produto);

}

void procedimentoEspecial(void (*procedimento1)(), void (*procedimento2)()) //Aqui iremos declarar os dois procedimentos acima
{
    int tamanhoVetor;
    int numero;
    srand(time(NULL));

    do
    {
        printf("\n");
        printf("Determine o tamanho do vetor: ");
        scanf("%d", &tamanhoVetor);

        if (tamanhoVetor <= 0)
        {
            printf("\n");
            printf("Maior que 0!!!!!!\n");
        }
        
    } while (tamanhoVetor <= 0);

    int *vetor = (int*)calloc(tamanhoVetor, sizeof(int)); /*Iremos utilziar o calloc para alocar um espaço de memória dinâmico no vetor
    sendo o espaço declarado pelo usuário durante a execução*/

    for (int i = 0; i < tamanhoVetor; i++)
    {
        vetor[i] = rand()%10; /*Iremos preencher o vetor com valores aleatórios de 0 a 10*/
    }

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\n");
        printf("Vetor na pos[%d]: %d\n", i, vetor[i]); /*Iremos imprimir os valores do vetor para a verificação*/
    }

    for (int j = 0; j < tamanhoVetor; j++)
    {
        verificarDivisao(*(vetor+j)); /*Aqui iremos passar individualmente cada valor do vetor para os procedimentos*/
        multiplicarNumero(*(vetor+j));
    }
    
    free(vetor); /*Iremos esvaziar o vetor*/
    vetor = NULL; /*Declarar o valor como um espaço NULL*/

}

int main()
{

    procedimentoEspecial(multiplicarNumero, verificarDivisao); //Passamos os dois procedimentos para o procedimento especial

    return 0;   
}