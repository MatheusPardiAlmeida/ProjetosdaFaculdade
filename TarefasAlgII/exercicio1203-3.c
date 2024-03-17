/*Implemente um algoritmo recursivo que 
desempilha todos os itens de uma pilha (com, no mínimo, 10 itens) e retorna a soma da chave dos registros. O programa deve imprimir o valor retornado.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct 
{
    int num;

}REGISTRO;

typedef struct
{
    REGISTRO itens[MAX];
    int topo;

}PILHA;

void iniciarPilha(PILHA *p)
{
    p->topo = 0;
}

void inserirPilha(PILHA *p, REGISTRO r)
{
    if (p->topo < MAX)
    {
        p->itens[p->topo] = r;
        p->topo++;
    }
    else
    {
        printf("\n");
        printf("\nA pilha esta cheia!!!!!!");
    }

}

void imprimirPilha(PILHA p)
{
    for (int i = p.topo - 1; i >= 0; i--)
    {
        printf("\nNumeros da pilha: %d", p.itens[i].num);
    }

}

REGISTRO desempilhar(PILHA *p)
{
    if (p->topo >= 0)
    {
        return p->itens[(p->topo)--];
    }
    else
    {
        printf("\n");
        printf("\nPilha vazia!!!!!");
        exit(1);
    }
    
}

int somaRecursivo(PILHA *p)
{
    if (p->topo >= 0)
    {
        REGISTRO n = desempilhar(p);
        return n.num + somaRecursivo(p);
    }
    else
    {
        return 0;
    }

}

int main()
{
    PILHA p;

    iniciarPilha(&p);

    for (int i = 1; i < 11; i++)
    {
        inserirPilha(&p, (REGISTRO){i});
    }

    int soma = somaRecursivo(&p);

    printf("\n");
    printf("\nA soma total eh: %d", soma);

    return 0;
}