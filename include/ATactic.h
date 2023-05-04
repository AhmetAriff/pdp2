#ifndef ATACTIC_H
#define ATACTIC_H

#include"Tactic.h"

struct A_TACTIC{
    Tactic super;
    
    void(*deleteAtactic)(struct A_TACTIC*);
};
typedef struct A_TACTIC* Atactic;

Atactic new_Atactic();
int attack(const Atactic);
void DeleteAtactic(const Atactic);

#endif