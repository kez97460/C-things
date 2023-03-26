#include <stdlib.h>
#include <stdio.h>
#include "piles_files.h"

Pile* pile_vide() 
{
    Pile* pile = (Pile*)malloc(sizeof(Pile));
    *pile = NULL;
    return pile;
}

int pile_est_vide(Pile* pile) 
{
    return (*pile == NULL);
}

void empiler(Pile* pile, int data) 
{
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = data;
    nouveau->next = *pile;
    *pile = nouveau;
}

int depiler(Pile* pile) 
{
    if (pile_est_vide(pile)) 
	{
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = *pile;
    int data = temp->data;
    *pile = temp->next;
    free(temp);
    return data;
}

void print_pile(Pile* pile) 
{
    if (pile_est_vide(pile)) 
	{
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    Node* temp = *pile;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

File* file_vide() 
{
    File* file = (File*)malloc(sizeof(File));
    file->entree = pile_vide();
    file->sortie = pile_vide();
    return file;
}

int file_est_vide(File* file) 
{
    return (pile_est_vide(file->entree) && pile_est_vide(file->sortie));
}

void enfiler(File* file, int data) 
{
    empiler(file->entree, data);
}

int defiler(File* file) 
{
    if (file_est_vide(file)) {
        printf("Queue is already empty\n");
        return -1;
    }
    if (pile_est_vide(file->sortie)) 
	{
        while (!pile_est_vide(file->entree)) 
		{
            int data = depiler(file->entree);
            empiler(file->sortie, data);
        }
    }
    return depiler(file->sortie);
}
