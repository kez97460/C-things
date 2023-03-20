#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linked_lists.h"

/////////////////////////////////////////////// (Fonctions)

// affiche les premiers éléments d'une liste chainee (affiche toute la liste si elle a moins de n_max elements)
void print_list_aux(list list , int n_max)
{
printf("{");
while(list != NULL && n_max > 0)
	{
	printf(" %f ",list->data);
	list = list->suiv;
	n_max--;
	}
if(list == NULL) printf("}\n");
else printf("...\n");
}

void print_list(list* list_pointer, int n_max)
{
print_list_aux(*list_pointer,n_max);
}

// ajout d'un node en tête (préciser le data du node a ajouter)
void add_node(list* list_pointer , float data) 
{
list nouveau = (list) malloc(sizeof(node));
nouveau->data = data;
nouveau->suiv = *list_pointer;
*list_pointer = nouveau;
}

void delete_head(list* list_pointer) 
{
*list_pointer = (*list_pointer)->suiv;
}

// miroir d'une liste chainee. En O(n)
void mirror_list(list* list_pointer)
{
list res = NULL;
while (*list_pointer != NULL)
	{
	add_node(&res,(*list_pointer)->data);
	*list_pointer = (*list_pointer)->suiv;
	}
*list_pointer = res;
}

// met dans la liste de fin la concaténation des 2 listes, supprime la liste de début
void concat_list(list* list_pointer_debut , list* list_pointer_fin)
{
mirror_list(list_pointer_debut);
while(*list_pointer_debut != NULL)
	{
	add_node(list_pointer_fin,(*list_pointer_debut)->data);
	*list_pointer_debut = (*list_pointer_debut)->suiv;
	}
}

// fusionne 2 listes triées en maintenant l'ordre (pour le tri fusion)
list merge_list(list tete1 , list tete2)
{
list res = NULL;
while (tete1 != NULL && tete2 != NULL)
	{
	if (tete1->data < tete2->data) // test de l'inégalité , modifier si nécessaire
		{
		add_node(&res,tete1->data);
		tete1 = tete1->suiv;
		}
	else
		{
		add_node(&res,tete2->data);
		tete2 = tete2->suiv;
		}
	}
while (tete1 != NULL || tete2 != NULL)
	{
	if (tete1 != NULL)
		{
		add_node(&res,tete1->data);
		tete1 = tete1->suiv;
		}
	else
		{
		add_node(&res,tete2->data);
		tete2 = tete2->suiv;
		}
	}
mirror_list(&res);
return res;
}

// tri fusion d'une liste chainee (pour définir l'ordre voir merge_list). En O(n.log n)
void merge_sort_list(list* list_pointer)
{
list list1 = NULL;
list list2 = NULL;
int i = 0;
if (*list_pointer == NULL || (*list_pointer)->suiv == NULL) return;
else
	{
	while (*list_pointer != NULL)
		{
		if (i == 0)
			{
			add_node(&list1,(*list_pointer)->data);
			*list_pointer = (*list_pointer)->suiv;
			i++;
			}
		else
			{
			add_node(&list2,(*list_pointer)->data);
			*list_pointer = (*list_pointer)->suiv;
			i = 0;
			}
		}
	merge_sort_list(&list1);
	merge_sort_list(&list2);
	*list_pointer = merge_list(list1, list2);
	return;
	}
printf("Error : what did you do ? Something wrong. ");
}

// renvoie la longueur de la liste. En O(n).
int length_list_aux(list list)
{
int res = 0;
while (list != NULL)
	{
	res++;
	list = list->suiv;
	}
return res;
}

int length_list(list* list_pointer)
{
return length_list_aux(*list_pointer);
}


// renvoie un tableau contenant les éléments de la liste. En O(n). Isn't it beautiful ? Kinda useless tho
float* linked_list_to_array(list list)
{
int len = length_list(&list);
float* res = (float*) malloc(len * sizeof(float));
for (int i = 0; i<len; i++)
	{
	res[i] = list->data;
	list = list->suiv;
	}
return res;
}

//////////////////////////////////// (fonctions statistiques)

//renvoie le minimum d'une liste
float min_list(list list)
{
if (list != NULL) 
	{	
	float res = list->data;
	while (list!= NULL)
		{
		if (list->data < res) res = list->data;
		list = list->suiv;
		}
	return res;
	}
printf("Error : min of empty list\n");
}
 
//renvoie le maximum d'une liste
float max_list(list list)
{
if (list != NULL) 
	{	
	float res = list->data;
	while (list!= NULL)
		{
		if (list->data > res) res = list->data;
		list = list->suiv;
		}
	return res;
	}
printf("Error : max of empty list\n");
}

//renvoie la médiane d'une liste en la triant et récupérant l'élément du milieu. En O(n.log n)
float median_list(list list)
{
int len = length_list(&list);
merge_sort_list(&list);
if (len>0)
	{
	int mid = len/2;
	for (int i = 0; i<mid; i++)
		{
		list = list->suiv;
		}
	return list->data;
	}
printf("Error : median of empty list\n");
}

//renvoie la mean d'une liste
float mean_list(list list)
{
int res = 0;
int len = length_list(&list);
if (len>0)
	{
	while (list != NULL)
		{
		res += list->data;
		list = list->suiv;
		}
	return res/len;
	}
printf("Error : average of empty list\n");
}

float variance_list(list list)
{
int len = length_list(&list);
if (len>0)
	{
	float moy_carres = 0;
	float moy = mean_list(list);
	while (list != NULL)
		{
		moy_carres += list->data * list->data;
		list = list->suiv;
		}
	return (moy_carres/len - moy*moy);
	}
printf("Error : variance of empty list \n");
}

float ecart_type_list(list list)
{
return sqrt(variance_list(list));
}

void print_stats_list(list list)
{
printf("Min : %f \n",min_list(list));
printf("Max : %f \n",max_list(list));
printf("Moyenne : %f \n",mean_list(list));
printf("Mediane : %f \n",median_list(list));
printf("Ecart-type : %f \n",ecart_type_list(list));
}