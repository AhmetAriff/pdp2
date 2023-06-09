#ifndef COLONY_H
#define COLONY_H
#include"ATactic.h"
#include"AProduction.h"
#include"BTactic.h"
#include"BProduction.h"
#include"stdio.h"
#include"stdlib.h"

struct COLONY
{
    char symbol;
    int population;
    int foodStock;
    int win;
    int lose;
    Tactic tactic;
    Production production;
    void (*deleteColony)(struct COLONY*);
   
};

typedef struct COLONY* Colony;
typedef enum Bool{false, true}boolean;

Colony new_Colony(int);
void DeleteColony(const Colony);
int generateRandomCharacter();


#endif