#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Colony.h"

struct GAME
{
    int tour;
    Colony* colonies;
    void(*startGame)(struct GAME*);
    void(*deleteGame)(struct GAME*);
};
typedef struct GAME* Game;

Game new_Game(Colony*);//string bir ifade alıcak
void DeleteGame(const Game);
void startGame(const Game);


#endif