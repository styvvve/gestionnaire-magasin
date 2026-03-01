#ifndef USER_H
#define USER_H

#define MAX_USER 10
#define PASSWORD_SYSTEM "azerty"

typedef struct  {
    int id; 
    char name[50]; 
    char password[50]; 
} user_t; 

user_t utilisateurs[MAX_USER]; //initialize to 0 all


void create_user(char name[], char password[]); 
user_t authentificate_user(char name[], char password[]); 
int delete_user(user_t user); 

#endif