#include <stdio.h>
#include <stdlib.h>
#include <Jeu.h>
#include <time.h>


void InitBilleArray(plateau TabJeu) { // Initialise tout le plateau a 0 donc aucun billes elles seront placée par l'utilisateur au début du jeu après que les trous aient été placé aléatoirement.
int i;	
int j;
	for (i=0 ; i<14;i++) {
		for (j=0;i<14;j++) {
		TabJeu[i][j]={0,0,0};
	
		}	
	}	
}




void InitTabJeu(plateau TabJeu) { // Fonction qui initialise le plateau de jeu avant le départ de la partie.
	
	
	
}


int main () {
	
plateau TabJeu[14][14]; // Tableau de variables de type tableau contenant comme informations bille , tireH et tireV



	return 0;
}
