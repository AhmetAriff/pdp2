#include"Production.h"

Production new_Production(){
    Production this;
    this=(Production)malloc(sizeof(struct PRODUCTION));
    this->deleteProduction=&DeleteProduction;
    return this;
}
void DeleteProduvtion(const Production this){
    if(this==NULL) return;
    free(this);
}