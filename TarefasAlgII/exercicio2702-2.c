/*Uma estudante de "Algoritmos e Estruturas de Dados II", fascinada com o conteúdo da disciplina 🙃, está criando um módulo de playlists
para um aplicativo de música como o Spotify. Uma playlist, evidentemente, pode conter diversas músicas. Como no Spotify,
músicas mais recentes são as primeiras a serem exibidas na lista. Para facilitar a vida dos usuários, ela deseja implementar o seguinte recurso em seu programa:
uma opção de desfazer e refazer a inserção de músicas na playlist, que funciona da seguinte forma:
a) se o usuário selecionar a opção desfazer, a última música inserida na playlist será removida;
b) se o usuário selecionar a opção refazer, a último música excluída voltará para a playlist;
Implemente um programa que funciona como o descrito acima.
Considere a implementação DINÂMICA da estrutura.*/
#include <stdlib.h>
#include <stdio.h>

typedef struct 
{
    char musica[25];
    
} REGISTRO;

typedef struct item
{
    REGISTRO r;
    struct item* prox;
    
} ITEM;

typedef struct 
{
    ITEM *inicio;
    ITEM *fim;
    int quantidade;

} FILA;

typedef struct 
{
    ITEM *inicio;
    ITEM *fim;

} FILAAUX;

void iniciarFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->quantidade = 0;

}

void iniciarFilaAux(FILAAUX *faux)
{
    faux->inicio = NULL;
    faux->fim = NULL;

}

ITEM* criarItem(REGISTRO r)
{
    ITEM *novo = (ITEM*)malloc(sizeof(ITEM));

    if (novo)
    {
        novo->r = r;
        novo->prox = NULL;
    }

    return novo;
}

void inserir(FILA *f, REGISTRO r)
{
    ITEM *novo = criarItem(r);

    if (novo)
    {
        if (!f->inicio)
        {
            f->inicio = novo;
        }
        else if (f->fim)
        {
            f->fim->prox = novo;
        }

        f->fim = novo;
        f->quantidade++;
        
    }
    
}

void imprimirFila(FILA *f)
{
    ITEM *posicao = f->inicio;

    while (posicao)
    {
        printf("Nome musica: %s\n", posicao->r.musica);
        posicao = posicao->prox;
    }

}

void desfazer(FILA *f, FILAAUX *faux)
{
    if (f->inicio)
    {
        faux->inicio = f->inicio;
        faux->fim = f->fim;
        faux->inicio->prox = f->inicio->prox;

        ITEM *excluir = f->inicio;
        f->inicio = f->inicio->prox;
        free(excluir);
        f->quantidade--;

        printf("\n");
        printf("\nA musica foi desfeita com sucesso.");
    }
    else
    {
        printf("\n");
        printf("\nNao tem nada na fila.");
    }

}


int main()
{
    int opcoes;

    FILA f;
    FILAAUX faux;
    iniciarFila(&f);
    iniciarFilaAux(&faux);
    inserir(&f, (REGISTRO){"Mechanized Memories"});
    inserir(&f, (REGISTRO){"Apex in Circle"});
    inserir(&f, (REGISTRO){"Monkey Likes Daddy"});
    inserir(&f, (REGISTRO){"Steel Haze"});
    
  
  do
  {
    printf("\n");
    printf("\nOpcoes");
    printf("\n1 - Desfazer");
    printf("\n2 - Refazer");
    printf("\n3 - Imprimir");
    printf("\n4 - Finalizar programa.");
    printf("\n");
    printf("\nDigite: ");
    scanf("%d", &opcoes);
    getchar();

    switch (opcoes)
    {
        case 1:
        desfazer(&f, &faux);
        break;

        case 2:
        /* code */
        break;

        case 3:
        imprimirFila(&f);
        break;

        case 4:
        printf("\n");
        printf("\nFinalizando programa.........");
        return 0;
        break;

    
        default:
        printf("\n");
        printf("\nOpcao invalida, tente novamente.");
        break;
    }

  } while (1);
  
    






    return 0;
}