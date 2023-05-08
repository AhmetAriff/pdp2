#include <stdio.h>
#include "Game.h"
#include"Colony.h"
int main() {

   Colony* colonies;
   int count =0;
   char str[100];
   fgets(str, 100, stdin);
   int len = strlen(str);

   for(int i=0; i<len; i++) {
      if(str[i] == ' ') {
         count++; // Boşluk karakteri bulunca sayacı artırın
      }
   }

   colonies = (Colony*) malloc((count+1) * sizeof(struct COLONY));
   int i =0;
   char* token = strtok(str, " ");
   while (token != NULL) {
      int population = atoi(token);
      Colony colony = new_Colony(population);
      colonies[i]=colony;
      i++;
      token = strtok(NULL, " ");
   }

   Game game = new_Game(colonies);









   free(colonies);// colony dizisinin iadesi en son yapılacak
   return 0;
}