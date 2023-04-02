/* This main exists only for testing purposes */
#include <stdio.h>
#include <stdlib.h>
#include "weighted_graphs.h"
#include "graphs.h"
#include "heaps.h"

//////////////////////////////// ( fcts )


//////////////////////////////// ( main )

int main() 
{
Heap* h = create_heap();
insert_in_heap(h,create_element(0, 0.1));
insert_in_heap(h,create_element(3, 5));
insert_in_heap(h,create_element(2, 3.3));
insert_in_heap(h,create_element(1, 2.2));
insert_in_heap(h,create_element(4, 10));
heapElement e;
while (h->heapSize > 0)
{
    e = extract_heap_root(h);
    printf(" %d ",e.value);
}
printf("\n");
}





















	
		
		
	
	
	


