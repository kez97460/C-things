#include <stdio.h>
#include <stdlib.h>
#include "adjacency_matrix.h"

//////////////////////////////// ( fcts )


//////////////////////////////// ( main )

int main() 
{
char filename[] = "graphe_exemple.txt";
graph_matrix graph = read_adjacency_matrix(filename,0);
print_matrix(graph.matrix,graph.nb_vertices);
}





















	
		
		
	
	
	


