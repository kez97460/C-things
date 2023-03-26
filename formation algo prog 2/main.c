#include <stdio.h>
#include <stdlib.h>
#include "piles_files.h"

int main()
{
File* f = file_vide();
enfiler(f,2);
enfiler(f,5);
enfiler(f,10);
}