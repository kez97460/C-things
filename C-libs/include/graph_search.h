/*
This library has dependencies : stacks_queues and graphs.



*/

#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include "stacks_queues.h"
#include "graphs.h"

int *bfs_matrix(graph_matrix g, int start_node);
int* dfs_matrix(graph_matrix g, int start_node);

#endif