#include <stdio.h>
#include <stdlib.h>

typedef struct _noeud
{
    float data;
    struct _noeud* suiv;
} 
noeud;

noeud* ajouter_noeud(noeud* tete, float data)
{
noeud* nouveau = (noeud*) malloc(sizeof(noeud));
nouveau->data = data;
nouveau->suiv = tete;
return nouveau;
}

int longueur_liste(noeud* tete)
{
int res = 0;
while(tete != NULL)
    {
    res++;
    tete = tete->suiv;
    }
return res;
}

int carre(float x)
{
return x*x;
}

void carre_2(float* p_x)
{
p_x[0] = p_x[0] * p_x[0] ;
}

float* changer_taille(float* tab, int old_length, int new_length)
{
float* res = (float*) malloc(new_length * sizeof(float));
int indice_maxi;
if(new_length < old_length) // on retire des éléments
    {
    indice_maxi = new_length;
    }
else // on ajoute de la place
    {
    indice_maxi = old_length; 
    }
for(int i = 0; i<indice_maxi; i++)
    {
    res[i] = tab[i];
    }
return res;
}

noeud* array_to_list(float* tab, int length)
{
noeud* tete = NULL;
for(int i = length-1; i >= 0; i--)
    {
    tete = ajouter_noeud(tete,tab[i]);
    }
return tete;
}

float* list_to_array(noeud* tete)
{
int length = longueur_liste(tete);
float* res = (float*) malloc(length * sizeof(float));

for(int i = 0; i<length; i++)
    {
    res[i] = tete->data;
    tete = tete->suiv;
    }
return res;
}

int main()
{
float x1 = 5;
float y1 = carre(x1);
//printf("x1 = %f ; y1 = %f ;\n",x1,y1);

float x2 = 5;
carre_2(&x2);
//printf("x2 = %f ;\n",x2);

char mot[6] = "feur";


float tab2[6] = {1.0, 2.5, 5, 10, 20, 100};
int taille = 3;

float* tab3 = changer_taille(tab2, 6, taille);
float* tab4 = changer_taille(tab2, 6, 20);

noeud* tete = NULL;
tete = ajouter_noeud(tete,10);
tete = ajouter_noeud(tete,5);
printf("longueur : %d \n",longueur_liste(tete));

float* tab = list_to_array(tete);
noeud* final = array_to_list(tab,2);

while(final != NULL)
    {
    printf(" %f ",final->data);
    final = final->suiv;
    }
printf("\n");
}