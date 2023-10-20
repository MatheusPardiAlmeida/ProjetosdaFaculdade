#include <stdio.h>
#include <ctype.h>
#define TAM 40

int main()
{
    char texto[TAM];
    int vogais=0,consoantes=0, i=0;
   
    printf("\nDigite seu texto: ");
    gets(texto);

    do
    {
       texto[i] = tolower(texto[i]);
       
       if (isalpha(texto[i]) == 2)
       {

        if ((texto[i] == 97) || (texto[i] == 101) || (texto[i] == 105) || (texto[i] == 111) || (texto[i] == 117))
        {
            vogais++;
            i++;
        }
        else
        {
            consoantes++;
            i++;
        }
       
       }

       else
       {

        i++;

       }
       

    } while (texto[i] != 0);

    printf("\n");
    printf("\nQuantidade de vogais: %d", vogais);
    printf("\n");
    printf("\nQuantidade de consoantes: %d", consoantes);

    return 0;
}