/* This main exists only for testing purposes */
#include <stdio.h>
#include <stdlib.h>
#include "weighted_graphs.h"

//////////////////////////////// ( fcts )


//////////////////////////////// ( main )

int main() 
{
char filename[] = "graphe_pondere_ei17.txt";
weighted_graph_matrix graph = read_adjacency_matrix_weighted(filename,0);
print_matrix_weighted(graph.matrix,graph.nb_vertices);
}





















	
		
		
	
	
	


