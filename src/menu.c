#include <ncurses.h>
#include <panel.h>
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void display_options_view(WINDOW *menu_win, int highlight, const char **options, int nb_options) {
    for (int i = 0; i < nb_options; i++) {
        if (i == highlight) {
            wattron(menu_win, A_REVERSE); //inverse la couleur du menu selectionne
        }
        mvwprintw(menu_win, i + 1, 4, "%s", options[i]); 
        wattroff(menu_win, A_REVERSE); 
    }
    wrefresh(menu_win); 
}

void login_user() {
    initscr(); //before i want to do anything with the terminal
    cbreak(); //disactivate the line buffering
    noecho(); //prevent the buttons display
    start_color(); 

    int h = 10, w = 40; 

    /*window positioning*/
    int y = (LINES - h) / 2; 
    int x = (COLS - w) / 2; 

    WINDOW *login = newwin(h, w, y, x); 
    box(login, 0, 0); 
    refresh();

    init_pair(1, COLOR_WHITE, COLOR_BLACK); 
    wbkgd(login, COLOR_PAIR(1)); 
    keypad(login, TRUE); //activate the special's button detection
    box(login, 0, 0); 

    //int nb_options = 2; 
    const char *options[2] = {
        "Se connecter", 
        "Quitter (échap)"
    }; 
    int highlight = 0; 
    int choix; 
    display_options_view(login, highlight, options, 2); 
    
    //we simulate an infinite
    int running = 1; 
    while (running) {

        choix = wgetch(login); //read

        switch (choix) {
            case KEY_UP: 
                highlight = (highlight == 0) ? 1 : 0; 
                break; 
            case KEY_DOWN: 
                highlight = (highlight == 1) ? 0 : 1; 
                break; 
            case '\n': //touche entree
                if (highlight == 0) {
                    //envoyer vers l'écran de connexion
                } else {
                    running = 0; 
                }
                break; 
            
            case 27: 
                running = 0; 
        }
        display_options_view(login, highlight, options, 2); 
    }
    endwin(); 
    delwin(login); 
} 