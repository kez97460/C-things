#include <stdio.h>
#include <stdlib.h>
#include "heaps.h"

// Creates an empty heap
heap empty_heap()
{
heap res;
res.size = 0;
res.elements = (element*) malloc(BASE_SIZE * sizeof(element));
res.max_size = BASE_SIZE;
return res;
}

// swaps 2 variables, given their adresses
void swap(int *x, int *y) 
{
int temp = *x;
*x = *y;
*y = temp;
}

// defining children as 2n+1 and 2n+2 instead of 2n and 2n+1 allows the use of values[0].

int parent_index(int i) 
{
return (i - 1) / 2;
}
int left_child_index(int i) 
{
return 2 * i + 1;
}
int right_child_index(int i) 
{
return 2 * i + 2;
}

void insert(element vertex)
{

}