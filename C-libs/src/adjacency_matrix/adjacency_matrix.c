#include <stdio.h>
#include <stdlib.h>
#include "adjacency_matrix.h"

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

