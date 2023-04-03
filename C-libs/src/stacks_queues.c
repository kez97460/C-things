#include <stdlib.h>
#include <stdio.h>
#include "stacks_queues.h"

Stack *empty_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    *stack = NULL;
    return stack;
}

int is_stack_empty(Stack *stack)
{
    return (*stack == NULL);
}

void push(Stack *stack, int data)
{
    Node *nouveau = (Node *)malloc(sizeof(Node));
    nouveau->data = data;
    nouveau->next = *stack;
    *stack = nouveau;
}

int pop(Stack *stack)
{
    if (is_stack_empty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = *stack;
    int data = temp->data;
    *stack = temp->next;
    free(temp);
    return data;
}

void print_stack(Stack *stack)
{
    if (is_stack_empty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    Node *temp = *stack;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Queue *empty_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->in = empty_stack();
    queue->out = empty_stack();
    return queue;
}

int is_queue_empty(Queue *queue)
{
    return (is_stack_empty(queue->in) && is_stack_empty(queue->out));
}

void enqueue(Queue *queue, int data)
{
    push(queue->in, data);
}

int dequeue(Queue *queue)
{
    if (is_queue_empty(queue))
    {
        printf("Queue is already empty\n");
        return -1;
    }
    if (is_stack_empty(queue->out))
    {
        while (!is_stack_empty(queue->in))
        {
            int data = pop(queue->in);
            push(queue->out, data);
        }
    }
    return pop(queue->out);
}
