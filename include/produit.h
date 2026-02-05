#ifndef PRODUIT_H
#define PRODUIT_H

#include "categorie.h"

typedef struct {
    int id; 
    char nom[50]; 
    categorie_e categorie_produit; 
    float prix; 
    int quantite; 
} produit_t; 

#endif