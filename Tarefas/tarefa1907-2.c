#include <stdio.h>

int main()
{
    int mes, ctrlLoop;

  do
  {
    ctrlLoop = 1;

    printf("\n");
    printf("\nInsira um numero para dizer o mes: ");
    scanf("%d", &mes);
    
    switch (mes)
    {
        case 1:

        printf("\n");
        printf("\nJaneiro.");
        
        break;

        case 2:

        printf("\n");
        printf("\nFevereiro.");
        
        break;

        case 3:

        printf("\n");
        printf("\nMarco.");
        
        break;

        case 4:

        printf("\n");
        printf("\nAbril.");
        
        break;

        case 5:

        printf("\n");
        printf("\nMaio.");
        
        break;

        case 6:

        printf("\n");
        printf("\nJunho.");
        
        break;

        case 7:

        printf("\n");
        printf("\nJulho.");
        
        break;

        case 8:

        printf("\n");
        printf("\nAgosto.");
        
        break;

        case 9:

        printf("\n");
        printf("\nSetembro.");
        
        break;

        case 10:

        printf("\n");
        printf("\nOutubro.");
        
        break;

        case 11:

        printf("\n");
        printf("\nNovembro.");
        
        break;

        case 12:

        printf("\n");
        printf("\nDezembro.");
        
        break;
    
        default:

        printf("\n");
        printf("\nInvalido, tente novamente.");
        ctrlLoop = 0;

        break;
    }

  } while(ctrlLoop == 0);

  return 0;

}