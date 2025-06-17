// Exercício 01: árvore binária de busca

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Node{
    int valor;
    struct Node *left;
    struct Node *right;
    struct Node *pai;
} Node;

Node* criarNode(int valor){
    Node *ponto = (Node*)malloc(sizeof(Node));
    ponto->valor = valor;
    ponto->left = NULL;
    ponto->right = NULL;
    ponto->pai = NULL;
    return ponto;
}

void inserirElemento(Node **raiz, Node **atual) {

    int escolha;
    int valor;

    printf("Digite o valor a ser inserido na arvore: ");
    scanf("%d", &valor);
    getchar();

    if (valor < 0 || isdigit(valor)) {
        printf("\nValor invalido, digite novamente: ");
        scanf("%d", &valor);
        getchar();
    }

    Node *ponto = criarNode(valor);

    if (*raiz == NULL){
        *raiz = ponto;
        *atual = ponto;
    }
    else{
        
        int i = 0;

        while (i == 0)
        {
            printf("\nO valor sera inserado em:\n");
            printf("1 - Esquerda\n");
            printf("2 - Direita\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);
            getchar();
        
            switch (escolha)
            {
                case 1:
                if ((*atual)->left == NULL){
                    ponto->pai = *atual;
                    (*atual)->left = ponto;
                    i = 1;
                }
                else{
                    printf("\nO elemento atual ja possui um valor a esquerda.\n");
                    printf("Retornando ao menu principal, pressione qualquer tecla para continuar...\n");
                    getchar();
                    i = 1;
                    break;
                }

                break;

                case 2:
                if ((*atual)->right == NULL){
                    ponto->pai = *atual;
                    (*atual)->right = ponto;
                    i = 1;
                }
                else{
                    printf("\nO elemento atual ja possui um valor a direita.\n");
                    printf("Retornando ao menu principal, pressione qualquer tecla para continuar...\n");
                    getchar();
                    i = 1;
                    break;
                }

                break;
        
                default:
                printf("\nOpcao invalida, digite novamente: ");
                scanf("%d", &escolha);
                getchar();
                break;
            }
        }
    }
    
    system("cls");
    return;
}

void elementoAtual(Node **atual){

    printf("sduiafhihousaiohuasihuodfsahuidsa\n");

    if (*atual == NULL){
        printf("\nO elemento atual se encontra vazio.\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
    }
    else{
        printf("\nO elemento atual:\n");
        printf("%d\n", (*atual)->valor);

            if (!((*atual)->left))
            {
                printf("\tEsquerda: #\n");
            }
            else{
                printf("\tEsquerda: %d\n", (*atual)->left->valor);
            }
            if (!((*atual)->right))
            {
                printf("\tDireita: #\n");
            }
            else{
                printf("\tDireita: %d\n", (*atual)->right->valor);
            }
    }

    system("cls");

}

void percorrerArvore(Node **atual, Node **raiz) {

    if (*atual == NULL) 
    {
        printf("\nA arvore esta vazia.\n");
        printf("Pressione qualquer tecla para continuar...");
        getchar();
        return;
    }

    int opcao;

    printf("\nPara onde deseja ir?");
    printf("\n1 - Esquerda\n");
    printf("2 - Direita\n");
    printf("3 - Raiz\n");
    printf("4 - Subir de nivel\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
        *atual = (*atual)->left;
        break;
    case 2:
        *atual = (*atual)->right;
        break;
    case 3:
        *atual = *raiz;
        break;
    case 4:
        if ((*atual)->pai == NULL){
            printf("\nA arvore ja esta no topo, pressione qualquer tecla para continuar.");
            getchar();
            return;
        }
        else{
            *atual = (*atual)->pai;
        }

        break;
        default:
        printf("\nOpcao invalida, tente novamente.");
        printf("\nDigite sua escolha: ");
        scanf("%d", &opcao);
        getchar();
        break;
    }
    
    system("cls");
    return;
}

void excluirNodo(Node ***p){
    if(p != NULL){
        if((**p)->left != NULL)
            excluirNodo(&((**p)->left));
        if((**p)->right != NULL)
            excluirNodo(&((**p)->right));
        free(*p);
    }
}

void removerElemento(Node **atual, Node **raiz) {

    if (*atual == NULL) {
        printf("\nNao tem elementos presentes.");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        return;
    }

    int i = 0;
    int escolha;

        while (i == 0)
        {
            printf("\nInforme onde deseja remover o valor:");
            printf("\n1 - Esquerda\n");
            printf("2 - Direita\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);
            getchar();

            if ((*atual == *raiz))
            {
                printf("\nInforme onde deseja remover o valor:");
                printf("\n1 - Esquerda\n");
                printf("2 - Direita\n");
                printf("3 - Raiz\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);
                getchar();
            }
            
        
            switch (escolha)
            {
                case 1:
                excluirNodo(&((*atual)->left));
                (*atual)->left = NULL;

                break;

                case 2:
                excluirNodo(&((*atual)->right));
                (*atual)->right = NULL;

                break;

                case 3:
                excluirNodo(&(*atual));
                *raiz = NULL;
                *atual = NULL;
                break;
        
                default:
                printf("\nOpcao invalida, digite novamente: ");
                scanf("%d", &escolha);
                getchar();
                break;
            }
        }

    

    system("cls");
    
}


int main() {

    Node *atual;
    Node *raiz;
    atual = NULL;
    raiz = NULL;

    int opcao, controleMenu;

    do
    {
        controleMenu = 0;
        
        printf("Bem-vindo ao sistema de arvore binaria.\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Mostrar elemento atual\n");
        printf("3 - Percorrer pela arvore\n"); //Esquerda/direita do atual, olhar a raiz e subir de nível
        printf("4 - Remover elemento\n");
        printf("5 - Buscar elemento na arvore\n"); //Busca por profundidade e largura, caso não ache, limpar a fila
        printf("6 - Listar elementos da arvore\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            system("cls");
            inserirElemento(&raiz, &atual);
            break;
        case 2:
            system("cls");
            printf("asdfuhasdihuoasohiuagsd");
            elementoAtual(&atual);
            break;
        case 3:
            system("cls");
            percorrerArvore(&atual, &raiz);
            break;
        case 4:
            system("cls");
            removerElemento(&atual, &raiz);
            break;
        case 5:
            system("cls");
            //buscarElementoArvore();
            break;
        case 6:
            system("cls");
            //listarElementos();
            break;
        case 0:
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