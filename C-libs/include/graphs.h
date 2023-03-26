#ifndef GRAPHS_H
#define GRAPHS_H

// type used to store graphs as adjacency matrices
typedef struct _graph_matrix
{
int** matrix;
int nb_vertices;
} graph_matrix;

// linked lists
struct _vertex_node
{
int data;
struct _vertex_node* suiv;
};

typedef struct _vertex_node* vertex_list; 

// used to store graphs as adjacency lists
typedef struct _graph_adjacency_lists
{
vertex_list* vertex_array; // array of lists of neighbors
int nb_vertices;
} graph_adjacency_lists;


/*--- Functions ---*/

/* Adjacency matrix */
graph_matrix read_adjacency_matrix(char* filename, int is_directed);
void print_matrix(int** matrix, int n);

/* Adjacency list */


#endif