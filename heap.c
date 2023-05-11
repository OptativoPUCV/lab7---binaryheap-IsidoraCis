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
    if(pq->size== 0) return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
    if(pq->size == pq->capac)
    {
      pq->heapArray = realloc(pq->heapArray, sizeof(heapElem)	* (2 * pq->capac + 1)); 
    }
    pq->heapArray[pq->size].data = data;
    pq->heapArray[pq->size].priority= priority;
  
    int s = pq->size;
    int padre = (pq->size -1)/2;
    heapElem aux;
    while((pq->heapArray[s].priority) > (pq->heapArray[padre].priority))
      {
        aux= pq->heapArray[s];
        pq->heapArray[s] = pq->heapArray[padre];
        pq->heapArray[padre]=aux;

        s = padre;
        padre = (s-1)/2;
        
      }
    pq->size++;
}


void heap_pop(Heap* pq){
  if(pq->size == 0) return;
  pq->heapArray[0] = pq->heapArray[pq->size];

  int hijoIzq = (2*pq->size) + 1;
  int hijoDer = (2*pq->size) + 2;
  int actual= 0;
  heapElem aux;

  while(pq->heapArray[actual].priority < pq->heapArray[hijoIzq].priority || pq->heapArray[actual].priority < pq->heapArray[hijoDer].priority){
  //Caso izq
    if(pq->heapArray[actual].priority < pq->heapArray[hijoIzq].priority && pq->heapArray[actual].priority > pq->heapArray[hijoDer].priority)
    {
      aux = pq->heapArray[actual];
      pq->heapArray[actual] = pq->heapArray[hijoIzq];
      pq->heapArray[hijoIzq] = aux;

      actual = hijoIzq;
      hijoIzq =  (2*actual) + 1;
      hijoDer = (2*actual) + 2;
    }

  //Caso der
    if(pq->heapArray[actual].priority > pq->heapArray[hijoIzq].priority && pq->heapArray[actual].priority < pq->heapArray[hijoDer].priority)
    {
      aux = pq->heapArray[actual];
      pq->heapArray[actual] = pq->heapArray[hijoDer];
      pq->heapArray[hijoDer] = aux;

      actual = hijoDer;
      hijoIzq =  (2*actual) + 1;
      hijoDer = (2*actual) + 2;
    }
  }
  pq->size--;
}

Heap* createHeap(){
  Heap* h =(Heap *) malloc(sizeof(Heap));
  h->capac = 3;
  h->size = 0;
  h->heapArray = (heapElem*) malloc(sizeof(heapElem) * h->capac);
  h->heapArray->data = NULL;
  h->heapArray->priority = 0;
   return h;
}
