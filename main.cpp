/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo 08 : Chasse au trésor
 Fichier     : main.cpp
 Auteur(s)   : Jeremy Zerbib, Nicolo Buzzi
 Date        : 13.12.2017

 But         : This program aims to determine the number of steps necessary to a
               researcher to find a hidden treasure.
               The program asks the user the number of simulations to do.

 Remarque(s) : - The field's size is set during the compilation.
               - The researcher's initial position, the treasure's position and the three
                 lakes' position are set randomly.
               - The hunter starts at his intitial position and can have four different states :
                    - Found the treasure if he stepped into the position of the treasure.
                    - Lost if he steps out of the map.
                    - Drowned in a lake
                    - Starved to death if he's lost (number of steps > width*height).
               - On those basis, the program displays the info of the game and launches the
                 hunters one by one to determine :
                    - The probability of finding the treasure.
                    - The average of the number of steps of the researcher if he finds the treasure.
               - The program must display the status of each searcher :
                    - his number of steps
                    - his status : rich, lost, drowned, starving
               - The lakes cannot overlap but could step out of the map.
                 The radius should be rounded to 0.5.
               - The starting point and the treasure's position should be distinct and
                 cannot be in a lake
               - At the end of the simulationl, the user should be asked if he wants to restart

Compilateur : MinGW-g++ <x.y.z>
-----------------------------------------------------------------------------------
*/

#include <cstdlib>

using namespace std;

int main(){
    return EXIT_SUCCESS;
}

