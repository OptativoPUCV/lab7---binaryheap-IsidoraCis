#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* h =(Heap *) malloc(sizeof(Heap));
  h->capac = 3;
  h->heapArray = (heapElem*) malloc(sizeof(heapElem));
  h->heapArray->data = NULL;
  h->heapArray->priority = 0;
   return h;
}
