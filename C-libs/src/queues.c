#include "queues.h"
#include <stdlib.h>
#include <stdio.h>

q_list new_node(int data)
{
q_list res = (q_list) malloc(sizeof(q_node));
res->data = data;
res->next = NULL;
return res;
}

queue* empty_queue()
{
queue* res = (queue*) malloc(sizeof(queue));
res->front = NULL;
res->back = NULL;
return res;
}

void enqueue(queue* q, int new_data)
{
q_list temp = new_node(new_data);
if( q->back == NULL )
{
    q->back = temp;
    q->front = temp;
    return;
}
q->back->next = temp;
q->back = temp;
}

int dequeue(queue* q)
{
if(q->front == NULL)
{
    printf("Warning : removing value from empty queue. Nothing happened.");
    return -1; // put an impossible value here
}
q_list temp = q->front;
q->front = q->front->next;
if(q->front == NULL)
{
    q->back = NULL;
}
int res = temp->data;
free(temp);
return res;
}

// Warning : takes the queue itself as input, and not a pointer, in order to not modify it.
void print_queue_aux(queue q)
{
printf("<-{");
while(q.front != NULL)
    {
    printf(" %d ",(q.front)->data);
    q.front = (q.front->next);
    }
printf("}<-\n");
}

void print_queue(queue* q)
{
print_queue_aux(*q); // to make a local copy.
}
