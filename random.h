//
// Created by jeremy on 12.12.17.
//

#ifndef LABO_8_RANDOM_H
#define LABO_8_RANDOM_H


// Macro to use 'unless' and 'until' statements
#define unless(x) if(!(x))
#define until(x) while(!(x))

void initRandom();

int getRandomNumber(int max, int min = 0);

void statistics(int tab[], size_t size, int throws);

void countStats(int percent, char c = '=');

void displayStatistics(int tab[], size_t sizeOfSample, int throws);

void makeStatistics(size_t sizeOfSample, int throws);


#endif //LABO_8_RANDOM_H
