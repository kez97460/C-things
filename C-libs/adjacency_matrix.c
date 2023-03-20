/*-----------------------------------------------------------------------------------------------

Load an undirected graph from a given file into an adjacency matrix.

-----------------------------------------------------------------------------------------------*/

#include "stdio.h"
#include "stdlib.h"
#include "adjacency_matrix.h"

int** 	read_graph_from_file(const char* file_name, int* nb_nodes, int* nb_edges);
void 	print_adjacency_matrix(int** adjacency_matrix, int nb_nodes);

int** read_graph_from_file(const char* file_name, int* nb_nodes, int* nb_edges) 
{
	FILE *fp = fopen(file_name, "r");
	fscanf(fp, "%d %d", nb_nodes, nb_edges);

	int nb_nodes_val = *nb_nodes;
	int nb_edges_val = *nb_edges;

 	int** adjacency_matrix = (int**) malloc(nb_nodes_val*sizeof(int*));

	for (int i = 0; i < nb_nodes_val; i++) 
	{			
		adjacency_matrix[i] = (int*) malloc(nb_nodes_val*sizeof(int)); 
		for (int j = 0; j < nb_nodes_val; j++)
			adjacency_matrix[i][j] = 0; 
	}

	for (int i = 0; i < nb_edges_val; i ++) 
	{	
		int u, v;
		fscanf(fp, "%d %d", &u, &v);
		adjacency_matrix[u-1][v-1] = 1;
		adjacency_matrix[v-1][u-1] = 1;
	}

	fclose(fp);
	return adjacency_matrix;
}

void print_adjacency_matrix(int** adjacency_matrix, int nb_nodes)
{
	for (int i = 0; i < nb_nodes; i++) 
	{
		for (int j = 0; j < nb_nodes; j++)
			printf("%d ", adjacency_matrix[i][j]); 
		printf("\n" ); 
	}
}
