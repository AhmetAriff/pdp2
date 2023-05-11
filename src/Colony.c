#include"Colony.h"
Colony new_Colony(int population){
    Colony this;
    this = (Colony)malloc(sizeof(struct COLONY));
    this->generateRandomCharacter=&generateRandomCharacter;
    this->symbol=generateRandomCharacter();
    this->population = population;
    this->foodStock = population*population;
    this->production=new_AProduction()->super;
    this->tactic=new_Atactic()->super;
    this->deleteColony = &DeleteColony;
    
}
// private
char generateRandomCharacter(){
    int symbol_min = 33; 
    int symbol_max = 126;
    srand(time(NULL));
    int symbol = rand() % (symbol_max - symbol_min + 1) + symbol_min;
    char choosenCharacter = (char)symbol;
    return choosenCharacter;
}
void DeleteColony(const Colony this){
    if(this==NULL) return;
    free(this->tactic);
    free(this->production);
    free(this);
}

