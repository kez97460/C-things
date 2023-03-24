#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

// type used to store graphs
typedef struct _graph_matrix
{
int** matrix;
int nb_vertices;
} graph_matrix;

/* Functions */

graph_matrix read_adjacency_matrix(char* filename, int is_directed);
void print_matrix(int** matrix, int n);

#endif