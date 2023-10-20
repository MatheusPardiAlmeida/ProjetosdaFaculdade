#include <stdio.h>

int main()
{

    int A,B,C;

    printf("\n");
    printf("\nDigite o valor de A: ");
    scanf("%d", &A);
    printf("\n");
    printf("\nDigite o valor de B: ");
    scanf("%d", &B);
    
    C = A; //Precisaremos de uma variável auxiliar para armazenar o valor de A
    A = B; //Como o valor de A receberá o valor de B, utilizaremos a variável auxiliar para que a inversão seja possível
    B = C; //Agora utilizaremos a variável auxiliar com o valor armazenado de A e daremos a variável B o valor de A

    printf("\nO valor de A %d e o valor de B %d", A,B);

    return 0;
}