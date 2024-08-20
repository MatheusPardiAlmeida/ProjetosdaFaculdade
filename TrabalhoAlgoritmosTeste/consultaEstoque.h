//TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS - VE1, ENGENHARIA DE COMPUTAÇÃO 2023/1
//ALUNOS: Matheus Pardi Almeida e Enzo Natali

extern int estoqueGlobal[eMax]; //Estamos chamando o vetor da função principal para o header

void consultaEstoque()
{
  printf("\n---------------------------------------------------------------");
  printf("\nCONSULTA DE ESTOQUE\n");

  for (int i = 0; i < eMax; i++)
  {
    printf("\nQuantidade de estoque para o produto (%d): %d", i , estoqueGlobal[i]);
  }
  printf("\n---------------------------------------------------------------");
  //Nesse procedimento estamos fazendo a visualização da quantidade de produtos em cada vetor
}