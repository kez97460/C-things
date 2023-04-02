#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heaps.h"

#define BASE_HEAP_SIZE 100

heapElement create_element(int val, float prio)
{
    heapElement elem;
    elem.value = val;
    elem.priority = prio;
    return elem;
}

int left_child(int i)
{
    return 2 * i + 1;
}

int right_child(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void swap_heap_elements(heapElement *a, heapElement *b)
{
    heapElement temp = *a;
    *a = *b;
    *b = temp;
}

// modifies the heap to make sure the Element at index i is at the right place.
void heapify(Heap *h, int i)
{
    int smallest = i;
    int l = left_child(i);
    int r = right_child(i);

    if (l < h->heapSize && h->heap[l].priority </*>*/ h->heap[smallest].priority) // Invert for a Max heap
    {
        smallest = l;
    }

    if (r < h->heapSize && h->heap[r].priority </*>*/ h->heap[smallest].priority) // Invert for a Max heap
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap_heap_elements(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

Heap *create_heap()
{
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->heap = (heapElement *)malloc(BASE_HEAP_SIZE * sizeof(heapElement));
    h->heapSize = 0;
    h->maxSize = BASE_HEAP_SIZE;
    return h;
}

void destroy_heap(Heap *h)
{
    free(h->heap);
    free(h);
}

void resize_heap(Heap *h)
{
    heapElement *newHeap = (heapElement *)malloc((h->maxSize + BASE_HEAP_SIZE) * sizeof(heapElement));
    memcpy(newHeap, h->heap, h->heapSize * sizeof(heapElement));
    free(h->heap);
    h->heap = newHeap;
    h->maxSize += BASE_HEAP_SIZE;
}

void insert_in_heap(Heap *h, heapElement e)
{
    if (h->heapSize == h->maxSize)
    {
        resize_heap(h);
    }

    int current = h->heapSize;
    h->heap[h->heapSize] = e;
    h->heapSize++;

    while (current != 0 && h->heap[current].priority </*>*/ h->heap[parent(current)].priority) // Invert for a Max heap
    {
        swap_heap_elements(&h->heap[current], &h->heap[parent(current)]);
        current = parent(current);
    }
}

heapElement extract_heap_root(Heap *h)
{
    heapElement root = h->heap[0];
    h->heap[0] = h->heap[h->heapSize - 1];
    h->heapSize--;

    heapify(h, 0);

    return root;
}

// Builds a heap from an array of n Elements
void build_heap(Heap *h, heapElement *a, int n)
{
    h->heapSize = n;
    h->maxSize = n + BASE_HEAP_SIZE;
    h->heap = (heapElement *)malloc(h->maxSize * sizeof(heapElement));
    memcpy(h->heap, a, n * sizeof(heapElement));

    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(h, i);
    }
}

void print_heap(Heap *h)
{
    printf("Heap elements: ");
    for (int i = 0; i < h->heapSize; i++)
    {
        printf("(%d, %.1f) ", h->heap[i].value, h->heap[i].priority);
    }
    printf("\n");
}

