#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
#include "Game.h"
#include"Colony.h"
int main() {

    srand(time(NULL));
   
    char input[100];
    Colony* colonies = NULL;
    int size = 0;

    // Kullanıcıdan boşluklu sayı dizisini al
    printf("Boşluklu sayı dizisini girin: ");
    fgets(input, 100, stdin);

    // Dizi boyutunu hesapla
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            size++;
        }
    }
    size++; // Son elemanı da hesaba kat

    
    colonies = (Colony*) malloc(size * sizeof(struct COLONY*));

    // Diziye elemanları ata
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      int population = atoi(token);
      Colony colony = new_Colony(population);
      colonies[i++] = colony; 
      token = strtok(NULL, " ");
    }

    Game game = new_Game(colonies,size);
    game->startGame(game);
    game->deleteGame(game);
   return 0;
}