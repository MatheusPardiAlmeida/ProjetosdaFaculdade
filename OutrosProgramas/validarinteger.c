#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define buffer_tamanho 4096 /*Definimos o tamanho da string*/

bool validar_integer(char *string, int *integer)/*Iremos utilizar os endereços (pointer) das variáveis string e integer para fazer a validação*/
{
    int i = 0; /*Variável para verificar a posição que desejamos ler*/
    int tamanho = strlen(string); /*Temos uma variável para verificar o tamanho da string*/
    int integer_buffer = 0; /*Variável para indicar a posição no buffer*/
    char buffer[buffer_tamanho]; /*Temos um buffer em char para armazenar os valores válidos da string que será lida*/
    
    while (isspace(string[i])) /*Aqui faremos a verificação para saber se a posição da string sendo lida é uma espaço vazio (white space)*/
    {
        i++; 
    }
    
    if (tamanho == i) /*Caso o tamanho da string seja igual o número de i, então quer dizer que a entrada é vazia, logo retornará falso*/
    {
        return false;
    }

    if (string[i] == '-') /*Aqui iremos validar a entrada caso ela seja um número negativo*/
    {
        buffer[integer_buffer] = '-'; /*O buffer receberá o sinal negativo na posição indicada pelo integer_buffer*/
        integer_buffer++; /*Iremos o integer_buffer*/
        i++; /*Iremos incrementar a posição da string*/

        if (!isdigit(string[i])) /*Caso a próxima posição da string não seja um dígito, irá retornar falso*/
        {
            return false;
        }
    }

    while (i < tamanho && !isspace(string[i])) /*Enquanto a variável i for menor que o tamanho da string e não tenha white space na posição, será continuado o loop*/
    {
        if (!isdigit(string[i])) /*Caso não tenha nenhum digito na posição da string, irá retornar falso*/
        {
            return false;
        }

        buffer[integer_buffer] = string[i]; /*Caso passe a verificação e tenha um número, o buffer na posição
        na posição indicada pela variável integer_buffer, irá receber o valor armazenado na string na posição i*/

        integer_buffer++; /*Iremos incrementar a posição do buffer*/
        i++; /*Iremos incrementar também a posição da string*/

    }

    buffer[integer_buffer] = '\0'; /*Caso não tenha mais nenhum dígito, a próxima posição do buffer irá receber o código para NULL (condição de parada)*/

    while (isspace(string[i])) /*Após armazenar os dígitos no buffer, iremos percorrer o restante da string e verificar se possuí mais alguma coisa*/
    {
        i++;
    }

    if (string[i] != '\0') /*Caso tenha mais algum valor armazenado na string após o armazenamento de valores no buffer, irá retornar falso*/
    {
        /*Utilizaremos o underline para representar os white space*/
        /*EXEMPLO: _____50____10: isso é uma entrada inválida, pois temos dois integers e queremos apenas um*/
        return false;
    }
     
    *integer = atoi(buffer); /*O endereço da variável integer irá receber o valor em inteiro da string que foi digitada pelo usuário*/
    /*Utilizando o "atoi", iremos conventer os valores armazenados em string para integer, sendo assim possível a leitura como um integer*/

    return true;    

}

int main()
{
    int integer = 0; /*A variável integer irá receber o valor em inteiro após a verificação*/
    char buffer[buffer_tamanho]; /*Utilizaremos a string para a leitura do valor digitado pelo usuário*/
    bool validacao_correta = true; /*Criamos uma variável em booleano e damos a ela o valor de "true" (verdadeiro)*/
    
    do
    {
        printf("\nDigite um numero: ");
        fgets(buffer, buffer_tamanho, stdin);

        validacao_correta = validar_integer(buffer, &integer); /*Aqui estamos passando a variável buffer em string para a função booleana e juntamente
        estamos passando também o endereço da variável integer*/

        /*A variável booleana irá receber o resultado da função booleana para a verificação da string inserida pelo usuário, que irá verificar se
        o valor digitado pelo usuário é um integer válido*/

        if (!validacao_correta) /*Caso o valor retornado pela função booleana seja "false", será inválido*/
        {
            printf("Deve ser um valor valido\n");
        }
    
    } while (!validacao_correta); /*Iremos repetir este laço de repetição enquanto o usuário não digitar um valor válido*/

    printf("Integer: %d\n", integer); /*Agora iremos printar o integer retornado pela função booleana*/
    
    return 0;
}
