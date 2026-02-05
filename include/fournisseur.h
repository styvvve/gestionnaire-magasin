#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#define MAX_PRODUITS_FOURNISSEURS 20

typedef struct {
    int id; 
    char nom[50];  
    int produits_fournisseurs[MAX_PRODUITS_FOURNISSEURS]; 
    int nb_produits; 
} fournisseur_t;

#endif