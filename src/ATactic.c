#include "ATactic.h"

Atactic new_Atactic(){
    Atactic this;
    this=(Atactic)malloc(sizeof(struct A_TACTIC));
    this->super=new_Tactic();
    this->super->attack = &attack;
    this->deleteAtactic = &DeleteAtactic;
    return this;
}
int attack(){
    int randomNum;
    randomNum = rand() % 1001; 
    return randomNum;
}
void DeleteAtactic(const Atactic this){
    if(this == NULL) return;
    this->super->deleteTactic(this->super);
    free(this);
}