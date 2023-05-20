#include"Colony.h"
Colony new_Colony(int population){
    Colony this;
    this = (Colony)malloc(sizeof(struct COLONY));
    this->symbol=generateRandomCharacter();
    this->population = population;
    this->foodStock = population*population;
    this->production=new_BProduction()->super;
    this->tactic=new_Atactic()->super;
    this->deleteColony = &DeleteColony;
    this->win=0;
    this->lose=0;
    return this;
}
int generateRandomCharacter(){
    int symbol_min = 33; 
    int symbol_max = 126;
    int symbol = rand() % (symbol_max - symbol_min + 1) + symbol_min;
    return symbol;
}
void DeleteColony(const Colony this){
    if(this==NULL) return;
    this->tactic->deleteTactic(this->tactic);
    this->production->deleteProduction(this->production);
    free(this);
}

