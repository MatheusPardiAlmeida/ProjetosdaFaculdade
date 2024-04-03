#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

} calendario;

int main()
{
    calendario *data;

    data = (calendario*) malloc(sizeof(calendario));

    data->ano = 2024;
    data->mes = 2;
    data->dia = 6;

    printf("\nDia: %d, Mes: %d, Ano: %d", data->dia, data->mes, data->ano);

    free(data);

    return 0;
}