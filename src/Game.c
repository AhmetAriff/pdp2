#include"Game.h"
Game new_Game(Colony* colonies){
    Game this;
    this->colonies=colonies;
    this->numberOfColonies=sizeof(this->colonies)/sizeof(this->colonies[0]);
    this->tour=0;
    this->startGame = &startGame;
    this->isItGameOver = &isItGameOver;
    this->startTour= &startTour;
    this->increasePopulation = &increasePopulation;
    this->decreaseFoodStock = &decreaseFoodStock;
    this->produceFood =&produceFood;
    this->deleteGame = &DeleteGame;
    this->startWar =&startWar;
    this->winWar =&winWar;
    
}
void startGame(const Game this){
    while(!isItGameOver(this)){

    startTour(this);
    produceFood(this);
    
        for(int i = 0;i<this->numberOfColonies-1;i++){
            for(int j = i+1;j<this->numberOfColonies;j++){
                startWar(this->colonies[i],this->colonies[j]);
            }
        }
    }
}
boolean isItGameOver(const Game this){
    int count = 0;
    for(int i = 0;i<this->numberOfColonies;i++){
        if(this->colonies[i]->population<=0)
            count++;
    }
    if(count == this->numberOfColonies-1)
        return true;
    else
        return false;
}
void startTour(const Game this){
    for(int i =0;i<this->numberOfColonies;i++){
        increasePopulation(this->colonies[i]);
        decreaseFoodStock(this->colonies[i]);
    }
    this->tour++;
}
void produceFood(const Game this){
    for(int i =0;i<this->numberOfColonies;i++){
        if(this->colonies[i]->population>=0){
            this->colonies[i]->population+=this->colonies[i]->production->produce();
        }
    }
}
void startWar(const Colony left,const Colony right){
    int leftDamage = left->tactic->attack();
    int rightDamage = right->tactic->attack();

    if(leftDamage>rightDamage){
        int difference = leftDamage-rightDamage;
        winWar(left,right,difference);
    }
    else if(rightDamage>leftDamage){
        int difference = rightDamage-leftDamage;
        winWar(right,left,difference);
    }
    else{
        int difference = 0;
        winWar(left,right,difference);
    }
}
void winWar(const Colony winner,const Colony loser,int difference){
    int percentage = (difference/1000)*100;
    loser->population-=loser->population*(percentage/100);
    int foodWillChange = loser->foodStock*(percentage/100);
    winner->foodStock+=foodWillChange;
    loser->foodStock-=foodWillChange;
}
void increasePopulation(const Colony this){
    if(this->population>=0)
        this->population+=(this->population)/5;
}
void decreaseFoodStock(const Colony this){
    if(this->population>=0)
        this->foodStock-=(this->population)*2;
}
void DeleteGame(const Game this){
    if(this==NULL) return;
    free(this);
}