#ifndef WEIGHTED_GRAPHS_H
#define WEIGHTED_GRAPHS_H

// type used to store graphs
typedef struct _weighted_graph_matrix
{
float** matrix; // matrix containing weights
int nb_vertices;
} weighted_graph_matrix;

/* Functions */

weighted_graph_matrix read_adjacency_matrix_weighted(char* filename, int is_directed);
void print_matrix_weighted(float** matrix, int n);

#endif