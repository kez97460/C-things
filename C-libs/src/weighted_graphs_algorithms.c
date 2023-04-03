#include <stdio.h>
#include <stdlib.h>
#include "weighted_graphs_algorithms.h"
#include <limits.h>

float* dijkstra(weighted_graph_matrix graph, int start_node)
{
{
    int *visited = (int *)malloc(g.nb_vertices * sizeof(int));
    distance_element *distances = (distance_element *)malloc(g.nb_vertices * sizeof(distance_element));
    for (int i = 0; i < g.nb_vertices; i++)
    {
        visited[i] = 0;
        distances[i].distance = -1;
    }
    visited[start_node] = 1;
    distances[start_node] = 0;

    Heap* h = create_heap();
    insert_in_heap(h,create_element(start_node,0))

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

}