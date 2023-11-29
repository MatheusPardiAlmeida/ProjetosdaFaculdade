/*Sem utilizar função ou procedimento, ou seja, implementando apenas na função
principal (int main), desenvolva um código leia um vetor de caracteres em letras
minúsculas e transforme todas as letras desse vetor em maiúsculas, sem utilizar um
vetor auxiliar. Ou seja, a modificação deve ser feita no próprio vetor que contém a
string. Utilize a biblioteca ctype.h*/
#include <stdio.h>
#include <ctype.h>
#define buffer 4096

int main()
{
    int i;
    int j = 0;
    char string[buffer];
    
    do
    {
        i = 0;

        printf("Digite a frase em letra minuscula: ");
        fgets(string, buffer, stdin);
        
        while (string[i] != '\0')
        {
            if (string[i] == '\n')
            {
                string[i] = '\0';
                i = 0;
                break;
            }  
            else
            {
                i++;
            }       
        }
        

        while (string[i] != '\0')
        {
            if (isspace(string[i]))
            {
                i++;
            }
            else if (islower(string[i]) == 0)
            { 
                printf("\n");
                printf("A frase nao eh totalmente minuscula, ou possui caracteres diferentes.\n");
                printf("\n");
            }
            else
            {
                i++;
            } 
        }
        
    } while (string[i] != '\0');

    while (string[j] != '\0')
    {
        string[j] = toupper(string[j]);
        j++;
    }
    
    printf("\n");
    printf("A frase agora eh: %s", string);

    return 0;
}