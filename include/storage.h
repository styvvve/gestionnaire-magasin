#ifndef STORAGE_H
#define STORAGE_H

#include "produit.h"

int save_produits(produit_t *produit, int n); 
int load_produits(produit_t *produit, int *n); 

#endif