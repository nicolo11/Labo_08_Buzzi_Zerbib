#include <cstdlib>
#include <iostream>

#include "tresor.h"

using namespace std;

int main() {
    
char reponse;    
    
do {
    simulationTresor();
    
    cout << " Voulez vous recommencer ? ";
    cin  >> reponse;
    cin.ignore(INT_MAX,'\n');
    
} while (reponse != 'n');

cout << " fin du programme, bonne continuation! " << endl;
   return EXIT_SUCCESS;
}