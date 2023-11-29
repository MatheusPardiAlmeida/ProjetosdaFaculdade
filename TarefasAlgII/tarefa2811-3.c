/*Maria Gláucia trabalha no departamento de recursos humanos de uma empresa que aumentará o salário dos seus funcionários. O programa lida com as seguintes informações:
código do departamento, representado por um número inteiro de 1 a 5;
salário do funcionário, representado por um número real;
Para funcionários dos departamentos 1 e 2, o aumento será de 22%. Para os funcionários do departamento 3, o aumento será de 17%.
Para os funcionários do departamento 4 e 5, o aumento de salário será de 10%.
Considerando as informações anteriores, implemente um programa com uma função que altera o novo salário dos funcionários,
considerando o salário atual, o reajuste e o departamento de atuação. 
Ao final, imprima os valores de salário reajustados.*/

#include <stdio.h>
#include <stdlib.h>

float ajusteSalario(float *salario, int codDepartamento)
{
    switch (codDepartamento)
    {
        case 1:
        case 2:
        *salario += (*salario*0.22);
        break;

        case 3:
        *salario += (*salario*0.17);
        break;

        case 4:
        case 5:
        *salario += (*salario*0.10);
        break;
    
    }

    return *salario;
}

int main()
{
    int ctrlLoop;
    int codDepartamento;
    float salario;
    float novoSalario;

    do
    {
        ctrlLoop = 1;
        salario = 0.0;
        novoSalario = 0.0;

      do
      {
        printf("\n");
        printf("Digite o codigo do seu departamento (1-5): ");
        scanf("%d", &codDepartamento);

        if (codDepartamento < 1 || codDepartamento > 5)
        {
            printf("\n");
            printf("Codigo invalido, tente novamente.\n");
        }
        
      } while (codDepartamento < 1 || codDepartamento > 5);

      do
      {
        printf("\n");
        printf("Digite o seu salario: R$");
        scanf("%f", &salario);

        if (salario <= 0)
        {
            printf("\n");
            printf("Codigo invalido, tente novamente.\n");
        }
        
      } while (salario <= 0);

      novoSalario = ajusteSalario(&salario, codDepartamento);
      
      printf("\n");
      printf("Seu novo salario sera de: R$%.2f", novoSalario);   

      printf("\n");
      
      do
      {
        printf("\n");
        printf("Digite 1 para continuar ou 0 para encerrar o programa.\n");
        printf("Deseja continuar?: ");
        scanf("%d", &ctrlLoop);
        
        if (ctrlLoop > 1 || ctrlLoop < 0)
        {
            printf("\n");
            printf("Codigo invalido, tente novamente.\n");
        }
        if (ctrlLoop == 0)
        {
            printf("\n");
            printf("Encerrando programa...........\n");
        }
        
      } while (ctrlLoop > 1 || ctrlLoop < 0);
      
    } while (ctrlLoop == 1);
    
    return 0;
}