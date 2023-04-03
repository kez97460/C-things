/* This main exists only for testing purposes */
#include <stdio.h>
#include <stdlib.h>
#include "weighted_graphs.h"
#include "graphs.h"
#include "heaps.h"
#include "stacks_queues.h"
#include "graph_search.h"

//////////////////////////////// ( fcts )


//////////////////////////////// ( main )

int main() 
{
char filename[] = "graphe_exemple.txt";
graph_matrix graph = read_adjacency_matrix(filename, 0);
print_matrix(graph.matrix,graph.nb_vertices);
int* dist = bfs_matrix(graph, 0);
for (int i = 0; i < graph.nb_vertices; i++)
{
    printf(" %d ",dist[i]);
}
printf("\n");
}


















	
		
		
	
	
	


