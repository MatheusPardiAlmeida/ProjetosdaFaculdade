/*Os algoritmos de ordenação utilizam uma variável chave para ordenar um vetor. Em geral, para fins didáticos, trabalha-se com uma variável do tipo int como este atributo. 
Escolha, dentre os algoritmos de ordenação apresentados na aula anterior, um para adaptar. O algoritmo, após o seu ajuste, deve ser capaz de ordenar strings.

Entrada	        Saída
RONDONOPOLIS	AMORINOPOLIS
CUIABA	        CUIABA
AMORINOPOLIS	DIORAMA
DIORAMA	        RONDONOPOLIS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TAM 4

typedef struct 
{
    char chave[20];

}REGISTRO;

void bubbleSort(REGISTRO vetor[], int tam)
{
    char temp[20];

    for (int i = 0; i < tam - 1; i++)
    {
        bool trocou = false; /*Utilizamos o bool para interromper o bubbleSort caso ele não tenha mais nada para ordenar*/

        for (int j = 0; j < tam - i - 1; j++)
        {
            if (strncmp(vetor[j].chave, vetor[j+1].chave, 10) > 0) /*Caso a primeira string seja maior que a segunda, iremos realizar a operação*/
            {
                strcpy(temp, vetor[j].chave); /*Passaremos a primeira string para a string temporária*/
                strcpy(vetor[j].chave, vetor[j+1].chave); /*A string da próxima posição irá para a posicão da primeira string anterior*/
                strcpy(vetor[j+1].chave, temp);/*E a string da próxima posição irá receber a string da primeira posição*/

                trocou = true; /*Caso ocorra a troca, iremos declarar como true*/
            }
        }

        if (!trocou) /*Caso a bool seja false, irá interromper o bubbleSort*/
        {
            break;
        }

    }

}

int main()
{

    REGISTRO vetor[TAM] = {"RONDONOPOLIS", "CUIABA", "AMORINOPOLIS", "DIORAMA"}; 

    printf("\n");
    printf("\nVetor de string sem alteracao: ");
    for (int i = 0; i < 4; i++)
    {
        printf("\n%s", vetor[i].chave);
    }

    bubbleSort(vetor, TAM);

    printf("\n");
    printf("\nVetor final");
    for (int i = 0; i < 4; i++)
    {
        printf("\n%s", vetor[i].chave);
    }

    return 0;
}