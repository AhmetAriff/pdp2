#ifndef PRODUCTION_H
#define PRODUCTION_H

#include "stdio.h"
#include "stdlib.h"

struct PRODUCTION{

    int (*produce)();
    void (*deleteProduction)(struct PRODUCTION*);
};

typedef struct PRODUCTION* Production;

Production new_Production();
void DeleteProduction(const Production);

#endif