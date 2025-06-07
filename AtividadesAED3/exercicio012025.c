// Exercício 01: árvore binária de busca

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node{
    int valor;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Arvore{
    Node *raiz;
} Arvore;

Node* criarNode(int valor){
    Node *ponto = (Node*)malloc(sizeof(Node));
    ponto->valor = valor;
    ponto->left = NULL;
    ponto->right = NULL;
    return ponto;
}

void inserirElemento(Arvore *arvore) {

    int valor;
    printf("Digite o valor a ser inserido na arvore: \n");
    scanf("%d", &valor);
    getchar();

    if (valor < 0 || !isdigit(valor)) {
        printf("\nValor invalido, digite novamente:\n");
        scanf("%d", &valor);
        getchar();
    }

    Node *novoNode = criarNode(valor);
    

    return;
}


int main() {

    int opcao, controleMenu;

    do
    {
        controleMenu = 0;
        
        printf("Bem-vindo ao sistema de arvore binaria.\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Listar elementos em ordem\n");
        printf("5 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            inserirElemento();
            system("cls");
            break;
        case 2:
            //buscarElemento();
            system("cls");
            break;
        case 3:
            //removerElemento();
            system("cls");
            break;
        case 4:
            //listarElementos();
            system("cls");
            break;
        case 5:
            printf("\nFinalizando o programa...\n");
            printf("Pressione qualquer tecla para sair.\n");
            getchar();
            controleMenu = 1;
            break;

        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }

    } while (controleMenu == 0);

    return 0;
}