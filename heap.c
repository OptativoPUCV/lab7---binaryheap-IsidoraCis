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
  

    while((pq->heapArray[pq->size].priority) > (pq->heapArray[(pq->size-1)/2].priority))
      {
        int aux= pq->heapArray[(pq->size-1)/2].priority;
        pq->heapArray[(pq->size-1)/2].priority = pq->heapArray[pq->size].priority;
        pq->heapArray[pq->size].priority=aux;
      }
    pq->size++;
}


void heap_pop(Heap* pq){

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
