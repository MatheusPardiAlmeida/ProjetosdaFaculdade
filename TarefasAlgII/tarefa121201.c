/*Roberval é um estudante de Controle e Automação que deseja criar um sistema controle de luzes de uma casa. 
Para começar, ele pretende criar procedimentos para ligar e desligar as luzes.
Um terceiro procedimento, que simula um interruptor, recebe os endereços de memória dos procedimentos ligar e desligar. 
Se a lâmpada estava desligada, o procedimento deve ligá-la quando acionada. Da mesma forma, se ela estivesse desligada, o procedimento deveria desligar a luz.*/

#include <stdio.h>
#include <stdlib.h>

void ligarLampada()
{
   printf("\nA lampada ligou");
      
}

void desligarLampada()
{
    printf("\nA lampada desligou");

}

void interruptor(int *endLampada,void (*l)(), void (*d)())
{

    if (*endLampada == 1)
    {
        d();
        *endLampada = 0;
    }
    else
    {
       l();
        *endLampada = 1;
    }

}

int main()
{
    int lampada = 0;

    interruptor(&lampada, ligarLampada, desligarLampada);              
    interruptor(&lampada, ligarLampada, desligarLampada);
    interruptor(&lampada, ligarLampada, desligarLampada); 
    interruptor(&lampada, ligarLampada, desligarLampada);  

    return 0;
}