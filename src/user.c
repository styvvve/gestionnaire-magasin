#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/user.h"

void create_user(char name[], char password[]) {
    int position = -1; 
    for (int i = 0; i < MAX_USER; i++) {
        if (utilisateurs[i].id == 0) {
            position = i; 
            break;
        }
    }

    if (position == -1) {
        perror("Too much users"); 
        exit(-1); 
    }

    user_t new_user;
    new_user.id = position+1; 
    strcpy(new_user.name, name); 
    strcpy(new_user.password, password);  

    utilisateurs[position] = new_user; 
}

user_t authentificate_user(char name[], char password[]) {
    
    int position = -1;

    //return an error user
    user_t error_user = { -1, "ttt", "vvv" }; 

    for (int i = 0; i < MAX_USER; i++) {
        if (strcmp(utilisateurs[i].name, name) == 0) {
            position = i; 
            break; 
        }
    }

    if (position == -1) {
        perror("No user found"); 
        return error_user; 
    }

    if (strcmp(utilisateurs[position].password, password) != 0) {
        perror("incorrect password"); 
        return error_user; 
    } 

    return utilisateurs[position]; 
}

int delete_user(user_t user) {

    int position = user.id - 1; 

    int last_value = MAX_USER; 

    //the last value in tab
    for (int i = 0; i < MAX_USER; i++) {
        if (utilisateurs[i].id == 0) {
            last_value = i; 
            break; 
        }
    }

    for (int i = position; i < last_value; i++) {
        utilisateurs[i] = utilisateurs[i+1];
        utilisateurs[i].id = i+1; //put back good id 
    }

    memset(&utilisateurs[position], 0, sizeof(user_t)); 

    return 0; 
}
