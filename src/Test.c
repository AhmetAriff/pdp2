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


   int size = sizeof(colonies)/sizeof(colonies[0]);

   printf("%d",size);      // dizi oluşturmada bir sıkıntı var  sizeı hep bir gösteriyor


   for (int i = 0; i <size ; i++)
   {
      printf("The value of num is: %d", colonies[i]->population);   //diziye bölmede bir hata var
   }
   


   Game game = new_Game(colonies);




   free(colonies);// colony dizisinin iadesi en son yapılacak
   return 0;
}