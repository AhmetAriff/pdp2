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
    int numberOfColonies;
    void(*startGame)(struct GAME*);
    void(*deleteGame)(struct GAME*);
    boolean(*isItGameOver)(struct GAME*);
    void(*startTour)(struct GAME*);
    void(*increasePopulation)(struct COLONY*);
    void(*decreaseFoodStock)(struct COLONY*);
    void(*produceFood)(struct GAME*);
};
typedef struct GAME* Game;


Game new_Game(Colony*);//string bir ifade alıcak
void DeleteGame(const Game);
void startGame(const Game);
boolean isItGameOver (const Game);
void startTour (const Game);
void increasePopulation (const Colony);
void decreaseFoodStock (const Colony);
void produceFood (const Game);

#endif