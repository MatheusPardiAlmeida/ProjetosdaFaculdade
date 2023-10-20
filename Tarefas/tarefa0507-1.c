#include <stdio.h>

int resultadoIdade(int anos, int meses, int dias)
{
  int diasTotal=0;

  //Aqui faremos uma conta básica de multiplicação

  diasTotal = diasTotal + (anos*365); 
  //Faremos a multiplicação para descobrir a transformação de anos em dias

  diasTotal = diasTotal + (meses*30); 
  //Agora que a variável diasTotal recebeu o valor da multiplicação de anos*365, faremos a soma desse resultado 
  //com a soma da multiplicação de meses*30

  diasTotal = diasTotal + dias;
  //Agora faremos a soma do resultado anterior das operações com o número de dias

  return diasTotal;
}

int main()
{
    int ano, mes, dia;

    printf("\n");
    printf("\nPrecisamos que insira sua idade, em anos, meses e dia!");
    
    do
    {
        printf("\nAnos: ");
        scanf("%d", &ano);

        if (ano < 0)
        {
        printf("\nNumero invalido, faca novamente.");
        printf("\n");
        }

    } while (ano < 0);

    do
    {
        printf("\nMeses: ");
        scanf("%d", &mes);

        if ((mes < 1) || (mes > 12))
        {
        printf("\nNumero invalido, faca novamente.");
        printf("\n");
        }

    } while ((mes < 1) || (mes > 12));

    do
    {
        printf("\nDias: ");
        scanf("%d", &dia);

        if ((dia < 0) || (dia > 30))
        {
        printf("\nNumero invalido, faca novamente.");
        printf("\n");
        }

    } while ((dia < 0) || (dia > 30));
    
    printf("\n");
    printf("\nO total de dias e de: %d", resultadoIdade(ano,mes,dia));

    return 0;
}