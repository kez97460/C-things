/* 
Auteurs : Kezia Marcou , Liam Lotte
Une description de chaque fonction est présente la ligne avant sa définition
*/
#ifndef FLOAT_LISTS_H
#define FLOAT_LISTS_H

typedef struct _node 
{
float data; // modifier si nécessaire
struct _node* suiv;
} 
node;

typedef node* list;

list empty_list();
void print_list(list* list_pointer , int n_max);
void add_node(list* list_pointer , float data);
void delete_head(list* list_pointer);
void mirror_list(list* list_pointer);
void concat_list(list* list_pointer_debut , list* list_pointer_fin);
void merge_sort_list(list* list_pointer);
int length_list(list* list_pointer);
// copy_list(list* list_pointer_origin, list* list_pointer_copy)

/////////////////////////////////// (fonctions statistiques - flemme de les changer pour prendre list* donc whatever)

float min_list(list list);
float max_list(list list);
float median_list(list list);
float mean_list(list list);
float ecart_type_list(list list);
void print_stats_list(list list);

#endif

