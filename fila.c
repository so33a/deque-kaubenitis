#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->fim = f->ini = NULL;
  return f;
}

void inserirFim(FILA f, int e) {
  if(f->ini == NULL) {
    f->ini = f->fim = novoNo(e, NULL);
  } else {
    f->fim->next = novoNo(e, NULL);
    f->fim = f->fim->next;
  }
}

void inserirInicio(FILA f, int e){
  if(f->ini == NULL) {
    f->ini = f->fim = novoNo(e, NULL);
  } else {
    f->ini = novoNo(e, NULL);
    f->ini = f->ini->next;
  }
}

int removerInicio(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->ini->item;
  t = f->ini;
  f->ini = f->ini->next;
 
  if(f->ini == NULL)
    f->fim = NULL;

  free(t);
  return x;
}
int removerFim(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  x = f->fim->item;
  t = f->fim;
 // f->ini = f->ini->next;
 
  if(f->ini == NULL)
    f->fim = NULL;

  free(t);
  return x;
}


int filaVazia(FILA f) {
  return ((f->fim == NULL) || (f->ini == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->ini; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

