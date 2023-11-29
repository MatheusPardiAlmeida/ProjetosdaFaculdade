/*Sem utilizar função ou procedimento, ou seja, implementando apenas na função
principal (int main), escreva um algoritmo que cadastre um nome de usuário e senha. Em seguida, simule a ação do login, ou seja, solicite ao usuário que ele insira um
nome de usuário e a senha cadastrada. O usuário terá até 3 tentativas, caso esgote as
tentativas, encerre o programa. Utilize a biblioteca string.h.*/
#include <stdio.h>
#include <string.h>
#define buffer 4096

int main()
{
    int contador;
    int tentativa;
    char nomeusuario[buffer];
    char senhausuario[buffer];
    char auxiliarnome[buffer];
    char auxiliarsenha[buffer];

    printf("Cadastre seu nome de usuario: ");
    fgets(nomeusuario, buffer, stdin);

    printf("Cadastre sua senha: ");
    fgets(senhausuario, buffer, stdin);
    
    printf("\n");
    printf("LOGIN:\n");

    do
    {
        contador = 0;
        tentativa = 0;

        printf("Insira seu nome de usuario: ");
        fgets(auxiliarnome, buffer, stdin);

        if (tentativa == 2)
        {
            printf("Voce excedeu o numero de tentativas, finalizando programa.......\n");
            return 0;
        }
        else if (strcmp(nomeusuario, auxiliarnome) != 0)
        {
            tentativa++;
            
            printf("\n");
            printf("Nome de usuario incorreto, tente novamente.\n");
            printf("%d tentativas restante.\n", (tentativa+1));
            printf("\n");
        }
        else
        {
            contador = 1;
        }
        
    } while (contador == 0);

    do
    {
        contador = 0;
        tentativa = 0;

        printf("\n");
        printf("Digite sua senha: ");
        fgets(auxiliarsenha, buffer, stdin);

        if (tentativa == 2)
        {
            printf("Voce excedeu o numero de tentativas, finalizando programa.......\n");
            return 0;
        }
        else if (strcmp(senhausuario, auxiliarsenha) != 0)
        {
            tentativa++;
            
            printf("\n");
            printf("Senha de usuario incorreta, tente novamente.\n");
            printf("%d tentativas restante.\n", (tentativa+1));
            printf("\n");
        }
        else
        {
            contador = 1;
        }
        
    } while (contador == 0);
    
    printf("\n");
    printf("Login finalizado com sucesso.\n");
    printf("Finalizando programa......\n");

    return 0;
}