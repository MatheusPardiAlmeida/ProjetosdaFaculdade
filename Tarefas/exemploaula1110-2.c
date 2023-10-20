#include <stdio.h>
#define Lin 5
#define Col 6

int main()
{
    int matriz[Lin][Col], num, i, j;

    for (i = 0; i < Lin; i++) //Linha
    {
        for (j = 0; j < Col; j++) //Coluna
        {
            /*Utilizaremos a regra para verificação da matriz*/

            if (i == j) //Caso a posição da linha seja igual a da coluna, faremos isso.
            {
                matriz[i][j] = 7*i - 2;
            }
            else if (i > j) //Caso a posição da linha seja maior que a da coluna, faremos isso.
            {
                matriz[i][j] = 2*i - 8*j + 3;
            }
            else //Caso a posição da linha seja menor que a da coluna, faremos isso.
            {
                matriz[i][j] = 3*i + 2*j + 1;
            }
        }   
    }

    printf("Col 1\tCol 2\tCol 3\tCol 4\tCol 5\tCol 6\n"); //Faremos dessa forma para mostrar as colunas de forma tabelada

    for (i = 0; i < Lin; i++)
    {
        for (j = 0; j < Col; j++)
        {
            printf("%d\t", matriz[i][j]); //Utilizamos o \t para imprimir um do lado do outro
        }

        printf("\n"); //Assim iremos pular para próxima linha
        
    }
    
  return 0;
}