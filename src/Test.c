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

    printf("%d",size);
    printf("\n");

    
    colonies = (Colony*) malloc(size * sizeof(struct COLONY*));

    printf("%p",colonies);
    printf("\n");


    // Diziye elemanları ata
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL) {
      int population = atoi(token);
      Colony colony = new_Colony(population);
      colonies[i++] = colony; 
      token = strtok(NULL, " ");
    }

  

    for(int i =0;i<size;i++){

      printf("%c", colonies[i]->symbol); 
      printf("\n");
      printf("%d", colonies[i]->population); 
      printf("\n");
      printf("%d", colonies[i]->foodStock); 
      printf("\n");
    }

  printf("%d",colonies);

     Game game = new_Game(colonies,size);
     printf("%d",game->numberOfColonies);
      printf("\n");
       printf("%d",game->tour);
      printf("\n");


     

     printf("%d",game->numberOfColonies);
     

     

   free(colonies);// colony dizisinin iadesi en son yapılacak
   return 0;
}