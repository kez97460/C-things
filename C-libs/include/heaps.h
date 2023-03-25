#ifndef HEAPS_H
#define HEAPS_H

// Elements in the heap have a priority and a number usually associated with a vertex in a graph (use: Djikstra, A*...)
typedef struct _element
{
int vertex_number;
float priority;
} element;

typedef struct _heap
{
int size;
int max_size;
element* elements;
} heap;

#define BASE_SIZE 64
// When a heap is initialised, its size is set to BASE_SIZE. 
// When it would overflow, it is instead copied in another heap which is twice as big.

/* Functions */
heap empty_heap();


#endif
