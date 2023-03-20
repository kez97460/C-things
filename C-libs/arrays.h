/* 
Auteur : Kezia Marcou 
Une description de chaque fonction est présente la ligne avant sa définition

>> Lignes de code modifiables :
- le type de donnée stocké est par défaut float, on peut le changer en remplacant ( float -> newtype ; %f -> %adapté )
les lignes où des %f sont présents sont marquées par un commentaire.
*/
#ifndef ARRAYS_H
#define ARRAYS_H

/* fonctions générales ( ne dépendent pas du type stocké ) */

void print_array( float* t , int len , char* debut , char* separateur , char* fin )  ;
float* concat_array( float* tab1 , float* tab2 , int len1 , int len2) ;
float* mirror_array(float* tab, int len) ;
int copy_array( float* tab_recepteur , float* tab_origine ,int len_recepteur , int len_origine ) ;
float* slice_array( float* tab , int debut , int fin ) ;

/* tri , stats etc. ( pour des nombres ) */

float* mergesort_array( float* t , int len ) ;
float min_array( float* tab , int len ) ;
float max_array( float* tab , int len ) ;
float average_array( float* tab , int len ) ;
//float variance_array( float* tab , int len ) ; utilisé pour calculer l'ecart type
float ecart_type_array( float* tab, int len ) ;

#endif
