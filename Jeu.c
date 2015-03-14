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

	printf("\n***--Initialisation des Tirettes Horizontales--***\n");

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
			printf("%d",TabJeu[i][j][2]);
		}
		printf("\n");		
	}
}	

void InitVertTirret(int TabJeu[14][14][3]) {
	printf("\n***--Initialisation des Tirettes Verticales--***\n");
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

				printf("%d",TabJeu[i][j][1]);

			}
		} printf("\n");
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
			x=0;
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
	printf("\n***--Affichage du tableau de Jeu--***\n");
	int i=0,j=0;
	couleur("32");
	printf("|XX|-|A |B |--|C |D |E |F |G |H |I |J |K |L |--|M |N |\n");
	couleur("0");

	for(j=0;j<14;j++)
	{
		couleur("32");
		if (j<10) {
			printf("|%d |-",j);
		}
		else { 
			printf("|%d|-",j);
		}
		couleur("0");

		for(i=0;i<14;i++)
		{
			if(i==0)
				printf("|");
			if(i==2)
			{
				if(TabJeu[i][j][1]==9 && TabJeu[i][j][2]==9)
				{   
					couleur("32");                                
					printf("--| #|");
					couleur("0");
				}           
				if(TabJeu[i][j][0]==0)
				{   
					//Disons que Vertical supérieur)
					if(TabJeu[i][j][2]==0)
					{   
						printf("--| N|");
					}           
					if(TabJeu[i][j][2]==1 && TabJeu[i][j][1]==9){                                                printf("--| T|");}
					if(TabJeu[i][j][2]==9)
					{
						if(TabJeu[i][j][1]==1)
							printf("--| T|");  
						if(TabJeu[i][j][1]==0)
							printf("--| 0|");

					}   
					if(TabJeu[i][j][2]==1)
					{
						if(TabJeu[i][j][1]==0)
						{
							printf("--| 0|");
						}   
						if(TabJeu[i][j][1]==1)
						{
							printf("--| T|");
						}   
					}                   
				}                   
				if(TabJeu[i][j][0]==1)
				{
					printf("--| *|");
				}} else{
					if(i==12)
					{
						if(TabJeu[i][j][1]==9 && TabJeu[i][j][2]==9)
						{
							couleur("32");
							printf("--| #|");
							couleur("32");
						}
						if(TabJeu[i][j][0]==0)
						{
							//Disons que Vertical supérieur)
							if(TabJeu[i][j][2]==0)
							{   
								printf("--| N|");
							}
							if(TabJeu[i][j][2]==1 && TabJeu[i][j][1]==9){                                                printf("--| T|");}
							if(TabJeu[i][j][2]==9)
							{
								if(TabJeu[i][j][1]==1)
									printf("--| T|");
								if(TabJeu[i][j][1]==0)
									printf("--| 0|");

							}
							if(TabJeu[i][j][2]==1)
							{
								if(TabJeu[i][j][1]==0)
								{
									printf("--| 0|");
								}
								if(TabJeu[i][j][1]==1)
								{
									printf("--| T|");
								}
							}
						}
						if(TabJeu[i][j][0]==1)
						{
							printf("--| *|");

						}}		
					else{

						if(TabJeu[i][j][1]==9 && TabJeu[i][j][2]==9)
						{
							couleur("32");
							printf(" #|");
							couleur("0");
						}	
						if(TabJeu[i][j][0]==0)
						{
							//Disons que Vertical supérieur)
							if(TabJeu[i][j][2]==0)
							{
								printf(" N|");
							}	
							if(TabJeu[i][j][2]==1 && TabJeu[i][j][1]==9){
								printf(" T|");}
							if(TabJeu[i][j][2]==9)
							{
								if(TabJeu[i][j][1]==1)
									printf(" T|");	
								if(TabJeu[i][j][1]==0)
									printf(" 0|");

							}
							if(TabJeu[i][j][2]==1)
							{
								if(TabJeu[i][j][1]==0)
								{
									printf(" 0|");
								}
								if(TabJeu[i][j][1]==1)
								{
									printf(" T|");
								}
							}
						}
						if(TabJeu[i][j][0]>0)
						{
							printf(" *|");
						}}}	

		}	if(j==1||j==11)
		{
			couleur("32");

			printf("\n|--|-|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|\n");
			couleur("0");
		}
		else{
			printf("\n");
		}	}
}		


//N signifie Pas de Trou
//0 signifie Trou Vertical Et Horizontal Rempli
//T signifie Trou Horizontal + Vertical
//* signifie BILLE
//int bille; // 1 si présence de bille  // 0 si pas de bille 
//int tireH; // tirette horizontale 1 si présence de trou // 0 si pas de trou
//int tireV; // tierette verticale 1 si présence de trou // 0 si pas de trou
void InitTabJeu(int TabJeu[14][14][3]) { // Fonction qui initialise le plateau de jeu avant le départ de la partie.
int nbPlayer=2;
int nbBilles=2;

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
