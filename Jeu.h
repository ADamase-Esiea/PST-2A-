//Projet Piège 2A ESIEA Damase-Revoil.


#ifndef JEU_H
#define JEU_H
#include <stdio.h>
#include <stdlib.h>

// Structure:
//typedef struct plateau plateau;
//struct plateau {
  //int bille; // 1 si présence de bille  // 0 si pas de bille 
  //int tireH; // tirette horizontale 1 si présence de trou // 0 si pas de trou
  //int tireV; // tierette verticale 1 si présence de trou // 0 si pas de trou
//}; Plus besoin de cette structure on crée un tableau [14][14][3]

// Prototypes :
void alea(int TabJeu[14][14][3]);
void InitBilleArray(int TabJeu[14][14][3]);
void InitTabJeu(int TabJeu[14][14][3]);

#endif
