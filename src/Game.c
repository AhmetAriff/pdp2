#include"Game.h"
Game new_Game(Colony* colonies){
    Game this;
    this->colonies=colonies;
    this->tour=0;
    this->startGame = &startGame;
    this->deleteGame = &DeleteGame;
    
}
void startGame(const Game this){
    
}
void DeleteGame(const Game this){
    if(this==NULL) return;
    free(this);
}