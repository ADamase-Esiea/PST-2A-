all : Jeu.o
	gcc -Wall Jeu.o -o Jeu
Jeu.o : Jeu.c
	gcc -Wall -c Jeu.c -o Jeu.o
clear : 
	rm -f *.o
