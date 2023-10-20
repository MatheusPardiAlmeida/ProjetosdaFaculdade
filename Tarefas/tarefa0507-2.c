#include <stdio.h>

int main()
{

    int dia, anos, meses, diasSobrou;

    do
    {

    printf("\n");
    printf("\nInsira a sua idade em dias: ");
    scanf("%d", &dia);

    if (dia < 1)
    {
        printf("\n");
        printf("\nDia invalido, faca novamente.");
    }

    }while(dia < 1);

    anos = dia/365; //Aqui faremos a divisão para saber quantos anos teremos, isso não irá alterar o valor da variável dia
    diasSobrou = dia%365; //Através do operador %, iremos descobrir quantos dias sobraram após a divisão dos dias para anos
    //LEMBRANDO QUE: a variável diasSobrou recebe o resto da divisão de dia/365

    meses = diasSobrou/30; //Com o restante dos dias que sobraram, descobriremos quantos meses teremos
    diasSobrou = diasSobrou%30; //Agora iremos utilizar novamente o operador % para descobrir quantos dias sobraram após a divisão dos meses
    //LEMBRANDO QUE: a variável diasSobrou nessa parte da função irá receber o resto da divisão de diasSobrou/30, sendo que a variável diasSobrou
    //recebeu anteriormente o resto da divisão de dia/365

    printf("\n");
    printf("\nIdade: %d anos, %d meses e %d dias.", anos, meses, diasSobrou);
    
    return 0;

}