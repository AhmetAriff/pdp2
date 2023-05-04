#ifndef TACTIC_H
#define TACTIC_H

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct TACTIC{

    int (*attack)();
    void (*deleteTactic)(struct TACTIC*);
};

typedef struct TACTIC* Tactic;

Tactic new_Tactic();
void DeleteTactic(const Tactic);

#endif