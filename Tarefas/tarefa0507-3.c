#include <stdio.h>
#define Lucro 0.45
#define Imposto 0.20
//Definimos valores para os termos Lucro e Imposto, para facilitar na hora da multiplicação 

int main()
{
    int i=0;
    float custoProducao, custoImposto, porcentagemLucro;

    
    do
    { //Aqui teremos um laço de repetição para que o usuário digite um valor maior que 0

      printf("\n");
      printf("\nNos diga o custo de producao do caminhao: R$");
      scanf("\n%f", &custoProducao);

      if (custoProducao < 1)
      {
        printf("\n");
        printf("\nValor invalido, faca novamente.");
      }
      else
      {
        i = 1;
      }
      
    } while (i == 0);    
    
    custoImposto = custoProducao*Imposto; //Aqui será feito o cálculo para o custo do imposto

    porcentagemLucro = custoProducao*Lucro; //Aqui será feito o cálculo para a porcentagem de lucro

    printf("\n");
    printf("\nO preco final sera de: R$%.2f", (custoProducao+custoImposto+porcentagemLucro)); 
    //Ao invés de utilizarmos uma variável auxiliar para fazer a soma de todos os valores, podemos fazer a soma direto no printf

    return 0;
}