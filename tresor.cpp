#include "tresor.h"
#include "random.h"

void generateurElement ( char tableau[][COLONNE_CARTE], const char element ){

    int x,y;

    do {
        x = getRandomNumber(LIGNE_CARTE);
        y = getRandomNumber(COLONNE_CARTE);

    }while( colisionObstacle ( tableau, x, y, LAC ) );

    tableau[x][y] = element;
}


void tableauInitialisation (char tableau[][COLONNE_CARTE], const char vide){

    for (int ligne = 0 ; ligne < LIGNE_CARTE ; ++ligne ){

        for (int colonne = 0 ; colonne < COLONNE_CARTE ; ++colonne) {

            tableau[ligne][colonne] = vide;
        }
    }
}

void cercleIntegration ( char tableau[][COLONNE_CARTE], const int rayon, const int x, const int y, const char element ){

    int ligne_initiale = x - rayon ;
    int ligne_max      = x + rayon ;

    int colonne_max      = y + rayon;
    int colonne_initiale = y - rayon;

    // pour la siutation ou le rayon est très faible cas particulier! ce si évite de faire d'autre boucle for
    if ( rayon == 0) {
        tableau[ligne_initiale][colonne_max] = element;
    }
    //pour éviter des opérations inutiles, on prends on compte uniquement les éléments dans la carte
    if ( ligne_initiale < 0           ) { ligne_initiale   = 0 ;}
    if ( ligne_max > LIGNE_CARTE      ) { ligne_max        = LIGNE_CARTE ;}
    if ( colonne_max > COLONNE_CARTE  ) { colonne_max      = COLONNE_CARTE; }
    if ( colonne_initiale < 0         ) { colonne_initiale = 0; }

    for ( ; ligne_initiale < ligne_max ; ++ligne_initiale ) {

        for ( int colonne (colonne_initiale); colonne < colonne_max; ++colonne ){

            tableau[ligne_initiale][colonne] = element;
        }
    }
}

bool colisionObstacle ( char tableau[][COLONNE_CARTE], const int x, const int y, const char vide,  const int rayon ) {

    bool colision = false;
    bool rayonNul = (bool) rayon;

    // on multiplie par rayonNul car si on veut juste testé une seul position on a pas besoin de controler ce qu'il y a autour
    int ligne            = x + ( - rayon - 1 ) * rayonNul;
    int ligne_max        = x + (   rayon + 1 ) * rayonNul;
    int colonne_max      = y + (   rayon + 1 ) * rayonNul;
    int colonne_initiale = y + ( - rayon - 1 ) * rayonNul;

    //pour éviter des opérations inutiles, tout ce qui est en dehors de la carte n'est plus pris en compte
    if ( ligne < 0 )                  { ligne  = 0 ;                }
    if ( ligne_max > LIGNE_CARTE )    { ligne_max  = LIGNE_CARTE ;  }
    if( colonne_max > COLONNE_CARTE ) {colonne_max = COLONNE_CARTE; }
    if (colonne_initiale < 0 )        { colonne_initiale = 0;       }

    for ( ; ligne <= ligne_max ; ++ligne ) {
        for ( int colonne (colonne_initiale) ; colonne <= colonne_max ; ++colonne ){

            if (tableau[ligne][colonne] == vide  ) {
                colision = true;
                return colision;
            }
        }
    }
    return colision;
}

void generateurLac ( char tableau[][COLONNE_CARTE] , const int nombreLac ) {

    int x,y;
    int distance;
    int rayon;
    int rayonAleatoire;
    int compteurLac = 1;

    while ( compteurLac <= nombreLac ){

        do {
            x = getRandomNumber(LIGNE_CARTE);
            y = getRandomNumber(COLONNE_CARTE);

            distance = (int)round ( hypot ( LIGNE_CARTE , COLONNE_CARTE ) );
            rayon    = (int)round ( distance / 4 );

            rayonAleatoire = getRandomNumber(rayon);

        } while( colisionObstacle ( tableau, x, y,LAC, rayonAleatoire ) );

        cercleIntegration ( tableau, rayonAleatoire, x, y, LAC);
        compteurLac++;
    }
}


void simulationTresor() {

    string etat;
    int compteurPas;
    int compteurTotal     = 0;
    int compteurChercheur = 0;
    int chercheur;
    int nbPasGagnant = 0;
    int gagnant = 0;

    double probabiliteReussite;

    char carte [LIGNE_CARTE][COLONNE_CARTE] = {};

    tableauInitialisation (carte, VIDE);

    generateurLac     ( carte, 3);
    generateurElement ( carte, TRESOR );

    cout << " nombre de chercheurs : ";
    cin >> chercheur;
    cin.ignore(INT_MAX,'\n');

    do{

        ++compteurChercheur;

        deplacementJoueur (carte, etat, compteurPas);

        cout << " etat : " << setw(6) <<etat << " || Le nombres de pas : " << compteurPas << endl;

        if ( etat == RICHE) {
            ++gagnant;
            nbPasGagnant += compteurPas;
        }
        compteurTotal +=  compteurPas;

    } while ( compteurChercheur < chercheur );

    probabiliteReussite = ( gagnant * 100 ) / compteurChercheur;


    cout << endl;
    cout << " nombre chercheurs : "<< compteurChercheur << " || Le nombre de pas total : " << compteurTotal << endl;
    cout << " Il y a eu " << gagnant << plural(" chercheur", gagnant)<< " riche." << endl;
    cout << " Il y a eu " << nbPasGagnant << " pour trouver un tresor au total." << endl;
    cout << " Le nombre de pas moyen pour devenir riche " << nbPasGagnant / gagnant;
    cout << " et le taux de reussite est de : " << setprecision(3) << probabiliteReussite << "%" <<endl;
    cout << endl;

}

void deplacementJoueur ( char tableau[][COLONNE_CARTE], string& etat, int& compteur ){

    int  x = 0;
    int  y = 0;
    int  ligne ;
    int  colonne;
    int  nombrePas = LIGNE_CARTE * COLONNE_CARTE;
    bool finPartie  = false;

    compteur = 0;

    do{
        ligne   = getRandomNumber(LIGNE_CARTE);
        colonne = getRandomNumber(COLONNE_CARTE);

    } while( colisionObstacle ( tableau, ligne, colonne, LAC)  and colisionObstacle ( tableau, ligne, colonne, TRESOR ) );

    tableau[ligne][colonne] = 'J';

    do{
        int  direction = getRandomNumber(3);

        switch (direction) {
            case 0 : x = -1;  y =  0;  break; // nord
            case 1 : x =  1;  y =  0;  break; // sud
            case 2 : x =  0;  y =  1;  break; // est
            case 3 : x =  0;  y = -1;  break; // ouest
            default:break;
        }
        ++compteur;
        ligne   += x;
        colonne += y;


        if (( (ligne >= LIGNE_CARTE ) or ( colonne >= COLONNE_CARTE) ) ){
            etat = PERDUE;
            finPartie = true;
        } else if ( ( compteur >= nombrePas ) ) {
            finPartie = true;
            etat = MORT;
        } else if((tableau[ligne][colonne] == 'T') ){
            etat = RICHE;
            finPartie = true;
        } else if((tableau[ligne][colonne] == 'L')){
            etat = NOYER;
            finPartie = true;
        } else if(!finPartie
                  and colisionObstacle ( tableau, ligne, colonne, LAC)
                  and colisionObstacle ( tableau, ligne, colonne, TRESOR)){
            tableau[ligne][colonne] = 'J';
        }

    } while( !finPartie );

}

/**
 *
 * @param s
 * @param value
 * @return a plural of a given word
 */

string plural(const string& s, int value){
    return (value > 1 ? s + 's': s);
}

