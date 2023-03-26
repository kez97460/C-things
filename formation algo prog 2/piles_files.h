#ifndef PILES_FILES_H
#define PILES_FILES_H

typedef struct node 
{
    int data;
    struct node* next;
} Node;

typedef Node* Pile;

typedef struct file 
{
    Pile* entree;
    Pile* sortie;
} File;

// Stack functions
Pile* pile_vide();
int pile_est_vide(Pile* pile);
void empiler(Pile* pile, int data);
int depiler(Pile* pile);
void print_pile(Pile* pile);

// Queue functions
File* file_vide();
int file_est_vide(File* file);
void enfiler(File* file, int data);
int defiler(File* file);

#endif
