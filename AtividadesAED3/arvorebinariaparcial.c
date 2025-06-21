// Exercício 01: árvore binária de busca

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <stdbool.h>

typedef struct Node{
    int valor;
    struct Node *left;
    struct Node *right;
    struct Node *pai;
} Node;

typedef struct item{
    Node *valor;
    struct item* prox;
} Item;

typedef struct fila{
    Item* inicio;
    Item* fim;
} Fila;

Node* criarNode(int valor){
    Node *ponto = (Node*)malloc(sizeof(Node));
    ponto->valor = valor;
    ponto->left = NULL;
    ponto->right = NULL;
    ponto->pai = NULL;
    return ponto;
}

bool verificarInput(char* input){
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])== 0){
            return false; // Retorna falso se encontrar um caractere não numérico
        }
    }
    return true; // Retorna verdadeiro se todos os caracteres forem numéricos
}

void inserirElemento(Node **raiz, Node **atual){
 // Utilizamos ponteiro duplo caso a função precise alterar as variáveis.
    int escolha;
    int valorConvertido;
    char valor[50];

    printf("Digite o valor a ser inserido na arvore: ");
    scanf("%s", &valor);
    getchar();

    if (!verificarInput(valor)) { //Verifica se o valor é um número inteiro
        printf("\nValor invalido, digite novamente: ");
        scanf("%s", &valor);
        getchar();
    }
    else{
        valorConvertido = atoi(valor); // Converte a string para inteiro

        if (valorConvertido < 0) //Verifica se o valor é negativo 
        {
            printf("\nValor menor que zero, digite novamente: ");
            scanf("%s", &valor);
            getchar();
        }
    }

    Node *ponto = criarNode(valorConvertido); //Cria o node

    if (*raiz == NULL){ //Caso o node seja o primeiro, será a raiz
        *raiz = ponto; // Atribui o node criado como raiz
        *atual = ponto; // Atribui o node criado como atual
    }
    else{ //Caso contrário
    
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
                    ponto->pai = *atual; // Para facilitar na hora de subir de nível, todos os nós subsequentes terão um valor pai atribuído a elas
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
                    ponto->pai = *atual; // Para facilitar na hora de subir de nível, todos os nós subsequentes terão um valor pai atribuído a elas
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
    
    free(ponto);
    system("cls");
    return;
}

void percorrerArvore(Node **atual, Node *raiz) { // Como a função só altera o endereço de memória de atual, raiz não precisa ser um ponteiro duplo, apenas teremos seu valor como referência.

    if (*atual == NULL && raiz == NULL) // Caso tanto o valor atual quanto a raiz estejam vazias, a árvore está completamente vazia
    {
        printf("\nA arvore esta vazia.");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        system("cls");
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
        if (((*atual)->left == NULL)){ // Impede o usuário de ir para um endereço de memória NULL
            printf("\nO elemento a esquerda esta vazio. Pressione qualquer tecla para continuar.");
            getchar();
            system("cls");
            return;
        }
        else{
            *atual = (*atual)->left;
        }
        
        break;
    case 2:
        if (((*atual)->right == NULL)){ // Impede o usuário de ir para um endereço de memória NULL
            printf("\nO elemento a direita esta vazio. Pressione qualquer tecla para continuar.");
            getchar();
            system("cls");
            return;
        }
        else{
            *atual = (*atual)->right;
        }
        break;
    case 3:
        if (*atual == raiz){
            printf("\nA arvore ja esta na raiz, pressione qualquer tecla para continuar.");
            getchar();
            system("cls");
            return;
        }
        else{
            *atual = raiz;
        }
        
        break;
    case 4:
        if ((*atual)->pai == NULL){
            printf("\nA arvore ja esta no topo, pressione qualquer tecla para continuar.");
            getchar();
            system("cls");
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

void excluirNodo(Node **p){
    if(p != NULL){
        if((*p)->left != NULL){
            excluirNodo(&(*p)->left); // Chama a função recursiva e verifica todos os elementos a esquerda do valor que será excluido
        }
        else{
            printf("\nElemento a esquerda vazio.\n"); // Para fazer verificação se esta funcionando corretamente
        }
        if((*p)->right != NULL){
            excluirNodo(&(*p)->right); // Chama a função rescursiva e verifica todos os elementos a direita do valor que será excluido
        }
        else{
            printf("\nElemento a direita vazio.\n"); // Para fazer verificação se esta funcionando corretamente
        }
        free(*p); // Libera o espaço de memória
    }
    else{
        printf("\nO elemento a ser removido nao existe");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
    }
    return;
}

void removerElemento(Node **atual, Node **raiz) {  // Utilizamos ponteiro duplo caso a função precise alterar as variáveis.

    if (*atual == NULL) { // Caso o valor atual seja nulo, então a árvore está vazia 
        printf("\nNao tem elementos presentes.");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        system("cls");
        return;
    }

    int escolha;
    int i = 0;

        do
        {
            printf("\nInforme onde deseja remover o valor:");
            printf("\n1 - Esquerda");
            printf("\n2 - Direita");
            if (*atual == *raiz) // Caso o endereço de memória atual seja o mesmo da raiz, terá a opção de excluir a raiz
            {
                printf("\n3 - Raiz");
            }
            printf("\nDigite sua escolha: ");
            scanf("%d", &escolha);
            getchar();      
        
            switch (escolha)
            {
                case 1:
                excluirNodo(&(*atual)->left); // Chama a função recursiva
                (*atual)->left = NULL; // Deixa o endereço de memória a esquerda do atual como NULL
                printf("\nOs elementos foram removidos com sucesso.");
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
                system("cls");
                i = 1; // A variável de controle do loop é alterada para 1, fazendo com que o loop não continue
                break;

                case 2:
                excluirNodo(&(*atual)->right); // Chama a função recursiva
                (*atual)->right = NULL; // Deixa o endereço de memória a direita do atual como NULL
                printf("\nOs elementos foram removidos com sucesso.");
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
                system("cls");
                i = 1; // A variável de controle do loop é alterada para 1, fazendo com que o loop não continue
                break;

                case 3:
                excluirNodo(&(*atual));
                *raiz = NULL; // Deixa o endereço de memória raiz como NULL, deixando a árvore vazia
                *atual = NULL;
                printf("\nOs elementos foram removidos com sucesso.");
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
                system("cls");
                i = 1; // A variável de controle do loop é alterada para 1, fazendo com que o loop não continue
                break;
        
                default:
                printf("\nOpcao invalida, digite novamente: ");
                scanf("%d", &escolha);
                getchar();
                break;
            }
        } while(i == 0); // Enquanto a variável de controle do loop for igual a 0, o loop continuará pedindo uma opção válida
    return;
}

void listarOrdem(Node *atual, int nivel) {
    if (atual == NULL){
        for (int i = 0; i < nivel; i++) {
        printf("\t"); // Para cada nível de profundidade, será dado um tab, dessa forma fazendo com que seja possível visualizar a árvore independente do tamanho
    }
        printf("#\n"); // Será impresso um # quando o valor atual for nulo
        return; 
    }

    listarOrdem(atual->right, nivel + 1); // A função começa listando todos os valores da direita, aumentando o nível a cada chamada recursiva

    for (int i = 0; i < nivel; i++) {
        printf("\t"); // Para cada nível de profundidade, será dado um tab, dessa forma fazendo com que seja possível visualizar a árvore independente do tamanho
    }
    printf("%d\n", atual->valor); // Será impresso o valor atual da árvore e irá pular para a próxima linha

    listarOrdem(atual->left, nivel + 1); // Depois de listar todos os valores a direita, a função lista todos os valores a esquerda, aumentando o nível a cada chamada recursiva
}

void listarElementos(Node *raiz){
    if (raiz == NULL) {
        printf("\nA arvore esta vazia.");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        system("cls");
        return;
    }
    else
    {
        listarOrdem(raiz, 0);
        //Chama a função recursiva, passando a raiz e o nível sempre começará em 0 (raiz)
    }
    
    printf("\nTodos os elementos da arvore.");
    printf("\nPressione qualquer tecla para continuar...");
    getchar();
    system("cls");
    return;
}

int buscaProfundidade(Node *atual, int valor){

    if (atual == NULL){
        return 0;
    }

    if (atual->valor == valor){
        printf("\n");
        printf("\nO numero buscado se encontra na arvore: %d\n", atual->valor);
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        system("cls");
        return 1;
    }
    
    else{
        printf("\nValor atual: %d\n", atual->valor);
    }

    if(buscaProfundidade(atual->left, valor)){ // Como a função é recursiva do tipo int, caso o valor seja encontrado, irá retornar 1 até não ter mais chamadas recursivas
        return 1; // Se o valor for encontrado na subárvore esquerda, retorna 1
    }
    if(buscaProfundidade(atual->right, valor)){ // Caso o valor retornado seja 0, a função irá continuar a busca até não ter mais chamadas recursivas
        return 1; // Se o valor for encontrado na subárvore direita, retorna 1
    }

    return 0; // Após acabar todas as chamadas recursivas, se o valor não for encontrado, retorna 0
}
void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enfileirar(Fila *fila, Node *atual) {
    Item *novoItem = (Item*)malloc(sizeof(Item));
    novoItem->valor = atual;
    novoItem->prox = NULL;

    if (fila->inicio == NULL){ // Se a fila estiver vazia, o novo item será o início e o fim
        fila->inicio = novoItem; // Adiciona o novo item como início da fila
        fila->fim = novoItem; // Adiciona o novo item como fim da fila
    } else {
        fila->fim->prox = novoItem; // O item anterior aponta para o novo item como próximo
        fila->fim = novoItem; // Atualiza o fim da fila para o novo item
    }
} 

Node* desenfileirar(Fila *fila) {
    if (fila->inicio == NULL){ // Se o ínicio da fila for nulo, retorna nulo
        return NULL;
    }

    Node *atualValor = fila->inicio->valor; // Irá armazenar o valor do início da fila antes de removê-lo
    Item *itemRemovido = fila->inicio; // Irá pegar o ínicio da fila para remover
    fila->inicio = fila->inicio->prox; // Move o início da fila para o próximo item

    free(itemRemovido); // Libera a memória do item removido
    return atualValor; // Retorna o valor do item removido
}

void buscaLargura(Node *atual, int valor) {

    Fila fila;
    inicializarFila(&fila);
    enfileirar(&fila, atual);

    while (fila.inicio != NULL) { // Enquanto houver elementos na fila, continue a busca
        Node *tempAtual = desenfileirar(&fila); // Armazena o valor do ínicio da fila nesse node temporário e remove o mesmo da fila
        // Assim, na primeira vez que a função for chamada, o valor atual será o mesmo que o valor da raiz
        // A fila ficará vazia já que não foi enfileirado os filhos da raiz
        // Porém quando for para enfileirar os filhos do node atual, a fila não ficará mais vazia
        // Assim teremos [1] -> [2,3] -> [4,5,6,7] e assim por diante, até que todos os nodes da árvore sejam lidos e depois desenfileirados 
        printf("\nValor atual da busca: %d", tempAtual->valor);

        if (tempAtual->valor == valor) { // Se o valor do node temporário for igual ao valor buscado, imprime o valor e retorna
            printf("\nO numero buscado se encontra na arvore: %d\n", tempAtual->valor);
            printf("\nPressione qualquer tecla para continuar...");
            getchar();

            while (fila.inicio != NULL) { // Limpa a fila antes de retornar
                desenfileirar(&fila); // Desenfileira todos os elementos restantes
            }
            system("cls");
            return;
        }

        if (tempAtual->left != NULL) { // Se o valor a esquerda do node temporário não for nulo, enfileira o valor
            enfileirar(&fila, tempAtual->left); 
        }
        if (tempAtual->right != NULL) { // Se o valor a direita do node temporário não for nulo, enfileira o valor
            enfileirar(&fila, tempAtual->right);
        }
        // Da forma que está escrito, a função irá enfileirar os filhos do node atual e depois se desenfileirar
        // Continuando a fila com os filhos, da esquerda pra direita
    }

    printf("\nO numero buscado nao se encontra na arvore.\n");
    printf("\nPressione qualquer tecla para continuar...");
    getchar();
    system("cls");
}

void buscarElementoArvore(Node *raiz){

    if (raiz == NULL) { // Caso a árvore seja vazia, retorna a função principal
        printf("\nA arvore esta vazia.");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        system("cls");
        return;
    }
    
    char valor[50]; 
    int valorConvertido;
    int escolha;
    int resultadoDFS;

    printf("\nDigite o valor que deseja encontar na arvore: ");
    scanf("%s", &valor);
    getchar();

    if (!verificarInput(valor)) { //Verifica se o valor é um número inteiro
        printf("\nValor invalido, digite novamente: ");
        scanf("%s", &valor);
        getchar();
    }
    else{
        valorConvertido = atoi(valor); // Converte a string para inteiro
    }

    printf("\nDeseja fazer busca por profundidade ou largura?");
    printf("\n1 - Profundidade");
    printf("\n2 - Largura");
    printf("\nDigite sua escolha: ");
    scanf("%d", &escolha);
    getchar();

    switch (escolha)
    {
    case 1:
        resultadoDFS = buscaProfundidade(raiz, valorConvertido);
        if (resultadoDFS == 0){ // Se a função retornar 0, significa que o valor não foi encontrado
        printf("\n");
        printf("\nO numero buscado nao se encontra na arvore.\n");
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        }
        break;
    case 2:
        buscaLargura(raiz, valorConvertido);
        break;
    default:
        printf("\nOpcao invalida, tente novamente.\n");
        break;
    }
    system("cls");
    return;
}

int main() {

    Node *raiz = NULL;
    Node *atual = NULL;

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
            if (atual == NULL){
            printf("\nO elemento atual se encontra vazio.");
            }
            else{
                printf("\nO elemento atual:\n");
                printf("\n");
                printf("\tAtual: %d\n", atual->valor);

                    if (!(atual->left))
                    {
                    printf("\tEsquerda: #\n");
                    }
                    else{
                    printf("\tEsquerda: %d\n", atual->left->valor);
                    }
                    if (!(atual->right))
                    {
                    printf("\tDireita: #\n");
                    }
                    else{
                    printf("\tDireita: %d\n", atual->right->valor);
                    }
                }   
                
                printf("\nPressione qualquer tecla para continuar...");
                getchar();
                system("cls");
        break;
        case 3:
            system("cls");
            percorrerArvore(&atual, raiz);
        break;
        case 4:
            system("cls");
            removerElemento(&atual, &raiz);
        break;
        case 5:
            system("cls");
            buscarElementoArvore(raiz);
            system("cls");
        break;

        case 6:
            system("cls");
            listarElementos(raiz);
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