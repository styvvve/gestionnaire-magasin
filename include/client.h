#ifndef CLIENT_H
#define CLIENT_H

typedef struct {
    int id; 
    char nom[50]; 
    char tel[10];  
    float somme_depense_cumules; //pour le programme de fidelité
    int historique_achats_id[10]; 
} client_t; 

#endif