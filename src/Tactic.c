#include"Tactic.h"

Tactic new_Tactic(){
    Tactic this;
    this=(Tactic)malloc(sizeof(struct TACTIC));
    this->deleteTactic=&DeleteTactic;
    return this;
}
void DeleteTactic(const Tactic this){
    if(this==NULL) return;
    free(this);
}
