#include <stdio.h>
#include <stdlib.h>
#include "Jeu.h"
#include <time.h>


void InitBilleArray(int TabJeu[i][j][k]) { // Initialise tout le plateau a 0 donc aucun billes elles seront placée par l'utilisateur au début du jeu après que les trous aient été placé aléatoirement.
int i;	
int j;
	for (i=0 ; i<14;i++) {
		for (j=0;i<14;j++) {
		TabJeu[i][j][0]=0;
		TabJeu[i][j][1]=0;
		TabJeu[i][j][2]=0;
		}	
	}	
}

void random(int TabJeu) {
int case1=0;
int case2=0;
int i=0;
int j=0;

Srand(time(NULL));
	for (j=0;j<14;j++) {
		for (i=0;i<14;i++){
			if (i==1 || i==2) {
				TabJeu[i][j][2]=rand()%2;
}
			else {
case1=TabJeu[i-2][j][2];
case2=TabJeu[i-1][j][2];
			if (case1=0 && case2=0) {
			TabJeu[i][j][2]=1;
}
			else { 
			TabJeu[i][j][2]=rand()%2;
	
	
}	
}

				Printf("%d\n",TabJeu[i][j][2]);

}
}
}	



void InitTabJeu(int TabJeu) { // Fonction qui initialise le plateau de jeu avant le départ de la partie.
	InitBilleArrat(TabJeu);
	random(TabJeu);
	
	
}


int main () {
	
int TabJeu[14][14][3]; // Tableau de variables de type tableau contenant comme informations bille[0] , tireH [1] et tireV [2]

InitTabJeu(TabJeu);

	return 0;
}
