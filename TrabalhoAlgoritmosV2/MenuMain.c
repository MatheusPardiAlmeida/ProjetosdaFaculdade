#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <strings.h>
#include <stdbool.h>
#include "../TrabalhoAlgoritmosV2/funcoes/validarEntrada.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub1.h"          
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub2.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub3.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub4.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub5.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub6.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaSub7.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/confirmarCompraLoja.h"
#include "../TrabalhoAlgoritmosV2/lojasSub/lojaFirelink.h"
#include "../TrabalhoAlgoritmosV2/saldos/depositarSaldo.h"
#include "../TrabalhoAlgoritmosV2/saldos/consultarSaldo.h"
#include "../TrabalhoAlgoritmosV2/saldos/sorteioAlmas.h"
/*Acima estamods chamando todas as funções auxiliares para o funcionamento completo do programa*/
#define buffer_tamanho 4096 /*Tamanho definido para a string*/
#define Clientes 10

int saldoClientes[Clientes] = {50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000};
/*Aqui teremos um array para armazenar o saldo dos clientes (tudo pré-definido)*/

int main()
{
    int almasClientes; /*variável para servir de auxilio para armazenar o valor do saldoClientes para o sorteio*/
    int i; /*Variável para armazenar um número aleatório do sorteio*/
    int codigo; /*Variável para inserir o código do cliente*/
    int ctrlLoop; /*Variável para controle do laço de repetição do programa*/
    int escolha; /*Variável para receber o código do nosso menu principal*/
    char string[buffer_tamanho]; /*Variável que irá receber a entrada do usuário e será utilizada para saber se é um integer ou não*/
    bool validar = true; /*Variável para auxiliar na validação da entrada do usuário*/
 do
 {
    almasClientes = 0; /*A variável voltará para 0 toda vez que o loop for reiniciado*/
    ctrlLoop = 0; /*A variável voltará para 0 toda vez que o loop for reiniciado*/

    do
    {
        printf("=====================================================\n");
        printf("Bem-vindo a Firelink Shrine, Undead\n");
        printf("Sou a Firekeeper e irei te guiar em nossa jornada. \n");
        printf("1 - Loja de Firelink\n");
        printf("2 - Depositar saldo\n");
        printf("3 - Consultar seu saldo\n");
        printf("4 - Sorteio Mega-Alma Firelink Shrine\n");
        printf("5 - Finalizar programa\n");
        printf("=====================================================\n");
        printf("\n");
        printf("Sua escolha: ");
        fgets(string, buffer_tamanho, stdin);
        printf("\n");

        validar = validar_integer(string, &escolha); /*Aqui iremos fazer a verificação para saber se o que o usuário digitou é realmente um integer*/
        
        if (!validar) /*Utilizamos o ! para indicar um operador de NOT, ou seja, caso não seja o sinal da variável validar não seja TRUE, caíra nesse if*/
        {
            printf("\n");
            printf("Entrada invalida, faca novamente.\n");
            printf("\n");
            }

    } while (!validar); /*Caso a variável validar seja diferente de TRUE, o laço irá se repetir*/

    switch (escolha)
    {
        case 1:
        lojaFirelink(); /*Estamos chamando a função loja para começar as compras do cliente*/
        break;

        case 2:
        /*Para que a função do saldo funcione corretamente, precisamos pedir o código do usuário antes*/
      do
      {
        printf("\n");
        printf("=====================================================\n");
        printf("Antes de depositar, digite o seu codigo de cliente.\n");
        printf("=====================================================\n");
        printf("\n");
        printf("Seu codigo: ");
        fgets(string, buffer_tamanho, stdin);

        validar = validar_integer(string, &codigo);

        if (!validar)
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Entrada invalida, tente novamente\n");
            printf("=====================================================\n");
            printf("\n");
        }
        else if (codigo < 0 || codigo > (Clientes - 1))
        {
            printf("\n");
            printf("=====================================================\n");
            printf("Codigo invalido, tente novamente\n");
            printf("=====================================================\n");
            printf("\n");
        }
                 
      } while ((!validar) || (codigo < 0 || codigo > (Clientes - 1)));

       saldoClientes[codigo] = depositarSaldo(saldoClientes[codigo]); /*Aqui iremos modificar o valor da variável saldoClientes para receber a soma do depósito*/

        break;

        case 3:
        consultarSaldo(); /*Iremos chamar a função para consultar o saldo*/
        break;

        case 4:

        srand(time(NULL)); /*Aqui iremos gerar um número totalmente aleatório utilizando o horário do computador como seed*/
        i = rand()%10; /*O número gerado será armazenado na variável i e receberá um número de 0 a 9*/
        almasClientes = saldoClientes[i]; /*Utilizaremos a variável auxiliar para armazenar o valor do saldoClientes na posição 
        indicada pela variável i*/

        saldoClientes[i] = sorteioAlmas(&almasClientes, i); /*A função receberá o endereço da variável auxiliar e receberá o valor do código*/

        break;

        case 5:

        printf("\n");
        printf("Obrigado pela sua escolha\n");
        printf("Finalizando programa......\n");
        printf("\n");
        ctrlLoop = 1; /*Aqui iremos finalizar o programa*/
        
        break;

        default:

        printf("\n");
        printf("Codigo invalido , faca novamente.\n");
        printf("\n");

        break;
    }

 }while(ctrlLoop == 0);

    return 0;
}