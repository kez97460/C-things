#include <stdio.h>
#include <stdlib.h>
#include "weighted_graphs.h"

// reads a graph from a file, and creates an adjacency matrix. The name of the vertices should be ints starting from 0.
weighted_graph_matrix read_adjacency_matrix_weighted(char* filename, int is_directed)
{
FILE* file = fopen(filename,"r");
if(file == NULL)
    {
    printf("Error : could not read from file %s \n",filename);
    weighted_graph_matrix graph;
    return graph; // this is just an empty graph;
    }
// read the number of vertices from file
int nb_vertices;
fscanf(file,"%d",&nb_vertices); 
// allocating memory for the adjacency matrix
weighted_graph_matrix graph;
graph.nb_vertices = nb_vertices;
graph.matrix = (float**) malloc(nb_vertices * sizeof(float*));
for(int i = 0; i < nb_vertices; i++)
    {
    graph.matrix[i] = (float*) malloc(nb_vertices * sizeof(float));
    }
// fill the matrix
for(int i = 0; i < nb_vertices; i++)
    {
    for(int j = 0; j < nb_vertices; j++)
        {
        graph.matrix[i][j] = -1; // initialize weights to -1 (impossible)
        }
    }
int i,j; 
float weight;
while(fscanf(file,"%d %d %f",&i,&j,&weight) > 0)
    {
    graph.matrix[i][j] = weight;
    if(!is_directed) // if the graph is undirected
        {
        graph.matrix[j][i] = weight;
        }
    }
fclose(file);
return graph;
}

// prints a square matrix (2 dimensional array with nb_lines == nb_columns)
void print_matrix_weighted(float** matrix, int n)
{
for(int i = 0; i < 2*n; i++) printf("-"); // looks good
printf("\n");
for(int i = 0; i < n; i++)
    {
    for(int j = 0; j < n; j++)
        {
        printf("%.1f ",matrix[i][j]);
        }
    printf("\n");
    }
for(int i = 0; i < 2*n; i++) printf("-"); // looks good
printf("\n");
}
