#ifndef APRODUCTION_H
#define APRODUCTION_H
#include "Production.h"

struct A_PRODUCTION
{
    Production super;

    void(*deleteAProduction)(struct A_PRODUCTION*);
};
typedef struct A_PRODUCTION* AProduction;

AProduction new_AProduction();
int produce ();
void DeleteAProduction(const AProduction);

#endif