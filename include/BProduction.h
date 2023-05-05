#ifndef BPRODUCTION_H
#define BPRODUCTION_H
#include "Production.h"

struct B_PRODUCTION
{
    Production super;
    void(*deleteBProduction)(struct B_PRODUCTION*);
};
typedef struct B_PRODUCTION* BProduction;

BProduction new_BProduction();
int produce (const BProduction);
void DeleteBProduction(const BProduction);


#endif