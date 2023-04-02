/*
Authors : ChatGPT, Kezia Marcou

This library was made in 30 minutes using between 5 and 10 prompts.

To make this a max heap, modify the functions insert_in_heap and heapify as written in the definition
*/
#ifndef HEAPS_H
#define HEAPS_H

typedef struct heapElement
{
    int value;
    float priority;
} heapElement;

typedef struct Heap
{
    heapElement *heap;
    int heapSize;
    int maxSize;
} Heap;

/* Functions */
heapElement create_element(int val, float prio);
Heap* create_heap();
void destroy_heap(Heap* h);
void insert_in_heap(Heap* h, heapElement e);
heapElement extract_heap_root(Heap* h);
void resize_heap(Heap* h);
void print_heap(Heap *h);

#endif
