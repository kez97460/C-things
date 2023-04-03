#include <stdio.h>
#include <stdlib.h>
#include "stacks_queues.h"
#include "graphs.h"

// Breadth first search in an adjacency matrix
int *bfs_matrix(graph_matrix g, int start_node)
{
    int *visited = (int *)malloc(g.nb_vertices * sizeof(int));
    int *distances = (int *)malloc(g.nb_vertices * sizeof(int));
    for (int i = 0; i < g.nb_vertices; i++)
    {
        visited[i] = 0;
        distances[i] = -1;
    }
    visited[start_node] = 1;
    distances[start_node] = 0;

    Queue *q = empty_queue();
    enqueue(q, start_node);

    while (!is_queue_empty(q))
    {
        int current_node = dequeue(q);
        for (int j = 0; j < g.nb_vertices; j++)
        {
            if (g.matrix[current_node][j] == 1 && !visited[j])
            {
                visited[j] = 1;
                distances[j] = distances[current_node] + 1;
                enqueue(q, j);
            }
        }
    }
    free(q);
    free(visited);
    return distances;
}

// 
void dfs_visit_matrix(graph_matrix g, int current_node, int *visited)
{
    visited[current_node] = 1;
}

int* dfs_matrix(graph_matrix g, int start_node)
{
    int *visited = (int *)malloc(g.nb_vertices * sizeof(int));
    for (int i = 0; i < g.nb_vertices; i++)
    {
        visited[i] = 0;
    }

    Stack *s = empty_stack();
    push(s, start_node);

    while (!is_stack_empty(s))
    {
        int current_node = pop(s);

        if (!visited[current_node])
        {
            dfs_visit_matrix(g, current_node, visited);
            for (int j = 0; j < g.nb_vertices; j++)
            {
                if (g.matrix[current_node][j] == 1 && !visited[j])
                {
                    push(s, j);
                }
            }
        }
    }
    free(s);
    return visited;
}