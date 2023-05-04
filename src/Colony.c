#include"Colony.h"
Colony new_Colony(int population){
    Colony this;
    this = (Colony)malloc(sizeof(struct COLONY));
    this->symbol=(char)generateRandomCharacter();
    this->population = population;
    this->foodStock = population*population;
    this->aProduction=new_AProduction();
    this->aTactic=new_Atactic();
    this->deleteColony = &DeleteColony;
}
// private
int generateRandomCharacter(){
    int symbol_min = 33; 
    int symbol_max = 126;
    int choosenCharacter = rand() % (symbol_max - symbol_min + 1) + symbol_min;
    return choosenCharacter;
}
void DeleteColony(const Colony this){
    if(this==NULL) return;
    free(this->aTactic);
    free(this->aProduction);
    free(this);
}
