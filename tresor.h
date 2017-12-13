#ifndef TRESOR_H
#define TRESOR_H

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <iomanip>

using namespace std;

const int COLONNE_CARTE = 100;
const int LIGNE_CARTE   = 200;
const char VIDE         = '_';
const char LAC          = 'L';
const char TRESOR       = 'T';
const char JOUEUR       = 'J';

const string NOYER      = "noye";
const string RICHE      = "riche";
const string MORT       = "epuise";
const string PERDUE     = "perdue";

void simulationTresor();

void generateurLac ( char tableau[][COLONNE_CARTE], const int nombreLac );

void cercleIntegration ( char tableau[][COLONNE_CARTE], const int rayon, const int x, const int y, const char element );

bool colisionObstacle ( char tableau[][COLONNE_CARTE], const int x, const int y , const char vide, const int rayon = 0);

void tableauInitialisation (char tableau[][COLONNE_CARTE], const char vide);

void generateurElement (char tableau[][COLONNE_CARTE], const char element );

void deplacementJoueur ( char tableau[][COLONNE_CARTE],string & etat, int & compteur);

//string (char tableau[][COLONNE_CARTE]);

string plural(const string& s, int value);

#endif