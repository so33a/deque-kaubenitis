#include <stdio.h>
#include "fila.h"

int main () {
  FILA alunos = novaFila();
  inserirInicio(alunos, 9);
  inserirFim(alunos, 8);
  inserirInicio(alunos, 3);
  inserirFim(alunos, 10);

  imprimirFila(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", removerInicio(alunos));
  while(!filaVazia(alunos))
    printf ("removido: %d \n", removerFim(alunos));


  inserirInicio(alunos, 10);
  inserirFim(alunos, 32);
  
  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
