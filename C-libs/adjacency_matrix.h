
#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

int** 	read_graph_from_file(const char* file_name, int* nb_nodes, int* nb_edges);
void 	print_adjacency_matrix(int** adjacency_matrix, int nb_nodes);

#endif