#include <stdio.h>
#include <stdlib.h>

#define VERMELHO 1
#define PRETO 0

typedef struct nodo{
    int valor;
    struct nodo *esq;
    struct nodo *dir;
    struct nodo *pai;
    int cor;
} Nodo;

Nodo* criarNodo(int v){
    Nodo *p = (Nodo*)malloc(sizeof(Nodo));

    if(p == NULL) {
        printf("Erro ao alocar memoria para o nodo.\n");
        getchar(); // Wait for user input before exiting
        exit(EXIT_FAILURE);
    }

    p->valor = v;
    p->esq = NULL;
    p->dir = NULL;
    p->pai = NULL;
    p->cor = VERMELHO;
    return p;
}
Nodo* inserirNodo(Nodo *raiz, int v);
Nodo* balancearArvore(Nodo *raiz);
Nodo* trocarCores(Nodo *raiz);
int cor(Nodo *raiz);
Nodo* rotEsquerda(Nodo *raiz);
Nodo* rotDireita(Nodo *raiz);
Nodo* movEsquerdaRED(Nodo *raiz);
Nodo* movDireitaRED(Nodo *raiz);
Nodo* excluirNode(Nodo *raiz, int v);
Nodo* procurarMinimo(Nodo *raiz);
Nodo* removerMinimo(Nodo *raiz);
Nodo* buscarElemento(Nodo *raiz, int v);
 
Nodo* buscarElemento(Nodo *raiz, int v){
    
    if(raiz){
        if(v == raiz->valor){
            return raiz; 
        }
        else if(v < raiz->valor){
            return buscarElemento(raiz->esq, v);
        }
        else{
            return buscarElemento(raiz->dir, v);
        }
    }
    else{
        return NULL; 
    }
}

Nodo* procurarMinimo(Nodo *raiz){
    Nodo *node1 = raiz;
    Nodo *node2 = raiz->esq;
    while(node2 != NULL){
        node1 = node2;
        node2 = node2->esq;
    }

    return node1; 
}

Nodo* removerMinimo(Nodo *raiz){
    if(raiz->esq == NULL){
        free(raiz);
        return NULL; 
    }
    
    if(cor(raiz->esq) == PRETO && cor(raiz->esq->esq) == PRETO){
        raiz = movEsquerdaRED(raiz);
    }

    raiz->esq = removerMinimo(raiz->esq);

    return balancearArvore(raiz);
}

Nodo* movEsquerdaRED(Nodo *raiz){
    trocarCores(raiz);
    if(cor(raiz->dir->esq) == VERMELHO){
        raiz->dir = rotDireita(raiz->dir);
        raiz = rotEsquerda(raiz);
        trocarCores(raiz);
    }

    return raiz;
}

Nodo* movDireitaRED(Nodo *raiz){
    trocarCores(raiz);
    if(cor(raiz->esq->esq) == VERMELHO){
        raiz = rotDireita(raiz);
        trocarCores(raiz);
    }

    return raiz;
}

int cor(Nodo *raiz){
    if(raiz == NULL){
        return PRETO;
    }
    else{
        return raiz->cor;
    }
}

Nodo* inserirNodo(Nodo *raiz, int v){
    Nodo *ponto = criarNodo(v);
    if(!raiz){
        raiz = criarNodo(v);
    }else{
        if(v <= raiz->valor){
            raiz->esq = inserirNodo(raiz->esq,v);
            raiz->esq->pai = raiz;
        }else{
            raiz->dir = inserirNodo(raiz->dir,v);
            raiz->dir->pai = raiz;
        }
    }
    return balancearArvore(raiz);
}

Nodo* excluirNode(Nodo *raiz, int v){
    if(v < raiz->valor){ 
        if(cor(raiz->esq) == PRETO && cor(raiz->esq->esq) == PRETO){
            raiz = movEsquerdaRED(raiz);

            raiz->esq = excluirNode(raiz->esq, v);
        }
    }
    else{
        if(cor(raiz->esq) == VERMELHO){
            raiz = rotDireita(raiz);
        }
        if(v == raiz->valor && (raiz->dir == NULL)){
            free(raiz);
            return NULL; // Retorna NULL se o nodo for excluído
        }
        if(cor(raiz->dir) == PRETO && cor(raiz->dir->esq) == PRETO){
        raiz = movDireitaRED(raiz);
        }
        if(v == raiz->valor){
            Nodo *temp = procurarMinimo(raiz->dir);
            raiz->valor = temp->valor;
            raiz->dir = removerMinimo(raiz->dir);
        }
        else{
            raiz->dir = excluirNode(raiz->dir, v);
        }
    }    

    return balancearArvore(raiz);
}

Nodo* rotDireita(Nodo *raiz){

    Nodo *raizNova = raiz->esq;
    raiz->esq = raizNova->dir;
    raizNova->dir = raiz;
    raizNova->cor = raiz->cor; 
    raiz->cor = VERMELHO;
    return raizNova;

}

Nodo* rotEsquerda(Nodo *raiz){
    
    Nodo *raizNova = raiz->dir;
    raiz->dir = raizNova->esq;
    raizNova->esq = raiz;
    raizNova->cor = raiz->cor; 
    raiz->cor = VERMELHO;
    return raizNova;
}

Nodo* trocarCores(Nodo *raiz){
    raiz->cor = !raiz->cor; // Inverte a cor do nó atual
    if(raiz->esq != NULL) {
        raiz->esq->cor = !raiz->esq->cor; // Inverte a cor do filho esquerdo
    }
    if(raiz->dir != NULL) {
        raiz->dir->cor = !raiz->dir->cor; // Inverte a cor do filho direito
    }
    
    return raiz;
}

Nodo* balancearArvore(Nodo *raiz){

    if(cor(raiz->dir) == VERMELHO && cor(raiz->esq) == PRETO){
        raiz = rotEsquerda(raiz);
    }
    if(cor(raiz->esq) == VERMELHO && cor(raiz->esq->esq) == VERMELHO){
        raiz = rotDireita(raiz);
    }
    if(cor(raiz->esq) == VERMELHO && cor(raiz->dir) == VERMELHO){
        raiz = trocarCores(raiz);
    }
    
    return raiz;
}

void listarArvore(Nodo *raiz, int nivel){

    if (raiz == NULL){
        for (int i = 0; i < nivel; i++) {
        printf("\t"); // Para cada nível de profundidade, será dado um tab, dessa forma fazendo com que seja possível visualizar a árvore independente do tamanho
    }
        printf("#\n"); // Será impresso um # quando o valor atual for nulo
        return; 
    }

    listarArvore(raiz->dir, nivel + 1); // A função começa listando todos os valores da direita, aumentando o nível a cada chamada recursiva

    for (int i = 0; i < nivel; i++) {
        printf("\t"); // Para cada nível de profundidade, será dado um tab, dessa forma fazendo com que seja possível visualizar a árvore independente do tamanho
    }
    printf("%d [%s]\n", raiz->valor, raiz->cor == VERMELHO ? "V" : "P"); // Será impresso o valor atual da árvore e irá pular para a próxima linha

    listarArvore(raiz->esq, nivel + 1); // Depois de listar todos os valores a direita, a função lista todos os valores a esquerda, aumentando o nível a cada chamada recursiva
}

void mostrarArvore(Nodo *raiz){
    if(raiz == NULL) {
        printf("A arvore esta vazia.\n");
        getchar();
        system("cls");
        return;
    }
    else{
        listarArvore(raiz, 0);
        printf("\nArvore exibida com sucesso!\n");
        getchar();
        system("cls");
    }

    return;
}

void buscar(Nodo *raiz){

    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        getchar();
        system("cls");
        return;
    }
    else{
        int valor;
        Nodo *aux = NULL;

        printf("Digite o valor do nodo a ser buscado: ");
        scanf("%d", &valor);
        aux = buscarElemento(raiz, valor);
        getchar(); // Limpa o buffer do teclado

        if(aux != NULL) {
            printf("Nodo encontrado: %d [%s]\n", aux->valor, aux->cor == VERMELHO ? "V" : "P");
            getchar();
            system("cls");
        } else {
            printf("Nodo com valor %d nao encontrado.\n", valor);
            getchar();
            system("cls");
        }
    }
    
    return;
}

int main(){

    Nodo *raiz = NULL;
    int opcao, valor;

    do {
        printf("Bem-vindo a arvores rubro-negra\n");
        printf("Selecione as operacoes:\n");
        printf("1 - Inserir nodo\n");
        printf("2 - Excluir nodo\n");
        printf("3 - Buscar nodo\n");
        printf("4 - Mostrar arvore\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch(opcao) {
            case 1:
                printf("Inserir nodo selecionado.\n");
                printf("\nDigite o valor do nodo a ser inserido: ");
                scanf("%d", &valor);
                getchar(); 

                raiz = inserirNodo(raiz, valor);
                if(raiz){
                    raiz->cor = PRETO; 
                    raiz = balancearArvore(raiz);
                }

                printf("Nodo inserido com sucesso!\n");
                printf("Nodo: %d [%s]\n", raiz->valor, raiz->cor == VERMELHO ? "V" : "P");
                printf("\n");
                listarArvore(raiz, 0);
                getchar();
                system("cls");
                
                break;
            case 2:
                printf("Excluir nodo selecionado.\n");
                if(raiz == NULL){
                printf("A arvore esta vazia.\n");
                getchar();
                system("cls");
                }

                printf("Digite o valor do nodo a ser excluido: ");
                scanf("%d", &valor);
                getchar(); 
    
                raiz = excluirNode(raiz, valor);
                raiz = balancearArvore(raiz);

                printf("Nodo excluido com sucesso!\n");
                printf("\n");
                listarArvore(raiz, 0);
                getchar();
                system("cls");

                break;
            case 3:
                printf("Buscar nodo selecionado.\n");
                buscar(raiz);
                break;
            case 4:
                printf("Mostrar arvore selecionado.\n");
                mostrarArvore(raiz);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                getchar(); // Limpa o buffer do teclado
                system("cls");
            break; 
        }

    }while(1);

    return 0;

}