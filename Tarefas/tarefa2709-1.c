/*Sem utilizar nenhuma biblioteca, desenvolva uma função do tipo inteira que recebe
um vetor de caracteres e retorna quantas letras “a” (minúsculas) existem nesse vetor
de caracteres. O tamanho do vetor deve ser de 30 posições e a string deve ser digitada
pelo usuário e lida */
#include <stdio.h>

int main ()
{
    int i = 0;  
    int contador = 0;
    char frase[30];

    printf("Digite uma frase qualquer: ");
    fgets(frase, 30, stdin);
    
    while (frase[i] != '\0')
    {
        if (frase[i] == 97)
        {
            contador++;
            i++;
        }
        else
        {
            i++;
        } 
    }

    printf("\n");
    printf("A frase tem '%s' , possui %d letras 'a'.", frase, contador);

    return 0;
}