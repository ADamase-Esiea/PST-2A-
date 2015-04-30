#include <stdio.h>
#include <stdlib.h>
#include "Jeu.h"
#include "couleurs.h" //surtout ne pas l'oublier;
#include <time.h>

// Test Github
void InitArray(int TabJeu[14][14][3]) { // Initialise tout le plateau a 0 donc aucun billes elles seront placée par l'utilisateur au début du jeu après que les trous aient été placé aléatoirement.
	int i;	
	int j;
	for (i=0 ; i<14;i++) {
		for (j=0;j<14;j++) {
			TabJeu[i][j][0]=0;
			TabJeu[i][j][1]=9;
			TabJeu[i][j][2]=9;
		}	
	}	
}

void InitHorTirret(int TabJeu[14][14][3]) {

	printf("***--Initialisation des Tirettes Horizontales--***\n");

	int case1=0;
	int case2=0;
	int i=0;
	int j=0;

	srand(time(NULL));
	for (j=0;j<14;j++) {
		if(j!=0 && j!=1 && j!=12 && j!=13)
		{
			for (i=0;i<14;i++){

				if (i==1 || i==2) {
					TabJeu[i][j][2]=rand()%2;
				}
				else {
					case1=TabJeu[i-2][j][2];
					case2=TabJeu[i-1][j][2];
					if (case1==0 && case2==0) {
						TabJeu[i][j][2]=1;
					}
					else { 
						TabJeu[i][j][2]=rand()%2;
					}	
				}

			}
		}}	
	for (j=0;j<14;j++) 
	{
		for (i=0;i<14;i++)	
		{
			//printf("%d",TabJeu[i][j][2]);
		}
		//printf("\n");		
	}
}	

void InitVertTirret(int TabJeu[14][14][3]) {
	printf("***--Initialisation des Tirettes Verticales--***\n");
	int case1=0;
	int case2=0;

	int i=0;
	int j=0;

	srand(time(NULL));
	for (j=0;j<14;j++) {

		{
			for (i=0;i<14;i++){
				if(i!=0 && i!=1 && i!=12 && i!=13)
				{       if (i==1 || i==2) {
								  TabJeu[i][j][1]=rand()%2;
							  }
				else {
					case1=TabJeu[i-2][j][1];
					case2=TabJeu[i-1][j][1];
					if (case1==0 && case2==0) {
						TabJeu[i][j][1]=1;
					}
					else { 
						TabJeu[i][j][1]=rand()%2;
					} 
				}}

				//printf("%d",TabJeu[i][j][1]);

			}
		} //printf("\n");
	}
}


void setBilles(int TabJeu[14][14][3], int nbPlayer, int nbBilles) {
	int i;
	int j;
	int x;
	int y;
	int test;


	printf("Les %d joueurs doivent chacun placer %d boules\n",nbPlayer,nbBilles);
	for (i=1; i<nbPlayer+1;i++) {
		for (j=1; j<nbBilles+1;j++) {
			test=1;
			while (test ==1) {
				test=0;
				i=0;
				y=0;

				printf("Choisissez la postion de la bille %d du joueur %d sur l'axe X\n",j,i);
				while (x<2 || x>11) {

					scanf("%d",&x);
					if (x<2 || x>11) {
						printf("La valeur ne peux pas être inférieur a 2 ou dépasser 11\n");
					}


				}



				printf("Choisissez la position  de la bille %d du joueur %d sur l'axe Y\n", j ,i);
				while (y<2 || y > 11) {
					scanf("%d",&y);
					if (y<2 || y>11) {

						printf("La valeur ne peux pas être inférieur a 2 ou dépasser 11\n");

					}
				}

				if (TabJeu[x][y][0]!=0) {
					printf("Une bille est déjà placé veuillez choisir une autre position.\n");
					test=1;
				}
			}
			TabJeu[x][y][0] =j;

		}
	}
}


void ShowArray(int TabJeu[14][14][3])
{
	//on considere la tirette verticale comme la tirrete superieure

	printf("***--Affichage du tableau de Jeu--***\n");
	printf("Voici les notations :\n");
	printf("- '*' signifie qu'il y a une bille\n");
	printf("- 'X' signifie que vu du dessus il n'y a pas de trou\n");
	printf("- 'P' signifie qu'il y a un trou seulement sur la premire couche\n");
	printf("- 'B' signifie qu'il a un trou sur chaque couche\n");
	int i=0,j=0;
	couleur("36");
	printf("| ** | A | B |---| C | D | E | F | G | H | I | J | K | L |---| M | N |\n");
	couleur("0");

	for(j=0;j<14;j++)
	{	
		if(j==2 || j==12)
		        {
			        couleur("36");
				        printf("|----|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
					        couleur("0");
						        }  
	if(j<10)
		{	
			couleur("36");
			printf("| 0%d |",j);
			couleur("0");
		}
		else{
			couleur("36");
			printf("| %d |",j);
			couleur("0");
		}
	
		for(i=0;i<14;i++)
		{
			// ON ENTRE DANS LE CAS DANS BILLE ------------------------------------------		
			if(i==2 || i==12)
			{	couleur("36");
				printf("---|");
				couleur("0");
			}

			if(TabJeu[i][j][0]==0)
			{
			
			
				if(TabJeu[i][j][1]==0)
				{
				
					if(TabJeu[i][j][2]==0)
					{
						printf(" B ");
					}
					if(TabJeu[i][j][2]==1)
					{
						printf(" P ");
					}
					if(TabJeu[i][j][2]==9)
					{
						printf(" P ");
					}
				}
				if(TabJeu[i][j][1]==1)
				{
					if(TabJeu[i][j][2]==0)
					{
						printf(" X ");
					}
					if(TabJeu[i][j][2]==1)
					{   
						printf(" X ");
					}  
					if(TabJeu[i][j][2]==9)
					{
						printf(" X ");
					}
				}
				if(TabJeu[i][j][1]==9)
				{
					if(TabJeu[i][j][2]==0)
					{
						printf(" P ");
					}
					if(TabJeu[i][j][2]==1)
					{
						printf(" X ");
					}
					if(TabJeu[i][j][2]==9)
					{
					printf(" # ");
					}
				}
							
				couleur("36");
				printf("|");
				couleur("0");
			
			}
			// ON SORT SUR CAS SANS BILLE -----------------------------------------------

			// ON ENTRE DANS LE CAS AVEC BILLE ------------------------------------------
			else
			{
				if(TabJeu[i][j][0]==1)
				{
					couleur("32");
					printf(" * ");
					couleur("0");
				}
				if(TabJeu[i][j][0]==2)
				{
					couleur("33");
					printf(" * ");
					couleur("0");
				}
				if(TabJeu[i][j][0]==3)
				{
					couleur("34");
					printf(" * ");
					couleur("0");
				}
				if(TabJeu[i][j][0]==4)
				{
					couleur("35");
					printf(" * ");
					couleur("0");
				}
				couleur("36");
				printf("|");
				couleur("0");
			}
			// ON SORT DU CAS AVEC BILLE ------------------------------------------------

		}
		printf("\n");
	}
	couleur("36");
	printf("|----|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
	couleur("0");

}		



void InitTabJeu(int TabJeu[14][14][3]) { // Fonction qui initialise le plateau de jeu avant le départ de la partie.
int nbPlayer=2;
int nbBilles=1;

	InitArray(TabJeu);
	InitVertTirret(TabJeu);
	InitHorTirret(TabJeu);
	ShowArray(TabJeu);
	setBilles(TabJeu,nbPlayer,nbBilles);
	ShowArray(TabJeu);
}


int main () {
	int TabJeu[14][14][3]; // Tableau de variables de type tableau contenant comme informations bille[0] , tireH [1] et tireV [2]

	InitTabJeu(TabJeu);

	return 0;
}
