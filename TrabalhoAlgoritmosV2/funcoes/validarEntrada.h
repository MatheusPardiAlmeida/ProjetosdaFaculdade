#define buffer_tamanho 4096

bool validar_integer(char *string, int *integer)/*Iremos utilizar os endereços das variáveis string e integer para fazer a validação (pointer)*/
{
    int i = 0; /*Variável para verificar a posição que desejamos ler*/
    int tamanho = strlen(string); /*Temos uma variável para verificar o tamanho da string*/
    int integer_buffer = 0; /*Variável para indicar a posição no buffer*/
    char buffer[buffer_tamanho]; /*Temos um buffer em char para armazenar os valores válidos da string que será lida*/
    
    while (isspace(string[i])) /*Aqui faremos a verificação para saber se a posição da string sendo lida é uma espaço vazio (white space)*/
    {
        i++; 
    }
    
    if (tamanho == i) /*Caso o tamanho da string seja igual o número de i, então quer dizer que a entrada é vazia, logo retornará falso*/
    {
        return false;
    }

    if (string[i] == '-') /*Aqui iremos validar a entrada caso ela seja um número negativo*/
    {
        buffer[integer_buffer] = '-'; /*O buffer receberá o sinal negativo na posição indicada pelo integer_buffer*/
        integer_buffer++; /*Iremos incrementar o integer_buffer*/
        i++; /*Iremos incrementar a posição da string*/

        if (!isdigit(string[i])) /*Caso a próxima posição da string não seja um dígito, irá retornar falso*/
        {
            return false;
        }
    }

    while (i < tamanho && !isspace(string[i])) /*Enquanto a variável i for menor que o tamanho da string e não tenha white space na posição, será continuado o loop*/
    {
        if (!isdigit(string[i])) /*Caso não tenha nenhum digito na posição da string, irá retornar falso*/
        {
            return false;
        }

        buffer[integer_buffer] = string[i]; /*Caso passe a verificação e tenha um número, o buffer na posição
        na posição indicada pela variável integer_buffer, irá receber o valor armazenado na string na posição i*/

        integer_buffer++; /*Iremos incrementar a posição do buffer*/
        i++; /*Iremos incrementar também a posição da string*/

    }

    buffer[integer_buffer] = '\0'; /*Caso não tenha mais nenhum dígito, a próxima posição do buffer irá receber o código para NULL (condição de parada)*/

    while (isspace(string[i])) /*Após armazenar os dígitos no buffer, iremos percorrer o restante da string e verificar se possuí mais alguma coisa*/
    {
        i++;
    }

    if (string[i] != '\0') /*Caso tenha mais algum valor armazenado na string após o armazenamento de valores no buffer, irá retornar falso*/
    {
        /*Utilizaremos o underline para representar os white space*/
        /*EXEMPLO: _____50____10: isso é uma entrada inválida, pois temos dois integers e queremos apenas*/
        return false;
    }
     
    *integer = atoi(buffer); /*O endereço da variável integer irá receber o valor em inteiro da string que foi digitada pelo usuário*/
    /*Utilizando o "atoi", iremos conventer os valores armazenados em string para integer, sendo assim possível a leitura como um integer*/

    return true;    

}