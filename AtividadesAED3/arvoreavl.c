#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo *esq;
    struct nodo *dir;
    struct nodo *pai;
    int h;
} Nodo;

Nodo* criarNodo(int v){
    Nodo *p = (Nodo*)malloc(sizeof(Nodo));
    p->valor = v;
    p->esq = NULL;
    p->dir = NULL;
    p->pai = NULL;
    p->h = 0;
    return p;
}

// Retorna o maior valor entre os dois como altura
int ajustarAltura(int a, int b){
    if(a > b) {
        return a;
    } else {
        return b;
    }
}
int altura(Nodo *p){ 
    if(p == NULL)
        return 0; //Caso seja nulo, retorna 0
    else{
        return p->h; //Se não, retorna a altura
    } 
}

/// Função de balancemanto
int fb(Nodo *p){ 
    if(p == NULL)
        return 0;
    else{
        return altura(p->esq) - altura(p->dir);
    }
}

Nodo* encontrarSucessor(Nodo *raiz){
    while(raiz->dir != NULL){ //Encontra o maior valor da subárvore esquerda
        raiz = raiz->dir;
    }
    return raiz; //Retorna o sucessor
}

Nodo* rotDir(Nodo *raiz){
    Nodo *raizNova = raiz->esq; //Nova raiz será o filho esquerdo da raiz atual
    raiz->esq = raizNova->dir; //O filho esquerda da raiz vira o filho direito da nova raiz
    raizNova->dir = raiz; //O filho direito da nova raiz será a raiz atual

    raizNova->pai = raiz->pai; //Atualiza o pai da nova raiz
    raiz->pai = raizNova; //O pai vira a nova raiz
    if(raiz->esq) //Caso a raiz a esquerda não seja nula, atualiza o pai
        raiz->esq->pai = raiz;

    //Recalcular as alturas
    raiz->h = ajustarAltura(altura(raiz->esq), altura(raiz->dir)) + 1;
    raizNova->h = ajustarAltura(altura(raizNova->esq), altura(raizNova->dir)) + 1;

    return raizNova;
}

Nodo* rotEsq(Nodo *raiz){
    Nodo *raizNova = raiz->dir; //Nova raiz será o filho direito da raiz atual
    raiz->dir = raizNova->esq; //O filho direito da raiz vira o filho esquerdo da nova raiz
    raizNova->esq = raiz; //O filho esquerdo da nova raiz será a raiz atual

    raizNova->pai = raiz->pai; //Atualiza o pai da nova raiz
    raiz->pai = raizNova; //O pai vira a nova raiz
    if(raiz->dir) //Caso a raiz a direita não seja nula, atualiza o pai
        raiz->dir->pai = raiz;
    
    raiz->h = ajustarAltura(altura(raiz->esq), altura(raiz->dir)) + 1;
    raizNova->h = ajustarAltura(altura(raizNova->esq), altura(raizNova->dir)) + 1;

    return raizNova;
}

Nodo* rotEsqDir(Nodo *raiz){ //Faz a rotação dupla esquerda-direita
    raiz->esq = rotEsq(raiz->esq);
    return rotDir(raiz);
}

Nodo* rotDirEsq(Nodo *raiz){ //Faz a rotação dupla direita-esquerda
    raiz->dir = rotDir(raiz->dir);
    return rotEsq(raiz);
}

Nodo* balancear(Nodo *raiz){
    if(raiz == NULL)
        return raiz;
    //Atualiza a altura do nó atual antes de balancear
    raiz->h = ajustarAltura(altura(raiz->esq), altura(raiz->dir)) + 1;
    //Calcula o fator de balanceamento
    int fator = fb(raiz);

    if(fator > 1 && fb(raiz->esq) > 0){
        return rotDir(raiz);
    }
    if(fator > 1 && fb(raiz->esq) < 0){
        return rotEsqDir(raiz);
    }
    if(fator < -1 && fb(raiz->dir) < 0){
        return rotEsq(raiz);
    }
    if(fator < -1 && fb(raiz->dir) > 0){
        return rotDirEsq(raiz);
    }

    return raiz;
}

void mostraArvore(Nodo *p, int nivel){
    int i;
    if(p){
        mostraArvore(p->dir,nivel+1);
        printf("\n");
        for(i=0;i<nivel;i++)
            printf("\t");
        printf("%i [%i|%i]\n",p->valor,p->h,fb(p)); //Valor, altura, fator de balanceamento
        mostraArvore(p->esq,nivel+1);
    }
}

Nodo* inserirNodo(Nodo *raiz, int v){
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
    //Balanceia a árvore depois da inserção
    return balancear(raiz);
}

Nodo* buscar(Nodo *raiz, int v){
    if(raiz){
        if(v == raiz->valor){
            return raiz;
        }else if(v < raiz->valor){
            return buscar(raiz->esq, v);
        }else
            return buscar(raiz->dir, v);
    }else
        return NULL;
}

Nodo* excluir(Nodo *raiz, int v){
    if(raiz == NULL)
        return NULL;
    
    if(v < raiz->valor){
        raiz->esq = excluir(raiz->esq, v);
        if(raiz->esq)
            raiz->esq->pai = raiz; //Atualiza ponteiro
    }
    else if(v > raiz->valor){
        raiz->dir = excluir(raiz->dir, v);
        if(raiz->dir)
            raiz->dir->pai = raiz; //Atualiza ponteiro
    }
    else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            raiz = NULL;
        }
        else if(raiz->esq == NULL){ //Nó apenas com filho direito
            Nodo *temp = raiz;
            raiz = raiz->dir;
            raiz->pai = temp->pai;
            free(temp);
        }
        else if(raiz->dir == NULL){ //Nó apenas com filho esquerdo
            Nodo *temp = raiz;
            raiz = raiz->esq;
            raiz->pai = temp->pai;
            free(temp);
        }
        else{
            //Caso 3, nó com dois filhos
            Nodo *sucessor = encontrarSucessor(raiz->esq);
            raiz->valor = sucessor->valor; //Substitui o valor do nó pelo sucessor
            raiz->esq = excluir(raiz->esq, sucessor->valor); //Remove o sucessor

            if(raiz->esq)
            {
                raiz->esq->pai = raiz;
            } 
        }
    }

    return balancear(raiz);
}

int main(){
    Nodo *raiz = NULL, *aux = NULL;
    int op, v;

    do{
        mostraArvore(raiz,0);
        printf("\n--------------------------------------------------\n");
        printf("1 - inserir novo nodo\n");
        printf("2 - excluir nodo\n");
        printf("3 - buscar nodo\n");
        printf("0 - sair\n");
        printf("opcao: ");
        scanf("%d",&op);

        switch(op){
        case 1:
            printf("Informe o valor (int): ");
            scanf("%d",&v);
            raiz = inserirNodo(raiz,v);
            break;
        case 2:
            printf("Informe o valor (int): ");
            scanf("%d",&v);
            raiz = excluir(raiz,v);
            break;
        case 3:
            printf("Informe o valor (int): ");
            scanf("%d",&v);
            if(aux = buscar(raiz,v))
                printf("valor encontrado\n");
            else
                printf("valor nao pertence a arvore\n");
            break;
        case 0:
            printf("saindo...\n");
            break;
        default:
            printf("opcao invalida\n");
        }
        printf("\n\n\n");
    }while(op!=0);

    return 0;
}
