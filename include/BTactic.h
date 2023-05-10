#ifndef BTACTIC_H
#define BTACTIC_H

#include"Tactic.h"

struct B_TACTIC{
    Tactic super;
    
    void(*deleteBtactic)(struct B_TACTIC*);
};
typedef struct B_TACTIC* Btactic;

Btactic new_Btactic();
int Attack();
void DeleteBtactic(const Btactic);


#endif