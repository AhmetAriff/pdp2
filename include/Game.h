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
};
typedef struct GAME* Game;


Game new_Game(Colony* colonies,int numberOfColonies);//colony dizisi alıcak
void DeleteGame( Game);
void startGame( Game);
boolean isItGameOver ( Game);
void startTour ( Game);
void increasePopulation ( Colony);
void decreaseFoodStock ( Colony);
void produceFood ( Game);
void winWar( Colony, Colony,int difference);
void startWar( Colony left, Colony right);
void toString ( Game);
void clearConsole();

#endif