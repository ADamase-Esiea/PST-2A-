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

void random(plateau TabJeu) {
int case1=0;
int case2=0;
int i=0;
int j=0;

Srand(time(NULL));
for (j=0;j<14;j++) {
for (i=0;i<14;i++){
if (i==1 || i==2) {
	TabJeu[i][j].tireV=rand()%2;
}
else {
case1=TabJeu[i-2][j].tireV;
case2=TabJeu[i-1][j].tireV;
if (case1=0 && case2=0) {
	TabJeu[i][j].tireV=1;
}
else { 
	TabJeu[i][j]=rand()%2;
	
	
}	
}

Printf("%d\n",TabJeu[i][j].tireV);

}
}
}	



void InitTabJeu(plateau TabJeu) { // Fonction qui initialise le plateau de jeu avant le départ de la partie.
	InitBilleArrat(TabJeu);
	random(TabJeu);
	
	
}


int main () {
	
plateau TabJeu[14][14]; // Tableau de variables de type tableau contenant comme informations bille , tireH et tireV

InitTabJeu(TabJeu);

	return 0;
}
