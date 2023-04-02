#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

/********************/
/* Adjacency matrix */
/********************/

// reads a graph from a file, and creates an adjacency matrix. The name of the vertices should be ints starting from 0.
graph_matrix read_adjacency_matrix(char* filename, int is_directed)
{
FILE* file = fopen(filename,"r");
if(file == NULL)
    {
    printf("Error : could not read from file %s \n",filename);
    graph_matrix graph;
    graph.nb_vertices = 0;
    graph.matrix = (int**) malloc(sizeof(int*)); 
    graph.matrix[0] = (int*) malloc(sizeof(int));
    return graph; // this is just an empty graph;
    }
// read the number of vertices from file
int nb_vertices;
fscanf(file,"%d",&nb_vertices); 
// allocating memory for the adjacency matrix
graph_matrix graph;
graph.nb_vertices = nb_vertices;
graph.matrix = (int**) malloc(nb_vertices * sizeof(int*));
for(int i = 0; i < nb_vertices; i++)
    {
    graph.matrix[i] = (int*) malloc(nb_vertices * sizeof(int));
    }
// fill the matrix
int i,j; 
while(fscanf(file,"%d %d",&i,&j) > 0)
    {
    graph.matrix[i][j]++;
    if(!is_directed) // if the graph is undirected
        {
        graph.matrix[j][i]++;
        }
    }
fclose(file);
return graph;
}

// prints a square matrix (2 dimensional array with nb_lines == nb_columns)
void print_matrix(int** matrix, int n)
{
for(int i = 0; i < 2*n; i++) printf("-"); // looks good
printf("\n");
for(int i = 0; i < n; i++)
    {
    for(int j = 0; j < n; j++)
        {
        printf("%d ",matrix[i][j]);
        }
    printf("\n");
    }
for(int i = 0; i < 2*n; i++) printf("-"); // looks good
printf("\n");
}

/******************/
/* Adjacency list */
/******************/

// add an element to a list of neighbors
void add_neighbor(vertex_list* list_pointer , int vertex) 
{
vertex_list nouveau = (vertex_list) malloc(sizeof(struct _vertex_node));
nouveau->data = vertex;
nouveau->suiv = *list_pointer;
*list_pointer = nouveau;
}

// delete head from list of neighbors
void delete_head_neighbor(vertex_list* list_pointer) 
{
*list_pointer = (*list_pointer)->suiv;
}

// reads a graph from a file, and creates an adjacency list array. The name of the vertices should be ints starting from 0.
graph_adjacency_lists read_adjacency_lists(char* filename, int is_directed)
{
FILE* file = fopen(filename,"r");
if(file == NULL)
    {
    printf("Error : could not read from file %s \n",filename);
    graph_adjacency_lists graph;
    graph.nb_vertices = 0;
    graph.vertex_array = NULL;
    return graph; // this is just an empty graph;
    }
// read the number of vertices from file
int nb_vertices;
fscanf(file,"%d",&nb_vertices); 
// allocating memory for the adjacency lists
graph_adjacency_lists graph;
graph.nb_vertices = nb_vertices;
graph.vertex_array = (vertex_list*) malloc(nb_vertices * sizeof(vertex_list));
for(int i = 0; i < nb_vertices; i++)
    {
    graph.vertex_array[i] = NULL; // make empty lists of neighbors 
    }
// fill the adjacency lists
int i,j; 
while(fscanf(file,"%d %d",&i,&j) > 0)
    {
    add_neighbor(&graph.vertex_array[i],j); // add j to i's neighbors
    if(!is_directed) // if the graph is undirected
        {
        add_neighbor(&graph.vertex_array[j],i); // add i to j's neighbors
        }
    }
fclose(file);
return graph;
}

void print_adjacency_lists(graph_adjacency_lists graph)
{
int length = graph.nb_vertices;
printf("----------\n"); // looks good
for(int i = 0; i < length; i++)
{
    printf("%d - (",i);
    vertex_list tete = (graph.vertex_array[i]);
    while(tete != NULL)
    {
        printf(" %d ",tete->data);
        delete_head_neighbor(&tete);
    }
    printf(")\n");
}
printf("----------\n"); // looks good
}