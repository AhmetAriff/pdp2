All :Compile Run

Compile:
	gcc -I ./include/ -o ./lib/Production.o -c ./src/Production.c
	gcc -I ./include/ -o ./lib/AProduction.o -c ./src/AProduction.c
	gcc -I ./include/ -o ./lib/BProduction.o -c ./src/BProduction.c 
	gcc -I ./include/ -o ./lib/Tactic.o -c ./src/Tactic.c
	gcc -I ./include/ -o ./lib/ATactic.o -c ./src/ATactic.c
	gcc -I ./include/ -o ./lib/BTactic.o -c ./src/BTactic.c
	gcc -I ./include/ -o ./lib/Colony.o -c ./src/Colony.c
	gcc -I ./include/ -o ./lib/Game.o -c ./src/Game.c 
	gcc -I ./include/ -o ./bin/Test ./lib/Production.o ./lib/AProduction.o ./lib/BProduction.o ./lib/Tactic.o ./lib/ATactic.o ./lib/BTactic.o ./lib/Colony.o ./lib/Game.o ./src/Test.c

Run:
	./bin/Test