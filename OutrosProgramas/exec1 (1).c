#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct
{
    int codigo;

}CONTEUDO;

typedef struct 
{
    CONTEUDO r;
    struct item *prox;

}ITEM;

typedef struct
{
   
   ITEM *topo;
   int quantidade;

}PILHA;

void iniciarPilha(PILHA *p)
{
    p->topo = NULL;
    p->quantidade = 0;

}

ITEM* criarItem(CONTEUDO r)
{
    ITEM* novo = (ITEM*)malloc(sizeof(ITEM));

    if (novo)
    {
        novo->r = r;
        novo->prox = NULL;
    }

    return novo;
}

void empilhar(PILHA *p, CONTEUDO r)
{
    
    
}

void desempilhar(PILHA *p)
{
    if (p->topo > 0)
    {
        p->topo--;
    }
        
}

void imprimir(PILHA *p)
{
    for (int i = p->topo -1; i >= 0 ; i--)
    {
        printf("\n%d", p->vetor[i].codigo);
    }
    
}

int main()
{

    PILHA p;
    iniciarPilha(&p);
    empilhar(&p, (CONTEUDO){10});
    empilhar(&p, (CONTEUDO){20});
    empilhar(&p, (CONTEUDO){30});
    imprimir(&p);
    desempilhar(&p);
    empilhar(&p, (CONTEUDO){40});
    imprimir(&p);

    return 0;
}