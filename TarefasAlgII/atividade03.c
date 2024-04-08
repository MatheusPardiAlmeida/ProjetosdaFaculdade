#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*João Pedro e sua amiga Juliana estavam em uma discussão: é possível implementar um algoritmo de ordenação simples em listas ligadas dinâmicas? Para verificar a possibilidade, 
eles se desafiaram a implementar um algoritmo de ordenação para listas ligadas dinâmicas, usando como referências as implementações estáticas do Bubble Sort e do Selection Sort. 
Identifique se é possível implementar um dos dois algoritmos mencionados para lidar com listas ligadas dinâmicas. Se for, apresente o código.*/

typedef struct
{
    int num;
}REGISTRO;

typedef struct item
{
    REGISTRO r;
    struct item *prox;
}ITEM;

typedef struct
{
    ITEM *inicio;
    int quantidade;
}LISTA;

void iniciarLista(LISTA *l)
{
    l->inicio = NULL;
    l->quantidade = 0;
}

ITEM* criarItem(REGISTRO r)
{
    ITEM *novo = (ITEM*) malloc(sizeof(ITEM));
    if (novo)
    {
        novo->r = r;
        novo->prox = NULL;
        return novo;
    }

    return NULL;

}

void inserirLista(LISTA *l, REGISTRO r)
{
    ITEM *novo = criarItem(r);
    ITEM *pos = l->inicio;
    ITEM *anterior = NULL;

    while (pos)
    {
        anterior = pos;
        pos = pos->prox;
    }
    if (!anterior)
    {
        l->inicio = novo;
    }
    else
    {
        anterior->prox = novo;
    }

    l->quantidade++;

}

imprimirLista(LISTA *l)
{
    ITEM *pos = l->inicio;

    while (pos)
    {
        printf("Num: %d\n", pos->r.num);
        pos = pos->prox;
    }

}

void trocarElementos(ITEM *a, ITEM *b)
{
    int temp = a->r.num;
    a->r.num = b->r.num;
    b->r.num = temp;
}

void BubbleSort(LISTA *l)
{
    bool trocou;
    ITEM *pos = l->inicio;
    ITEM *anterior = NULL;

    if (l->inicio == NULL)
    {
        return;
    }
    
    do
    {
        trocou = false;

        while (pos)
        {
            if (pos->r.num > pos->prox->r.num)
            {
                trocarElementos(pos, pos->prox);
                trocou = true;
            }

            anterior = pos;
            pos = pos->prox;
        }

    } while (trocou == false);
    
}

int main()
{
    LISTA l;
    iniciarLista(&l);
    inserirLista(&l, (REGISTRO){22});
    inserirLista(&l, (REGISTRO){35});
    inserirLista(&l, (REGISTRO){5});
    inserirLista(&l, (REGISTRO){10});
    inserirLista(&l, (REGISTRO){20});
    inserirLista(&l, (REGISTRO){23});
    inserirLista(&l, (REGISTRO){1});

    printf("Lista sem estar organizada:\n");
    imprimirLista(&l);
    BubbleSort(&l);
    printf("\n");
    printf("Lista organizada com Bubble Sort:\n");

    return 0;
}