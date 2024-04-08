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
#define TAM 4

typedef struct
 {
    char musica[30];
 }REGISTRO;

 typedef struct 
 {
    REGISTRO r;
    struct item *ant;
 }ITEM;
 
 typedef struct
 {
    ITEM *topo;
    int quantidade;
 }PILHA;

 typedef struct
 {
    ITEM *topo;
    int quantidade;
 }PILHAAUX;

void iniciarPilha(PILHA *p)
{
    p->topo = NULL;
    p->quantidade = 0;

}

void iniciarPilhaAux(PILHAAUX *paux)
{
    paux->topo = NULL;
    paux->quantidade = 0;

}

ITEM* criarItem(REGISTRO r)
{
    ITEM *novo = (ITEM*)malloc(sizeof(ITEM));

    if (novo)
    {
        novo->r = r;
        novo->ant = NULL;
    }

    return novo;
}

void inserir(PILHA *p, PILHAAUX *paux, REGISTRO r)
{
    ITEM *novo = criarItem(r); /*Inserir na pilha normal*/

    novo->ant = p->topo;
    p->topo = novo;

    ITEM *novoaux = criarItem(r); /*Inserir na pilha auxiliar para a operação de refazer*/
 
    novoaux->ant = paux->topo;
    paux->topo = novoaux;
    
}

void imprimirFila(PILHA *p)
{

    while (p->topo != NULL)
    {
        printf("\n");
        printf("\nMusica: %s", p->topo->r.musica);
        p->topo = p->topo->ant;
    }

}

void desfazer(PILHA *p, PILHAAUX *paux){k

    if(paux->topo = NULL)
    {
        printf("\n");
        printf("\nNada para desfazer!");
        return;
    }

    ITEM *musicaDesfazer = p->topo;
    p->topo = p->topo->ant;

    ITEM *refazerMusica = criarItem(musicaDesfazer->r);
    refazerMusica->ant = paux->topo;
    paux->topo = refazerMusica;

    free(musicaDesfazer);
}

void refazer(PILHA *p, PILHAAUX *paux)
{
    if(paux->topo = NULL)
    {
        printf("\n");
        printf("\nNada para desfazer!");
        return;
    }

    ITEM *refazerMusica = paux->topo;
    paux->topo = paux->topo->ant;

    ITEM *desfazerMusica = criarItem(refazerMusica->r);
    desfazerMusica->ant = p->topo;
    p->topo = desfazerMusica;

    free(refazerMusica);
}


int main()
{
    int opcoes;

    PILHA p;
    PILHAAUX paux;
    iniciarPilha(&p);
    iniciarPilhaAux(&paux);
    inserir(&p, &paux, (REGISTRO){"Mechanized Memories"});
    inserir(&p, &paux, (REGISTRO){"Apex in Circle"});
    inserir(&p, &paux, (REGISTRO){"Monkey Likes Daddy"});
    inserir(&p, &paux, (REGISTRO){"Steel Haze"});
    
  
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
        desfazer(&p, &paux);
        break;

        case 2:
        refazer(&p, &paux);
        break;

        case 3:
        imprimirFila(&p);
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