#include"BProduction.h"

BProduction new_BProduction(){
    BProduction this;
    this = (BProduction) malloc(sizeof(struct B_PRODUCTION));
    this->super = new_Production();
    this->super->produce = &produce;
    this->deleteBProduction = &DeleteBProduction;
    return this;
}
int produce (const BProduction this){
    int randomNum;
    srand(time(NULL)); 
    randomNum = rand() % 10 + 1; 
    return randomNum;
}
void DeleteBProduction(const BProduction this){
    if(this==NULL) return;
    this->super->deleteProduction(this->super);
    free(this);

}