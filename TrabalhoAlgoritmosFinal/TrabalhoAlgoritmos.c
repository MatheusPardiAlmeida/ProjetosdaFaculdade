//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menuCompras.h"
#include "consultaDebito.h"
#include "consultaEstoque.h"
#include "pagarDebito.h"
#include "sorteioClientes.h"
#include "estoqueProdutos.h"
#include "constantes.h"
/*Aqui na função principal iremos incluir todas as bibliotecas a serem utilizadas em nosso programa, incluindo as bibliotecas padrões
do próprio VSCode mais as bibliotecas (headers) que criamos para a execução completa do código. Utilizamos os headers para separar as nossas
funções e criar um código mais limpo e fácil de ler/interpretar, sendo assim, precisamos apenas de um arquivo .c, sendo ele o arquivo principal
e todos os outros arquivos serão declarados como .h*/
/*Utilizando o comando extern, podemos ler uma variável declarada na função principal em outras funções, seja ela uma variável global ou local*/

//variaveis globais para crédito de clientes e estoque dos produtos
//Para que não tenhamos que repor o estoque toda vez que o programa iniciar, predifimos os valores do estoque
int estoqueGlobal[eMax] = {100,100,100,100,100,100,100,100,100,100,100,100};
double clientes[cMax] = {};


//SEPARAÇÃO DE PROCEDIMENTO/FUNÇÃO

int main()
{
    //A variável opcao será utilizada para a escolha de opções no menu
    //e a variável controleMenu será utilizada para que o laço de repetição do menu continue acontecendo
    //enquanto a variável for 0, o menu será repetido até que o programa seja finalizado
    int opcao, controleMenu;

    do{
        controleMenu = 0;

    //começo do menu
    printf("\n");
    printf("\nBem vindo a loja Firelink Shrine.");
    printf("\n");
    printf("\n---------------------------------------------------------------");
    printf("\n");
    printf("\n100 - Menu de compra.");
    printf("\n101 - Consultar debito.");
    printf("\n102 - Repor estoque.");
    printf("\n103 - Consultar estoque.");
    printf("\n104 - Pagar débito de devedores.");
    printf("\n105 - Sorteio especial para clientes especiais.");
    printf("\n");
    printf("\n---------------------------------------------------------------");
    printf("\n");
    printf("\nDigite o código: ");
    scanf("%d", &opcao);

    //opções para escolhas de menu
    switch(opcao){

       case 100:
       menuCompras();
       break;

       case 101:
       consultaDebito();
       break;

       case 102:
       estoqueProdutos();
       break;
    
       case 103:
       consultaEstoque();
       break;

       case 104:
       pagarDebito();
       break;

       case 105:
       sorteioClientes();
       break;

       case 999:
       printf("\n");
       printf("\nFinalizando o programa....");
       controleMenu = 1;
       break;

       default:
       printf("\nCodigo invalido.\n");
       break;

    }
    
    }while(controleMenu == 0);

    return 0;
}