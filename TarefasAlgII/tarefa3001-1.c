/*Roberval, aquele um estudante de Controle e Automação que queria criar um sistema controle de luzes de uma casa, está de volta.
Agora, ele pretende melhorar o sistema desenvolvido, colocando uma “memória”, que considera o estado da lâmpada após a execução anterior do programa. 
Por exemplo: se o programa anterior terminou com a lâmpada ligada, em uma nova execução, essa informação deve ser considerada. */

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
        d(); //Desligar
        *endLampada = 0;
    }
    else
    {
       l(); //Ligar
        *endLampada = 1;
    }

}

int main()
{
    int lampada = 0;
    
    FILE *arquivo;
    arquivo = fopen("lampada.txt", "a+");
    
    if (!arquivo)
    {
        printf("\nArquivo nao foi aberto!\n");
        return 1;
    }

    int estadoLampada;

    while (fscanf(arquivo, "%d", &estadoLampada) != EOF)
    {
        lampada = estadoLampada;
    }
    
    printf("\nEstado lampada apos leitura: %d", lampada);
    
    interruptor(&lampada, ligarLampada, desligarLampada);
    interruptor(&lampada, ligarLampada, desligarLampada);
    interruptor(&lampada, ligarLampada, desligarLampada);

    printf("\nUltimo valor lampada: %d", lampada);
    
    fprintf(arquivo, "%d\n", lampada);

    fclose(arquivo);


    return 0;
}