/* Utilizando a biblioteca ctype.h, desenvolva um procedimento que receba um vetor
de caracteres e imprima quantas letras do alfabeto e quantos números existem nesse
vetor de caracteres. O tamanho do vetor deve ser de 30 posições e a string deve ser
digitada pelo usuário e lida na função principal.*/

#include <stdio.h>
#include <ctype.h>

void lerString(char string[])
{
    int i = 0;  
    int contadoralfa = 0;
    int contadornum = 0;

    while (string[i] != '\0')
    {
        if (isalpha(string[i]))
        {
            contadoralfa++;
            i++;
        }
        else if(isdigit(string[i]))
        {
            contadornum++;
            i++;
        }
        else
        {
            i++;
        }
         
    }

    printf("\n");
    printf("Frase: %s\n", string);
    printf("A frase possui %d letras do alfabeto\n", contadoralfa);
    printf("E possui %d numeros.\n", contadornum);

}

int main ()
{
    char frase[30];

    printf("Digite uma frase qualquer: ");
    fgets(frase, 30, stdin);

    lerString(frase);

    return 0;
}