#ifndef COMMANDE_H
#define COMMANDE_H

typedef struct {
    int numero_commande; 
    int produit_id; 
    int fournisseur_id; 
    bool est_livre; 
} commande_t;

#endif