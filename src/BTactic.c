#include "BTactic.h"

Btactic new_Btactic(){
    Btactic this;
    this=(Btactic)malloc(sizeof(struct B_TACTIC));
    this->super=new_Tactic();
    this->super->attack = &Attack;
    this->deleteBtactic = &DeleteBtactic;
    return this;
}
int Attack(){
    int randomNum;
    randomNum = rand() % 101; 
    return randomNum;
}
void DeleteBtactic(const Btactic this){
    if(this == NULL) return;
    this->super->deleteTactic(this->super);
    free(this);
}