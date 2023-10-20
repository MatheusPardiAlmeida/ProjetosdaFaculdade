//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

#include "constantes.h" //Chamamos as constantes para este header
extern double clientes[cMax]; //Estamos chamando o vetor da função principal para o header

void sorteioClientes()
{
    //Aqui declaramos uma variável para armazenar o valor sorteado e uma variável para controlar o sorteio
    int i;
    srand(time(NULL));//a seed será o tempo do computador

        i = rand()%10;//o número gerado será um valor entre 0 e 9

        if (clientes[i] == 0)
        { 
            printf("\nO cliente %d nao tem debitos!", i);
            printf("\n");
        }

        else
        {
            printf("\nO cliente sorteado foi: %d", i);
            printf("\nParabens cliente %d, seu debito foi absolvido",i);
            printf("\n");
            clientes[i] = 0;
        }

    //Como no PDF pede para que o sorteio seja realizado até que uma pessoa com dívida seja sorteada
    //o laço será executado infinitamente caso não tenha ninguém com dívida, por isso eu tirei o laço de repetição
    //para que os sorteios ocorram um por vez sem que ocorra a repetição infinita

}