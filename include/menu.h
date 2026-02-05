#ifndef MENU_H
#define MENU_H 

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

//display anything
void display_options_view(WINDOW *menu_win, int highlight, const char **options, int nb_options); 
void login_user(); 

#endif