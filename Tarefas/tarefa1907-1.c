#include <stdio.h>
#include <ctype.h>

/*Utilizando o switch case, desenvolva um código que leia uma letra (caracter) e
informe se é uma vogal ou consoante. Desconsidere a possibilidade do usuário digitar
números e símbolos.*/

int main()
{
    /*Aqui temos as nossas variáveis de controle e outra para determinar a posicao do nosso vetor*/
    int ctrlLoop, i=0;
    char palavra[50];

    printf("\nDigite uma palavra qualquer: ");
    gets(palavra); /*Utilizamos o gets para ler o vetor, já que assim o vetor irá ler os espaços entre as palavras também*/

    do
    {
        ctrlLoop = 1; /*Aqui teremos o controle do loop, e o valor sempre ficará em 1, caso a letra não seja do alfabeto, irá voltar o valor para 0 e o loop iniciará novamente*/
        palavra[i] = tolower(palavra[i]); /*Colocamos as letras em minúscula para facilitar a identificação*/
        
        if (isalpha(palavra[i]) == 2) /*Caso seja uma letra do alfabeto, fará a verificação para saber se é vogal ou consoante.*/
        {
            if ((palavra[i] == 97) || (palavra[i] == 101) || (palavra[i] == 105) || (palavra[i] == 111) || (palavra[i] == 117))
            {
                printf("\nA letra %c e vogal.", palavra[i]); /*E aqui mostrará a letra que é vogal ou consoante*/
            }
            else
            {
                printf("\nA letra %c e consoante.", palavra[i]);
            }                    
        }
        else
        {
           i++;
           ctrlLoop = 0;
        }

    } while (ctrlLoop == 0);

    return 0;
}