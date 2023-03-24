#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrays.h"

/////////////////////////////////////////////// ( Fonctions )

// printf pour un array, il faut préciser les strings qui apparaissent au début , à la fin et entre 2 éléments
void print_array( float* tab , int len , char* debut , char* separateur , char* fin ) 
{
printf("%s",debut) ;
for(int i = 0 ; i<len ; i++)  
    {
    printf("%.2f", tab[i]) ; // modidifer le %f si on modifie le type stocké ou l'affichage : %.2f <=> 2 chiffres après la virgule
    if ( i < len-1 ) printf("%s",separateur) ;
    }
printf("%s\n",fin) ;
}

// renvoie la concaténation de tab1 et tab2 , sans les modifier.
float* concat_array( float* tab1 , float* tab2 , int len1 , int len2) 
{ 
float* res ; 
int i ;
int nb_oct = (len1 + len2) * sizeof(float) ;
res = (float*) malloc(nb_oct) ;

for ( i=0 ; i<len1 ; i++ ) res[i] = tab1[i] ;
for ( i=0 ; i<len2 ; i++ ) res[len1+i] = tab2[i] ;

return res ;
}

// renvoie le miroir d'un tableau de taille len , sans le modifier
float* mirror_array(float* tab, int len) 
{ 
float* res ; 
int i ;
int nb_oct = len * sizeof(float) ;
res = (float*) malloc(nb_oct) ;

for ( i = 0 ; i<len ; i++ ) res[len-i-1] = tab[i] ; 

return res ;
}

// merge du tri fusion
float* merge( float* tab1 , float* tab2 , int len1 , int len2 ) 
{
float* res ; 
int i ; 
int nb_oct = (len1 + len2) * sizeof(float) ;
res = (float*) malloc(nb_oct) ;

int j = 0 ; int k = 0 ;
for ( i=0 ; i<len1+len2 ; i++ ) 
    {
    if ( j == len1 ) { res[i] = tab2[k] ; k++ ; }
    else if ( tab1[j] < tab2[k] || k == len2 ) { res[i] = tab1[j] ; j++ ; }
    else { res[i] = tab2[k] ; k++ ; }
    }
return res ;
}

// tri fusion d'un tableau renvoyé , ne modifie pas le tableau donné.
float* mergesort_array( float* t , int len )
{ 
if ( len > 1 ) 
    {
    int mid = len/2 ;
    /* sépare le tableau en 2 */
    int nb_oct_1 = mid * sizeof(float) ; 
    int nb_oct_2 = ( len - mid ) * sizeof(float) ;
    float* t1 = (float*) malloc(nb_oct_1) ; 
    float* t2 = (float*) malloc(nb_oct_2) ;
    for ( int i = 0 ; i<len ; i++ ) 
        {
        if ( i < mid ) t1[i] = t[i] ;
        else t2[i-mid] = t[i] ;
        }
    return merge( mergesort_array(t1,mid) , mergesort_array(t2,len-mid) , mid , len-mid ) ;
    }
return t ;
}

//copie le contenu de tab_origine , dans tab_recepteur ( renvoie 1 si le tableau complet a été copié, 0 sinon ) 
int copy_array( float* tab_recepteur , float* tab_origine  ,int len_recepteur , int len_origine )
{
int elems_a_copier ;
int res = 1 ;
/*elems_a_copier = min( len_recepteur , len_origine )*/
if ( len_recepteur < len_origine ) 
    {
    elems_a_copier = len_recepteur ;
    res = 0 ;
    }
else elems_a_copier = len_origine ;

for ( int i = 0 ; i < elems_a_copier ; i++ )
    {
    tab_recepteur[i] = tab_origine[i] ;
    }
return res ;
}

// renvoie tab[debut:fin] ( equivalent python ), attention aux segmentation fault si fin >= len(tab)
float* slice_array( float* tab , int debut , int fin )
{
int len_res = fin-debut ;
float* res = (float*)malloc(len_res*sizeof(float)) ;

for ( int i = 0 ; i < len_res ; i++ )
    {
    res[i] = tab[debut+i] ;
    }
return res ;
}

float min_array( float* tab, int len )
{
float res = tab[0] ;
for ( int i = 0 ; i<len ; i++ )
    {
    if ( tab[i] < res ) res = tab[i] ;
    }
return res;
}

float max_array( float* tab, int len )
{
float res = tab[0] ;
for ( int i = 0 ; i<len ; i++ )
    {
    if ( tab[i] > res ) res = tab[i] ;
    }
return res;
}

float average_array( float* tab, int len )
{
float res = 0;
for ( int i = 0 ; i<len ; i++ )
    {
    res += tab[i] ;
    }
return res/len ;
}

float variance_array( float* tab, int len )
{
float moy = average_array(tab,len);
float moy_carres = 0 ;
for ( int i = 0 ; i<len ; i++ )
    {
    moy_carres += tab[i]*tab[i] ;
    }
return ( moy_carres - moy*moy ) ;
}

float ecart_type_array( float* tab , int len )
{
return sqrt(variance_array(tab,len)) ;
}