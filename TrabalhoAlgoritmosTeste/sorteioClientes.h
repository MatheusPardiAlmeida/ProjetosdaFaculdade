//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "constantes.h" //Chamamos as constantes para este header
extern int clientes[cMax]; //Estamos chamando o vetor da função principal para o header

void sorteioClientes()
{
    //Aqui declaramos uma variável para armazenar o valor sorteado e uma variável para controlar o sorteio
    int i, contador = 0;
    srand(time(NULL));//a seed será o tempo do computador

        i = rand()%10;//o número gerado será um valor entre 0 e 9

        while (clientes[i] == 0 && contador < cMax)
        {
            i = rand()%10;//o número gerado será um valor entre 0 e 9
            contador++;
        }

        if (contador == cMax)
        {
            printf("\n---------------------------------------------------------------");
            printf("\n");
            printf("\nNenhum Undead possui debitos.");
            printf("\n");
            printf("\n---------------------------------------------------------------");
        }
        else
        {
            printf("\n---------------------------------------------------------------");
            printf("\n");
            printf("\nO Undead sorteado foi: %d", i);
            printf("\nParabens Undead (%d), seu debito foi absolvido.",i);
            printf("\n");
            printf("\n---------------------------------------------------------------");
            clientes[i] = 0;
        } 
        
    //Como no PDF pede para que o sorteio seja realizado até que uma pessoa com dívida seja sorteada
    //o laço será executado infinitamente caso não tenha ninguém com dívida, por isso eu tirei o laço de repetição
    //para que os sorteios ocorram um por vez sem que ocorra a repetição infinita

}