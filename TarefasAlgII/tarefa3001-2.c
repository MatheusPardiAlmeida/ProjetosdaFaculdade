/*João está desenvolvendo um programa para trocar mensagens com seus amigos usando arquivos de texto. A intenção dele é fazer
com que as outras pessoas não entendam o conteúdo dos arquivos, mesmo tendo acesso a eles.
Para isso, ele resolveu fazer a seguinte brincadeira: ao iniciar o programa, o usuário deve selecionar uma das seguintes opções em um menu: escrever ou ler mensagem.
Optando por escrever uma mensagem, o usuário deve informar uma frase de até 100 caracteres e um número inteiro Não entre 1 e 5.
Lidas as opções, o programa deve armazenar a frase digitada em um arquivo, pulando n casas a cada caractere.
Da mesma forma, quando a opção de leitura for selecionada, o programa deve solicitar: um inteiro Não, entre 1 e 5, imprimindo a mensagem decodificada.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void escreverMensagem()
{
    char mensagemEncriptada[100];
    int qtdPulo;

    do
    {
        printf("\n");
        printf("\nEscolha quantos números entre 1-5 deseja pular na cifra: "); /*Escolhemos a chave*/
        scanf("%d", &qtdPulo);
        getchar();

        if (qtdPulo < 1 || qtdPulo > 5)
        {
            printf("\n");
            printf("\nValor invalido, escreva novamente um valor entre 1-5!!");
        }

    } while (qtdPulo < 1 || qtdPulo > 5);
    
    
    printf("\n");
    printf("\nDigite a mensagem para encriptar(100 carac Max)"); /*Agora iremos escrever uma mensagem de até 100 caracteres*/
    printf("\nMensagem: ");
    fgets(mensagemEncriptada, sizeof(mensagemEncriptada), stdin);

    for (int i = 0; i < strlen(mensagemEncriptada); i++) /*Esse for será para encriptar a mensagem*/
    {
        if (isupper(mensagemEncriptada[i]))
        {
            mensagemEncriptada[i] = ((mensagemEncriptada[i] - 65 + qtdPulo) % 26) + 65; /*Utilizando a tabela ASCII e a fórmula da cifra, podemos determinar as letras*/
        }
        else if (islower(mensagemEncriptada[i]))
        {
            mensagemEncriptada[i] = ((mensagemEncriptada[i] - 97 + qtdPulo) % 26) + 97; /*Utilizando a tabela ASCII e a fórmula da cifra, podemos determinar as letras*/
        }
        else
        {
            mensagemEncriptada[i] = mensagemEncriptada[i]; /*Qualquer outro caractere que não seja do alfabeto, será colocado normalmente*/
        }
          
    }

    printf("\nMensagem: %s", mensagemEncriptada);

    FILE *arquivo;
    arquivo = fopen("mensagemencriptada.txt", "w"); /*Aqui iremos apenas escrever a mensagem no arquivo de texto*/

    if (!arquivo)
    {
        printf("\nArquivo nao foi aberto!\n");
    }
    else
    {
        fprintf(arquivo, "%s", mensagemEncriptada);
    }
    
}

void decriptarMensagem()
{
    int qtdPulo;
    char mensagemEncriptada[100];

    do
    {
        printf("\n");
        printf("\nDigite a chave entre 1-5 para decriptar a mensagem: "); /*Teremos que escolher a chave certa para decriptar a mensagem*/
        scanf("%d", &qtdPulo);
        getchar();

        if (qtdPulo < 1 || qtdPulo > 5)
        {
            printf("\n");
            printf("\nValor invalido, escreva novamente um valor entre 1-5!!");
        }

    } while (qtdPulo < 1 || qtdPulo > 5);

    FILE *arquivo;

    arquivo = fopen("mensagemencriptada.txt", "r"); /*Iremos abrir o arquivo apenas para leitura*/

    if (!arquivo)
    {
        printf("\nArquivo nao foi aberto!\n");
    }
    else
    {
        fgets(mensagemEncriptada, 100, arquivo); /*Iremos imprimir o conteúdo do arquivo na variável*/
 
        for (int i = 0; i < strlen(mensagemEncriptada); i++)
        {
            if (isupper(mensagemEncriptada[i]))
            {
                mensagemEncriptada[i] = ((mensagemEncriptada[i] - 65 - qtdPulo) % 26) + 65; /*Faremos o mesmo procedimento de encriptar, porém retirando as casas extras*/
            }
            else if (islower(mensagemEncriptada[i]))
            {
                mensagemEncriptada[i] = ((mensagemEncriptada[i] - 97 - qtdPulo) % 26) + 97;/*Faremos o mesmo procedimento de encriptar, porém retirando as casas extras*/
            }
            else
            {
                mensagemEncriptada[i] = mensagemEncriptada[i];
            }
      
        }
        
    }

    printf("\n");
    printf("\nMensagem decriptada: %s", mensagemEncriptada); /*Imprimimos a mensagem*/

    fclose(arquivo); /*E fechamos o arquivo*/

}

int main()
{
    int opcao;

    do
    {
        printf("\n");
        printf("\nApos escrever a mensagem, deve finalizar o programa e abri-lo novamente."); /*A escrita só é feita após finalizar o programa*/
        printf("\n");
        printf("\n1 - Escrever mensagem");
        printf("\n2 - Decriptar mensagem");
        printf("\n3 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
            escreverMensagem();
            break;

            case 2:
            decriptarMensagem();
            break;

            case 3:
            printf("\n");
            printf("\nFinalizando programa.....");
            return 0;
            break;
        
            default:
            printf("\n");
            printf("\nOpcao invalida, tente novamente.");
            break;
        }

    } while (1);
    
}