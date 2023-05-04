#include "BTactic.h"

Btactic new_Btactic(){
    Btactic this;
    this=(Btactic)malloc(sizeof(struct B_TACTIC));
    this->super=new_Tactic();
    this->super->attack = &attack;
    this->deleteBtactic = &DeleteBtactic;
    return this;
}
int attack(const Btactic this){
    int randomNum;
    srand(time(NULL)); 
    randomNum = rand() % 1001; 
    return randomNum;
}
void DeleteBtactic(const Btactic this){
    if(this == NULL) return;
    this->super->deleteTactic(this->super);
    free(this);
}