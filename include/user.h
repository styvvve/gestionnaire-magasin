#ifndef USER_H
#define USER_H

#define MAX_USER 10

struct user_e {
    int id; 
    char name[50]; 
    char password[50]; 
}; 

void create_user(char name[], char password[]); 
void authentifiate_user(char name[], char password[]); 
void delete_user(struct user_e user); 

#endif