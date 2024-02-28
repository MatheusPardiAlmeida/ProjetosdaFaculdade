/*Em um prédio de Cuiabá, há uma garagem estreita, porém comprida. Sua largura contém espaço suficiente para um único veículo,
além da passagem para o motorista. Assim, os carros são estacionados um atrás do outro, sem exceção.
 Para remover um carro, é preciso que todos os demais sejam removidos também. Como o prédio não tem manobrista, em todas as manhãs
 o cenário é de correria e confusão. Para tentar agilizar o processo, o porteiro Ribamar implementou um sistema de informação que registra,
 para cada carro, a placa e o número do apartamento do proprietário. Quando um morador chega para retirar seu carro,
 ele informa a placa do seu veículo e o programa retorna: a quantidade de veículos a serem retirados primeiro,
 bem como o números dos apartamentos dos proprietários dos veículos envolvidos.
 Implemente esse programa em C, usando uma estrutura de dados adequada para essa finalidade.*/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define TAM 4

 typedef struct
 {
    char placa[7];
    int aptoNum;

 }REGISTRO;

 typedef struct
 {
    REGISTRO conteudo[TAM];
    int topo;

 }PILHA;

 typedef struct
 {
    REGISTRO conteudoaux[TAM];
    int topo;

 }PILHAAUX;

 void iniciarPilha(PILHA *p, PILHA *paux)
 {
    p->topo = 0;
    paux->topo = 0;

 }
 
 void inserirDados(PILHA *p, REGISTRO r)
 {
    if (p->topo < TAM)
    {
        p->conteudo[p->topo] = r;
        p->topo++;
    }
    else
    {
        printf("\n");
        printf("\nPilha cheia!!!");
    }

 }

 void removerDados(PILHA *p, PILHA *paux)
 {
    char placaCarro[7];
    int i;

    printf("\n");
    printf("\nInsira a placa do carro que deseja remover: ");
    setbuf(stdin, NULL);
    gets(placaCarro);

    for (i = p->topo - 1; i >= 0; i--)
    {
    
        if (strcmp(p->conteudo[i].placa, placaCarro) == 0)
        {
            printf("\n");
            printf("\nO carro com placa %s, do apto %d foi encontrado e sera removido.", p->conteudo[i].placa, p->conteudo[i].aptoNum);
            break;
        }
        else if(i <= 0)
        {
            printf("\n");
            printf("\nNenhum carro encontrado!");
            return 1;
        }
        
    }

        for (int j = p->topo - 1; j >= i; j--)
    { 
        if (j == i)
        {
            p->topo--;
        }
        else
        {
            paux->conteudo[j-1] = p->conteudo[j];
            printf("\n");
            printf("\nPos: %d", j-1);
            printf("\nPilha aux. Placa: %s Apto: %d", paux->conteudo[j-1].placa, paux->conteudo[j-1].aptoNum);
        }
    }

    for (int k = p->topo - 1; k >= i; k--)
    {
        p->conteudo[k] = paux->conteudo[k];
        printf("\n");
        printf("\nPos: %d", k);
        printf("\nPilha normal. Placa: %s Apto: %d", p->conteudo[k].placa, p->conteudo[k].aptoNum);
    }

 }

 void visualizarCarros(PILHA *p)
 {
    for (int i = p->topo - 1; i >= 0; i--)
    {
        printf("\n");
        printf("\nPos: %d", i);
        printf("\nPlaca: %s Apto: %d", p->conteudo[i].placa, p->conteudo[i].aptoNum);
    }
    
 }

 int main()
 {
    int opcao;
    PILHA p;
    PILHA paux;
    iniciarPilha(&p, &paux);
    inserirDados(&p, (REGISTRO){"CBA0001", 201});
    inserirDados(&p, (REGISTRO){"CBA0002", 202});
    inserirDados(&p, (REGISTRO){"CBA0003", 203});
    inserirDados(&p, (REGISTRO){"CBA0004", 204});

    do
    {
        printf("\n");
        printf("\nMENU OPCOES");
        printf("\n1 - Remover carro");
        printf("\n2 - Visualizar carros");
        printf("\n3 - Finalizar programa");
        printf("\nDigite: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
            removerDados(&p, &paux);
            break;

            case 2:
            visualizarCarros(&p);
            break;

            case 3:
            printf("\n");
            printf("\nFinalizando programa......");
            return 0;
            break;
        
            default:
            printf("\n");
            printf("\nOpcao invalida, tente novamente.");
            break;
        }

    } while (1);
    
 }