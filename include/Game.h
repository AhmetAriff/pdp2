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
    void(*winWar)(struct COLONY*,struct COLONY*,int difference);
    void(*startWar)(struct COLONY*,struct COLONY*);
    void(*toString)(struct GAME*);
    void(*clearConsole)();
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
void startWar( Colony, Colony);
void toString ( Game);
void clearConsole();

#endif