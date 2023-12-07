/*Utilizar um procedimento que receba um ponteiro em void para imprimir o valor do ponteiro sem especificar o tipo*/
#include <stdio.h>
void receberPonteiro(void *ponteiro, char tipo)
{
    switch (tipo)
    {
        case 'I':
        printf("\nPonteiro apontando para x: %d", *(int*)*ponteiro);
        break;

        case 'F':
        printf("\nPonteiro apontando para y: %.2f", *(float*)ponteiro);
        break;
    
    }

}

int main()
{
    int x = 40;
    float y = 30.4;
    void *ponteiroA = &x;
    void *ponteiroB = &y;

    receberPonteiro(ponteiroA, 'I');
    receberPonteiro(ponteiroB, 'F');

    return 0;
}