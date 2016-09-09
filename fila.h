#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link ini;
  link fim;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inserirFim(FILA f, int e);
link inserirInicio(FILA f, int e);
int removerInicio(FILA f);
int removerFim(FILA f);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 

#endif 
