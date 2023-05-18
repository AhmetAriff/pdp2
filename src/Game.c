#include"Game.h"
Game new_Game(Colony* colonies,int numberOfColonies){
    Game this;
    this = (Game)malloc(sizeof(struct GAME));
    this->colonies=colonies;
    this->numberOfColonies=numberOfColonies;
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
    this->toString=&toString;
    this->clearConsole=&clearConsole;
    return this;
    
}
void startGame(Game this){

    while(!isItGameOver(this)){

    startTour(this);
    produceFood(this);
    
        for(int i = 0;i<this->numberOfColonies-1;i++){
            for(int j = i+1;j<this->numberOfColonies;j++){
                startWar(this->colonies[i],this->colonies[j]);
            }
        }
        this->clearConsole();
        this->toString(this);
        sleep(2);
    }
    
}
boolean isItGameOver( Game this){
    int count = 0;
    for(int i = 0;i<this->numberOfColonies;i++){
        if(this->colonies[i]->population<=0  || this->colonies[i]->foodStock<=0)
        {
            count++;
        } 
    }
    if(count >= this->numberOfColonies-1)
        {return true;}
    else
        {return false;}
}
void startTour( Game this){
    for(int i =0;i<this->numberOfColonies;i++){
        increasePopulation(this->colonies[i]);
        decreaseFoodStock(this->colonies[i]);
    }
    this->tour++;
}
void produceFood( Game this){
    for(int i =0;i<this->numberOfColonies;i++){
        if(this->colonies[i]->population>0 && this->colonies[i]->foodStock>0){
            this->colonies[i]->foodStock+=(this->colonies[i]->production->produce());
        }
    }
}
void startWar( Colony left, Colony right){

    if(left->population>0 && right->population>0 && left->foodStock>0 && right->foodStock>0){
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
            if(left->population>right->population){
                winWar(left,right,0);
            }
            else if(right->population>left->population){
                winWar(right,left,0);
            }
            else{
                winWar(left,right,0);
            }
        }
           
    }
}
void winWar( Colony winner, Colony loser,int difference){
    int percentage = (difference/1000)*100;
    loser->population-=(loser->population*(percentage/100));
    int foodWillChange = loser->foodStock*(percentage/100);
    winner->foodStock+=foodWillChange;
    winner->win++;
    loser->foodStock-=foodWillChange;
    loser->lose++;
}
void increasePopulation( Colony this){
    if(this->population>0 && this->foodStock>0)
    {
        this->population+=((this->population)/5);
    }  
}
void decreaseFoodStock( Colony this){
    if(this->population>0 && this->foodStock>0)
    {
        this->foodStock-=((this->population)*2);
    }
}
void toString( Game this){
    printf("----------------------------------------------------------------- \n Tour : %d \n Colony \tPopulation \t FoodStock \t Win \t Lose \n",this->tour);
    for(int i =0;i<this->numberOfColonies;i++){
        if(this->colonies[i]->population<=0|| this->colonies[i]->foodStock<=0){
            printf("  %c\t\t  %5c \t    %5c \t%3c \t%3c \n",this->colonies[i]->symbol,'-','-','-','-');
        }
        else{
            printf("  %c\t\t  %5d \t    %5d \t%3d \t%3d \n",this->colonies[i]->symbol,this->colonies[i]->population,this->colonies[i]->foodStock,this->colonies[i]->win,this->colonies[i]->lose);
        }
    }
    printf("------------------------------------------------------------------");
}
void clearConsole(){
    #ifdef _WIN32  // for Windows
        system("cls");
    #else  // for Linux and macOS
        system("clear");
    #endif
}
void DeleteGame( Game this){
    if(this==NULL) return;
    for(int i =0;i<this->numberOfColonies;i++){
        this->colonies[i]->deleteColony(this->colonies[i]);
    }
    free(this->colonies);
    free(this);
}
