/*Uma estudante de Algoritmos e Estrutura de Dados II deseja implementar com conjunto de funções/procedimentos para facilitar a criação
de vetores alocados dinamicamente na memória, oferecendo recursos que possibilitem:

a) a criação de um novo vetor;
b) a inserção de valores no vetor, lidos do teclado;
c) a impressão do vetor;
d) a mudança da capacidade de armazenamento do vetor, para mais ou para menos;
e) a liberação do espaço de memória ocupado pelo vetor;*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criacaoVetor(int (*procedimento1)(), void (*procedimento2)(), void (*procedimento3)(), void (*procedimento4)()) 
{ /*Aqui criamos a chamada dos procedimentos dentro do procedimento*/

    int tamanhoVetor; /*Criamos uma variável para determinar o tamanho do vetor*/

    do
    {
        printf("\n");
        printf("Diga o tamanho do vetor (maior que 1!!!!!): ");
        scanf("%d", &tamanhoVetor);

        if (tamanhoVetor <= 1)
        {
            printf("\n");
            printf("Digite um valor maior que 1!!!!!!!!!");
        }
        
    } while (tamanhoVetor <= 1);
    
    int *vetor = (int*) calloc(tamanhoVetor, sizeof(int)); /*Aqui iremos criar o vetor e utilizar a função calloc para determinar o endereço e tamanho ocupado pelo vetor*/

    procedimento1(vetor, tamanhoVetor); /*Agora iremos passar essas duas variáveis para os outros procedimentos*/
    procedimento2(vetor, tamanhoVetor);
    procedimento3(vetor, &tamanhoVetor);
    procedimento2(vetor, tamanhoVetor);
    procedimento1(vetor, tamanhoVetor);
    procedimento2(vetor, tamanhoVetor);
    procedimento4(vetor);

}

int preencherVetor(int *vetor, int tamanhoVetor)
{ /*Nessa função iremos preencher o vetor criado anteriormente e iremos retornar o mesmo para o procedimento principal*/
    printf("\n");
    printf("Vamos preencher o vetor.\n");

    for (int i = 0; i < tamanhoVetor; i++)
    {

        printf("\n");
        printf("Digite o valor do vetor na pos[%d]: ", i);
        scanf("%d", &vetor[i]);
    
    }

    return *vetor;
    
}

void imprimirVetor(int *vetor, int tamanhoVetor)
{ /*Iremos imprimir o vetor para mostrar o conteúdo do mesmo*/
    printf("\n");
    printf("Agora a impressão do vetor.");
    printf("\nVetor: ");

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("\t%d", *(vetor+i));
    }

    printf("\n");

}

void alterarVetor(int *vetor, int *tamanhoVetor)
{ /*Nessa função iremos alterar o tamanho do vetor, e caso seja necessário, mudar o endereço de memória do vetor*/
    int novoTamanho;
    
    do
    {
        printf("\n");
        printf("Agora vamos alterar o valor do vetor\n");
        printf("Digite um novo tamanho para o vetor: ");
        scanf("%d", &novoTamanho);

        if (novoTamanho <= 1)
        {
            printf("\n");
            printf("O tamanho deve ser maior que 1!!!!!!!\n");
        }
        
    } while (novoTamanho <= 1);

    *tamanhoVetor = novoTamanho;

    int *novoVetor = (int*) realloc(vetor, novoTamanho * sizeof(int));

    if (novoVetor != vetor)
    {
        printf("\n");
        printf("O endereco do vetor mudou de local\n");
    }
    else
    {
        printf("\n");
        printf("O endereco do vetor nao mudou de local\n");
    }

    if (novoVetor != NULL)
    {
        vetor = novoVetor;
    }
    
} 

void limparVetor(int *vetor)
{ /*Aqui iremos limpar o vetor para desocupar a memória no programa*/
    printf("\n");
    printf("Limpeza do vetor.");
    free(vetor);
    vetor = NULL;
}

int main()
{

    criacaoVetor(preencherVetor, imprimirVetor, alterarVetor, limparVetor); 
    /*Aqui iremos chamar o procedimento e passar todos os outros para o procedimento*/

    printf("\n");
    printf("Finalizando programa........");

    return 0;
}