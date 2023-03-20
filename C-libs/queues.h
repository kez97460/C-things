#ifndef QUEUES_H
#define QUEUES_H

// linked list implementation
typedef struct _q_node
{
int data ; // modifier si nécessaire
struct _q_node* next ;
} 
q_node ;

typedef q_node* q_list;

// queue defined by back(in) and front(out) -> back is a list and front a pointer to the last element
typedef struct _queue
{
q_list back ;
q_list front ;
}
queue ;

/*---Functions---*/

queue* empty_queue();
void enqueue(queue* q, int new_data);
int dequeue(queue* q);
void print_queue(queue* q);

#endif