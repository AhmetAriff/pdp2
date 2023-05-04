#include"AProduction.h"

AProduction new_AProduction(){
    AProduction this;
    this = (AProduction) malloc(sizeof(struct A_PRODUCTION));
    this->super = new_Production();
    this->super->produce = &produce;
    this->deleteAProduction = &DeleteAProduction;
    return this;
}
int produce (const AProduction this){
    int randomNum;
    srand(time(NULL)); 
    randomNum = rand() % 10 + 1; 
    return randomNum;
}
void DeleteAProduction(const AProduction this){
    if(this==NULL) return;
    this->super->deleteProduction(this->super);
    free(this);

}