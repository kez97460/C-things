#ifndef STACKS_QUEUES_H
#define STACKS_QUEUES_H

typedef struct _node 
{
    int data;
    struct _node* next;
} Node;

typedef Node* Stack;

typedef struct _queue
{
    Stack* in;
    Stack* out;
} Queue;

// Stack functions
Stack* empty_stack();
int is_stack_empty(Stack* pile);
void push(Stack* pile, int data);
int pop(Stack* pile);
void print_stack(Stack* pile);

// Queue functions
Queue* empty_queue();
int is_queue_empty(Queue* file);
void enqueue(Queue* file, int data);
int dequeue(Queue* file);

#endif