#include <stdio.h>

int  elementosIguais(float matriz[3][5]) //Procedimento para verificar os elementos iguais

{
    int qtdIguais = 0, i, j, k, l; //Temos as variáveis para os for e para armazenar a quantidade de elementos iguais
    float matrizAuxiliar[3][5]; //Uma matriz auxiliar para verificar os números iguais

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matrizAuxiliar[i][j] = matriz[i][j]; //Aqui iremos colocar os valores da matriz principal na auxiliar
        }
    }

    for (i = 0; i < 3; i++) //Linha matriz principal
    {
        for (j = 0; j < 5; j++) //Coluna matriz principal
        {
            for (k = 0; k < 3; k++) //Linha matriz auxiliar
            { 
                for (l = 0; l < 5; l++) //Coluna matriz auxiliar
                {
                    /*Aqui iremos verificar se o valor da matriz principal é igual a da matriz auxiliar, e para evitar que a matriz leia a própria posição
                    faremos a verficação também para saber se a linha da matriz principal é diferente de linha da matriz auxiliar ou se a coluna da matriz principal
                    é diferente da coluna da matriz auxiliar*/
                    if ((matriz[i][j] == matrizAuxiliar[k][l]) && (i != k || j != l)) 
                    {
                        matrizAuxiliar[k][l] = 0; //Caso passe as verificações, o número na posição será substituido por 0
                    }           
                }           
            }       
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrizAuxiliar[i][j] == 0) //Aqui iremos verificar quantos 0 possuí a matriz, que são a quantidade de elementos iguais
            {
                qtdIguais++;
            }
            
        }   
    }

    return qtdIguais;
}

float menorElemento(float matriz[3][5]) //Aqui iremos verificar o menor valor da matriz
{
    float menor = matriz[0][0]; //Iremos atribuir o menor valor como sendo a primeira linha e primeira coluna da matriz
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matriz[i][j] < menor) //Caso tenha algum outro número menor que o menor número atribuído na variável, será substituído
            {
              menor = matriz[i][j];
            }
        }
    }

    return menor; 
}

int main()
{
    float matriz[3][5];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            do
            {
                printf("\nDigite os valores da posicao[%d][%d]: ", i, j);
                scanf("%f", &matriz[i][j]);
                
                /*Para não haver conflito na verificação de elementos iguais no caso da pessoa digitar 0, iremos bloquear o número 0 de ser digitado*/
                if (matriz[i][j] == 0) 
                {
                    printf("\nInvalido, nao pode ser 0.");
                    printf("\n");
                }
                
            } while (matriz[i][j] == 0);   
        }      
    }

    printf("\nNossa matriz: \n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%.2f\t", matriz[i][j]);
        } 

        printf("\n");   
    }

    printf("\nSendo o menor valor da expressão %.2f\n", menorElemento(matriz));
    printf("\nA quantidade de elementos iguais sao %d", elementosIguais(matriz));

    return 0;
}